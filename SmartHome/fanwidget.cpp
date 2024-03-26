#include "fanwidget.h"
#include "ui_fanwidget.h"

FanWidget::FanWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FanWidget)
{
    ui->setupUi(this);
}

FanWidget::~FanWidget()
{
    delete ui;
}

void FanWidget::on_pushButton_return_clicked()
{
    this->close();
}


void FanWidget::on_pushButton_on_clicked()
{
    static bool flag = true;
    if(flag)
    {
        emit fan_ctrl(flag);
        ui->pushButton_on->setText("关");
    }
    else
    {
        emit fan_ctrl(flag);
        ui->pushButton_on->setText("开");
    }

    flag = !flag;
}

