#ifndef ISPPPINPUT_FORMATTER_H
#define ISPPPINPUT_FORMATTER_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class IspPPinput_formatter : public QWidget
{
    Q_OBJECT
public:
    explicit IspPPinput_formatter(QWidget *parent = 0);

public:
    QLabel *ptLabel_black_level ;
    QLineEdit *ptEdit_black_level ;

    QLabel *ptLabel_factor_ml ;
    QLineEdit *ptEdit_factor_ml ;

    QLabel *ptLabel_factor_ms ;
    QLineEdit *ptEdit_factor_ms ;

    QLabel *ptLabel_knee_point2 ;
    QLineEdit *ptEdit_knee_point2 ;

    QLabel *ptLabel_reg_knee_point0 ;
    QLineEdit *ptEdit_reg_knee_point0 ;

    QLabel *ptLabel_reg_mode_in ;
    QLineEdit *ptEdit_reg_mode_in ;

    QLabel *ptLabel_reg_slope0_select ;
    QLineEdit *ptEdit_reg_slope0_select ;

    QPushButton *ptPBtn;
signals:

public slots:
    void clickedSlot(bool checked = false);

};

#endif // ISPPPINPUT_FORMATTER_H
