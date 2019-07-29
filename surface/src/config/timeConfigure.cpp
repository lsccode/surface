#include "timeConfigure.h"
TimeConfigure::TimeConfigure(QWidget *parent):QWidget(parent)
{
    groupTimeZone = new QGroupBox("timeZone");
   // groupTimeZone->setMa
    timeZone = new QComboBox;
    autoAjust = new QCheckBox("auto adjust!");
    applyZone = new QPushButton("apply");
    applyZone->setMaximumWidth(64);

    timeSet = new QGroupBox("timeSetting");
    timeType = new QComboBox;
    timeType->addItem("Local Computer");
    timeType->addItem("Ntp Server");
    timeType->addItem("Set Manually");
    timeShow = new QLineEdit;
    timeShow->setReadOnly(true);
    //localTime = new QDateTime;
    ntpServer = new QLineEdit;
    dateTimeSet = new QDateTimeEdit;
    dateTimeSet->setDateTime(QDateTime::currentDateTime());
    applyTimeSet = new QPushButton("apply");
    applyTimeSet->setMaximumWidth(64);
    localtimeLabel = new QLabel("Local Computer Time:");
    ntpTimeLabel   = new QLabel("Ntp Server:");
    userSetLabel   = new QLabel("User Set:");

    QVBoxLayout *layoutTimeZone = new QVBoxLayout;
    layoutTimeZone->addWidget(timeZone);
    layoutTimeZone->addWidget(autoAjust);
    layoutTimeZone->addWidget(applyZone);
   // layoutTimeZone->setSpacing(20);
    layoutTimeZone->setContentsMargins(10,20,10,10);
    groupTimeZone->setLayout(layoutTimeZone);

    QVBoxLayout *layoutTimeSetting = new QVBoxLayout;
    layoutTimeSetting->addWidget(timeType);

    QHBoxLayout *layoutTimeshow = new QHBoxLayout;
    layoutTimeshow->addWidget(localtimeLabel);
    layoutTimeshow->addWidget(timeShow);
    layoutTimeSetting->addLayout(layoutTimeshow);
    QHBoxLayout *layoutTimeNtp = new QHBoxLayout;
    layoutTimeNtp->addWidget(ntpTimeLabel);
    layoutTimeNtp->addWidget(ntpServer);
    layoutTimeSetting->addLayout(layoutTimeNtp);
    QHBoxLayout *layoutTimeSet = new QHBoxLayout;
    layoutTimeSet->addWidget(userSetLabel);
    layoutTimeSet->addWidget(dateTimeSet);
    layoutTimeSetting->addLayout(layoutTimeSet);
    layoutTimeSetting->addWidget(applyTimeSet);
    layoutTimeSetting->setContentsMargins(10,20,10,10);

    timeSet->setLayout(layoutTimeSetting);
    connect(timeType,SIGNAL(activated(const QString &)),this,SLOT(setTimeindex(const QString &)));
    timeType->activated("Local Computer");
    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addWidget(groupTimeZone);
    mainLayout->addWidget(timeSet);
    mainLayout->addStretch();

    setMaximumWidth(384);
    m_timerId = startTimer(1000);
    setLayout(mainLayout);

    connect(applyTimeSet,SIGNAL(clicked()),SLOT(doSetTimgSt()));

}
void TimeConfigure::setTimeindex(const QString &string)
{
    if(string == "Local Computer")
    {
        timeShow->setEnabled(true);
        ntpServer->setDisabled(true);
        dateTimeSet->setDisabled(true);
    }
    else if(string == "Ntp Server")
    {
        timeShow->setDisabled(true);
        ntpServer->setEnabled(true);
        dateTimeSet->setDisabled(true);
    }
    else if(string == "Set Manually")
    {
        timeShow->setDisabled(true);
        ntpServer->setDisabled(true);
        dateTimeSet->setEnabled(true);
    }
}
void TimeConfigure::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == m_timerId)
    {
        QDateTime curTime = QDateTime::currentDateTime();
        QString strTime = curTime.toString(Qt::SystemLocaleLongDate);
        timeShow->setText(strTime);
       // strTime.sprintf("%d-%d-%d %d:%d:%d",curTime.toString())
    }
}
void TimeConfigure::doUpdateWgt(UrlInfo info)
{
    this->info = info;
    if(info.type == "onvif")
    {
        DeviceBindingProxy deviceMg;
        std::string str = info.url.toStdString();
        int ret = SOAP_ERR;
        deviceMg.soap_endpoint = str.c_str();//"http://192.168.9.43/onvif/device_service";
        {
            _tds__GetSystemDateAndTime reqGetSystemDateAndTime;
            _tds__GetSystemDateAndTimeResponse resGetSystemDateAndTime;
            ret = deviceMg.GetSystemDateAndTime(&reqGetSystemDateAndTime,&resGetSystemDateAndTime);
            if(ret != SOAP_OK)
            {
                return;
            }
            if(resGetSystemDateAndTime.SystemDateAndTime != NULL)
            {
                if(resGetSystemDateAndTime.SystemDateAndTime->TimeZone != NULL)
                {
                    timeZone->addItem(resGetSystemDateAndTime.SystemDateAndTime->TimeZone->TZ);
                }
            }
        }
        deviceMg.destroy();
    }
}
void TimeConfigure::doSetTimgSt()
{
   if(info.type == "onvif")
   {
       int ret = SOAP_ERR;
       DeviceBindingProxy deviceMg;
       QString  typeTime = timeType->currentText();
       std::string strUrl = info.url.toStdString();
       std::string strUsr = info.user.toStdString();
       std::string strPass = info.passWord.toStdString();
       _tds__SetSystemDateAndTime reqSetSystemDateAndTime;
       _tds__SetSystemDateAndTimeResponse resSetSystemDateAndTime;
       _tds__GetSystemDateAndTime reqGetSystemDateAndTime;
       _tds__GetSystemDateAndTimeResponse resGetSystemDateAndTime;
       _tds__SetNTP reqSetNTP;
       _tds__SetNTPResponse resSetNTP;
       static tt__NetworkHost sNTPManual;
       tt__DateTime UTCDateTime;
       tt__Time Time;
       tt__Date Date;
       UTCDateTime.Date = &Date;
       UTCDateTime.Time = &Time;
       TimeDateUser syncTime;
       deviceMg.soap_endpoint = strUrl.c_str();//"http://192.168.9.43/onvif/device_service";
       if(typeTime == "Local Computer")
       {
           reqSetSystemDateAndTime.DateTimeType = tt__SetDateTimeType__Manual;
           reqSetSystemDateAndTime.UTCDateTime = &UTCDateTime;
           QDateTime curTime = QDateTime::currentDateTime();
           Time.Hour = curTime.time().hour();
           Time.Minute = curTime.time().minute();
           Time.Second = curTime.time().second();
           Date.Day = curTime.date().day();
           Date.Month = curTime.date().month();
           Date.Year = curTime.date().year();

       }
       else if(typeTime == "Set Manually")
       {
           reqSetSystemDateAndTime.DateTimeType = tt__SetDateTimeType__Manual;
           reqSetSystemDateAndTime.UTCDateTime = &UTCDateTime;
           Time.Hour   = dateTimeSet->time().hour();
           Time.Minute = dateTimeSet->time().minute();
           Time.Second = dateTimeSet->time().second();
           Date.Day    = dateTimeSet->date().day();
           Date.Month  = dateTimeSet->date().month();
           Date.Year   = dateTimeSet->date().year();
       }
       else if(typeTime == "Ntp Server" && ntpServer->text() != "")
       {
           reqSetSystemDateAndTime.DateTimeType = tt__SetDateTimeType__NTP;

           reqSetNTP.FromDHCP = false;
           reqSetNTP.__sizeNTPManual = 1;
           tt__NetworkHost *NTPManual = &sNTPManual;
           reqSetNTP.NTPManual = &NTPManual;
           NTPManual->Type = tt__NetworkHostType__IPv4;
           NTPManual->IPv4Address = soap_strdup((soap *)&deviceMg,ntpServer->text().toStdString().c_str());
       }

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
       if(typeTime == "Ntp Server" && ntpServer->text() != "")
       {
           if(info.user != "none" && info.passWord != "none")
           {
               soap_wsse_add_UsernameTokenDigestCreated((soap *)&deviceMg, "User",
                                                        strUsr.c_str(),strPass.c_str(),syncTime.created());
           }
           ret = deviceMg.SetNTP(&reqSetNTP,&resSetNTP);
           if(ret != SOAP_OK)
           {
               return;
           }
       }
       if(typeTime == "Set Manually" || typeTime == "Local Computer")
       {
           if(info.user != "none" && info.passWord != "none")
           {
               soap_wsse_add_UsernameTokenDigestCreated((soap *)&deviceMg, "User",
                                                        strUsr.c_str(),strPass.c_str(),syncTime.created());
           }
           ret = deviceMg.SetSystemDateAndTime(&reqSetSystemDateAndTime,&resSetSystemDateAndTime);
           if(ret != SOAP_OK)
           {
               return;
           }
       }

       deviceMg.destroy();
   }

}
