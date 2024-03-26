#include "beeperwidget.h"
#include "ui_beeperwidget.h"

BeeperWidget::BeeperWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BeeperWidget)
{
    ui->setupUi(this);
}

BeeperWidget::~BeeperWidget()
{
    delete ui;
}

void BeeperWidget::on_pushButton_on_clicked()
{
    static bool flag = true;
    if(flag)
    {
        ui->pushButton_on->setText("关");
        emit sendBeeper(flag);
    }
    else
    {
        ui->pushButton_on->setText("开");
        emit sendBeeper(flag);
    }
    flag = !flag;
}


void BeeperWidget::on_pushButton_return_clicked()
{
    this->close();
}

