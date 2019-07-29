#include "maintenance.h"
Maintence::Maintence(QWidget *parent):QWidget(parent)
{
    conf = new QLabel("Configuration:");
    softFacRest = new QLabel("Soft Factory Reset:");
    hardFacRest = new QLabel("Hard Factory Reset:");
    reboot = new QLabel("System Reboot");
    firmware = new QLabel("Firmware");
    backupBtn = new QPushButton("Backup");
    restoreBtn = new QPushButton("Restore");
    softRstBtn = new QPushButton("Soft Reset");
    hardRstBtn = new QPushButton("Hard Reset");
    rebootBtn = new QPushButton("Reboot");
    upGradeBtn = new QPushButton("Upgrade");
    Softversion = new QLineEdit;
    QGridLayout *mainLayOut = new QGridLayout;
    mainLayOut->addWidget(conf,0,0);
    mainLayOut->addWidget(backupBtn,0,1);
    mainLayOut->addWidget(restoreBtn,0,1);

    mainLayOut->addWidget(softFacRest,1,0);
    mainLayOut->addWidget(softRstBtn,1,1);

    mainLayOut->addWidget(hardFacRest,2,0);
    mainLayOut->addWidget(hardRstBtn,2,1);

    mainLayOut->addWidget(reboot,3,0);
    mainLayOut->addWidget(rebootBtn,3,1);

    mainLayOut->addWidget(firmware,4,0);
    mainLayOut->addWidget(upGradeBtn,4,1);
    mainLayOut->addWidget(Softversion,4,2);

    QHBoxLayout *layout1 = new QHBoxLayout;

    layout1->addLayout(mainLayOut);
    layout1->addStretch();

    QVBoxLayout *layout2 = new QVBoxLayout;
    layout2->addLayout(layout1);
    layout2->addStretch();
    setLayout(layout2);

    connect(softRstBtn,SIGNAL(clicked()),SLOT(doSoftRestSt()));
    connect(hardRstBtn,SIGNAL(clicked()),SLOT(doHardRestSt()));
    connect(rebootBtn,SIGNAL(clicked()),SLOT(doRebootStSt()));
}
void Maintence::doUpdateWgt(UrlInfo info)
{
    this->info = info;
    TimeDateUser syncTime;
    std::string strUrl = info.url.toStdString();
    std::string strUsr = info.user.toStdString();
    std::string strPass = info.passWord.toStdString();
    if(info.type == "onvif")
    {
        int ret = SOAP_ERR;
        DeviceBindingProxy deviceMg;
        _tds__GetSystemDateAndTime reqGetSystemDateAndTime;
        _tds__GetSystemDateAndTimeResponse resGetSystemDateAndTime;
        _tds__GetDeviceInformation reqGetDeviceInformation;
        _tds__GetDeviceInformationResponse resGetDeviceInformation;
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

        ret = deviceMg.GetDeviceInformation(&reqGetDeviceInformation,&resGetDeviceInformation);
        if(ret != SOAP_OK)
        {
            return;
        }
        if(resGetDeviceInformation.FirmwareVersion != NULL)
        {
            Softversion->setText(resGetDeviceInformation.FirmwareVersion);
        }
        deviceMg.destroy();
    }
}
void Maintence::doSoftRestSt()
{
    if(info.type == "onvif")
    {
        TimeDateUser syncTime;
        int ret = SOAP_ERR;
        DeviceBindingProxy deviceMg;
        std::string strUrl = info.url.toStdString();
        std::string strUsr = info.user.toStdString();
        std::string strPass = info.passWord.toStdString();
        deviceMg.soap_endpoint = strUrl.c_str();
        _tds__GetSystemDateAndTime reqGetSystemDateAndTime;
        _tds__GetSystemDateAndTimeResponse resGetSystemDateAndTime;
        _tds__SetSystemFactoryDefault reqSetSystemFactoryDefault;
        _tds__SetSystemFactoryDefaultResponse resSetSystemFactoryDefault;
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

        reqSetSystemFactoryDefault.FactoryDefault = tt__FactoryDefaultType__Soft;
        if(info.user != "none" && info.passWord != "none")
        {
            soap_wsse_add_UsernameTokenDigestCreated((soap *)&deviceMg, "User",
                                                     strUsr.c_str(),strPass.c_str(),syncTime.created());
        }
        ret = deviceMg.SetSystemFactoryDefault(&reqSetSystemFactoryDefault,&resSetSystemFactoryDefault);
        if(ret != SOAP_OK)
        {
            return;
        }
        deviceMg.destroy();
    }
}
void Maintence::doHardRestSt()
{
    if(info.type == "onvif")
    {
        TimeDateUser syncTime;
        int ret = SOAP_ERR;
        DeviceBindingProxy deviceMg;
        std::string strUrl = info.url.toStdString();
        std::string strUsr = info.user.toStdString();
        std::string strPass = info.passWord.toStdString();
        deviceMg.soap_endpoint = strUrl.c_str();
        _tds__GetSystemDateAndTime reqGetSystemDateAndTime;
        _tds__GetSystemDateAndTimeResponse resGetSystemDateAndTime;
        _tds__SetSystemFactoryDefault reqSetSystemFactoryDefault;
        _tds__SetSystemFactoryDefaultResponse resSetSystemFactoryDefault;
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

        reqSetSystemFactoryDefault.FactoryDefault = tt__FactoryDefaultType__Hard;
        if(info.user != "none" && info.passWord != "none")
        {
            soap_wsse_add_UsernameTokenDigestCreated((soap *)&deviceMg, "User",
                                                     strUsr.c_str(),strPass.c_str(),syncTime.created());
        }
        ret = deviceMg.SetSystemFactoryDefault(&reqSetSystemFactoryDefault,&resSetSystemFactoryDefault);
        if(ret != SOAP_OK)
        {
            return;
        }
        deviceMg.destroy();
    }
}
void Maintence::doRebootStSt()
{
    if(info.type == "onvif")
    {
        TimeDateUser syncTime;
        int ret = SOAP_ERR;
        DeviceBindingProxy deviceMg;
        std::string strUrl = info.url.toStdString();
        std::string strUsr = info.user.toStdString();
        std::string strPass = info.passWord.toStdString();
        deviceMg.soap_endpoint = strUrl.c_str();
        _tds__GetSystemDateAndTime reqGetSystemDateAndTime;
        _tds__GetSystemDateAndTimeResponse resGetSystemDateAndTime;
        _tds__SystemReboot reqSystemReboot;
        _tds__SystemRebootResponse resSystemReboot;
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
        ret = deviceMg.SystemReboot(&reqSystemReboot,&resSystemReboot);
        if(ret != SOAP_OK)
        {
            return;
        }
        deviceMg.destroy();
    }
}
