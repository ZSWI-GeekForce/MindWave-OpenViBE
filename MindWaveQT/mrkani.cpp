// Mrkani.cpp : Defines the entry point for the console application.
//

#include <QApplication>
#include <Windows.h>
#include "stdafx.h"
#include "ovaCAbstractVrpnPeripheral.h"
#include "mainwindow.h"


using namespace OpenViBEVRDemos;
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.running = true;
    w.setWindowTitle("MindWaveQT");
    w.show();
    CAbstractVrpnPeripheral *conn = new CAbstractVrpnPeripheral(&w);
    conn->setParent(&w);
    while(w.running){
        QCoreApplication::processEvents();
        conn->loop();

  /*      if (GetAsyncKeyState(VK_ESCAPE)){
                    w.print("Ending process");
                    QCoreApplication::processEvents();
                    Sleep(2000);
                    w.running = false;
       }*/
    }
    return 0;
}

