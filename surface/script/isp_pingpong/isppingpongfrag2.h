#ifndef ISPPINGPONGFRAG2_H
#define ISPPINGPONGFRAG2_H

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

class IspPingPongFrag2 : public QWidget,public IspCommonStep
{
    Q_OBJECT
public:
    explicit IspPingPongFrag2(QWidget *parent = 0);
public:
    QListWidget *ptListWidget;
    QStackedLayout *ptStackedLayout;

//    IspPPfr_config *pt_fr_config;
//    IspPPframe_stitch *pt_frame_stitch;
//    IspPPinput_formatter *pt_input_formatter;
    IspPPmesh_shading *pt_mesh_shading;
    IspPPmetering *pt_metering;
//    IspPPmetering_af *pt_metering_af;
//    IspPPmetering_awb *pt_metering_awb;
//    IspPPmetering_ihist *pt_metering_ihist;
    IspPPradial_shading *pt_radial_shading;
    IspPPraw_frontend *pt_raw_frontend;
    IspPPsensor_offset *pt_sensor_offset;
    IspPPsinter *pt_sinter;
    IspPPtemper *pt_temper;
    IspPPtop *pt_top;
    IspPPwhite_balance_aexp *pt_white_balance_aexp;

    QPushButton *ptPBtnOK;
    QPushButton *ptPBtnExec;

public:
    virtual void step1();
    virtual void step2();
    virtual void step3();
    virtual void step4();
    virtual void step5();
signals:
    void clickedPingPongF2Sig(bool checked);
public slots:
    void clickedPingPongF2OkSlot(bool checked = false);
    void clickedPingPongF2ExecSlot(bool checked = false);
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);
    void clickedF2OKDisableSlot();
    void clickedF2OKEnableSlot();
};

#endif // ISPPINGPONGFRAG2_H
