#ifndef EVENTS_H
#define EVENTS_H
#include "commonHeader.h"
#include "commonDef.h"
class NotificationConsumerBinding:public NotificationConsumerBindingService/*,public QObject*/
{
//    Q_OBJECT
public:
    NotificationConsumerBinding();
    NotificationConsumerBinding(const struct soap&);
    NotificationConsumerBinding(soap_mode iomode);
    NotificationConsumerBinding(soap_mode imode, soap_mode omode);
    void setEventTable(QTableWidget *eventTable);
    virtual int Notify(_wsnt__Notify *wsnt__Notify);
private:
    QTableWidget *eventTable;
};
class EventNofyMessThread:public QThread
{
    Q_OBJECT
public:
    explicit EventNofyMessThread(QObject *parent = 0);
    void stop();
    void setEventTable(QTableWidget *eventTable);
protected:
    void run();
private:
    volatile bool stopped;
    QTableWidget *eventTable;

signals:
public slots:
};

class Events:public QWidget
{
    Q_OBJECT
public:
    Events(QWidget *parent = 0);
    QTableWidget *eventTable;
    EventNofyMessThread notifyMes;
public slots:
    void doUpdateWgt(UrlInfo info);
private:
    UrlInfo info;
};

#endif // EVENTS_H
