#ifndef ISPPPSENSOR_OFFSET_H
#define ISPPPSENSOR_OFFSET_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

#include "script/ispcommonstep.h"

class IspPPsensor_offset : public QWidget,public IspCommonStep
{
    Q_OBJECT
public:
    explicit IspPPsensor_offset(QWidget *parent = 0);

public:
    QLabel *ptLabel_sensor_offset_feoffset_00 ;
    QLineEdit *ptEdit_sensor_offset_feoffset_00 ;

    QLabel *ptLabel_sensor_offset_feoffset_01 ;
    QLineEdit *ptEdit_sensor_offset_feoffset_01 ;

    QLabel *ptLabel_sensor_offset_feoffset_10 ;
    QLineEdit *ptEdit_sensor_offset_feoffset_10 ;

    QLabel *ptLabel_sensor_offset_feoffset_11 ;
    QLineEdit *ptEdit_sensor_offset_feoffset_11 ;

    QLabel *ptLabel_sensor_offset_pre_shadingoffset_00 ;
    QLineEdit *ptEdit_sensor_offset_pre_shadingoffset_00 ;

    QLabel *ptLabel_sensor_offset_pre_shadingoffset_01 ;
    QLineEdit *ptEdit_sensor_offset_pre_shadingoffset_01 ;

    QLabel *ptLabel_sensor_offset_pre_shadingoffset_10 ;
    QLineEdit *ptEdit_sensor_offset_pre_shadingoffset_10 ;

    QLabel *ptLabel_sensor_offset_pre_shadingoffset_11 ;
    QLineEdit *ptEdit_sensor_offset_pre_shadingoffset_11 ;

    QPushButton *ptPBtn;

public:
    virtual void step1();
signals:

public slots:
    void clickedSlot(bool checked = false);

};

#endif // ISPPPSENSOR_OFFSET_H
