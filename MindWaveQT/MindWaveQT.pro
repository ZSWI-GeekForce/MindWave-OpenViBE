#-------------------------------------------------
#
# Project created by QtCreator 2014-04-22T11:10:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MindWaveQT
TEMPLATE = app


SOURCES +=\
    mainwindow.cpp \
    mrkani.cpp \
    ovaCAbstractVrpnPeripheral.cpp \
    stdafx.cpp

HEADERS  +=\
    ovaCAbstractVrpnPeripheral.h \
    stdafx.h \
    targetver.h \
    vrpn_Button.h \
    vrpn_BaseClass.h \
    vrpn_Configure.h \
    vrpn_Connection.h \
    vrpn_Serial.h \
    vrpn_Shared.h \
    vrpn_Types.h \
    mainwindow.h

FORMS    += \
    mainwindow.ui

QMAKE_LFLAGS += /INCREMENTAL:NO

win32:CONFIG(release, debug|release): LIBS += $$PWD/vrpn.lib
else:win32:CONFIG(debug, debug|release): LIBS += $$PWD/vrpn.lib

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/
