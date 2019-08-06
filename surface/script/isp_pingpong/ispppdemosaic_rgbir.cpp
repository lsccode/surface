#include "ispppdemosaic_rgbir.h"
#include <QGridLayout>
IspPPdemosaic_rgbir::IspPPdemosaic_rgbir(QWidget *parent) :
    QWidget(parent)
{
    init_array();

    QGridLayout *layoutGrid = new QGridLayout;

    ptLabel_clip_debloom  = new QLabel("clip_debloom :");
    ptEdit_clip_debloom  = new QLineEdit("000006c1");
    layoutGrid->addWidget(ptLabel_clip_debloom ,0,0);layoutGrid->addWidget(ptEdit_clip_debloom ,0,1);

    ptLabel_clip_level  = new QLabel("clip_level :");
    ptEdit_clip_level  = new QLineEdit("00000b5f");
    layoutGrid->addWidget(ptLabel_clip_level ,1,0);layoutGrid->addWidget(ptEdit_clip_level ,1,1);

    ptLabel_fc_grad  = new QLabel("fc_grad :");
    ptEdit_fc_grad  = new QLineEdit("00000d05");
    layoutGrid->addWidget(ptLabel_fc_grad ,2,0);layoutGrid->addWidget(ptEdit_fc_grad ,2,1);

    ptLabel_fc_low  = new QLabel("fc_low :");
    ptEdit_fc_low  = new QLineEdit("000006f7");
    layoutGrid->addWidget(ptLabel_fc_low ,3,0);layoutGrid->addWidget(ptEdit_fc_low ,3,1);

    ptLabel_interpolation_directionality  = new QLabel("interpolation_directionality :");
    ptEdit_interpolation_directionality  = new QLineEdit("00000080");
    layoutGrid->addWidget(ptLabel_interpolation_directionality ,4,0);layoutGrid->addWidget(ptEdit_interpolation_directionality ,4,1);

    ptLabel_reg_gain_r  = new QLabel("reg_gain_r :");
    ptEdit_reg_gain_r  = new QLineEdit("0dfa0f87");
    layoutGrid->addWidget(ptLabel_reg_gain_r ,5,0);layoutGrid->addWidget(ptEdit_reg_gain_r ,5,1);

    ptLabel_reg_ir_correct_mat00  = new QLabel("reg_ir_correct_mat00 :");
    ptEdit_reg_ir_correct_mat00  = new QLineEdit("0c2d0787");
    layoutGrid->addWidget(ptLabel_reg_ir_correct_mat00 ,6,0);layoutGrid->addWidget(ptEdit_reg_ir_correct_mat00 ,6,1);

    ptLabel_reg_ir_correct_mat02  = new QLabel("reg_ir_correct_mat02 :");
    ptEdit_reg_ir_correct_mat02  = new QLineEdit("0fe9065c");
    layoutGrid->addWidget(ptLabel_reg_ir_correct_mat02 ,7,0);layoutGrid->addWidget(ptEdit_reg_ir_correct_mat02 ,7,1);

    ptLabel_reg_ir_correct_mat10  = new QLabel("reg_ir_correct_mat10 :");
    ptEdit_reg_ir_correct_mat10  = new QLineEdit("08a80e4a");
    layoutGrid->addWidget(ptLabel_reg_ir_correct_mat10 ,8,0);layoutGrid->addWidget(ptEdit_reg_ir_correct_mat10 ,8,1);

    ptLabel_reg_ir_correct_mat12  = new QLabel("reg_ir_correct_mat12 :");
    ptEdit_reg_ir_correct_mat12  = new QLineEdit("0685039c");
    layoutGrid->addWidget(ptLabel_reg_ir_correct_mat12 ,9,0);layoutGrid->addWidget(ptEdit_reg_ir_correct_mat12 ,9,1);

    ptLabel_reg_ir_correct_mat20  = new QLabel("reg_ir_correct_mat20 :");
    ptEdit_reg_ir_correct_mat20  = new QLineEdit("03b60186");
    layoutGrid->addWidget(ptLabel_reg_ir_correct_mat20 ,10,0);layoutGrid->addWidget(ptEdit_reg_ir_correct_mat20 ,10,1);

    ptLabel_reg_ir_correct_mat22  = new QLabel("reg_ir_correct_mat22 :");
    ptEdit_reg_ir_correct_mat22  = new QLineEdit("01580fa2");
    layoutGrid->addWidget(ptLabel_reg_ir_correct_mat22 ,11,0);layoutGrid->addWidget(ptEdit_reg_ir_correct_mat22 ,11,1);

    ptLabel_reg_ir_correct_mat30  = new QLabel("reg_ir_correct_mat30 :");
    ptEdit_reg_ir_correct_mat30  = new QLineEdit("0c060ca9");
    layoutGrid->addWidget(ptLabel_reg_ir_correct_mat30 ,12,0);layoutGrid->addWidget(ptEdit_reg_ir_correct_mat30 ,12,1);

    ptLabel_reg_ir_correct_mat32  = new QLabel("reg_ir_correct_mat32 :");
    ptEdit_reg_ir_correct_mat32  = new QLineEdit("001a0ab6");
    layoutGrid->addWidget(ptLabel_reg_ir_correct_mat32 ,13,0);layoutGrid->addWidget(ptEdit_reg_ir_correct_mat32 ,13,1);

    ptLabel_reg_static_gain_r  = new QLabel("reg_static_gain_r :");
    ptEdit_reg_static_gain_r  = new QLineEdit("001700f0");
    layoutGrid->addWidget(ptLabel_reg_static_gain_r ,14,0);layoutGrid->addWidget(ptEdit_reg_static_gain_r ,14,1);

    ptLabel_rgbir_config  = new QLabel("rgbir_config :");
    ptEdit_rgbir_config  = new QLineEdit("00000002");
    layoutGrid->addWidget(ptLabel_rgbir_config ,15,0);layoutGrid->addWidget(ptEdit_rgbir_config ,15,1);

    ptLabel_sharp_high  = new QLabel("sharp_high :");
    ptEdit_sharp_high  = new QLineEdit("00000cf8");
    layoutGrid->addWidget(ptLabel_sharp_high ,16,0);layoutGrid->addWidget(ptEdit_sharp_high ,16,1);

    ptLabel_sharp_limit  = new QLabel("sharp_limit :");
    ptEdit_sharp_limit  = new QLineEdit("00000f0d");
    layoutGrid->addWidget(ptLabel_sharp_limit ,17,0);layoutGrid->addWidget(ptEdit_sharp_limit ,17,1);

    ptLabel_sharp_low  = new QLabel("sharp_low :");
    ptEdit_sharp_low  = new QLineEdit("0000011b");
    layoutGrid->addWidget(ptLabel_sharp_low ,18,0);layoutGrid->addWidget(ptEdit_sharp_low ,18,1);

    ptLabel_static_gain_i  = new QLabel("static_gain_i :");
    ptEdit_static_gain_i  = new QLineEdit("000007d0");
    layoutGrid->addWidget(ptLabel_static_gain_i ,19,0);layoutGrid->addWidget(ptEdit_static_gain_i ,19,1);

    ptLabel_weight_lut  = new QLabel("weight_lut :");
    ptEdit_weight_lut  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_weight_lut ,20,0);layoutGrid->addWidget(ptEdit_weight_lut ,20,1);

    ptCb_demosaic_rgb_noise_profile_weight_lut  = new QComboBox;
    ptEdit_demosaic_rgb_noise_profile_weight_lut = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_demosaic_rgb_noise_profile_weight_lut,21,0);layoutGrid->addWidget(ptEdit_demosaic_rgb_noise_profile_weight_lut,21,1);
    for(unsigned int i = 0;i < M_DEMOSAIC_RGB_NOISE_PROFILE_WEIGHT_LUT_NUMBER; ++i)
    {
        QString str;
        str.sprintf("demosaic_rgb_noise_profile_weight_lut[%x]",i);
        ptCb_demosaic_rgb_noise_profile_weight_lut->addItem(str);
//        szQStr_demosaic_rgb_noise_profile_weight_lut[i].sprintf("%x",i);
    }
    ptEdit_demosaic_rgb_noise_profile_weight_lut->setText(szQStr_demosaic_rgb_noise_profile_weight_lut[ptCb_demosaic_rgb_noise_profile_weight_lut->currentIndex()]);
    //    ptPBtn = new QPushButton("确定");
    //    layoutGrid->addWidget(ptPBtn,21,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

    //   connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));
    connect(ptCb_demosaic_rgb_noise_profile_weight_lut,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_demosaic_rgb_noise_profile_weight_lut(int)));
    connect(ptEdit_demosaic_rgb_noise_profile_weight_lut,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_demosaic_rgb_noise_profile_weight_lut(const QString)));
    setLayout(mainLayout);
}

void IspPPdemosaic_rgbir::init_array()
{
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x7c] = "0000009a";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x7d] = "0000007d";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x7e] = "0000000f";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x7f] = "00000069";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x78] = "000000ba";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x79] = "00000070";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x7a] = "000000a6";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x7b] = "00000010";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x74] = "0000001b";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x75] = "00000032";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x76] = "000000b7";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x77] = "000000ae";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x70] = "00000010";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x71] = "0000004d";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x72] = "00000065";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x73] = "000000e5";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x6c] = "000000fe";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x6d] = "000000e1";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x6e] = "000000cc";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x6f] = "000000ad";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x68] = "000000d7";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x69] = "000000de";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x6a] = "000000bf";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x6b] = "0000004e";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x64] = "00000080";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x65] = "00000044";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x66] = "00000023";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x67] = "00000036";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x60] = "000000ca";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x61] = "00000097";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x62] = "000000a9";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x63] = "000000bb";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x5c] = "00000008";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x5d] = "0000003e";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x5e] = "00000014";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x5f] = "0000000c";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x58] = "00000046";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x59] = "00000010";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x5a] = "00000069";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x5b] = "0000001c";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x54] = "0000005a";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x55] = "00000037";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x56] = "000000e7";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x57] = "000000c0";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x50] = "0000004b";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x51] = "0000003b";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x52] = "000000c7";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x53] = "00000084";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x4c] = "000000e2";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x4d] = "000000d0";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x4e] = "00000079";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x4f] = "00000034";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x48] = "00000051";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x49] = "0000009a";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x4a] = "00000093";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x4b] = "000000d4";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x44] = "0000005c";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x45] = "00000066";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x46] = "000000d8";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x47] = "000000a4";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x40] = "000000b8";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x41] = "00000027";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x42] = "0000006f";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x43] = "00000078";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x3c] = "0000004c";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x3d] = "00000035";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x3e] = "000000c0";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x3f] = "0000006d";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x38] = "00000066";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x39] = "00000097";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x3a] = "000000db";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x3b] = "000000e7";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x34] = "00000020";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x35] = "0000002b";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x36] = "00000065";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x37] = "000000ec";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x30] = "0000001c";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x31] = "000000b8";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x32] = "00000033";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x33] = "00000016";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x2c] = "000000b3";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x2d] = "00000003";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x2e] = "0000008e";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x2f] = "0000006a";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x28] = "000000e6";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x29] = "00000095";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x2a] = "000000a6";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x2b] = "000000a0";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x24] = "0000005e";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x25] = "0000005a";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x26] = "00000051";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x27] = "00000079";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x20] = "00000017";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x21] = "00000026";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x22] = "00000000";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x23] = "000000b0";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x1c] = "00000088";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x1d] = "000000c7";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x1e] = "00000068";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x1f] = "000000d4";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x18] = "0000006f";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x19] = "0000008f";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x1a] = "00000045";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x1b] = "0000006c";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x14] = "000000dc";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x15] = "000000bc";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x16] = "0000008c";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x17] = "0000004a";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x10] = "00000053";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x11] = "00000010";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x12] = "000000cf";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x13] = "00000008";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0xc] = "00000044";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0xd] = "000000f4";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0xe] = "000000dc";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0xf] = "000000a8";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x8] = "00000007";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x9] = "000000de";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0xa] = "000000b2";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0xb] = "000000a6";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x4] = "0000007f";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x5] = "00000097";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x6] = "000000f4";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x7] = "000000ce";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x0] = "000000ca";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x1] = "000000f1";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x2] = "00000049";
    szQStr_demosaic_rgb_noise_profile_weight_lut[0x3] = "00000009";
}

void IspPPdemosaic_rgbir::step1()
{
    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.rgbir_config",ptEdit_rgbir_config->text());
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.rgbir_config");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.clip_level",ptEdit_clip_level->text());
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.clip_level");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.clip_debloom",ptEdit_clip_debloom->text());
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.clip_debloom");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.reg_gain_r","01000f87");
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.reg_gain_r");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.reg_gain_r",ptEdit_reg_gain_r->text());
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.reg_gain_r");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.reg_static_gain_r","010000f0");
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.reg_static_gain_r");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.reg_static_gain_r",ptEdit_reg_static_gain_r->text());
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.reg_static_gain_r");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.static_gain_i",ptEdit_static_gain_i->text());
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.static_gain_i");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.interpolation_directionality",ptEdit_interpolation_directionality->text());
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.interpolation_directionality");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.sharp_limit",ptEdit_sharp_limit->text());
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.sharp_limit");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.sharp_high",ptEdit_sharp_high->text());
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.sharp_high");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.sharp_low",ptEdit_sharp_low->text());
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.sharp_low");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.fc_low",ptEdit_fc_low->text());
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.fc_low");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.fc_grad",ptEdit_fc_grad->text());
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.fc_grad");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat00","00000787");
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat00");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat00",ptEdit_reg_ir_correct_mat00->text());
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat00");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat02","0000065c");
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat02");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat02",ptEdit_reg_ir_correct_mat02->text());
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat02");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat10","04000e4a");
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat10");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat10",ptEdit_reg_ir_correct_mat10->text());
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat10");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat12","0000039c");
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat12");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat12",ptEdit_reg_ir_correct_mat12->text());
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat12");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat20","00000186");
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat20");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat20",ptEdit_reg_ir_correct_mat20->text());
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat20");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat22","00000fa2");
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat22");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat22",ptEdit_reg_ir_correct_mat22->text());
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat22");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat30","00000ca9");
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat30");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat30",ptEdit_reg_ir_correct_mat30->text());
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat30");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat32","04000ab6");
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat32");

    writeLine(E_ACTION_WR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat32",ptEdit_reg_ir_correct_mat32->text());
    writeLine(E_ACTION_RR,"isp_config_ping.demosaic_rgbir.reg_ir_correct_mat32");

    for(int i = M_DEMOSAIC_RGB_NOISE_PROFILE_WEIGHT_LUT_NUMBER - 1; i >0; i-=4)
    {
        for(int j = 3; j >=0; j--)
        {
            QString strLine;
            strLine.sprintf("isp_config_ping.demosaic_rgb_noise_profile.weight_lut[%x]",i-j);

            writeLine(E_ACTION_WR,strLine,szQStr_demosaic_rgb_noise_profile_weight_lut[i-j]);
            writeLine(E_ACTION_RR,strLine);
        }
    }
}

void IspPPdemosaic_rgbir::clickedSlot(bool checked)
{
    QString str_clip_debloom = ptEdit_clip_debloom->text();
    QString str_clip_level = ptEdit_clip_level->text();
    QString str_fc_grad = ptEdit_fc_grad->text();
    QString str_fc_low = ptEdit_fc_low->text();
    QString str_interpolation_directionality = ptEdit_interpolation_directionality->text();
    QString str_reg_gain_r = ptEdit_reg_gain_r->text();
    QString str_reg_ir_correct_mat00 = ptEdit_reg_ir_correct_mat00->text();
    QString str_reg_ir_correct_mat02 = ptEdit_reg_ir_correct_mat02->text();
    QString str_reg_ir_correct_mat10 = ptEdit_reg_ir_correct_mat10->text();
    QString str_reg_ir_correct_mat12 = ptEdit_reg_ir_correct_mat12->text();
    QString str_reg_ir_correct_mat20 = ptEdit_reg_ir_correct_mat20->text();
    QString str_reg_ir_correct_mat22 = ptEdit_reg_ir_correct_mat22->text();
    QString str_reg_ir_correct_mat30 = ptEdit_reg_ir_correct_mat30->text();
    QString str_reg_ir_correct_mat32 = ptEdit_reg_ir_correct_mat32->text();
    QString str_reg_static_gain_r = ptEdit_reg_static_gain_r->text();
    QString str_rgbir_config = ptEdit_rgbir_config->text();
    QString str_sharp_high = ptEdit_sharp_high->text();
    QString str_sharp_limit = ptEdit_sharp_limit->text();
    QString str_sharp_low = ptEdit_sharp_low->text();
    QString str_static_gain_i = ptEdit_static_gain_i->text();
    QString str_weight_lut = ptEdit_weight_lut->text();
}

void IspPPdemosaic_rgbir::activatedSlot_demosaic_rgb_noise_profile_weight_lut(int index)
{
    ptEdit_demosaic_rgb_noise_profile_weight_lut->setText(szQStr_demosaic_rgb_noise_profile_weight_lut[index]);
}

void IspPPdemosaic_rgbir::textChangedSlot_demosaic_rgb_noise_profile_weight_lut(const QString &text)
{
    int index = ptCb_demosaic_rgb_noise_profile_weight_lut->currentIndex();
    szQStr_demosaic_rgb_noise_profile_weight_lut[index] = text;
}
