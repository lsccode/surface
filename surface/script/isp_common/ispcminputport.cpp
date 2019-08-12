#include <QGridLayout>
#include "ispcminputport.h"

IspCminputport::IspCminputport(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    ptLabel_FrStatusReset = new QLabel("frame_stats.stats_reset:");
    ptEdit_FrStatusReset  = new QLineEdit("00000001");
    layoutGrid->addWidget(ptLabel_FrStatusReset,1,0);layoutGrid->addWidget(ptEdit_FrStatusReset,1,1);

    ptLabel_FrStatusHold = new QLabel("frame_stats.stats_hold:");
    ptEdit_FrStatusHold  = new QLineEdit("00000001");
    layoutGrid->addWidget(ptLabel_FrStatusHold,0,0);layoutGrid->addWidget(ptEdit_FrStatusHold,0,1);

    ptLabel_reg_hc_limit = new QLabel("reg_hc_limit:");
    ptEdit_reg_hc_limit  = new QLineEdit("0576ffff");
    layoutGrid->addWidget(ptLabel_reg_hc_limit,2,0);layoutGrid->addWidget(ptEdit_reg_hc_limit,2,1);

    ptLabel_reg_hc_size0 = new QLabel("reg_hc_size0:");
    ptEdit_reg_hc_size0  = new QLineEdit("0741d5cb");
    layoutGrid->addWidget(ptLabel_reg_hc_size0,3,0);layoutGrid->addWidget(ptEdit_reg_hc_size0,3,1);

    ptLabel_reg_hc_size1 = new QLabel("reg_hc_size1:");
    ptEdit_reg_hc_size1  = new QLineEdit("ffffacb0");
    layoutGrid->addWidget(ptLabel_reg_hc_size1,4,0);layoutGrid->addWidget(ptEdit_reg_hc_size1,4,1);

    ptLabel_reg_mode_request = new QLabel("reg_mode_request:");
    ptEdit_reg_mode_request  = new QLineEdit("00000001");
    layoutGrid->addWidget(ptLabel_reg_mode_request,5,0);layoutGrid->addWidget(ptEdit_reg_mode_request,5,1);

    ptLabel_reg_preset = new QLabel("reg_preset:");
    ptEdit_reg_preset  = new QLineEdit("0090c002");
    layoutGrid->addWidget(ptLabel_reg_preset,6,0);layoutGrid->addWidget(ptEdit_reg_preset,6,1);

    ptLabel_reg_vc_start = new QLabel("reg_vc_start:");
    ptEdit_reg_vc_start  = new QLineEdit("5471d19c");
    layoutGrid->addWidget(ptLabel_reg_vc_start,7,0);layoutGrid->addWidget(ptEdit_reg_vc_start,7,1);

//    ptPBtn = new QPushButton("确定");
//    layoutGrid->addWidget(ptPBtn,8,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

//    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

    setLayout(mainLayout);

}

void IspCminputport::step1()
{
    writeLine(E_ACTION_WR,"isp_common.input_port.reg_preset","00104002");
    writeLine(E_ACTION_RR,"isp_common.input_port.reg_preset");

    writeLine(E_ACTION_WR,"isp_common.input_port.reg_preset","0010c002");
    writeLine(E_ACTION_RR,"isp_common.input_port.reg_preset");

    writeLine(E_ACTION_WR,"isp_common.input_port.reg_preset",ptEdit_reg_preset->text());
    writeLine(E_ACTION_RR,"isp_common.input_port.reg_preset");

    writeLine(E_ACTION_WR,"isp_common.input_port.reg_hc_limit",ptEdit_reg_hc_limit->text());
    writeLine(E_ACTION_RR,"isp_common.input_port.reg_hc_limit");

    writeLine(E_ACTION_WR,"isp_common.input_port.reg_hc_size0","0000d5cb");
    writeLine(E_ACTION_RR,"isp_common.input_port.reg_hc_size0");

    writeLine(E_ACTION_WR,"isp_common.input_port.reg_hc_size0",ptEdit_reg_hc_size0->text());
    writeLine(E_ACTION_RR,"isp_common.input_port.reg_hc_size0");

    writeLine(E_ACTION_WR,"isp_common.input_port.reg_hc_size1",ptEdit_reg_hc_size1->text());
    writeLine(E_ACTION_RR,"isp_common.input_port.reg_hc_size1");

    writeLine(E_ACTION_WR,"isp_common.input_port.reg_vc_start","0000d19c");
    writeLine(E_ACTION_RR,"isp_common.input_port.reg_vc_start");

    writeLine(E_ACTION_WR,"isp_common.input_port.reg_vc_start",ptEdit_reg_vc_start->text());
    writeLine(E_ACTION_RR,"isp_common.input_port.reg_vc_start");

    writeLine(E_ACTION_WR,"isp_common.input_port.reg_mode_request",ptEdit_reg_mode_request->text());
    writeLine(E_ACTION_RR,"isp_common.input_port.reg_mode_request");

    writeLine(E_ACTION_WR,"isp_common.input_port_frame_stats.stats_reset",ptEdit_FrStatusReset->text());
    writeLine(E_ACTION_RR,"isp_common.input_port_frame_stats.stats_reset");

    writeLine(E_ACTION_WR,"isp_common.input_port_frame_stats.stats_hold", ptEdit_FrStatusHold->text());
    writeLine(E_ACTION_RR,"isp_common.input_port_frame_stats.stats_hold");
}

void IspCminputport::clickedSlot(bool checked)
{
    if(checked)
        return;
    str_FrStatusReset = ptEdit_FrStatusReset->text();
    str_FrStatusHold = ptEdit_FrStatusHold->text();
    strt_reg_hc_limit = ptEdit_reg_hc_limit->text();
    str_reg_hc_size0 = ptEdit_reg_hc_size0->text();
    str_reg_hc_size1 = ptEdit_reg_hc_size1->text();
    str_reg_mode_request = ptEdit_reg_mode_request->text();
    str_reg_preset = ptEdit_reg_preset->text();
    str_reg_vc_start = ptEdit_reg_vc_start->text();

    return;
}
