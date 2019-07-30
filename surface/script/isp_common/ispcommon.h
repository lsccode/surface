#ifndef ISPCOMMON_H
#define ISPCOMMON_H

#include <QWidget>
#include <QListWidget>
#include <QStackedLayout>
#include "ispcmglobal.h"
#include "ispcminputport.h"

class IspCommon : public QWidget
{
    Q_OBJECT
public:
    explicit IspCommon(QWidget *parent = 0);

public:

    QListWidget *ptListWidget;
    QStackedLayout *ptStackedLayout;

    IspCmGlobal *ptWidgtIspCmGlobal;
    IspCminputport *ptWidgtIspCmInputPort;

signals:

public slots:
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);
};

#endif // ISPCOMMON_H
