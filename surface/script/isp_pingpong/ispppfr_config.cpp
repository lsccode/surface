#include "ispppfr_config.h"
#include <QGridLayout>
IspPPfr_config::IspPPfr_config(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    // add edit

    ptLabel_fr_cs_convclip_max_uv  = new QLabel("fr_cs_convclip_max_uv :");
    ptEdit_fr_cs_convclip_max_uv  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_cs_convclip_max_uv ,0,0);layoutGrid->addWidget(ptEdit_fr_cs_convclip_max_uv ,0,1);

    ptLabel_fr_cs_convclip_max_y  = new QLabel("fr_cs_convclip_max_y :");
    ptEdit_fr_cs_convclip_max_y  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_cs_convclip_max_y ,0,2);layoutGrid->addWidget(ptEdit_fr_cs_convclip_max_y ,0,3);

    ptLabel_fr_cs_convclip_min_uv  = new QLabel("fr_cs_convclip_min_uv :");
    ptEdit_fr_cs_convclip_min_uv  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_cs_convclip_min_uv ,1,0);layoutGrid->addWidget(ptEdit_fr_cs_convclip_min_uv ,1,1);

    ptLabel_fr_cs_convclip_min_y  = new QLabel("fr_cs_convclip_min_y :");
    ptEdit_fr_cs_convclip_min_y  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_cs_convclip_min_y ,1,2);layoutGrid->addWidget(ptEdit_fr_cs_convclip_min_y ,1,3);

    ptLabel_fr_cs_convcoefft_11  = new QLabel("fr_cs_convcoefft_11 :");
    ptEdit_fr_cs_convcoefft_11  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_11 ,2,0);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_11 ,2,1);

    ptLabel_fr_cs_convcoefft_12  = new QLabel("fr_cs_convcoefft_12 :");
    ptEdit_fr_cs_convcoefft_12  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_12 ,2,2);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_12 ,2,3);

    ptLabel_fr_cs_convcoefft_13  = new QLabel("fr_cs_convcoefft_13 :");
    ptEdit_fr_cs_convcoefft_13  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_13 ,3,0);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_13 ,3,1);

    ptLabel_fr_cs_convcoefft_21  = new QLabel("fr_cs_convcoefft_21 :");
    ptEdit_fr_cs_convcoefft_21  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_21 ,3,2);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_21 ,3,3);

    ptLabel_fr_cs_convcoefft_22  = new QLabel("fr_cs_convcoefft_22 :");
    ptEdit_fr_cs_convcoefft_22  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_22 ,4,0);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_22 ,4,1);

    ptLabel_fr_cs_convcoefft_23  = new QLabel("fr_cs_convcoefft_23 :");
    ptEdit_fr_cs_convcoefft_23  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_23 ,4,2);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_23 ,4,3);

    ptLabel_fr_cs_convcoefft_31  = new QLabel("fr_cs_convcoefft_31 :");
    ptEdit_fr_cs_convcoefft_31  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_31 ,5,0);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_31 ,5,1);

    ptLabel_fr_cs_convcoefft_32  = new QLabel("fr_cs_convcoefft_32 :");
    ptEdit_fr_cs_convcoefft_32  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_32 ,5,2);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_32 ,5,3);

    ptLabel_fr_cs_convcoefft_33  = new QLabel("fr_cs_convcoefft_33 :");
    ptEdit_fr_cs_convcoefft_33  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_33 ,6,0);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_33 ,6,1);

    ptLabel_fr_cs_convcoefft_o1  = new QLabel("fr_cs_convcoefft_o1 :");
    ptEdit_fr_cs_convcoefft_o1  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_o1 ,6,2);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_o1 ,6,3);

    ptLabel_fr_cs_convcoefft_o2  = new QLabel("fr_cs_convcoefft_o2 :");
    ptEdit_fr_cs_convcoefft_o2  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_o2 ,7,0);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_o2 ,7,1);

    ptLabel_fr_cs_convcoefft_o3  = new QLabel("fr_cs_convcoefft_o3 :");
    ptEdit_fr_cs_convcoefft_o3  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_cs_convcoefft_o3 ,7,2);layoutGrid->addWidget(ptEdit_fr_cs_convcoefft_o3 ,7,3);

    ptLabel_fr_cs_convdata_mask_bv  = new QLabel("fr_cs_convdata_mask_bv :");
    ptEdit_fr_cs_convdata_mask_bv  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_cs_convdata_mask_bv ,8,0);layoutGrid->addWidget(ptEdit_fr_cs_convdata_mask_bv ,8,1);

    ptLabel_fr_cs_convdata_mask_gu  = new QLabel("fr_cs_convdata_mask_gu :");
    ptEdit_fr_cs_convdata_mask_gu  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_cs_convdata_mask_gu ,8,2);layoutGrid->addWidget(ptEdit_fr_cs_convdata_mask_gu ,8,3);

    ptLabel_fr_cs_convdata_mask_ry  = new QLabel("fr_cs_convdata_mask_ry :");
    ptEdit_fr_cs_convdata_mask_ry  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_cs_convdata_mask_ry ,9,0);layoutGrid->addWidget(ptEdit_fr_cs_convdata_mask_ry ,9,1);

    ptLabel_fr_cs_conv_ditherreg_enable_dither  = new QLabel("fr_cs_conv_ditherreg_enable_dither :");
    ptEdit_fr_cs_conv_ditherreg_enable_dither  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_cs_conv_ditherreg_enable_dither ,9,2);layoutGrid->addWidget(ptEdit_fr_cs_conv_ditherreg_enable_dither ,9,3);

    ptLabel_fr_dma_writeraxi_id_value  = new QLabel("fr_dma_writeraxi_id_value :");
    ptEdit_fr_dma_writeraxi_id_value  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_dma_writeraxi_id_value ,10,0);layoutGrid->addWidget(ptEdit_fr_dma_writeraxi_id_value ,10,1);

    ptLabel_fr_dma_writerline_offset  = new QLabel("fr_dma_writerline_offset :");
    ptEdit_fr_dma_writerline_offset  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_dma_writerline_offset ,10,2);layoutGrid->addWidget(ptEdit_fr_dma_writerline_offset ,10,3);

    ptLabel_fr_dma_writerreg_active_width  = new QLabel("fr_dma_writerreg_active_width :");
    ptEdit_fr_dma_writerreg_active_width  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_dma_writerreg_active_width ,11,0);layoutGrid->addWidget(ptEdit_fr_dma_writerreg_active_width ,11,1);

    ptLabel_fr_dma_writerreg_format  = new QLabel("fr_dma_writerreg_format :");
    ptEdit_fr_dma_writerreg_format  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_dma_writerreg_format ,11,2);layoutGrid->addWidget(ptEdit_fr_dma_writerreg_format ,11,3);

    ptLabel_fr_dma_writerreg_pagewarm_on  = new QLabel("fr_dma_writerreg_pagewarm_on :");
    ptEdit_fr_dma_writerreg_pagewarm_on  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_dma_writerreg_pagewarm_on ,12,0);layoutGrid->addWidget(ptEdit_fr_dma_writerreg_pagewarm_on ,12,1);

    ptLabel_fr_gamma_rgbgain_b  = new QLabel("fr_gamma_rgbgain_b :");
    ptEdit_fr_gamma_rgbgain_b  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_gamma_rgbgain_b ,12,2);layoutGrid->addWidget(ptEdit_fr_gamma_rgbgain_b ,12,3);

    ptLabel_fr_gamma_rgboffset_b  = new QLabel("fr_gamma_rgboffset_b :");
    ptEdit_fr_gamma_rgboffset_b  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_gamma_rgboffset_b ,13,0);layoutGrid->addWidget(ptEdit_fr_gamma_rgboffset_b ,13,1);

    ptLabel_fr_gamma_rgbreg_gain_r  = new QLabel("fr_gamma_rgbreg_gain_r :");
    ptEdit_fr_gamma_rgbreg_gain_r  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_gamma_rgbreg_gain_r ,13,2);layoutGrid->addWidget(ptEdit_fr_gamma_rgbreg_gain_r ,13,3);

    ptLabel_fr_gamma_rgbreg_offset_r  = new QLabel("fr_gamma_rgbreg_offset_r :");
    ptEdit_fr_gamma_rgbreg_offset_r  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_gamma_rgbreg_offset_r ,14,0);layoutGrid->addWidget(ptEdit_fr_gamma_rgbreg_offset_r ,14,1);

    ptLabel_fr_sharpendebug  = new QLabel("fr_sharpendebug :");
    ptEdit_fr_sharpendebug  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_sharpendebug ,14,2);layoutGrid->addWidget(ptEdit_fr_sharpendebug ,14,3);

    ptLabel_fr_sharpenenable  = new QLabel("fr_sharpenenable :");
    ptEdit_fr_sharpenenable  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_sharpenenable ,15,0);layoutGrid->addWidget(ptEdit_fr_sharpenenable ,15,1);

    ptLabel_fr_sharpenreg_clip_str_max  = new QLabel("fr_sharpenreg_clip_str_max :");
    ptEdit_fr_sharpenreg_clip_str_max  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_sharpenreg_clip_str_max ,15,2);layoutGrid->addWidget(ptEdit_fr_sharpenreg_clip_str_max ,15,3);

    ptLabel_fr_sharpenreg_control_r  = new QLabel("fr_sharpenreg_control_r :");
    ptEdit_fr_sharpenreg_control_r  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_sharpenreg_control_r ,16,0);layoutGrid->addWidget(ptEdit_fr_sharpenreg_control_r ,16,1);

    ptLabel_fr_sharpenreg_luma_offset_high  = new QLabel("fr_sharpenreg_luma_offset_high :");
    ptEdit_fr_sharpenreg_luma_offset_high  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_sharpenreg_luma_offset_high ,16,2);layoutGrid->addWidget(ptEdit_fr_sharpenreg_luma_offset_high ,16,3);

    ptLabel_fr_sharpenreg_luma_slope_low  = new QLabel("fr_sharpenreg_luma_slope_low :");
    ptEdit_fr_sharpenreg_luma_slope_low  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_sharpenreg_luma_slope_low ,17,0);layoutGrid->addWidget(ptEdit_fr_sharpenreg_luma_slope_low ,17,1);

    ptLabel_fr_sharpenreg_luma_thresh_low  = new QLabel("fr_sharpenreg_luma_thresh_low :");
    ptEdit_fr_sharpenreg_luma_thresh_low  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_sharpenreg_luma_thresh_low ,17,2);layoutGrid->addWidget(ptEdit_fr_sharpenreg_luma_thresh_low ,17,3);

    ptLabel_fr_sharpenstrength  = new QLabel("fr_sharpenstrength :");
    ptEdit_fr_sharpenstrength  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_sharpenstrength ,18,0);layoutGrid->addWidget(ptEdit_fr_sharpenstrength ,18,1);

    ptLabel_fr_uv_dma_writeraxi_id_value  = new QLabel("fr_uv_dma_writeraxi_id_value :");
    ptEdit_fr_uv_dma_writeraxi_id_value  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_uv_dma_writeraxi_id_value ,18,2);layoutGrid->addWidget(ptEdit_fr_uv_dma_writeraxi_id_value ,18,3);

    ptLabel_fr_uv_dma_writerbank0_base  = new QLabel("fr_uv_dma_writerbank0_base :");
    ptEdit_fr_uv_dma_writerbank0_base  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_uv_dma_writerbank0_base ,19,0);layoutGrid->addWidget(ptEdit_fr_uv_dma_writerbank0_base ,19,1);

    ptLabel_fr_uv_dma_writerline_offset  = new QLabel("fr_uv_dma_writerline_offset :");
    ptEdit_fr_uv_dma_writerline_offset  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_uv_dma_writerline_offset ,19,2);layoutGrid->addWidget(ptEdit_fr_uv_dma_writerline_offset ,19,3);

    ptLabel_fr_uv_dma_writerreg_active_width  = new QLabel("fr_uv_dma_writerreg_active_width :");
    ptEdit_fr_uv_dma_writerreg_active_width  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_uv_dma_writerreg_active_width ,20,0);layoutGrid->addWidget(ptEdit_fr_uv_dma_writerreg_active_width ,20,1);

    ptLabel_fr_uv_dma_writerreg_format  = new QLabel("fr_uv_dma_writerreg_format :");
    ptEdit_fr_uv_dma_writerreg_format  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_uv_dma_writerreg_format ,20,2);layoutGrid->addWidget(ptEdit_fr_uv_dma_writerreg_format ,20,3);

    ptLabel_fr_uv_dma_writerreg_pagewarm_on  = new QLabel("fr_uv_dma_writerreg_pagewarm_on :");
    ptEdit_fr_uv_dma_writerreg_pagewarm_on  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fr_uv_dma_writerreg_pagewarm_on ,21,0);layoutGrid->addWidget(ptEdit_fr_uv_dma_writerreg_pagewarm_on ,21,1);

    ptCb_fr_gamma_rgb_ping_mem  = new QComboBox;
    ptEdit_fr_gamma_rgb_ping_mem = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_fr_gamma_rgb_ping_mem,21,2);layoutGrid->addWidget(ptEdit_fr_gamma_rgb_ping_mem,21,3);
    for(unsigned int i = 0;i < M_FR_GAMMA_RGB_PING_NUMBER; ++i)
    {
        QString str;
        str.sprintf("fr_gamma_rgb_ping_mem[%x]",i);
        ptCb_fr_gamma_rgb_ping_mem->addItem(str);
        szQStr_fr_gamma_rgb_ping_mem[i].sprintf("%x",i);
    }
    ptEdit_fr_gamma_rgb_ping_mem->setText(szQStr_fr_gamma_rgb_ping_mem[ptCb_fr_gamma_rgb_ping_mem->currentIndex()]);

    ptPBtn = new QPushButton("确定");
    layoutGrid->addWidget(ptPBtn,22,3,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));
    connect(ptCb_fr_gamma_rgb_ping_mem,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_fr_gamma_rgb_ping_mem(int)));
    connect(ptEdit_fr_gamma_rgb_ping_mem,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_fr_gamma_rgb_ping_mem(const QString)));

    setLayout(mainLayout);
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
