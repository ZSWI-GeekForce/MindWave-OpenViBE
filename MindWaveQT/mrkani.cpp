// Mrkani.cpp : Defines the entry point for the console application.
//

#include <QApplication>
//#include <Windows.h>
//#include "stdafx.h"
//#include "ovaCAbstractVrpnPeripheral.h"
#include "mainwindow.h"


using namespace OpenViBEVRDemos;
using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("MindWaveQT");
    w.show();

    return a.exec();
}

