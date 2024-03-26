#ifndef LOCALHOUSE_H
#define LOCALHOUSE_H

#include <QObject>
#include "fsmpLed.h"
#include "fsmpFan.h"
#include "fsmpTempHum.h"
#include <QTimer>
#include "fsmpBeeper.h"
#include "fsmpVibrator.h"
#include "fsmpLight.h"


class LocalHouse : public QObject
{
    Q_OBJECT
public:
    explicit LocalHouse(QObject *parent = nullptr);

signals:
    void sendTemHumData(double tem, double hum);
    void sendLightData(double light);
private slots:
    void ctrl_led(bool flag, int id);
    void getHumTemData();
    void getLightData();
    void ctrl_fan(bool flag);
    void ctrl_beeper(bool flag);
    void press_led(int keynum);
    void relese_led(int keynum);
    void ctrl_vibrator(bool flag);


private:
    fsmpLeds *fsLed;
    QTimer *timer;
    fsmpTempHum *tem_hum;
    fsmpFan *fsFan;
    fsmpBeeper *fsBeeper;
    fsmpVibrator *fsVibrator;

    fsmpLight *fsLight;
};

#endif // LOCALHOUSE_H
