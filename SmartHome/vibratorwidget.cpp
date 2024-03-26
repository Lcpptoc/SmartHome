#include "vibratorwidget.h"
#include "ui_vibratorwidget.h"

VibratorWidget::VibratorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VibratorWidget)
{
    ui->setupUi(this);
}

VibratorWidget::~VibratorWidget()
{
    delete ui;
}

void VibratorWidget::on_pushButton_return_clicked()
{
    this->close();
}


void VibratorWidget::on_pushButton_on_clicked()
{
    static bool flag = true;
    if(flag)
    {
        emit vibrator_ctrl(flag);
        ui->pushButton_on->setText("关");
    }
    else
    {
        emit vibrator_ctrl(flag);
        ui->pushButton_on->setText("开");
    }

    flag = !flag;
}

