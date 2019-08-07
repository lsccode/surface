#ifndef ISPPPTEMPER_H
#define ISPPPTEMPER_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include "script/ispcommonstep.h"

#define M_TEMPER_NOISE_PROFILE_LUT_WEIGHT_LUT_NUMBER (0x7f + 1 )

class IspPPtemper : public QWidget,public IspCommonStep
{
    Q_OBJECT
public:
    explicit IspPPtemper(QWidget *parent = 0);

public:
    QLabel *ptLabel_format ;
    QLineEdit *ptEdit_format ;

    QLabel *ptLabel_line_offset ;
    QLineEdit *ptEdit_line_offset ;

    QLabel *ptLabel_msb_bank_base_reader ;
    QLineEdit *ptEdit_msb_bank_base_reader ;

    QLabel *ptLabel_msb_bank_base_writer ;
    QLineEdit *ptEdit_msb_bank_base_writer ;

    QLabel *ptLabel_reg_frame_write_on_msb_dma ;
    QLineEdit *ptEdit_reg_frame_write_on_msb_dma ;

    QLabel *ptLabel_reg_msb_reader_axi_id_value ;
    QLineEdit *ptEdit_reg_msb_reader_axi_id_value ;

    QLabel *ptLabel_reg_msb_writer_axi_id_value ;
    QLineEdit *ptEdit_reg_msb_writer_axi_id_value ;

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

    QLabel *ptLabel_reg_enable ;
    QLineEdit *ptEdit_reg_enable ;

    QLabel *ptLabel_reg_recursion_limit ;
    QLineEdit *ptEdit_reg_recursion_limit ;

    QComboBox *ptCb_temper_noise_profile_lut_weight_lut;
    QLineEdit *ptEdit_temper_noise_profile_lut_weight_lut;
    QString szQStr_temper_noise_profile_lut_weight_lut[M_TEMPER_NOISE_PROFILE_LUT_WEIGHT_LUT_NUMBER];

    QPushButton *ptPBtn;

public:
    virtual void step1();
    virtual void step2();
    virtual void step3();

    void initArray();
signals:

public slots:
    void clickedSlot(bool checked = false);

    void activatedSlot_temper_noise_profile_lut_weight_lut(int index);
    void textChangedSlot_temper_noise_profile_lut_weight_lut(const QString &text);
};

#endif // ISPPPTEMPER_H
