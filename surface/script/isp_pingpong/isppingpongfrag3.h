#ifndef ISPPINGPONGFRAG3_H
#define ISPPINGPONGFRAG3_H

#include <QWidget>
#include <QListWidget>
#include <QStackedLayout>
#include "ispppblack_level.h"
#include "ispppca_correction.h"
#include "ispppccm.h"
#include "ispppcnr.h"
#include "ispppdecompander.h"
#include "ispppdemosaic_rgbir.h"
#include "ispppds_cs_conv.h"
#include "ispppds_dma_writer.h"
#include "ispppds_gamma_rgb.h"
#include "ispppds_sharpen.h"
#include "ispppfr_cs_conv.h"
#include "ispppfr_dma_writer.h"
#include "ispppfr_gamma_rgb.h"
#include "ispppfr_sharpen.h"
#include "ispppframe_stitch.h"
#include "ispppinput_formatter.h"
#include "ispppmesh_shading.h"
#include "ispppmetering_aexp.h"
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

class IspPingPongFrag3 : public QWidget
{
    Q_OBJECT
public:
    explicit IspPingPongFrag3(QWidget *parent = 0);
public:
    QListWidget *ptListWidget;
    QStackedLayout *ptStackedLayout;

    IspPPmetering_awb *pt_metering_awb;
    IspPPmetering_ihist *pt_metering_ihist;
    IspPPradial_shading *pt_radial_shading;
    IspPPraw_frontend *pt_raw_frontend;
    IspPPsensor_offset *pt_sensor_offset;
    IspPPsinter *pt_sinter;
    IspPPtemper *pt_temper;
    IspPPtop *pt_top;
    IspPPwhite_balance_aexp *pt_white_balance_aexp;
signals:

public slots:
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);
};

#endif // ISPPINGPONGFRAG3_H
