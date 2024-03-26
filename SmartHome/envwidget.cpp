#include "envwidget.h"
#include "ui_envwidget.h"

Envwidget::Envwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Envwidget)
{
    ui->setupUi(this);
}

Envwidget::~Envwidget()
{
    delete ui;
}

void Envwidget::on_pushButton_clicked()
{
    this->hide();
}

void Envwidget::showTemHumData(double tem, double hum)
{
    ui->lineEdit_tem->setText(QString::number(tem));
    ui->lineEdit_hum->setText(QString::number(hum));
}

void Envwidget::showLightData(double light)
{
    ui->lineEdit_light->setText(QString::number(light));
    ui->lineEdit_light->setText(QString::number(0));
}

