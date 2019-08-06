#ifndef ISPCOMMON_H
#define ISPCOMMON_H

#include <QWidget>
#include <QListWidget>
#include <QStackedLayout>
#include <QPushButton>

#include "ispcmglobal.h"
#include "ispcminputport.h"
#include "script/ispcommonstep.h"

class IspCommon : public QWidget,public IspCommonStep
{
    Q_OBJECT
public:
    explicit IspCommon(QWidget *parent = 0);

public:

    QListWidget *ptListWidget;
    QStackedLayout *ptStackedLayout;

    IspCmGlobal *ptWidgtIspCmGlobal;
    IspCminputport *ptWidgtIspCmInputPort;

    QPushButton *ptPBtn;
    QPushButton *ptPBExec;

public:
    virtual void step1();
    virtual void step2();
    virtual void step3();

signals:
    void clickedCommonSig(bool checked);
public slots:
    void clickedCommonSlot(bool checked = false);
    void clickedCommonExecSlot(bool checked = false);
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);
};

#endif // ISPCOMMON_H
