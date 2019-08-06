#ifndef ISPPPDS_CS_CONV_H
#define ISPPPDS_CS_CONV_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>

#include "script/ispcommonstep.h"

#define M_DS_GAMMA_RGB_PING_NUMBER (0x80+1)

class IspPPds_config : public QWidget,public IspCommonStep
{
    Q_OBJECT
public:
    explicit IspPPds_config(QWidget *parent = 0);
public:
    QLabel *ptLabel_reg_enable_dither ;
    QLineEdit *ptEdit_reg_enable_dither ;

    QLabel *ptLabel_ds_dma_writer_axi_id_value ;
    QLineEdit *ptEdit_ds_dma_writer_axi_id_value ;

    QLabel *ptLabel_ds_dma_writer_bank0_base ;
    QLineEdit *ptEdit_ds_dma_writer_bank0_base ;

    QLabel *ptLabel_ds_dma_writer_line_offset ;
    QLineEdit *ptEdit_ds_dma_writer_line_offset ;

    QLabel *ptLabel_ds_dma_writer_reg_active_width ;
    QLineEdit *ptEdit_ds_dma_writer_reg_active_width ;

    QLabel *ptLabel_ds_dma_writer_reg_format ;
    QLineEdit *ptEdit_ds_dma_writer_reg_format ;

    QLabel *ptLabel_ds_dma_writer_reg_pagewarm_on ;
    QLineEdit *ptEdit_ds_dma_writer_reg_pagewarm_on ;

    QLabel *ptLabel_ds_gamma_rgb_enable ;
    QLineEdit *ptEdit_ds_gamma_rgb_enable ;

    QLabel *ptLabel_ds_gamma_rgb_gain_b ;
    QLineEdit *ptEdit_ds_gamma_rgb_gain_b ;

    QLabel *ptLabel_ds_gamma_rgb_offset_b ;
    QLineEdit *ptEdit_ds_gamma_rgb_offset_b ;

    QLabel *ptLabel_ds_gamma_rgb_reg_gain_r ;
    QLineEdit *ptEdit_ds_gamma_rgb_reg_gain_r ;

    QLabel *ptLabel_ds_gamma_rgb_reg_offset_r ;
    QLineEdit *ptEdit_ds_gamma_rgb_reg_offset_r ;

    QLabel *ptLabel_ds_sharpen_enable ;
    QLineEdit *ptEdit_ds_sharp_enenable ;

    QLabel *ptLabel_ds_sharpenreg_clip_str_max ;
    QLineEdit *ptEdit_ds_sharpen_reg_clip_str_max ;

    QLabel *ptLabel_ds_sharpen_reg_control_r ;
    QLineEdit *ptEdit_ds_sharpen_reg_control_r ;

    QLabel *ptLabel_ds_sharpen_reg_luma_offset_high ;
    QLineEdit *ptEdit_ds_sharpen_reg_luma_offset_high ;

    QLabel *ptLabel_ds_ds_sharpen_reg_luma_slope_low ;
    QLineEdit *ptEdit_ds_sharpen_reg_luma_slope_low ;

    QLabel *ptLabel_ds_sharpen_reg_luma_thresh_low ;
    QLineEdit *ptEdit_ds_sharpen_reg_luma_thresh_low ;

    QLabel *ptLabel_ds_sharpen_strength ;
    QLineEdit *ptEdit_ds_sharpen_strength ;

    QLabel *ptLabel_ds_uv_dma_writer_axi_id_value ;
    QLineEdit *ptEdit_ds_uv_dma_writer_axi_id_value ;

    QLabel *ptLabel_ds_uv_dma_writer_bank0_base ;
    QLineEdit *ptEdit_ds_uv_dma_writer_bank0_base ;

    QLabel *ptLabel_ds_uv_dma_writer_line_offset ;
    QLineEdit *ptEdit_ds_uv_dma_writer_line_offset ;

    QLabel *ptLabel_ds_uv_dma_writer_reg_active_width ;
    QLineEdit *ptEdit_ds_uv_dma_writer_reg_active_width ;

    QLabel *ptLabel_ds_uv_dma_writer_reg_format ;
    QLineEdit *ptEdit_ds_uv_dma_writer_reg_format ;

    QLabel *ptLabel_ds_uv_dma_writer_reg_pagewarm_on ;
    QLineEdit *ptEdit_ds_uv_dma_writer_reg_pagewarm_on ;

    QComboBox *ptCb_ds_gamma_rgb_ping_mem;
    QLineEdit *ptEdit_ds_gamma_rgb_ping_mem;
    QString szQStr_ds_gamma_rgb_ping_mem[M_DS_GAMMA_RGB_PING_NUMBER];

    QPushButton *ptPBtn;

public:
    void init_array();
    virtual void step1();
signals:

public slots:
    void clickedSlot(bool checked = false);
    void activatedSlot_ds_gamma_rgb_ping_mem(int index);
    void textChangedSlot_ds_gamma_rgb_ping_mem(const QString &text);
};

#endif // ISPPPDS_CS_CONV_H
