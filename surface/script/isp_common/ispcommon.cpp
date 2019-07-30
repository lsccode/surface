#include "ispcommon.h"

IspCommon::IspCommon(QWidget *parent) :
    QWidget(parent)
{
    ptListWidget = new QListWidget;
    ptStackedLayout =  new QStackedLayout;

    ptWidgtIspCmGlobal    = new IspCmGlobal;
    ptWidgtIspCmInputPort = new IspCminputport;

    ptStackedLayout->addWidget(ptWidgtIspCmGlobal);
    ptStackedLayout->addWidget(ptWidgtIspCmInputPort);

    ptListWidget->setViewMode(QListView::IconMode);
    ptListWidget->setIconSize(QSize(32, 32));
    ptListWidget->setMovement(QListView::Static);
    ptListWidget->setMaximumWidth(110);
    ptListWidget->setSpacing(5);
    ptListWidget->setFrameShape(QFrame::NoFrame);

    QListWidgetItem *ptListBtnGlobal = new QListWidgetItem(ptListWidget);
    ptListBtnGlobal->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtnGlobal->setText(tr("isp_global"));
    ptListBtnGlobal->setTextAlignment(Qt::AlignHCenter);
    ptListBtnGlobal->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *ptListBtnInput = new QListWidgetItem(ptListWidget);
    ptListBtnInput->setIcon(QIcon(":/images/devInfo.png"));
    ptListBtnInput->setText(tr("input_port"));
    ptListBtnInput->setTextAlignment(Qt::AlignHCenter);
    ptListBtnInput->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QHBoxLayout *layoutMain = new QHBoxLayout;
    layoutMain->addWidget(ptListWidget);
    layoutMain->addLayout(ptStackedLayout);
    setLayout(layoutMain);

    connect(ptListWidget,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));

    ptListWidget->setCurrentRow(0);

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
