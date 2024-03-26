#ifndef MQTTWIDGET_H
#define MQTTWIDGET_H

#include <QWidget>
#include <QMqttClient>

namespace Ui {
class Mqttwidget;
}

class Mqttwidget : public QWidget
{
    Q_OBJECT

public:
    explicit Mqttwidget(QWidget *parent = nullptr);
    ~Mqttwidget();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void myNetted();

    void recvData(const QByteArray &data, const QMqttTopicName &topic);

    void pub_TemHumData(double, double);
    void pub_LightData(double);
    void pub_InfraredData(bool);
signals:
    void sig_localLed(bool flag, int id); //小程序控制灯
    void sig_localFan(bool flag); // 小程序控制风扇
    void sig_beeper(bool flag);  // 小程序控制蜂鸣器


private:
    Ui::Mqttwidget *ui;
    QMqttClient *m_client;
    QString subTopic;
    QString pubTopic;
};

#endif // MQTTWIDGET_H
