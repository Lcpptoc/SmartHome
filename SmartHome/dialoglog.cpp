#include "dialoglog.h"
#include "ui_dialoglog.h"
#include <QPixmap>
#include <QMessageBox>

DialogLog::DialogLog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLog)
{
    ui->setupUi(this);

    log_Sock = new QTcpSocket();

    //将密码设置为不可见
    ui->lineEdit_passwd->setEchoMode(QLineEdit::Password);

    //添加图片
    //    ui->label_user->setPixmap(QPixmap(":/user.png"));
    //    ui->label_user->setScaledContents(true);
    //    ui->label_passwd->setPixmap(QPixmap(":/passwd.png"));
    //    ui->label_passwd->setScaledContents(true);

    //初始化
    diaRegister = new DialogRegister();
    m_keyBoard = new KeyBoard();

    ui->lineEdit_user->installEventFilter(m_keyBoard);
    ui->lineEdit_passwd->installEventFilter(m_keyBoard);

    // 连接信号槽，处理连接成功和接收数据的信号
    connect(log_Sock, &QTcpSocket::connected, [=]() {
        qDebug() << "连接到服务器";
    });

    connect(log_Sock, &QTcpSocket::readyRead, this,[=]() {
        QString response = log_Sock->readAll();
        qDebug() << "响应内容: " << response;
        // 处理服务器的响应
        if (response == "LOGIN_SUCCESS")
        {
            QMessageBox::information(this, "登录成功", "登录成功!");
            emit showWidget();
            this->hide();
        } else if (response == "LOGIN_FAILURE")
        {
            QMessageBox::critical(this, "登录失败", "用户名或密码错误");
        } else
        {
            QMessageBox::critical(this, "登录失败", "用户名不存在");
        }
    });

    // 连接服务器
    log_Sock->connectToHost("192.168.137.84", 8080);
}

DialogLog::~DialogLog()
{
    delete ui;
}

void DialogLog::on_pushButton_log_clicked()
{
//    emit showWidget();
//    this->hide();
    QString username = ui->lineEdit_user->text();
    QString password = ui->lineEdit_passwd->text();

    if(username.isEmpty() ||  password.isEmpty())
    {
        QMessageBox::information(this,"提示","请输入用户名或密码!");
        return;
    }
    // 发送登录请求
    QString request = "LOGIN " + username + " " + password;
    qDebug() << "request: "<<request;
    log_Sock->write(request.toUtf8());
}


void DialogLog::on_pushButton_register_clicked()
{
    diaRegister->show();
}


void DialogLog::on_pushButton_clicked()
{
    this->close();
}

