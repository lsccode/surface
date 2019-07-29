#include "sysLog.h"

SystemLog::SystemLog(QWidget *parent):QWidget(parent)
{
    selectLogLabel = new QLabel("Select log type");
    logCombox = new QComboBox;
    logCombox->addItem("system");
    logCombox->addItem("acess");
    getBtn = new QPushButton("get");
    logInfo = new QLabel("System log");
    saveBtn = new QPushButton("Save...");
    textLog = new QTextEdit;
    QHBoxLayout *layoutTop = new QHBoxLayout;
    layoutTop->addWidget(selectLogLabel);
    layoutTop->addWidget(logCombox);
    layoutTop->addWidget(getBtn);
    layoutTop->addStretch();

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addWidget(logInfo);
    layoutInter->addStretch();
    layoutInter->addWidget(saveBtn);

    QVBoxLayout *layoutmain = new QVBoxLayout;
    layoutmain->addLayout(layoutTop);
    layoutmain->addLayout(layoutInter);
    layoutmain->addWidget(textLog);

    setLayout(layoutmain);
}
void SystemLog::doUpdateWgt(UrlInfo info)
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
        _tds__GetSystemLog reqGetSystemLog;
        _tds__GetSystemLogResponse resGetSystemLog;
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
        reqGetSystemLog.LogType = tt__SystemLogType__System;
        if(info.user != "none" && info.passWord != "none")
        {
            soap_wsse_add_UsernameTokenDigestCreated((soap *)&deviceMg, "User",
                                                     strUsr.c_str(),strPass.c_str(),syncTime.created());
        }
        ret = deviceMg.GetSystemLog(&reqGetSystemLog,&resGetSystemLog);
        if(ret != SOAP_OK)
        {
            return;
        }
        if(resGetSystemLog.SystemLog && resGetSystemLog.SystemLog->String)
        {
            textLog->clear();
            textLog->setText(resGetSystemLog.SystemLog->String);
        }

        deviceMg.destroy();
    }
}
