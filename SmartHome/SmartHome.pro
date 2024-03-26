QT       += core gui mqtt network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    beeperwidget.cpp \
    camerawidget.cpp \
    dialoglog.cpp \
    dialogregister.cpp \
    envwidget.cpp \
    eventswidget.cpp \
    fanwidget.cpp \
    fsmpCamera_v1.cpp \
    fsmpKeyboard/keyboard.cpp \
    ledwidget.cpp \
    localhouse.cpp \
    main.cpp \
    mqttwidget.cpp \
    vibratorwidget.cpp \
    widget.cpp

HEADERS += \
    beeperwidget.h \
    camerawidget.h \
    dialoglog.h \
    dialogregister.h \
    envwidget.h \
    eventswidget.h \
    fanwidget.h \
    fsmpBeeper.h \
    fsmpCamera_v1.h \
    fsmpEvents.h \
    fsmpFan.h \
    fsmpKeyboard/keyboard.h \
    fsmpLed.h \
    fsmpLight.h \
    fsmpTempHum.h \
    fsmpVibrator.h \
    ledwidget.h \
    localhouse.h \
    mqttwidget.h \
    vibratorwidget.h \
    widget.h

FORMS += \
    beeperwidget.ui \
    camerawidget.ui \
    dialoglog.ui \
    dialogregister.ui \
    envwidget.ui \
    eventswidget.ui \
    fanwidget.ui \
    fsmpKeyboard/keyboard.ui \
    ledwidget.ui \
    mqttwidget.ui \
    vibratorwidget.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    fsmpKeyboard/ziku/ziku.qrc \
    res.qrc

DISTFILES += \
    fsmpKeyboard/ziku/ziku.dat
