#ifndef ISPPPWHITE_BALANCE_AEXP_H
#define ISPPPWHITE_BALANCE_AEXP_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class IspPPwhite_balance_aexp : public QWidget
{
    Q_OBJECT
public:
    explicit IspPPwhite_balance_aexp(QWidget *parent = 0);

public:
    QLabel *ptLabel_white_balance_aexpreg_gain_00 ;
    QLineEdit *ptEdit_white_balance_aexpreg_gain_00 ;

    QLabel *ptLabel_white_balance_aexpreg_gain_10 ;
    QLineEdit *ptEdit_white_balance_aexpreg_gain_10 ;

    QLabel *ptLabel_white_balancereg_gain_00 ;
    QLineEdit *ptEdit_white_balancereg_gain_00 ;

    QLabel *ptLabel_white_balancereg_gain_10 ;
    QLineEdit *ptEdit_white_balancereg_gain_10 ;

    QPushButton *ptPBtn;
signals:

public slots:
    void clickedSlot(bool checked = false);

};

#endif // ISPPPWHITE_BALANCE_AEXP_H
