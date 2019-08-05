#include "isppptop.h"
#include <QGridLayout>
IspPPtop::IspPPtop(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    // add edit
    ptLabel_reg_active_width  = new QLabel("reg_active_width :");
    ptEdit_reg_active_width  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_active_width ,0,0);layoutGrid->addWidget(ptEdit_reg_active_width ,0,1);

    ptLabel_reg_ae_5bin_hist_disable  = new QLabel("reg_ae_5bin_hist_disable :");
    ptEdit_reg_ae_5bin_hist_disable  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_ae_5bin_hist_disable ,1,0);layoutGrid->addWidget(ptEdit_reg_ae_5bin_hist_disable ,1,1);

    ptLabel_reg_bypass_digital_gain  = new QLabel("reg_bypass_digital_gain :");
    ptEdit_reg_bypass_digital_gain  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_bypass_digital_gain ,2,0);layoutGrid->addWidget(ptEdit_reg_bypass_digital_gain ,2,1);

    ptLabel_reg_bypass_ds_crop  = new QLabel("reg_bypass_ds_crop :");
    ptEdit_reg_bypass_ds_crop  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_bypass_ds_crop ,3,0);layoutGrid->addWidget(ptEdit_reg_bypass_ds_crop ,3,1);

    ptLabel_reg_bypass_fr_crop  = new QLabel("reg_bypass_fr_crop :");
    ptEdit_reg_bypass_fr_crop  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_bypass_fr_crop ,4,0);layoutGrid->addWidget(ptEdit_reg_bypass_fr_crop ,4,1);

    ptLabel_reg_bypass_sinter  = new QLabel("reg_bypass_sinter :");
    ptEdit_reg_bypass_sinter  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_bypass_sinter ,5,0);layoutGrid->addWidget(ptEdit_reg_bypass_sinter ,5,1);

    ptLabel_reg_bypass_square_be  = new QLabel("reg_bypass_square_be :");
    ptEdit_reg_bypass_square_be  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_bypass_square_be ,6,0);layoutGrid->addWidget(ptEdit_reg_bypass_square_be ,6,1);

    ptLabel_reg_bypass_video_test_gen  = new QLabel("reg_bypass_video_test_gen :");
    ptEdit_reg_bypass_video_test_gen  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_bypass_video_test_gen ,7,0);layoutGrid->addWidget(ptEdit_reg_bypass_video_test_gen ,7,1);

    ptLabel_reg_rggb_start_pre_mirror  = new QLabel("reg_rggb_start_pre_mirror :");
    ptEdit_reg_rggb_start_pre_mirror  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_rggb_start_pre_mirror ,8,0);layoutGrid->addWidget(ptEdit_reg_rggb_start_pre_mirror ,8,1);

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

void IspPPtop::clickedSlot(bool checked)
{
    QString str_reg_active_width = ptEdit_reg_active_width->text();
    QString str_reg_ae_5bin_hist_disable = ptEdit_reg_ae_5bin_hist_disable->text();
    QString str_reg_bypass_digital_gain = ptEdit_reg_bypass_digital_gain->text();
    QString str_reg_bypass_ds_crop = ptEdit_reg_bypass_ds_crop->text();
    QString str_reg_bypass_fr_crop = ptEdit_reg_bypass_fr_crop->text();
    QString str_reg_bypass_sinter = ptEdit_reg_bypass_sinter->text();
    QString str_reg_bypass_square_be = ptEdit_reg_bypass_square_be->text();
    QString str_reg_bypass_video_test_gen = ptEdit_reg_bypass_video_test_gen->text();
    QString str_reg_rggb_start_pre_mirror = ptEdit_reg_rggb_start_pre_mirror->text();
}
