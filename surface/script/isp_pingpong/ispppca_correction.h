#ifndef ISPPPCA_CORRECTION_H
#define ISPPPCA_CORRECTION_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>

#include "script/ispcommonstep.h"

#define M_CA_CORRECTION_MESH_PING_MEM_NUM (0xfff + 1)
#define M_CA_CORRECTION_FILTER_PING_MEM_NUM (0x1f + 1)
class IspPPCa_correction : public QWidget,public IspCommonStep
{
    Q_OBJECT
public:
    explicit IspPPCa_correction(QWidget *parent = 0);
public:
    QLabel *ptLabel_mesh_reload;
    QLineEdit *ptEdit_mesh_reload;

    QLabel *ptLabel_reg_enable;
    QLineEdit *ptEdit_reg_enable;

    QLabel *ptLabel_reg_line_offset;
    QLineEdit *ptEdit_reg_line_offset;

    QLabel *ptLabel_reg_mesh_width;
    QLineEdit *ptEdit_reg_mesh_width;

    QComboBox *ptCb_ca_correction_mesh_ping_mem;
    QLineEdit *ptEdit_ca_correction_mesh_ping_mem;
    QString szQStr_ca_correction_mesh_ping_mem[M_CA_CORRECTION_MESH_PING_MEM_NUM];

    QComboBox *ptCb_ca_correction_filter_ping_mem;
    QLineEdit *ptEdit_ca_correction_filter_ping_mem;
    QString szQStr_ca_correction_filter_ping_mem[M_CA_CORRECTION_FILTER_PING_MEM_NUM];

    QPushButton *ptPBtn;

public:
    void init_array();
    void init_ca_correction_mesh_ping_mem();
    void init_ca_correction_filter_ping_mem();
    virtual void step1();
signals:

public slots:
    void clickedSlot(bool checked = false);

    void activatedSlot_mesh_ping(int index);
    void textChangedSlot_mesh_ping(const QString & text);

    void activatedSlot_filter_ping(int index);
    void textChangedSlot_filter_ping(const QString & text);
};

#endif // ISPPPCA_CORRECTION_H
