#include "isppingpongfrag2.h"

IspPingPongFrag2::IspPingPongFrag2(QWidget *parent) :
    QWidget(parent)
{
    ptListWidget = new QListWidget;
    ptStackedLayout =  new QStackedLayout;

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

    ptListWidget->setViewMode(QListView::IconMode);
    ptListWidget->setIconSize(QSize(130, 32));
    ptListWidget->setMovement(QListView::Static);
    ptListWidget->setMaximumWidth(120);
    ptListWidget->setSpacing(5);
    ptListWidget->setFrameShape(QFrame::NoFrame);

    QListWidgetItem *ptListBtn_ds_sharpen = new QListWidgetItem(ptListWidget);
    ptListBtn_ds_sharpen->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_ds_sharpen->setText(tr("     ds_sharpen    "));
    ptListBtn_ds_sharpen->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_ds_sharpen->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_fr_cs_conv = new QListWidgetItem(ptListWidget);
    ptListBtn_fr_cs_conv->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_fr_cs_conv->setText(tr("      fr_cs_conv   "));
    ptListBtn_fr_cs_conv->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_fr_cs_conv->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_fr_dma_writer = new QListWidgetItem(ptListWidget);
    ptListBtn_fr_dma_writer->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_fr_dma_writer->setText(tr("   fr_dma_writer  "));
    ptListBtn_fr_dma_writer->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_fr_dma_writer->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_fr_gamma_rgb = new QListWidgetItem(ptListWidget);
    ptListBtn_fr_gamma_rgb->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_fr_gamma_rgb->setText(tr("  fr_gamma_rgb  "));
    ptListBtn_fr_gamma_rgb->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_fr_gamma_rgb->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_fr_sharpen = new QListWidgetItem(ptListWidget);
    ptListBtn_fr_sharpen->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_fr_sharpen->setText(tr("     fr_sharpen    "));
    ptListBtn_fr_sharpen->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_fr_sharpen->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_frame_stitch = new QListWidgetItem(ptListWidget);
    ptListBtn_frame_stitch->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_frame_stitch->setText(tr("  frame_stitch   "));
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
    ptListBtn_metering_af->setText(tr("  metering_af  "));
    ptListBtn_metering_af->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_metering_af->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QHBoxLayout *layoutMain = new QHBoxLayout;
    layoutMain->addWidget(ptListWidget);
    layoutMain->addLayout(ptStackedLayout);
    setLayout(layoutMain);

    connect(ptListWidget,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));

    ptListWidget->setCurrentRow(0);
}

void IspPingPongFrag2::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
    int rowIndex;
    if (!current)
        current = previous;

    rowIndex = ptListWidget->row(current);
    ptStackedLayout->setCurrentIndex(rowIndex);

    switch(rowIndex)
    {
        case 0:
        {

        }break;
        case 1:
        {

        }break;
    }
    return;
}
