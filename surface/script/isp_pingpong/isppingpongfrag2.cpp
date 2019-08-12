#include "isppingpongfrag2.h"

IspPingPongFrag2::IspPingPongFrag2(QWidget *parent) :
    QWidget(parent)
{
    ptListWidget = new QListWidget;
    ptStackedLayout =  new QStackedLayout;

//    pt_fr_config = new IspPPfr_config;
//    pt_frame_stitch = new IspPPframe_stitch;
//    pt_input_formatter = new IspPPinput_formatter;
    pt_mesh_shading = new IspPPmesh_shading;
    pt_metering = new IspPPmetering;
//    pt_metering_af = new IspPPmetering_af;
//    pt_metering_awb = new IspPPmetering_awb;
//    pt_metering_ihist = new IspPPmetering_ihist;
    pt_radial_shading = new IspPPradial_shading;
    pt_raw_frontend = new IspPPraw_frontend;
    pt_sensor_offset = new IspPPsensor_offset;
    pt_sinter = new IspPPsinter;
    pt_temper = new IspPPtemper;
    pt_top = new IspPPtop;
    pt_white_balance_aexp = new IspPPwhite_balance_aexp;

    ptPBtnOK = new QPushButton("确定");
    ptPBtnExec = new QPushButton("执行");

//    ptStackedLayout->addWidget(pt_fr_config);
//    ptStackedLayout->addWidget(pt_frame_stitch);
//    ptStackedLayout->addWidget(pt_input_formatter);
    ptStackedLayout->addWidget(pt_mesh_shading);
    ptStackedLayout->addWidget(pt_metering);
//    ptStackedLayout->addWidget(pt_metering_af);
//    ptStackedLayout->addWidget(pt_metering_awb);
//    ptStackedLayout->addWidget(pt_metering_ihist);
    ptStackedLayout->addWidget(pt_radial_shading);
    ptStackedLayout->addWidget(pt_raw_frontend);
    ptStackedLayout->addWidget(pt_sensor_offset);
    ptStackedLayout->addWidget(pt_sinter);
    ptStackedLayout->addWidget(pt_temper);
    ptStackedLayout->addWidget(pt_top);
    ptStackedLayout->addWidget(pt_white_balance_aexp);

    ptListWidget->setViewMode(QListView::IconMode);
    ptListWidget->setIconSize(QSize(104, 16));
    ptListWidget->setMovement(QListView::Static);
    ptListWidget->setMaximumWidth(122);
    ptListWidget->setSpacing(5);
    ptListWidget->setFrameShape(QFrame::NoFrame);

//    QListWidgetItem *ptListBtn_ds_sharpen = new QListWidgetItem(ptListWidget);
//    ptListBtn_ds_sharpen->setIcon(QIcon(":/images/fr_config.png"));
//   // ptListBtn_ds_sharpen->setText(tr("     fr_config    "));
//    ptListBtn_ds_sharpen->setTextAlignment(Qt::AlignHCenter);
//    ptListBtn_ds_sharpen->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

//    QListWidgetItem *ptListBtn_frame_stitch = new QListWidgetItem(ptListWidget);
//    ptListBtn_frame_stitch->setIcon(QIcon(":/images/frame_stitch.png"));
//    //ptListBtn_frame_stitch->setText(tr("  frame_stitch   "));
//    ptListBtn_frame_stitch->setTextAlignment(Qt::AlignHCenter);
//    ptListBtn_frame_stitch->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

//    QListWidgetItem *ptListBtn_input_formatter = new QListWidgetItem(ptListWidget);
//    ptListBtn_input_formatter->setIcon(QIcon(":/images/input_formatter.png"));
//   // ptListBtn_input_formatter->setText(tr("input_formatter"));
//    ptListBtn_input_formatter->setTextAlignment(Qt::AlignHCenter);
//    ptListBtn_input_formatter->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_mesh_shading = new QListWidgetItem(ptListWidget);
    ptListBtn_mesh_shading->setIcon(QIcon(":/images/mesh_shading.png"));
    // ptListBtn_mesh_shading->setText(tr(" mesh_shading"));
    ptListBtn_mesh_shading->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_mesh_shading->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_metering_aexp = new QListWidgetItem(ptListWidget);
    ptListBtn_metering_aexp->setIcon(QIcon(":/images/metering_aexp.png"));
    //ptListBtn_metering_aexp->setText(tr("metering_aexp"));
    ptListBtn_metering_aexp->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_metering_aexp->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

//    QListWidgetItem *ptListBtn_metering_af = new QListWidgetItem(ptListWidget);
//    ptListBtn_metering_af->setIcon(QIcon(":/images/metering_af.png"));
//    //ptListBtn_metering_af->setText(tr("  metering_af  "));
//    ptListBtn_metering_af->setTextAlignment(Qt::AlignHCenter);
//    ptListBtn_metering_af->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_radial_shading = new QListWidgetItem(ptListWidget);
    ptListBtn_radial_shading->setIcon(QIcon(":/images/radial_shading.png"));
    //ptListBtn_radial_shading->setText(tr("radial_shading"));
    ptListBtn_radial_shading->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_radial_shading->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_raw_frontend = new QListWidgetItem(ptListWidget);
    ptListBtn_raw_frontend->setIcon(QIcon(":/images/raw_frontend.png"));
    //ptListBtn_raw_frontend->setText(tr("raw_frontend"));
    ptListBtn_raw_frontend->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_raw_frontend->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_sensor_offset = new QListWidgetItem(ptListWidget);
    ptListBtn_sensor_offset->setIcon(QIcon(":/images/sensor_offset.png"));
    //ptListBtn_sensor_offset->setText(tr("sensor_offset"));
    ptListBtn_sensor_offset->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_sensor_offset->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_sinter = new QListWidgetItem(ptListWidget);
    ptListBtn_sinter->setIcon(QIcon(":/images/sinter.png"));
    //ptListBtn_sinter->setText(tr("        sinter     "));
    ptListBtn_sinter->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_sinter->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_temper = new QListWidgetItem(ptListWidget);
    ptListBtn_temper->setIcon(QIcon(":/images/temper.png"));
    //ptListBtn_temper->setText(tr("      temper     "));
    ptListBtn_temper->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_temper->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_top = new QListWidgetItem(ptListWidget);
    ptListBtn_top->setIcon(QIcon(":/images/top.png"));
    //ptListBtn_top->setText(tr("         top       "));
    ptListBtn_top->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_top->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_white_balance_aexp = new QListWidgetItem(ptListWidget);
    ptListBtn_white_balance_aexp->setIcon(QIcon(":/images/white_balance_aexp.png"));
    //ptListBtn_white_balance_aexp->setText(tr("white_balance\naexp"));
    ptListBtn_white_balance_aexp->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_white_balance_aexp->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

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
    connect(ptPBtnOK,SIGNAL(clicked(bool)),this,SLOT(clickedPingPongF2OkSlot(bool)));
    //connect(ptPBtnExec,SIGNAL(clicked(bool)),this,SLOT(clickedPingPongF2ExecSlot(bool)));
    ptListWidget->setCurrentRow(0);
}

void IspPingPongFrag2::step1()
{
    pt_temper->step1();
    pt_sinter->step1();
}

void IspPingPongFrag2::step2()
{
    pt_top->step1();
}

void IspPingPongFrag2::step3()
{
    pt_sinter->step2();
    pt_temper->step2();
}

void IspPingPongFrag2::step4()
{
    pt_white_balance_aexp->step1();
    pt_radial_shading->step1();
    pt_mesh_shading->step1();
}

void IspPingPongFrag2::step5()
{
    pt_sensor_offset->step1();
    pt_raw_frontend->step1();
}

void IspPingPongFrag2::clickedPingPongF2OkSlot(bool checked)
{
    emit clickedPingPongF2Sig(true);
}

void IspPingPongFrag2::clickedPingPongF2ExecSlot(bool checked)
{
    execFile();
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

void IspPingPongFrag2::clickedF2OKDisableSlot()
{
    ptPBtnOK->setEnabled(false);
}

void IspPingPongFrag2::clickedF2OKEnableSlot()
{
    ptPBtnOK->setEnabled(true);
}
