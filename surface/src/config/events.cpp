#include "events.h"

Events::Events(QWidget *parent):QWidget(parent)
{
    eventTable = new QTableWidget(0, 5);;
    eventTable->setHorizontalHeaderLabels(QStringList() << tr("Time") <<tr("Operation")<<tr("Source")<<tr("Data")<< tr("Topic"));
    QHBoxLayout *layoutmain = new QHBoxLayout;
    layoutmain->addWidget(eventTable);
    setLayout(layoutmain);
}
void Events::doUpdateWgt(UrlInfo info)
{
    this->info = info;
    if(info.type == "onvif")
    {
        int ret = SOAP_ERR;
        TimeDateUser syncTime;
        DeviceBindingProxy deviceMg;
        NotificationProducerBindingProxy ntProducer;
        std::string strUrl = info.url.toStdString();
        std::string strUsr = info.user.toStdString();
        std::string strPass = info.passWord.toStdString();
        _tds__GetSystemDateAndTime reqGetSystemDateAndTime;
        _tds__GetSystemDateAndTimeResponse resGetSystemDateAndTime;
        _wsnt__Subscribe reqSubscribe;
        _wsnt__SubscribeResponse resSubscribe;
        deviceMg.soap_endpoint = strUrl.c_str();
        ntProducer.soap_endpoint = "http://192.168.9.63/onvif/services";
        if(notifyMes.isRunning())
        {
            goto END;
        }
        ret = deviceMg.GetSystemDateAndTime(&reqGetSystemDateAndTime, &resGetSystemDateAndTime);
        if(ret != SOAP_OK)
        {
            goto END;
        }
        syncTime.setTimeDate(resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Date->Year,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Date->Month,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Date->Day,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Time->Hour,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Time->Minute,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Time->Second,
                             0);
        struct wsa__EndpointReferenceType wsa__ReplyTo;
        wsa__ReplyTo.Address = "http://www.w3.org/2005/08/addressing/anonymous";
        ntProducer.soap_header(NULL, const_cast<char *>(soap_wsa_rand_uuid((soap *)&ntProducer)),
                               NULL,
                               NULL,
                               &wsa__ReplyTo,
                               NULL,
                               "http://192.168.9.63/onvif/services",
                               "http://docs.oasis-open.org/wsn/bw-2/NotificationProducer/SubscribeRequest",
                               NULL,
                               NULL, NULL,
                               NULL,
                               NULL,
                               NULL,
                               NULL, NULL, NULL);
        if(info.user != "none" && info.passWord != "none")
        {
            soap_wsse_add_UsernameTokenDigestCreated((soap *)&ntProducer, "User",
                                                     strUsr.c_str(),strPass.c_str(),syncTime.created());
        }
        reqSubscribe.ConsumerReference.Address = "http://192.168.9.61:8012";
        reqSubscribe.InitialTerminationTime = "PT60S";
        ret = ntProducer.Subscribe(&reqSubscribe,&resSubscribe);
        if(ret != SOAP_OK)
        {
            goto END;
        }

        while(eventTable->rowCount() > 0)
        {
            eventTable->removeRow(eventTable->rowCount()-1);
        }
        notifyMes.setEventTable(eventTable);
        notifyMes.start();
        return;
END:
        deviceMg.destroy();
        ntProducer.destroy();

        return;


    }
}
EventNofyMessThread::EventNofyMessThread(QObject *parent):QThread(parent)
{
   stopped = false;
   eventTable = NULL;
}
void EventNofyMessThread::stop()
{
    stopped = false;
}
void EventNofyMessThread::run()
{
    QString mes;
    NotificationConsumerBinding server;
    server.recv_timeout = 5;
    server.accept_timeout = 60;
    server.send_timeout = 5;
    server.setEventTable(eventTable);
    while(!stopped)
    {
        if (server.run(8012))
        {
            mes = *soap_faultstring(&server);
            if(mes == "Timeout")
            {
                stopped = true;
                fprintf(stderr,"%s\n","Timeout");
            }
        }
    }
    server.destroy();
    stopped = false;
}
void EventNofyMessThread::setEventTable(QTableWidget *eventTable)
{
    this->eventTable = eventTable;
}
NotificationConsumerBinding::NotificationConsumerBinding():
    NotificationConsumerBindingService()
{
    eventTable = NULL;
}
NotificationConsumerBinding::NotificationConsumerBinding(const struct soap &soap):
    NotificationConsumerBindingService(soap)
{
    eventTable = NULL;
}
NotificationConsumerBinding::NotificationConsumerBinding(soap_mode iomode):
    NotificationConsumerBindingService(iomode)
{
    eventTable = NULL;
}
NotificationConsumerBinding::NotificationConsumerBinding(soap_mode imode, soap_mode omode):
    NotificationConsumerBindingService(imode,omode)
{
    eventTable = NULL;
}
int NotificationConsumerBinding::Notify(_wsnt__Notify *wsnt__Notify)
{
    if(wsnt__Notify == NULL || wsnt__Notify->__sizeNotificationMessage == 0)
        return 0;
    wsnt__NotificationMessageHolderType **NotificationMessage = wsnt__Notify->NotificationMessage;

    for(int i = 0;i < wsnt__Notify->__sizeNotificationMessage;++i)
    {
        int row = eventTable->rowCount();
        //_tt__Message *message = (_tt__Message *)NotificationMessage[i]->Message.__any;
//        std::string  strMessage = NotificationMessage[i]->Message.__any;
        _tt__Message *message = NotificationMessage[i]->Message.Message;
        eventTable->insertRow(row);
        QTableWidgetItem *item0 = new QTableWidgetItem;
        item0->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        eventTable->setItem(row, 0, item0);

        QTableWidgetItem *item1 = new QTableWidgetItem;
        item1->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        eventTable->setItem(row, 1, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem;
        item2->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        eventTable->setItem(row, 2, item2);

        QTableWidgetItem *item3 = new QTableWidgetItem;
        item2->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        eventTable->setItem(row, 3, item3);

        QTableWidgetItem *item4 = new QTableWidgetItem;
        item2->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        eventTable->setItem(row, 4, item4);
        if(message != NULL)
        {
            QString timeQstr;
            struct tm *p = localtime(&message->UtcTime);
            timeQstr.sprintf("%02d-%02d-%02d %02d:%02d:%02d",
                             1900+p->tm_year,1+p->tm_mon,p->tm_mday,
                             p->tm_hour,p->tm_min,p->tm_sec);
            eventTable->item(row,0)->setText(timeQstr);
            if(message->PropertyOperation != NULL)
            {
                if(*message->PropertyOperation == tt__PropertyOperation__Initialized)
                {
                    eventTable->item(row,1)->setText("Initialized");
                }
                else if(*message->PropertyOperation == tt__PropertyOperation__Deleted)
                {
                    eventTable->item(row,1)->setText("Deleted");
                }
                else if(*message->PropertyOperation == tt__PropertyOperation__Changed)
                {
                    eventTable->item(row,1)->setText("Changed");
                }
            }
            if(message->Source && message->Source->__sizeSimpleItem)
            {
                QString mes;
                mes.sprintf("%s:%s",message->Source->SimpleItem->Name,message->Source->SimpleItem->Value);
                eventTable->item(row,2)->setText(mes);
            }
            if(message->Data && message->Data->__sizeSimpleItem)
            {
                QString mes;
                mes.sprintf("%s:%s",message->Data->SimpleItem->Name,message->Data->SimpleItem->Value);
                eventTable->item(row,3)->setText(mes);
            }
        }
        if(NotificationMessage[i]->Topic && NotificationMessage[i]->Topic->__any)
            eventTable->item(row,4)->setText(NotificationMessage[i]->Topic->__any);

    }
    return send_Notify_empty_response(202);
}
void NotificationConsumerBinding::setEventTable(QTableWidget *eventTable)
{
    this->eventTable = eventTable;
}
