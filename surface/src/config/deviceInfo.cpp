#include "deviceInfo.h"
#include <string>

DeviceInfo::DeviceInfo(QWidget *parent): QDialog(parent)
{
    nameLabel = new QLabel("name:");
    locationLabel = new QLabel("location:");
    manuFacturerLabel = new QLabel("manufacuturer:");
    modelLabel = new QLabel("model:");
    hardWareLabel = new QLabel("hardware:");
    firmwareLabel = new QLabel("firmware:");
    deviceIdLabel = new QLabel("deviceid:");
    ipaddressLabel = new QLabel("ip:");
    macLabel = new QLabel("mac:");
    onvifVersionLabel = new QLabel("onvif version:");
    urlLabel = new QLabel("url:");

    nameEdit = new QLineEdit("NULL");nameEdit->setReadOnly(true);
    locationEdit = new QLineEdit("NULL");locationEdit->setReadOnly(true);
    manuFacturerEdit = new QLineEdit("NULL");manuFacturerEdit->setReadOnly(true);
    modelEdit = new QLineEdit("NULL"); modelEdit->setReadOnly(true);
    hardWareEdit = new QLineEdit("NULL");hardWareEdit->setReadOnly(true);
    firmwareEdit = new QLineEdit("NULL"); firmwareEdit->setReadOnly(true);
    deviceIdEdit = new QLineEdit("NULL");deviceIdEdit->setReadOnly(true);
    ipaddressEdit = new QLineEdit("NULL");ipaddressEdit->setReadOnly(true);
    macEdit = new QLineEdit("NULL");macEdit->setReadOnly(true);
    onvifVersionEdit = new QLineEdit("NULL");onvifVersionEdit->setReadOnly(true);
    urlEdit = new QLineEdit("NULL"); urlEdit->setReadOnly(true);

    QGridLayout *layoutGrid = new QGridLayout;
    layoutGrid->addWidget(nameLabel,0,0);layoutGrid->addWidget(nameEdit,0,1);
    layoutGrid->addWidget(locationLabel,1,0);layoutGrid->addWidget(locationEdit,1,1);
    layoutGrid->addWidget(manuFacturerLabel,2,0);layoutGrid->addWidget(manuFacturerEdit,2,1);
    layoutGrid->addWidget(modelLabel,3,0);layoutGrid->addWidget(modelEdit,3,1);
    layoutGrid->addWidget(hardWareLabel,4,0);layoutGrid->addWidget(hardWareEdit,4,1);
    layoutGrid->addWidget(firmwareLabel,5,0);layoutGrid->addWidget(firmwareEdit,5,1);
    layoutGrid->addWidget(deviceIdLabel,6,0);layoutGrid->addWidget(deviceIdEdit,6,1);
    layoutGrid->addWidget(ipaddressLabel,7,0);layoutGrid->addWidget(ipaddressEdit,7,1);
    layoutGrid->addWidget(macLabel,8,0);layoutGrid->addWidget(macEdit,8,1);
    layoutGrid->addWidget(onvifVersionLabel,9,0);layoutGrid->addWidget(onvifVersionEdit,9,1);
    layoutGrid->addWidget(urlLabel,10,0);layoutGrid->addWidget(urlEdit,10,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

    setLayout(mainLayout);
}
void DeviceInfo::doUpdateWgt(UrlInfo info)
{
    this->info = info;
    if(info.type != "onvif")
        return;

    DeviceBindingProxy deviceMg;
    std::string strUrl = info.url.toStdString();
//    std::string strType = info.type.toStdString();
    std::string strUsr = info.user.toStdString();
    std::string strPass = info.passWord.toStdString();
    TimeDateUser syncTime;
    deviceMg.soap_endpoint = strUrl.c_str();//"http://192.168.9.43/onvif/device_service";
    {
        int ret;
        _tds__GetDeviceInformation reqGetDeviceInformation;
        _tds__GetDeviceInformationResponse resGetDeviceInformation;
        _tds__GetSystemDateAndTime reqGetSystemDateAndTime;
        _tds__GetSystemDateAndTimeResponse resGetSystemDateAndTime;
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
            soap_wsse_add_UsernameTokenDigestCreated((soap *)&deviceMg, "User",strUsr.c_str(),strPass.c_str(),syncTime.created());
        }
        ret = deviceMg.GetDeviceInformation(&reqGetDeviceInformation,&resGetDeviceInformation);
        if(ret != SOAP_OK)
        {
            return;
        }
        manuFacturerEdit->setText(resGetDeviceInformation.Manufacturer);
        firmwareEdit->setText(resGetDeviceInformation.FirmwareVersion);
        modelEdit->setText(resGetDeviceInformation.Model);
        hardWareEdit->setText(resGetDeviceInformation.HardwareId);
        deviceIdEdit->setText(resGetDeviceInformation.SerialNumber);
    }
    {
        _tds__GetCapabilities reqGetCapabilities;
        _tds__GetCapabilitiesResponse resGetCapabilities;
        if(info.user != "none" && info.passWord != "none")
        {
            soap_wsse_add_UsernameTokenDigestCreated((soap *)&deviceMg, "User",strUsr.c_str(),strPass.c_str(),syncTime.created());
        }
        int ret = deviceMg.GetCapabilities(&reqGetCapabilities,&resGetCapabilities);
        if(ret != SOAP_OK)
        {
            return;
        }
        if(resGetCapabilities.Capabilities != NULL &&
           resGetCapabilities.Capabilities->Device != NULL
           )
        {
            if(resGetCapabilities.Capabilities->Device->XAddr != NULL)
                urlEdit->setText(resGetCapabilities.Capabilities->Device->XAddr);
            if(resGetCapabilities.Capabilities->Device->System != NULL &&
               resGetCapabilities.Capabilities->Device->System->SupportedVersions != NULL &&
               *resGetCapabilities.Capabilities->Device->System->SupportedVersions != NULL   )
            {
                tt__OnvifVersion *SupportedVersions =
                        *resGetCapabilities.Capabilities->Device->System->SupportedVersions;
                QString OnvifVer;
                    OnvifVer.sprintf("%d.%02d",SupportedVersions->Major,SupportedVersions->Minor);
                onvifVersionEdit->setText(OnvifVer);
            }
        }


    }
    {
        _tds__GetScopes reqGetScopes;
        _tds__GetScopesResponse resGetScopes;
        tt__Scope *Scopes = NULL;
        if(info.user != "none" && info.passWord != "none")
        {
            soap_wsse_add_UsernameTokenDigestCreated((soap *)&deviceMg, "User",strUsr.c_str(),strPass.c_str(),syncTime.created());
        }
        int ret = deviceMg.GetScopes(&reqGetScopes,&resGetScopes);
        if(ret != SOAP_OK)
        {
            return;
        }
        if(resGetScopes.__sizeScopes != 0)
        {
           for(int i = 0;i < resGetScopes.__sizeScopes;++i)
           {
                Scopes = resGetScopes.Scopes[i];
                if(Scopes != NULL)
                {
                    QString temp = Scopes->ScopeItem;
                    int index = -1;
                    if((index = temp.lastIndexOf("name/"))!= -1)
                    {
                        nameEdit->setText(temp.right(temp.count() - index - 5));
                    }
                    else if((index = temp.lastIndexOf("location/")) != -1)
                    {
                        locationEdit->setText(temp.right(temp.count()-index - 9));
                    }
                }
           }
        }
    }
    {
        _tds__GetNetworkInterfaces reqGetNetworkInterfaces;
        _tds__GetNetworkInterfacesResponse resGetNetworkInterfaces;
        if(info.user != "none" && info.passWord != "none")
        {
            soap_wsse_add_UsernameTokenDigestCreated((soap *)&deviceMg, "User",strUsr.c_str(),strPass.c_str(),syncTime.created());
        }
        int ret = deviceMg.GetNetworkInterfaces(&reqGetNetworkInterfaces,&resGetNetworkInterfaces);
        if(ret != SOAP_OK)
        {
            return;
        }
        if(resGetNetworkInterfaces.__sizeNetworkInterfaces != 0)
        {
            if(resGetNetworkInterfaces.NetworkInterfaces != NULL &&
               *resGetNetworkInterfaces.NetworkInterfaces != NULL)
            {
                tt__NetworkInterface *NetworkInterfaces = resGetNetworkInterfaces.NetworkInterfaces[0];
                if(NetworkInterfaces != NULL)
                {
                    tt__NetworkInterfaceInfo *info = NetworkInterfaces->Info;
                    if(info != NULL && info->HwAddress != NULL)
                    {
                        macEdit->setText(info->HwAddress);
                    }
                     tt__IPv4NetworkInterface *IPv4 = NetworkInterfaces->IPv4;
                     if(IPv4 != NULL && IPv4->Enabled && IPv4->Config != NULL)
                     {
                        if(IPv4->Config->__sizeManual != 0 &&
                                IPv4->Config->Manual != NULL &&
                                *IPv4->Config->Manual != NULL)
                        {
                            class tt__PrefixedIPv4Address *Manual = IPv4->Config->Manual[0];
                             ipaddressEdit->setText(Manual->Address);
                        }
                        else if(IPv4->Config->DHCP &&
                                IPv4->Config->FromDHCP != NULL)
                        {
                            tt__PrefixedIPv4Address *FromDHCP = IPv4->Config->FromDHCP;
                            if(FromDHCP->Address)
                            {
                                ipaddressEdit->setText(FromDHCP->Address);
                            }

                        }
                        else if(IPv4->Config->LinkLocal)
                        {
                             ipaddressEdit->setText(IPv4->Config->LinkLocal->Address);
                        }
                     }
                }
            }
        }
    }
    deviceMg.destroy();
}
