#ifndef ISPPPSINTER_H
#define ISPPPSINTER_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include "script/ispcommonstep.h"

#define M_SINTER_SHADING_RM_SHADING_LUT_NUMBER (0x20 + 1)
#define M_SINTER_NOISE_PROFILE_LUT_WEIGHT_LUT_NUMBER (0x7f + 1)
#define M_LUT3D_MEM_NUMBER (0x3e7 + 1 )
class IspPPsinter : public QWidget,public IspCommonStep
{
    Q_OBJECT
public:
    explicit IspPPsinter(QWidget *parent = 0);

public:
    QLabel *ptLabel_config1 ;
    QLineEdit *ptEdit_config1 ;

    QLabel *ptLabel_config2 ;
    QLineEdit *ptEdit_config2 ;

    QLabel *ptLabel_black_level ;
    QLineEdit *ptEdit_black_level ;

    QLabel *ptLabel_weight_lut ;
    QLineEdit *ptEdit_weight_lut ;

    QLabel *ptLabel_reg_noise_level_0 ;
    QLineEdit *ptEdit_reg_noise_level_0 ;

    QLabel *ptLabel_reg_use_lut ;
    QLineEdit *ptEdit_reg_use_lut ;

    QLabel *ptLabel_thresh1 ;
    QLineEdit *ptEdit_thresh1 ;

    QLabel *ptLabel_thresh2 ;
    QLineEdit *ptEdit_thresh2 ;

    QLabel *ptLabel_thresh3 ;
    QLineEdit *ptEdit_thresh3 ;

    QLabel *ptLabel_reg_rm_center_x ;
    QLineEdit *ptEdit_reg_rm_center_x ;

    QLabel *ptLabel_reg_strength_0 ;
    QLineEdit *ptEdit_reg_strength_0 ;

    QLabel *ptLabel_reg_thresh_0h ;
    QLineEdit *ptEdit_reg_thresh_0h ;

    QLabel *ptLabel_reg_thresh_0v ;
    QLineEdit *ptEdit_reg_thresh_0v ;

    QLabel *ptLabel_rm_off_center_mult ;
    QLineEdit *ptEdit_rm_off_center_mult ;

    QLabel *ptLabel_sad_filt_thresh ;
    QLineEdit *ptEdit_sad_filt_thresh ;

    QComboBox *ptCb_sinter_shading_rm_shading_lut;
    QLineEdit *ptEdit_sinter_shading_rm_shading_lut;
    QString szQStr_sinter_shading_rm_shading_lut[M_SINTER_SHADING_RM_SHADING_LUT_NUMBER];

    QComboBox *ptCb_sinter_noise_profile_lut_weight_lut;
    QLineEdit *ptEdit_sinter_noise_profile_lut_weight_lut;
    QString szQStr_sinter_noise_profile_lut_weight_lut[M_SINTER_NOISE_PROFILE_LUT_WEIGHT_LUT_NUMBER];

    QComboBox *ptCb_lut3d_mem;
    QLineEdit *ptEdit_lut3d_mem;
    QString szQStr_lut3d_mem[M_LUT3D_MEM_NUMBER];

    QPushButton *ptPBtn;

public:
    void init_array();
    void init_lut3d_mem();
    void init_rm_Shading_lut();
    void init_sinter_noise_profile_lut_weight_lut();
    virtual void step1();
    virtual void step2();
signals:

public slots:
    void clickedSlot(bool checked = false);

    void activatedSlot_sinter_shading_rm_shading_lut(int index);
    void textChangedSlot_sinter_shading_rm_shading_lut(const QString &text);

    void activatedSlot_sinter_noise_profile_lut_weight_lut(int index);
    void textChangedSlot_sinter_noise_profile_lut_weight_lut(const QString &text);

    void activatedSlot_lut3d_mem(int index);
    void textChangedSlot_lut3d_mem(const QString &text);
};

#endif // ISPPPSINTER_H
