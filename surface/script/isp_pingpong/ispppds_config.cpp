#include "ispppds_config.h"
#include <QGridLayout>
IspPPds_config::IspPPds_config(QWidget *parent) :
    QWidget(parent)
{
    init_array();

    QGridLayout *layoutGrid = new QGridLayout;

    ptLabel_reg_enable_dither  = new QLabel("reg_enable_dither :");
    ptEdit_reg_enable_dither  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_enable_dither ,0,0);layoutGrid->addWidget(ptEdit_reg_enable_dither ,0,1);

    ptLabel_ds_dma_writer_axi_id_value  = new QLabel("ds_dma_writer_axi_id_value :");
    ptEdit_ds_dma_writer_axi_id_value  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_dma_writer_axi_id_value ,1,0);layoutGrid->addWidget(ptEdit_ds_dma_writer_axi_id_value ,1,1);

    ptLabel_ds_dma_writer_bank0_base  = new QLabel("ds_dma_writer_bank0_base :");
    ptEdit_ds_dma_writer_bank0_base  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_dma_writer_bank0_base ,2,0);layoutGrid->addWidget(ptEdit_ds_dma_writer_bank0_base ,2,1);

    ptLabel_ds_dma_writer_line_offset  = new QLabel("ds_dma_line_offset :");
    ptEdit_ds_dma_writer_line_offset  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_dma_writer_line_offset ,3,0);layoutGrid->addWidget(ptEdit_ds_dma_writer_line_offset ,3,1);

    ptLabel_ds_dma_writer_reg_active_width  = new QLabel("ds_dma_reg_active_width :");
    ptEdit_ds_dma_writer_reg_active_width  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_dma_writer_reg_active_width ,4,0);layoutGrid->addWidget(ptEdit_ds_dma_writer_reg_active_width ,4,1);

    ptLabel_ds_dma_writer_reg_format  = new QLabel("ds_dma_reg_format :");
    ptEdit_ds_dma_writer_reg_format  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_dma_writer_reg_format ,5,0);layoutGrid->addWidget(ptEdit_ds_dma_writer_reg_format ,5,1);

    ptLabel_ds_dma_writer_reg_pagewarm_on  = new QLabel("ds_dma_reg_pagewarm_on :");
    ptEdit_ds_dma_writer_reg_pagewarm_on  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_dma_writer_reg_pagewarm_on ,6,0);layoutGrid->addWidget(ptEdit_ds_dma_writer_reg_pagewarm_on ,6,1);

    ptLabel_ds_gamma_rgb_enable  = new QLabel("ds_gamma_enable :");
    ptEdit_ds_gamma_rgb_enable  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_gamma_rgb_enable ,7,0);layoutGrid->addWidget(ptEdit_ds_gamma_rgb_enable ,7,1);

    ptLabel_ds_gamma_rgb_gain_b  = new QLabel("ds_gamma_gain_b :");
    ptEdit_ds_gamma_rgb_gain_b  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_gamma_rgb_gain_b ,8,0);layoutGrid->addWidget(ptEdit_ds_gamma_rgb_gain_b ,8,1);

    ptLabel_ds_gamma_rgb_offset_b  = new QLabel("ds_gamma_offset_b :");
    ptEdit_ds_gamma_rgb_offset_b  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_gamma_rgb_offset_b ,9,0);layoutGrid->addWidget(ptEdit_ds_gamma_rgb_offset_b ,9,1);

    ptLabel_ds_gamma_rgb_reg_gain_r  = new QLabel("ds_gamma_reg_gain_r :");
    ptEdit_ds_gamma_rgb_reg_gain_r  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_gamma_rgb_reg_gain_r ,10,0);layoutGrid->addWidget(ptEdit_ds_gamma_rgb_reg_gain_r ,10,1);

    ptLabel_ds_gamma_rgb_reg_offset_r  = new QLabel("ds_gamma_reg_offset_r :");
    ptEdit_ds_gamma_rgb_reg_offset_r  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_gamma_rgb_reg_offset_r ,11,0);layoutGrid->addWidget(ptEdit_ds_gamma_rgb_reg_offset_r ,11,1);

    ptLabel_ds_sharpen_enable  = new QLabel("ds_sharpen_enable :");
    ptEdit_ds_sharp_enenable  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_sharpen_enable ,12,0);layoutGrid->addWidget(ptEdit_ds_sharp_enenable ,12,1);

    ptLabel_ds_sharpenreg_clip_str_max  = new QLabel("ds_sharpen_reg_clip_str_max :");
    ptEdit_ds_sharpen_reg_clip_str_max  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_sharpenreg_clip_str_max ,13,0);layoutGrid->addWidget(ptEdit_ds_sharpen_reg_clip_str_max ,13,1);

    ptLabel_ds_sharpen_reg_control_r  = new QLabel("ds_sharpen_reg_control_r :");
    ptEdit_ds_sharpen_reg_control_r  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_sharpen_reg_control_r ,14,0);layoutGrid->addWidget(ptEdit_ds_sharpen_reg_control_r ,14,1);

    ptLabel_ds_sharpen_reg_luma_offset_high  = new QLabel("ds_sharpen_reg_luma_offset_high :");
    ptEdit_ds_sharpen_reg_luma_offset_high  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_sharpen_reg_luma_offset_high ,15,0);layoutGrid->addWidget(ptEdit_ds_sharpen_reg_luma_offset_high ,15,1);

    ptLabel_ds_ds_sharpen_reg_luma_slope_low  = new QLabel("ds_sharpen_reg_luma_slope_low :");
    ptEdit_ds_sharpen_reg_luma_slope_low  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_ds_sharpen_reg_luma_slope_low ,16,0);layoutGrid->addWidget(ptEdit_ds_sharpen_reg_luma_slope_low ,16,1);

    ptLabel_ds_sharpen_reg_luma_thresh_low  = new QLabel("ds_sharpen_reg_luma_thresh_low :");
    ptEdit_ds_sharpen_reg_luma_thresh_low  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_sharpen_reg_luma_thresh_low ,17,0);layoutGrid->addWidget(ptEdit_ds_sharpen_reg_luma_thresh_low ,17,1);

    ptLabel_ds_sharpen_strength  = new QLabel("ds_sharpen_strength :");
    ptEdit_ds_sharpen_strength  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_sharpen_strength ,18,0);layoutGrid->addWidget(ptEdit_ds_sharpen_strength ,18,1);

    ptLabel_ds_uv_dma_writer_axi_id_value  = new QLabel("ds_uv_dma_writer_axi_id_value :");
    ptEdit_ds_uv_dma_writer_axi_id_value  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_uv_dma_writer_axi_id_value ,19,0);layoutGrid->addWidget(ptEdit_ds_uv_dma_writer_axi_id_value ,19,1);

    ptLabel_ds_uv_dma_writer_bank0_base  = new QLabel("ds_uv_dma_writer_bank0_base :");
    ptEdit_ds_uv_dma_writer_bank0_base  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_uv_dma_writer_bank0_base ,20,0);layoutGrid->addWidget(ptEdit_ds_uv_dma_writer_bank0_base ,20,1);

    ptLabel_ds_uv_dma_writer_line_offset  = new QLabel("ds_uv_dma_writer_line_offset :");
    ptEdit_ds_uv_dma_writer_line_offset  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_uv_dma_writer_line_offset ,21,0);layoutGrid->addWidget(ptEdit_ds_uv_dma_writer_line_offset ,21,1);

    ptLabel_ds_uv_dma_writer_reg_active_width  = new QLabel("ds_uv_dma_writer_reg_active_width :");
    ptEdit_ds_uv_dma_writer_reg_active_width  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_uv_dma_writer_reg_active_width ,22,0);layoutGrid->addWidget(ptEdit_ds_uv_dma_writer_reg_active_width ,22,1);

    ptLabel_ds_uv_dma_writer_reg_format  = new QLabel("ds_uv_dma_writer_reg_format :");
    ptEdit_ds_uv_dma_writer_reg_format  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_uv_dma_writer_reg_format ,23,0);layoutGrid->addWidget(ptEdit_ds_uv_dma_writer_reg_format ,23,1);

    ptLabel_ds_uv_dma_writer_reg_pagewarm_on  = new QLabel("ds_uv_dma_writer_reg_pagewarm_on :");
    ptEdit_ds_uv_dma_writer_reg_pagewarm_on  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_ds_uv_dma_writer_reg_pagewarm_on ,24,0);layoutGrid->addWidget(ptEdit_ds_uv_dma_writer_reg_pagewarm_on ,24,1);

    ptCb_ds_gamma_rgb_ping_mem  = new QComboBox;
    ptEdit_ds_gamma_rgb_ping_mem = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_ds_gamma_rgb_ping_mem,25,0);layoutGrid->addWidget(ptEdit_ds_gamma_rgb_ping_mem,25,1);
    for(unsigned int i = 0;i < M_DS_GAMMA_RGB_PING_NUMBER; ++i)
    {
        QString str;
        str.sprintf("ds_gamma_rgb_ping_mem[%x]",i);
        ptCb_ds_gamma_rgb_ping_mem->addItem(str);
 //       szQStr_ds_gamma_rgb_ping_mem[i].sprintf("%x",i);
    }
    ptEdit_ds_gamma_rgb_ping_mem->setText(szQStr_ds_gamma_rgb_ping_mem[ptCb_ds_gamma_rgb_ping_mem->currentIndex()]);

//    ptPBtn = new QPushButton("确定");
//    layoutGrid->addWidget(ptPBtn,30,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

//    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

    connect(ptCb_ds_gamma_rgb_ping_mem,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_ds_gamma_rgb_ping_mem(int)));
    connect(ptEdit_ds_gamma_rgb_ping_mem,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_ds_gamma_rgb_ping_mem(const QString)));

    setLayout(mainLayout);
}

void IspPPds_config::init_array()
{
    szQStr_ds_gamma_rgb_ping_mem[0x0] = "0000001c";
    szQStr_ds_gamma_rgb_ping_mem[0x1] = "0000002d";
    szQStr_ds_gamma_rgb_ping_mem[0x2] = "0000009a";
    szQStr_ds_gamma_rgb_ping_mem[0x3] = "000000aa";
    szQStr_ds_gamma_rgb_ping_mem[0x4] = "000000c3";
    szQStr_ds_gamma_rgb_ping_mem[0x5] = "000000c9";
    szQStr_ds_gamma_rgb_ping_mem[0x6] = "000000cc";
    szQStr_ds_gamma_rgb_ping_mem[0x7] = "000000e7";
    szQStr_ds_gamma_rgb_ping_mem[0x8] = "000000f1";
    szQStr_ds_gamma_rgb_ping_mem[0x9] = "000000f2";
    szQStr_ds_gamma_rgb_ping_mem[0xa] = "0000015f";
    szQStr_ds_gamma_rgb_ping_mem[0xb] = "0000018b";
    szQStr_ds_gamma_rgb_ping_mem[0xc] = "0000018f";
    szQStr_ds_gamma_rgb_ping_mem[0xd] = "00000193";
    szQStr_ds_gamma_rgb_ping_mem[0xe] = "000001bf";
    szQStr_ds_gamma_rgb_ping_mem[0xf] = "000001c2";
    szQStr_ds_gamma_rgb_ping_mem[0x10] = "000001cb";
    szQStr_ds_gamma_rgb_ping_mem[0x11] = "000001ce";
    szQStr_ds_gamma_rgb_ping_mem[0x12] = "00000207";
    szQStr_ds_gamma_rgb_ping_mem[0x13] = "00000218";
    szQStr_ds_gamma_rgb_ping_mem[0x14] = "0000021a";
    szQStr_ds_gamma_rgb_ping_mem[0x15] = "00000225";
    szQStr_ds_gamma_rgb_ping_mem[0x16] = "00000228";
    szQStr_ds_gamma_rgb_ping_mem[0x17] = "0000023d";
    szQStr_ds_gamma_rgb_ping_mem[0x18] = "00000292";
    szQStr_ds_gamma_rgb_ping_mem[0x19] = "000002aa";
    szQStr_ds_gamma_rgb_ping_mem[0x1a] = "000002b5";
    szQStr_ds_gamma_rgb_ping_mem[0x1b] = "000002c7";
    szQStr_ds_gamma_rgb_ping_mem[0x1c] = "000002cb";
    szQStr_ds_gamma_rgb_ping_mem[0x1d] = "00000303";
    szQStr_ds_gamma_rgb_ping_mem[0x1e] = "0000032a";
    szQStr_ds_gamma_rgb_ping_mem[0x1f] = "00000344";
    szQStr_ds_gamma_rgb_ping_mem[0x20] = "0000036b";
    szQStr_ds_gamma_rgb_ping_mem[0x21] = "00000379";
    szQStr_ds_gamma_rgb_ping_mem[0x22] = "00000380";
    szQStr_ds_gamma_rgb_ping_mem[0x23] = "000003b2";
    szQStr_ds_gamma_rgb_ping_mem[0x24] = "000003e5";
    szQStr_ds_gamma_rgb_ping_mem[0x25] = "000003e7";
    szQStr_ds_gamma_rgb_ping_mem[0x26] = "000003eb";
    szQStr_ds_gamma_rgb_ping_mem[0x27] = "000003fe";
    szQStr_ds_gamma_rgb_ping_mem[0x28] = "00000411";
    szQStr_ds_gamma_rgb_ping_mem[0x29] = "00000445";
    szQStr_ds_gamma_rgb_ping_mem[0x2a] = "0000044b";
    szQStr_ds_gamma_rgb_ping_mem[0x2b] = "000004c0";
    szQStr_ds_gamma_rgb_ping_mem[0x2c] = "000004dc";
    szQStr_ds_gamma_rgb_ping_mem[0x2d] = "000004e2";
    szQStr_ds_gamma_rgb_ping_mem[0x2e] = "0000050b";
    szQStr_ds_gamma_rgb_ping_mem[0x2f] = "00000518";
    szQStr_ds_gamma_rgb_ping_mem[0x30] = "0000054b";
    szQStr_ds_gamma_rgb_ping_mem[0x31] = "0000054c";
    szQStr_ds_gamma_rgb_ping_mem[0x32] = "00000576";
    szQStr_ds_gamma_rgb_ping_mem[0x33] = "0000059b";
    szQStr_ds_gamma_rgb_ping_mem[0x34] = "0000059e";
    szQStr_ds_gamma_rgb_ping_mem[0x35] = "000005ea";
    szQStr_ds_gamma_rgb_ping_mem[0x36] = "0000060e";
    szQStr_ds_gamma_rgb_ping_mem[0x37] = "00000615";
    szQStr_ds_gamma_rgb_ping_mem[0x38] = "00000621";
    szQStr_ds_gamma_rgb_ping_mem[0x39] = "00000634";
    szQStr_ds_gamma_rgb_ping_mem[0x3a] = "0000066d";
    szQStr_ds_gamma_rgb_ping_mem[0x3b] = "0000066f";
    szQStr_ds_gamma_rgb_ping_mem[0x3c] = "00000697";
    szQStr_ds_gamma_rgb_ping_mem[0x3d] = "000006bf";
    szQStr_ds_gamma_rgb_ping_mem[0x3e] = "000006c4";
    szQStr_ds_gamma_rgb_ping_mem[0x3f] = "000006ca";
    szQStr_ds_gamma_rgb_ping_mem[0x40] = "000006cc";
    szQStr_ds_gamma_rgb_ping_mem[0x41] = "000006e6";
    szQStr_ds_gamma_rgb_ping_mem[0x42] = "0000070c";
    szQStr_ds_gamma_rgb_ping_mem[0x43] = "0000070f";
    szQStr_ds_gamma_rgb_ping_mem[0x44] = "00000785";
    szQStr_ds_gamma_rgb_ping_mem[0x45] = "00000795";
    szQStr_ds_gamma_rgb_ping_mem[0x46] = "0000079e";
    szQStr_ds_gamma_rgb_ping_mem[0x47] = "000007ac";
    szQStr_ds_gamma_rgb_ping_mem[0x48] = "000007c1";
    szQStr_ds_gamma_rgb_ping_mem[0x49] = "000007ca";
    szQStr_ds_gamma_rgb_ping_mem[0x4a] = "000007ea";
    szQStr_ds_gamma_rgb_ping_mem[0x4b] = "00000805";
    szQStr_ds_gamma_rgb_ping_mem[0x4c] = "0000080a";
    szQStr_ds_gamma_rgb_ping_mem[0x4d] = "0000084c";
    szQStr_ds_gamma_rgb_ping_mem[0x4e] = "00000850";
    szQStr_ds_gamma_rgb_ping_mem[0x4f] = "00000856";
    szQStr_ds_gamma_rgb_ping_mem[0x50] = "00000900";
    szQStr_ds_gamma_rgb_ping_mem[0x51] = "00000913";
    szQStr_ds_gamma_rgb_ping_mem[0x52] = "00000926";
    szQStr_ds_gamma_rgb_ping_mem[0x53] = "00000944";
    szQStr_ds_gamma_rgb_ping_mem[0x54] = "00000953";
    szQStr_ds_gamma_rgb_ping_mem[0x55] = "00000993";
    szQStr_ds_gamma_rgb_ping_mem[0x56] = "000009ac";
    szQStr_ds_gamma_rgb_ping_mem[0x57] = "000009c5";
    szQStr_ds_gamma_rgb_ping_mem[0x58] = "000009e9";
    szQStr_ds_gamma_rgb_ping_mem[0x59] = "000009f1";
    szQStr_ds_gamma_rgb_ping_mem[0x5a] = "00000a01";
    szQStr_ds_gamma_rgb_ping_mem[0x5b] = "00000a26";
    szQStr_ds_gamma_rgb_ping_mem[0x5c] = "00000a30";
    szQStr_ds_gamma_rgb_ping_mem[0x5d] = "00000a4c";
    szQStr_ds_gamma_rgb_ping_mem[0x5e] = "00000aeb";
    szQStr_ds_gamma_rgb_ping_mem[0x5f] = "00000b53";
    szQStr_ds_gamma_rgb_ping_mem[0x60] = "00000b65";
    szQStr_ds_gamma_rgb_ping_mem[0x61] = "00000ba6";
    szQStr_ds_gamma_rgb_ping_mem[0x62] = "00000bc2";
    szQStr_ds_gamma_rgb_ping_mem[0x63] = "00000be4";
    szQStr_ds_gamma_rgb_ping_mem[0x64] = "00000bf0";
    szQStr_ds_gamma_rgb_ping_mem[0x65] = "00000bfd";
    szQStr_ds_gamma_rgb_ping_mem[0x66] = "00000c20";
    szQStr_ds_gamma_rgb_ping_mem[0x67] = "00000c93";
    szQStr_ds_gamma_rgb_ping_mem[0x68] = "00000c9f";
    szQStr_ds_gamma_rgb_ping_mem[0x69] = "00000cdd";
    szQStr_ds_gamma_rgb_ping_mem[0x6a] = "00000d2b";
    szQStr_ds_gamma_rgb_ping_mem[0x6b] = "00000d4d";
    szQStr_ds_gamma_rgb_ping_mem[0x6c] = "00000d75";
    szQStr_ds_gamma_rgb_ping_mem[0x6d] = "00000d86";
    szQStr_ds_gamma_rgb_ping_mem[0x6e] = "00000d86";
    szQStr_ds_gamma_rgb_ping_mem[0x6f] = "00000da5";
    szQStr_ds_gamma_rgb_ping_mem[0x70] = "00000df3";
    szQStr_ds_gamma_rgb_ping_mem[0x71] = "00000e0f";
    szQStr_ds_gamma_rgb_ping_mem[0x72] = "00000e12";
    szQStr_ds_gamma_rgb_ping_mem[0x73] = "00000e35";
    szQStr_ds_gamma_rgb_ping_mem[0x74] = "00000e46";
    szQStr_ds_gamma_rgb_ping_mem[0x75] = "00000e72";
    szQStr_ds_gamma_rgb_ping_mem[0x76] = "00000e86";
    szQStr_ds_gamma_rgb_ping_mem[0x77] = "00000e8e";
    szQStr_ds_gamma_rgb_ping_mem[0x78] = "00000ebf";
    szQStr_ds_gamma_rgb_ping_mem[0x79] = "00000ed6";
    szQStr_ds_gamma_rgb_ping_mem[0x7a] = "00000eda";
    szQStr_ds_gamma_rgb_ping_mem[0x7b] = "00000f3b";
    szQStr_ds_gamma_rgb_ping_mem[0x7c] = "00000f50";
    szQStr_ds_gamma_rgb_ping_mem[0x7d] = "00000fb2";
    szQStr_ds_gamma_rgb_ping_mem[0x7e] = "00000fbe";
    szQStr_ds_gamma_rgb_ping_mem[0x7f] = "00000fd3";
    szQStr_ds_gamma_rgb_ping_mem[0x80] = "00000fe6";
}

void IspPPds_config::step1()
{
    for(unsigned int i = 0;i < M_DS_GAMMA_RGB_PING_NUMBER; ++i)
    {
        QString strLine;
        strLine.sprintf("ds_gamma_rgb_ping_mem[%x]",i);

        writeLine(E_ACTION_WR,strLine,szQStr_ds_gamma_rgb_ping_mem[i]);
        writeLine(E_ACTION_RR,strLine);
    }
}

void IspPPds_config::clickedSlot(bool checked)
{
    QString str_reg_enable_dither = ptEdit_reg_enable_dither->text();
    QString str_ds_dma_writer_axi_id_value = ptEdit_ds_dma_writer_axi_id_value->text();
    QString str_ds_dma_writer_bank0_base = ptEdit_ds_dma_writer_bank0_base->text();
    QString str_ds_dma_writer_line_offset = ptEdit_ds_dma_writer_line_offset->text();
    QString str_ds_dma_writer_reg_active_width = ptEdit_ds_dma_writer_reg_active_width->text();
    QString str_ds_dma_writer_reg_format = ptEdit_ds_dma_writer_reg_format->text();
    QString str_ds_dma_writer_reg_pagewarm_on = ptEdit_ds_dma_writer_reg_pagewarm_on->text();
    QString str_ds_gamma_rgb_enable = ptEdit_ds_gamma_rgb_enable->text();
    QString str_ds_gamma_rgb_gain_b = ptEdit_ds_gamma_rgb_gain_b->text();
    QString str_ds_gamma_rgb_offset_b = ptEdit_ds_gamma_rgb_offset_b->text();
    QString str_ds_gamma_rgb_reg_gain_r = ptEdit_ds_gamma_rgb_reg_gain_r->text();
    QString str_ds_gamma_rgb_reg_offset_r = ptEdit_ds_gamma_rgb_reg_offset_r->text();
    QString str_ds_sharpen_enable = ptEdit_ds_sharp_enenable->text();
    QString str_ds_sharpen_reg_clip_str_max = ptEdit_ds_sharpen_reg_clip_str_max->text();
    QString str_ds_sharpen_reg_control_r = ptEdit_ds_sharpen_reg_control_r->text();
    QString str_ds_sharpen_reg_luma_offset_high = ptEdit_ds_sharpen_reg_luma_offset_high->text();
    QString str_ds_sharpen_reg_luma_slope_low = ptEdit_ds_sharpen_reg_luma_slope_low->text();
    QString str_ds_sharpen_reg_luma_thresh_low = ptEdit_ds_sharpen_reg_luma_thresh_low->text();
    QString str_ds_sharpen_strength = ptEdit_ds_sharpen_strength->text();
    QString str_ds_uv_dma_writer_axi_id_value = ptEdit_ds_uv_dma_writer_axi_id_value->text();
    QString str_ds_uv_dma_writer_bank0_base = ptEdit_ds_uv_dma_writer_bank0_base->text();
    QString str_ds_uv_dma_writer_line_offset = ptEdit_ds_uv_dma_writer_line_offset->text();
    QString str_ds_uv_dma_writer_reg_active_width = ptEdit_ds_uv_dma_writer_reg_active_width->text();
    QString str_ds_uv_dma_writer_reg_format = ptEdit_ds_uv_dma_writer_reg_format->text();
    QString str_ds_uv_dma_writer_reg_pagewarm_on = ptEdit_ds_uv_dma_writer_reg_pagewarm_on->text();
}

void IspPPds_config::activatedSlot_ds_gamma_rgb_ping_mem(int index)
{
    ptEdit_ds_gamma_rgb_ping_mem->setText(szQStr_ds_gamma_rgb_ping_mem[index]);
}

void IspPPds_config::textChangedSlot_ds_gamma_rgb_ping_mem(const QString &text)
{
    int index = ptCb_ds_gamma_rgb_ping_mem->currentIndex();
    szQStr_ds_gamma_rgb_ping_mem[index] = text;
}

