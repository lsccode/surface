#ifndef ISPPPDEMOSAIC_RGBIR_H
#define ISPPPDEMOSAIC_RGBIR_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>

#include "script/ispcommonstep.h"

#define M_DEMOSAIC_RGB_NOISE_PROFILE_WEIGHT_LUT_NUMBER (0x7f + 1 )

class IspPPdemosaic_rgbir : public QWidget,public IspCommonStep
{
    Q_OBJECT
public:
    explicit IspPPdemosaic_rgbir(QWidget *parent = 0);

public:
    QLabel *ptLabel_clip_debloom ;
    QLineEdit *ptEdit_clip_debloom ;

    QLabel *ptLabel_clip_level ;
    QLineEdit *ptEdit_clip_level ;

    QLabel *ptLabel_fc_grad ;
    QLineEdit *ptEdit_fc_grad ;

    QLabel *ptLabel_fc_low ;
    QLineEdit *ptEdit_fc_low ;

    QLabel *ptLabel_interpolation_directionality ;
    QLineEdit *ptEdit_interpolation_directionality ;

    QLabel *ptLabel_reg_gain_r ;
    QLineEdit *ptEdit_reg_gain_r ;

    QLabel *ptLabel_reg_ir_correct_mat00 ;
    QLineEdit *ptEdit_reg_ir_correct_mat00 ;

    QLabel *ptLabel_reg_ir_correct_mat02 ;
    QLineEdit *ptEdit_reg_ir_correct_mat02 ;

    QLabel *ptLabel_reg_ir_correct_mat10 ;
    QLineEdit *ptEdit_reg_ir_correct_mat10 ;

    QLabel *ptLabel_reg_ir_correct_mat12 ;
    QLineEdit *ptEdit_reg_ir_correct_mat12 ;

    QLabel *ptLabel_reg_ir_correct_mat20 ;
    QLineEdit *ptEdit_reg_ir_correct_mat20 ;

    QLabel *ptLabel_reg_ir_correct_mat22 ;
    QLineEdit *ptEdit_reg_ir_correct_mat22 ;

    QLabel *ptLabel_reg_ir_correct_mat30 ;
    QLineEdit *ptEdit_reg_ir_correct_mat30 ;

    QLabel *ptLabel_reg_ir_correct_mat32 ;
    QLineEdit *ptEdit_reg_ir_correct_mat32 ;

    QLabel *ptLabel_reg_static_gain_r ;
    QLineEdit *ptEdit_reg_static_gain_r ;

    QLabel *ptLabel_rgbir_config ;
    QLineEdit *ptEdit_rgbir_config ;

    QLabel *ptLabel_sharp_high ;
    QLineEdit *ptEdit_sharp_high ;

    QLabel *ptLabel_sharp_limit ;
    QLineEdit *ptEdit_sharp_limit ;

    QLabel *ptLabel_sharp_low ;
    QLineEdit *ptEdit_sharp_low ;

    QLabel *ptLabel_static_gain_i ;
    QLineEdit *ptEdit_static_gain_i ;

    QLabel *ptLabel_weight_lut ;
    QLineEdit *ptEdit_weight_lut ;

    QComboBox *ptCb_demosaic_rgb_noise_profile_weight_lut;
    QLineEdit *ptEdit_demosaic_rgb_noise_profile_weight_lut;
    QString szQStr_demosaic_rgb_noise_profile_weight_lut[M_DEMOSAIC_RGB_NOISE_PROFILE_WEIGHT_LUT_NUMBER];

    QPushButton *ptPBtn;

public:
    void init_array();
    virtual void step1();
signals:

public slots:
    void clickedSlot(bool checked);
    void activatedSlot_demosaic_rgb_noise_profile_weight_lut(int index);
    void textChangedSlot_demosaic_rgb_noise_profile_weight_lut(const QString &text);

};

#endif // ISPPPDEMOSAIC_RGBIR_H
