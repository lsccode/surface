#include "ispppframe_stitch.h"
#include <QGridLayout>
IspPPframe_stitch::IspPPframe_stitch(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    // add edit

    ptCb_frame_stitch_np_lut_l_weight_lut  = new QComboBox;
    ptEdit_frame_stitch_np_lut_l_weight_lut = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_frame_stitch_np_lut_l_weight_lut,0,0);layoutGrid->addWidget(ptEdit_frame_stitch_np_lut_l_weight_lut,0,1);
    for(unsigned int i = 0;i < M_FRAME_STICH_NP_LUT_X_WEIGHT_NUMBER; ++i)
    {
        QString str;
        str.sprintf("frame_stitch_np_lut_l.weight_lut[%x]",i);
        ptCb_frame_stitch_np_lut_l_weight_lut->addItem(str);
        szQStr_frame_stitch_np_lut_l_weight_lut[i].sprintf("%x",i);
    }
    ptEdit_frame_stitch_np_lut_l_weight_lut->setText(szQStr_frame_stitch_np_lut_l_weight_lut[ptCb_frame_stitch_np_lut_l_weight_lut->currentIndex()]);

    ptCb_frame_stitch_np_lut_m_weight_lut  = new QComboBox;
    ptEdit_frame_stitch_np_lut_m_weight_lut = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_frame_stitch_np_lut_m_weight_lut,1,0);layoutGrid->addWidget(ptEdit_frame_stitch_np_lut_m_weight_lut,1,1);
    for(unsigned int i = 0;i < M_FRAME_STICH_NP_LUT_X_WEIGHT_NUMBER; ++i)
    {
        QString str;
        str.sprintf("frame_stitch_np_lut_m.weight_lut[%x]",i);
        ptCb_frame_stitch_np_lut_m_weight_lut->addItem(str);
        szQStr_frame_stitch_np_lut_m_weight_lut[i].sprintf("%x",i);
    }
    ptEdit_frame_stitch_np_lut_m_weight_lut->setText(szQStr_frame_stitch_np_lut_m_weight_lut[ptCb_frame_stitch_np_lut_m_weight_lut->currentIndex()]);

    ptCb_frame_stitch_np_lut_s_weight_lut  = new QComboBox;
    ptEdit_frame_stitch_np_lut_s_weight_lut = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_frame_stitch_np_lut_s_weight_lut,2,0);layoutGrid->addWidget(ptEdit_frame_stitch_np_lut_s_weight_lut,2,1);
    for(unsigned int i = 0;i < M_FRAME_STICH_NP_LUT_X_WEIGHT_NUMBER; ++i)
    {
        QString str;
        str.sprintf("frame_stitch_np_lut_s.weight_lut[%x]",i);
        ptCb_frame_stitch_np_lut_s_weight_lut->addItem(str);
        szQStr_frame_stitch_np_lut_s_weight_lut[i].sprintf("%x",i);
    }
    ptEdit_frame_stitch_np_lut_s_weight_lut->setText(szQStr_frame_stitch_np_lut_s_weight_lut[ptCb_frame_stitch_np_lut_s_weight_lut->currentIndex()]);

    ptCb_frame_stitch_np_lut_vs_weight_lut  = new QComboBox;
    ptEdit_frame_stitch_np_lut_vs_weight_lut = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_frame_stitch_np_lut_vs_weight_lut,3,0);layoutGrid->addWidget(ptEdit_frame_stitch_np_lut_vs_weight_lut,3,1);
    for(unsigned int i = 0;i < M_FRAME_STICH_NP_LUT_X_WEIGHT_NUMBER; ++i)
    {
        QString str;
        str.sprintf("frame_stitch_np_lut_vs.weight_lut[%x]",i);
        ptCb_frame_stitch_np_lut_vs_weight_lut->addItem(str);
        szQStr_frame_stitch_np_lut_vs_weight_lut[i].sprintf("%x",i);
    }
    ptEdit_frame_stitch_np_lut_vs_weight_lut->setText(szQStr_frame_stitch_np_lut_vs_weight_lut[ptCb_frame_stitch_np_lut_vs_weight_lut->currentIndex()]);

    ptPBtn = new QPushButton("确定");
    layoutGrid->addWidget(ptPBtn,40,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

    connect(ptCb_frame_stitch_np_lut_l_weight_lut,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_frame_stitch_np_lut_l_weight_lut(int)));
    connect(ptEdit_frame_stitch_np_lut_l_weight_lut,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_frame_stitch_np_lut_l_weight_lut(const QString)));

    connect(ptCb_frame_stitch_np_lut_m_weight_lut,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_frame_stitch_np_lut_m_weight_lut(int)));
    connect(ptEdit_frame_stitch_np_lut_m_weight_lut,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_frame_stitch_np_lut_m_weight_lut(const QString)));

    connect(ptCb_frame_stitch_np_lut_s_weight_lut,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_frame_stitch_np_lut_s_weight_lut(int)));
    connect(ptEdit_frame_stitch_np_lut_s_weight_lut,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_frame_stitch_np_lut_s_weight_lut(const QString)));

    connect(ptCb_frame_stitch_np_lut_vs_weight_lut,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_frame_stitch_np_lut_vs_weight_lut(int)));
    connect(ptEdit_frame_stitch_np_lut_vs_weight_lut,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_frame_stitch_np_lut_vs_weight_lut(const QString)));

    setLayout(mainLayout);
}

void IspPPframe_stitch::clickedSlot(bool checked)
{

}

void IspPPframe_stitch::activatedSlot_frame_stitch_np_lut_l_weight_lut(int index)
{
    ptEdit_frame_stitch_np_lut_l_weight_lut->setText(szQStr_frame_stitch_np_lut_l_weight_lut[index]);
}

void IspPPframe_stitch::textChangedSlot_frame_stitch_np_lut_l_weight_lut(const QString &text)
{
    int index = ptCb_frame_stitch_np_lut_l_weight_lut->currentIndex();
    szQStr_frame_stitch_np_lut_l_weight_lut[index] = text;
}

void IspPPframe_stitch::activatedSlot_frame_stitch_np_lut_m_weight_lut(int index)
{
    ptEdit_frame_stitch_np_lut_m_weight_lut->setText(szQStr_frame_stitch_np_lut_m_weight_lut[index]);
}

void IspPPframe_stitch::textChangedSlot_frame_stitch_np_lut_m_weight_lut(const QString &text)
{
    int index = ptCb_frame_stitch_np_lut_m_weight_lut->currentIndex();
    szQStr_frame_stitch_np_lut_m_weight_lut[index] = text;
}

void IspPPframe_stitch::activatedSlot_frame_stitch_np_lut_s_weight_lut(int index)
{
    ptEdit_frame_stitch_np_lut_s_weight_lut->setText(szQStr_frame_stitch_np_lut_s_weight_lut[index]);
}

void IspPPframe_stitch::textChangedSlot_frame_stitch_np_lut_s_weight_lut(const QString &text)
{
    int index = ptCb_frame_stitch_np_lut_s_weight_lut->currentIndex();
    szQStr_frame_stitch_np_lut_s_weight_lut[index] = text;
}

void IspPPframe_stitch::activatedSlot_frame_stitch_np_lut_vs_weight_lut(int index)
{
    ptEdit_frame_stitch_np_lut_vs_weight_lut->setText(szQStr_frame_stitch_np_lut_vs_weight_lut[index]);
}

void IspPPframe_stitch::textChangedSlot_frame_stitch_np_lut_vs_weight_lut(const QString &text)
{
    int index = ptCb_frame_stitch_np_lut_vs_weight_lut->currentIndex();
    szQStr_frame_stitch_np_lut_vs_weight_lut[index] = text;
}
