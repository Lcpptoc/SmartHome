#ifndef CAMERAWIDGET_H
#define CAMERAWIDGET_H

#include <QWidget>
#include "fsmpCamera_v1.h"

namespace Ui {
class CameraWidget;
}

class CameraWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CameraWidget(QWidget *parent = nullptr);
    ~CameraWidget();

private slots:
    void showCamera(QImage img);
private:
    Ui::CameraWidget *ui;
    fsmpCamera *cam;
};

#endif // CAMERAWIDGET_H
