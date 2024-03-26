#include "dialogregister.h"
#include "ui_dialogregister.h"
#include <QMessageBox>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <QDebug>

DialogRegister::DialogRegister(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRegister)
{
    ui->setupUi(this);
    register_Sock = new QTcpSocket();

    //设置键盘
    keyBoard = new KeyBoard();
    ui->lineEdit_user->installEventFilter(keyBoard);
    ui->lineEdit_passwd->installEventFilter(keyBoard);
    ui->lineEdit_sure->installEventFilter(keyBoard);

    //将密码框设置为不可见
    ui->lineEdit_passwd->setEchoMode(QLineEdit::Password);
    ui->lineEdit_sure->setEchoMode(QLineEdit::Password);

    // 连接信号槽，处理连接成功和接收数据的信号
    connect(register_Sock, &QTcpSocket::connected, [=]() {
        qDebug() << "连接到服务器";
    });

    connect(register_Sock, &QTcpSocket::readyRead, [=]() {
        QString response = register_Sock->readAll();
        qDebug() << "响应内容: " << response;
        // 处理服务器的响应
        if (response == "REGISTER_SUCCESS")
        {
            QMessageBox::information(this, "注册成功", "注册成功!");
            ui->lineEdit_user->clear();
            ui->lineEdit_passwd->clear();
            ui->lineEdit_sure->clear();
            this->close();

        } else if (response == "REGISTER_FAILURE")
        {
            QMessageBox::critical(this, "注册失败", "该用户已存在");
        }
    });

    // 连接服务器
    register_Sock->connectToHost("192.168.137.84", 8080);
}

DialogRegister::~DialogRegister()
{
    delete ui;
    this->setModal(true);
}

void DialogRegister::on_pushButton_clicked()
{
    this->hide();
}


void DialogRegister::on_pushButton_registre_clicked()
{
    QString username = ui->lineEdit_user->text();
    QString password = ui->lineEdit_passwd->text();
    QString passwordSure = ui->lineEdit_sure->text();

    if(username.isEmpty() ||  password.isEmpty() || passwordSure.isEmpty())
    {
        QMessageBox::information(this,"提示","请输入用户名或密码!");
        return;
    } else if(password != passwordSure)
    {
        QMessageBox::information(this,"提示","两次输入密码不一致!");
        return;
    }
    // 发送注册请求
    QString request = "REGISTER " + username + " " + password;
    register_Sock->write(request.toUtf8());
}

