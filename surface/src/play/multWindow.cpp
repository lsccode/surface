#include "multWindow.h"

picWindow04::picWindow04(QWidget *parent):QWidget(parent)
{
    for(int i = 0;i < 4;++i)
    {
        pic04[i] = new picWindow;
    }
    QGridLayout *layoutGrid = new QGridLayout;
    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < 2;j++)
        {
            layoutGrid->addWidget(pic04[i*2+j],i,j,1,1);
        }
    }
    layoutGrid->setMargin(0);
    setLayout(layoutGrid);
}
picWindow09::picWindow09(QWidget *parent):QWidget(parent)
{
    for(int i = 0;i < 9;++i)
    {
        pic09[i] = new picWindow;
    }
    QGridLayout *layoutGrid = new QGridLayout;
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            layoutGrid->addWidget(pic09[i*3+j],i,j,1,1);
        }
    }
    layoutGrid->setMargin(0);
    setLayout(layoutGrid);
}
picWindow17::picWindow17(QWidget *parent):QWidget(parent)
{
    for(int i = 0;i < 17;++i)
    {
        pic17[i] = new picWindow;
    }
    QGridLayout *layoutGrid = new QGridLayout;
    {
        for(int i = 0;i < 5;i++)
        {
            layoutGrid->addWidget(pic17[i],0,i);
            layoutGrid->addWidget(pic17[i+11],4,i);
        }
        for(int i = 1;i < 4;i++)
        {
            layoutGrid->addWidget(pic17[i+4],i,0);
            layoutGrid->addWidget(pic17[i+7],i,4);
        }
        layoutGrid->addWidget(pic17[16],1,1,3,3);

    }
    layoutGrid->setMargin(0);
    setLayout(layoutGrid);
}
