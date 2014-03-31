// Mrkani.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ovaCAbstractVrpnPeripheral.h"
#include <OIS.h>
#include <Windows.h>

using namespace OpenViBEVRDemos;
using namespace std;

bool running;


int _tmain(int argc, _TCHAR* argv[])
{
	running = true;
	cout << "Setting connection" << endl;
	CAbstractVrpnPeripheral *conn = new CAbstractVrpnPeripheral();
	cout << "Initializing connection" << endl;
	(*conn).init();
	cout << "Starting communication" << endl;

	while (running)
	{
		(*conn).loop();

		if (GetAsyncKeyState(VK_ESCAPE)){
			std::cout << "Ending proces" << std::endl;
			running = false;
		}
		
	}

	Sleep(2000);
	return 0;
}

