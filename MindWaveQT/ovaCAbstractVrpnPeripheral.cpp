#include <iostream>
#include "stdafx.h"
#include "ovaCAbstractVrpnPeripheral.h"
#include <vrpn_Button.h>

using namespace OpenViBEVRDemos;

class CDeviceInfo
{
public:

	std::string m_sAddress;
	vrpn_Button_Remote* m_pButton;

};

namespace
{
	void VRPN_CALLBACK handle_button(void* pUserData, const vrpn_BUTTONCB b)
	{
        CAbstractVrpnPeripheral* l_pAbstractVrpnPeripheral = (CAbstractVrpnPeripheral *)pUserData;
		std::pair < int, int > l_oVrpnButtonState;
		l_oVrpnButtonState.first=b.button;
        l_oVrpnButtonState.second=b.state;
        l_pAbstractVrpnPeripheral->blink_count++;
        std::cout << l_pAbstractVrpnPeripheral->blink_count << ". mrk" << std::endl;
        l_pAbstractVrpnPeripheral->playAnimation();
		l_pAbstractVrpnPeripheral->m_vButton.push_back(l_oVrpnButtonState);
	}

}

CAbstractVrpnPeripheral::CAbstractVrpnPeripheral(void)
{
	blink_count = 0;
	m_sDeviceAddress = "openvibe-vrpn@localhost";
    init();
}

CAbstractVrpnPeripheral::CAbstractVrpnPeripheral(const std::string serverName)
{
	blink_count = 0;
	m_sDeviceAddress = serverName;
    init();
}

CAbstractVrpnPeripheral::CAbstractVrpnPeripheral(MainWindow *w)
{
    blink_count = 0;
    m_sDeviceAddress = "openvibe-vrpn@localhost";
    window = w;
    init();
}

CAbstractVrpnPeripheral::~CAbstractVrpnPeripheral(void)
{
}

void CAbstractVrpnPeripheral::init(void)
{
	m_pDevice=new CDeviceInfo;
	m_pDevice->m_sAddress=m_sDeviceAddress;
	m_pDevice->m_pButton=new vrpn_Button_Remote(m_sDeviceAddress.c_str());
	m_pDevice->m_pButton->register_change_handler(this, &handle_button);
    print("Connection initialized!");
    connect(this, &CAbstractVrpnPeripheral::makeItHappen, window, &MainWindow::doWork);
}

void CAbstractVrpnPeripheral::loop(void)
{
    m_pDevice->m_pButton->mainloop();
}

void CAbstractVrpnPeripheral::print(QString string)
{
    window->print(string);
}


void CAbstractVrpnPeripheral::playAnimation()
{
   emit makeItHappen();
}

