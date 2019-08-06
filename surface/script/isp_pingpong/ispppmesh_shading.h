#ifndef ISPPPMESH_SHADING_H
#define ISPPPMESH_SHADING_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>

#include "script/ispcommonstep.h"

#define M_MESH_SHADING_PING_MEM_NUMBER (0xfff+1)

class IspPPmesh_shading : public QWidget,public IspCommonStep
{
    Q_OBJECT
public:
    explicit IspPPmesh_shading(QWidget *parent = 0);
public:
    QLabel *ptLabel_mesh_reload ;
    QLineEdit *ptEdit_mesh_reload ;

    QLabel *ptLabel_mesh_strength ;
    QLineEdit *ptEdit_mesh_strength ;

    QLabel *ptLabel_reg_enable ;
    QLineEdit *ptEdit_reg_enable ;

    QLabel *ptLabel_reg_mesh_alpha_bank_r ;
    QLineEdit *ptEdit_reg_mesh_alpha_bank_r ;

    QLabel *ptLabel_reg_mesh_alpha_r ;
    QLineEdit *ptEdit_reg_mesh_alpha_r ;

    QComboBox *ptCb_mesh_shading_ping_mem;
    QLineEdit *ptEdit_mesh_shading_ping_mem;
    QString szQStr_mesh_shading_ping_mem[M_MESH_SHADING_PING_MEM_NUMBER];

    QPushButton *ptPBtn;

public:
    void init_array();
    virtual void step1();
signals:

public slots:
    void clickedSlot(bool checked = false);
    void activatedSlot_mesh_shading_ping_mem(int index);
    void textChangedSlot_mesh_shading_ping_mem(const QString &text);
};

#endif // ISPPPMESH_SHADING_H
