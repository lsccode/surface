#include "ispppmesh_shading.h"
#include <QGridLayout>
IspPPmesh_shading::IspPPmesh_shading(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    // add edit
    ptLabel_mesh_reload  = new QLabel("mesh_reload :");
    ptEdit_mesh_reload  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_mesh_reload ,0,0);layoutGrid->addWidget(ptEdit_mesh_reload ,0,1);

    ptLabel_mesh_strength  = new QLabel("mesh_strength :");
    ptEdit_mesh_strength  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_mesh_strength ,1,0);layoutGrid->addWidget(ptEdit_mesh_strength ,1,1);

    ptLabel_reg_enable  = new QLabel("reg_enable :");
    ptEdit_reg_enable  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_enable ,2,0);layoutGrid->addWidget(ptEdit_reg_enable ,2,1);

    ptLabel_reg_mesh_alpha_bank_r  = new QLabel("reg_mesh_alpha_bank_r :");
    ptEdit_reg_mesh_alpha_bank_r  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_mesh_alpha_bank_r ,3,0);layoutGrid->addWidget(ptEdit_reg_mesh_alpha_bank_r ,3,1);

    ptLabel_reg_mesh_alpha_r  = new QLabel("reg_mesh_alpha_r :");
    ptEdit_reg_mesh_alpha_r  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_mesh_alpha_r ,4,0);layoutGrid->addWidget(ptEdit_reg_mesh_alpha_r ,4,1);

    ptCb_mesh_shading_ping_mem  = new QComboBox;
    ptEdit_mesh_shading_ping_mem = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_mesh_shading_ping_mem,5,0);layoutGrid->addWidget(ptEdit_mesh_shading_ping_mem,5,1);
    for(unsigned int i = 0;i < M_MESH_SHADING_PING_MEM_NUMBER; ++i)
    {
        QString str;
        str.sprintf("mesh_shading_ping_mem[%x]",i);
        ptCb_mesh_shading_ping_mem->addItem(str);
        szQStr_mesh_shading_ping_mem[i].sprintf("%x",i);
    }
    ptEdit_mesh_shading_ping_mem->setText(szQStr_mesh_shading_ping_mem[ptCb_mesh_shading_ping_mem->currentIndex()]);

    ptPBtn = new QPushButton("确定");
    layoutGrid->addWidget(ptPBtn,40,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

    connect(ptCb_mesh_shading_ping_mem,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_mesh_shading_ping_mem(int)));
    connect(ptEdit_mesh_shading_ping_mem,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_mesh_shading_ping_mem(const QString)));
    setLayout(mainLayout);
}

void IspPPmesh_shading::clickedSlot(bool checked)
{
    QString str_mesh_reload = ptEdit_mesh_reload->text();
    QString str_mesh_strength = ptEdit_mesh_strength->text();
    QString str_reg_enable = ptEdit_reg_enable->text();
    QString str_reg_mesh_alpha_bank_r = ptEdit_reg_mesh_alpha_bank_r->text();
    QString str_reg_mesh_alpha_r = ptEdit_reg_mesh_alpha_r->text();
}

void IspPPmesh_shading::activatedSlot_mesh_shading_ping_mem(int index)
{
    ptEdit_mesh_shading_ping_mem->setText(szQStr_mesh_shading_ping_mem[index]);
}

void IspPPmesh_shading::textChangedSlot_mesh_shading_ping_mem(const QString &text)
{
    int index = ptCb_mesh_shading_ping_mem->currentIndex();
    szQStr_mesh_shading_ping_mem[index] = text;
}
