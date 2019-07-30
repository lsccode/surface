#include "ispppca_correction.h"
#include <QGridLayout>
IspPPCa_correction::IspPPCa_correction(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    ptLabel_mesh_reload = new QLabel("mesh_reload:");
    ptEdit_mesh_reload  = new QLineEdit("00000001");
    layoutGrid->addWidget(ptLabel_mesh_reload,1,0);layoutGrid->addWidget(ptEdit_mesh_reload,1,1);

    ptLabel_reg_enable = new QLabel("reg_enable");
    ptEdit_reg_enable  = new QLineEdit("00000001");
    layoutGrid->addWidget(ptLabel_reg_enable,0,0);layoutGrid->addWidget(ptEdit_reg_enable,0,1);

    ptLabel_reg_line_offset = new QLabel("reg_line_offset:");
    ptEdit_reg_line_offset  = new QLineEdit("0576ffff");
    layoutGrid->addWidget(ptLabel_reg_line_offset,2,0);layoutGrid->addWidget(ptEdit_reg_line_offset,2,1);

    ptLabel_reg_mesh_width = new QLabel("reg_mesh_width:");
    ptEdit_reg_mesh_width  = new QLineEdit("0000d5cb");
    layoutGrid->addWidget(ptLabel_reg_mesh_width,3,0);layoutGrid->addWidget(ptEdit_reg_mesh_width,3,1);

    ptCb_ca_correction_mesh_ping_mem = new QComboBox;
    ptEdit_ca_correction_mesh_ping_mem  = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_ca_correction_mesh_ping_mem,4,0);layoutGrid->addWidget(ptEdit_ca_correction_mesh_ping_mem,4,1);
    for(unsigned int i = 0;i < M_MESH_PING_MEM_NUM; ++i)
    {
        QString str;
        str.sprintf("ca_correction_filter_ping_mem[%x]",i);
        ptCb_ca_correction_mesh_ping_mem->addItem(str);
        szQStr_mesh_ping_mem[i].sprintf("%x");
    }
    ptEdit_ca_correction_mesh_ping_mem->setText(szQStr_mesh_ping_mem[ptCb_ca_correction_mesh_ping_mem->currentIndex()]);

    ptCb_correction_filter_ping_mem  = new QComboBox;
    ptEdit_correction_filter_ping_mem = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_correction_filter_ping_mem,5,0);layoutGrid->addWidget(ptEdit_correction_filter_ping_mem,5,1);
    for(unsigned int i = 0;i < M_FILTER_PING_MEM_NUM; ++i)
    {
        QString str;
        str.sprintf("ca_correction_filter_ping_mem[%x]",i);
        ptCb_correction_filter_ping_mem->addItem(str);
        szQStr_filter_ping_mem[i].sprintf("%x");
    }
    ptEdit_correction_filter_ping_mem->setText(szQStr_filter_ping_mem[ptCb_correction_filter_ping_mem->currentIndex()]);

    ptPBtn = new QPushButton("确定");
    layoutGrid->addWidget(ptPBtn,8,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

    connect(ptCb_ca_correction_mesh_ping_mem,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_mesh_ping(int)));
    connect(ptEdit_ca_correction_mesh_ping_mem,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_mesh_ping(const QString)));

    connect(ptCb_correction_filter_ping_mem,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_filter_ping(int)));
    connect(ptEdit_correction_filter_ping_mem,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_filter_ping(const QString)));

    setLayout(mainLayout);
}

void IspPPCa_correction::clickedSlot(bool checked)
{
    QString str_mesh_reload = ptEdit_mesh_reload->text();
    QString str_reg_enable = ptEdit_reg_enable->text();
    QString strt_reg_line_offset = ptEdit_reg_line_offset->text();
    QString str_reg_mesh_width = ptEdit_reg_mesh_width->text();
}

void IspPPCa_correction::activatedSlot_mesh_ping(int index)
{
    ptEdit_ca_correction_mesh_ping_mem->setText(szQStr_mesh_ping_mem[index]);
}

void IspPPCa_correction::textChangedSlot_mesh_ping(const QString &text)
{
    int index = ptCb_ca_correction_mesh_ping_mem->currentIndex();
    szQStr_mesh_ping_mem[index] = text;
}

void IspPPCa_correction::activatedSlot_filter_ping(int index)
{
    ptEdit_correction_filter_ping_mem->setText(szQStr_filter_ping_mem[index]);
}

void IspPPCa_correction::textChangedSlot_filter_ping(const QString &text)
{
    int index = ptCb_correction_filter_ping_mem->currentIndex();
    szQStr_filter_ping_mem[index] = text;
}
