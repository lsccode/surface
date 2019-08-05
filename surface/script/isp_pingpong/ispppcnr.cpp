#include "ispppcnr.h"
#include <QGridLayout>
IspPPCnr::IspPPCnr(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    ptLabel_delta_factor  = new QLabel(tr("delta_factor :"));
    ptEdit_delta_factor  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_delta_factor ,0,0);layoutGrid->addWidget(ptEdit_delta_factor ,0,1);

    ptLabel_effective_kernel  = new QLabel("effective_kernel :");
    ptEdit_effective_kernel  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_effective_kernel ,0,2);layoutGrid->addWidget(ptEdit_effective_kernel ,0,3);

    ptLabel_enable  = new QLabel("enable :");
    ptEdit_enable  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_enable ,1,0);layoutGrid->addWidget(ptEdit_enable ,1,1);

    ptLabel_global_offset  = new QLabel("global_offset :");
    ptEdit_global_offset  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_global_offset ,1,2);layoutGrid->addWidget(ptEdit_global_offset ,1,3);

    ptLabel_global_slope  = new QLabel("global_slope :");
    ptEdit_global_slope  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_global_slope ,2,0);layoutGrid->addWidget(ptEdit_global_slope ,2,1);

    ptLabel_reg_uv_var1_scale  = new QLabel("reg_uv_var1_scale :");
    ptEdit_reg_uv_var1_scale  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_uv_var1_scale ,2,2);layoutGrid->addWidget(ptEdit_reg_uv_var1_scale ,2,3);

    ptLabel_u_center  = new QLabel("u_center :");
    ptEdit_u_center  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_u_center ,3,0);layoutGrid->addWidget(ptEdit_u_center ,3,1);

    ptLabel_umean1_offset  = new QLabel("umean1_offset :");
    ptEdit_umean1_offset  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_umean1_offset ,3,2);layoutGrid->addWidget(ptEdit_umean1_offset ,3,3);

    ptLabel_umean1_slope  = new QLabel("umean1_slope :");
    ptEdit_umean1_slope  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_umean1_slope ,4,0);layoutGrid->addWidget(ptEdit_umean1_slope ,4,1);

    ptLabel_umean1_threshold  = new QLabel("umean1_threshold :");
    ptEdit_umean1_threshold  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_umean1_threshold ,4,2);layoutGrid->addWidget(ptEdit_umean1_threshold ,4,3);

    ptLabel_umean2_offset  = new QLabel("umean2_offset :");
    ptEdit_umean2_offset  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_umean2_offset ,5,0);layoutGrid->addWidget(ptEdit_umean2_offset ,5,1);

    ptLabel_umean2_slope  = new QLabel("umean2_slope :");
    ptEdit_umean2_slope  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_umean2_slope ,5,2);layoutGrid->addWidget(ptEdit_umean2_slope ,5,3);

    ptLabel_umean2_threshold  = new QLabel("umean2_threshold :");
    ptEdit_umean2_threshold  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_umean2_threshold ,6,0);layoutGrid->addWidget(ptEdit_umean2_threshold ,6,1);

    ptLabel_uv_delta1_offset  = new QLabel("uv_delta1_offset :");
    ptEdit_uv_delta1_offset  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_uv_delta1_offset ,6,2);layoutGrid->addWidget(ptEdit_uv_delta1_offset ,6,3);

    ptLabel_uv_delta1_slope  = new QLabel("uv_delta1_slope :");
    ptEdit_uv_delta1_slope  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_uv_delta1_slope ,7,0);layoutGrid->addWidget(ptEdit_uv_delta1_slope ,7,1);

    ptLabel_uv_delta1_threshold  = new QLabel("uv_delta1_threshold :");
    ptEdit_uv_delta1_threshold  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_uv_delta1_threshold ,7,2);layoutGrid->addWidget(ptEdit_uv_delta1_threshold ,7,3);

    ptLabel_uv_delta2_offset  = new QLabel("uv_delta2_offset :");
    ptEdit_uv_delta2_offset  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_uv_delta2_offset ,8,0);layoutGrid->addWidget(ptEdit_uv_delta2_offset ,8,1);

    ptLabel_uv_delta2_slope  = new QLabel("uv_delta2_slope :");
    ptEdit_uv_delta2_slope  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_uv_delta2_slope ,8,2);layoutGrid->addWidget(ptEdit_uv_delta2_slope ,8,3);

    ptLabel_uv_delta2_threshold  = new QLabel("uv_delta2_threshold :");
    ptEdit_uv_delta2_threshold  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_uv_delta2_threshold ,9,0);layoutGrid->addWidget(ptEdit_uv_delta2_threshold ,9,1);

    ptLabel_uv_seg1_offset  = new QLabel("uv_seg1_offset :");
    ptEdit_uv_seg1_offset  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_uv_seg1_offset ,9,2);layoutGrid->addWidget(ptEdit_uv_seg1_offset ,9,3);

    ptLabel_uv_seg1_slope  = new QLabel("uv_seg1_slope :");
    ptEdit_uv_seg1_slope  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_uv_seg1_slope ,10,0);layoutGrid->addWidget(ptEdit_uv_seg1_slope ,10,1);

    ptLabel_uv_seg1_threshold  = new QLabel("uv_seg1_threshold :");
    ptEdit_uv_seg1_threshold  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_uv_seg1_threshold ,10,2);layoutGrid->addWidget(ptEdit_uv_seg1_threshold ,10,3);

    ptLabel_uv_var1_offset  = new QLabel("uv_var1_offset :");
    ptEdit_uv_var1_offset  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_uv_var1_offset ,11,0);layoutGrid->addWidget(ptEdit_uv_var1_offset ,11,1);

    ptLabel_uv_var1_slope  = new QLabel("uv_var1_slope :");
    ptEdit_uv_var1_slope  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_uv_var1_slope ,11,2);layoutGrid->addWidget(ptEdit_uv_var1_slope ,11,3);

    ptLabel_uv_var1_threshold  = new QLabel("uv_var1_threshold :");
    ptEdit_uv_var1_threshold  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_uv_var1_threshold ,12,0);layoutGrid->addWidget(ptEdit_uv_var1_threshold ,12,1);

    ptLabel_uv_var2_offset  = new QLabel("uv_var2_offset :");
    ptEdit_uv_var2_offset  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_uv_var2_offset ,12,2);layoutGrid->addWidget(ptEdit_uv_var2_offset ,12,3);

    ptLabel_uv_var2_slope  = new QLabel("uv_var2_slope :");
    ptEdit_uv_var2_slope  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_uv_var2_slope ,13,0);layoutGrid->addWidget(ptEdit_uv_var2_slope ,13,1);

    ptLabel_uv_var2_threshold  = new QLabel("uv_var2_threshold :");
    ptEdit_uv_var2_threshold  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_uv_var2_threshold ,13,2);layoutGrid->addWidget(ptEdit_uv_var2_threshold ,13,3);

    ptLabel_v_center  = new QLabel("v_center :");
    ptEdit_v_center  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_v_center ,14,0);layoutGrid->addWidget(ptEdit_v_center ,14,1);

    ptLabel_vmean1_offset  = new QLabel("vmean1_offset :");
    ptEdit_vmean1_offset  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_vmean1_offset ,14,2);layoutGrid->addWidget(ptEdit_vmean1_offset ,14,3);

    ptLabel_vmean1_slope  = new QLabel("vmean1_slope :");
    ptEdit_vmean1_slope  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_vmean1_slope ,15,0);layoutGrid->addWidget(ptEdit_vmean1_slope ,15,1);

    ptLabel_vmean1_threshold  = new QLabel("vmean1_threshold :");
    ptEdit_vmean1_threshold  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_vmean1_threshold ,15,2);layoutGrid->addWidget(ptEdit_vmean1_threshold ,15,3);

    ptLabel_vmean2_offset  = new QLabel("vmean2_offset :");
    ptEdit_vmean2_offset  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_vmean2_offset ,16,0);layoutGrid->addWidget(ptEdit_vmean2_offset ,16,1);

    ptLabel_vmean2_slope  = new QLabel("vmean2_slope :");
    ptEdit_vmean2_slope  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_vmean2_slope ,16,2);layoutGrid->addWidget(ptEdit_vmean2_slope ,16,3);

    ptLabel_vmean2_threshold  = new QLabel("vmean2_threshold :");
    ptEdit_vmean2_threshold  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_vmean2_threshold ,17,0);layoutGrid->addWidget(ptEdit_vmean2_threshold ,17,1);

    ptPBtn = new QPushButton("确定");
    layoutGrid->addWidget(ptPBtn,18,3,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

    setLayout(mainLayout);
}

void IspPPCnr::clickedSlot(bool checked)
{
    QString str_delta_factor = ptEdit_delta_factor->text();
    QString str_effective_kernel = ptEdit_effective_kernel->text();
    QString str_enable = ptEdit_enable->text();
    QString str_global_offset = ptEdit_global_offset->text();
    QString str_global_slope = ptEdit_global_slope->text();
    QString str_reg_uv_var1_scale = ptEdit_reg_uv_var1_scale->text();
    QString str_u_center = ptEdit_u_center->text();
    QString str_umean1_offset = ptEdit_umean1_offset->text();
    QString str_umean1_slope = ptEdit_umean1_slope->text();
    QString str_umean1_threshold = ptEdit_umean1_threshold->text();
    QString str_umean2_offset = ptEdit_umean2_offset->text();
    QString str_umean2_slope = ptEdit_umean2_slope->text();
    QString str_umean2_threshold = ptEdit_umean2_threshold->text();
    QString str_uv_delta1_offset = ptEdit_uv_delta1_offset->text();
    QString str_uv_delta1_slope = ptEdit_uv_delta1_slope->text();
    QString str_uv_delta1_threshold = ptEdit_uv_delta1_threshold->text();
    QString str_uv_delta2_offset = ptEdit_uv_delta2_offset->text();
    QString str_uv_delta2_slope = ptEdit_uv_delta2_slope->text();
    QString str_uv_delta2_threshold = ptEdit_uv_delta2_threshold->text();
    QString str_uv_seg1_offset = ptEdit_uv_seg1_offset->text();
    QString str_uv_seg1_slope = ptEdit_uv_seg1_slope->text();
    QString str_uv_seg1_threshold = ptEdit_uv_seg1_threshold->text();
    QString str_uv_var1_offset = ptEdit_uv_var1_offset->text();
    QString str_uv_var1_slope = ptEdit_uv_var1_slope->text();
    QString str_uv_var1_threshold = ptEdit_uv_var1_threshold->text();
    QString str_uv_var2_offset = ptEdit_uv_var2_offset->text();
    QString str_uv_var2_slope = ptEdit_uv_var2_slope->text();
    QString str_uv_var2_threshold = ptEdit_uv_var2_threshold->text();
    QString str_v_center = ptEdit_v_center->text();
    QString str_vmean1_offset = ptEdit_vmean1_offset->text();
    QString str_vmean1_slope = ptEdit_vmean1_slope->text();
    QString str_vmean1_threshold = ptEdit_vmean1_threshold->text();
    QString str_vmean2_offset = ptEdit_vmean2_offset->text();
    QString str_vmean2_slope = ptEdit_vmean2_slope->text();
    QString str_vmean2_threshold = ptEdit_vmean2_threshold->text();
}
