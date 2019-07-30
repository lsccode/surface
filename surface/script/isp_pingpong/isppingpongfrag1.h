#ifndef ISPPINGPONGFRAG1_H
#define ISPPINGPONGFRAG1_H

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

class IspPingPongFrag1 : public QWidget
{
    Q_OBJECT
public:
    explicit IspPingPongFrag1(QWidget *parent = 0);
public:
    QListWidget *ptListWidget;
    QStackedLayout *ptStackedLayout;

    IspPPblack_level *pt_black_level;
    IspPPCa_correction *pt_Ca_correction;
    IspPPCcm *pt_Ccm;
    IspPPCnr *pt_Cnr;
    IspPPdecompander *pt_decompander;
    IspPPdemosaic_rgbir *pt_demosaic_rgbir;
    IspPPds_cs_conv *pt_ds_cs_conv;
    IspPPds_dma_writer *pt_ds_dma_writer;
    IspPPds_gamma_rgb *pt_ds_gamma_rgb;
signals:

public slots:
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);
};

#endif // ISPPINGPONGFRAG1_H
