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
        CAbstractVrpnPeripheral* vrpnPeripheral = (CAbstractVrpnPeripheral *)pUserData;
		std::pair < int, int > l_oVrpnButtonState;
		l_oVrpnButtonState.first=b.button;
        l_oVrpnButtonState.second=b.state;
        vrpnPeripheral->playAnimation();
        vrpnPeripheral->m_vButton.push_back(l_oVrpnButtonState);
	}
}

CAbstractVrpnPeripheral::CAbstractVrpnPeripheral(void)
{


   m_dAnalogScale=1;
	m_dAnalogOffset=0;
	m_sDeviceAddress = "openvibe-vrpn@localhost";
    init();
}

CAbstractVrpnPeripheral::CAbstractVrpnPeripheral(const std::string serverName)
{

	m_dAnalogScale=1;
	m_dAnalogOffset=0;
    m_sDeviceAddress = serverName;
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
}

void CAbstractVrpnPeripheral::loop(void)
{
    m_pDevice->m_pButton->mainloop();
}

void CAbstractVrpnPeripheral::playAnimation()
{
  emit resultReady();
}

void CAbstractVrpnPeripheral::doWork(void)
{
    bool running = true;

    while(running){
        loop();
    }
}
