#ifndef ISPPPRADIAL_SHADING_H
#define ISPPPRADIAL_SHADING_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>

#define M_RADIAL_SHADING_PING_MEM_NUMBER (0x380+1)

class IspPPradial_shading : public QWidget
{
    Q_OBJECT
public:
    explicit IspPPradial_shading(QWidget *parent = 0);

public:
    QLabel *ptLabel_enable ;
    QLineEdit *ptEdit_enable ;

    QLabel *ptLabel_reg_centerb_x ;
    QLineEdit *ptEdit_reg_centerb_x ;

    QLabel *ptLabel_reg_centerg_x ;
    QLineEdit *ptEdit_reg_centerg_x ;

    QLabel *ptLabel_reg_centerir_x ;
    QLineEdit *ptEdit_reg_centerir_x ;

    QLabel *ptLabel_reg_centerr_x ;
    QLineEdit *ptEdit_reg_centerr_x ;

    QLabel *ptLabel_reg_off_center_multbx ;
    QLineEdit *ptEdit_reg_off_center_multbx ;

    QLabel *ptLabel_reg_off_center_multgx ;
    QLineEdit *ptEdit_reg_off_center_multgx ;

    QLabel *ptLabel_reg_off_center_multirx ;
    QLineEdit *ptEdit_reg_off_center_multirx ;

    QLabel *ptLabel_reg_off_center_multrx ;
    QLineEdit *ptEdit_reg_off_center_multrx ;

    QComboBox *ptCb_radial_shading_ping_mem;
    QLineEdit *ptEdit_radial_shading_ping_mem;
    QString szQStr_radial_shading_ping_mem[M_RADIAL_SHADING_PING_MEM_NUMBER];

    QPushButton *ptPBtn;
signals:

public slots:
    void clickedSlot(bool checked = false);
    void activatedSlot_radial_shading_ping_mem(int index);
    void textChangedSlot_radial_shading_ping_mem(const QString &text);
};

#endif // ISPPPRADIAL_SHADING_H
