#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->hide();

    ledWidget = new LedWidget();
    locHouse = new LocalHouse();
    envWidget = new Envwidget();
    mqttWidget = new Mqttwidget();
    fanWidget = new FanWidget();
    beeperWidget = new BeeperWidget();
    eventsWidget = new EventsWidget();
    vibratorWidget = new VibratorWidget();
    cameraWidget = new CameraWidget();

    fsEvents = new fsmpEvents();

    //显示登录
    diaLog = new DialogLog();
    diaLog->show();

    connect(diaLog,&DialogLog::showWidget,this,[=](){
        this->show();
    });

    //led灯
    connect(ledWidget,SIGNAL(led_locl(bool,int)),locHouse,SLOT(ctrl_led(bool, int)));
    //界面显示
    connect(ledWidget,&LedWidget::showWidget,this,[=](){
        this->show();
    });

    //灯
    connect(mqttWidget, SIGNAL(sig_localLed(bool, int)), locHouse, SLOT(ctrl_led(bool, int)));
    //温湿度
    connect(locHouse, SIGNAL(sendTemHumData(double, double)), envWidget, SLOT(showTemHumData(double, double)));
    connect(locHouse, SIGNAL(sendTemHumData(double, double)), mqttWidget, SLOT(pub_TemHumData(double, double)));
    //光照
    connect(locHouse, SIGNAL(sendLightData(double)), envWidget, SLOT(showLightData(double)));
    connect(locHouse, SIGNAL(sendLightData(double)), mqttWidget, SLOT(pub_LightData(double)));
    //风扇
    connect(fanWidget,SIGNAL(fan_ctrl(bool)),locHouse,SLOT(ctrl_fan(bool)));
    connect(mqttWidget,SIGNAL(sig_localFan(bool)),locHouse,SLOT(ctrl_fan(bool)));

    //蜂鸣器
    connect(beeperWidget,SIGNAL(sendBeeper(bool)),locHouse,SLOT(ctrl_beeper(bool)));
    connect(mqttWidget,SIGNAL(sig_beeper(bool)),locHouse,SLOT(ctrl_beeper(bool)));

    //人体红外
    connect(fsEvents,SIGNAL(peopleDetected(bool)),eventsWidget,SLOT(peopleData(bool)));
    connect(fsEvents,SIGNAL(peopleDetected(bool)),mqttWidget,SLOT(pub_InfraredData(bool)));
    //按键按下
    connect(fsEvents,SIGNAL(keyPressed(int)),locHouse,SLOT(press_led(int)));
    //按键释放
    connect(fsEvents,SIGNAL(keyRelessed(int)),locHouse,SLOT(relese_led(int)));

    //马达
    connect(vibratorWidget,SIGNAL(vibrator_ctrl(bool)),locHouse,SLOT(ctrl_vibrator(bool)));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    //this->hide();
    ledWidget->show();
}


void Widget::on_pushButton_2_clicked()
{
    //this->hide();
    envWidget->show();
}


void Widget::on_pushButton_3_clicked()
{
    mqttWidget->show();
}


void Widget::on_pushButton_4_clicked()
{
    fanWidget->show();
}


void Widget::on_pushButton_5_clicked()
{
    beeperWidget->show();
}


void Widget::on_pushButton_6_clicked()
{
    eventsWidget->show();
}


void Widget::on_pushButton_7_clicked()
{
    vibratorWidget->show();
}


void Widget::on_pushButton_8_clicked()
{
    cameraWidget->show();
}

