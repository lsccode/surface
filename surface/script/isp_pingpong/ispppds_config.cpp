#include "ispppds_config.h"
#include <QGridLayout>
IspPPds_config::IspPPds_config(QWidget *parent) :
    QWidget(parent)
{
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
        szQStr_ds_gamma_rgb_ping_mem[i].sprintf("%x",i);
    }
    ptEdit_ds_gamma_rgb_ping_mem->setText(szQStr_ds_gamma_rgb_ping_mem[ptCb_ds_gamma_rgb_ping_mem->currentIndex()]);

    ptPBtn = new QPushButton("确定");
    layoutGrid->addWidget(ptPBtn,30,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

    connect(ptCb_ds_gamma_rgb_ping_mem,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_ds_gamma_rgb_ping_mem(int)));
    connect(ptEdit_ds_gamma_rgb_ping_mem,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_ds_gamma_rgb_ping_mem(const QString)));

    setLayout(mainLayout);
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

