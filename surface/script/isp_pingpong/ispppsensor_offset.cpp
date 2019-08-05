#include "ispppsensor_offset.h"
#include <QGridLayout>
IspPPsensor_offset::IspPPsensor_offset(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    // add edit
    ptLabel_sensor_offset_feoffset_00  = new QLabel("sensor_offset_feoffset_00 :");
    ptEdit_sensor_offset_feoffset_00  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_sensor_offset_feoffset_00 ,0,0);layoutGrid->addWidget(ptEdit_sensor_offset_feoffset_00 ,0,1);

    ptLabel_sensor_offset_feoffset_01  = new QLabel("sensor_offset_feoffset_01 :");
    ptEdit_sensor_offset_feoffset_01  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_sensor_offset_feoffset_01 ,1,0);layoutGrid->addWidget(ptEdit_sensor_offset_feoffset_01 ,1,1);

    ptLabel_sensor_offset_feoffset_10  = new QLabel("sensor_offset_feoffset_10 :");
    ptEdit_sensor_offset_feoffset_10  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_sensor_offset_feoffset_10 ,2,0);layoutGrid->addWidget(ptEdit_sensor_offset_feoffset_10 ,2,1);

    ptLabel_sensor_offset_feoffset_11  = new QLabel("sensor_offset_feoffset_11 :");
    ptEdit_sensor_offset_feoffset_11  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_sensor_offset_feoffset_11 ,3,0);layoutGrid->addWidget(ptEdit_sensor_offset_feoffset_11 ,3,1);

    ptLabel_sensor_offset_pre_shadingoffset_00  = new QLabel("sensor_offset_pre_shadingoffset_00 :");
    ptEdit_sensor_offset_pre_shadingoffset_00  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_sensor_offset_pre_shadingoffset_00 ,4,0);layoutGrid->addWidget(ptEdit_sensor_offset_pre_shadingoffset_00 ,4,1);

    ptLabel_sensor_offset_pre_shadingoffset_01  = new QLabel("sensor_offset_pre_shadingoffset_01 :");
    ptEdit_sensor_offset_pre_shadingoffset_01  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_sensor_offset_pre_shadingoffset_01 ,5,0);layoutGrid->addWidget(ptEdit_sensor_offset_pre_shadingoffset_01 ,5,1);

    ptLabel_sensor_offset_pre_shadingoffset_10  = new QLabel("sensor_offset_pre_shadingoffset_10 :");
    ptEdit_sensor_offset_pre_shadingoffset_10  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_sensor_offset_pre_shadingoffset_10 ,6,0);layoutGrid->addWidget(ptEdit_sensor_offset_pre_shadingoffset_10 ,6,1);

    ptLabel_sensor_offset_pre_shadingoffset_11  = new QLabel("sensor_offset_pre_shadingoffset_11 :");
    ptEdit_sensor_offset_pre_shadingoffset_11  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_sensor_offset_pre_shadingoffset_11 ,7,0);layoutGrid->addWidget(ptEdit_sensor_offset_pre_shadingoffset_11 ,7,1);

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

void IspPPsensor_offset::clickedSlot(bool checked)
{
    QString str_sensor_offset_feoffset_00 = ptEdit_sensor_offset_feoffset_00->text();
    QString str_sensor_offset_feoffset_01 = ptEdit_sensor_offset_feoffset_01->text();
    QString str_sensor_offset_feoffset_10 = ptEdit_sensor_offset_feoffset_10->text();
    QString str_sensor_offset_feoffset_11 = ptEdit_sensor_offset_feoffset_11->text();
    QString str_sensor_offset_pre_shadingoffset_00 = ptEdit_sensor_offset_pre_shadingoffset_00->text();
    QString str_sensor_offset_pre_shadingoffset_01 = ptEdit_sensor_offset_pre_shadingoffset_01->text();
    QString str_sensor_offset_pre_shadingoffset_10 = ptEdit_sensor_offset_pre_shadingoffset_10->text();
    QString str_sensor_offset_pre_shadingoffset_11 = ptEdit_sensor_offset_pre_shadingoffset_11->text();
}
