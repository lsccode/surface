#include "ispppframe_stitch.h"
#include <QGridLayout>
IspPPframe_stitch::IspPPframe_stitch(QWidget *parent) :
    QWidget(parent)
{
    init_array();

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
//        szQStr_frame_stitch_np_lut_l_weight_lut[i].sprintf("%x",i);
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
//        szQStr_frame_stitch_np_lut_m_weight_lut[i].sprintf("%x",i);
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
//        szQStr_frame_stitch_np_lut_s_weight_lut[i].sprintf("%x",i);
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
//        szQStr_frame_stitch_np_lut_vs_weight_lut[i].sprintf("%x",i);
    }
    ptEdit_frame_stitch_np_lut_vs_weight_lut->setText(szQStr_frame_stitch_np_lut_vs_weight_lut[ptCb_frame_stitch_np_lut_vs_weight_lut->currentIndex()]);

//    ptPBtn = new QPushButton("确定");
//    layoutGrid->addWidget(ptPBtn,40,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

//    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

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

void IspPPframe_stitch::init_array()
{
    init_frame_stitch_np_lut_l_weight_lut();
    init_frame_stitch_np_lut_m_weight_lut();
    init_frame_stitch_np_lut_s_weight_lut();
    init_frame_stitch_np_lut_vs_weight_lut();
}

void IspPPframe_stitch::init_frame_stitch_np_lut_l_weight_lut()
{
    szQStr_frame_stitch_np_lut_l_weight_lut[0x0] = "00000086";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x1] = "00000018";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x2] = "00000007";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x3] = "00000008";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x4] = "00000061";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x5] = "0000000f";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x6] = "00000066";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x7] = "0000003a";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x8] = "0000005f";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x9] = "0000001a";
    szQStr_frame_stitch_np_lut_l_weight_lut[0xa] = "000000a3";
    szQStr_frame_stitch_np_lut_l_weight_lut[0xb] = "00000020";
    szQStr_frame_stitch_np_lut_l_weight_lut[0xc] = "00000017";
    szQStr_frame_stitch_np_lut_l_weight_lut[0xd] = "00000024";
    szQStr_frame_stitch_np_lut_l_weight_lut[0xe] = "00000035";
    szQStr_frame_stitch_np_lut_l_weight_lut[0xf] = "00000026";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x10] = "000000e9";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x11] = "000000d7";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x12] = "0000002e";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x13] = "000000c8";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x14] = "000000f1";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x15] = "000000ef";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x16] = "00000014";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x17] = "0000002b";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x18] = "000000fa";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x19] = "000000f6";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x1a] = "00000045";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x1b] = "00000031";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x1c] = "00000006";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x1d] = "0000000b";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x1e] = "00000033";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x1f] = "0000003b";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x20] = "0000001a";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x21] = "00000057";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x22] = "00000010";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x23] = "000000e2";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x24] = "000000fb";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x25] = "00000011";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x26] = "00000086";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x27] = "00000047";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x28] = "0000000b";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x29] = "00000044";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x2a] = "000000c5";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x2b] = "0000000c";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x2c] = "00000033";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x2d] = "00000005";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x2e] = "0000002f";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x2f] = "00000090";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x30] = "000000b3";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x31] = "00000027";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x32] = "00000016";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x33] = "00000014";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x34] = "00000086";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x35] = "000000b6";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x36] = "00000063";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x37] = "00000005";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x38] = "0000007e";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x39] = "00000012";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x3a] = "000000c3";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x3b] = "0000001f";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x3c] = "0000000b";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x3d] = "000000df";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x3e] = "00000021";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x3f] = "000000db";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x40] = "0000005e";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x41] = "00000090";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x42] = "00000001";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x43] = "000000aa";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x44] = "00000002";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x45] = "0000005a";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x46] = "000000f2";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x47] = "0000000b";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x48] = "000000e2";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x49] = "000000cd";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x4a] = "00000032";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x4b] = "00000023";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x4c] = "0000001b";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x4d] = "0000007d";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x4e] = "0000002a";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x4f] = "0000001b";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x50] = "000000e0";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x51] = "00000058";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x52] = "000000c8";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x53] = "000000c0";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x54] = "000000dd";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x55] = "0000009b";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x56] = "00000053";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x57] = "0000007c";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x58] = "00000008";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x59] = "0000006b";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x5a] = "000000a8";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x5b] = "0000002b";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x5c] = "00000011";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x5d] = "0000000e";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x5e] = "00000015";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x5f] = "00000000";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x60] = "000000f7";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x61] = "00000027";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x62] = "00000027";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x63] = "00000075";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x64] = "000000ea";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x65] = "0000005e";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x66] = "000000bd";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x67] = "0000003a";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x68] = "00000016";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x69] = "000000e9";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x6a] = "00000003";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x6b] = "000000b7";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x6c] = "0000005e";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x6d] = "00000026";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x6e] = "0000002b";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x6f] = "00000063";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x70] = "00000046";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x71] = "00000037";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x72] = "000000cf";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x73] = "00000012";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x74] = "00000028";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x75] = "0000002c";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x76] = "000000a1";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x77] = "000000a8";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x78] = "000000ee";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x79] = "000000de";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x7a] = "000000b5";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x7b] = "00000079";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x7c] = "0000003b";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x7d] = "00000053";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x7e] = "00000099";
    szQStr_frame_stitch_np_lut_l_weight_lut[0x7f] = "0000003a";
}

void IspPPframe_stitch::init_frame_stitch_np_lut_m_weight_lut()
{
    szQStr_frame_stitch_np_lut_m_weight_lut[0x0] = "0000003c";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x1] = "0000002c";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x2] = "0000002f";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x3] = "0000000a";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x4] = "0000004b";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x5] = "00000065";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x6] = "00000025";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x7] = "00000024";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x8] = "00000011";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x9] = "000000e6";
    szQStr_frame_stitch_np_lut_m_weight_lut[0xa] = "000000f0";
    szQStr_frame_stitch_np_lut_m_weight_lut[0xb] = "00000086";
    szQStr_frame_stitch_np_lut_m_weight_lut[0xc] = "00000045";
    szQStr_frame_stitch_np_lut_m_weight_lut[0xd] = "0000005b";
    szQStr_frame_stitch_np_lut_m_weight_lut[0xe] = "0000004d";
    szQStr_frame_stitch_np_lut_m_weight_lut[0xf] = "000000fa";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x10] = "000000bc";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x11] = "0000002d";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x12] = "000000fc";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x13] = "00000035";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x14] = "0000000f";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x15] = "00000019";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x16] = "0000009a";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x17] = "0000006d";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x18] = "00000097";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x19] = "000000b7";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x1a] = "0000003e";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x1b] = "00000060";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x1c] = "0000001d";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x1d] = "00000024";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x1e] = "00000028";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x1f] = "000000eb";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x20] = "0000001a";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x21] = "00000044";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x22] = "0000000d";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x23] = "00000002";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x24] = "0000002a";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x25] = "0000002e";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x26] = "00000011";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x27] = "0000008d";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x28] = "000000af";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x29] = "00000052";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x2a] = "00000005";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x2b] = "00000052";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x2c] = "00000008";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x2d] = "000000d3";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x2e] = "0000000e";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x2f] = "0000000d";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x30] = "000000ab";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x31] = "000000d8";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x32] = "00000038";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x33] = "00000004";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x34] = "000000e2";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x35] = "00000045";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x36] = "000000bf";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x37] = "00000080";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x38] = "00000019";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x39] = "000000f1";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x3a] = "00000082";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x3b] = "000000ac";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x3c] = "00000002";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x3d] = "0000000b";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x3e] = "000000a6";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x3f] = "00000062";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x40] = "0000001c";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x41] = "00000037";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x42] = "0000003c";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x43] = "00000008";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x44] = "000000d9";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x45] = "0000001a";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x46] = "00000026";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x47] = "0000000b";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x48] = "0000001f";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x49] = "0000007e";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x4a] = "00000080";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x4b] = "0000000f";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x4c] = "0000002a";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x4d] = "00000057";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x4e] = "00000026";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x4f] = "000000a4";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x50] = "00000092";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x51] = "00000040";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x52] = "0000003e";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x53] = "00000095";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x54] = "000000f1";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x55] = "000000ae";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x56] = "0000000d";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x57] = "00000066";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x58] = "00000012";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x59] = "000000a0";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x5a] = "0000008c";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x5b] = "000000df";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x5c] = "00000002";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x5d] = "0000008b";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x5e] = "0000003b";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x5f] = "000000d9";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x60] = "000000e4";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x61] = "00000084";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x62] = "000000ad";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x63] = "0000000d";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x64] = "0000001a";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x65] = "00000036";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x66] = "0000008d";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x67] = "000000be";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x68] = "0000003e";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x69] = "0000002b";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x6a] = "0000000a";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x6b] = "00000030";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x6c] = "00000020";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x6d] = "00000093";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x6e] = "0000000d";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x6f] = "000000ca";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x70] = "000000e0";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x71] = "000000c6";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x72] = "0000001f";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x73] = "00000030";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x74] = "000000eb";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x75] = "00000017";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x76] = "00000052";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x77] = "000000f9";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x78] = "0000002c";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x79] = "0000006c";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x7a] = "00000013";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x7b] = "0000003d";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x7c] = "000000bf";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x7d] = "000000b6";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x7e] = "00000015";
    szQStr_frame_stitch_np_lut_m_weight_lut[0x7f] = "000000fe";
}

void IspPPframe_stitch::init_frame_stitch_np_lut_s_weight_lut()
{
    szQStr_frame_stitch_np_lut_s_weight_lut[0x0] = "0000000c";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x1] = "000000e2";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x2] = "00000024";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x3] = "00000027";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x4] = "0000000a";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x5] = "00000027";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x6] = "00000004";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x7] = "0000003f";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x8] = "000000e1";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x9] = "00000037";
    szQStr_frame_stitch_np_lut_s_weight_lut[0xa] = "0000003e";
    szQStr_frame_stitch_np_lut_s_weight_lut[0xb] = "0000003d";
    szQStr_frame_stitch_np_lut_s_weight_lut[0xc] = "000000b1";
    szQStr_frame_stitch_np_lut_s_weight_lut[0xd] = "000000f4";
    szQStr_frame_stitch_np_lut_s_weight_lut[0xe] = "00000044";
    szQStr_frame_stitch_np_lut_s_weight_lut[0xf] = "0000002a";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x10] = "00000013";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x11] = "00000036";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x12] = "00000010";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x13] = "00000038";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x14] = "00000029";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x15] = "00000011";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x16] = "0000000a";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x17] = "000000ec";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x18] = "00000033";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x19] = "00000095";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x1a] = "000000af";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x1b] = "0000001e";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x1c] = "00000063";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x1d] = "000000c6";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x1e] = "00000037";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x1f] = "00000043";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x20] = "000000d1";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x21] = "000000e7";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x22] = "000000d7";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x23] = "0000003b";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x24] = "00000030";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x25] = "0000002b";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x26] = "00000014";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x27] = "0000003e";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x28] = "00000072";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x29] = "00000057";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x2a] = "000000ca";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x2b] = "0000002c";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x2c] = "000000b7";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x2d] = "00000014";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x2e] = "00000003";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x2f] = "0000007f";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x30] = "00000004";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x31] = "00000035";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x32] = "0000003c";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x33] = "0000003b";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x34] = "0000006c";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x35] = "000000ca";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x36] = "00000068";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x37] = "0000003b";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x38] = "00000089";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x39] = "000000e9";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x3a] = "00000038";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x3b] = "00000022";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x3c] = "0000008c";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x3d] = "00000007";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x3e] = "00000016";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x3f] = "00000001";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x40] = "000000bd";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x41] = "000000e4";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x42] = "0000003a";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x43] = "00000022";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x44] = "000000c0";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x45] = "0000009d";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x46] = "00000034";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x47] = "000000a3";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x48] = "0000000a";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x49] = "0000001d";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x4a] = "000000ce";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x4b] = "0000002b";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x4c] = "00000029";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x4d] = "000000c5";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x4e] = "000000ea";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x4f] = "00000091";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x50] = "0000000e";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x51] = "000000aa";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x52] = "00000064";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x53] = "0000000f";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x54] = "00000073";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x55] = "000000a8";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x56] = "00000010";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x57] = "00000018";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x58] = "0000002f";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x59] = "00000019";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x5a] = "00000001";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x5b] = "000000fa";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x5c] = "000000ad";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x5d] = "00000038";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x5e] = "00000071";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x5f] = "0000003e";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x60] = "00000068";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x61] = "000000a7";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x62] = "0000007d";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x63] = "00000057";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x64] = "0000003f";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x65] = "00000028";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x66] = "0000005f";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x67] = "00000036";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x68] = "00000024";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x69] = "0000003c";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x6a] = "000000cd";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x6b] = "00000031";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x6c] = "0000002f";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x6d] = "00000008";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x6e] = "00000025";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x6f] = "00000004";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x70] = "000000ab";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x71] = "0000003f";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x72] = "00000064";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x73] = "000000d3";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x74] = "00000036";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x75] = "00000094";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x76] = "000000bb";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x77] = "00000038";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x78] = "000000fd";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x79] = "0000002e";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x7a] = "00000004";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x7b] = "0000001e";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x7c] = "000000c3";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x7d] = "00000027";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x7e] = "0000009e";
    szQStr_frame_stitch_np_lut_s_weight_lut[0x7f] = "0000003b";
}

void IspPPframe_stitch::init_frame_stitch_np_lut_vs_weight_lut()
{
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x0] = "0000000e";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x1] = "00000020";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x2] = "00000015";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x3] = "0000008b";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x4] = "00000013";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x5] = "0000001b";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x6] = "00000021";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x7] = "0000003a";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x8] = "00000082";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x9] = "0000000d";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0xa] = "0000001c";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0xb] = "00000007";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0xc] = "000000bd";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0xd] = "00000035";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0xe] = "000000df";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0xf] = "0000000c";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x10] = "00000065";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x11] = "00000076";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x12] = "00000039";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x13] = "000000fc";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x14] = "0000005d";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x15] = "0000007e";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x16] = "00000043";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x17] = "00000018";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x18] = "00000035";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x19] = "00000056";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x1a] = "000000a0";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x1b] = "00000001";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x1c] = "000000c8";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x1d] = "00000021";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x1e] = "0000000f";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x1f] = "00000036";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x20] = "0000007f";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x21] = "00000015";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x22] = "00000005";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x23] = "0000003b";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x24] = "00000059";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x25] = "00000008";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x26] = "000000e7";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x27] = "0000002f";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x28] = "000000a9";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x29] = "00000038";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x2a] = "0000002d";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x2b] = "00000087";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x2c] = "00000014";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x2d] = "0000000c";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x2e] = "00000019";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x2f] = "0000005a";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x30] = "0000002e";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x31] = "000000e1";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x32] = "0000000c";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x33] = "0000008f";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x34] = "00000021";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x35] = "00000000";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x36] = "000000ee";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x37] = "00000051";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x38] = "0000000e";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x39] = "0000001e";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x3a] = "00000037";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x3b] = "000000e3";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x3c] = "00000026";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x3d] = "00000033";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x3e] = "00000092";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x3f] = "000000f2";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x40] = "0000006e";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x41] = "000000ff";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x42] = "000000a8";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x43] = "00000084";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x44] = "00000032";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x45] = "0000006b";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x46] = "000000b7";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x47] = "0000000f";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x48] = "00000067";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x49] = "0000002c";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x4a] = "00000026";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x4b] = "00000026";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x4c] = "00000053";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x4d] = "000000f7";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x4e] = "0000003f";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x4f] = "00000010";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x50] = "00000027";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x51] = "000000a4";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x52] = "00000064";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x53] = "0000006d";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x54] = "000000aa";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x55] = "0000008a";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x56] = "000000c9";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x57] = "00000020";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x58] = "00000034";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x59] = "00000036";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x5a] = "00000030";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x5b] = "00000011";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x5c] = "0000003e";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x5d] = "00000006";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x5e] = "000000f1";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x5f] = "000000d8";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x60] = "00000059";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x61] = "00000096";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x62] = "00000064";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x63] = "00000004";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x64] = "0000002b";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x65] = "0000006a";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x66] = "0000008a";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x67] = "0000003b";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x68] = "000000ee";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x69] = "0000004c";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x6a] = "00000085";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x6b] = "000000d5";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x6c] = "00000097";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x6d] = "00000022";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x6e] = "0000004b";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x6f] = "00000017";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x70] = "000000f3";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x71] = "00000013";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x72] = "00000022";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x73] = "00000045";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x74] = "0000006c";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x75] = "0000002f";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x76] = "00000017";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x77] = "0000001f";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x78] = "0000006b";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x79] = "00000025";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x7a] = "0000003c";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x7b] = "00000060";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x7c] = "00000034";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x7d] = "0000001c";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x7e] = "00000046";
    szQStr_frame_stitch_np_lut_vs_weight_lut[0x7f] = "00000016";
}

void IspPPframe_stitch::step1()
{
    for(unsigned int i = 0;i < M_FRAME_STICH_NP_LUT_X_WEIGHT_NUMBER; ++i)
    {
        QString strLine;
        strLine.sprintf("isp_config_ping.frame_stitch_np_lut_l.weight_lut[%x]",i);

        writeLine(E_ACTION_WR,strLine,szQStr_frame_stitch_np_lut_l_weight_lut[i]);
        writeLine(E_ACTION_RR,strLine);
    }

    for(unsigned int i = 0;i < M_FRAME_STICH_NP_LUT_X_WEIGHT_NUMBER; ++i)
    {
        QString strLine;
        strLine.sprintf("isp_config_ping.frame_stitch_np_lut_m.weight_lut[%x]",i);

        writeLine(E_ACTION_WR,strLine,szQStr_frame_stitch_np_lut_m_weight_lut[i]);
        writeLine(E_ACTION_RR,strLine);
    }

    for(unsigned int i = 0;i < M_FRAME_STICH_NP_LUT_X_WEIGHT_NUMBER; ++i)
    {
        QString strLine;
        strLine.sprintf("isp_config_ping.frame_stitch_np_lut_s.weight_lut[%x]",i);

        writeLine(E_ACTION_WR,strLine,szQStr_frame_stitch_np_lut_s_weight_lut[i]);
        writeLine(E_ACTION_RR,strLine);
    }

    for(unsigned int i = 0;i < M_FRAME_STICH_NP_LUT_X_WEIGHT_NUMBER; ++i)
    {
        QString strLine;
        strLine.sprintf("isp_config_ping.frame_stitch_np_lut_vs.weight_lut[%x]",i);

        writeLine(E_ACTION_WR,strLine,szQStr_frame_stitch_np_lut_vs_weight_lut[i]);
        writeLine(E_ACTION_RR,strLine);
    }
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
