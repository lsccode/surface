#include "ispppfr_config.h"
#include <QGridLayout>
IspPPfr_config::IspPPfr_config(QWidget *parent) :
    QWidget(parent)
{
    init_array();
    QGridLayout *layoutGrid = new QGridLayout;

    // add edit

    ptLabel_fr_cs_convclip_max_uv  = new QLabel("fr_cs_convclip_max_uv :");
    ptEdit_fr_cs_convclip_max_uv  = new QLineEdit("0000024f");
    layoutGrid->addWidget(ptLabel_fr_cs_convclip_max_uv ,0,0);layoutGrid->addWidget(ptEdit_fr_cs_convclip_max_uv ,0,1);

    ptLabel_fr_cs_convclip_max_y  = new QLabel("fr_cs_convclip_max_y :");
    ptEdit_fr_cs_convclip_max_y  = new QLineEdit("0000004e");
    layoutGrid->addWidget(ptLabel_fr_cs_convclip_max_y ,0,2);layoutGrid->addWidget(ptEdit_fr_cs_convclip_max_y ,0,3);

    ptLabel_fr_cs_convclip_min_uv  = new QLabel("fr_cs_convclip_min_uv :");
    ptEdit_fr_cs_convclip_min_uv  = new QLineEdit("000001cf");
    layoutGrid->addWidget(ptLabel_fr_cs_convclip_min_uv ,1,0);layoutGrid->addWidget(ptEdit_fr_cs_convclip_min_uv ,1,1);

    ptLabel_fr_cs_convclip_min_y  = new QLabel("fr_cs_convclip_min_y :");
    ptEdit_fr_cs_convclip_min_y  = new QLineEdit("00000321");
    layoutGrid->addWidget(ptLabel_fr_cs_convclip_min_y ,1,2);layoutGrid->addWidget(ptEdit_fr_cs_convclip_min_y ,1,3);

    ptLabel_fr_cs_convcoefft_11  = new QLabel("fr_cs_convcoefft_11 :");
    ptEdit_fr_cs_convcoefft_11  = new QLineEdit("0000d0b5");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_11 ,2,0);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_11 ,2,1);

    ptLabel_fr_cs_convcoefft_12  = new QLabel("fr_cs_convcoefft_12 :");
    ptEdit_fr_cs_convcoefft_12  = new QLineEdit("000008ea");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_12 ,2,2);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_12 ,2,3);

    ptLabel_fr_cs_convcoefft_13  = new QLabel("fr_cs_convcoefft_13 :");
    ptEdit_fr_cs_convcoefft_13  = new QLineEdit("0000d311");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_13 ,3,0);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_13 ,3,1);

    ptLabel_fr_cs_convcoefft_21  = new QLabel("fr_cs_convcoefft_21 :");
    ptEdit_fr_cs_convcoefft_21  = new QLineEdit("00006af3");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_21 ,3,2);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_21 ,3,3);

    ptLabel_fr_cs_convcoefft_22  = new QLabel("fr_cs_convcoefft_22 :");
    ptEdit_fr_cs_convcoefft_22  = new QLineEdit("0000d604");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_22 ,4,0);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_22 ,4,1);

    ptLabel_fr_cs_convcoefft_23  = new QLabel("fr_cs_convcoefft_23 :");
    ptEdit_fr_cs_convcoefft_23  = new QLineEdit("0000acd4");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_23 ,4,2);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_23 ,4,3);

    ptLabel_fr_cs_convcoefft_31  = new QLabel("fr_cs_convcoefft_31 :");
    ptEdit_fr_cs_convcoefft_31  = new QLineEdit("0000204b");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_31 ,5,0);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_31 ,5,1);

    ptLabel_fr_cs_convcoefft_32  = new QLabel("fr_cs_convcoefft_32 :");
    ptEdit_fr_cs_convcoefft_32  = new QLineEdit("00005ba0");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_32 ,5,2);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_32 ,5,3);

    ptLabel_fr_cs_convcoefft_33  = new QLabel("fr_cs_convcoefft_33 :");
    ptEdit_fr_cs_convcoefft_33  = new QLineEdit("0000bddd");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_33 ,6,0);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_33 ,6,1);

    ptLabel_fr_cs_convcoefft_o1  = new QLabel("fr_cs_convcoefft_o1 :");
    ptEdit_fr_cs_convcoefft_o1  = new QLineEdit("00000732");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_o1 ,6,2);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_o1 ,6,3);

    ptLabel_fr_cs_convcoefft_o2  = new QLabel("fr_cs_convcoefft_o2 :");
    ptEdit_fr_cs_convcoefft_o2  = new QLineEdit("00000617");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_o2 ,7,0);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_o2 ,7,1);

    ptLabel_fr_cs_convcoefft_o3  = new QLabel("fr_cs_convcoefft_o3 :");
    ptEdit_fr_cs_convcoefft_o3  = new QLineEdit("0000027d");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_o3 ,7,2);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_o3 ,7,3);

    ptLabel_fr_cs_convdata_mask_bv  = new QLabel("fr_cs_convdata_mask_bv :");
    ptEdit_fr_cs_convdata_mask_bv  = new QLineEdit("00000334");
    layoutGrid->addWidget(ptLabel_fr_cs_convdata_mask_bv ,8,0);layoutGrid->addWidget(ptEdit_fr_cs_convdata_mask_bv ,8,1);

    ptLabel_fr_cs_convdata_mask_gu  = new QLabel("fr_cs_convdata_mask_gu :");
    ptEdit_fr_cs_convdata_mask_gu  = new QLineEdit("0000020c");
    layoutGrid->addWidget(ptLabel_fr_cs_convdata_mask_gu ,8,2);layoutGrid->addWidget(ptEdit_fr_cs_convdata_mask_gu ,8,3);

    ptLabel_fr_cs_convdata_mask_ry  = new QLabel("fr_cs_convdata_mask_ry :");
    ptEdit_fr_cs_convdata_mask_ry  = new QLineEdit("00000349");
    layoutGrid->addWidget(ptLabel_fr_cs_convdata_mask_ry ,9,0);layoutGrid->addWidget(ptEdit_fr_cs_convdata_mask_ry ,9,1);

    ptLabel_fr_cs_conv_ditherreg_enable_dither  = new QLabel("fr_cs_conv_ditherreg_enable_dither :");
    ptEdit_fr_cs_conv_ditherreg_enable_dither  = new QLineEdit("00000005");
    layoutGrid->addWidget(ptLabel_fr_cs_conv_ditherreg_enable_dither ,9,2);layoutGrid->addWidget(ptEdit_fr_cs_conv_ditherreg_enable_dither ,9,3);

    ptLabel_fr_dma_writeraxi_id_value  = new QLabel("fr_dma_writeraxi_id_value :");
    ptEdit_fr_dma_writeraxi_id_value  = new QLineEdit("0000000c");
    layoutGrid->addWidget(ptLabel_fr_dma_writeraxi_id_value ,10,0);layoutGrid->addWidget(ptEdit_fr_dma_writeraxi_id_value ,10,1);

    ptLabel_fr_dma_writerline_offset  = new QLabel("fr_dma_writerline_offset :");
    ptEdit_fr_dma_writerline_offset  = new QLineEdit("00000180");
    layoutGrid->addWidget(ptLabel_fr_dma_writerline_offset ,10,2);layoutGrid->addWidget(ptEdit_fr_dma_writerline_offset ,10,3);

    ptLabel_fr_dma_writerreg_active_width  = new QLabel("fr_dma_writerreg_active_width :");
    ptEdit_fr_dma_writerreg_active_width  = new QLineEdit("00800080");
    layoutGrid->addWidget(ptLabel_fr_dma_writerreg_active_width ,11,0);layoutGrid->addWidget(ptEdit_fr_dma_writerreg_active_width ,11,1);

    ptLabel_fr_dma_writerreg_format  = new QLabel("fr_dma_writerreg_format :");
    ptEdit_fr_dma_writerreg_format  = new QLineEdit("00000a04");
    layoutGrid->addWidget(ptLabel_fr_dma_writerreg_format ,11,2);layoutGrid->addWidget(ptEdit_fr_dma_writerreg_format ,11,3);

    ptLabel_fr_dma_writerreg_pagewarm_on  = new QLabel("fr_dma_writerreg_pagewarm_on :");
    ptEdit_fr_dma_writerreg_pagewarm_on  = new QLineEdit("0f070f0e");
    layoutGrid->addWidget(ptLabel_fr_dma_writerreg_pagewarm_on ,12,0);layoutGrid->addWidget(ptEdit_fr_dma_writerreg_pagewarm_on ,12,1);

    ptLabel_fr_gamma_rgbgain_b  = new QLabel("fr_gamma_rgbgain_b :");
    ptEdit_fr_gamma_rgbgain_b  = new QLineEdit("00000114");
    layoutGrid->addWidget(ptLabel_fr_gamma_rgbgain_b ,12,2);layoutGrid->addWidget(ptEdit_fr_gamma_rgbgain_b ,12,3);

    ptLabel_fr_gamma_rgboffset_b  = new QLabel("fr_gamma_rgboffset_b :");
    ptEdit_fr_gamma_rgboffset_b  = new QLineEdit("00000003");
    layoutGrid->addWidget(ptLabel_fr_gamma_rgboffset_b ,13,0);layoutGrid->addWidget(ptEdit_fr_gamma_rgboffset_b ,13,1);

    ptLabel_fr_gamma_rgbreg_gain_r  = new QLabel("fr_gamma_rgbreg_gain_r :");
    ptEdit_fr_gamma_rgbreg_gain_r  = new QLineEdit("01a201c3");
    layoutGrid->addWidget(ptLabel_fr_gamma_rgbreg_gain_r ,13,2);layoutGrid->addWidget(ptEdit_fr_gamma_rgbreg_gain_r ,13,3);

    ptLabel_fr_gamma_rgbreg_offset_r  = new QLabel("fr_gamma_rgbreg_offset_r :");
    ptEdit_fr_gamma_rgbreg_offset_r  = new QLineEdit("009e004a");
    layoutGrid->addWidget(ptLabel_fr_gamma_rgbreg_offset_r ,14,0);layoutGrid->addWidget(ptEdit_fr_gamma_rgbreg_offset_r ,14,1);

    ptLabel_fr_sharpendebug  = new QLabel("fr_sharpendebug :");
    ptEdit_fr_sharpendebug  = new QLineEdit("0000000e");
    layoutGrid->addWidget(ptLabel_fr_sharpendebug ,14,2);layoutGrid->addWidget(ptEdit_fr_sharpendebug ,14,3);

    ptLabel_fr_sharpenenable  = new QLabel("fr_sharpenenable :");
    ptEdit_fr_sharpenenable  = new QLineEdit("00000001");
    layoutGrid->addWidget(ptLabel_fr_sharpenenable ,15,0);layoutGrid->addWidget(ptEdit_fr_sharpenenable ,15,1);

    ptLabel_fr_sharpenreg_clip_str_max  = new QLabel("fr_sharpenreg_clip_str_max :");
    ptEdit_fr_sharpenreg_clip_str_max  = new QLineEdit("121410c8");
    layoutGrid->addWidget(ptLabel_fr_sharpenreg_clip_str_max ,15,2);layoutGrid->addWidget(ptEdit_fr_sharpenreg_clip_str_max ,15,3);

    ptLabel_fr_sharpenreg_control_r  = new QLabel("fr_sharpenreg_control_r :");
    ptEdit_fr_sharpenreg_control_r  = new QLineEdit("003240be");
    layoutGrid->addWidget(ptLabel_fr_sharpenreg_control_r ,16,0);layoutGrid->addWidget(ptEdit_fr_sharpenreg_control_r ,16,1);

    ptLabel_fr_sharpenreg_luma_offset_high  = new QLabel("fr_sharpenreg_luma_offset_high :");
    ptEdit_fr_sharpenreg_luma_offset_high  = new QLineEdit("89650038");
    layoutGrid->addWidget(ptLabel_fr_sharpenreg_luma_offset_high ,16,2);layoutGrid->addWidget(ptEdit_fr_sharpenreg_luma_offset_high ,16,3);

    ptLabel_fr_sharpenreg_luma_slope_low  = new QLabel("fr_sharpenreg_luma_slope_low :");
    ptEdit_fr_sharpenreg_luma_slope_low  = new QLineEdit("02c6e991");
    layoutGrid->addWidget(ptLabel_fr_sharpenreg_luma_slope_low ,17,0);layoutGrid->addWidget(ptEdit_fr_sharpenreg_luma_slope_low ,17,1);

    ptLabel_fr_sharpenreg_luma_thresh_low  = new QLabel("fr_sharpenreg_luma_thresh_low :");
    ptEdit_fr_sharpenreg_luma_thresh_low  = new QLineEdit("00b50173");
    layoutGrid->addWidget(ptLabel_fr_sharpenreg_luma_thresh_low ,17,2);layoutGrid->addWidget(ptEdit_fr_sharpenreg_luma_thresh_low ,17,3);

    ptLabel_fr_sharpenstrength  = new QLabel("fr_sharpenstrength :");
    ptEdit_fr_sharpenstrength  = new QLineEdit("0000019a");
    layoutGrid->addWidget(ptLabel_fr_sharpenstrength ,18,0);layoutGrid->addWidget(ptEdit_fr_sharpenstrength ,18,1);

    ptLabel_fr_uv_dma_writeraxi_id_value  = new QLabel("fr_uv_dma_writeraxi_id_value :");
    ptEdit_fr_uv_dma_writeraxi_id_value  = new QLineEdit("00000007");
    layoutGrid->addWidget(ptLabel_fr_uv_dma_writeraxi_id_value ,18,2);layoutGrid->addWidget(ptEdit_fr_uv_dma_writeraxi_id_value ,18,3);

    ptLabel_fr_uv_dma_writerbank0_base  = new QLabel("fr_uv_dma_writerbank0_base :");
    ptEdit_fr_uv_dma_writerbank0_base  = new QLineEdit("20000000");
    layoutGrid->addWidget(ptLabel_fr_uv_dma_writerbank0_base ,19,0);layoutGrid->addWidget(ptEdit_fr_uv_dma_writerbank0_base ,19,1);

    ptLabel_fr_uv_dma_writerline_offset  = new QLabel("fr_uv_dma_writerline_offset :");
    ptEdit_fr_uv_dma_writerline_offset  = new QLineEdit("00000000");
    layoutGrid->addWidget(ptLabel_fr_uv_dma_writerline_offset ,19,2);layoutGrid->addWidget(ptEdit_fr_uv_dma_writerline_offset ,19,3);

    ptLabel_fr_uv_dma_writerreg_active_width  = new QLabel("fr_uv_dma_writerreg_active_width :");
    ptEdit_fr_uv_dma_writerreg_active_width  = new QLineEdit("00800080");
    layoutGrid->addWidget(ptLabel_fr_uv_dma_writerreg_active_width ,20,0);layoutGrid->addWidget(ptEdit_fr_uv_dma_writerreg_active_width ,20,1);

    ptLabel_fr_uv_dma_writerreg_format  = new QLabel("fr_uv_dma_writerreg_format :");
    ptEdit_fr_uv_dma_writerreg_format  = new QLineEdit("00000a00");
    layoutGrid->addWidget(ptLabel_fr_uv_dma_writerreg_format ,20,2);layoutGrid->addWidget(ptEdit_fr_uv_dma_writerreg_format ,20,3);

    ptLabel_fr_uv_dma_writerreg_pagewarm_on  = new QLabel("fr_uv_dma_writerreg_pagewarm_on :");
    ptEdit_fr_uv_dma_writerreg_pagewarm_on  = new QLineEdit("0f280f0c");
    layoutGrid->addWidget(ptLabel_fr_uv_dma_writerreg_pagewarm_on ,21,0);layoutGrid->addWidget(ptEdit_fr_uv_dma_writerreg_pagewarm_on ,21,1);

    ptCb_fr_gamma_rgb_ping_mem  = new QComboBox;
    ptEdit_fr_gamma_rgb_ping_mem = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_fr_gamma_rgb_ping_mem,21,2);layoutGrid->addWidget(ptEdit_fr_gamma_rgb_ping_mem,21,3);
    for(unsigned int i = 0;i < M_FR_GAMMA_RGB_PING_NUMBER; ++i)
    {
        QString str;
        str.sprintf("fr_gamma_rgb_ping_mem[%x]",i);
        ptCb_fr_gamma_rgb_ping_mem->addItem(str);
//        szQStr_fr_gamma_rgb_ping_mem[i].sprintf("%x",i);
    }
    ptEdit_fr_gamma_rgb_ping_mem->setText(szQStr_fr_gamma_rgb_ping_mem[ptCb_fr_gamma_rgb_ping_mem->currentIndex()]);

//    ptPBtn = new QPushButton("确定");
//    layoutGrid->addWidget(ptPBtn,22,3,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

//    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));
    connect(ptCb_fr_gamma_rgb_ping_mem,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_fr_gamma_rgb_ping_mem(int)));
    connect(ptEdit_fr_gamma_rgb_ping_mem,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_fr_gamma_rgb_ping_mem(const QString)));

    setLayout(mainLayout);
}

void IspPPfr_config::init_array()
{
    szQStr_fr_gamma_rgb_ping_mem[0x0] = "00000003";
    szQStr_fr_gamma_rgb_ping_mem[0x1] = "00000011";
    szQStr_fr_gamma_rgb_ping_mem[0x2] = "0000002d";
    szQStr_fr_gamma_rgb_ping_mem[0x3] = "00000033";
    szQStr_fr_gamma_rgb_ping_mem[0x4] = "00000088";
    szQStr_fr_gamma_rgb_ping_mem[0x5] = "00000098";
    szQStr_fr_gamma_rgb_ping_mem[0x6] = "000000dc";
    szQStr_fr_gamma_rgb_ping_mem[0x7] = "000000dd";
    szQStr_fr_gamma_rgb_ping_mem[0x8] = "00000118";
    szQStr_fr_gamma_rgb_ping_mem[0x9] = "00000142";
    szQStr_fr_gamma_rgb_ping_mem[0xa] = "0000015d";
    szQStr_fr_gamma_rgb_ping_mem[0xb] = "00000164";
    szQStr_fr_gamma_rgb_ping_mem[0xc] = "000001a9";
    szQStr_fr_gamma_rgb_ping_mem[0xd] = "000001f5";
    szQStr_fr_gamma_rgb_ping_mem[0xe] = "00000247";
    szQStr_fr_gamma_rgb_ping_mem[0xf] = "00000283";
    szQStr_fr_gamma_rgb_ping_mem[0x10] = "000002a4";
    szQStr_fr_gamma_rgb_ping_mem[0x11] = "000002e2";
    szQStr_fr_gamma_rgb_ping_mem[0x12] = "000002ff";
    szQStr_fr_gamma_rgb_ping_mem[0x13] = "00000306";
    szQStr_fr_gamma_rgb_ping_mem[0x14] = "0000030f";
    szQStr_fr_gamma_rgb_ping_mem[0x15] = "00000314";
    szQStr_fr_gamma_rgb_ping_mem[0x16] = "00000338";
    szQStr_fr_gamma_rgb_ping_mem[0x17] = "0000034a";
    szQStr_fr_gamma_rgb_ping_mem[0x18] = "0000036e";
    szQStr_fr_gamma_rgb_ping_mem[0x19] = "0000038c";
    szQStr_fr_gamma_rgb_ping_mem[0x1a] = "00000394";
    szQStr_fr_gamma_rgb_ping_mem[0x1b] = "000003a2";
    szQStr_fr_gamma_rgb_ping_mem[0x1c] = "000003c6";
    szQStr_fr_gamma_rgb_ping_mem[0x1d] = "000003e9";
    szQStr_fr_gamma_rgb_ping_mem[0x1e] = "00000418";
    szQStr_fr_gamma_rgb_ping_mem[0x1f] = "00000425";
    szQStr_fr_gamma_rgb_ping_mem[0x20] = "00000441";
    szQStr_fr_gamma_rgb_ping_mem[0x21] = "00000444";
    szQStr_fr_gamma_rgb_ping_mem[0x22] = "00000478";
    szQStr_fr_gamma_rgb_ping_mem[0x23] = "0000047e";
    szQStr_fr_gamma_rgb_ping_mem[0x24] = "00000494";
    szQStr_fr_gamma_rgb_ping_mem[0x25] = "00000498";
    szQStr_fr_gamma_rgb_ping_mem[0x26] = "000004a3";
    szQStr_fr_gamma_rgb_ping_mem[0x27] = "000004b7";
    szQStr_fr_gamma_rgb_ping_mem[0x28] = "000004c9";
    szQStr_fr_gamma_rgb_ping_mem[0x29] = "00000530";
    szQStr_fr_gamma_rgb_ping_mem[0x2a] = "00000531";
    szQStr_fr_gamma_rgb_ping_mem[0x2b] = "0000053a";
    szQStr_fr_gamma_rgb_ping_mem[0x2c] = "0000053b";
    szQStr_fr_gamma_rgb_ping_mem[0x2d] = "00000547";
    szQStr_fr_gamma_rgb_ping_mem[0x2e] = "00000556";
    szQStr_fr_gamma_rgb_ping_mem[0x2f] = "00000570";
    szQStr_fr_gamma_rgb_ping_mem[0x30] = "0000058c";
    szQStr_fr_gamma_rgb_ping_mem[0x31] = "0000059a";
    szQStr_fr_gamma_rgb_ping_mem[0x32] = "00000623";
    szQStr_fr_gamma_rgb_ping_mem[0x33] = "0000063b";
    szQStr_fr_gamma_rgb_ping_mem[0x34] = "00000658";
    szQStr_fr_gamma_rgb_ping_mem[0x35] = "00000662";
    szQStr_fr_gamma_rgb_ping_mem[0x36] = "00000695";
    szQStr_fr_gamma_rgb_ping_mem[0x37] = "000006b9";
    szQStr_fr_gamma_rgb_ping_mem[0x38] = "000006cb";
    szQStr_fr_gamma_rgb_ping_mem[0x39] = "000006cc";
    szQStr_fr_gamma_rgb_ping_mem[0x3a] = "000006f6";
    szQStr_fr_gamma_rgb_ping_mem[0x3b] = "000006fb";
    szQStr_fr_gamma_rgb_ping_mem[0x3c] = "00000771";
    szQStr_fr_gamma_rgb_ping_mem[0x3d] = "000007a6";
    szQStr_fr_gamma_rgb_ping_mem[0x3e] = "000007b0";
    szQStr_fr_gamma_rgb_ping_mem[0x3f] = "000007cf";
    szQStr_fr_gamma_rgb_ping_mem[0x40] = "000007de";
    szQStr_fr_gamma_rgb_ping_mem[0x41] = "000007e0";
    szQStr_fr_gamma_rgb_ping_mem[0x42] = "000007eb";
    szQStr_fr_gamma_rgb_ping_mem[0x43] = "000007f4";
    szQStr_fr_gamma_rgb_ping_mem[0x44] = "000007fa";
    szQStr_fr_gamma_rgb_ping_mem[0x45] = "00000809";
    szQStr_fr_gamma_rgb_ping_mem[0x46] = "0000082b";
    szQStr_fr_gamma_rgb_ping_mem[0x47] = "00000843";
    szQStr_fr_gamma_rgb_ping_mem[0x48] = "0000086c";
    szQStr_fr_gamma_rgb_ping_mem[0x49] = "00000872";
    szQStr_fr_gamma_rgb_ping_mem[0x4a] = "00000883";
    szQStr_fr_gamma_rgb_ping_mem[0x4b] = "000008a2";
    szQStr_fr_gamma_rgb_ping_mem[0x4c] = "000008d8";
    szQStr_fr_gamma_rgb_ping_mem[0x4d] = "000008db";
    szQStr_fr_gamma_rgb_ping_mem[0x4e] = "0000090e";
    szQStr_fr_gamma_rgb_ping_mem[0x4f] = "00000911";
    szQStr_fr_gamma_rgb_ping_mem[0x50] = "0000092e";
    szQStr_fr_gamma_rgb_ping_mem[0x51] = "00000942";
    szQStr_fr_gamma_rgb_ping_mem[0x52] = "0000096b";
    szQStr_fr_gamma_rgb_ping_mem[0x53] = "00000973";
    szQStr_fr_gamma_rgb_ping_mem[0x54] = "00000995";
    szQStr_fr_gamma_rgb_ping_mem[0x55] = "000009a3";
    szQStr_fr_gamma_rgb_ping_mem[0x56] = "000009ac";
    szQStr_fr_gamma_rgb_ping_mem[0x57] = "000009d9";
    szQStr_fr_gamma_rgb_ping_mem[0x58] = "00000a00";
    szQStr_fr_gamma_rgb_ping_mem[0x59] = "00000a14";
    szQStr_fr_gamma_rgb_ping_mem[0x5a] = "00000a42";
    szQStr_fr_gamma_rgb_ping_mem[0x5b] = "00000a73";
    szQStr_fr_gamma_rgb_ping_mem[0x5c] = "00000a7b";
    szQStr_fr_gamma_rgb_ping_mem[0x5d] = "00000a80";
    szQStr_fr_gamma_rgb_ping_mem[0x5e] = "00000a95";
    szQStr_fr_gamma_rgb_ping_mem[0x5f] = "00000aa0";
    szQStr_fr_gamma_rgb_ping_mem[0x60] = "00000aae";
    szQStr_fr_gamma_rgb_ping_mem[0x61] = "00000b09";
    szQStr_fr_gamma_rgb_ping_mem[0x62] = "00000b1a";
    szQStr_fr_gamma_rgb_ping_mem[0x63] = "00000b47";
    szQStr_fr_gamma_rgb_ping_mem[0x64] = "00000b6b";
    szQStr_fr_gamma_rgb_ping_mem[0x65] = "00000b88";
    szQStr_fr_gamma_rgb_ping_mem[0x66] = "00000bb3";
    szQStr_fr_gamma_rgb_ping_mem[0x67] = "00000bfe";
    szQStr_fr_gamma_rgb_ping_mem[0x68] = "00000c0a";
    szQStr_fr_gamma_rgb_ping_mem[0x69] = "00000c14";
    szQStr_fr_gamma_rgb_ping_mem[0x6a] = "00000c64";
    szQStr_fr_gamma_rgb_ping_mem[0x6b] = "00000c6a";
    szQStr_fr_gamma_rgb_ping_mem[0x6c] = "00000c9e";
    szQStr_fr_gamma_rgb_ping_mem[0x6d] = "00000cd2";
    szQStr_fr_gamma_rgb_ping_mem[0x6e] = "00000ced";
    szQStr_fr_gamma_rgb_ping_mem[0x6f] = "00000d29";
    szQStr_fr_gamma_rgb_ping_mem[0x70] = "00000d42";
    szQStr_fr_gamma_rgb_ping_mem[0x71] = "00000d98";
    szQStr_fr_gamma_rgb_ping_mem[0x72] = "00000e3e";
    szQStr_fr_gamma_rgb_ping_mem[0x73] = "00000e87";
    szQStr_fr_gamma_rgb_ping_mem[0x74] = "00000e87";
    szQStr_fr_gamma_rgb_ping_mem[0x75] = "00000e8c";
    szQStr_fr_gamma_rgb_ping_mem[0x76] = "00000e95";
    szQStr_fr_gamma_rgb_ping_mem[0x77] = "00000e9e";
    szQStr_fr_gamma_rgb_ping_mem[0x78] = "00000ea8";
    szQStr_fr_gamma_rgb_ping_mem[0x79] = "00000ef5";
    szQStr_fr_gamma_rgb_ping_mem[0x7a] = "00000f3f";
    szQStr_fr_gamma_rgb_ping_mem[0x7b] = "00000f47";
    szQStr_fr_gamma_rgb_ping_mem[0x7c] = "00000f66";
    szQStr_fr_gamma_rgb_ping_mem[0x7d] = "00000fb6";
    szQStr_fr_gamma_rgb_ping_mem[0x7e] = "00000fd5";
    szQStr_fr_gamma_rgb_ping_mem[0x7f] = "00000fd7";
    szQStr_fr_gamma_rgb_ping_mem[0x80] = "00000fe5";
}

void IspPPfr_config::step1()
{
    for(unsigned int i = 0;i < M_FR_GAMMA_RGB_PING_NUMBER; ++i)
    {
        QString strLine;
        strLine.sprintf("fr_gamma_rgb_ping_mem[%x]",i);

        writeLine(E_ACTION_WR,strLine,szQStr_fr_gamma_rgb_ping_mem[i]);
        writeLine(E_ACTION_RR,strLine);
    }
}

void IspPPfr_config::step2()
{
    writeLine(E_ACTION_WR,"isp_config_ping.fr_sharpen.enable",ptEdit_fr_sharpenenable->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_sharpen.enable");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_sharpen.strength",ptEdit_fr_sharpenstrength->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_sharpen.strength");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_sharpen.reg_control_r","00131ebe");
    writeLine(E_ACTION_RR,"isp_config_ping.fr_sharpen.reg_control_r");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_sharpen.reg_control_r","001340be");
    writeLine(E_ACTION_RR,"isp_config_ping.fr_sharpen.reg_control_r");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_sharpen.reg_control_r",ptEdit_fr_sharpenreg_control_r->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_sharpen.reg_control_r");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_sharpen.reg_luma_thresh_low","00000173");
    writeLine(E_ACTION_RR,"isp_config_ping.fr_sharpen.reg_luma_thresh_low");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_sharpen.reg_luma_thresh_low",ptEdit_fr_sharpenreg_luma_thresh_low->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_sharpen.reg_luma_thresh_low");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_sharpen.reg_luma_slope_low","0332e991");
    writeLine(E_ACTION_RR,"isp_config_ping.fr_sharpen.reg_luma_slope_low");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_sharpen.reg_luma_slope_low",ptEdit_fr_sharpenreg_luma_slope_low->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_sharpen.reg_luma_slope_low");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_sharpen.reg_luma_offset_high","06a40038");
    writeLine(E_ACTION_RR,"isp_config_ping.fr_sharpen.reg_luma_offset_high");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_sharpen.reg_luma_offset_high",ptEdit_fr_sharpenreg_luma_offset_high->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_sharpen.reg_luma_offset_high");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_sharpen.reg_clip_str_max","00cd10c8");
    writeLine(E_ACTION_RR,"isp_config_ping.fr_sharpen.reg_clip_str_max");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_sharpen.reg_clip_str_max",ptEdit_fr_sharpenreg_clip_str_max->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_sharpen.reg_clip_str_max");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_sharpen.debug",ptEdit_fr_sharpendebug->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_sharpen.debug");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_gamma_rgb.reg_gain_r","010001c3");
    writeLine(E_ACTION_RR,"isp_config_ping.fr_gamma_rgb.reg_gain_r");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_gamma_rgb.reg_gain_r",ptEdit_fr_gamma_rgbreg_gain_r->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_gamma_rgb.reg_gain_r");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_gamma_rgb.gain_b",ptEdit_fr_gamma_rgbgain_b->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_gamma_rgb.gain_b");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_gamma_rgb.reg_offset_r","0000004a");
    writeLine(E_ACTION_RR,"isp_config_ping.fr_gamma_rgb.reg_offset_r");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_gamma_rgb.reg_offset_r",ptEdit_fr_gamma_rgbreg_offset_r->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_gamma_rgb.reg_offset_r");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_gamma_rgb.offset_b",ptEdit_fr_gamma_rgboffset_b->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_gamma_rgb.offset_b");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_dma_writer.reg_format","00000004");
    writeLine(E_ACTION_RR,"isp_config_ping.fr_dma_writer.reg_format");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_dma_writer.reg_format","00000204");
    writeLine(E_ACTION_RR,"isp_config_ping.fr_dma_writer.reg_format");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_dma_writer.reg_format",ptEdit_fr_dma_writerreg_format->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_dma_writer.reg_format");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_dma_writer.reg_active_width","04380080");
    writeLine(E_ACTION_RR,"isp_config_ping.fr_dma_writer.reg_active_width");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_dma_writer.reg_active_width",ptEdit_fr_dma_writerreg_active_width->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_dma_writer.reg_active_width");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_dma_writer.line_offset",ptEdit_fr_dma_writerline_offset->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_dma_writer.line_offset");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_dma_writer.reg_pagewarm_on","0f000f0e");
    writeLine(E_ACTION_RR,"isp_config_ping.fr_dma_writer.reg_pagewarm_on");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_dma_writer.reg_pagewarm_on",ptEdit_fr_dma_writerreg_pagewarm_on->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_dma_writer.reg_pagewarm_on");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_dma_writer.axi_id_value",ptEdit_fr_dma_writeraxi_id_value->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_dma_writer.axi_id_value");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_uv_dma_writer.reg_format","00000200");
    writeLine(E_ACTION_RR,"isp_config_ping.fr_uv_dma_writer.reg_format");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_uv_dma_writer.reg_format",ptEdit_fr_uv_dma_writerreg_format->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_uv_dma_writer.reg_format");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_uv_dma_writer.reg_active_width","04380080");
    writeLine(E_ACTION_RR,"isp_config_ping.fr_uv_dma_writer.reg_active_width");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_uv_dma_writer.reg_active_width",ptEdit_fr_uv_dma_writerreg_active_width->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_uv_dma_writer.reg_active_width");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_uv_dma_writer.bank0_base",ptEdit_fr_uv_dma_writerbank0_base->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_uv_dma_writer.bank0_base");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_uv_dma_writer.line_offset",ptEdit_fr_uv_dma_writerline_offset->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_uv_dma_writer.line_offset");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_uv_dma_writer.reg_pagewarm_on",ptEdit_fr_uv_dma_writerreg_pagewarm_on->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_uv_dma_writer.reg_pagewarm_on");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_uv_dma_writer.axi_id_value",ptEdit_fr_uv_dma_writeraxi_id_value->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_uv_dma_writer.axi_id_value");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_cs_conv_dither.reg_enable_dither","00000001");
    writeLine(E_ACTION_RR,"isp_config_ping.fr_cs_conv_dither.reg_enable_dither");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_cs_conv_dither.reg_enable_dither",ptEdit_fr_cs_conv_ditherreg_enable_dither->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_cs_conv_dither.reg_enable_dither");

}

void IspPPfr_config::step3()
{
    writeLine(E_ACTION_WR,"isp_config_ping.fr_cs_conv.coefft_11",ptEdit_fr_cs_convcoefft_11->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_cs_conv.coefft_11");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_cs_conv.coefft_12",ptEdit_fr_cs_convcoefft_12->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_cs_conv.coefft_12");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_cs_conv.coefft_13",ptEdit_fr_cs_convcoefft_13->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_cs_conv.coefft_13");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_cs_conv.coefft_21",ptEdit_fr_cs_convcoefft_21->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_cs_conv.coefft_21");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_cs_conv.coefft_22",ptEdit_fr_cs_convcoefft_22->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_cs_conv.coefft_22");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_cs_conv.coefft_23",ptEdit_fr_cs_convcoefft_23->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_cs_conv.coefft_23");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_cs_conv.coefft_31",ptEdit_fr_cs_convcoefft_31->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_cs_conv.coefft_31");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_cs_conv.coefft_32",ptEdit_fr_cs_convcoefft_32->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_cs_conv.coefft_32");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_cs_conv.coefft_33",ptEdit_fr_cs_convcoefft_33->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_cs_conv.coefft_33");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_cs_conv.coefft_o1",ptEdit_fr_cs_convcoefft_o1->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_cs_conv.coefft_o1");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_cs_conv.coefft_o2",ptEdit_fr_cs_convcoefft_o2->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_cs_conv.coefft_o2");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_cs_conv.coefft_o3",ptEdit_fr_cs_convcoefft_o3->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_cs_conv.coefft_o3");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_cs_conv.clip_min_y",ptEdit_fr_cs_convclip_min_y->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_cs_conv.clip_min_y");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_cs_conv.clip_max_y",ptEdit_fr_cs_convclip_max_y->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_cs_conv.clip_max_y");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_cs_conv.clip_min_uv",ptEdit_fr_cs_convclip_min_uv->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_cs_conv.clip_min_uv");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_cs_conv.clip_max_uv",ptEdit_fr_cs_convclip_max_uv->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_cs_conv.clip_max_uv");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_cs_conv.data_mask_ry",ptEdit_fr_cs_convdata_mask_ry->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_cs_conv.data_mask_ry");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_cs_conv.data_mask_gu",ptEdit_fr_cs_convdata_mask_gu->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_cs_conv.data_mask_gu");

    writeLine(E_ACTION_WR,"isp_config_ping.fr_cs_conv.data_mask_bv",ptEdit_fr_cs_convdata_mask_bv->text());
    writeLine(E_ACTION_RR,"isp_config_ping.fr_cs_conv.data_mask_bv");
}

void IspPPfr_config::clickedSlot(bool checked)
{
    QString str_fr_cs_convclip_max_uv = ptEdit_fr_cs_convclip_max_uv->text();
    QString str_fr_cs_convclip_max_y = ptEdit_fr_cs_convclip_max_y->text();
    QString str_fr_cs_convclip_min_uv = ptEdit_fr_cs_convclip_min_uv->text();
    QString str_fr_cs_convclip_min_y = ptEdit_fr_cs_convclip_min_y->text();
    QString str_fr_cs_convcoefft_11 = ptEdit_fr_cs_convcoefft_11->text();
    QString str_fr_cs_convcoefft_12 = ptEdit_fr_cs_convcoefft_12->text();
    QString str_fr_cs_convcoefft_13 = ptEdit_fr_cs_convcoefft_13->text();
    QString str_fr_cs_convcoefft_21 = ptEdit_fr_cs_convcoefft_21->text();
    QString str_fr_cs_convcoefft_22 = ptEdit_fr_cs_convcoefft_22->text();
    QString str_fr_cs_convcoefft_23 = ptEdit_fr_cs_convcoefft_23->text();
    QString str_fr_cs_convcoefft_31 = ptEdit_fr_cs_convcoefft_31->text();
    QString str_fr_cs_convcoefft_32 = ptEdit_fr_cs_convcoefft_32->text();
    QString str_fr_cs_convcoefft_33 = ptEdit_fr_cs_convcoefft_33->text();
    QString str_fr_cs_convcoefft_o1 = ptEdit_fr_cs_convcoefft_o1->text();
    QString str_fr_cs_convcoefft_o2 = ptEdit_fr_cs_convcoefft_o2->text();
    QString str_fr_cs_convcoefft_o3 = ptEdit_fr_cs_convcoefft_o3->text();
    QString str_fr_cs_convdata_mask_bv = ptEdit_fr_cs_convdata_mask_bv->text();
    QString str_fr_cs_convdata_mask_gu = ptEdit_fr_cs_convdata_mask_gu->text();
    QString str_fr_cs_convdata_mask_ry = ptEdit_fr_cs_convdata_mask_ry->text();
    QString str_fr_cs_conv_ditherreg_enable_dither = ptEdit_fr_cs_conv_ditherreg_enable_dither->text();
    QString str_fr_dma_writeraxi_id_value = ptEdit_fr_dma_writeraxi_id_value->text();
    QString str_fr_dma_writerline_offset = ptEdit_fr_dma_writerline_offset->text();
    QString str_fr_dma_writerreg_active_width = ptEdit_fr_dma_writerreg_active_width->text();
    QString str_fr_dma_writerreg_format = ptEdit_fr_dma_writerreg_format->text();
    QString str_fr_dma_writerreg_pagewarm_on = ptEdit_fr_dma_writerreg_pagewarm_on->text();
    QString str_fr_gamma_rgbgain_b = ptEdit_fr_gamma_rgbgain_b->text();
    QString str_fr_gamma_rgboffset_b = ptEdit_fr_gamma_rgboffset_b->text();
    QString str_fr_gamma_rgbreg_gain_r = ptEdit_fr_gamma_rgbreg_gain_r->text();
    QString str_fr_gamma_rgbreg_offset_r = ptEdit_fr_gamma_rgbreg_offset_r->text();
    QString str_fr_sharpendebug = ptEdit_fr_sharpendebug->text();
    QString str_fr_sharpenenable = ptEdit_fr_sharpenenable->text();
    QString str_fr_sharpenreg_clip_str_max = ptEdit_fr_sharpenreg_clip_str_max->text();
    QString str_fr_sharpenreg_control_r = ptEdit_fr_sharpenreg_control_r->text();
    QString str_fr_sharpenreg_luma_offset_high = ptEdit_fr_sharpenreg_luma_offset_high->text();
    QString str_fr_sharpenreg_luma_slope_low = ptEdit_fr_sharpenreg_luma_slope_low->text();
    QString str_fr_sharpenreg_luma_thresh_low = ptEdit_fr_sharpenreg_luma_thresh_low->text();
    QString str_fr_sharpenstrength = ptEdit_fr_sharpenstrength->text();
    QString str_fr_uv_dma_writeraxi_id_value = ptEdit_fr_uv_dma_writeraxi_id_value->text();
    QString str_fr_uv_dma_writerbank0_base = ptEdit_fr_uv_dma_writerbank0_base->text();
    QString str_fr_uv_dma_writerline_offset = ptEdit_fr_uv_dma_writerline_offset->text();
    QString str_fr_uv_dma_writerreg_active_width = ptEdit_fr_uv_dma_writerreg_active_width->text();
    QString str_fr_uv_dma_writerreg_format = ptEdit_fr_uv_dma_writerreg_format->text();
    QString str_fr_uv_dma_writerreg_pagewarm_on = ptEdit_fr_uv_dma_writerreg_pagewarm_on->text();
}

void IspPPfr_config::activatedSlot_fr_gamma_rgb_ping_mem(int index)
{
    ptEdit_fr_gamma_rgb_ping_mem->setText(szQStr_fr_gamma_rgb_ping_mem[index]);
}

void IspPPfr_config::textChangedSlot_fr_gamma_rgb_ping_mem(const QString &text)
{
    int index = ptCb_fr_gamma_rgb_ping_mem->currentIndex();
    szQStr_fr_gamma_rgb_ping_mem[index] = text;
}
