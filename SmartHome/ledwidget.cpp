#include "ledwidget.h"
#include "ui_ledwidget.h"

LedWidget::LedWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LedWidget)
{
    ui->setupUi(this);
}

LedWidget::~LedWidget()
{
    delete ui;
}

void LedWidget::on_pushButton_return_clicked()
{
    this->close();
    emit showWidget();
}


void LedWidget::on_pushButton_1_clicked()
{
    static bool flag = true;
    if(flag)
    {
        emit led_locl(flag,0);
        ui->pushButton_1->setText("关灯");
    }
    else
    {
        emit led_locl(flag,0);
        ui->pushButton_1->setText("开灯");
    }

    flag = !flag;
}



void LedWidget::on_pushButton_2_clicked()
{
    static bool flag = true;
    if(flag)
    {
        emit led_locl(flag,1);
        ui->pushButton_2->setText("关灯");
    }
    else
    {
        emit led_locl(flag,1);
        ui->pushButton_2->setText("开灯");
    }

    flag = !flag;
}


void LedWidget::on_pushButton_3_clicked()
{
    static bool flag = true;
    if(flag)
    {
        emit led_locl(flag,2);
        ui->pushButton_3->setText("关灯");
    }
    else
    {
        emit led_locl(flag,2);
        ui->pushButton_3->setText("开灯");
    }

    flag = !flag;
}

