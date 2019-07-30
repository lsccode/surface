#ifndef ISPPINGPONGFRAG2_H
#define ISPPINGPONGFRAG2_H

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

class IspPingPongFrag2 : public QWidget
{
    Q_OBJECT
public:
    explicit IspPingPongFrag2(QWidget *parent = 0);
public:
    QListWidget *ptListWidget;
    QStackedLayout *ptStackedLayout;

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
signals:

public slots:
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);
};

#endif // ISPPINGPONGFRAG2_H
