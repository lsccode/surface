#include "ispppmisc.h"
#include <QGridLayout>
IspPPmisc::IspPPmisc(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    // add edit
    ptLabel_sqrtblack_level_in  = new QLabel("sqrtblack_level_in :");
    ptEdit_sqrtblack_level_in  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_sqrtblack_level_in ,0,0);layoutGrid->addWidget(ptEdit_sqrtblack_level_in ,0,1);

    ptLabel_sqrtblack_level_out  = new QLabel("sqrtblack_level_out :");
    ptEdit_sqrtblack_level_out  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_sqrtblack_level_out ,1,0);layoutGrid->addWidget(ptEdit_sqrtblack_level_out ,1,1);

    ptLabel_square_beblack_level_in  = new QLabel("square_beblack_level_in :");
    ptEdit_square_beblack_level_in  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_square_beblack_level_in ,2,0);layoutGrid->addWidget(ptEdit_square_beblack_level_in ,2,1);

    ptLabel_square_beblack_level_out  = new QLabel("square_beblack_level_out :");
    ptEdit_square_beblack_level_out  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_square_beblack_level_out ,3,0);layoutGrid->addWidget(ptEdit_square_beblack_level_out ,3,1);

    ptLabel_lumvar_reg_active_width  = new QLabel("lumvar_reg_active_width :");
    ptEdit_lumvar_reg_active_width  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_lumvar_reg_active_width ,4,0);layoutGrid->addWidget(ptEdit_lumvar_reg_active_width ,4,1);

    ptLabel_defect_pixel_defect_pixel_count_in  = new QLabel("defect_pixel_defect_pixel_count_in :");
    ptEdit_defect_pixel_defect_pixel_count_in  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_defect_pixel_defect_pixel_count_in ,5,0);layoutGrid->addWidget(ptEdit_defect_pixel_defect_pixel_count_in ,5,1);

    ptCb_nonequ_gamma_srgb_lut_coeff_lut  = new QComboBox;
    ptEdit_nonequ_gamma_srgb_lut_coeff_lut = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_nonequ_gamma_srgb_lut_coeff_lut,7,0);layoutGrid->addWidget(ptEdit_nonequ_gamma_srgb_lut_coeff_lut,7,1);
    for(unsigned int i = 0;i < M_NONEQU_GAMMA_SRGB_LUT_COEFF_LUT_NUMBER; ++i)
    {
        QString str;
        str.sprintf("nonequ_gamma_srgb_lut_coeff_lut[%x]",i);
        ptCb_nonequ_gamma_srgb_lut_coeff_lut->addItem(str);
        szQStr_nonequ_gamma_srgb_lut_coeff_lut[i].sprintf("%x",i);
    }
    ptEdit_nonequ_gamma_srgb_lut_coeff_lut->setText(szQStr_nonequ_gamma_srgb_lut_coeff_lut[ptCb_nonequ_gamma_srgb_lut_coeff_lut->currentIndex()]);

    ptCb_pf_correction_shading_shading_lut  = new QComboBox;
    ptEdit_pf_correction_shading_shading_lut = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_pf_correction_shading_shading_lut,8,0);layoutGrid->addWidget(ptEdit_pf_correction_shading_shading_lut,8,1);
    for(unsigned int i = 0;i < M_PF_CORRECTION_SHADING_SHADING_LUT_NUMBER; ++i)
    {
        QString str;
        str.sprintf("pf_correction_shading_shading_lut[%x]",i);
        ptCb_pf_correction_shading_shading_lut->addItem(str);
        szQStr_pf_correction_shading_shading_lut[i].sprintf("%x",i);
    }
    ptEdit_pf_correction_shading_shading_lut->setText(szQStr_pf_correction_shading_shading_lut[ptCb_pf_correction_shading_shading_lut->currentIndex()]);


    ptCb_lumvar_stats_ping_mem  = new QComboBox;
    ptEdit_lumvar_stats_ping_mem = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_lumvar_stats_ping_mem,6,0);layoutGrid->addWidget(ptEdit_lumvar_stats_ping_mem,6,1);
    for(unsigned int i = 0;i < M_LUMVAR_STATS_PING_MEM_NUMBER; ++i)
    {
        QString str;
        str.sprintf("lumvar_stats_ping_mem[%x]",i);
        ptCb_lumvar_stats_ping_mem->addItem(str);
        szQStr_lumvar_stats_ping_mem[i].sprintf("%x",i);
    }
    ptEdit_lumvar_stats_ping_mem->setText(szQStr_lumvar_stats_ping_mem[ptCb_lumvar_stats_ping_mem->currentIndex()]);

    ptPBtn = new QPushButton("确定");
    layoutGrid->addWidget(ptPBtn,40,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));
    connect(ptCb_nonequ_gamma_srgb_lut_coeff_lut,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_nonequ_gamma_srgb_lut_coeff_lut(int)));
    connect(ptEdit_nonequ_gamma_srgb_lut_coeff_lut,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_nonequ_gamma_srgb_lut_coeff_lut(const QString)));
    setLayout(mainLayout);
    connect(ptCb_pf_correction_shading_shading_lut,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_pf_correction_shading_shading_lut(int)));
    connect(ptEdit_pf_correction_shading_shading_lut,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_pf_correction_shading_shading_lut(const QString)));

    connect(ptCb_lumvar_stats_ping_mem,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_lumvar_stats_ping_mem(int)));
    connect(ptEdit_lumvar_stats_ping_mem,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_lumvar_stats_ping_mem(const QString)));
}

void IspPPmisc::clickedSlot(bool checked)
{
    QString str_sqrtblack_level_in = ptEdit_sqrtblack_level_in->text();
    QString str_sqrtblack_level_out = ptEdit_sqrtblack_level_out->text();
    QString str_square_beblack_level_in = ptEdit_square_beblack_level_in->text();
    QString str_square_beblack_level_out = ptEdit_square_beblack_level_out->text();
}


void IspPPmisc::activatedSlot_nonequ_gamma_srgb_lut_coeff_lut(int index)
{
    ptEdit_nonequ_gamma_srgb_lut_coeff_lut->setText(szQStr_nonequ_gamma_srgb_lut_coeff_lut[index]);
}

void IspPPmisc::textChangedSlot_nonequ_gamma_srgb_lut_coeff_lut(const QString &text)
{
    int index = ptCb_nonequ_gamma_srgb_lut_coeff_lut->currentIndex();
    szQStr_nonequ_gamma_srgb_lut_coeff_lut[index] = text;
}

void IspPPmisc::activatedSlot_pf_correction_shading_shading_lut(int index)
{
    ptEdit_pf_correction_shading_shading_lut->setText(szQStr_pf_correction_shading_shading_lut[index]);
}

void IspPPmisc::textChangedSlot_pf_correction_shading_shading_lut(const QString &text)
{
    int index = ptCb_pf_correction_shading_shading_lut->currentIndex();
    szQStr_pf_correction_shading_shading_lut[index] = text;
}

void IspPPmisc::activatedSlot_lumvar_stats_ping_mem(int index)
{
    ptEdit_lumvar_stats_ping_mem->setText(szQStr_lumvar_stats_ping_mem[index]);
}

void IspPPmisc::textChangedSlot_lumvar_stats_ping_mem(const QString &text)
{
    int index = ptCb_lumvar_stats_ping_mem->currentIndex();
    szQStr_lumvar_stats_ping_mem[index] = text;
}
