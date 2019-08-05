#include "ispppmetering_awb.h"
#include <QGridLayout>
IspPPmetering_awb::IspPPmetering_awb(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    // add edit

    ptPBtn = new QPushButton("确定");
    layoutGrid->addWidget(ptPBtn,40,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

    setLayout(mainLayout);
}

void IspPPmetering_awb::clickedSlot(bool checked)
{

}
