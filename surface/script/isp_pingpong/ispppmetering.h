#ifndef ISPPPMETERING_AEXP_H
#define ISPPPMETERING_AEXP_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>

#include "script/ispcommonstep.h"

#define M_METERING_AWB_ZONES_WEIGHT_NUMBER (0x440 + 1)
#define M_METERING_HIST_AEXP_ZONES_WEIGHT_NUMBER (0x440 + 1)

class IspPPmetering : public QWidget,public IspCommonStep
{
    Q_OBJECT
public:
    explicit IspPPmetering(QWidget *parent = 0);

public:
    QLabel *ptLabel_metering_aexphist_thresh_0_1 ;
    QLineEdit *ptEdit_metering_aexphist_thresh_0_1 ;

    QLabel *ptLabel_metering_aexphist_thresh_1_2 ;
    QLineEdit *ptEdit_metering_aexphist_thresh_1_2 ;

    QLabel *ptLabel_metering_aexphist_thresh_3_4 ;
    QLineEdit *ptEdit_metering_aexphist_thresh_3_4 ;

    QLabel *ptLabel_metering_aexphist_thresh_4_5 ;
    QLineEdit *ptEdit_metering_aexphist_thresh_4_5 ;

    QLabel *ptLabel_metering_aexpreg_nodes_used_horiz ;
    QLineEdit *ptEdit_metering_aexpreg_nodes_used_horiz ;

    QLabel *ptLabel_metering_afkernel_select ;
    QLineEdit *ptEdit_metering_afkernel_select ;

    QLabel *ptLabel_metering_afreg_active_width ;
    QLineEdit *ptEdit_metering_afreg_active_width ;

    QLabel *ptLabel_metering_afreg_nodes_used_horiz ;
    QLineEdit *ptEdit_metering_afreg_nodes_used_horiz ;

    QLabel *ptLabel_metering_awbblack_level_awb ;
    QLineEdit *ptEdit_metering_awbblack_level_awb ;

    QLabel *ptLabel_metering_awbcb_ref_high_awb ;
    QLineEdit *ptEdit_metering_awbcb_ref_high_awb ;

    QLabel *ptLabel_metering_awbcb_ref_low_awb ;
    QLineEdit *ptEdit_metering_awbcb_ref_low_awb ;

    QLabel *ptLabel_metering_awbcb_ref_max_awb ;
    QLineEdit *ptEdit_metering_awbcb_ref_max_awb ;

    QLabel *ptLabel_metering_awbcb_ref_min_awb ;
    QLineEdit *ptEdit_metering_awbcb_ref_min_awb ;

    QLabel *ptLabel_metering_awbcr_ref_high_awb ;
    QLineEdit *ptEdit_metering_awbcr_ref_high_awb ;

    QLabel *ptLabel_metering_awbcr_ref_low_awb ;
    QLineEdit *ptEdit_metering_awbcr_ref_low_awb ;

    QLabel *ptLabel_metering_awbcr_ref_max_awb ;
    QLineEdit *ptEdit_metering_awbcr_ref_max_awb ;

    QLabel *ptLabel_metering_awbcr_ref_min_awb ;
    QLineEdit *ptEdit_metering_awbcr_ref_min_awb ;

    QLabel *ptLabel_metering_awbreg_nodes_used_horiz ;
    QLineEdit *ptEdit_metering_awbreg_nodes_used_horiz ;

    QLabel *ptLabel_metering_awbstats_mode ;
    QLineEdit *ptEdit_metering_awbstats_mode ;

    QLabel *ptLabel_metering_awbwhite_level_awb ;
    QLineEdit *ptEdit_metering_awbwhite_level_awb ;

    QLabel *ptLabel_metering_awbzones_weight ;
    QLineEdit *ptEdit_metering_awbzones_weight ;

    QLabel *ptLabel_metering_hist_aexpplane_mode ;
    QLineEdit *ptEdit_metering_hist_aexpplane_mode ;

    QLabel *ptLabel_metering_hist_aexpreg_nodes_used_horiz ;
    QLineEdit *ptEdit_metering_hist_aexpreg_nodes_used_horiz ;

    QLabel *ptLabel_metering_hist_aexpreg_scale_bottom ;
    QLineEdit *ptEdit_metering_hist_aexpreg_scale_bottom ;

    QLabel *ptLabel_metering_hist_aexpreg_skip_x ;
    QLineEdit *ptEdit_metering_hist_aexpreg_skip_x ;

    QLabel *ptLabel_metering_hist_aexpzones_weight ;
    QLineEdit *ptEdit_metering_hist_aexpzones_weight ;

    QLabel *ptLabel_metering_ihistplane_mode ;
    QLineEdit *ptEdit_metering_ihistplane_mode ;

    QLabel *ptLabel_metering_ihistreg_nodes_used_horiz ;
    QLineEdit *ptEdit_metering_ihistreg_nodes_used_horiz ;

    QLabel *ptLabel_metering_ihistreg_scale_bottom ;
    QLineEdit *ptEdit_metering_ihistreg_scale_bottom ;

    QLabel *ptLabel_metering_ihistreg_skip_x ;
    QLineEdit *ptEdit_metering_ihistreg_skip_x ;

    QLabel *ptLabel_metering_ihistzones_weight ;
    QLineEdit *ptEdit_metering_ihistzones_weight ;

    QComboBox *ptCb_metering_awb_zones_weight;
    QLineEdit *ptEdit_metering_awb_zones_weight;
    QString szQStr_metering_awb_zones_weight[M_METERING_AWB_ZONES_WEIGHT_NUMBER];

    QComboBox *ptCb_metering_hist_aexp_zones_weight;
    QLineEdit *ptEdit_metering_hist_aexp_zones_weight;
    QString szQStr_metering_hist_aexp_zones_weight[M_METERING_HIST_AEXP_ZONES_WEIGHT_NUMBER];

    QPushButton *ptPBtn;

public:
    void init_array();
    void init_metering_awb_zones_weight();
    virtual void step1();
signals:

public slots:
    void clickedSlot(bool checked = false);

    void activatedSlot_metering_awb_zones_weight(int index);
    void textChangedSlot_metering_awb_zones_weight(const QString &text);

    void activatedSlot_metering_hist_aexp_zones_weight(int index);
    void textChangedSlot_metering_hist_aexp_zones_weight(const QString &text);

};

#endif // ISPPPMETERING_AEXP_H
