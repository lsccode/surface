#include "ispppsinter.h"
#include <QGridLayout>
IspPPsinter::IspPPsinter(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    // add edit
    ptLabel_config1  = new QLabel("config1 :");
    ptEdit_config1  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_config1 ,0,0);layoutGrid->addWidget(ptEdit_config1 ,0,1);

    ptLabel_config2  = new QLabel("config2 :");
    ptEdit_config2  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_config2 ,1,0);layoutGrid->addWidget(ptEdit_config2 ,1,1);

    ptLabel_black_level  = new QLabel("black_level :");
    ptEdit_black_level  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_black_level ,2,0);layoutGrid->addWidget(ptEdit_black_level ,2,1);

    ptLabel_weight_lut  = new QLabel("weight_lut :");
    ptEdit_weight_lut  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_weight_lut ,3,0);layoutGrid->addWidget(ptEdit_weight_lut ,3,1);

    ptLabel_reg_noise_level_0  = new QLabel("reg_noise_level_0 :");
    ptEdit_reg_noise_level_0  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_noise_level_0 ,4,0);layoutGrid->addWidget(ptEdit_reg_noise_level_0 ,4,1);

    ptLabel_reg_use_lut  = new QLabel("reg_use_lut :");
    ptEdit_reg_use_lut  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_use_lut ,5,0);layoutGrid->addWidget(ptEdit_reg_use_lut ,5,1);

    ptLabel_thresh1  = new QLabel("thresh1 :");
    ptEdit_thresh1  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_thresh1 ,6,0);layoutGrid->addWidget(ptEdit_thresh1 ,6,1);

    ptLabel_thresh2  = new QLabel("thresh2 :");
    ptEdit_thresh2  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_thresh2 ,7,0);layoutGrid->addWidget(ptEdit_thresh2 ,7,1);

    ptLabel_thresh3  = new QLabel("thresh3 :");
    ptEdit_thresh3  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_thresh3 ,8,0);layoutGrid->addWidget(ptEdit_thresh3 ,8,1);

    ptCb_sinter_shading_rm_shading_lut  = new QComboBox;
    ptEdit_sinter_shading_rm_shading_lut = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_sinter_shading_rm_shading_lut,9,0);layoutGrid->addWidget(ptEdit_sinter_shading_rm_shading_lut,9,1);
    for(unsigned int i = 0;i < M_SINTER_SHADING_RM_SHADING_LUT_NUMBER; ++i)
    {
        QString str;
        str.sprintf("sinter_shading_rm_shading_lut[%x]",i);
        ptCb_sinter_shading_rm_shading_lut->addItem(str);
        szQStr_sinter_shading_rm_shading_lut[i].sprintf("%x",i);
    }
    ptEdit_sinter_shading_rm_shading_lut->setText(szQStr_sinter_shading_rm_shading_lut[ptCb_sinter_shading_rm_shading_lut->currentIndex()]);

    ptCb_sinter_noise_profile_lut_weight_lut  = new QComboBox;
    ptEdit_sinter_noise_profile_lut_weight_lut = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_sinter_noise_profile_lut_weight_lut,10,0);layoutGrid->addWidget(ptEdit_sinter_noise_profile_lut_weight_lut,10,1);
    for(unsigned int i = 0;i < M_SINTER_NOISE_PROFILE_LUT_WEIGHT_LUT_NUMBER; ++i)
    {
        QString str;
        str.sprintf("sinter_noise_profile_lut_weight_lut[%x]",i);
        ptCb_sinter_noise_profile_lut_weight_lut->addItem(str);
        szQStr_sinter_noise_profile_lut_weight_lut[i].sprintf("%x",i);
    }
    ptEdit_sinter_noise_profile_lut_weight_lut->setText(szQStr_sinter_noise_profile_lut_weight_lut[ptCb_sinter_noise_profile_lut_weight_lut->currentIndex()]);

    ptCb_lut3d_mem  = new QComboBox;
    ptEdit_lut3d_mem = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_lut3d_mem,11,0);layoutGrid->addWidget(ptEdit_lut3d_mem,11,1);
    for(unsigned int i = 0;i < M_LUT3D_MEM_NUMBER; ++i)
    {
        QString str;
        str.sprintf("lut3d_mem[%x]",i);
        ptCb_lut3d_mem->addItem(str);
        szQStr_lut3d_mem[i].sprintf("%x",i);
    }
    ptEdit_lut3d_mem->setText(szQStr_lut3d_mem[ptCb_lut3d_mem->currentIndex()]);

    ptPBtn = new QPushButton("确定");
    layoutGrid->addWidget(ptPBtn,40,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

    connect(ptCb_sinter_shading_rm_shading_lut,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_sinter_shading_rm_shading_lut(int)));
    connect(ptEdit_sinter_shading_rm_shading_lut,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_sinter_shading_rm_shading_lut(const QString)));

    connect(ptCb_sinter_noise_profile_lut_weight_lut,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_sinter_noise_profile_lut_weight_lut(int)));
    connect(ptEdit_sinter_noise_profile_lut_weight_lut,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_sinter_noise_profile_lut_weight_lut(const QString)));

    connect(ptCb_lut3d_mem,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_lut3d_mem(int)));
    connect(ptEdit_lut3d_mem,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_lut3d_mem(const QString)));

    setLayout(mainLayout);
}

void IspPPsinter::clickedSlot(bool checked)
{
    QString str_config1 = ptEdit_config1->text();
    QString str_config2 = ptEdit_config2->text();
    QString str_black_level = ptEdit_black_level->text();
    QString str_weight_lut = ptEdit_weight_lut->text();
    QString str_reg_noise_level_0 = ptEdit_reg_noise_level_0->text();
    QString str_reg_use_lut = ptEdit_reg_use_lut->text();
    QString str_thresh1 = ptEdit_thresh1->text();
    QString str_thresh2 = ptEdit_thresh2->text();
    QString str_thresh3 = ptEdit_thresh3->text();
    QString str_reg_rm_center_x = ptEdit_reg_rm_center_x->text();
    QString str_reg_strength_0 = ptEdit_reg_strength_0->text();
    QString str_reg_thresh_0h = ptEdit_reg_thresh_0h->text();
    QString str_reg_thresh_0v = ptEdit_reg_thresh_0v->text();
    QString str_rm_off_center_mult = ptEdit_rm_off_center_mult->text();
    QString str_sad_filt_thresh = ptEdit_sad_filt_thresh->text();
    QString str_rm_shading_lut = ptEdit_rm_shading_lut->text();
}

void IspPPsinter::activatedSlot_sinter_shading_rm_shading_lut(int index)
{
    ptEdit_sinter_shading_rm_shading_lut->setText(szQStr_sinter_shading_rm_shading_lut[index]);
}

void IspPPsinter::textChangedSlot_sinter_shading_rm_shading_lut(const QString &text)
{
    int index = ptCb_sinter_shading_rm_shading_lut->currentIndex();
    szQStr_sinter_shading_rm_shading_lut[index] = text;
}

void IspPPsinter::activatedSlot_sinter_noise_profile_lut_weight_lut(int index)
{
    ptEdit_sinter_noise_profile_lut_weight_lut->setText(szQStr_sinter_noise_profile_lut_weight_lut[index]);
}

void IspPPsinter::textChangedSlot_sinter_noise_profile_lut_weight_lut(const QString &text)
{
    int index = ptCb_sinter_noise_profile_lut_weight_lut->currentIndex();
    szQStr_sinter_noise_profile_lut_weight_lut[index] = text;
}

void IspPPsinter::activatedSlot_lut3d_mem(int index)
{
    ptEdit_lut3d_mem->setText(szQStr_lut3d_mem[index]);
}

void IspPPsinter::textChangedSlot_lut3d_mem(const QString &text)
{
    int index = ptCb_lut3d_mem->currentIndex();
    szQStr_lut3d_mem[index] = text;
}
