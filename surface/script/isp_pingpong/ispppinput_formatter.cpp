#include "ispppinput_formatter.h"
#include <QGridLayout>
IspPPinput_formatter::IspPPinput_formatter(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    // add edit
    ptLabel_black_level  = new QLabel("black_level :");
    ptEdit_black_level  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_black_level ,0,0);layoutGrid->addWidget(ptEdit_black_level ,0,1);

    ptLabel_factor_ml  = new QLabel("factor_ml :");
    ptEdit_factor_ml  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_factor_ml ,1,0);layoutGrid->addWidget(ptEdit_factor_ml ,1,1);

    ptLabel_factor_ms  = new QLabel("factor_ms :");
    ptEdit_factor_ms  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_factor_ms ,2,0);layoutGrid->addWidget(ptEdit_factor_ms ,2,1);

    ptLabel_knee_point2  = new QLabel("knee_point2 :");
    ptEdit_knee_point2  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_knee_point2 ,3,0);layoutGrid->addWidget(ptEdit_knee_point2 ,3,1);

    ptLabel_reg_knee_point0  = new QLabel("reg_knee_point0 :");
    ptEdit_reg_knee_point0  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_knee_point0 ,4,0);layoutGrid->addWidget(ptEdit_reg_knee_point0 ,4,1);

    ptLabel_reg_mode_in  = new QLabel("reg_mode_in :");
    ptEdit_reg_mode_in  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_mode_in ,5,0);layoutGrid->addWidget(ptEdit_reg_mode_in ,5,1);

    ptLabel_reg_slope0_select  = new QLabel("reg_slope0_select :");
    ptEdit_reg_slope0_select  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_slope0_select ,6,0);layoutGrid->addWidget(ptEdit_reg_slope0_select ,6,1);

    ptPBtn = new QPushButton("确定");
    layoutGrid->addWidget(ptPBtn,40,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

    setLayout(mainLayout);
}

void IspPPinput_formatter::clickedSlot(bool checked)
{
    QString str_black_level = ptEdit_black_level->text();
    QString str_factor_ml = ptEdit_factor_ml->text();
    QString str_factor_ms = ptEdit_factor_ms->text();
    QString str_knee_point2 = ptEdit_knee_point2->text();
    QString str_reg_knee_point0 = ptEdit_reg_knee_point0->text();
    QString str_reg_mode_in = ptEdit_reg_mode_in->text();
    QString str_reg_slope0_select = ptEdit_reg_slope0_select->text();
}
