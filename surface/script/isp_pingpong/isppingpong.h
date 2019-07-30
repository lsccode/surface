#ifndef ISPPINGPONG_H
#define ISPPINGPONG_H

#include <QWidget>
#include <QListWidget>
#include <QStackedLayout>
#include "ispppblack_level.h"
#include "ispppca_correction.h"
#include "ispppccm.h"
#include "ispppcnr.h"
#include "ispppdecompander0.h"
#include "ispppdecompander1.h"
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


class IspPingPong : public QWidget
{
    Q_OBJECT
public:
    explicit IspPingPong(QWidget *parent = 0);

public:
    QListWidget *ptListWidget;
    QStackedLayout *ptStackedLayout;

    IspPPblack_level *pt_black_level;
    IspPPCa_correction *pt_Ca_correction;
    IspPPCcm *pt_Ccm;
    IspPPCnr *pt_Cnr;
    IspPPdecompander0 *pt_decompander0;
    IspPPdecompander1 *pt_decompander1;
    IspPPdemosaic_rgbir *pt_demosaic_rgbir;
    IspPPds_cs_conv *pt_ds_cs_conv;
    IspPPds_dma_writer *pt_ds_dma_writer;
    IspPPds_gamma_rgb *pt_ds_gamma_rgb;
    IspPPds_sharpen *pt_ds_sharpen;
    IspPPfr_cs_conv *pt_fr_cs_conv;
    IspPPfr_dma_writer *pt_fr_dma_writer;
    IspPPfr_gamma_rgb *pt_fr_gamma_rgb;
    IspPPfr_sharpen *pt_fr_sharpen;
    IspPPframe_stitch *pt_frame_stitch;
    IspPPinput_formatter *pt_input_formatter;
    IspPPmesh_shading *pt_mesh_shading;
    IspPPmetering_aexp *pt_metering_aexp;
    IspPPmetering_af *pt_metering_af;
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

#endif // ISPPINGPONG_H
