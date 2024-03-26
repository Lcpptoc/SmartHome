#include "camerawidget.h"
#include "ui_camerawidget.h"

CameraWidget::CameraWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CameraWidget)
{
    ui->setupUi(this);
    cam = new fsmpCamera;
    connect(cam, SIGNAL(currentImage(QImage)),this,SLOT(showCamera(QImage)));
    cam->start();
}

CameraWidget::~CameraWidget()
{
    delete ui;
}

void CameraWidget::showCamera(QImage img)
{
    ui->label->setPixmap(QPixmap::fromImage(img));
}
