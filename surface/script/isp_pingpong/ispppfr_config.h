#ifndef ISPPPFR_CS_CONV_H
#define ISPPPFR_CS_CONV_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>

#include "script/ispcommonstep.h"

#define M_FR_GAMMA_RGB_PING_NUMBER (0x80+1)

class IspPPfr_config : public QWidget,public IspCommonStep
{
    Q_OBJECT
public:
    explicit IspPPfr_config(QWidget *parent = 0);
    QLabel *ptLabel_fr_cs_convclip_max_uv ;
    QLineEdit *ptEdit_fr_cs_convclip_max_uv ;

    QLabel *ptLabel_fr_cs_convclip_max_y ;
    QLineEdit *ptEdit_fr_cs_convclip_max_y ;

    QLabel *ptLabel_fr_cs_convclip_min_uv ;
    QLineEdit *ptEdit_fr_cs_convclip_min_uv ;

    QLabel *ptLabel_fr_cs_convclip_min_y ;
    QLineEdit *ptEdit_fr_cs_convclip_min_y ;

    QLabel *ptLabel_fr_cs_convcoefft_11 ;
    QLineEdit *ptEdit_fr_cs_convcoefft_11 ;

    QLabel *ptLabel_fr_cs_convcoefft_12 ;
    QLineEdit *ptEdit_fr_cs_convcoefft_12 ;

    QLabel *ptLabel_fr_cs_convcoefft_13 ;
    QLineEdit *ptEdit_fr_cs_convcoefft_13 ;

    QLabel *ptLabel_fr_cs_convcoefft_21 ;
    QLineEdit *ptEdit_fr_cs_convcoefft_21 ;

    QLabel *ptLabel_fr_cs_convcoefft_22 ;
    QLineEdit *ptEdit_fr_cs_convcoefft_22 ;

    QLabel *ptLabel_fr_cs_convcoefft_23 ;
    QLineEdit *ptEdit_fr_cs_convcoefft_23 ;

    QLabel *ptLabel_fr_cs_convcoefft_31 ;
    QLineEdit *ptEdit_fr_cs_convcoefft_31 ;

    QLabel *ptLabel_fr_cs_convcoefft_32 ;
    QLineEdit *ptEdit_fr_cs_convcoefft_32 ;

    QLabel *ptLabel_fr_cs_convcoefft_33 ;
    QLineEdit *ptEdit_fr_cs_convcoefft_33 ;

    QLabel *ptLabel_fr_cs_convcoefft_o1 ;
    QLineEdit *ptEdit_fr_cs_convcoefft_o1 ;

    QLabel *ptLabel_fr_cs_convcoefft_o2 ;
    QLineEdit *ptEdit_fr_cs_convcoefft_o2 ;

    QLabel *ptLabel_fr_cs_convcoefft_o3 ;
    QLineEdit *ptEdit_fr_cs_convcoefft_o3 ;

    QLabel *ptLabel_fr_cs_convdata_mask_bv ;
    QLineEdit *ptEdit_fr_cs_convdata_mask_bv ;

    QLabel *ptLabel_fr_cs_convdata_mask_gu ;
    QLineEdit *ptEdit_fr_cs_convdata_mask_gu ;

    QLabel *ptLabel_fr_cs_convdata_mask_ry ;
    QLineEdit *ptEdit_fr_cs_convdata_mask_ry ;

    QLabel *ptLabel_fr_cs_conv_ditherreg_enable_dither ;
    QLineEdit *ptEdit_fr_cs_conv_ditherreg_enable_dither ;

    QLabel *ptLabel_fr_dma_writeraxi_id_value ;
    QLineEdit *ptEdit_fr_dma_writeraxi_id_value ;

    QLabel *ptLabel_fr_dma_writerline_offset ;
    QLineEdit *ptEdit_fr_dma_writerline_offset ;

    QLabel *ptLabel_fr_dma_writerreg_active_width ;
    QLineEdit *ptEdit_fr_dma_writerreg_active_width ;

    QLabel *ptLabel_fr_dma_writerreg_format ;
    QLineEdit *ptEdit_fr_dma_writerreg_format ;

    QLabel *ptLabel_fr_dma_writerreg_pagewarm_on ;
    QLineEdit *ptEdit_fr_dma_writerreg_pagewarm_on ;

    QLabel *ptLabel_fr_gamma_rgbgain_b ;
    QLineEdit *ptEdit_fr_gamma_rgbgain_b ;

    QLabel *ptLabel_fr_gamma_rgboffset_b ;
    QLineEdit *ptEdit_fr_gamma_rgboffset_b ;

    QLabel *ptLabel_fr_gamma_rgbreg_gain_r ;
    QLineEdit *ptEdit_fr_gamma_rgbreg_gain_r ;

    QLabel *ptLabel_fr_gamma_rgbreg_offset_r ;
    QLineEdit *ptEdit_fr_gamma_rgbreg_offset_r ;

    QLabel *ptLabel_fr_sharpendebug ;
    QLineEdit *ptEdit_fr_sharpendebug ;

    QLabel *ptLabel_fr_sharpenenable ;
    QLineEdit *ptEdit_fr_sharpenenable ;

    QLabel *ptLabel_fr_sharpenreg_clip_str_max ;
    QLineEdit *ptEdit_fr_sharpenreg_clip_str_max ;

    QLabel *ptLabel_fr_sharpenreg_control_r ;
    QLineEdit *ptEdit_fr_sharpenreg_control_r ;

    QLabel *ptLabel_fr_sharpenreg_luma_offset_high ;
    QLineEdit *ptEdit_fr_sharpenreg_luma_offset_high ;

    QLabel *ptLabel_fr_sharpenreg_luma_slope_low ;
    QLineEdit *ptEdit_fr_sharpenreg_luma_slope_low ;

    QLabel *ptLabel_fr_sharpenreg_luma_thresh_low ;
    QLineEdit *ptEdit_fr_sharpenreg_luma_thresh_low ;

    QLabel *ptLabel_fr_sharpenstrength ;
    QLineEdit *ptEdit_fr_sharpenstrength ;

    QLabel *ptLabel_fr_uv_dma_writeraxi_id_value ;
    QLineEdit *ptEdit_fr_uv_dma_writeraxi_id_value ;

    QLabel *ptLabel_fr_uv_dma_writerbank0_base ;
    QLineEdit *ptEdit_fr_uv_dma_writerbank0_base ;

    QLabel *ptLabel_fr_uv_dma_writerline_offset ;
    QLineEdit *ptEdit_fr_uv_dma_writerline_offset ;

    QLabel *ptLabel_fr_uv_dma_writerreg_active_width ;
    QLineEdit *ptEdit_fr_uv_dma_writerreg_active_width ;

    QLabel *ptLabel_fr_uv_dma_writerreg_format ;
    QLineEdit *ptEdit_fr_uv_dma_writerreg_format ;

    QLabel *ptLabel_fr_uv_dma_writerreg_pagewarm_on ;
    QLineEdit *ptEdit_fr_uv_dma_writerreg_pagewarm_on ;

    QComboBox *ptCb_fr_gamma_rgb_ping_mem;
    QLineEdit *ptEdit_fr_gamma_rgb_ping_mem;
    QString szQStr_fr_gamma_rgb_ping_mem[M_FR_GAMMA_RGB_PING_NUMBER];

    QPushButton *ptPBtn;

public:
    void init_array();
    virtual void step1();
    virtual void step2();
signals:

public slots:
    void clickedSlot(bool checked = false);
    void activatedSlot_fr_gamma_rgb_ping_mem(int index);
    void textChangedSlot_fr_gamma_rgb_ping_mem(const QString &text);
};

#endif // ISPPPFR_CS_CONV_H
