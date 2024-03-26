#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setScaledContents(true);

    cam = new fsmpCamera;
    connect(cam, &fsmpCamera::currentImage, [&](QImage img){
       ui->label->setPixmap(QPixmap::fromImage(img));
    });
    cam->start();
}

Widget::~Widget()
{
    delete ui;
}

