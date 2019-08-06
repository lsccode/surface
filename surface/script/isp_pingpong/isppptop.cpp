#include "isppptop.h"
#include <QGridLayout>
IspPPtop::IspPPtop(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    // add edit
    ptLabel_reg_active_width  = new QLabel("reg_active_width :");
    ptEdit_reg_active_width  = new QLineEdit("00800080");
    layoutGrid->addWidget(ptLabel_reg_active_width ,0,0);layoutGrid->addWidget(ptEdit_reg_active_width ,0,1);

    ptLabel_reg_ae_5bin_hist_disable  = new QLabel("reg_ae_5bin_hist_disable :");
    ptEdit_reg_ae_5bin_hist_disable  = new QLineEdit("01004004");
    layoutGrid->addWidget(ptLabel_reg_ae_5bin_hist_disable ,1,0);layoutGrid->addWidget(ptEdit_reg_ae_5bin_hist_disable ,1,1);

    ptLabel_reg_bypass_digital_gain  = new QLabel("reg_bypass_digital_gain :");
    ptEdit_reg_bypass_digital_gain  = new QLineEdit("00000000");
    layoutGrid->addWidget(ptLabel_reg_bypass_digital_gain ,2,0);layoutGrid->addWidget(ptEdit_reg_bypass_digital_gain ,2,1);

    ptLabel_reg_bypass_ds_crop  = new QLabel("reg_bypass_ds_crop :");
    ptEdit_reg_bypass_ds_crop  = new QLineEdit("00000003");
    layoutGrid->addWidget(ptLabel_reg_bypass_ds_crop ,3,0);layoutGrid->addWidget(ptEdit_reg_bypass_ds_crop ,3,1);

    ptLabel_reg_bypass_fr_crop  = new QLabel("reg_bypass_fr_crop :");
    ptEdit_reg_bypass_fr_crop  = new QLineEdit("00000001");
    layoutGrid->addWidget(ptLabel_reg_bypass_fr_crop ,4,0);layoutGrid->addWidget(ptEdit_reg_bypass_fr_crop ,4,1);

    ptLabel_reg_bypass_sinter  = new QLabel("reg_bypass_sinter :");
    ptEdit_reg_bypass_sinter  = new QLineEdit("00000000");
    layoutGrid->addWidget(ptLabel_reg_bypass_sinter ,5,0);layoutGrid->addWidget(ptEdit_reg_bypass_sinter ,5,1);

    ptLabel_reg_bypass_square_be  = new QLabel("reg_bypass_square_be :");
    ptEdit_reg_bypass_square_be  = new QLineEdit("00000060");
    layoutGrid->addWidget(ptLabel_reg_bypass_square_be ,6,0);layoutGrid->addWidget(ptEdit_reg_bypass_square_be ,6,1);

    ptLabel_reg_bypass_video_test_gen  = new QLabel("reg_bypass_video_test_gen :");
    ptEdit_reg_bypass_video_test_gen  = new QLineEdit("00000019");
    layoutGrid->addWidget(ptLabel_reg_bypass_video_test_gen ,7,0);layoutGrid->addWidget(ptEdit_reg_bypass_video_test_gen ,7,1);

    ptLabel_reg_rggb_start_pre_mirror  = new QLabel("reg_rggb_start_pre_mirror :");
    ptEdit_reg_rggb_start_pre_mirror  = new QLineEdit("02000001");
    layoutGrid->addWidget(ptLabel_reg_rggb_start_pre_mirror ,8,0);layoutGrid->addWidget(ptEdit_reg_rggb_start_pre_mirror ,8,1);

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

void IspPPtop::step1()
{
    writeLine(E_ACTION_WR,"isp_config_ping.top.reg_active_width","04380080");
    writeLine(E_ACTION_RR,"isp_config_ping.top.reg_active_width");

    writeLine(E_ACTION_WR,"isp_config_ping.top.reg_active_width",ptEdit_reg_active_width->text());
    writeLine(E_ACTION_RR,"isp_config_ping.top.reg_active_width");

    writeLine(E_ACTION_WR,"isp_config_ping.top.reg_rggb_start_pre_mirror","00000001");
    writeLine(E_ACTION_RR,"isp_config_ping.top.reg_rggb_start_pre_mirror");

    writeLine(E_ACTION_WR,"isp_config_ping.top.reg_rggb_start_pre_mirror",ptEdit_reg_rggb_start_pre_mirror->text());
    writeLine(E_ACTION_RR,"isp_config_ping.top.reg_rggb_start_pre_mirror");

    writeLine(E_ACTION_WR,"isp_config_ping.top.reg_bypass_video_test_gen","00000001");
    writeLine(E_ACTION_RR,"isp_config_ping.top.reg_bypass_video_test_gen");

    writeLine(E_ACTION_WR,"isp_config_ping.top.reg_bypass_video_test_gen","00000009");
    writeLine(E_ACTION_RR,"isp_config_ping.top.reg_bypass_video_test_gen");

    writeLine(E_ACTION_WR,"isp_config_ping.top.reg_bypass_video_test_gen",ptEdit_reg_bypass_video_test_gen->text());
    writeLine(E_ACTION_RR,"isp_config_ping.top.reg_bypass_video_test_gen");

    writeLine(E_ACTION_WR,"isp_config_ping.top.reg_bypass_digital_gain",ptEdit_reg_bypass_digital_gain->text());
    writeLine(E_ACTION_RR,"isp_config_ping.top.reg_bypass_digital_gain");

    writeLine(E_ACTION_WR,"isp_config_ping.top.reg_bypass_sinter",ptEdit_reg_bypass_sinter->text());
    writeLine(E_ACTION_RR,"isp_config_ping.top.reg_bypass_sinter");

    writeLine(E_ACTION_WR,"isp_config_ping.top.reg_bypass_square_be","00000020");
    writeLine(E_ACTION_RR,"isp_config_ping.top.reg_bypass_square_be");

    writeLine(E_ACTION_WR,"isp_config_ping.top.reg_bypass_square_be",ptEdit_reg_bypass_square_be->text());
    writeLine(E_ACTION_RR,"isp_config_ping.top.reg_bypass_square_be");

    writeLine(E_ACTION_WR,"isp_config_ping.top.reg_bypass_fr_crop",ptEdit_reg_bypass_fr_crop->text());
    writeLine(E_ACTION_RR,"isp_config_ping.top.reg_bypass_fr_crop");

    writeLine(E_ACTION_WR,"isp_config_ping.top.reg_bypass_ds_crop","00000001");
    writeLine(E_ACTION_RR,"isp_config_ping.top.reg_bypass_ds_crop");

    writeLine(E_ACTION_WR,"isp_config_ping.top.reg_bypass_ds_crop",ptEdit_reg_bypass_ds_crop->text());
    writeLine(E_ACTION_RR,"isp_config_ping.top.reg_bypass_ds_crop");

    writeLine(E_ACTION_WR,"isp_config_ping.top.reg_ae_5bin_hist_disable","00010004");
    writeLine(E_ACTION_RR,"isp_config_ping.top.reg_ae_5bin_hist_disable");

    writeLine(E_ACTION_WR,"isp_config_ping.top.reg_ae_5bin_hist_disable","00014004");
    writeLine(E_ACTION_RR,"isp_config_ping.top.reg_ae_5bin_hist_disable");

    writeLine(E_ACTION_WR,"isp_config_ping.top.reg_ae_5bin_hist_disable","00004004");
    writeLine(E_ACTION_RR,"isp_config_ping.top.reg_ae_5bin_hist_disable");

    writeLine(E_ACTION_WR,"isp_config_ping.top.reg_ae_5bin_hist_disable",ptEdit_reg_ae_5bin_hist_disable->text());
    writeLine(E_ACTION_RR,"isp_config_ping.top.reg_ae_5bin_hist_disable");
}

void IspPPtop::clickedSlot(bool checked)
{
    QString str_reg_active_width = ptEdit_reg_active_width->text();
    QString str_reg_ae_5bin_hist_disable = ptEdit_reg_ae_5bin_hist_disable->text();
    QString str_reg_bypass_digital_gain = ptEdit_reg_bypass_digital_gain->text();
    QString str_reg_bypass_ds_crop = ptEdit_reg_bypass_ds_crop->text();
    QString str_reg_bypass_fr_crop = ptEdit_reg_bypass_fr_crop->text();
    QString str_reg_bypass_sinter = ptEdit_reg_bypass_sinter->text();
    QString str_reg_bypass_square_be = ptEdit_reg_bypass_square_be->text();
    QString str_reg_bypass_video_test_gen = ptEdit_reg_bypass_video_test_gen->text();
    QString str_reg_rggb_start_pre_mirror = ptEdit_reg_rggb_start_pre_mirror->text();
}
