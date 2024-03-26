#include "eventswidget.h"
#include "ui_eventswidget.h"

EventsWidget::EventsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EventsWidget)
{
    ui->setupUi(this);
}

EventsWidget::~EventsWidget()
{
    delete ui;
}

void EventsWidget::peopleData(bool detected)
{
    if(detected)
    {
        ui->lineEdit_human->setText("发现人类");
    }
    else
    {
        ui->lineEdit_human->setText("暂时没有发现人类");
    }
}

void EventsWidget::on_pushButton_return_clicked()
{
    this->close();
}

