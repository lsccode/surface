#include "ispppmisc.h"
#include <QGridLayout>
IspPPmisc::IspPPmisc(QWidget *parent) :
    QWidget(parent)
{
    init_array();

    QGridLayout *layoutGrid = new QGridLayout;

    // add edit
    ptLabel_sqrtblack_level_in  = new QLabel("sqrtblack_level_in :");
    ptEdit_sqrtblack_level_in  = new QLineEdit("000037cb");
    layoutGrid->addWidget(ptLabel_sqrtblack_level_in ,0,0);layoutGrid->addWidget(ptEdit_sqrtblack_level_in ,0,1);

    ptLabel_sqrtblack_level_out  = new QLabel("sqrtblack_level_out :");
    ptEdit_sqrtblack_level_out  = new QLineEdit("0000038a");
    layoutGrid->addWidget(ptLabel_sqrtblack_level_out ,1,0);layoutGrid->addWidget(ptEdit_sqrtblack_level_out ,1,1);

    ptLabel_square_beblack_level_in  = new QLabel("square_beblack_level_in :");
    ptEdit_square_beblack_level_in  = new QLineEdit("000003a5");
    layoutGrid->addWidget(ptLabel_square_beblack_level_in ,2,0);layoutGrid->addWidget(ptEdit_square_beblack_level_in ,2,1);

    ptLabel_square_beblack_level_out  = new QLabel("square_beblack_level_out :");
    ptEdit_square_beblack_level_out  = new QLineEdit("00003076");
    layoutGrid->addWidget(ptLabel_square_beblack_level_out ,3,0);layoutGrid->addWidget(ptEdit_square_beblack_level_out ,3,1);

    ptLabel_lumvar_reg_active_width  = new QLabel("lumvar_reg_active_width :");
    ptEdit_lumvar_reg_active_width  = new QLineEdit("00800080");
    layoutGrid->addWidget(ptLabel_lumvar_reg_active_width ,4,0);layoutGrid->addWidget(ptEdit_lumvar_reg_active_width ,4,1);

    ptLabel_defect_pixel_defect_pixel_count_in  = new QLabel("defect_pixel_defect_pixel_count_in :");
    ptEdit_defect_pixel_defect_pixel_count_in  = new QLineEdit("00000344");
    layoutGrid->addWidget(ptLabel_defect_pixel_defect_pixel_count_in ,5,0);layoutGrid->addWidget(ptEdit_defect_pixel_defect_pixel_count_in ,5,1);

    ptCb_nonequ_gamma_srgb_lut_coeff_lut  = new QComboBox;
    ptEdit_nonequ_gamma_srgb_lut_coeff_lut = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_nonequ_gamma_srgb_lut_coeff_lut,7,0);layoutGrid->addWidget(ptEdit_nonequ_gamma_srgb_lut_coeff_lut,7,1);
    for(unsigned int i = 0;i < M_NONEQU_GAMMA_SRGB_LUT_COEFF_LUT_NUMBER; ++i)
    {
        QString str;
        str.sprintf("nonequ_gamma_srgb_lut_coeff_lut[%x]",i);
        ptCb_nonequ_gamma_srgb_lut_coeff_lut->addItem(str);
//        szQStr_nonequ_gamma_srgb_lut_coeff_lut[i].sprintf("%x",i);
    }
    ptEdit_nonequ_gamma_srgb_lut_coeff_lut->setText(szQStr_nonequ_gamma_srgb_lut_coeff_lut[ptCb_nonequ_gamma_srgb_lut_coeff_lut->currentIndex()]);

    ptCb_pf_correction_shading_shading_lut  = new QComboBox;
    ptEdit_pf_correction_shading_shading_lut = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_pf_correction_shading_shading_lut,8,0);layoutGrid->addWidget(ptEdit_pf_correction_shading_shading_lut,8,1);
    for(unsigned int i = 0;i < M_PF_CORRECTION_SHADING_SHADING_LUT_NUMBER; ++i)
    {
        QString str;
        str.sprintf("pf_correction_shading_shading_lut[%x]",i);
        ptCb_pf_correction_shading_shading_lut->addItem(str);
//        szQStr_pf_correction_shading_shading_lut[i].sprintf("%x",i);
    }
    ptEdit_pf_correction_shading_shading_lut->setText(szQStr_pf_correction_shading_shading_lut[ptCb_pf_correction_shading_shading_lut->currentIndex()]);


    ptCb_lumvar_stats_ping_mem  = new QComboBox;
    ptEdit_lumvar_stats_ping_mem = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_lumvar_stats_ping_mem,6,0);layoutGrid->addWidget(ptEdit_lumvar_stats_ping_mem,6,1);
    for(unsigned int i = 0;i < M_LUMVAR_STATS_PING_MEM_NUMBER; ++i)
    {
        QString str;
        str.sprintf("lumvar_stats_ping_mem[%x]",i);
        ptCb_lumvar_stats_ping_mem->addItem(str);
        szQStr_lumvar_stats_ping_mem[i].sprintf("%x",0);
    }
    ptEdit_lumvar_stats_ping_mem->setText(szQStr_lumvar_stats_ping_mem[ptCb_lumvar_stats_ping_mem->currentIndex()]);

//    ptPBtn = new QPushButton("确定");
//    layoutGrid->addWidget(ptPBtn,40,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

//    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));
    connect(ptCb_nonequ_gamma_srgb_lut_coeff_lut,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_nonequ_gamma_srgb_lut_coeff_lut(int)));
    connect(ptEdit_nonequ_gamma_srgb_lut_coeff_lut,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_nonequ_gamma_srgb_lut_coeff_lut(const QString)));
    setLayout(mainLayout);
    connect(ptCb_pf_correction_shading_shading_lut,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_pf_correction_shading_shading_lut(int)));
    connect(ptEdit_pf_correction_shading_shading_lut,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_pf_correction_shading_shading_lut(const QString)));

    connect(ptCb_lumvar_stats_ping_mem,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_lumvar_stats_ping_mem(int)));
    connect(ptEdit_lumvar_stats_ping_mem,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_lumvar_stats_ping_mem(const QString)));
}

void IspPPmisc::init_array()
{
    init_pf_correction_shading_shading_lut();
    init_nonequ_gamma_srgb_lut_coeff_lut();
}

void IspPPmisc::init_pf_correction_shading_shading_lut()
{
    szQStr_pf_correction_shading_shading_lut[0x0] = "00000002";
    szQStr_pf_correction_shading_shading_lut[0x1] = "000000bb";
    szQStr_pf_correction_shading_shading_lut[0x2] = "0000007d";
    szQStr_pf_correction_shading_shading_lut[0x3] = "000000b3";
    szQStr_pf_correction_shading_shading_lut[0x4] = "0000006d";
    szQStr_pf_correction_shading_shading_lut[0x5] = "0000007b";
    szQStr_pf_correction_shading_shading_lut[0x6] = "00000044";
    szQStr_pf_correction_shading_shading_lut[0x7] = "00000099";
    szQStr_pf_correction_shading_shading_lut[0x8] = "000000c0";
    szQStr_pf_correction_shading_shading_lut[0x9] = "000000e9";
    szQStr_pf_correction_shading_shading_lut[0xa] = "0000009c";
    szQStr_pf_correction_shading_shading_lut[0xb] = "000000d9";
    szQStr_pf_correction_shading_shading_lut[0xc] = "00000097";
    szQStr_pf_correction_shading_shading_lut[0xd] = "0000004f";
    szQStr_pf_correction_shading_shading_lut[0xe] = "000000da";
    szQStr_pf_correction_shading_shading_lut[0xf] = "0000009e";
    szQStr_pf_correction_shading_shading_lut[0x10] = "0000001e";
    szQStr_pf_correction_shading_shading_lut[0x11] = "000000c6";
    szQStr_pf_correction_shading_shading_lut[0x12] = "00000070";
    szQStr_pf_correction_shading_shading_lut[0x13] = "00000028";
    szQStr_pf_correction_shading_shading_lut[0x14] = "000000fb";
    szQStr_pf_correction_shading_shading_lut[0x15] = "000000d5";
    szQStr_pf_correction_shading_shading_lut[0x16] = "00000011";
    szQStr_pf_correction_shading_shading_lut[0x17] = "00000066";
    szQStr_pf_correction_shading_shading_lut[0x18] = "00000079";
    szQStr_pf_correction_shading_shading_lut[0x19] = "000000b4";
    szQStr_pf_correction_shading_shading_lut[0x1a] = "00000083";
    szQStr_pf_correction_shading_shading_lut[0x1b] = "000000e2";
    szQStr_pf_correction_shading_shading_lut[0x1c] = "00000061";
    szQStr_pf_correction_shading_shading_lut[0x1d] = "000000c5";
    szQStr_pf_correction_shading_shading_lut[0x1e] = "000000db";
    szQStr_pf_correction_shading_shading_lut[0x1f] = "00000042";
    szQStr_pf_correction_shading_shading_lut[0x20] = "0000003f";
}

void IspPPmisc::init_nonequ_gamma_srgb_lut_coeff_lut()
{
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x0] = "00000000";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x1] = "0000009a";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x2] = "000000e9";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x3] = "0000012b";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x4] = "00000167";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x5] = "0000019f";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x6] = "000001d5";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x7] = "00000208";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x8] = "00000239";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x9] = "00000269";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0xa] = "00000297";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0xb] = "000002c5";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0xc] = "000002f1";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0xd] = "0000031d";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0xe] = "00000347";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0xf] = "00000370";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x10] = "00000397";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x11] = "00000427";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x12] = "000004a8";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x13] = "0000051d";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x14] = "0000058a";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x15] = "0000064f";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x16] = "000006ff";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x17] = "000007a0";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x18] = "00000835";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x19] = "00000943";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x1a] = "00000a35";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x1b] = "00000b11";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x1c] = "00000bdd";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x1d] = "00000d4f";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x1e] = "00000e9a";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x1f] = "00000fc8";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x20] = "000010e0";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x21] = "000012db";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x22] = "000014a1";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x23] = "00001640";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x24] = "000017bf";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x25] = "00001a77";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x26] = "00001ce7";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x27] = "00001f21";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x28] = "00002130";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x29] = "0000231c";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x2a] = "000024ec";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x2b] = "000026a3";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x2c] = "00002845";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x2d] = "000029d4";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x2e] = "00002b54";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x2f] = "00002cc5";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x30] = "00002e28";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x31] = "00002f80";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x32] = "000030cd";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x33] = "00003211";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x34] = "0000334b";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x35] = "0000347d";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x36] = "000035a7";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x37] = "000036ca";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x38] = "000037e6";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x39] = "000038fc";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x3a] = "00003a0b";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x3b] = "00003b16";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x3c] = "00003c1b";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x3d] = "00003d1b";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x3e] = "00003e16";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x3f] = "00003f0d";
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[0x40] = "00003fff";
}

void IspPPmisc::step1()
{
    writeLine(E_ACTION_WR,"isp_config_ping.defect_pixel.defect_pixel_count_in",ptEdit_defect_pixel_defect_pixel_count_in->text());
    writeLine(E_ACTION_RR,"isp_config_ping.defect_pixel.defect_pixel_count_in");
}

void IspPPmisc::step2()
{
    writeLine(E_ACTION_WR,"isp_config_ping.square_be.black_level_in",ptEdit_square_beblack_level_in->text());
    writeLine(E_ACTION_RR,"isp_config_ping.square_be.black_level_in");

    writeLine(E_ACTION_WR,"isp_config_ping.square_be.black_level_out",ptEdit_square_beblack_level_out->text());
    writeLine(E_ACTION_RR,"isp_config_ping.square_be.black_level_out");

}

void IspPPmisc::step3()
{
    writeLine(E_ACTION_WR,"isp_config_ping.lumvar.reg_active_width","04380080");
    writeLine(E_ACTION_RR,"isp_config_ping.lumvar.reg_active_width");

    writeLine(E_ACTION_WR,"isp_config_ping.lumvar.reg_active_width",ptEdit_lumvar_reg_active_width->text());
    writeLine(E_ACTION_RR,"isp_config_ping.lumvar.reg_active_width");
}

void IspPPmisc::step4()
{
    for(unsigned int i = 0;i < M_PF_CORRECTION_SHADING_SHADING_LUT_NUMBER; ++i)
    {
        QString strLine;
        strLine.sprintf("isp_config_ping.pf_correction_shading.shading_lut[%x]",i);

        writeLine(E_ACTION_WR,strLine,szQStr_pf_correction_shading_shading_lut[i]);
        writeLine(E_ACTION_RR,strLine);
    }
}

void IspPPmisc::step5()
{
    for(unsigned int i = 0;i < M_NONEQU_GAMMA_SRGB_LUT_COEFF_LUT_NUMBER; ++i)
    {
        QString strLine;
        strLine.sprintf("isp_config_ping.nonequ_gamma.srgb_lut_coeff_lut[%x]",i);

        writeLine(E_ACTION_WR,strLine,szQStr_nonequ_gamma_srgb_lut_coeff_lut[i]);
        writeLine(E_ACTION_RR,strLine);
        writeLine(E_ACTION_RR,strLine);
    }
}

void IspPPmisc::step6()
{
    writeLine(E_ACTION_WR,"isp_config_ping.sqrt.black_level_in",ptEdit_sqrtblack_level_in->text());
    writeLine(E_ACTION_RR,"isp_config_ping.sqrt.black_level_in");

    writeLine(E_ACTION_WR,"isp_config_ping.sqrt.black_level_out",ptEdit_sqrtblack_level_out->text());
    writeLine(E_ACTION_RR,"isp_config_ping.sqrt.black_level_out");
}

void IspPPmisc::step7()
{
    for(int i = 0; i < M_LUMVAR_STATS_PING_MEM_NUMBER; ++i)
    {
        QString strLine;
        strLine.sprintf("lumvar_stats_ping_mem[%x]",i);
        writeLine(E_ACTION_RR,strLine);
    }
}

void IspPPmisc::clickedSlot(bool checked)
{
    if(checked)
        return;
    QString str_sqrtblack_level_in = ptEdit_sqrtblack_level_in->text();
    QString str_sqrtblack_level_out = ptEdit_sqrtblack_level_out->text();
    QString str_square_beblack_level_in = ptEdit_square_beblack_level_in->text();
    QString str_square_beblack_level_out = ptEdit_square_beblack_level_out->text();
}


void IspPPmisc::activatedSlot_nonequ_gamma_srgb_lut_coeff_lut(int index)
{
    ptEdit_nonequ_gamma_srgb_lut_coeff_lut->setText(szQStr_nonequ_gamma_srgb_lut_coeff_lut[index]);
}

void IspPPmisc::textChangedSlot_nonequ_gamma_srgb_lut_coeff_lut(const QString &text)
{
    int index = ptCb_nonequ_gamma_srgb_lut_coeff_lut->currentIndex();
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[index] = text;
}

void IspPPmisc::activatedSlot_pf_correction_shading_shading_lut(int index)
{
    ptEdit_pf_correction_shading_shading_lut->setText(szQStr_pf_correction_shading_shading_lut[index]);
}

void IspPPmisc::textChangedSlot_pf_correction_shading_shading_lut(const QString &text)
{
    int index = ptCb_pf_correction_shading_shading_lut->currentIndex();
    szQStr_pf_correction_shading_shading_lut[index] = text;
}

void IspPPmisc::activatedSlot_lumvar_stats_ping_mem(int index)
{
    ptEdit_lumvar_stats_ping_mem->setText(szQStr_lumvar_stats_ping_mem[index]);
}

void IspPPmisc::textChangedSlot_lumvar_stats_ping_mem(const QString &text)
{
    int index = ptCb_lumvar_stats_ping_mem->currentIndex();
    szQStr_lumvar_stats_ping_mem[index] = text;
}
