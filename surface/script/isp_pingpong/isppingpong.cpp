#include "isppingpong.h"

IspPingPong::IspPingPong(QWidget *parent) :
    QWidget(parent)
{
    ptListWidget = new QListWidget;
    ptStackedLayout =  new QStackedLayout;

    pt_black_level = new IspPPblack_level;
    pt_Ca_correction = new IspPPCa_correction;
    pt_Ccm = new IspPPCcm;
    pt_Cnr = new IspPPCnr;
    pt_decompander0 = new IspPPdecompander0;
    pt_decompander1 = new IspPPdecompander1;
    pt_demosaic_rgbir = new IspPPdemosaic_rgbir;
    pt_ds_cs_conv = new IspPPds_cs_conv;
    pt_ds_dma_writer = new IspPPds_dma_writer;
    pt_ds_gamma_rgb = new IspPPds_gamma_rgb;
    pt_ds_sharpen = new IspPPds_sharpen;
    pt_fr_cs_conv = new IspPPfr_cs_conv;
    pt_fr_dma_writer = new IspPPfr_dma_writer;
    pt_fr_gamma_rgb = new IspPPfr_gamma_rgb;
    pt_fr_sharpen = new IspPPfr_sharpen;
    pt_frame_stitch = new IspPPframe_stitch;
    pt_input_formatter = new IspPPinput_formatter;
    pt_mesh_shading = new IspPPmesh_shading;
    pt_metering_aexp = new IspPPmetering_aexp;
    pt_metering_af = new IspPPmetering_af;
    pt_metering_awb = new IspPPmetering_awb;
    pt_metering_ihist = new IspPPmetering_ihist;
    pt_radial_shading = new IspPPradial_shading;
    pt_raw_frontend = new IspPPraw_frontend;
    pt_sensor_offset = new IspPPsensor_offset;
    pt_sinter = new IspPPsinter;
    pt_temper = new IspPPtemper;
    pt_top = new IspPPtop;
    pt_white_balance_aexp = new IspPPwhite_balance_aexp;

    ptStackedLayout->addWidget(pt_black_level);
    ptStackedLayout->addWidget(pt_Ca_correction);
    ptStackedLayout->addWidget(pt_Ccm);
    ptStackedLayout->addWidget(pt_Cnr);
    ptStackedLayout->addWidget(pt_decompander0);
    ptStackedLayout->addWidget(pt_decompander1);
    ptStackedLayout->addWidget(pt_demosaic_rgbir);
    ptStackedLayout->addWidget(pt_ds_cs_conv);
    ptStackedLayout->addWidget(pt_ds_dma_writer);
    ptStackedLayout->addWidget(pt_ds_gamma_rgb);
    ptStackedLayout->addWidget(pt_ds_sharpen);
    ptStackedLayout->addWidget(pt_fr_cs_conv);
    ptStackedLayout->addWidget(pt_fr_dma_writer);
    ptStackedLayout->addWidget(pt_fr_gamma_rgb);
    ptStackedLayout->addWidget(pt_fr_sharpen);
    ptStackedLayout->addWidget(pt_frame_stitch);
    ptStackedLayout->addWidget(pt_input_formatter);
    ptStackedLayout->addWidget(pt_mesh_shading);
    ptStackedLayout->addWidget(pt_metering_aexp);
    ptStackedLayout->addWidget(pt_metering_af);
    ptStackedLayout->addWidget(pt_metering_awb);
    ptStackedLayout->addWidget(pt_metering_ihist);
    ptStackedLayout->addWidget(pt_radial_shading);
    ptStackedLayout->addWidget(pt_raw_frontend);
    ptStackedLayout->addWidget(pt_sensor_offset);
    ptStackedLayout->addWidget(pt_sinter);
    ptStackedLayout->addWidget(pt_temper);
    ptStackedLayout->addWidget(pt_top);
    ptStackedLayout->addWidget(pt_white_balance_aexp);

    ptListWidget->setViewMode(QListView::IconMode);
    ptListWidget->setIconSize(QSize(130, 32));
    ptListWidget->setMovement(QListView::Static);
    ptListWidget->setMaximumWidth(140);
    ptListWidget->setSpacing(5);
    ptListWidget->setFrameShape(QFrame::NoFrame);

    QListWidgetItem *ptListBtn_black_level = new QListWidgetItem(ptListWidget);
    ptListBtn_black_level->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_black_level->setText(tr("    black_level  "));
    ptListBtn_black_level->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_black_level->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_Ca_correction = new QListWidgetItem(ptListWidget);
    ptListBtn_Ca_correction->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_Ca_correction->setText(tr(" ca correction"));
    ptListBtn_Ca_correction->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_Ca_correction->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_Ccm = new QListWidgetItem(ptListWidget);
    ptListBtn_Ccm->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_Ccm->setText(tr("         ccm     "));
    ptListBtn_Ccm->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_Ccm->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_Cnr = new QListWidgetItem(ptListWidget);
    ptListBtn_Cnr->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_Cnr->setText(tr("         cnr     "));
    ptListBtn_Cnr->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_Cnr->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_decompander0 = new QListWidgetItem(ptListWidget);
    ptListBtn_decompander0->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_decompander0->setText(tr("decompander0"));
    ptListBtn_decompander0->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_decompander0->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_decompander1 = new QListWidgetItem(ptListWidget);
    ptListBtn_decompander1->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_decompander1->setText(tr("decompander1"));
    ptListBtn_decompander1->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_decompander1->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_demosaic_rgbir = new QListWidgetItem(ptListWidget);
    ptListBtn_demosaic_rgbir->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_demosaic_rgbir->setText(tr("demosaic_rgbir"));
    ptListBtn_demosaic_rgbir->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_demosaic_rgbir->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_ds_cs_conv = new QListWidgetItem(ptListWidget);
    ptListBtn_ds_cs_conv->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_ds_cs_conv->setText(tr("    ds_cs_conv "));
    ptListBtn_ds_cs_conv->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_ds_cs_conv->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_ds_dma_writer = new QListWidgetItem(ptListWidget);
    ptListBtn_ds_dma_writer->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_ds_dma_writer->setText(tr(" ds_dma_writer"));
    ptListBtn_ds_dma_writer->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_ds_dma_writer->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_ds_gamma_rgb = new QListWidgetItem(ptListWidget);
    ptListBtn_ds_gamma_rgb->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_ds_gamma_rgb->setText(tr("ds_gamma_rgb"));
    ptListBtn_ds_gamma_rgb->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_ds_gamma_rgb->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_ds_sharpen = new QListWidgetItem(ptListWidget);
    ptListBtn_ds_sharpen->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_ds_sharpen->setText(tr("    ds_sharpen   "));
    ptListBtn_ds_sharpen->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_ds_sharpen->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_fr_cs_conv = new QListWidgetItem(ptListWidget);
    ptListBtn_fr_cs_conv->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_fr_cs_conv->setText(tr("    fr_cs_conv  "));
    ptListBtn_fr_cs_conv->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_fr_cs_conv->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_fr_dma_writer = new QListWidgetItem(ptListWidget);
    ptListBtn_fr_dma_writer->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_fr_dma_writer->setText(tr("   fr_dma_writer  "));
    ptListBtn_fr_dma_writer->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_fr_dma_writer->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_fr_gamma_rgb = new QListWidgetItem(ptListWidget);
    ptListBtn_fr_gamma_rgb->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_fr_gamma_rgb->setText(tr("   fr_gamma_rgb  "));
    ptListBtn_fr_gamma_rgb->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_fr_gamma_rgb->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_fr_sharpen = new QListWidgetItem(ptListWidget);
    ptListBtn_fr_sharpen->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_fr_sharpen->setText(tr("    fr_sharpen   "));
    ptListBtn_fr_sharpen->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_fr_sharpen->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_frame_stitch = new QListWidgetItem(ptListWidget);
    ptListBtn_frame_stitch->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_frame_stitch->setText(tr(" frame_stitch "));
    ptListBtn_frame_stitch->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_frame_stitch->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_input_formatter = new QListWidgetItem(ptListWidget);
    ptListBtn_input_formatter->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_input_formatter->setText(tr("input_formatter"));
    ptListBtn_input_formatter->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_input_formatter->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_mesh_shading = new QListWidgetItem(ptListWidget);
    ptListBtn_mesh_shading->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_mesh_shading->setText(tr(" mesh_shading"));
    ptListBtn_mesh_shading->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_mesh_shading->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_metering_aexp = new QListWidgetItem(ptListWidget);
    ptListBtn_metering_aexp->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_metering_aexp->setText(tr("metering_aexp"));
    ptListBtn_metering_aexp->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_metering_aexp->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_metering_af = new QListWidgetItem(ptListWidget);
    ptListBtn_metering_af->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_metering_af->setText(tr("  metering_af "));
    ptListBtn_metering_af->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_metering_af->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_metering_awb = new QListWidgetItem(ptListWidget);
    ptListBtn_metering_awb->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_metering_awb->setText(tr("metering_awb"));
    ptListBtn_metering_awb->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_metering_awb->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_metering_ihist = new QListWidgetItem(ptListWidget);
    ptListBtn_metering_ihist->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_metering_ihist->setText(tr("metering_ihist"));
    ptListBtn_metering_ihist->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_metering_ihist->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_radial_shading = new QListWidgetItem(ptListWidget);
    ptListBtn_radial_shading->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_radial_shading->setText(tr("radial_shading"));
    ptListBtn_radial_shading->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_radial_shading->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_raw_frontend = new QListWidgetItem(ptListWidget);
    ptListBtn_raw_frontend->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_raw_frontend->setText(tr("raw_frontend"));
    ptListBtn_raw_frontend->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_raw_frontend->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_sensor_offset = new QListWidgetItem(ptListWidget);
    ptListBtn_sensor_offset->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_sensor_offset->setText(tr("sensor_offset"));
    ptListBtn_sensor_offset->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_sensor_offset->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_sinter = new QListWidgetItem(ptListWidget);
    ptListBtn_sinter->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_sinter->setText(tr("        sinter     "));
    ptListBtn_sinter->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_sinter->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_temper = new QListWidgetItem(ptListWidget);
    ptListBtn_temper->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_temper->setText(tr("         temper     "));
    ptListBtn_temper->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_temper->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_top = new QListWidgetItem(ptListWidget);
    ptListBtn_top->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_top->setText(tr("         top       "));
    ptListBtn_top->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_top->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_white_balance_aexp = new QListWidgetItem(ptListWidget);
    ptListBtn_white_balance_aexp->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_white_balance_aexp->setText(tr("white_balance\naexp"));
    ptListBtn_white_balance_aexp->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_white_balance_aexp->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    QHBoxLayout *layoutMain = new QHBoxLayout;
    layoutMain->addWidget(ptListWidget);
    layoutMain->addLayout(ptStackedLayout);
    setLayout(layoutMain);

    connect(ptListWidget,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));

    ptListWidget->setCurrentRow(0);
}

void IspPingPong::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{

}
