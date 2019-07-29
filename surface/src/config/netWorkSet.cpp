#include "netWorkSet.h"

NetWorkSet::NetWorkSet(QWidget *parent):QWidget(parent)
{
    dhcpLabel = new QLabel("DHCP");
    dhcpCombox = new QComboBox;
    dhcpCombox->addItem("Off");
    dhcpCombox->addItem("On");

    ipaddrLabel = new QLabel("IP Address");
    ipaddrEdit = new QLineEdit;

    subMaskLabel = new QLabel("Subnet Mask");
    subMaskEdit = new QLineEdit;

    gateWayLabel = new QLabel("Gateway");
    gateWayEdit = new QLineEdit;

    dnsLabel = new QLabel("Dns");
    dnsCombox = new QComboBox;
    dnsCombox->addItem("Manual");
    dnsCombox->addItem("Auto");
    dnsEdit = new QLineEdit;

    hostnameLabel = new QLabel("Host Name");
    hostnameCombox = new QComboBox;
    hostnameCombox->addItem("Manual");
    hostnameCombox->addItem("Auto");
    hostnameEdit = new QLineEdit;

    httpPortsLabel = new QLabel("Http Ports");
    httpCombox = new QComboBox;
    httpCombox->addItem("Enable");
    httpCombox->addItem("Disable");
    httpPortsEdit = new QLineEdit;

    httpsPortsLabel = new QLabel("Https Ports");
    httpsCombox = new QComboBox;
    httpsCombox->addItem("Enable");
    httpsCombox->addItem("Disable");
    httpsPortsEdit = new QLineEdit;

    rtspPortsLabel = new QLabel("Rtsp Ports");
    rtspCombox = new QComboBox;
    rtspCombox->addItem("Enable");
    rtspCombox->addItem("Disable");
    rtspPortsEdit = new QLineEdit;

    zeroLable = new QLabel("Enable Zero Config");
    zeroText = new QCheckBox("none");//169.254.134.138

    onvifDisLabel = new QLabel("Onvif Discovery Mode");
    onvifCombox   = new QComboBox;
    onvifCombox->addItem("Non-Discoveyable");
    onvifCombox->addItem("Discoveyable");


    applyBtn = new QPushButton("apply");

    QGridLayout *layoutGrid = new QGridLayout;
    layoutGrid->addWidget(dhcpLabel,0,0);
    layoutGrid->addWidget(dhcpCombox,0,1,1,2);
    layoutGrid->addWidget(ipaddrLabel,1,0);
    layoutGrid->addWidget(ipaddrEdit,1,1,1,2);
    layoutGrid->addWidget(subMaskLabel,2,0);
    layoutGrid->addWidget(subMaskEdit,2,1,1,2);
    layoutGrid->addWidget(gateWayLabel,3,0);
    layoutGrid->addWidget(gateWayEdit,3,1,1,2);

    layoutGrid->addWidget(dnsLabel,4,0);
    layoutGrid->addWidget(dnsCombox,4,1);
    layoutGrid->addWidget(dnsEdit,4,2);
    layoutGrid->addWidget(hostnameLabel,5,0);
    layoutGrid->addWidget(hostnameCombox,5,1);
    layoutGrid->addWidget(hostnameEdit,5,2);

    layoutGrid->addWidget(httpPortsLabel,6,0);
    layoutGrid->addWidget(httpCombox,6,1);
    layoutGrid->addWidget(httpPortsEdit,6,2);
    layoutGrid->addWidget(httpsPortsLabel,7,0);
    layoutGrid->addWidget(httpsCombox,7,1);
    layoutGrid->addWidget(httpsPortsEdit,7,2);
    layoutGrid->addWidget(rtspPortsLabel,8,0);
    layoutGrid->addWidget(rtspCombox,8,1);
    layoutGrid->addWidget(rtspPortsEdit,8,2);

    layoutGrid->addWidget(zeroLable,9,0);
    layoutGrid->addWidget(zeroText,9,1,1,2);

    layoutGrid->addWidget(onvifDisLabel,10,0);
    layoutGrid->addWidget(onvifCombox,10,1,1,2);
    QHBoxLayout *layoutApplyBtn = new QHBoxLayout;
    layoutApplyBtn->addStretch();
    layoutApplyBtn->addWidget(applyBtn);
    layoutGrid->addLayout(layoutApplyBtn,11,2);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *layoutmain = new QVBoxLayout;
    layoutmain->addLayout(layoutInter);
    layoutmain->addStretch();

    setLayout(layoutmain);

}
void NetWorkSet::doUpdateWgt(UrlInfo info)
{
    this->info = info;
    if(info.type == "onvif")
    {
        int ret = SOAP_ERR;
        TimeDateUser syncTime;
        DeviceBindingProxy deviceMg;

        std::string strUrl = info.url.toStdString();
        std::string strUsr = info.user.toStdString();
        std::string strPass = info.passWord.toStdString();
        _tds__GetNetworkInterfaces reqGetNetworkInterfaces;
        _tds__GetNetworkInterfacesResponse resGetNetworkInterfaces;
        _tds__GetZeroConfiguration reqGetZeroConfiguration;
        _tds__GetZeroConfigurationResponse resGetZeroConfiguration;
        _tds__GetHostname reqGetHostname;
        _tds__GetHostnameResponse resGetHostname;
        _tds__GetNetworkProtocols reqGetNetworkProtocols;
        _tds__GetNetworkProtocolsResponse resGetNetworkProtocols;
        _tds__GetNetworkDefaultGateway reqGetNetworkDefaultGateway;
        _tds__GetNetworkDefaultGatewayResponse resGetNetworkDefaultGateway;
        _tds__GetDNS reqGetDNS;
        _tds__GetDNSResponse resGetDNS;
        _tds__GetDiscoveryMode reqGetDiscoveryMode;
        _tds__GetDiscoveryModeResponse resGetDiscoveryMode;
        _tds__GetSystemDateAndTime reqGetSystemDateAndTime;
        _tds__GetSystemDateAndTimeResponse resGetSystemDateAndTime;
        deviceMg.soap_endpoint = strUrl.c_str();
        ret = deviceMg.GetSystemDateAndTime(&reqGetSystemDateAndTime, &resGetSystemDateAndTime);
        if(ret != SOAP_OK)
        {
            return;
        }
        syncTime.setTimeDate(resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Date->Year,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Date->Month,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Date->Day,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Time->Hour,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Time->Minute,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Time->Second,
                             0);
        if(info.user != "none" && info.passWord != "none")
        {
            soap_wsse_add_UsernameTokenDigestCreated((soap *)&deviceMg, "User",
                                                     strUsr.c_str(),strPass.c_str(),syncTime.created());
        }
        ret = deviceMg.GetNetworkInterfaces(&reqGetNetworkInterfaces,&resGetNetworkInterfaces);
        if(ret != SOAP_OK)
        {
            return;
        }
        if(info.user != "none" && info.passWord != "none")
        {
            soap_wsse_add_UsernameTokenDigestCreated((soap *)&deviceMg, "User",
                                                     strUsr.c_str(),strPass.c_str(),syncTime.created());
        }
        ret = deviceMg.GetZeroConfiguration(&reqGetZeroConfiguration,&resGetZeroConfiguration);
        if(ret != SOAP_OK)
        {
            return;
        }
        if(info.user != "none" && info.passWord != "none")
        {
            soap_wsse_add_UsernameTokenDigestCreated((soap *)&deviceMg, "User",
                                                     strUsr.c_str(),strPass.c_str(),syncTime.created());
        }
        ret = deviceMg.GetHostname(&reqGetHostname,&resGetHostname);
        if(ret != SOAP_OK)
        {
            return;
        }
        if(info.user != "none" && info.passWord != "none")
        {
            soap_wsse_add_UsernameTokenDigestCreated((soap *)&deviceMg, "User",
                                                     strUsr.c_str(),strPass.c_str(),syncTime.created());
        }
        ret = deviceMg.GetNetworkProtocols(&reqGetNetworkProtocols,&resGetNetworkProtocols);
        if(ret != SOAP_OK)
        {
            return;
        }
        if(info.user != "none" && info.passWord != "none")
        {
            soap_wsse_add_UsernameTokenDigestCreated((soap *)&deviceMg, "User",
                                                     strUsr.c_str(),strPass.c_str(),syncTime.created());
        }
        ret = deviceMg.GetNetworkDefaultGateway(&reqGetNetworkDefaultGateway,&resGetNetworkDefaultGateway);
        if(ret != SOAP_OK)
        {
            return;
        }
        if(info.user != "none" && info.passWord != "none")
        {
            soap_wsse_add_UsernameTokenDigestCreated((soap *)&deviceMg, "User",
                                                     strUsr.c_str(),strPass.c_str(),syncTime.created());
        }
        ret = deviceMg.GetDNS(&reqGetDNS,&resGetDNS);
        if(ret != SOAP_OK)
        {
            return;
        }
        if(info.user != "none" && info.passWord != "none")
        {
            soap_wsse_add_UsernameTokenDigestCreated((soap *)&deviceMg, "User",
                                                     strUsr.c_str(),strPass.c_str(),syncTime.created());
        }
        ret = deviceMg.GetDiscoveryMode(&reqGetDiscoveryMode,&resGetDiscoveryMode);
        if(ret != SOAP_OK)
        {
            return;
        }

        if(resGetNetworkInterfaces.__sizeNetworkInterfaces > 0 &&
                resGetNetworkInterfaces.NetworkInterfaces != NULL &&
                *resGetNetworkInterfaces.NetworkInterfaces != NULL)
        {
            tt__NetworkInterface *NetworkInterfaces = resGetNetworkInterfaces.NetworkInterfaces[0];
            if(NetworkInterfaces->Enabled)
            {
                if(NetworkInterfaces->IPv4 != NULL &&
                        NetworkInterfaces->IPv4->Enabled &&
                        NetworkInterfaces->IPv4->Config != NULL
                        )
                {
                    if(NetworkInterfaces->IPv4->Config->__sizeManual > 0 &&
                            NetworkInterfaces->IPv4->Config->Manual != NULL &&
                            *NetworkInterfaces->IPv4->Config->Manual != NULL)
                    {
                        tt__PrefixedIPv4Address *Manual = NetworkInterfaces->IPv4->Config->Manual[0];
                        ipaddrEdit->setText(Manual->Address);
                        dhcpCombox->setCurrentIndex(0);
                        QString strSubMask;
                        unsigned int subMask = 1;
                        unsigned char *ptSubMask = (char *)&subMask;
                        for(int i = 0;i < Manual->PrefixLength;++i)
                        {
                            subMask = subMask << 1 | 0x1;
                        }
                        subMask = subMask<<(32 - Manual->PrefixLength);
                        if(ptSubMask[0] > ptSubMask[3])
                        {
                            strSubMask.sprintf("%d.%d.%d.%d",ptSubMask[0],ptSubMask[1],ptSubMask[2],ptSubMask[3]);
                        }
                        else
                        {
                            strSubMask.sprintf("%d.%d.%d.%d",ptSubMask[3],ptSubMask[2],ptSubMask[1],ptSubMask[0]);
                        }

                        subMaskEdit->setText(strSubMask);

                    }
                    else if(NetworkInterfaces->IPv4->Config->DHCP &&
                            NetworkInterfaces->IPv4->Config->FromDHCP)
                    {
                        ipaddrEdit->setText(NetworkInterfaces->IPv4->Config->FromDHCP->Address);
                        dhcpCombox->setCurrentIndex(1);
                        QString strSubMask;
                        unsigned int subMask = 1;
                        unsigned char *ptSubMask = (char *)&subMask;
                        for(int i = 0;i < NetworkInterfaces->IPv4->Config->FromDHCP->PrefixLength;++i)
                        {
                            subMask = subMask << 1 | 0x1;
                        }
                        subMask = subMask<<(32 - NetworkInterfaces->IPv4->Config->FromDHCP->PrefixLength);
                        if(ptSubMask[0] > ptSubMask[3])
                        {
                            strSubMask.sprintf("%d.%d.%d.%d",ptSubMask[0],ptSubMask[1],ptSubMask[2],ptSubMask[3]);
                        }
                        else
                        {
                            strSubMask.sprintf("%d.%d.%d.%d",ptSubMask[3],ptSubMask[2],ptSubMask[1],ptSubMask[0]);
                        }

                        subMaskEdit->setText(strSubMask);
                    }
                }
            }
        }
        if(resGetNetworkDefaultGateway.NetworkGateway != NULL)
        {
            if(resGetNetworkDefaultGateway.NetworkGateway->__sizeIPv4Address != 0)
            {
                gateWayEdit->setText(resGetNetworkDefaultGateway.NetworkGateway->IPv4Address[0]);
            }
            else if(resGetNetworkDefaultGateway.NetworkGateway->__sizeIPv6Address)
            {
                gateWayEdit->setText(resGetNetworkDefaultGateway.NetworkGateway->IPv6Address[0]);
            }
        }
        if(resGetDNS.DNSInformation)
        {
            if(resGetDNS.DNSInformation->FromDHCP && resGetDNS.DNSInformation->__sizeDNSFromDHCP &&
                    resGetDNS.DNSInformation->DNSFromDHCP != NULL &&
                    *resGetDNS.DNSInformation->DNSFromDHCP)
            {
                dnsCombox->setCurrentIndex(1);
                tt__IPAddress **DNSFromDHCP = resGetDNS.DNSInformation->DNSFromDHCP;
                if(DNSFromDHCP[0]->Type == tt__IPType__IPv4)
                    dnsEdit->setText(DNSFromDHCP[0]->IPv4Address);
                else if(DNSFromDHCP[0]->Type == tt__IPType__IPv6)
                {
                    dnsEdit->setText(DNSFromDHCP[0]->IPv6Address);
                }
            }
        }
        if(resGetHostname.HostnameInformation)
        {
            if(resGetHostname.HostnameInformation->FromDHCP)
            {
                hostnameCombox->setCurrentIndex(1);
            }
            else
            {
                 hostnameCombox->setCurrentIndex(0);
            }
            if(resGetHostname.HostnameInformation->Name)
                hostnameEdit->setText(resGetHostname.HostnameInformation->Name);
        }
        if(resGetNetworkProtocols.__sizeNetworkProtocols > 0 &&
                resGetNetworkProtocols.NetworkProtocols)
        {
            tt__NetworkProtocol **NetworkProtocols = resGetNetworkProtocols.NetworkProtocols;
            for(int i = 0; i < resGetNetworkProtocols.__sizeNetworkProtocols;++i)
            {
                QString strPort;
                for(int j = 0;j < NetworkProtocols[i]->__sizePort;++j)
                {
                    strPort.append(QString::number(NetworkProtocols[i]->Port[j]));
                }

                if(NetworkProtocols[i]->Name == tt__NetworkProtocolType__HTTP)
                {
                    if(NetworkProtocols[i]->Enabled)
                    {
                        httpCombox->setCurrentIndex(0);
                    }
                    else
                    {
                        httpCombox->setCurrentIndex(1);
                    }
                    httpPortsEdit->setText(strPort);
                }
                else if(NetworkProtocols[i]->Name == tt__NetworkProtocolType__HTTPS)
                {
                    if(NetworkProtocols[i]->Enabled)
                    {
                        httpsCombox->setCurrentIndex(0);
                    }
                    else
                    {
                        httpsCombox->setCurrentIndex(1);
                    }
                    httpsPortsEdit->setText(strPort);
                }
                else if(NetworkProtocols[i]->Name == tt__NetworkProtocolType__RTSP)
                {
                    if(NetworkProtocols[i]->Enabled)
                    {
                        rtspCombox->setCurrentIndex(0);
                    }
                    else
                    {
                        rtspCombox->setCurrentIndex(1);
                    }
                    rtspPortsEdit->setText(strPort);
                }
            }
        }
        if(resGetZeroConfiguration.ZeroConfiguration)
        {
            if(resGetZeroConfiguration.ZeroConfiguration->Enabled)
            {
                zeroText->setChecked(true);
                if(resGetZeroConfiguration.ZeroConfiguration->Addresses)
                    zeroText->setText(resGetZeroConfiguration.ZeroConfiguration->Addresses[0]);
            }
            else
            {
                zeroText->setChecked(false);
                zeroText->setText("none");
            }
        }
        if(resGetDiscoveryMode.DiscoveryMode == tt__DiscoveryMode__Discoverable)
        {
            onvifCombox->setCurrentIndex(1);
        }
        else if(resGetDiscoveryMode.DiscoveryMode == tt__DiscoveryMode__NonDiscoverable)
        {
            onvifCombox->setCurrentIndex(0);
        }
        deviceMg.destroy();
    }

}
