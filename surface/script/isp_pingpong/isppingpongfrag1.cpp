#include "isppingpongfrag1.h"

IspPingPongFrag1::IspPingPongFrag1(QWidget *parent) :
    QWidget(parent)
{
    ptListWidget = new QListWidget;
    ptStackedLayout =  new QStackedLayout;

    pt_black_level = new IspPPblack_level;
    pt_Ca_correction = new IspPPCa_correction;
    pt_Ccm = new IspPPCcm;
    pt_Cnr = new IspPPCnr;
    pt_decompander = new IspPPdecompander;
    pt_demosaic_rgbir = new IspPPdemosaic_rgbir;
    pt_ds_cs_conv = new IspPPds_cs_conv;
    pt_ds_dma_writer = new IspPPds_dma_writer;
    pt_ds_gamma_rgb = new IspPPds_gamma_rgb;

    ptStackedLayout->addWidget(pt_black_level);
    ptStackedLayout->addWidget(pt_Ca_correction);
    ptStackedLayout->addWidget(pt_Ccm);
    ptStackedLayout->addWidget(pt_Cnr);
    ptStackedLayout->addWidget(pt_decompander);
    ptStackedLayout->addWidget(pt_demosaic_rgbir);
    ptStackedLayout->addWidget(pt_ds_cs_conv);
    ptStackedLayout->addWidget(pt_ds_dma_writer);
    ptStackedLayout->addWidget(pt_ds_gamma_rgb);

    ptListWidget->setViewMode(QListView::IconMode);
    ptListWidget->setIconSize(QSize(130, 32));
    ptListWidget->setMovement(QListView::Static);
    ptListWidget->setMaximumWidth(120);
    ptListWidget->setSpacing(5);
    ptListWidget->setFrameShape(QFrame::NoFrame);

    QListWidgetItem *ptListBtn_black_level = new QListWidgetItem(ptListWidget);
    ptListBtn_black_level->setIcon(QIcon(":/images/ccm.png"));
    ptListBtn_black_level->setText(tr("     black_level   "));
    ptListBtn_black_level->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_black_level->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_Ca_correction = new QListWidgetItem(ptListWidget);
    ptListBtn_Ca_correction->setIcon(QIcon(":/images/ccm.png"));
    ptListBtn_Ca_correction->setText(tr("  ca correction  "));
    ptListBtn_Ca_correction->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_Ca_correction->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_Ccm = new QListWidgetItem(ptListWidget);
    ptListBtn_Ccm->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_Ccm->setText(tr("         ccm        "));
    ptListBtn_Ccm->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_Ccm->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_Cnr = new QListWidgetItem(ptListWidget);
    ptListBtn_Cnr->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_Cnr->setText(tr("         cnr         "));
    ptListBtn_Cnr->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_Cnr->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_decompander0 = new QListWidgetItem(ptListWidget);
    ptListBtn_decompander0->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_decompander0->setText(tr(" decompander "));
    ptListBtn_decompander0->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_decompander0->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_demosaic_rgbir = new QListWidgetItem(ptListWidget);
    ptListBtn_demosaic_rgbir->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_demosaic_rgbir->setText(tr("demosaic_rgbir"));
    ptListBtn_demosaic_rgbir->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_demosaic_rgbir->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_ds_cs_conv = new QListWidgetItem(ptListWidget);
    ptListBtn_ds_cs_conv->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtn_ds_cs_conv->setText(tr("    ds_cs_conv  "));
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

    QHBoxLayout *layoutMain = new QHBoxLayout;
    layoutMain->addWidget(ptListWidget);
    layoutMain->addLayout(ptStackedLayout);
    setLayout(layoutMain);

    connect(ptListWidget,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));

    ptListWidget->setCurrentRow(0);
}

void IspPingPongFrag1::changePage(QListWidgetItem *current, QListWidgetItem *previous)
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
