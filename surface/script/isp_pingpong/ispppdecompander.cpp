#include "ispppdecompander.h"
#include <QGridLayout>
IspPPdecompander::IspPPdecompander(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    ptLabel_decompander0_reg_enable = new QLabel("decompander0 reg_enable :");
    ptEdit_decompander0_reg_enable  = new QLineEdit("00000001");
    layoutGrid->addWidget(ptLabel_decompander0_reg_enable,0,0);layoutGrid->addWidget(ptEdit_decompander0_reg_enable,0,1);

    ptLabel_decompander1_reg_enable = new QLabel("decompander1 reg_enable :");
    ptEdit_decompander1_reg_enable  = new QLineEdit("00000001");
    layoutGrid->addWidget(ptLabel_decompander1_reg_enable,1,0);layoutGrid->addWidget(ptEdit_decompander1_reg_enable,1,1);

    ptCb_decompander0_ping_mem = new QComboBox;
    ptEdit_decompander0_ping_mem  = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_decompander0_ping_mem,2,0);layoutGrid->addWidget(ptEdit_decompander0_ping_mem,2,1);
    for(unsigned int i = 0;i < M_DECOMPANDER0_PING_MEN; ++i)
    {
        QString str;
        str.sprintf("decompander0_ping_mem[%x]",i);
        ptCb_decompander0_ping_mem->addItem(str);
        szQStr_decompander0_ping_mem[i].sprintf("%x",i);
    }
    ptEdit_decompander0_ping_mem->setText(szQStr_decompander0_ping_mem[ptCb_decompander0_ping_mem->currentIndex()]);

    ptCb_decompander1_ping_mem  = new QComboBox;
    ptEdit_decompander1_ping_mem = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_decompander1_ping_mem,3,0);layoutGrid->addWidget(ptEdit_decompander1_ping_mem,3,1);
    for(unsigned int i = 0;i < M_DECOMPANDER1_PING_MEN; ++i)
    {
        QString str;
        str.sprintf("decompander1_ping_mem[%x]",i);
        ptCb_decompander1_ping_mem->addItem(str);
        szQStr_decompander1_ping_mem[i].sprintf("%x",i);
    }
    ptEdit_decompander1_ping_mem->setText(szQStr_decompander1_ping_mem[ptCb_decompander1_ping_mem->currentIndex()]);

    ptPBtn = new QPushButton("确定");
    layoutGrid->addWidget(ptPBtn,5,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

    connect(ptCb_decompander0_ping_mem,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_decompander0_ping(int)));
    connect(ptEdit_decompander0_ping_mem,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_decompander0_ping(const QString)));

    connect(ptCb_decompander1_ping_mem,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_decompander1_ping(int)));
    connect(ptEdit_decompander1_ping_mem,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_decompander1_ping(const QString)));

    setLayout(mainLayout);
}

void IspPPdecompander::clickedSlot(bool checked)
{
    QString str_decompander0_reg_enable = ptEdit_decompander0_reg_enable->text();
    QString str_decompander1_reg_enable = ptEdit_decompander1_reg_enable->text();
}

void IspPPdecompander::activatedSlot_decompander0_ping(int index)
{
    ptEdit_decompander0_ping_mem->setText(szQStr_decompander0_ping_mem[index]);
}

void IspPPdecompander::textChangedSlot_decompander0_ping(const QString &text)
{
    int index = ptCb_decompander0_ping_mem->currentIndex();
    szQStr_decompander0_ping_mem[index] = text;
}

void IspPPdecompander::activatedSlot_decompander1_ping(int index)
{
    ptEdit_decompander1_ping_mem->setText(szQStr_decompander1_ping_mem[index]);
}

void IspPPdecompander::textChangedSlot_decompander1_ping(const QString &text)
{
    int index = ptCb_decompander0_ping_mem->currentIndex();
    szQStr_decompander1_ping_mem[index] = text;
}
