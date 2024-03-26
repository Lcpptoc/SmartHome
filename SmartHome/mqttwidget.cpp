#include "mqttwidget.h"
#include "ui_mqttwidget.h"
#include <QJsonDocument>
#include <QJsonObject>

Mqttwidget::Mqttwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mqttwidget)
{
    ui->setupUi(this);
    m_client = new QMqttClient;

    m_client->setHostname("mqtt.yyzlab.com.cn");
    m_client->setPort(1883);
    m_client->connectToHost();
    pubTopic = "1709863728402/Device2AIOTSIM";
    subTopic = "1709863728402/AIOTSIM2Device";
    connect(m_client, SIGNAL(connected()), this, SLOT(myNetted()));
    connect(m_client, SIGNAL(messageReceived(QByteArray, QMqttTopicName)), this, SLOT(recvData(QByteArray, QMqttTopicName)));

}

Mqttwidget::~Mqttwidget()
{
    delete ui;
}

void Mqttwidget::on_pushButton_2_clicked()
{
    this->hide();
}


void Mqttwidget::on_pushButton_clicked()
{
    if(ui->pushButton->text() == "连接"){
        m_client->connectToHost();
    }else if(ui->pushButton->text() == "断开"){
        m_client->disconnectFromHost();
        ui->pushButton->setText("连接");
        ui->lineEdit->setText("mqtt客户端断开");
    }
}

void Mqttwidget::myNetted()
{
    ui->pushButton->setText("断开");
    ui->lineEdit->setText("连接成功");
    //订阅消息
    m_client->subscribe(subTopic, 0); //订阅灯、风扇。。。。的状态
}

void Mqttwidget::recvData(const QByteArray &data, const QMqttTopicName &)
{
    ui->textEdit->append(data);
    qDebug() << "data: " << data;
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject obj = doc.object();
    if(obj.contains("lamp"))
    {
        bool flag = obj.value("lamp").toBool();
        int id = obj.value("id").toInt();
        //发射控制本地的灯的信号
        emit sig_localLed(flag, id);
    } else if(obj.contains("fan"))
    {
        bool flag = obj.value("fan").toBool();
        //发射控制本地风扇的信号
        emit sig_localFan(flag);
    } else if(obj.contains("alarm"))
    {
        bool flag = obj.value("alarm").toBool();
        //发射蜂鸣器信号
        emit sig_beeper(flag);
    }
}

void Mqttwidget::pub_TemHumData(double tem, double hum)
{
    QString msg = QString("{\"tem\":%1, \"hum\":%2, \"id\": 0}").arg(tem).arg(hum);
    m_client->publish(pubTopic, msg.toLocal8Bit());

}

void Mqttwidget::pub_LightData(double light)
{
    QString msg = QString("{\"light\":%1,\"id\": 0}").arg(light);
    m_client->publish(pubTopic, msg.toLocal8Bit());
}

void Mqttwidget::pub_InfraredData(bool flag)
{
    QString msg = QString("{\"infrared\":%1,\"id\": 0}").arg(flag);
    m_client->publish(pubTopic, msg.toLocal8Bit());
}

