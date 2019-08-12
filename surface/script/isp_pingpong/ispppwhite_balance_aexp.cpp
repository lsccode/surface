#include "ispppwhite_balance_aexp.h"
#include <QGridLayout>
IspPPwhite_balance_aexp::IspPPwhite_balance_aexp(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    // add edit
    ptLabel_white_balance_aexpreg_gain_00  = new QLabel("white_balance_aexpreg_gain_00 :");
    ptEdit_white_balance_aexpreg_gain_00  = new QLineEdit("012f0170");
    layoutGrid->addWidget(ptLabel_white_balance_aexpreg_gain_00 ,0,0);layoutGrid->addWidget(ptEdit_white_balance_aexpreg_gain_00 ,0,1);

    ptLabel_white_balance_aexpreg_gain_10  = new QLabel("white_balance_aexpreg_gain_10 :");
    ptEdit_white_balance_aexpreg_gain_10  = new QLineEdit("012a01e6");
    layoutGrid->addWidget(ptLabel_white_balance_aexpreg_gain_10 ,1,0);layoutGrid->addWidget(ptEdit_white_balance_aexpreg_gain_10 ,1,1);

    ptLabel_white_balancereg_gain_00  = new QLabel("white_balancereg_gain_00 :");
    ptEdit_white_balancereg_gain_00  = new QLineEdit("01bb0140");
    layoutGrid->addWidget(ptLabel_white_balancereg_gain_00 ,2,0);layoutGrid->addWidget(ptEdit_white_balancereg_gain_00 ,2,1);

    ptLabel_white_balancereg_gain_10  = new QLabel("white_balancereg_gain_10 :");
    ptEdit_white_balancereg_gain_10  = new QLineEdit("00c10033");
    layoutGrid->addWidget(ptLabel_white_balancereg_gain_10 ,3,0);layoutGrid->addWidget(ptEdit_white_balancereg_gain_10 ,3,1);

//    ptPBtn = new QPushButton("确定");
//    layoutGrid->addWidget(ptPBtn,40,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

//    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

    setLayout(mainLayout);
}

void IspPPwhite_balance_aexp::step1()
{
    writeLine(E_ACTION_WR,"isp_config_ping.white_balance.reg_gain_00","01000140");
    writeLine(E_ACTION_RR,"isp_config_ping.white_balance.reg_gain_00");

    writeLine(E_ACTION_WR,"isp_config_ping.white_balance.reg_gain_00",ptEdit_white_balancereg_gain_00->text());
    writeLine(E_ACTION_RR,"isp_config_ping.white_balance.reg_gain_00");

    writeLine(E_ACTION_WR,"isp_config_ping.white_balance.reg_gain_10","01000033");
    writeLine(E_ACTION_RR,"isp_config_ping.white_balance.reg_gain_10");

    writeLine(E_ACTION_WR,"isp_config_ping.white_balance.reg_gain_10",ptEdit_white_balancereg_gain_10->text());
    writeLine(E_ACTION_RR,"isp_config_ping.white_balance.reg_gain_10");

    writeLine(E_ACTION_WR,"isp_config_ping.white_balance_aexp.reg_gain_00","01000170");
    writeLine(E_ACTION_RR,"isp_config_ping.white_balance_aexp.reg_gain_00");

    writeLine(E_ACTION_WR,"isp_config_ping.white_balance_aexp.reg_gain_00",ptEdit_white_balance_aexpreg_gain_00->text());
    writeLine(E_ACTION_RR,"isp_config_ping.white_balance_aexp.reg_gain_00");

    writeLine(E_ACTION_WR,"isp_config_ping.white_balance_aexp.reg_gain_10","010001e6");
    writeLine(E_ACTION_RR,"isp_config_ping.white_balance_aexp.reg_gain_10");

    writeLine(E_ACTION_WR,"isp_config_ping.white_balance_aexp.reg_gain_10",ptEdit_white_balance_aexpreg_gain_10->text());
    writeLine(E_ACTION_RR,"isp_config_ping.white_balance_aexp.reg_gain_10");
}

void IspPPwhite_balance_aexp::clickedSlot(bool checked)
{
    if(checked)
        return;
    QString str_white_balance_aexpreg_gain_00 = ptEdit_white_balance_aexpreg_gain_00->text();
    QString str_white_balance_aexpreg_gain_10 = ptEdit_white_balance_aexpreg_gain_10->text();
    QString str_white_balancereg_gain_00 = ptEdit_white_balancereg_gain_00->text();
    QString str_white_balancereg_gain_10 = ptEdit_white_balancereg_gain_10->text();
}
