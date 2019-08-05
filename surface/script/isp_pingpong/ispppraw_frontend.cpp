#include "ispppraw_frontend.h"
#include <QGridLayout>
IspPPraw_frontend::IspPPraw_frontend(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    // add edit
    ptLabel_exp_thresh  = new QLabel("exp_thresh :");
    ptEdit_exp_thresh  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_exp_thresh ,0,0);layoutGrid->addWidget(ptEdit_exp_thresh ,0,1);

    ptLabel_weight_lut  = new QLabel("weight_lut :");
    ptEdit_weight_lut  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_weight_lut ,1,0);layoutGrid->addWidget(ptEdit_weight_lut ,1,1);

    ptLabel_reg_short_ratio  = new QLabel("reg_short_ratio :");
    ptEdit_reg_short_ratio  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_short_ratio ,2,0);layoutGrid->addWidget(ptEdit_reg_short_ratio ,2,1);

    ptLabel_reg_dpdev_threshold  = new QLabel("reg_dpdev_threshold :");
    ptEdit_reg_dpdev_threshold  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_dpdev_threshold ,3,0);layoutGrid->addWidget(ptEdit_reg_dpdev_threshold ,3,1);

    ptLabel_reg_dp_slope  = new QLabel("reg_dp_slope :");
    ptEdit_reg_dp_slope  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_dp_slope ,4,0);layoutGrid->addWidget(ptEdit_reg_dp_slope ,4,1);

    ptLabel_reg_ge_slope  = new QLabel("reg_ge_slope :");
    ptEdit_reg_ge_slope  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_ge_slope ,5,0);layoutGrid->addWidget(ptEdit_reg_ge_slope ,5,1);

    ptLabel_reg_ge_strength  = new QLabel("reg_ge_strength :");
    ptEdit_reg_ge_strength  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_ge_strength ,6,0);layoutGrid->addWidget(ptEdit_reg_ge_strength ,6,1);

    ptLabel_reg_line_thresh  = new QLabel("reg_line_thresh :");
    ptEdit_reg_line_thresh  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_line_thresh ,7,0);layoutGrid->addWidget(ptEdit_reg_line_thresh ,7,1);

    ptLabel_reg_thresh_short  = new QLabel("reg_thresh_short :");
    ptEdit_reg_thresh_short  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_thresh_short ,8,0);layoutGrid->addWidget(ptEdit_reg_thresh_short ,8,1);

    ptCb_raw_frontend_np_lut_weight_lut  = new QComboBox;
    ptEdit_raw_frontend_np_lut_weight_lut = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_raw_frontend_np_lut_weight_lut,9,0);layoutGrid->addWidget(ptEdit_raw_frontend_np_lut_weight_lut,9,1);
    for(unsigned int i = 0;i < M_RAW_FRONTED_NP_LUT_WEIGHT_LUT_NUMBER; ++i)
    {
        QString str;
        str.sprintf("raw_frontend_np_lut.weight_lut[%x]",i);
        ptCb_raw_frontend_np_lut_weight_lut->addItem(str);
        szQStr_raw_frontend_np_lut_weight_lut[i].sprintf("%x",i);
    }
    ptEdit_raw_frontend_np_lut_weight_lut->setText(szQStr_raw_frontend_np_lut_weight_lut[ptCb_raw_frontend_np_lut_weight_lut->currentIndex()]);

    ptPBtn = new QPushButton("确定");
    layoutGrid->addWidget(ptPBtn,40,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

    connect(ptCb_raw_frontend_np_lut_weight_lut,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_raw_frontend_np_lut_weight_lut(int)));
    connect(ptEdit_raw_frontend_np_lut_weight_lut,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_raw_frontend_np_lut_weight_lut(const QString)));

    setLayout(mainLayout);
}

void IspPPraw_frontend::clickedSlot(bool checked)
{
    QString str_exp_thresh = ptEdit_exp_thresh->text();
    QString str_weight_lut = ptEdit_weight_lut->text();
    QString str_reg_short_ratio = ptEdit_reg_short_ratio->text();
    QString str_reg_dpdev_threshold = ptEdit_reg_dpdev_threshold->text();
    QString str_reg_dp_slope = ptEdit_reg_dp_slope->text();
    QString str_reg_ge_slope = ptEdit_reg_ge_slope->text();
    QString str_reg_ge_strength = ptEdit_reg_ge_strength->text();
    QString str_reg_line_thresh = ptEdit_reg_line_thresh->text();
    QString str_reg_thresh_short = ptEdit_reg_thresh_short->text();
}

void IspPPraw_frontend::activatedSlot_raw_frontend_np_lut_weight_lut(int index)
{
    ptEdit_raw_frontend_np_lut_weight_lut->setText(szQStr_raw_frontend_np_lut_weight_lut[index]);
}

void IspPPraw_frontend::textChangedSlot_raw_frontend_np_lut_weight_lut(const QString &text)
{
    int index = ptCb_raw_frontend_np_lut_weight_lut->currentIndex();
    szQStr_raw_frontend_np_lut_weight_lut[index] = text;
}
