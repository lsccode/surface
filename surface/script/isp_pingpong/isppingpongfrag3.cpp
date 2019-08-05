#include "isppingpongfrag3.h"

IspPingPongFrag3::IspPingPongFrag3(QWidget *parent) :
    QWidget(parent)
{
    ptListWidget = new QListWidget;
    ptStackedLayout =  new QStackedLayout;

    pt_metering_awb = new IspPPmetering_awb;
    pt_metering_ihist = new IspPPmetering_ihist;
    pt_radial_shading = new IspPPradial_shading;
    pt_raw_frontend = new IspPPraw_frontend;
    pt_sensor_offset = new IspPPsensor_offset;
    pt_sinter = new IspPPsinter;
    pt_temper = new IspPPtemper;
    pt_top = new IspPPtop;
    pt_white_balance_aexp = new IspPPwhite_balance_aexp;

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

//    QListWidgetItem *ptListBtn_metering_awb = new QListWidgetItem(ptListWidget);
//    ptListBtn_metering_awb->setIcon(QIcon(":/images/metring_awb.png"));
//    //ptListBtn_metering_awb->setText(tr("metering_awb"));
//    ptListBtn_metering_awb->setTextAlignment(Qt::AlignHCenter);
//    ptListBtn_metering_awb->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

//    QListWidgetItem *ptListBtn_metering_ihist = new QListWidgetItem(ptListWidget);
//    ptListBtn_metering_ihist->setIcon(QIcon(":/images/metring_ihist.png"));
//    //ptListBtn_metering_ihist->setText(tr("metering_ihist"));
//    ptListBtn_metering_ihist->setTextAlignment(Qt::AlignHCenter);
//    ptListBtn_metering_ihist->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_radial_shading = new QListWidgetItem(ptListWidget);
    ptListBtn_radial_shading->setIcon(QIcon(":/images/radial_shading.png"));
    //ptListBtn_radial_shading->setText(tr("radial_shading"));
    ptListBtn_radial_shading->setTextAlignment(Qt::AlignHCenter);
    ptListBtn_radial_shading->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtn_raw_frontend = new QListWidgetItem(ptListWidget);
    ptListBtn_raw_frontend->setIcon(QIcon(":/images/raw_front.png"));
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
    QHBoxLayout *layoutMain = new QHBoxLayout;
    layoutMain->addWidget(ptListWidget);
    layoutMain->addLayout(ptStackedLayout);
    setLayout(layoutMain);

    connect(ptListWidget,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));

    ptListWidget->setCurrentRow(0);
}

void IspPingPongFrag3::changePage(QListWidgetItem *current, QListWidgetItem *previous)
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
