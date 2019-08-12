#include "isppingpongfrag1.h"

IspPingPongFrag1::IspPingPongFrag1(QWidget *parent) :
    QWidget(parent),IspCommonStep()
{
    ptListWidget = new QListWidget;
    ptStackedLayout =  new QStackedLayout;

    pt_misc = new IspPPmisc;
    pt_Ca_correction = new IspPPCa_correction;
    pt_Ccm = new IspPPCcm;
    pt_Cnr = new IspPPCnr;
    pt_decompander = new IspPPdecompander;
    pt_demosaic_rgbir = new IspPPdemosaic_rgbir;
    pt_ds_config = new IspPPds_config;
    pt_fr_config = new IspPPfr_config;
    pt_frame_stitch = new IspPPframe_stitch;
    pt_input_formatter = new IspPPinput_formatter;

    ptPBtnOK = new QPushButton("确定");
    //ptPBtnExec = new QPushButton("执行");

    ptStackedLayout->addWidget(pt_misc);
    ptStackedLayout->addWidget(pt_Ca_correction);
    ptStackedLayout->addWidget(pt_Ccm);
    ptStackedLayout->addWidget(pt_Cnr);
    ptStackedLayout->addWidget(pt_decompander);
    ptStackedLayout->addWidget(pt_demosaic_rgbir);
    ptStackedLayout->addWidget(pt_ds_config);
    ptStackedLayout->addWidget(pt_fr_config);
    ptStackedLayout->addWidget(pt_frame_stitch);
    ptStackedLayout->addWidget(pt_input_formatter);

    ptListWidget->setViewMode(QListView::IconMode);
    ptListWidget->setIconSize(QSize(104, 16));
    ptListWidget->setMovement(QListView::Static);
    ptListWidget->setMaximumWidth(122);
    ptListWidget->setSpacing(5);
    ptListWidget->setFrameShape(QFrame::NoFrame);

    QListWidgetItem *ptListBtn_black_level = new QListWidgetItem(ptListWidget);
    ptListBtn_black_level->setIcon(QIcon(":/images/misc.png"));
    //ptListBtn_black_level->setText(tr("     misc   "));
    ptListBtn_black_level->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_black_level->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_Ca_correction = new QListWidgetItem(ptListWidget);
    ptListBtn_Ca_correction->setIcon(QIcon(":/images/ca_correction.png"));
    //ptListBtn_Ca_correction->setText(tr("  ca correction  "));
    ptListBtn_Ca_correction->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_Ca_correction->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_Ccm = new QListWidgetItem(ptListWidget);
    ptListBtn_Ccm->setIcon(QIcon(":/images/ccm.png"));
    //ptListBtn_Ccm->setText(tr("         ccm        "));
    ptListBtn_Ccm->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_Ccm->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_Cnr = new QListWidgetItem(ptListWidget);
    ptListBtn_Cnr->setIcon(QIcon(":/images/cnr.png"));
    //ptListBtn_Cnr->setText(tr("         cnr         "));
    ptListBtn_Cnr->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_Cnr->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_decompander0 = new QListWidgetItem(ptListWidget);
    ptListBtn_decompander0->setIcon(QIcon(":/images/decompander.png"));
    //ptListBtn_decompander0->setText(tr(" decompander "));
    ptListBtn_decompander0->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_decompander0->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_demosaic_rgbir = new QListWidgetItem(ptListWidget);
    ptListBtn_demosaic_rgbir->setIcon(QIcon(":/images/demosaic_rgbir.png"));
    //ptListBtn_demosaic_rgbir->setText(tr("demosaic_rgbir"));
    ptListBtn_demosaic_rgbir->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_demosaic_rgbir->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_ds_cs_conv = new QListWidgetItem(ptListWidget);
    ptListBtn_ds_cs_conv->setIcon(QIcon(":/images/ds_config.png"));
    //ptListBtn_ds_cs_conv->setText(tr("    ds_config   "));
    ptListBtn_ds_cs_conv->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_ds_cs_conv->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_ds_sharpen = new QListWidgetItem(ptListWidget);
    ptListBtn_ds_sharpen->setIcon(QIcon(":/images/fr_config.png"));
   // ptListBtn_ds_sharpen->setText(tr("     fr_config    "));
    ptListBtn_ds_sharpen->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_ds_sharpen->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_frame_stitch = new QListWidgetItem(ptListWidget);
    ptListBtn_frame_stitch->setIcon(QIcon(":/images/frame_stitch.png"));
    //ptListBtn_frame_stitch->setText(tr("  frame_stitch   "));
    ptListBtn_frame_stitch->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_frame_stitch->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_input_formatter = new QListWidgetItem(ptListWidget);
    ptListBtn_input_formatter->setIcon(QIcon(":/images/input_formatter.png"));
   // ptListBtn_input_formatter->setText(tr("input_formatter"));
    ptListBtn_input_formatter->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_input_formatter->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

#if 0
    QHBoxLayout *layoutMain = new QHBoxLayout;
    layoutMain->addWidget(ptListWidget);
    layoutMain->addLayout(ptStackedLayout);
    setLayout(layoutMain);
#else
    QGridLayout *layoutTop = new QGridLayout;
    layoutTop->addWidget(ptListWidget,0,0,2,1);
    layoutTop->addLayout(ptStackedLayout,0,1,1,2);
    layoutTop->addWidget(ptPBtnOK,1,1);
    //layoutTop->addWidget(ptPBtnExec,1,2);
    setLayout(layoutTop);
#endif


    connect(ptListWidget,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));

    connect(ptPBtnOK,SIGNAL(clicked(bool)),this,SLOT(clickedPingPongF1OkSlot(bool)));
    //connect(ptPBtnExec,SIGNAL(clicked(bool)),this,SLOT(clickedPingPongF1ExecSlot(bool)));

    ptListWidget->setCurrentRow(0);
}

void IspPingPongFrag1::step1()
{
    pt_input_formatter->step1();
    pt_misc->step1();
}

void IspPingPongFrag1::step2()
{
    pt_Ca_correction->step1();
    pt_misc->step2();

}

void IspPingPongFrag1::step3()
{
    pt_demosaic_rgbir->step1();
    pt_Ccm->step1();
    pt_misc->step3();
    pt_decompander->step1();
    pt_misc->step4();
    pt_fr_config->step1();
    pt_ds_config->step1();
    pt_misc->step5();
    pt_frame_stitch->step1();
    pt_misc->step6();
    pt_Cnr->step1();
}

void IspPingPongFrag1::step4()
{
    pt_fr_config->step2();
}

void IspPingPongFrag1::clickedPingPongF1OkSlot(bool checked)
{
    if(checked)
        return;
    emit clickedPingPongF1Sig(true);
}

void IspPingPongFrag1::clickedPingPongF1ExecSlot(bool checked)
{
    if(!checked)
        return;
    execFile();
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

void IspPingPongFrag1::clickedF1OKDisableSlot()
{
    ptPBtnOK->setText(tr("执行中..."));
    ptPBtnOK->setEnabled(false);
}

void IspPingPongFrag1::clickedF1OKEnableSlot()
{
    ptPBtnOK->setEnabled(true);
    ptPBtnOK->setText("确定");
}
