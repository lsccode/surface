#ifndef ISPPPTOP_H
#define ISPPPTOP_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class IspPPtop : public QWidget
{
    Q_OBJECT
public:
    explicit IspPPtop(QWidget *parent = 0);

public:
    QLabel *ptLabel_reg_active_width ;
    QLineEdit *ptEdit_reg_active_width ;

    QLabel *ptLabel_reg_ae_5bin_hist_disable ;
    QLineEdit *ptEdit_reg_ae_5bin_hist_disable ;

    QLabel *ptLabel_reg_bypass_digital_gain ;
    QLineEdit *ptEdit_reg_bypass_digital_gain ;

    QLabel *ptLabel_reg_bypass_ds_crop ;
    QLineEdit *ptEdit_reg_bypass_ds_crop ;

    QLabel *ptLabel_reg_bypass_fr_crop ;
    QLineEdit *ptEdit_reg_bypass_fr_crop ;

    QLabel *ptLabel_reg_bypass_sinter ;
    QLineEdit *ptEdit_reg_bypass_sinter ;

    QLabel *ptLabel_reg_bypass_square_be ;
    QLineEdit *ptEdit_reg_bypass_square_be ;

    QLabel *ptLabel_reg_bypass_video_test_gen ;
    QLineEdit *ptEdit_reg_bypass_video_test_gen ;

    QLabel *ptLabel_reg_rggb_start_pre_mirror ;
    QLineEdit *ptEdit_reg_rggb_start_pre_mirror ;
    QPushButton *ptPBtn;
signals:

public slots:
    void clickedSlot(bool checked = false);

};

#endif // ISPPPTOP_H
