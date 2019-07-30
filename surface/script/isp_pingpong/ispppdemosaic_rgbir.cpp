#include "ispppdemosaic_rgbir.h"
#include <QGridLayout>
IspPPdemosaic_rgbir::IspPPdemosaic_rgbir(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    ptLabel_clip_debloom  = new QLabel("clip_debloom :");
    ptEdit_clip_debloom  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_clip_debloom ,0,0);layoutGrid->addWidget(ptEdit_clip_debloom ,0,1);

    ptLabel_clip_level  = new QLabel("clip_level :");
    ptEdit_clip_level  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_clip_level ,1,0);layoutGrid->addWidget(ptEdit_clip_level ,1,1);

    ptLabel_fc_grad  = new QLabel("fc_grad :");
    ptEdit_fc_grad  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fc_grad ,2,0);layoutGrid->addWidget(ptEdit_fc_grad ,2,1);

    ptLabel_fc_low  = new QLabel("fc_low :");
    ptEdit_fc_low  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_fc_low ,3,0);layoutGrid->addWidget(ptEdit_fc_low ,3,1);

    ptLabel_interpolation_directionality  = new QLabel("interpolation_directionality :");
    ptEdit_interpolation_directionality  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_interpolation_directionality ,4,0);layoutGrid->addWidget(ptEdit_interpolation_directionality ,4,1);

    ptLabel_reg_gain_r  = new QLabel("reg_gain_r :");
    ptEdit_reg_gain_r  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_gain_r ,5,0);layoutGrid->addWidget(ptEdit_reg_gain_r ,5,1);

    ptLabel_reg_ir_correct_mat00  = new QLabel("reg_ir_correct_mat00 :");
    ptEdit_reg_ir_correct_mat00  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_ir_correct_mat00 ,6,0);layoutGrid->addWidget(ptEdit_reg_ir_correct_mat00 ,6,1);

    ptLabel_reg_ir_correct_mat02  = new QLabel("reg_ir_correct_mat02 :");
    ptEdit_reg_ir_correct_mat02  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_ir_correct_mat02 ,7,0);layoutGrid->addWidget(ptEdit_reg_ir_correct_mat02 ,7,1);

    ptLabel_reg_ir_correct_mat10  = new QLabel("reg_ir_correct_mat10 :");
    ptEdit_reg_ir_correct_mat10  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_ir_correct_mat10 ,8,0);layoutGrid->addWidget(ptEdit_reg_ir_correct_mat10 ,8,1);

    ptLabel_reg_ir_correct_mat12  = new QLabel("reg_ir_correct_mat12 :");
    ptEdit_reg_ir_correct_mat12  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_ir_correct_mat12 ,9,0);layoutGrid->addWidget(ptEdit_reg_ir_correct_mat12 ,9,1);

    ptLabel_reg_ir_correct_mat20  = new QLabel("reg_ir_correct_mat20 :");
    ptEdit_reg_ir_correct_mat20  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_ir_correct_mat20 ,10,0);layoutGrid->addWidget(ptEdit_reg_ir_correct_mat20 ,10,1);

    ptLabel_reg_ir_correct_mat22  = new QLabel("reg_ir_correct_mat22 :");
    ptEdit_reg_ir_correct_mat22  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_ir_correct_mat22 ,11,0);layoutGrid->addWidget(ptEdit_reg_ir_correct_mat22 ,11,1);

    ptLabel_reg_ir_correct_mat30  = new QLabel("reg_ir_correct_mat30 :");
    ptEdit_reg_ir_correct_mat30  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_ir_correct_mat30 ,12,0);layoutGrid->addWidget(ptEdit_reg_ir_correct_mat30 ,12,1);

    ptLabel_reg_ir_correct_mat32  = new QLabel("reg_ir_correct_mat32 :");
    ptEdit_reg_ir_correct_mat32  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_ir_correct_mat32 ,13,0);layoutGrid->addWidget(ptEdit_reg_ir_correct_mat32 ,13,1);

    ptLabel_reg_static_gain_r  = new QLabel("reg_static_gain_r :");
    ptEdit_reg_static_gain_r  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_static_gain_r ,14,0);layoutGrid->addWidget(ptEdit_reg_static_gain_r ,14,1);

    ptLabel_rgbir_config  = new QLabel("rgbir_config :");
    ptEdit_rgbir_config  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_rgbir_config ,15,0);layoutGrid->addWidget(ptEdit_rgbir_config ,15,1);

    ptLabel_sharp_high  = new QLabel("sharp_high :");
    ptEdit_sharp_high  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_sharp_high ,16,0);layoutGrid->addWidget(ptEdit_sharp_high ,16,1);

    ptLabel_sharp_limit  = new QLabel("sharp_limit :");
    ptEdit_sharp_limit  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_sharp_limit ,17,0);layoutGrid->addWidget(ptEdit_sharp_limit ,17,1);

    ptLabel_sharp_low  = new QLabel("sharp_low :");
    ptEdit_sharp_low  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_sharp_low ,18,0);layoutGrid->addWidget(ptEdit_sharp_low ,18,1);

    ptLabel_static_gain_i  = new QLabel("static_gain_i :");
    ptEdit_static_gain_i  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_static_gain_i ,19,0);layoutGrid->addWidget(ptEdit_static_gain_i ,19,1);

    ptLabel_weight_lut  = new QLabel("weight_lut :");
    ptEdit_weight_lut  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_weight_lut ,20,0);layoutGrid->addWidget(ptEdit_weight_lut ,20,1);

    ptPBtn = new QPushButton("确定");
    layoutGrid->addWidget(ptPBtn,21,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

    setLayout(mainLayout);
}

void IspPPdemosaic_rgbir::clickedSlot(bool checked)
{
    QString str_clip_debloom = ptEdit_clip_debloom->text();
    QString str_clip_level = ptEdit_clip_level->text();
    QString str_fc_grad = ptEdit_fc_grad->text();
    QString str_fc_low = ptEdit_fc_low->text();
    QString str_interpolation_directionality = ptEdit_interpolation_directionality->text();
    QString str_reg_gain_r = ptEdit_reg_gain_r->text();
    QString str_reg_ir_correct_mat00 = ptEdit_reg_ir_correct_mat00->text();
    QString str_reg_ir_correct_mat02 = ptEdit_reg_ir_correct_mat02->text();
    QString str_reg_ir_correct_mat10 = ptEdit_reg_ir_correct_mat10->text();
    QString str_reg_ir_correct_mat12 = ptEdit_reg_ir_correct_mat12->text();
    QString str_reg_ir_correct_mat20 = ptEdit_reg_ir_correct_mat20->text();
    QString str_reg_ir_correct_mat22 = ptEdit_reg_ir_correct_mat22->text();
    QString str_reg_ir_correct_mat30 = ptEdit_reg_ir_correct_mat30->text();
    QString str_reg_ir_correct_mat32 = ptEdit_reg_ir_correct_mat32->text();
    QString str_reg_static_gain_r = ptEdit_reg_static_gain_r->text();
    QString str_rgbir_config = ptEdit_rgbir_config->text();
    QString str_sharp_high = ptEdit_sharp_high->text();
    QString str_sharp_limit = ptEdit_sharp_limit->text();
    QString str_sharp_low = ptEdit_sharp_low->text();
    QString str_static_gain_i = ptEdit_static_gain_i->text();
    QString str_weight_lut = ptEdit_weight_lut->text();
}
