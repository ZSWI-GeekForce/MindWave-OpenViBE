// Mrkani.cpp : Defines the entry point for the console application.
//

#include <QApplication>
#include <Windows.h>
#include "stdafx.h"
#include "ovaCAbstractVrpnPeripheral.h"
#include "mainwindow.h"


using namespace OpenViBEVRDemos;
using namespace std;

bool running;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("MindWaveQT");
    w.show();


    running = true;
    //cout << "Setting connection" << endl;
    w.print("Setting connection");
    CAbstractVrpnPeripheral *conn = new CAbstractVrpnPeripheral();
    //cout << "Initializing connection" << endl;
    w.print("Initializing connection");
    (*conn).init();
   // cout << "Starting communication" << endl;
    w.print("Starting communication");
   /* while (running)
    {
        (*conn).loop();

        if (GetAsyncKeyState(VK_ESCAPE)){
            std::cout << "Ending proces" << std::endl;
            running = false;
        }

    }
*/
    conn->~CAbstractVrpnPeripheral();
    return a.exec();
/*
    Sleep(2000);
    return 0;
    */
}

