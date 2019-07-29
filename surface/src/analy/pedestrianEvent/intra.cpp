#include "pedestrianEvent/intra.h"
IntraCfg::IntraCfg(QWidget *parent):QWidget(parent)
{
    playWidget = new picWindow;
    QHBoxLayout *layoutTop = new QHBoxLayout;
    layoutTop->addWidget(playWidget);
    layoutTop->setMargin(0);
    setLayout(layoutTop);
}
