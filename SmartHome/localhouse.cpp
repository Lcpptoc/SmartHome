#include "localhouse.h"

LocalHouse::LocalHouse(QObject *parent) : QObject(parent)
{
    fsLed = new fsmpLeds();
    tem_hum = new fsmpTempHum;

    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(getHumTemData()));
    timer->start(1000);

    fsFan = new fsmpFan();
    fsBeeper = new fsmpBeeper();
    fsVibrator = new fsmpVibrator();
    fsLight = new fsmpLight();
}

void LocalHouse::ctrl_led(bool flag, int id)
{
    switch (id) {
    case 0:
        flag ? fsLed->on(fsLed->LED1) : fsLed->off(fsLed->LED1);
        break;
    case 1:
        flag ? fsLed->on(fsLed->LED2) : fsLed->off(fsLed->LED2);
        break;
    case 2:
        flag ? fsLed->on(fsLed->LED3) : fsLed->off(fsLed->LED3);
        break;
    default:
        break;
    }
}
void LocalHouse::getHumTemData()
{
    //得到并发送温湿度数据
    emit sendTemHumData(tem_hum->temperature(), tem_hum->humidity());

//    qDebug() << "tem: " << tem;
    //    qDebug() << "hum: " << hum;
}

void LocalHouse::getLightData()
{
    //得到并发送光照数据
    emit sendLightData(fsLight->getValue());

}

void LocalHouse::ctrl_fan(bool flag)
{
    fsFan->setSpeed(100);
    flag ? fsFan->start() : fsFan->stop();
}


void LocalHouse::ctrl_beeper(bool flag)
{
    fsBeeper->setRate(1000);
    flag ? fsBeeper->start() : fsBeeper->stop();
}

void LocalHouse::press_led(int keynum)
{
    switch (keynum) {
    case 1:
        fsLed->on(fsLed->LED1);
        break;
    case 2:
        fsLed->on(fsLed->LED2);
        break;
    case 3:
        fsLed->on(fsLed->LED3);
        break;
    default:
        break;
    }
}

void LocalHouse::relese_led(int keynum)
{
    switch (keynum) {
    case 1:
        fsLed->off(fsLed->LED1);
        break;
    case 2:
        fsLed->off(fsLed->LED2);
        break;
    case 3:
        fsLed->off(fsLed->LED3);
        break;
    default:
        break;
    }
}


void LocalHouse::ctrl_vibrator(bool flag)
{
    fsVibrator->setParameter(0xFFFF,2000);
    flag ? fsVibrator->start() : fsVibrator->stop();
}

