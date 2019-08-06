#ifndef ISPPPRAW_FRONTEND_H
#define ISPPPRAW_FRONTEND_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>

#include "script/ispcommonstep.h"

#define M_RAW_FRONTED_NP_LUT_WEIGHT_LUT_NUMBER (0x7f + 1)
class IspPPraw_frontend : public QWidget,public IspCommonStep
{
    Q_OBJECT
public:
    explicit IspPPraw_frontend(QWidget *parent = 0);
public:
    QLabel *ptLabel_exp_thresh ;
    QLineEdit *ptEdit_exp_thresh ;

    QLabel *ptLabel_weight_lut ;
    QLineEdit *ptEdit_weight_lut ;

    QLabel *ptLabel_reg_short_ratio ;
    QLineEdit *ptEdit_reg_short_ratio ;

    QLabel *ptLabel_reg_dpdev_threshold ;
    QLineEdit *ptEdit_reg_dpdev_threshold ;

    QLabel *ptLabel_reg_dp_slope ;
    QLineEdit *ptEdit_reg_dp_slope ;

    QLabel *ptLabel_reg_ge_slope ;
    QLineEdit *ptEdit_reg_ge_slope ;

    QLabel *ptLabel_reg_ge_strength ;
    QLineEdit *ptEdit_reg_ge_strength ;

    QLabel *ptLabel_reg_line_thresh ;
    QLineEdit *ptEdit_reg_line_thresh ;

    QLabel *ptLabel_reg_thresh_short ;
    QLineEdit *ptEdit_reg_thresh_short ;

    QComboBox *ptCb_raw_frontend_np_lut_weight_lut;
    QLineEdit *ptEdit_raw_frontend_np_lut_weight_lut;
    QString szQStr_raw_frontend_np_lut_weight_lut[M_RAW_FRONTED_NP_LUT_WEIGHT_LUT_NUMBER];

    QPushButton *ptPBtn;

public:
    void init_array();
    virtual void step1();
signals:

public slots:
    void clickedSlot(bool checked = false);
    void activatedSlot_raw_frontend_np_lut_weight_lut(int index);
    void textChangedSlot_raw_frontend_np_lut_weight_lut(const QString &text);
};

#endif // ISPPPRAW_FRONTEND_H
