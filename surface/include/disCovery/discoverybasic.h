#ifndef DISCOVERYBASIC_H
#define DISCOVERYBASIC_H
#include "commonHeader.h"
class DisCoveryBasic:public QObject
{
    Q_OBJECT
public:
    DisCoveryBasic(QObject *parent = 0);
    virtual void start() = 0;
signals:
    void FindNewItemSg(QString type,QString url);
public slots:

};
class OnvifDisImp:public DisCoveryBasic
{
    Q_OBJECT
public:
    OnvifDisImp(QObject *parent = 0);
    void start();
};
#endif // DISCOVERYBASIC_H
