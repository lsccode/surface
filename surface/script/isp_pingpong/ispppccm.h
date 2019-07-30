#ifndef ISPPPCCM_H
#define ISPPPCCM_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
class IspPPCcm : public QWidget
{
    Q_OBJECT
public:
    explicit IspPPCcm(QWidget *parent = 0);

public:
    QLabel *ptLabel_coefft_b_b;
    QLineEdit *ptEdit_coefft_b_b;

    QLabel *ptLabel_coefft_b_g;
    QLineEdit *ptEdit_coefft_b_g;

    QLabel *ptLabel_coefft_b_ir;
    QLineEdit *ptEdit_coefft_b_ir;

    QLabel *ptLabel_coefft_b_r;
    QLineEdit *ptEdit_coefft_b_r;

    QLabel *ptLabel_coefft_fog_offset_b;
    QLineEdit *ptEdit_coefft_fog_offset_b;

    QLabel *ptLabel_coefft_fog_offset_g;
    QLineEdit *ptEdit_coefft_fog_offset_g;

    QLabel *ptLabel_coefft_fog_offset_ir;
    QLineEdit *ptEdit_coefft_fog_offset_ir;

    QLabel *ptLabel_coefft_fog_offset_r;
    QLineEdit *ptEdit_coefft_fog_offset_r;

    QLabel *ptLabel_coefft_g_b;
    QLineEdit *ptEdit_coefft_g_b;

    QLabel *ptLabel_coefft_g_g;
    QLineEdit *ptEdit_coefft_g_g;

    QLabel *ptLabel_coefft_g_ir;
    QLineEdit *ptEdit_coefft_g_ir;

    QLabel *ptLabel_coefft_g_r;
    QLineEdit *ptEdit_coefft_g_r;

    QLabel *ptLabel_coefft_r_b;
    QLineEdit *ptEdit_coefft_r_b;

    QLabel *ptLabel_coefft_r_g;
    QLineEdit *ptEdit_coefft_r_g;

    QLabel *ptLabel_coefft_r_ir;
    QLineEdit *ptEdit_coefft_r_ir;

    QLabel *ptLabel_coefft_r_r;
    QLineEdit *ptEdit_coefft_r_r;

    QLabel *ptLabel_coefft_wb_b;
    QLineEdit *ptEdit_coefft_wb_b;

    QLabel *ptLabel_coefft_wb_g;
    QLineEdit *ptEdit_coefft_wb_g;

    QLabel *ptLabel_coefft_wb_ir;
    QLineEdit *ptEdit_coefft_wb_ir;

    QLabel *ptLabel_coefft_wb_r;
    QLineEdit *ptEdit_coefft_wb_r;

    QPushButton *ptPBtn;

signals:

public slots:
    void clickedSlot(bool checked = false);
};

#endif // ISPPPCCM_H
