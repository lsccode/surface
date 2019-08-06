#ifndef ISPCMGLOBAL_H
#define ISPCMGLOBAL_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "script/ispcommonstep.h"

class IspCmGlobal : public QWidget,public IspCommonStep
{
    Q_OBJECT
public:
    explicit IspCmGlobal(QWidget *parent = 0);

public:
    QLabel *ptLabel_chickBit_reg_frame_end_select;
    QLineEdit *ptEdit_chickBit_reg_frame_end_select;

    QLabel *ptLabel_interrupt_clear;
    QLineEdit *ptEdit_interrupt_clear;

    QLabel *ptLabel_interrupt_clear_vector;
    QLineEdit *ptEdit_interrupt_clear_vector;

    QLabel *ptLabel_mcu_ping_pong_config_select;
    QLineEdit *ptEdit_mcu_ping_pong_config_select;

    QLabel *ptLabel_reg_flush_hblank;
    QLineEdit *ptEdit_reg_flush_hblank;

    QLabel *ptLabel_reg_global_fsm_reset;
    QLineEdit *ptEdit_reg_global_fsm_reset;

    QLabel *ptLabel_reg_mcu_override_config_select;
    QLineEdit *ptEdit_reg_mcu_override_config_select;

    QLabel *ptLabel_watchdog_timer_max_count;
    QLineEdit *ptEdit_watchdog_timer_max_count;

    QPushButton *ptPBtn;

public:
    QString str_chickBit_reg_frame_end_select ;
    QString str_interrupt_clear;
    QString str_interrupt_clear_vector;
    QString str_mcu_ping_pong_config_select;
    QString str_reg_flush_hblank;
    QString str_reg_global_fsm_reset;
    QString str_reg_mcu_override_config_select;
    QString str_watchdog_timer_max_count;
public:
    virtual void step1();
    virtual void step2();
    virtual void step3();

signals:

public slots:
    void clickedSlot(bool checked = false);

};

#endif // ISPCMGLOBAL_H
