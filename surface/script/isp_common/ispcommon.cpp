#include "ispcommon.h"

IspCommon::IspCommon(QWidget *parent) :
    QWidget(parent),IspCommonStep()
{
    ptListWidget = new QListWidget;
    ptStackedLayout =  new QStackedLayout;

    ptWidgtIspCmGlobal    = new IspCmGlobal;
    ptWidgtIspCmInputPort = new IspCminputport;

    ptStackedLayout->addWidget(ptWidgtIspCmGlobal);
    ptStackedLayout->addWidget(ptWidgtIspCmInputPort);

    ptListWidget->setViewMode(QListView::IconMode);
    ptListWidget->setIconSize(QSize(104, 16));
    ptListWidget->setMovement(QListView::Static);
    ptListWidget->setMaximumWidth(122);
    ptListWidget->setSpacing(5);
    ptListWidget->setFrameShape(QFrame::NoFrame);

    ptPBtn = new QPushButton("确定");
    ptPBExec = new QPushButton("执行");

    QListWidgetItem *ptListBtnGlobal = new QListWidgetItem(ptListWidget);
    ptListBtnGlobal->setIcon(QIcon(":/images/isp_global.png"));
   // ptListBtnGlobal->setText(tr("isp_global"));
    ptListBtnGlobal->setTextAlignment(Qt::AlignHCenter);
    ptListBtnGlobal->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtnInput = new QListWidgetItem(ptListWidget);
    ptListBtnInput->setIcon(QIcon(":/images/input_port.png"));
    //ptListBtnInput->setText(tr("input_port"));
    ptListBtnInput->setTextAlignment(Qt::AlignHCenter);
    ptListBtnInput->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

#if 0
    QHBoxLayout *layoutMain = new QHBoxLayout;
    layoutMain->addWidget(ptListWidget);
    layoutMain->addLayout(ptStackedLayout);
    //layoutMain->addWidget(ptPBtn);
    setLayout(layoutMain);
#else
    QGridLayout *layoutTop = new QGridLayout;
    layoutTop->addWidget(ptListWidget,0,0,2,1);
    layoutTop->addLayout(ptStackedLayout,0,1,1,2);
    layoutTop->addWidget(ptPBtn,1,1);
    layoutTop->addWidget(ptPBExec,1,2);
    setLayout(layoutTop);
#endif
    ptListWidget->setCurrentRow(0);

    connect(ptListWidget,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));

    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedCommonSlot(bool)));
    connect(ptPBExec,SIGNAL(clicked(bool)),this,SLOT(clickedCommonExecSlot(bool)));



}

void IspCommon::step1()
{
    initFile();
    ptWidgtIspCmGlobal->step1();
    ptWidgtIspCmInputPort->step1();
    ptWidgtIspCmGlobal->step2();
}

void IspCommon::step2()
{
    ptWidgtIspCmGlobal->step3();
}

void IspCommon::step3()
{
}

void IspCommon::clickedCommonSlot(bool checked)
{
    emit clickedCommonSig(true);
}

void IspCommon::clickedCommonExecSlot(bool checked)
{
    execFile();
}

void IspCommon::changePage(QListWidgetItem *current, QListWidgetItem *previous)
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
