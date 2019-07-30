#include "ispppccm.h"
#include <QGridLayout>
IspPPCcm::IspPPCcm(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    ptLabel_coefft_b_b = new QLabel("coefft_b_b:");
    ptEdit_coefft_b_b  = new QLineEdit("00000149");
    layoutGrid->addWidget(ptLabel_coefft_b_b,0,0);layoutGrid->addWidget(ptEdit_coefft_b_b,0,1);

    ptLabel_coefft_b_g = new QLabel("coefft_b_g:");
    ptEdit_coefft_b_g  = new QLineEdit("00000149");
    layoutGrid->addWidget(ptLabel_coefft_b_g,1,0);layoutGrid->addWidget(ptEdit_coefft_b_g,1,1);

    ptLabel_coefft_b_ir = new QLabel("coefft_b_ir:");
    ptEdit_coefft_b_ir  = new QLineEdit("00000149");
    layoutGrid->addWidget(ptLabel_coefft_b_ir,2,0);layoutGrid->addWidget(ptEdit_coefft_b_ir,2,1);

    ptLabel_coefft_b_r = new QLabel("coefft_b_r:");
    ptEdit_coefft_b_r  = new QLineEdit("00000149");
    layoutGrid->addWidget(ptLabel_coefft_b_r,3,0);layoutGrid->addWidget(ptEdit_coefft_b_r,3,1);

    ptLabel_coefft_fog_offset_b = new QLabel("coefft_fog_offset_b:");
    ptEdit_coefft_fog_offset_b  = new QLineEdit("00000149");
    layoutGrid->addWidget(ptLabel_coefft_fog_offset_b,4,0);layoutGrid->addWidget(ptEdit_coefft_fog_offset_b,4,1);

    ptLabel_coefft_fog_offset_g = new QLabel("coefft_fog_offset_g:");
    ptEdit_coefft_fog_offset_g  = new QLineEdit("00000149");
    layoutGrid->addWidget(ptLabel_coefft_fog_offset_g,5,0);layoutGrid->addWidget(ptEdit_coefft_fog_offset_g,5,1);

    ptLabel_coefft_fog_offset_ir = new QLabel("coefft_fog_offset_ir:");
    ptEdit_coefft_fog_offset_ir  = new QLineEdit("00000149");
    layoutGrid->addWidget(ptLabel_coefft_fog_offset_ir,6,0);layoutGrid->addWidget(ptEdit_coefft_fog_offset_ir,6,1);

    ptLabel_coefft_fog_offset_r = new QLabel("coefft_fog_offset_r:");
    ptEdit_coefft_fog_offset_r  = new QLineEdit("00000149");
    layoutGrid->addWidget(ptLabel_coefft_fog_offset_r,7,0);layoutGrid->addWidget(ptEdit_coefft_fog_offset_r,7,1);

    ptLabel_coefft_g_b = new QLabel("coefft_g_b:");
    ptEdit_coefft_g_b  = new QLineEdit("00000149");
    layoutGrid->addWidget(ptLabel_coefft_g_b,8,0);layoutGrid->addWidget(ptEdit_coefft_g_b,8,1);

    ptLabel_coefft_g_g = new QLabel("coefft_g_g:");
    ptEdit_coefft_g_g  = new QLineEdit("00000149");
    layoutGrid->addWidget(ptLabel_coefft_g_g,9,0);layoutGrid->addWidget(ptEdit_coefft_g_g,9,1);

    ptLabel_coefft_g_ir = new QLabel("coefft_g_ir:");
    ptEdit_coefft_g_ir  = new QLineEdit("00000149");
    layoutGrid->addWidget(ptLabel_coefft_g_ir,10,0);layoutGrid->addWidget(ptEdit_coefft_g_ir,10,1);

    ptLabel_coefft_g_r = new QLabel("coefft_g_r:");
    ptEdit_coefft_g_r  = new QLineEdit("00000149");
    layoutGrid->addWidget(ptLabel_coefft_g_r,11,0);layoutGrid->addWidget(ptEdit_coefft_g_r,11,1);

    ptLabel_coefft_r_b = new QLabel("coefft_r_b:");
    ptEdit_coefft_r_b  = new QLineEdit("00000149");
    layoutGrid->addWidget(ptLabel_coefft_r_b,12,0);layoutGrid->addWidget(ptEdit_coefft_r_b,12,1);

    ptLabel_coefft_r_g = new QLabel("coefft_r_g:");
    ptEdit_coefft_r_g  = new QLineEdit("00000149");
    layoutGrid->addWidget(ptLabel_coefft_r_g,13,0);layoutGrid->addWidget(ptEdit_coefft_r_g,13,1);

    ptLabel_coefft_r_ir = new QLabel("coefft_r_ir:");
    ptEdit_coefft_r_ir  = new QLineEdit("00000149");
    layoutGrid->addWidget(ptLabel_coefft_r_ir,14,0);layoutGrid->addWidget(ptEdit_coefft_r_ir,14,1);

    ptLabel_coefft_r_r = new QLabel("coefft_r_r:");
    ptEdit_coefft_r_r  = new QLineEdit("00000149");
    layoutGrid->addWidget(ptLabel_coefft_r_r,15,0);layoutGrid->addWidget(ptEdit_coefft_r_r,15,1);

    ptLabel_coefft_wb_b = new QLabel("coefft_wb_b:");
    ptEdit_coefft_wb_b  = new QLineEdit("00000149");
    layoutGrid->addWidget(ptLabel_coefft_wb_b,16,0);layoutGrid->addWidget(ptEdit_coefft_wb_b,16,1);

    ptLabel_coefft_wb_g = new QLabel("coefft_wb_g:");
    ptEdit_coefft_wb_g  = new QLineEdit("00000149");
    layoutGrid->addWidget(ptLabel_coefft_wb_g,17,0);layoutGrid->addWidget(ptEdit_coefft_wb_g,17,1);

    ptLabel_coefft_wb_ir = new QLabel("coefft_wb_ir:");
    ptEdit_coefft_wb_ir  = new QLineEdit("00000149");
    layoutGrid->addWidget(ptLabel_coefft_wb_ir,18,0);layoutGrid->addWidget(ptEdit_coefft_wb_ir,18,1);

    ptLabel_coefft_wb_r = new QLabel("coefft_wb_r:");
    ptEdit_coefft_wb_r  = new QLineEdit("00000149");
    layoutGrid->addWidget(ptLabel_coefft_wb_r,19,0);layoutGrid->addWidget(ptEdit_coefft_wb_r,19,1);

    ptPBtn = new QPushButton("确定");
    layoutGrid->addWidget(ptPBtn,20,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

    setLayout(mainLayout);
}

void IspPPCcm::clickedSlot(bool checked)
{

    QString str_coefft_b_b = ptEdit_coefft_b_b->text();
    QString str_coefft_b_g = ptEdit_coefft_b_g->text();
    QString str_coefft_b_ir = ptEdit_coefft_b_ir->text();
    QString str_coefft_b_r = ptEdit_coefft_b_r->text();
    QString str_coefft_fog_offset_b = ptEdit_coefft_fog_offset_b->text();
    QString str_coefft_fog_offset_g = ptEdit_coefft_fog_offset_g->text();
    QString str_coefft_fog_offset_ir = ptEdit_coefft_fog_offset_ir->text();
    QString str_coefft_fog_offset_r = ptEdit_coefft_fog_offset_r->text();
    QString str_coefft_g_b = ptEdit_coefft_g_b->text();
    QString str_coefft_g_g = ptEdit_coefft_g_g->text();
    QString str_coefft_g_ir = ptEdit_coefft_g_ir->text();
    QString str_coefft_g_r = ptEdit_coefft_g_r->text();
    QString str_coefft_r_b = ptEdit_coefft_r_b->text();
    QString str_coefft_r_g = ptEdit_coefft_r_g->text();
    QString str_coefft_r_ir = ptEdit_coefft_r_ir->text();
    QString str_coefft_r_ = ptEdit_coefft_r_r->text();
    QString str_coefft_wb_b = ptEdit_coefft_wb_b->text();
    QString str_coefft_wb_g = ptEdit_coefft_wb_g->text();
    QString str_coefft_wb_ir = ptEdit_coefft_wb_ir->text();
    QString str_coefft_wb_r = ptEdit_coefft_wb_r->text();
}
