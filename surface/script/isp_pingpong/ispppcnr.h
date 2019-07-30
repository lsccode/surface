#ifndef ISPPPCNR_H
#define ISPPPCNR_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class IspPPCnr : public QWidget
{
    Q_OBJECT
public:
    explicit IspPPCnr(QWidget *parent = 0);
public:
    QLabel *ptLabel_delta_factor ;
    QLineEdit *ptEdit_delta_factor ;

    QLabel *ptLabel_effective_kernel ;
    QLineEdit *ptEdit_effective_kernel ;

    QLabel *ptLabel_enable ;
    QLineEdit *ptEdit_enable ;

    QLabel *ptLabel_global_offset ;
    QLineEdit *ptEdit_global_offset ;

    QLabel *ptLabel_global_slope ;
    QLineEdit *ptEdit_global_slope ;

    QLabel *ptLabel_reg_uv_var1_scale ;
    QLineEdit *ptEdit_reg_uv_var1_scale ;

    QLabel *ptLabel_u_center ;
    QLineEdit *ptEdit_u_center ;

    QLabel *ptLabel_umean1_offset ;
    QLineEdit *ptEdit_umean1_offset ;

    QLabel *ptLabel_umean1_slope ;
    QLineEdit *ptEdit_umean1_slope ;

    QLabel *ptLabel_umean1_threshold ;
    QLineEdit *ptEdit_umean1_threshold ;

    QLabel *ptLabel_umean2_offset ;
    QLineEdit *ptEdit_umean2_offset ;

    QLabel *ptLabel_umean2_slope ;
    QLineEdit *ptEdit_umean2_slope ;

    QLabel *ptLabel_umean2_threshold ;
    QLineEdit *ptEdit_umean2_threshold ;

    QLabel *ptLabel_uv_delta1_offset ;
    QLineEdit *ptEdit_uv_delta1_offset ;

    QLabel *ptLabel_uv_delta1_slope ;
    QLineEdit *ptEdit_uv_delta1_slope ;

    QLabel *ptLabel_uv_delta1_threshold ;
    QLineEdit *ptEdit_uv_delta1_threshold ;

    QLabel *ptLabel_uv_delta2_offset ;
    QLineEdit *ptEdit_uv_delta2_offset ;

    QLabel *ptLabel_uv_delta2_slope ;
    QLineEdit *ptEdit_uv_delta2_slope ;

    QLabel *ptLabel_uv_delta2_threshold ;
    QLineEdit *ptEdit_uv_delta2_threshold ;

    QLabel *ptLabel_uv_seg1_offset ;
    QLineEdit *ptEdit_uv_seg1_offset ;

    QLabel *ptLabel_uv_seg1_slope ;
    QLineEdit *ptEdit_uv_seg1_slope ;

    QLabel *ptLabel_uv_seg1_threshold ;
    QLineEdit *ptEdit_uv_seg1_threshold ;

    QLabel *ptLabel_uv_var1_offset ;
    QLineEdit *ptEdit_uv_var1_offset ;

    QLabel *ptLabel_uv_var1_slope ;
    QLineEdit *ptEdit_uv_var1_slope ;

    QLabel *ptLabel_uv_var1_threshold ;
    QLineEdit *ptEdit_uv_var1_threshold ;

    QLabel *ptLabel_uv_var2_offset ;
    QLineEdit *ptEdit_uv_var2_offset ;

    QLabel *ptLabel_uv_var2_slope ;
    QLineEdit *ptEdit_uv_var2_slope ;

    QLabel *ptLabel_uv_var2_threshold ;
    QLineEdit *ptEdit_uv_var2_threshold ;

    QLabel *ptLabel_v_center ;
    QLineEdit *ptEdit_v_center ;

    QLabel *ptLabel_vmean1_offset ;
    QLineEdit *ptEdit_vmean1_offset ;

    QLabel *ptLabel_vmean1_slope ;
    QLineEdit *ptEdit_vmean1_slope ;

    QLabel *ptLabel_vmean1_threshold ;
    QLineEdit *ptEdit_vmean1_threshold ;

    QLabel *ptLabel_vmean2_offset ;
    QLineEdit *ptEdit_vmean2_offset ;

    QLabel *ptLabel_vmean2_slope ;
    QLineEdit *ptEdit_vmean2_slope ;

    QLabel *ptLabel_vmean2_threshold ;
    QLineEdit *ptEdit_vmean2_threshold ;

    QPushButton *ptPBtn;
signals:

public slots:
    void clickedSlot(bool checked);
};

#endif // ISPPPCNR_H
