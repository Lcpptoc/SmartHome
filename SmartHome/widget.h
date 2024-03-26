#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "dialoglog.h"
#include "ledwidget.h"
#include "localhouse.h"
#include "envwidget.h"
#include "mqttwidget.h"
#include "fanwidget.h"
#include "beeperwidget.h"
#include "eventswidget.h"
#include "vibratorwidget.h"
#include "fsmpEvents.h"
#include "camerawidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::Widget *ui;

    DialogLog *diaLog;

    LedWidget *ledWidget; //灯窗口

    LocalHouse *locHouse; //信号处理

    Envwidget *envWidget; //温湿度

    Mqttwidget *mqttWidget; // mqtt 界面控制本地的灯

    FanWidget *fanWidget; //风扇

    BeeperWidget *beeperWidget; // 蜂鸣器

    EventsWidget *eventsWidget; //检测

    VibratorWidget *vibratorWidget; // 马达

    fsmpEvents *fsEvents; // 扩展板

    CameraWidget *cameraWidget; //摄像头

};
#endif // WIDGET_H
