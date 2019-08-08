#include <QGridLayout>
#include <QMessageBox>

#include "ispcmglobal.h"

IspCmGlobal::IspCmGlobal(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    ptLabel_chickBit_reg_frame_end_select = new QLabel("chicken_bit.reg_frame_end_select:");
    ptEdit_chickBit_reg_frame_end_select  = new QLineEdit("00000016");
    layoutGrid->addWidget(ptLabel_chickBit_reg_frame_end_select,1,0);layoutGrid->addWidget(ptEdit_chickBit_reg_frame_end_select,1,1);

    ptLabel_interrupt_clear = new QLabel("interrupt.clear:");
    ptEdit_interrupt_clear  = new QLineEdit("00000001");
    layoutGrid->addWidget(ptLabel_interrupt_clear,0,0);layoutGrid->addWidget(ptEdit_interrupt_clear,0,1);

    ptLabel_interrupt_clear_vector = new QLabel("interrupt.clear_vector:");
    ptEdit_interrupt_clear_vector  = new QLineEdit("00000200");
    layoutGrid->addWidget(ptLabel_interrupt_clear_vector,2,0);layoutGrid->addWidget(ptEdit_interrupt_clear_vector,2,1);

    ptLabel_mcu_ping_pong_config_select = new QLabel("mcu_ping_pong_config_select:");
    ptEdit_mcu_ping_pong_config_select  = new QLineEdit("00000001");
    layoutGrid->addWidget(ptLabel_mcu_ping_pong_config_select,3,0);layoutGrid->addWidget(ptEdit_mcu_ping_pong_config_select,3,1);

    ptLabel_reg_flush_hblank = new QLabel("reg_flush_hblank:");
    ptEdit_reg_flush_hblank  = new QLineEdit("00000020");
    layoutGrid->addWidget(ptLabel_reg_flush_hblank,4,0);layoutGrid->addWidget(ptEdit_reg_flush_hblank,4,1);

    ptLabel_reg_global_fsm_reset = new QLabel("reg_global_fsm_reset:");
    ptEdit_reg_global_fsm_reset  = new QLineEdit("00000030");
    layoutGrid->addWidget(ptLabel_reg_global_fsm_reset,5,0);layoutGrid->addWidget(ptEdit_reg_global_fsm_reset,5,1);

    ptLabel_reg_mcu_override_config_select = new QLabel("reg_mcu_override_config_select:");
    ptEdit_reg_mcu_override_config_select  = new QLineEdit("00000003");
    layoutGrid->addWidget(ptLabel_reg_mcu_override_config_select,6,0);layoutGrid->addWidget(ptEdit_reg_mcu_override_config_select,6,1);

    ptLabel_watchdog_timer_max_count = new QLabel("watchdog_timer_max_count:");
    ptEdit_watchdog_timer_max_count  = new QLineEdit("02160ec0");
    layoutGrid->addWidget(ptLabel_watchdog_timer_max_count,7,0);layoutGrid->addWidget(ptEdit_watchdog_timer_max_count,7,1);

    ptLabel_input_frame = new QLabel("input frame:");
    ptEdit_input_frame  = new QLineEdit("model_input_frame0.frm");
    layoutGrid->addWidget(ptLabel_input_frame,8,0);layoutGrid->addWidget(ptEdit_input_frame,8,1);

//    ptPBtn = new QPushButton("确定");
//    layoutGrid->addWidget(ptPBtn,8,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

    setLayout(mainLayout);

    //    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));
}

int IspCmGlobal::checkInputFrame()
{
    QString strInputFileName = ptEdit_input_frame->text();

    if(strInputFileName.length() == 0)
    {
        QMessageBox msgBox;
        msgBox.setText(tr("input frame must set!"));
        ptEdit_input_frame->setStyleSheet("QLineEdit {background-color: red;}");  // "background-color:rgb(139,28,98)"
        msgBox.exec();
        return -1;
    }

    ptEdit_input_frame->setStyleSheet("QLineEdit {background-color:rgb(24,30,41)}");

    return 0;
}

void IspCmGlobal::step1()
{
    writeLine(E_ACTION_RR,"isp_common.isp_global_interrupt.status_vector");

    writeLine(E_ACTION_WR,"isp_common.isp_global_interrupt.clear_vector",ptEdit_interrupt_clear_vector->text());
    writeLine(E_ACTION_RR,"isp_common.isp_global_interrupt.clear_vector");

    writeLine(E_ACTION_WR,"isp_common.isp_global_interrupt.clear",ptEdit_interrupt_clear->text());
    writeLine(E_ACTION_RR,"isp_common.isp_global_interrupt.clear");

    writeLine(E_ACTION_WR,"isp_common.isp_global_interrupt.clear","00000000");
    writeLine(E_ACTION_RR,"isp_common.isp_global_interrupt.clear");

    writeLine(E_ACTION_RR,"isp_common.isp_global_interrupt.status_vector");

    writeLine(E_ACTION_WR,"isp_common.isp_global_interrupt.clear_vector","00000000");
    writeLine(E_ACTION_RR,"isp_common.isp_global_interrupt.clear_vector");

    writeLine(E_ACTION_WR,"isp_common.isp_global_interrupt.clear",ptEdit_interrupt_clear->text());
    writeLine(E_ACTION_RR,"isp_common.isp_global_interrupt.clear");

    writeLine(E_ACTION_WR,"isp_common.isp_global_interrupt.clear","00000000");
    writeLine(E_ACTION_RR,"isp_common.isp_global_interrupt.clear");

    writeLine(E_ACTION_WR,"isp_common.isp_global.watchdog_timer_max_count",ptEdit_watchdog_timer_max_count->text());
    writeLine(E_ACTION_RR,"isp_common.isp_global.watchdog_timer_max_count");

    writeLine(E_ACTION_WR,"isp_common.isp_global.reg_mcu_override_config_select","00000001");
    writeLine(E_ACTION_RR,"isp_common.isp_global.reg_mcu_override_config_select");

    writeLine(E_ACTION_WR,"isp_common.isp_global.reg_flush_hblank",ptEdit_reg_flush_hblank->text());
    writeLine(E_ACTION_RR,"isp_common.isp_global.reg_flush_hblank");

    writeLine(E_ACTION_WR,"isp_common.isp_global.reg_global_fsm_reset",ptEdit_reg_global_fsm_reset->text());
    writeLine(E_ACTION_RR,"isp_common.isp_global.reg_global_fsm_reset");
}

void IspCmGlobal::step2()
{
    writeLine(E_ACTION_WR,"isp_common.isp_global_chicken_bit.reg_frame_end_select","00000006");
    writeLine(E_ACTION_RR,"isp_common.isp_global_chicken_bit.reg_frame_end_select");

    writeLine(E_ACTION_WR,"isp_common.isp_global_chicken_bit.reg_frame_end_select",ptEdit_chickBit_reg_frame_end_select->text());
    writeLine(E_ACTION_RR,"isp_common.isp_global_chicken_bit.reg_frame_end_select");
}

void IspCmGlobal::step3()
{
    writeLine(E_ACTION_WR,"isp_common.isp_global.reg_mcu_override_config_select",ptEdit_reg_mcu_override_config_select->text());
    writeLine(E_ACTION_RR,"isp_common.isp_global.reg_mcu_override_config_select");
}

void IspCmGlobal::step4()
{
    QString szStr_status_vector[7];
    szStr_status_vector[0] = "00000001";
    szStr_status_vector[1] = "00000000";
    szStr_status_vector[2] = "00004000";
    szStr_status_vector[3] = "00000000";
    szStr_status_vector[4] = "00008000";
    szStr_status_vector[5] = "00000000";
    szStr_status_vector[6] = "00000020";

    for(int i = 0; i < 7; ++i)
    {
        writeLine(E_ACTION_RR,"isp_common.isp_global_interrupt.status_vector");

        writeLine(E_ACTION_WR,"isp_common.isp_global_interrupt.clear_vector",szStr_status_vector[i]);
        writeLine(E_ACTION_RR,"isp_common.isp_global_interrupt.clear_vector");

        writeLine(E_ACTION_WR,"isp_common.isp_global_interrupt.clear",ptEdit_interrupt_clear->text());
        writeLine(E_ACTION_RR,"isp_common.isp_global_interrupt.clear");

        writeLine(E_ACTION_WR,"isp_common.isp_global_interrupt.clear","00000000");
        writeLine(E_ACTION_RR,"isp_common.isp_global_interrupt.clear");
    }

}

void IspCmGlobal::step5()
{
    QString strInputFileName = ptEdit_input_frame->text();
    QString strOutputFileName = "out_" + strInputFileName;

    writeLine(E_ACTION_RR,"isp_common.isp_global_interrupt.status_vector");
    writeLine(E_ACTION_WR,"isp_common.isp_global.mcu_ping_pong_config_select","00000001");
    writeLine(E_ACTION_RR,"isp_common.isp_global.mcu_ping_pong_config_select");

    writeLine(E_ACTION_INDATA,strInputFileName);
    writeLine(E_ACTION_OUTDATA,strOutputFileName);

    writeLine(E_ACTION_PROCESS);
    writeLine(E_ACTION_WR,"isp_common.isp_global_interrupt.clear_vector","002715d2");
    writeLine(E_ACTION_RR,"isp_common.isp_global_interrupt.clear_vector");

    writeLine(E_ACTION_WR,"isp_common.isp_global_interrupt.clear",ptEdit_interrupt_clear->text());
    writeLine(E_ACTION_RR,"isp_common.isp_global_interrupt.clear");

    writeLine(E_ACTION_WR,"isp_common.isp_global_interrupt.clear","00000000");
    writeLine(E_ACTION_RR,"isp_common.isp_global_interrupt.clear");
}

void IspCmGlobal::clickedSlot(bool checked)
{
    str_chickBit_reg_frame_end_select = ptEdit_chickBit_reg_frame_end_select->text();
    str_interrupt_clear = ptEdit_interrupt_clear->text();
    str_interrupt_clear_vector = ptEdit_interrupt_clear_vector->text();
    str_mcu_ping_pong_config_select = ptEdit_mcu_ping_pong_config_select->text();
    str_reg_flush_hblank = ptEdit_reg_flush_hblank->text();
    str_reg_global_fsm_reset = ptEdit_reg_global_fsm_reset->text();
    str_reg_mcu_override_config_select = ptEdit_reg_mcu_override_config_select->text();
    str_watchdog_timer_max_count = ptEdit_watchdog_timer_max_count->text();

    return;
}
