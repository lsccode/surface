#ifndef ISPPINGPONGFRAG1_H
#define ISPPINGPONGFRAG1_H

#include <QWidget>
#include <QListWidget>
#include <QStackedLayout>
#include "ispppmisc.h"
#include "ispppca_correction.h"
#include "ispppccm.h"
#include "ispppcnr.h"
#include "ispppdecompander.h"
#include "ispppdemosaic_rgbir.h"
#include "ispppds_config.h"
#include "ispppfr_config.h"
#include "ispppframe_stitch.h"
#include "ispppinput_formatter.h"
#include "ispppmesh_shading.h"
#include "ispppmetering.h"
#include "ispppmetering_af.h"
#include "ispppmetering_awb.h"
#include "ispppmetering_ihist.h"
#include "ispppradial_shading.h"
#include "ispppraw_frontend.h"
#include "ispppsensor_offset.h"
#include "ispppsinter.h"
#include "isppptemper.h"
#include "isppptop.h"
#include "ispppwhite_balance_aexp.h"
#include "script/ispcommonstep.h"

class IspPingPongFrag1 : public QWidget,public IspCommonStep
{
    Q_OBJECT
public:
    explicit IspPingPongFrag1(QWidget *parent = 0);
public:
    QListWidget *ptListWidget;
    QStackedLayout *ptStackedLayout;

    IspPPmisc *pt_misc;
    IspPPCa_correction *pt_Ca_correction;
    IspPPCcm *pt_Ccm;
    IspPPCnr *pt_Cnr;
    IspPPdecompander *pt_decompander;
    IspPPdemosaic_rgbir *pt_demosaic_rgbir;
    IspPPds_config *pt_ds_config;
    IspPPfr_config *pt_fr_config;
    IspPPframe_stitch *pt_frame_stitch;
    IspPPinput_formatter *pt_input_formatter;

    QPushButton *ptPBtnOK;
    QPushButton *ptPBtnExec;

public:
    virtual void step1();
    virtual void step2();
    virtual void step3();
    virtual void step4();
signals:
    void clickedPingPongF1Sig(bool checked);
public slots:
    void clickedPingPongF1OkSlot(bool checked = false);
    void clickedPingPongF1ExecSlot(bool checked = false);
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);
    void clickedF1OKDisableSlot();
    void clickedF1OKEnableSlot();
};

#endif // ISPPINGPONGFRAG1_H
