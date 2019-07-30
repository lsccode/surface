#include <QGridLayout>
#include "ispcmglobal.h"

IspCmGlobal::IspCmGlobal(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    ptLabel_chickBit_reg_frame_end_select = new QLabel("chicken_bit.reg_frame_end_select:");
    ptEdit_chickBit_reg_frame_end_select  = new QLineEdit("00000006");
    layoutGrid->addWidget(ptLabel_chickBit_reg_frame_end_select,1,0);layoutGrid->addWidget(ptEdit_chickBit_reg_frame_end_select,1,1);

    ptLabel_interrupt_clear = new QLabel("interrupt.clear:");
    ptEdit_interrupt_clear  = new QLineEdit("00000001");
    layoutGrid->addWidget(ptLabel_interrupt_clear,0,0);layoutGrid->addWidget(ptEdit_interrupt_clear,0,1);

    ptLabel_interrupt_clear_vector = new QLabel("interrupt.clear_vector:");
    ptEdit_interrupt_clear_vector  = new QLineEdit("00000200");
    layoutGrid->addWidget(ptLabel_interrupt_clear_vector,2,0);layoutGrid->addWidget(ptEdit_interrupt_clear_vector,2,1);

    ptLabel_mcu_ping_pong_config_select = new QLabel("mcu_ping_pong_config_select:");
    ptEdit_mcu_ping_pong_config_select  = new QLineEdit("00000000");
    layoutGrid->addWidget(ptLabel_mcu_ping_pong_config_select,3,0);layoutGrid->addWidget(ptEdit_mcu_ping_pong_config_select,3,1);

    ptLabel_reg_flush_hblank = new QLabel("reg_flush_hblank:");
    ptEdit_reg_flush_hblank  = new QLineEdit("00000020");
    layoutGrid->addWidget(ptLabel_reg_flush_hblank,4,0);layoutGrid->addWidget(ptEdit_reg_flush_hblank,4,1);

    ptLabel_reg_global_fsm_reset = new QLabel("reg_global_fsm_reset:");
    ptEdit_reg_global_fsm_reset  = new QLineEdit("00000030");
    layoutGrid->addWidget(ptLabel_reg_global_fsm_reset,5,0);layoutGrid->addWidget(ptEdit_reg_global_fsm_reset,5,1);

    ptLabel_reg_mcu_override_config_select = new QLabel("reg_mcu_override_config_select:");
    ptEdit_reg_mcu_override_config_select  = new QLineEdit("00000001");
    layoutGrid->addWidget(ptLabel_reg_mcu_override_config_select,6,0);layoutGrid->addWidget(ptEdit_reg_mcu_override_config_select,6,1);

    ptLabel_watchdog_timer_max_count = new QLabel("watchdog_timer_max_count:");
    ptEdit_watchdog_timer_max_count  = new QLineEdit("02160ec0");
    layoutGrid->addWidget(ptLabel_watchdog_timer_max_count,7,0);layoutGrid->addWidget(ptEdit_watchdog_timer_max_count,7,1);

    ptPBtn = new QPushButton("确定");
    layoutGrid->addWidget(ptPBtn,8,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

    setLayout(mainLayout);

    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));
}

void IspCmGlobal::clickedSlot(bool checked)
{
    QString str_chickBit_reg_frame_end_select = ptEdit_chickBit_reg_frame_end_select->text();
    QString str_interrupt_clear = ptEdit_interrupt_clear->text();
    QString str_interrupt_clear_vector = ptEdit_interrupt_clear_vector->text();
    QString str_mcu_ping_pong_config_select = ptEdit_mcu_ping_pong_config_select->text();
    QString str_reg_flush_hblank = ptEdit_reg_flush_hblank->text();
    QString str_reg_global_fsm_reset = ptEdit_reg_global_fsm_reset->text();
    QString str_reg_mcu_override_config_select = ptEdit_reg_mcu_override_config_select->text();
    QString str_watchdog_timer_max_count = ptEdit_watchdog_timer_max_count->text();

    return;
}
