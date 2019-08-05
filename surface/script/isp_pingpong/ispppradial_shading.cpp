#include "ispppradial_shading.h"
#include <QGridLayout>
IspPPradial_shading::IspPPradial_shading(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    // add edit
    ptLabel_enable  = new QLabel("enable :");
    ptEdit_enable  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_enable ,0,0);layoutGrid->addWidget(ptEdit_enable ,0,1);

    ptLabel_reg_centerb_x  = new QLabel("reg_centerb_x :");
    ptEdit_reg_centerb_x  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_centerb_x ,1,0);layoutGrid->addWidget(ptEdit_reg_centerb_x ,1,1);

    ptLabel_reg_centerg_x  = new QLabel("reg_centerg_x :");
    ptEdit_reg_centerg_x  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_centerg_x ,2,0);layoutGrid->addWidget(ptEdit_reg_centerg_x ,2,1);

    ptLabel_reg_centerir_x  = new QLabel("reg_centerir_x :");
    ptEdit_reg_centerir_x  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_centerir_x ,3,0);layoutGrid->addWidget(ptEdit_reg_centerir_x ,3,1);

    ptLabel_reg_centerr_x  = new QLabel("reg_centerr_x :");
    ptEdit_reg_centerr_x  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_centerr_x ,4,0);layoutGrid->addWidget(ptEdit_reg_centerr_x ,4,1);

    ptLabel_reg_off_center_multbx  = new QLabel("reg_off_center_multbx :");
    ptEdit_reg_off_center_multbx  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_off_center_multbx ,5,0);layoutGrid->addWidget(ptEdit_reg_off_center_multbx ,5,1);

    ptLabel_reg_off_center_multgx  = new QLabel("reg_off_center_multgx :");
    ptEdit_reg_off_center_multgx  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_off_center_multgx ,6,0);layoutGrid->addWidget(ptEdit_reg_off_center_multgx ,6,1);

    ptLabel_reg_off_center_multirx  = new QLabel("reg_off_center_multirx :");
    ptEdit_reg_off_center_multirx  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_off_center_multirx ,7,0);layoutGrid->addWidget(ptEdit_reg_off_center_multirx ,7,1);

    ptLabel_reg_off_center_multrx  = new QLabel("reg_off_center_multrx :");
    ptEdit_reg_off_center_multrx  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_off_center_multrx ,8,0);layoutGrid->addWidget(ptEdit_reg_off_center_multrx ,8,1);

    ptCb_radial_shading_ping_mem  = new QComboBox;
    ptEdit_radial_shading_ping_mem = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_radial_shading_ping_mem,9,0);layoutGrid->addWidget(ptEdit_radial_shading_ping_mem,9,1);
    for(unsigned int i = 0;i < M_RADIAL_SHADING_PING_MEM_NUMBER; ++i)
    {
        QString str;
        str.sprintf("radial_shading_ping_mem[%x]",i);
        ptCb_radial_shading_ping_mem->addItem(str);
        szQStr_radial_shading_ping_mem[i].sprintf("%x",i);
    }
    ptEdit_radial_shading_ping_mem->setText(szQStr_radial_shading_ping_mem[ptCb_radial_shading_ping_mem->currentIndex()]);

    ptPBtn = new QPushButton("确定");
    layoutGrid->addWidget(ptPBtn,40,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

    connect(ptCb_radial_shading_ping_mem,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_radial_shading_ping_mem(int)));
    connect(ptEdit_radial_shading_ping_mem,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_radial_shading_ping_mem(const QString)));

    setLayout(mainLayout);
}

void IspPPradial_shading::clickedSlot(bool checked)
{
    QString str_enable = ptEdit_enable->text();
    QString str_reg_centerb_x = ptEdit_reg_centerb_x->text();
    QString str_reg_centerg_x = ptEdit_reg_centerg_x->text();
    QString str_reg_centerir_x = ptEdit_reg_centerir_x->text();
    QString str_reg_centerr_x = ptEdit_reg_centerr_x->text();
    QString str_reg_off_center_multbx = ptEdit_reg_off_center_multbx->text();
    QString str_reg_off_center_multgx = ptEdit_reg_off_center_multgx->text();
    QString str_reg_off_center_multirx = ptEdit_reg_off_center_multirx->text();
    QString str_reg_off_center_multrx = ptEdit_reg_off_center_multrx->text();
}

void IspPPradial_shading::activatedSlot_radial_shading_ping_mem(int index)
{
    ptEdit_radial_shading_ping_mem->setText(szQStr_radial_shading_ping_mem[index]);
}

void IspPPradial_shading::textChangedSlot_radial_shading_ping_mem(const QString &text)
{
    int index = ptCb_radial_shading_ping_mem->currentIndex();
    szQStr_radial_shading_ping_mem[index] = text;
}
