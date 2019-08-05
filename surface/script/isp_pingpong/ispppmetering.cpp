#include "ispppmetering.h"
#include <QGridLayout>
IspPPmetering::IspPPmetering(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    // add edit
    ptLabel_metering_aexphist_thresh_0_1  = new QLabel("metering_aexphist_thresh_0_1 :");
    ptEdit_metering_aexphist_thresh_0_1  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_aexphist_thresh_0_1 ,0,0);layoutGrid->addWidget(ptEdit_metering_aexphist_thresh_0_1 ,0,1);

    ptLabel_metering_aexphist_thresh_1_2  = new QLabel("metering_aexphist_thresh_1_2 :");
    ptEdit_metering_aexphist_thresh_1_2  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_aexphist_thresh_1_2 ,0,2);layoutGrid->addWidget(ptEdit_metering_aexphist_thresh_1_2 ,0,3);

    ptLabel_metering_aexphist_thresh_3_4  = new QLabel("metering_aexphist_thresh_3_4 :");
    ptEdit_metering_aexphist_thresh_3_4  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_aexphist_thresh_3_4 ,1,0);layoutGrid->addWidget(ptEdit_metering_aexphist_thresh_3_4 ,1,1);

    ptLabel_metering_aexphist_thresh_4_5  = new QLabel("metering_aexphist_thresh_4_5 :");
    ptEdit_metering_aexphist_thresh_4_5  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_aexphist_thresh_4_5 ,1,2);layoutGrid->addWidget(ptEdit_metering_aexphist_thresh_4_5 ,1,3);

    ptLabel_metering_aexpreg_nodes_used_horiz  = new QLabel("metering_aexpreg_nodes_used_horiz :");
    ptEdit_metering_aexpreg_nodes_used_horiz  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_aexpreg_nodes_used_horiz ,2,0);layoutGrid->addWidget(ptEdit_metering_aexpreg_nodes_used_horiz ,2,1);

    ptLabel_metering_afkernel_select  = new QLabel("metering_afkernel_select :");
    ptEdit_metering_afkernel_select  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_afkernel_select ,2,2);layoutGrid->addWidget(ptEdit_metering_afkernel_select ,2,3);

    ptLabel_metering_afreg_active_width  = new QLabel("metering_afreg_active_width :");
    ptEdit_metering_afreg_active_width  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_afreg_active_width ,3,0);layoutGrid->addWidget(ptEdit_metering_afreg_active_width ,3,1);

    ptLabel_metering_afreg_nodes_used_horiz  = new QLabel("metering_afreg_nodes_used_horiz :");
    ptEdit_metering_afreg_nodes_used_horiz  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_afreg_nodes_used_horiz ,3,2);layoutGrid->addWidget(ptEdit_metering_afreg_nodes_used_horiz ,3,3);

    ptLabel_metering_awbblack_level_awb  = new QLabel("metering_awbblack_level_awb :");
    ptEdit_metering_awbblack_level_awb  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_awbblack_level_awb ,4,0);layoutGrid->addWidget(ptEdit_metering_awbblack_level_awb ,4,1);

    ptLabel_metering_awbcb_ref_high_awb  = new QLabel("metering_awbcb_ref_high_awb :");
    ptEdit_metering_awbcb_ref_high_awb  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_awbcb_ref_high_awb ,4,2);layoutGrid->addWidget(ptEdit_metering_awbcb_ref_high_awb ,4,3);

    ptLabel_metering_awbcb_ref_low_awb  = new QLabel("metering_awbcb_ref_low_awb :");
    ptEdit_metering_awbcb_ref_low_awb  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_awbcb_ref_low_awb ,5,0);layoutGrid->addWidget(ptEdit_metering_awbcb_ref_low_awb ,5,1);

    ptLabel_metering_awbcb_ref_max_awb  = new QLabel("metering_awbcb_ref_max_awb :");
    ptEdit_metering_awbcb_ref_max_awb  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_awbcb_ref_max_awb ,5,2);layoutGrid->addWidget(ptEdit_metering_awbcb_ref_max_awb ,5,3);

    ptLabel_metering_awbcb_ref_min_awb  = new QLabel("metering_awbcb_ref_min_awb :");
    ptEdit_metering_awbcb_ref_min_awb  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_awbcb_ref_min_awb ,6,0);layoutGrid->addWidget(ptEdit_metering_awbcb_ref_min_awb ,6,1);

    ptLabel_metering_awbcr_ref_high_awb  = new QLabel("metering_awbcr_ref_high_awb :");
    ptEdit_metering_awbcr_ref_high_awb  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_awbcr_ref_high_awb ,6,2);layoutGrid->addWidget(ptEdit_metering_awbcr_ref_high_awb ,6,3);

    ptLabel_metering_awbcr_ref_low_awb  = new QLabel("metering_awbcr_ref_low_awb :");
    ptEdit_metering_awbcr_ref_low_awb  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_awbcr_ref_low_awb ,7,0);layoutGrid->addWidget(ptEdit_metering_awbcr_ref_low_awb ,7,1);

    ptLabel_metering_awbcr_ref_max_awb  = new QLabel("metering_awbcr_ref_max_awb :");
    ptEdit_metering_awbcr_ref_max_awb  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_awbcr_ref_max_awb ,7,2);layoutGrid->addWidget(ptEdit_metering_awbcr_ref_max_awb ,7,3);

    ptLabel_metering_awbcr_ref_min_awb  = new QLabel("metering_awbcr_ref_min_awb :");
    ptEdit_metering_awbcr_ref_min_awb  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_awbcr_ref_min_awb ,8,0);layoutGrid->addWidget(ptEdit_metering_awbcr_ref_min_awb ,8,1);

    ptLabel_metering_awbreg_nodes_used_horiz  = new QLabel("metering_awbreg_nodes_used_horiz :");
    ptEdit_metering_awbreg_nodes_used_horiz  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_awbreg_nodes_used_horiz ,8,2);layoutGrid->addWidget(ptEdit_metering_awbreg_nodes_used_horiz ,8,3);

    ptLabel_metering_awbstats_mode  = new QLabel("metering_awbstats_mode :");
    ptEdit_metering_awbstats_mode  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_awbstats_mode ,9,0);layoutGrid->addWidget(ptEdit_metering_awbstats_mode ,9,1);

    ptLabel_metering_awbwhite_level_awb  = new QLabel("metering_awbwhite_level_awb :");
    ptEdit_metering_awbwhite_level_awb  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_awbwhite_level_awb ,9,2);layoutGrid->addWidget(ptEdit_metering_awbwhite_level_awb ,9,3);

    ptLabel_metering_awbzones_weight  = new QLabel("metering_awbzones_weight :");
    ptEdit_metering_awbzones_weight  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_awbzones_weight ,10,0);layoutGrid->addWidget(ptEdit_metering_awbzones_weight ,10,1);

    ptLabel_metering_hist_aexpplane_mode  = new QLabel("metering_hist_aexpplane_mode :");
    ptEdit_metering_hist_aexpplane_mode  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_hist_aexpplane_mode ,10,2);layoutGrid->addWidget(ptEdit_metering_hist_aexpplane_mode ,10,3);

    ptLabel_metering_hist_aexpreg_nodes_used_horiz  = new QLabel("metering_hist_aexpreg_nodes_used_horiz :");
    ptEdit_metering_hist_aexpreg_nodes_used_horiz  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_hist_aexpreg_nodes_used_horiz ,11,0);layoutGrid->addWidget(ptEdit_metering_hist_aexpreg_nodes_used_horiz ,11,1);

    ptLabel_metering_hist_aexpreg_scale_bottom  = new QLabel("metering_hist_aexpreg_scale_bottom :");
    ptEdit_metering_hist_aexpreg_scale_bottom  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_hist_aexpreg_scale_bottom ,11,2);layoutGrid->addWidget(ptEdit_metering_hist_aexpreg_scale_bottom ,11,3);

    ptLabel_metering_hist_aexpreg_skip_x  = new QLabel("metering_hist_aexpreg_skip_x :");
    ptEdit_metering_hist_aexpreg_skip_x  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_hist_aexpreg_skip_x ,12,0);layoutGrid->addWidget(ptEdit_metering_hist_aexpreg_skip_x ,12,1);

    ptLabel_metering_hist_aexpzones_weight  = new QLabel("metering_hist_aexpzones_weight :");
    ptEdit_metering_hist_aexpzones_weight  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_hist_aexpzones_weight ,12,2);layoutGrid->addWidget(ptEdit_metering_hist_aexpzones_weight ,12,3);

    ptLabel_metering_ihistplane_mode  = new QLabel("metering_ihistplane_mode :");
    ptEdit_metering_ihistplane_mode  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_ihistplane_mode ,13,0);layoutGrid->addWidget(ptEdit_metering_ihistplane_mode ,13,1);

    ptLabel_metering_ihistreg_nodes_used_horiz  = new QLabel("metering_ihistreg_nodes_used_horiz :");
    ptEdit_metering_ihistreg_nodes_used_horiz  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_ihistreg_nodes_used_horiz ,13,2);layoutGrid->addWidget(ptEdit_metering_ihistreg_nodes_used_horiz ,13,3);

    ptLabel_metering_ihistreg_scale_bottom  = new QLabel("metering_ihistreg_scale_bottom :");
    ptEdit_metering_ihistreg_scale_bottom  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_ihistreg_scale_bottom ,14,0);layoutGrid->addWidget(ptEdit_metering_ihistreg_scale_bottom ,14,1);

    ptLabel_metering_ihistreg_skip_x  = new QLabel("metering_ihistreg_skip_x :");
    ptEdit_metering_ihistreg_skip_x  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_ihistreg_skip_x ,14,2);layoutGrid->addWidget(ptEdit_metering_ihistreg_skip_x ,14,3);

    ptLabel_metering_ihistzones_weight  = new QLabel("metering_ihistzones_weight :");
    ptEdit_metering_ihistzones_weight  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_metering_ihistzones_weight ,15,0);layoutGrid->addWidget(ptEdit_metering_ihistzones_weight ,15,1);

    ptCb_metering_awb_zones_weight  = new QComboBox;
    ptEdit_metering_awb_zones_weight = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_metering_awb_zones_weight,15,2);layoutGrid->addWidget(ptEdit_metering_awb_zones_weight,15,3);
    for(unsigned int i = 0;i < M_METERING_AWB_ZONES_WEIGHT_NUMBER; ++i)
    {
        QString str;
        str.sprintf("metering_awb.zones_weight[%x]",i);
        ptCb_metering_awb_zones_weight->addItem(str);
        szQStr_metering_awb_zones_weight[i].sprintf("%x",i);
    }
    ptEdit_metering_awb_zones_weight->setText(szQStr_metering_awb_zones_weight[ptCb_metering_awb_zones_weight->currentIndex()]);

    ptCb_metering_hist_aexp_zones_weight  = new QComboBox;
    ptEdit_metering_hist_aexp_zones_weight = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_metering_hist_aexp_zones_weight,16,0);layoutGrid->addWidget(ptEdit_metering_hist_aexp_zones_weight,16,1);
    for(unsigned int i = 0;i < M_METERING_HIST_AEXP_ZONES_WEIGHT_NUMBER; ++i)
    {
        QString str;
        str.sprintf("metering_hist_aexp.zones_weight[%x]",i);
        ptCb_metering_hist_aexp_zones_weight->addItem(str);
        szQStr_metering_hist_aexp_zones_weight[i].sprintf("%x",i);
    }
    ptEdit_metering_hist_aexp_zones_weight->setText(szQStr_metering_hist_aexp_zones_weight[ptCb_metering_hist_aexp_zones_weight->currentIndex()]);

    ptPBtn = new QPushButton("确定");
    layoutGrid->addWidget(ptPBtn,17,3,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

    connect(ptCb_metering_awb_zones_weight,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_metering_awb_zones_weight(int)));
    connect(ptEdit_metering_awb_zones_weight,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_metering_awb_zones_weight(const QString)));

    connect(ptCb_metering_hist_aexp_zones_weight,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_metering_hist_aexp_zones_weight(int)));
    connect(ptEdit_metering_hist_aexp_zones_weight,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_metering_hist_aexp_zones_weight(const QString)));

    setLayout(mainLayout);
}

void IspPPmetering::clickedSlot(bool checked)
{
    QString str_metering_aexphist_thresh_0_1 = ptEdit_metering_aexphist_thresh_0_1->text();
    QString str_metering_aexphist_thresh_1_2 = ptEdit_metering_aexphist_thresh_1_2->text();
    QString str_metering_aexphist_thresh_3_4 = ptEdit_metering_aexphist_thresh_3_4->text();
    QString str_metering_aexphist_thresh_4_5 = ptEdit_metering_aexphist_thresh_4_5->text();
    QString str_metering_aexpreg_nodes_used_horiz = ptEdit_metering_aexpreg_nodes_used_horiz->text();
    QString str_metering_afkernel_select = ptEdit_metering_afkernel_select->text();
    QString str_metering_afreg_active_width = ptEdit_metering_afreg_active_width->text();
    QString str_metering_afreg_nodes_used_horiz = ptEdit_metering_afreg_nodes_used_horiz->text();
    QString str_metering_awbblack_level_awb = ptEdit_metering_awbblack_level_awb->text();
    QString str_metering_awbcb_ref_high_awb = ptEdit_metering_awbcb_ref_high_awb->text();
    QString str_metering_awbcb_ref_low_awb = ptEdit_metering_awbcb_ref_low_awb->text();
    QString str_metering_awbcb_ref_max_awb = ptEdit_metering_awbcb_ref_max_awb->text();
    QString str_metering_awbcb_ref_min_awb = ptEdit_metering_awbcb_ref_min_awb->text();
    QString str_metering_awbcr_ref_high_awb = ptEdit_metering_awbcr_ref_high_awb->text();
    QString str_metering_awbcr_ref_low_awb = ptEdit_metering_awbcr_ref_low_awb->text();
    QString str_metering_awbcr_ref_max_awb = ptEdit_metering_awbcr_ref_max_awb->text();
    QString str_metering_awbcr_ref_min_awb = ptEdit_metering_awbcr_ref_min_awb->text();
    QString str_metering_awbreg_nodes_used_horiz = ptEdit_metering_awbreg_nodes_used_horiz->text();
    QString str_metering_awbstats_mode = ptEdit_metering_awbstats_mode->text();
    QString str_metering_awbwhite_level_awb = ptEdit_metering_awbwhite_level_awb->text();
    QString str_metering_awbzones_weight = ptEdit_metering_awbzones_weight->text();
    QString str_metering_hist_aexpplane_mode = ptEdit_metering_hist_aexpplane_mode->text();
    QString str_metering_hist_aexpreg_nodes_used_horiz = ptEdit_metering_hist_aexpreg_nodes_used_horiz->text();
    QString str_metering_hist_aexpreg_scale_bottom = ptEdit_metering_hist_aexpreg_scale_bottom->text();
    QString str_metering_hist_aexpreg_skip_x = ptEdit_metering_hist_aexpreg_skip_x->text();
    QString str_metering_hist_aexpzones_weight = ptEdit_metering_hist_aexpzones_weight->text();
    QString str_metering_ihistplane_mode = ptEdit_metering_ihistplane_mode->text();
    QString str_metering_ihistreg_nodes_used_horiz = ptEdit_metering_ihistreg_nodes_used_horiz->text();
    QString str_metering_ihistreg_scale_bottom = ptEdit_metering_ihistreg_scale_bottom->text();
    QString str_metering_ihistreg_skip_x = ptEdit_metering_ihistreg_skip_x->text();
    QString str_metering_ihistzones_weight = ptEdit_metering_ihistzones_weight->text();
}

void IspPPmetering::activatedSlot_metering_awb_zones_weight(int index)
{
    ptEdit_metering_awb_zones_weight->setText(szQStr_metering_awb_zones_weight[index]);
}

void IspPPmetering::textChangedSlot_metering_awb_zones_weight(const QString &text)
{
    int index = ptCb_metering_awb_zones_weight->currentIndex();
    szQStr_metering_awb_zones_weight[index] = text;
}

void IspPPmetering::activatedSlot_metering_hist_aexp_zones_weight(int index)
{
    ptEdit_metering_hist_aexp_zones_weight->setText(szQStr_metering_hist_aexp_zones_weight[index]);
}

void IspPPmetering::textChangedSlot_metering_hist_aexp_zones_weight(const QString &text)
{
    int index = ptCb_metering_hist_aexp_zones_weight->currentIndex();
    szQStr_metering_hist_aexp_zones_weight[index] = text;
}
