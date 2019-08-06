#include "ispppccm.h"
#include <QGridLayout>
IspPPCcm::IspPPCcm(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    ptLabel_coefft_b_b = new QLabel("coefft_b_b :");
    ptEdit_coefft_b_b  = new QLineEdit("00000149");
    layoutGrid->addWidget(ptLabel_coefft_b_b,0,0);layoutGrid->addWidget(ptEdit_coefft_b_b,0,1);

    ptLabel_coefft_b_g = new QLabel("coefft_b_g :");
    ptEdit_coefft_b_g  = new QLineEdit("000000db");
    layoutGrid->addWidget(ptLabel_coefft_b_g,1,0);layoutGrid->addWidget(ptEdit_coefft_b_g,1,1);

    ptLabel_coefft_b_ir = new QLabel("coefft_b_ir :");
    ptEdit_coefft_b_ir  = new QLineEdit("000000a6");
    layoutGrid->addWidget(ptLabel_coefft_b_ir,2,0);layoutGrid->addWidget(ptEdit_coefft_b_ir,2,1);

    ptLabel_coefft_b_r = new QLabel("coefft_b_r :");
    ptEdit_coefft_b_r  = new QLineEdit("000000d2");
    layoutGrid->addWidget(ptLabel_coefft_b_r,3,0);layoutGrid->addWidget(ptEdit_coefft_b_r,3,1);

    ptLabel_coefft_fog_offset_b = new QLabel("coefft_fog_offset_b :");
    ptEdit_coefft_fog_offset_b  = new QLineEdit("0000000c");
    layoutGrid->addWidget(ptLabel_coefft_fog_offset_b,4,0);layoutGrid->addWidget(ptEdit_coefft_fog_offset_b,4,1);

    ptLabel_coefft_fog_offset_g = new QLabel("coefft_fog_offset_g :");
    ptEdit_coefft_fog_offset_g  = new QLineEdit("00000032");
    layoutGrid->addWidget(ptLabel_coefft_fog_offset_g,5,0);layoutGrid->addWidget(ptEdit_coefft_fog_offset_g,5,1);

    ptLabel_coefft_fog_offset_ir = new QLabel("coefft_fog_offset_ir :");
    ptEdit_coefft_fog_offset_ir  = new QLineEdit("00000038");
    layoutGrid->addWidget(ptLabel_coefft_fog_offset_ir,6,0);layoutGrid->addWidget(ptEdit_coefft_fog_offset_ir,6,1);

    ptLabel_coefft_fog_offset_r = new QLabel("coefft_fog_offset_r :");
    ptEdit_coefft_fog_offset_r  = new QLineEdit("0000002b");
    layoutGrid->addWidget(ptLabel_coefft_fog_offset_r,7,0);layoutGrid->addWidget(ptEdit_coefft_fog_offset_r,7,1);

    ptLabel_coefft_g_b = new QLabel("coefft_g_b :");
    ptEdit_coefft_g_b  = new QLineEdit("000000a7");
    layoutGrid->addWidget(ptLabel_coefft_g_b,8,0);layoutGrid->addWidget(ptEdit_coefft_g_b,8,1);

    ptLabel_coefft_g_g = new QLabel("coefft_g_g :");
    ptEdit_coefft_g_g  = new QLineEdit("00000283");
    layoutGrid->addWidget(ptLabel_coefft_g_g,9,0);layoutGrid->addWidget(ptEdit_coefft_g_g,9,1);

    ptLabel_coefft_g_ir = new QLabel("coefft_g_ir :");
    ptEdit_coefft_g_ir  = new QLineEdit("000004fd");
    layoutGrid->addWidget(ptLabel_coefft_g_ir,10,0);layoutGrid->addWidget(ptEdit_coefft_g_ir,10,1);

    ptLabel_coefft_g_r = new QLabel("coefft_g_r :");
    ptEdit_coefft_g_r  = new QLineEdit("000000d2");
    layoutGrid->addWidget(ptLabel_coefft_g_r,11,0);layoutGrid->addWidget(ptEdit_coefft_g_r,11,1);

    ptLabel_coefft_r_b = new QLabel("coefft_r_b :");
    ptEdit_coefft_r_b  = new QLineEdit("000000ab");
    layoutGrid->addWidget(ptLabel_coefft_r_b,12,0);layoutGrid->addWidget(ptEdit_coefft_r_b,12,1);

    ptLabel_coefft_r_g = new QLabel("coefft_r_g :");
    ptEdit_coefft_r_g  = new QLineEdit("000000b7");
    layoutGrid->addWidget(ptLabel_coefft_r_g,13,0);layoutGrid->addWidget(ptEdit_coefft_r_g,13,1);

    ptLabel_coefft_r_ir = new QLabel("coefft_r_ir :");
    ptEdit_coefft_r_ir  = new QLineEdit("000011b7");
    layoutGrid->addWidget(ptLabel_coefft_r_ir,14,0);layoutGrid->addWidget(ptEdit_coefft_r_ir,14,1);

    ptLabel_coefft_r_r = new QLabel("coefft_r_r :");
    ptEdit_coefft_r_r  = new QLineEdit("00000138");
    layoutGrid->addWidget(ptLabel_coefft_r_r,15,0);layoutGrid->addWidget(ptEdit_coefft_r_r,15,1);

    ptLabel_coefft_wb_b = new QLabel("coefft_wb_b :");
    ptEdit_coefft_wb_b  = new QLineEdit("000008e3");
    layoutGrid->addWidget(ptLabel_coefft_wb_b,16,0);layoutGrid->addWidget(ptEdit_coefft_wb_b,16,1);

    ptLabel_coefft_wb_g = new QLabel("coefft_wb_g :");
    ptEdit_coefft_wb_g  = new QLineEdit("000000fe");
    layoutGrid->addWidget(ptLabel_coefft_wb_g,17,0);layoutGrid->addWidget(ptEdit_coefft_wb_g,17,1);

    ptLabel_coefft_wb_ir = new QLabel("coefft_wb_ir :");
    ptEdit_coefft_wb_ir  = new QLineEdit("000002f7");
    layoutGrid->addWidget(ptLabel_coefft_wb_ir,18,0);layoutGrid->addWidget(ptEdit_coefft_wb_ir,18,1);

    ptLabel_coefft_wb_r = new QLabel("coefft_wb_r :");
    ptEdit_coefft_wb_r  = new QLineEdit("00000063");
    layoutGrid->addWidget(ptLabel_coefft_wb_r,19,0);layoutGrid->addWidget(ptEdit_coefft_wb_r,19,1);

    ptLabel_enable = new QLabel("enable :");
    ptEdit_enable  = new QLineEdit("00000000");
    layoutGrid->addWidget(ptLabel_enable,20,0);layoutGrid->addWidget(ptEdit_enable,20,1);

//    ptPBtn = new QPushButton("确定");
//    layoutGrid->addWidget(ptPBtn,20,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

//    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

    setLayout(mainLayout);
}

void IspPPCcm::step1()
{
    writeLine(E_ACTION_WR,"isp_config_ping.ccm.enable",ptEdit_enable->text());
    writeLine(E_ACTION_RR,"isp_config_ping.ccm.enable");

    writeLine(E_ACTION_WR,"isp_config_ping.ccm.coefft_r_r",ptEdit_coefft_r_r->text());
    writeLine(E_ACTION_RR,"isp_config_ping.ccm.coefft_r_r");
    writeLine(E_ACTION_WR,"isp_config_ping.ccm.coefft_r_g",ptEdit_coefft_r_g->text());
    writeLine(E_ACTION_RR,"isp_config_ping.ccm.coefft_r_g");
    writeLine(E_ACTION_WR,"isp_config_ping.ccm.coefft_r_b",ptEdit_coefft_r_b->text());
    writeLine(E_ACTION_RR,"isp_config_ping.ccm.coefft_r_b");
    writeLine(E_ACTION_WR,"isp_config_ping.ccm.coefft_r_ir",ptEdit_coefft_r_ir->text());
    writeLine(E_ACTION_RR,"isp_config_ping.ccm.coefft_r_ir");

    writeLine(E_ACTION_WR,"isp_config_ping.ccm.coefft_g_r",ptEdit_coefft_g_r->text());
    writeLine(E_ACTION_RR,"isp_config_ping.ccm.coefft_g_r");
    writeLine(E_ACTION_WR,"isp_config_ping.ccm.coefft_g_g",ptEdit_coefft_g_g->text());
    writeLine(E_ACTION_RR,"isp_config_ping.ccm.coefft_g_g");
    writeLine(E_ACTION_WR,"isp_config_ping.ccm.coefft_g_b",ptEdit_coefft_g_b->text());
    writeLine(E_ACTION_RR,"isp_config_ping.ccm.coefft_g_b");
    writeLine(E_ACTION_WR,"isp_config_ping.ccm.coefft_g_ir",ptEdit_coefft_g_ir->text());
    writeLine(E_ACTION_RR,"isp_config_ping.ccm.coefft_g_ir");

    writeLine(E_ACTION_WR,"isp_config_ping.ccm.coefft_b_r",ptEdit_coefft_b_r->text());
    writeLine(E_ACTION_RR,"isp_config_ping.ccm.coefft_b_r");
    writeLine(E_ACTION_WR,"isp_config_ping.ccm.coefft_b_g",ptEdit_coefft_b_g->text());
    writeLine(E_ACTION_RR,"isp_config_ping.ccm.coefft_b_g");
    writeLine(E_ACTION_WR,"isp_config_ping.ccm.coefft_b_b",ptEdit_coefft_b_b->text());
    writeLine(E_ACTION_RR,"isp_config_ping.ccm.coefft_b_b");
    writeLine(E_ACTION_WR,"isp_config_ping.ccm.coefft_b_ir",ptEdit_coefft_b_ir->text());
    writeLine(E_ACTION_RR,"isp_config_ping.ccm.coefft_b_ir");

    writeLine(E_ACTION_WR,"isp_config_ping.ccm.coefft_wb_r",ptEdit_coefft_wb_r->text());
    writeLine(E_ACTION_RR,"isp_config_ping.ccm.coefft_wb_r");
    writeLine(E_ACTION_WR,"isp_config_ping.ccm.coefft_wb_g",ptEdit_coefft_wb_g->text());
    writeLine(E_ACTION_RR,"isp_config_ping.ccm.coefft_wb_g");
    writeLine(E_ACTION_WR,"isp_config_ping.ccm.coefft_wb_b",ptEdit_coefft_wb_b->text());
    writeLine(E_ACTION_RR,"isp_config_ping.ccm.coefft_wb_b");
    writeLine(E_ACTION_WR,"isp_config_ping.ccm.coefft_wb_ir",ptEdit_coefft_wb_ir->text());
    writeLine(E_ACTION_RR,"isp_config_ping.ccm.coefft_wb_ir");

    writeLine(E_ACTION_WR,"isp_config_ping.ccm.coefft_fog_offset_r",ptEdit_coefft_fog_offset_r->text());
    writeLine(E_ACTION_RR,"isp_config_ping.ccm.coefft_fog_offset_r");
    writeLine(E_ACTION_WR,"isp_config_ping.ccm.coefft_fog_offset_g",ptEdit_coefft_fog_offset_g->text());
    writeLine(E_ACTION_RR,"isp_config_ping.ccm.coefft_fog_offset_g");
    writeLine(E_ACTION_WR,"isp_config_ping.ccm.coefft_fog_offset_b",ptEdit_coefft_fog_offset_b->text());
    writeLine(E_ACTION_RR,"isp_config_ping.ccm.coefft_fog_offset_b");
    writeLine(E_ACTION_WR,"isp_config_ping.ccm.coefft_fog_offset_ir",ptEdit_coefft_fog_offset_ir->text());
    writeLine(E_ACTION_RR,"isp_config_ping.ccm.coefft_fog_offset_ir");
}

void IspPPCcm::clickedSlot(bool checked)
{

    QString str_coefft_b_b = ptEdit_coefft_b_b->text();
    QString str_coefft_b_g = ptEdit_coefft_b_g->text();
    QString str_coefft_b_ir = ptEdit_coefft_b_ir->text();
    QString str_coefft_b_r = ptEdit_coefft_b_r->text();
    QString str_coefft_fog_offset_b = ptEdit_coefft_fog_offset_b->text();
    QString str_coefft_fog_offset_g = ptEdit_coefft_fog_offset_g->text();
    QString str_coefft_fog_offset_ir = ptEdit_coefft_fog_offset_ir->text();
    QString str_coefft_fog_offset_r = ptEdit_coefft_fog_offset_r->text();
    QString str_coefft_g_b = ptEdit_coefft_g_b->text();
    QString str_coefft_g_g = ptEdit_coefft_g_g->text();
    QString str_coefft_g_ir = ptEdit_coefft_g_ir->text();
    QString str_coefft_g_r = ptEdit_coefft_g_r->text();
    QString str_coefft_r_b = ptEdit_coefft_r_b->text();
    QString str_coefft_r_g = ptEdit_coefft_r_g->text();
    QString str_coefft_r_ir = ptEdit_coefft_r_ir->text();
    QString str_coefft_r_ = ptEdit_coefft_r_r->text();
    QString str_coefft_wb_b = ptEdit_coefft_wb_b->text();
    QString str_coefft_wb_g = ptEdit_coefft_wb_g->text();
    QString str_coefft_wb_ir = ptEdit_coefft_wb_ir->text();
    QString str_coefft_wb_r = ptEdit_coefft_wb_r->text();
}
