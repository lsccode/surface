#include "ispppsinter.h"
#include <QGridLayout>
IspPPsinter::IspPPsinter(QWidget *parent) :
    QWidget(parent)
{
    init_array();

    QGridLayout *layoutGrid = new QGridLayout;

    // add edit
    ptLabel_config1  = new QLabel("config1 :");
    ptEdit_config1  = new QLineEdit("000000dc");
    layoutGrid->addWidget(ptLabel_config1 ,0,0);layoutGrid->addWidget(ptEdit_config1 ,0,1);

    ptLabel_config2  = new QLabel("config2 :");
    ptEdit_config2  = new QLineEdit("00000009");
    layoutGrid->addWidget(ptLabel_config2 ,1,0);layoutGrid->addWidget(ptEdit_config2 ,1,1);

    ptLabel_black_level  = new QLabel("black_level :");
    ptEdit_black_level  = new QLineEdit("000026c5");
    layoutGrid->addWidget(ptLabel_black_level ,2,0);layoutGrid->addWidget(ptEdit_black_level ,2,1);

//    ptLabel_weight_lut  = new QLabel("weight_lut :");
//    ptEdit_weight_lut  = new QLineEdit("000000001");
//    layoutGrid->addWidget(ptLabel_weight_lut ,3,0);layoutGrid->addWidget(ptEdit_weight_lut ,3,1);

    ptLabel_reg_noise_level_0  = new QLabel("reg_noise_level_0 :");
    ptEdit_reg_noise_level_0  = new QLineEdit("3f3d3d3d");
    layoutGrid->addWidget(ptLabel_reg_noise_level_0 ,4,0);layoutGrid->addWidget(ptEdit_reg_noise_level_0 ,4,1);

    ptLabel_reg_use_lut  = new QLabel("reg_use_lut :");
    ptEdit_reg_use_lut  = new QLineEdit("0000a404");
    layoutGrid->addWidget(ptLabel_reg_use_lut ,5,0);layoutGrid->addWidget(ptEdit_reg_use_lut ,5,1);

    ptLabel_thresh1  = new QLabel("thresh1 :");
    ptEdit_thresh1  = new QLineEdit("00000012");
    layoutGrid->addWidget(ptLabel_thresh1 ,6,0);layoutGrid->addWidget(ptEdit_thresh1 ,6,1);

    ptLabel_thresh2  = new QLabel("thresh2 :");
    ptEdit_thresh2  = new QLineEdit("0000041f");
    layoutGrid->addWidget(ptLabel_thresh2 ,7,0);layoutGrid->addWidget(ptEdit_thresh2 ,7,1);

    ptLabel_thresh3  = new QLabel("thresh3 :");
    ptEdit_thresh3  = new QLineEdit("00009895");
    layoutGrid->addWidget(ptLabel_thresh3 ,8,0);layoutGrid->addWidget(ptEdit_thresh3 ,8,1);

    ptLabel_reg_rm_center_x  = new QLabel("reg_rm_center_x :");
    ptEdit_reg_rm_center_x  = new QLineEdit("00410041");
    layoutGrid->addWidget(ptLabel_reg_rm_center_x ,9,0);layoutGrid->addWidget(ptEdit_reg_rm_center_x ,9,1);

    ptLabel_reg_strength_0  = new QLabel("reg_strength_0 :");
    ptEdit_reg_strength_0  = new QLineEdit("2cf722d6");
    layoutGrid->addWidget(ptLabel_reg_strength_0 ,10,0);layoutGrid->addWidget(ptEdit_reg_strength_0 ,10,1);

    ptLabel_reg_thresh_0h  = new QLabel("reg_thresh_0h :");
    ptEdit_reg_thresh_0h  = new QLineEdit("2a89566c");
    layoutGrid->addWidget(ptLabel_reg_thresh_0h ,11,0);layoutGrid->addWidget(ptEdit_reg_thresh_0h ,11,1);

    ptLabel_reg_thresh_0v  = new QLabel("reg_thresh_0v :");
    ptEdit_reg_thresh_0v  = new QLineEdit("5f9709be");
    layoutGrid->addWidget(ptLabel_reg_thresh_0v ,12,0);layoutGrid->addWidget(ptEdit_reg_thresh_0v ,12,1);

    ptLabel_rm_off_center_mult  = new QLabel("rm_off_center_mult :");
    ptEdit_rm_off_center_mult  = new QLineEdit("0000ffff");
    layoutGrid->addWidget(ptLabel_rm_off_center_mult ,13,0);layoutGrid->addWidget(ptEdit_rm_off_center_mult ,13,1);

    ptLabel_sad_filt_thresh  = new QLabel("sad_filt_thresh :");
    ptEdit_sad_filt_thresh  = new QLineEdit("000000ea");
    layoutGrid->addWidget(ptLabel_sad_filt_thresh ,14,0);layoutGrid->addWidget(ptEdit_sad_filt_thresh ,14,1);

    ptCb_sinter_shading_rm_shading_lut  = new QComboBox;
    ptEdit_sinter_shading_rm_shading_lut = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_sinter_shading_rm_shading_lut,9,0);layoutGrid->addWidget(ptEdit_sinter_shading_rm_shading_lut,9,1);
    for(unsigned int i = 0;i < M_SINTER_SHADING_RM_SHADING_LUT_NUMBER; ++i)
    {
        QString str;
        str.sprintf("sinter_shading_rm_shading_lut[%x]",i);
        ptCb_sinter_shading_rm_shading_lut->addItem(str);
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
//        szQStr_lut3d_mem[i].sprintf("%x",i);
    }
    ptEdit_lut3d_mem->setText(szQStr_lut3d_mem[ptCb_lut3d_mem->currentIndex()]);

//    ptPBtn = new QPushButton("确定");
//    layoutGrid->addWidget(ptPBtn,40,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

//    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

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

void IspPPsinter::init_array()
{
    init_lut3d_mem();
    init_rm_Shading_lut();
    init_sinter_noise_profile_lut_weight_lut();
}

void IspPPsinter::init_lut3d_mem()
{

    szQStr_lut3d_mem[0x0] = "00000000";
    szQStr_lut3d_mem[0x1] = "01d00000";
    szQStr_lut3d_mem[0x2] = "00504c00";
    szQStr_lut3d_mem[0x3] = "01f05800";
    szQStr_lut3d_mem[0x4] = "00100025";
    szQStr_lut3d_mem[0x5] = "01b00027";
    szQStr_lut3d_mem[0x6] = "00305018";
    szQStr_lut3d_mem[0x7] = "02008020";
    szQStr_lut3d_mem[0x8] = "03203000";
    szQStr_lut3d_mem[0x9] = "04907000";
    szQStr_lut3d_mem[0xa] = "03908000";
    szQStr_lut3d_mem[0xb] = "04f0bc00";
    szQStr_lut3d_mem[0xc] = "02500018";
    szQStr_lut3d_mem[0xd] = "03500413";
    szQStr_lut3d_mem[0xe] = "03a07011";
    szQStr_lut3d_mem[0xf] = "04a09403";
    szQStr_lut3d_mem[0x10] = "05d09c00";
    szQStr_lut3d_mem[0x11] = "06f0c403";
    szQStr_lut3d_mem[0x12] = "0630f001";
    szQStr_lut3d_mem[0x13] = "07712003";
    szQStr_lut3d_mem[0x14] = "04701c10";
    szQStr_lut3d_mem[0x15] = "05a03c0f";
    szQStr_lut3d_mem[0x16] = "0600c805";
    szQStr_lut3d_mem[0x17] = "0750f808";
    szQStr_lut3d_mem[0x18] = "07f0e405";
    szQStr_lut3d_mem[0x19] = "08f11407";
    szQStr_lut3d_mem[0x1a] = "08814805";
    szQStr_lut3d_mem[0x1b] = "09616c07";
    szQStr_lut3d_mem[0x1c] = "06a05811";
    szQStr_lut3d_mem[0x1d] = "07606814";
    szQStr_lut3d_mem[0x1e] = "0861180b";
    szQStr_lut3d_mem[0x1f] = "0941300d";
    szQStr_lut3d_mem[0x20] = "09c13807";
    szQStr_lut3d_mem[0x21] = "00000000";
    szQStr_lut3d_mem[0x22] = "0a218809";
    szQStr_lut3d_mem[0x23] = "00000000";
    szQStr_lut3d_mem[0x24] = "08207c14";
    szQStr_lut3d_mem[0x25] = "00000000";
    szQStr_lut3d_mem[0x26] = "0a115c0d";
    szQStr_lut3d_mem[0x27] = "00000000";
    szQStr_lut3d_mem[0x28] = "01307400";
    szQStr_lut3d_mem[0x29] = "02809c00";
    szQStr_lut3d_mem[0x2a] = "01c0d400";
    szQStr_lut3d_mem[0x2b] = "0300fc00";
    szQStr_lut3d_mem[0x2c] = "01408008";
    szQStr_lut3d_mem[0x2d] = "0210c812";
    szQStr_lut3d_mem[0x2e] = "01d0d408";
    szQStr_lut3d_mem[0x2f] = "0290e804";
    szQStr_lut3d_mem[0x30] = "03f0c000";
    szQStr_lut3d_mem[0x31] = "0530f401";
    szQStr_lut3d_mem[0x32] = "04812002";
    szQStr_lut3d_mem[0x33] = "05813003";
    szQStr_lut3d_mem[0x34] = "03d0d411";
    szQStr_lut3d_mem[0x35] = "0510e405";
    szQStr_lut3d_mem[0x36] = "04311406";
    szQStr_lut3d_mem[0x37] = "05812c08";
    szQStr_lut3d_mem[0x38] = "06712003";
    szQStr_lut3d_mem[0x39] = "07a15005";
    szQStr_lut3d_mem[0x3a] = "06a14c05";
    szQStr_lut3d_mem[0x3b] = "07e17c07";
    szQStr_lut3d_mem[0x3c] = "06711c08";
    szQStr_lut3d_mem[0x3d] = "07c1500a";
    szQStr_lut3d_mem[0x3e] = "06c1540a";
    szQStr_lut3d_mem[0x3f] = "0801840d";
    szQStr_lut3d_mem[0x40] = "08b17c08";
    szQStr_lut3d_mem[0x41] = "09a1a00a";
    szQStr_lut3d_mem[0x42] = "08f1a80a";
    szQStr_lut3d_mem[0x43] = "09d1cc0c";
    szQStr_lut3d_mem[0x44] = "08d1780d";
    szQStr_lut3d_mem[0x45] = "09b1980e";
    szQStr_lut3d_mem[0x46] = "0911b00f";
    szQStr_lut3d_mem[0x47] = "09f1d011";
    szQStr_lut3d_mem[0x48] = "0a61bc0c";
    szQStr_lut3d_mem[0x49] = "00000000";
    szQStr_lut3d_mem[0x4a] = "0aa1ec0e";
    szQStr_lut3d_mem[0x4b] = "00000000";
    szQStr_lut3d_mem[0x4c] = "0a61b410";
    szQStr_lut3d_mem[0x4d] = "00000000";
    szQStr_lut3d_mem[0x4e] = "0aa1ec13";
    szQStr_lut3d_mem[0x4f] = "00000000";
    szQStr_lut3d_mem[0x50] = "02713c01";
    szQStr_lut3d_mem[0x51] = "03816003";
    szQStr_lut3d_mem[0x52] = "0331b007";
    szQStr_lut3d_mem[0x53] = "0401d00a";
    szQStr_lut3d_mem[0x54] = "0271380c";
    szQStr_lut3d_mem[0x55] = "03215008";
    szQStr_lut3d_mem[0x56] = "0321b013";
    szQStr_lut3d_mem[0x57] = "03d1c80f";
    szQStr_lut3d_mem[0x58] = "04e18006";
    szQStr_lut3d_mem[0x59] = "06119407";
    szQStr_lut3d_mem[0x5a] = "0561ec0c";
    szQStr_lut3d_mem[0x5b] = "0691fc0e";
    szQStr_lut3d_mem[0x5c] = "04a17c0a";
    szQStr_lut3d_mem[0x5d] = "06219c0d";
    szQStr_lut3d_mem[0x5e] = "0531f011";
    szQStr_lut3d_mem[0x5f] = "06920814";
    szQStr_lut3d_mem[0x60] = "06f19008";
    szQStr_lut3d_mem[0x61] = "0811ac09";
    szQStr_lut3d_mem[0x62] = "07c2080f";
    szQStr_lut3d_mem[0x63] = "0881fc0e";
    szQStr_lut3d_mem[0x64] = "07219c0e";
    szQStr_lut3d_mem[0x65] = "0841b80f";
    szQStr_lut3d_mem[0x66] = "07e21815";
    szQStr_lut3d_mem[0x67] = "08c21015";
    szQStr_lut3d_mem[0x68] = "0921d40c";
    szQStr_lut3d_mem[0x69] = "0a21f80f";
    szQStr_lut3d_mem[0x6a] = "09821010";
    szQStr_lut3d_mem[0x6b] = "0a622c12";
    szQStr_lut3d_mem[0x6c] = "0951e012";
    szQStr_lut3d_mem[0x6d] = "0a320014";
    szQStr_lut3d_mem[0x6e] = "09b21c16";
    szQStr_lut3d_mem[0x6f] = "0a823418";
    szQStr_lut3d_mem[0x70] = "0ae21c11";
    szQStr_lut3d_mem[0x71] = "00000000";
    szQStr_lut3d_mem[0x72] = "0b224814";
    szQStr_lut3d_mem[0x73] = "00000000";
    szQStr_lut3d_mem[0x74] = "0ae21c16";
    szQStr_lut3d_mem[0x75] = "00000000";
    szQStr_lut3d_mem[0x76] = "0b324819";
    szQStr_lut3d_mem[0x77] = "00000000";
    szQStr_lut3d_mem[0x78] = "03c21c0e";
    szQStr_lut3d_mem[0x79] = "04623410";
    szQStr_lut3d_mem[0x7a] = "04227013";
    szQStr_lut3d_mem[0x7b] = "04c28015";
    szQStr_lut3d_mem[0x7c] = "03d2201b";
    szQStr_lut3d_mem[0x7d] = "04523416";
    szQStr_lut3d_mem[0x7e] = "04227820";
    szQStr_lut3d_mem[0x7f] = "04a2841a";
    szQStr_lut3d_mem[0x80] = "05b24c12";
    szQStr_lut3d_mem[0x81] = "06e25c14";
    szQStr_lut3d_mem[0x82] = "05c29416";
    szQStr_lut3d_mem[0x83] = "0712a418";
    szQStr_lut3d_mem[0x84] = "05824c18";
    szQStr_lut3d_mem[0x85] = "06d2641a";
    szQStr_lut3d_mem[0x86] = "0582941c";
    szQStr_lut3d_mem[0x87] = "06d2a81e";
    szQStr_lut3d_mem[0x88] = "08226c15";
    szQStr_lut3d_mem[0x89] = "09627817";
    szQStr_lut3d_mem[0x8a] = "0852b419";
    szQStr_lut3d_mem[0x8b] = "0992c41b";
    szQStr_lut3d_mem[0x8c] = "0822741b";
    szQStr_lut3d_mem[0x8d] = "0972881d";
    szQStr_lut3d_mem[0x8e] = "0832b81f";
    szQStr_lut3d_mem[0x8f] = "0992cc21";
    szQStr_lut3d_mem[0x90] = "0a026816";
    szQStr_lut3d_mem[0x91] = "0ad27017";
    szQStr_lut3d_mem[0x92] = "0ac2d41d";
    szQStr_lut3d_mem[0x93] = "0b52c41c";
    szQStr_lut3d_mem[0x94] = "0a32781d";
    szQStr_lut3d_mem[0x95] = "0af27c1d";
    szQStr_lut3d_mem[0x96] = "0ad2e023";
    szQStr_lut3d_mem[0x97] = "0b72d022";
    szQStr_lut3d_mem[0x98] = "0b828018";
    szQStr_lut3d_mem[0x99] = "00000000";
    szQStr_lut3d_mem[0x9a] = "0be2c41c";
    szQStr_lut3d_mem[0x9b] = "00000000";
    szQStr_lut3d_mem[0x9c] = "0b82841d";
    szQStr_lut3d_mem[0x9d] = "00000000";
    szQStr_lut3d_mem[0x9e] = "0c02cc22";
    szQStr_lut3d_mem[0x9f] = "00000000";
    szQStr_lut3d_mem[0xa0] = "04a2c417";
    szQStr_lut3d_mem[0xa1] = "0522cc18";
    szQStr_lut3d_mem[0xa2] = "00000000";
    szQStr_lut3d_mem[0xa3] = "00000000";
    szQStr_lut3d_mem[0xa4] = "0482c824";
    szQStr_lut3d_mem[0xa5] = "0502cc1e";
    szQStr_lut3d_mem[0xa6] = "00000000";
    szQStr_lut3d_mem[0xa7] = "00000000";
    szQStr_lut3d_mem[0xa8] = "0602d819";
    szQStr_lut3d_mem[0xa9] = "0752e81b";
    szQStr_lut3d_mem[0xaa] = "00000000";
    szQStr_lut3d_mem[0xab] = "00000000";
    szQStr_lut3d_mem[0xac] = "05a2d41e";
    szQStr_lut3d_mem[0xad] = "0702e420";
    szQStr_lut3d_mem[0xae] = "00000000";
    szQStr_lut3d_mem[0xaf] = "00000000";
    szQStr_lut3d_mem[0xb0] = "0892f41c";
    szQStr_lut3d_mem[0xb1] = "09c3001d";
    szQStr_lut3d_mem[0xb2] = "00000000";
    szQStr_lut3d_mem[0xb3] = "00000000";
    szQStr_lut3d_mem[0xb4] = "0852f421";
    szQStr_lut3d_mem[0xb5] = "09930022";
    szQStr_lut3d_mem[0xb6] = "00000000";
    szQStr_lut3d_mem[0xb7] = "00000000";
    szQStr_lut3d_mem[0xb8] = "0ae31020";
    szQStr_lut3d_mem[0xb9] = "0bd31c21";
    szQStr_lut3d_mem[0xba] = "00000000";
    szQStr_lut3d_mem[0xbb] = "00000000";
    szQStr_lut3d_mem[0xbc] = "0ad31425";
    szQStr_lut3d_mem[0xbd] = "0be32427";
    szQStr_lut3d_mem[0xbe] = "00000000";
    szQStr_lut3d_mem[0xbf] = "00000000";
    szQStr_lut3d_mem[0xc0] = "0c430820";
    szQStr_lut3d_mem[0xc1] = "00000000";
    szQStr_lut3d_mem[0xc2] = "00000000";
    szQStr_lut3d_mem[0xc3] = "00000000";
    szQStr_lut3d_mem[0xc4] = "0c531026";
    szQStr_lut3d_mem[0xc5] = "00000000";
    szQStr_lut3d_mem[0xc6] = "00000000";
    szQStr_lut3d_mem[0xc7] = "00000000";
    szQStr_lut3d_mem[0xc8] = "00202053";
    szQStr_lut3d_mem[0xc9] = "0110185a";
    szQStr_lut3d_mem[0xca] = "00203c45";
    szQStr_lut3d_mem[0xcb] = "01a07041";
    szQStr_lut3d_mem[0xcc] = "00303c70";
    szQStr_lut3d_mem[0xcd] = "00b02874";
    szQStr_lut3d_mem[0xce] = "00205c6b";
    szQStr_lut3d_mem[0xcf] = "00f0806a";
    szQStr_lut3d_mem[0xd0] = "02502059";
    szQStr_lut3d_mem[0xd1] = "03401842";
    szQStr_lut3d_mem[0xd2] = "03206843";
    szQStr_lut3d_mem[0xd3] = "03604c2b";
    szQStr_lut3d_mem[0xd4] = "02303476";
    szQStr_lut3d_mem[0xd5] = "03303c73";
    szQStr_lut3d_mem[0xd6] = "0200646b";
    szQStr_lut3d_mem[0xd7] = "0320706b";
    szQStr_lut3d_mem[0xd8] = "04201c37";
    szQStr_lut3d_mem[0xd9] = "05102035";
    szQStr_lut3d_mem[0xda] = "04d0681f";
    szQStr_lut3d_mem[0xdb] = "06508c15";
    szQStr_lut3d_mem[0xdc] = "04303c62";
    szQStr_lut3d_mem[0xdd] = "05003852";
    szQStr_lut3d_mem[0xde] = "04206851";
    szQStr_lut3d_mem[0xdf] = "05306844";
    szQStr_lut3d_mem[0xe0] = "05e02c37";
    szQStr_lut3d_mem[0xe1] = "0690383b";
    szQStr_lut3d_mem[0xe2] = "0770a414";
    szQStr_lut3d_mem[0xe3] = "0820b017";
    szQStr_lut3d_mem[0xe4] = "05d03c4f";
    szQStr_lut3d_mem[0xe5] = "06804451";
    szQStr_lut3d_mem[0xe6] = "06306c3e";
    szQStr_lut3d_mem[0xe7] = "07007c3f";
    szQStr_lut3d_mem[0xe8] = "0730483e";
    szQStr_lut3d_mem[0xe9] = "00000000";
    szQStr_lut3d_mem[0xea] = "0910d817";
    szQStr_lut3d_mem[0xeb] = "00000000";
    szQStr_lut3d_mem[0xec] = "07204c54";
    szQStr_lut3d_mem[0xed] = "00000000";
    szQStr_lut3d_mem[0xee] = "07a09042";
    szQStr_lut3d_mem[0xef] = "00000000";
    szQStr_lut3d_mem[0xf0] = "00908839";
    szQStr_lut3d_mem[0xf1] = "01c0d03d";
    szQStr_lut3d_mem[0xf2] = "01910832";
    szQStr_lut3d_mem[0xf3] = "0291082b";
    szQStr_lut3d_mem[0xf4] = "0040a866";
    szQStr_lut3d_mem[0xf5] = "00d0b469";
    szQStr_lut3d_mem[0xf6] = "00c0f461";
    szQStr_lut3d_mem[0xf7] = "01310062";
    szQStr_lut3d_mem[0xf8] = "04010040";
    szQStr_lut3d_mem[0xf9] = "0560ec2c";
    szQStr_lut3d_mem[0xfa] = "03f1442c";
    szQStr_lut3d_mem[0xfb] = "05a14c2a";
    szQStr_lut3d_mem[0xfc] = "0350ec5e";
    szQStr_lut3d_mem[0xfd] = "04d0e85d";
    szQStr_lut3d_mem[0xfe] = "0381505d";
    szQStr_lut3d_mem[0xff] = "06018060";
    szQStr_lut3d_mem[0x100] = "06510812";
    szQStr_lut3d_mem[0x101] = "07c14411";
    szQStr_lut3d_mem[0x102] = "06c15410";
    szQStr_lut3d_mem[0x103] = "08218c12";
    szQStr_lut3d_mem[0x104] = "0500d444";
    szQStr_lut3d_mem[0x105] = "0690e834";
    szQStr_lut3d_mem[0x106] = "07416c49";
    szQStr_lut3d_mem[0x107] = "07e17829";
    szQStr_lut3d_mem[0x108] = "08d16412";
    szQStr_lut3d_mem[0x109] = "09b17c14";
    szQStr_lut3d_mem[0x10a] = "0931b014";
    szQStr_lut3d_mem[0x10b] = "0a01d016";
    szQStr_lut3d_mem[0x10c] = "07d0fc28";
    szQStr_lut3d_mem[0x10d] = "08b10c25";
    szQStr_lut3d_mem[0x10e] = "09119c26";
    szQStr_lut3d_mem[0x10f] = "09e1b024";
    szQStr_lut3d_mem[0x110] = "0a518c15";
    szQStr_lut3d_mem[0x111] = "00000000";
    szQStr_lut3d_mem[0x112] = "0aa1e017";
    szQStr_lut3d_mem[0x113] = "00000000";
    szQStr_lut3d_mem[0x114] = "09612024";
    szQStr_lut3d_mem[0x115] = "00000000";
    szQStr_lut3d_mem[0x116] = "0a71bc22";
    szQStr_lut3d_mem[0x117] = "00000000";
    szQStr_lut3d_mem[0x118] = "02916428";
    szQStr_lut3d_mem[0x119] = "0351641f";
    szQStr_lut3d_mem[0x11a] = "0361d024";
    szQStr_lut3d_mem[0x11b] = "03f1d422";
    szQStr_lut3d_mem[0x11c] = "0211a066";
    szQStr_lut3d_mem[0x11d] = "02819c60";
    szQStr_lut3d_mem[0x11e] = "03221864";
    szQStr_lut3d_mem[0x11f] = "03b20c5a";
    szQStr_lut3d_mem[0x120] = "04416815";
    szQStr_lut3d_mem[0x121] = "05d19013";
    szQStr_lut3d_mem[0x122] = "04d1e41c";
    szQStr_lut3d_mem[0x123] = "06420019";
    szQStr_lut3d_mem[0x124] = "0431944c";
    szQStr_lut3d_mem[0x125] = "05c1cc49";
    szQStr_lut3d_mem[0x126] = "05120443";
    szQStr_lut3d_mem[0x127] = "0611fc2f";
    szQStr_lut3d_mem[0x128] = "0721a014";
    szQStr_lut3d_mem[0x129] = "0861c015";
    szQStr_lut3d_mem[0x12a] = "07d21c1b";
    szQStr_lut3d_mem[0x12b] = "08e21c1c";
    szQStr_lut3d_mem[0x12c] = "0781cc45";
    szQStr_lut3d_mem[0x12d] = "0871c828";
    szQStr_lut3d_mem[0x12e] = "07a21c2b";
    szQStr_lut3d_mem[0x12f] = "08f2282a";
    szQStr_lut3d_mem[0x130] = "0971e818";
    szQStr_lut3d_mem[0x131] = "0a52081a";
    szQStr_lut3d_mem[0x132] = "09e22c1c";
    szQStr_lut3d_mem[0x133] = "0ab2401e";
    szQStr_lut3d_mem[0x134] = "09a1f821";
    szQStr_lut3d_mem[0x135] = "0a721021";
    szQStr_lut3d_mem[0x136] = "0a023827";
    szQStr_lut3d_mem[0x137] = "0ad24c24";
    szQStr_lut3d_mem[0x138] = "0af21c1b";
    szQStr_lut3d_mem[0x139] = "00000000";
    szQStr_lut3d_mem[0x13a] = "0b42501e";
    szQStr_lut3d_mem[0x13b] = "00000000";
    szQStr_lut3d_mem[0x13c] = "0b021821";
    szQStr_lut3d_mem[0x13d] = "00000000";
    szQStr_lut3d_mem[0x13e] = "0b525424";
    szQStr_lut3d_mem[0x13f] = "00000000";
    szQStr_lut3d_mem[0x140] = "03f2442d";
    szQStr_lut3d_mem[0x141] = "04824429";
    szQStr_lut3d_mem[0x142] = "04429833";
    szQStr_lut3d_mem[0x143] = "04d2942f";
    szQStr_lut3d_mem[0x144] = "03e2846b";
    szQStr_lut3d_mem[0x145] = "04827c5c";
    szQStr_lut3d_mem[0x146] = "0452d06c";
    szQStr_lut3d_mem[0x147] = "04d2c85e";
    szQStr_lut3d_mem[0x148] = "05424c23";
    szQStr_lut3d_mem[0x149] = "0682641f";
    szQStr_lut3d_mem[0x14a] = "05929c2a";
    szQStr_lut3d_mem[0x14b] = "0682a823";
    szQStr_lut3d_mem[0x14c] = "05b27448";
    szQStr_lut3d_mem[0x14d] = "06826c35";
    szQStr_lut3d_mem[0x14e] = "05f2c44e";
    szQStr_lut3d_mem[0x14f] = "06d2bc3f";
    szQStr_lut3d_mem[0x150] = "08027821";
    szQStr_lut3d_mem[0x151] = "09829023";
    szQStr_lut3d_mem[0x152] = "07e2b824";
    szQStr_lut3d_mem[0x153] = "0972d026";
    szQStr_lut3d_mem[0x154] = "07d27c2f";
    szQStr_lut3d_mem[0x155] = "0972942a";
    szQStr_lut3d_mem[0x156] = "07a2c034";
    szQStr_lut3d_mem[0x157] = "0942d42d";
    szQStr_lut3d_mem[0x158] = "0a628823";
    szQStr_lut3d_mem[0x159] = "0b228823";
    szQStr_lut3d_mem[0x15a] = "0ae2e829";
    szQStr_lut3d_mem[0x15b] = "0b92dc29";
    szQStr_lut3d_mem[0x15c] = "0a82982b";
    szQStr_lut3d_mem[0x15d] = "0b429429";
    szQStr_lut3d_mem[0x15e] = "0ad2ec2e";
    szQStr_lut3d_mem[0x15f] = "0bb2e82f";
    szQStr_lut3d_mem[0x160] = "0b928823";
    szQStr_lut3d_mem[0x161] = "00000000";
    szQStr_lut3d_mem[0x162] = "0c12d428";
    szQStr_lut3d_mem[0x163] = "00000000";
    szQStr_lut3d_mem[0x164] = "0bb29429";
    szQStr_lut3d_mem[0x165] = "00000000";
    szQStr_lut3d_mem[0x166] = "0c22dc2e";
    szQStr_lut3d_mem[0x167] = "00000000";
    szQStr_lut3d_mem[0x168] = "04b2e038";
    szQStr_lut3d_mem[0x169] = "0562e034";
    szQStr_lut3d_mem[0x16a] = "00000000";
    szQStr_lut3d_mem[0x16b] = "00000000";
    szQStr_lut3d_mem[0x16c] = "04a30463";
    szQStr_lut3d_mem[0x16d] = "05330059";
    szQStr_lut3d_mem[0x16e] = "00000000";
    szQStr_lut3d_mem[0x16f] = "00000000";
    szQStr_lut3d_mem[0x170] = "05c2dc28";
    szQStr_lut3d_mem[0x171] = "06c2e425";
    szQStr_lut3d_mem[0x172] = "00000000";
    szQStr_lut3d_mem[0x173] = "00000000";
    szQStr_lut3d_mem[0x174] = "0662fc4d";
    szQStr_lut3d_mem[0x175] = "0702f43f";
    szQStr_lut3d_mem[0x176] = "00000000";
    szQStr_lut3d_mem[0x177] = "00000000";
    szQStr_lut3d_mem[0x178] = "0802f427";
    szQStr_lut3d_mem[0x179] = "09530028";
    szQStr_lut3d_mem[0x17a] = "00000000";
    szQStr_lut3d_mem[0x17b] = "00000000";
    szQStr_lut3d_mem[0x17c] = "07d2f436";
    szQStr_lut3d_mem[0x17d] = "0913002e";
    szQStr_lut3d_mem[0x17e] = "00000000";
    szQStr_lut3d_mem[0x17f] = "00000000";
    szQStr_lut3d_mem[0x180] = "0ab3142a";
    szQStr_lut3d_mem[0x181] = "0be3282c";
    szQStr_lut3d_mem[0x182] = "00000000";
    szQStr_lut3d_mem[0x183] = "00000000";
    szQStr_lut3d_mem[0x184] = "0a93182f";
    szQStr_lut3d_mem[0x185] = "0be32c32";
    szQStr_lut3d_mem[0x186] = "00000000";
    szQStr_lut3d_mem[0x187] = "00000000";
    szQStr_lut3d_mem[0x188] = "0c73182c";
    szQStr_lut3d_mem[0x189] = "00000000";
    szQStr_lut3d_mem[0x18a] = "00000000";
    szQStr_lut3d_mem[0x18b] = "00000000";
    szQStr_lut3d_mem[0x18c] = "0c831c31";
    szQStr_lut3d_mem[0x18d] = "00000000";
    szQStr_lut3d_mem[0x18e] = "00000000";
    szQStr_lut3d_mem[0x18f] = "00000000";
    szQStr_lut3d_mem[0x190] = "0030588a";
    szQStr_lut3d_mem[0x191] = "00b0388a";
    szQStr_lut3d_mem[0x192] = "00207c8b";
    szQStr_lut3d_mem[0x193] = "00b09c8d";
    szQStr_lut3d_mem[0x194] = "003070a0";
    szQStr_lut3d_mem[0x195] = "00a0449d";
    szQStr_lut3d_mem[0x196] = "002098a5";
    szQStr_lut3d_mem[0x197] = "00a0b4a7";
    szQStr_lut3d_mem[0x198] = "02003c8d";
    szQStr_lut3d_mem[0x199] = "0310508d";
    szQStr_lut3d_mem[0x19a] = "01906c8a";
    szQStr_lut3d_mem[0x19b] = "02f0848b";
    szQStr_lut3d_mem[0x19c] = "01a0449f";
    szQStr_lut3d_mem[0x19d] = "02f054a1";
    szQStr_lut3d_mem[0x19e] = "012090a4";
    szQStr_lut3d_mem[0x19f] = "02c088a3";
    szQStr_lut3d_mem[0x1a0] = "0410588c";
    szQStr_lut3d_mem[0x1a1] = "0520587c";
    szQStr_lut3d_mem[0x1a2] = "0410888a";
    szQStr_lut3d_mem[0x1a3] = "05108070";
    szQStr_lut3d_mem[0x1a4] = "03f068a2";
    szQStr_lut3d_mem[0x1a5] = "04f070a1";
    szQStr_lut3d_mem[0x1a6] = "03e09ca5";
    szQStr_lut3d_mem[0x1a7] = "0500a0a5";
    szQStr_lut3d_mem[0x1a8] = "05d0546b";
    szQStr_lut3d_mem[0x1a9] = "06905466";
    szQStr_lut3d_mem[0x1aa] = "05f0785e";
    szQStr_lut3d_mem[0x1ab] = "06b0805b";
    szQStr_lut3d_mem[0x1ac] = "05f07899";
    szQStr_lut3d_mem[0x1ad] = "06907489";
    szQStr_lut3d_mem[0x1ae] = "06009c94";
    szQStr_lut3d_mem[0x1af] = "06a0947f";
    szQStr_lut3d_mem[0x1b0] = "07105c67";
    szQStr_lut3d_mem[0x1b1] = "00000000";
    szQStr_lut3d_mem[0x1b2] = "0750885d";
    szQStr_lut3d_mem[0x1b3] = "00000000";
    szQStr_lut3d_mem[0x1b4] = "07207481";
    szQStr_lut3d_mem[0x1b5] = "00000000";
    szQStr_lut3d_mem[0x1b6] = "07309878";
    szQStr_lut3d_mem[0x1b7] = "00000000";
    szQStr_lut3d_mem[0x1b8] = "0020c48d";
    szQStr_lut3d_mem[0x1b9] = "00a0c490";
    szQStr_lut3d_mem[0x1ba] = "0061148c";
    szQStr_lut3d_mem[0x1bb] = "00c11c8e";
    szQStr_lut3d_mem[0x1bc] = "0020d8ab";
    szQStr_lut3d_mem[0x1bd] = "0090dcad";
    szQStr_lut3d_mem[0x1be] = "00413cae";
    szQStr_lut3d_mem[0x1bf] = "00812cb1";
    szQStr_lut3d_mem[0x1c0] = "0270fc84";
    szQStr_lut3d_mem[0x1c1] = "0310dc83";
    szQStr_lut3d_mem[0x1c2] = "02913c87";
    szQStr_lut3d_mem[0x1c3] = "05016880";
    szQStr_lut3d_mem[0x1c4] = "021114a9";
    szQStr_lut3d_mem[0x1c5] = "02a0e8a4";
    szQStr_lut3d_mem[0x1c6] = "020140ae";
    szQStr_lut3d_mem[0x1c7] = "03b178a4";
    szQStr_lut3d_mem[0x1c8] = "0440e083";
    szQStr_lut3d_mem[0x1c9] = "05a0dc62";
    szQStr_lut3d_mem[0x1ca] = "0691647e";
    szQStr_lut3d_mem[0x1cb] = "06b14c5d";
    szQStr_lut3d_mem[0x1cc] = "03f0f0a5";
    szQStr_lut3d_mem[0x1cd] = "0510f0a6";
    szQStr_lut3d_mem[0x1ce] = "045150a1";
    szQStr_lut3d_mem[0x1cf] = "059154a3";
    szQStr_lut3d_mem[0x1d0] = "06a0d855";
    szQStr_lut3d_mem[0x1d1] = "0770d850";
    szQStr_lut3d_mem[0x1d2] = "0801584e";
    szQStr_lut3d_mem[0x1d3] = "08e15c43";
    szQStr_lut3d_mem[0x1d4] = "0620e48b";
    szQStr_lut3d_mem[0x1d5] = "0700e076";
    szQStr_lut3d_mem[0x1d6] = "06d14883";
    szQStr_lut3d_mem[0x1d7] = "07a13c74";
    szQStr_lut3d_mem[0x1d8] = "0810e052";
    szQStr_lut3d_mem[0x1d9] = "00000000";
    szQStr_lut3d_mem[0x1da] = "09715c3e";
    szQStr_lut3d_mem[0x1db] = "00000000";
    szQStr_lut3d_mem[0x1dc] = "0790e072";
    szQStr_lut3d_mem[0x1dd] = "00000000";
    szQStr_lut3d_mem[0x1de] = "08312c6d";
    szQStr_lut3d_mem[0x1df] = "00000000";
    szQStr_lut3d_mem[0x1e0] = "0101688a";
    szQStr_lut3d_mem[0x1e1] = "01416c8b";
    szQStr_lut3d_mem[0x1e2] = "02b23897";
    szQStr_lut3d_mem[0x1e3] = "03123893";
    szQStr_lut3d_mem[0x1e4] = "00a188b0";
    szQStr_lut3d_mem[0x1e5] = "00e18cb2";
    szQStr_lut3d_mem[0x1e6] = "0181f0b2";
    szQStr_lut3d_mem[0x1e7] = "01b1f0b3";
    szQStr_lut3d_mem[0x1e8] = "02d18485";
    szQStr_lut3d_mem[0x1e9] = "0541d87f";
    szQStr_lut3d_mem[0x1ea] = "04423885";
    szQStr_lut3d_mem[0x1eb] = "0602306f";
    szQStr_lut3d_mem[0x1ec] = "01a1a0b1";
    szQStr_lut3d_mem[0x1ed] = "03f1c0aa";
    szQStr_lut3d_mem[0x1ee] = "0231fcb1";
    szQStr_lut3d_mem[0x1ef] = "047220ab";
    szQStr_lut3d_mem[0x1f0] = "08020080";
    szQStr_lut3d_mem[0x1f1] = "0931f066";
    szQStr_lut3d_mem[0x1f2] = "07b25869";
    szQStr_lut3d_mem[0x1f3] = "09825c62";
    szQStr_lut3d_mem[0x1f4] = "06b1eca3";
    szQStr_lut3d_mem[0x1f5] = "0851e4a2";
    szQStr_lut3d_mem[0x1f6] = "071264a4";
    szQStr_lut3d_mem[0x1f7] = "0a0280a0";
    szQStr_lut3d_mem[0x1f8] = "0971f042";
    szQStr_lut3d_mem[0x1f9] = "0a31f83d";
    szQStr_lut3d_mem[0x1fa] = "0a224c42";
    szQStr_lut3d_mem[0x1fb] = "0b02603d";
    szQStr_lut3d_mem[0x1fc] = "07e1c084";
    szQStr_lut3d_mem[0x1fd] = "08c1b876";
    szQStr_lut3d_mem[0x1fe] = "0ae27891";
    szQStr_lut3d_mem[0x1ff] = "0aa26c71";
    szQStr_lut3d_mem[0x200] = "0ab1f439";
    szQStr_lut3d_mem[0x201] = "00000000";
    szQStr_lut3d_mem[0x202] = "0b725c2c";
    szQStr_lut3d_mem[0x203] = "00000000";
    szQStr_lut3d_mem[0x204] = "0951a86c";
    szQStr_lut3d_mem[0x205] = "00000000";
    szQStr_lut3d_mem[0x206] = "0b125062";
    szQStr_lut3d_mem[0x207] = "00000000";
    szQStr_lut3d_mem[0x208] = "03c2b89a";
    szQStr_lut3d_mem[0x209] = "0422b494";
    szQStr_lut3d_mem[0x20a] = "0432f898";
    szQStr_lut3d_mem[0x20b] = "0492f490";
    szQStr_lut3d_mem[0x20c] = "02f298bb";
    szQStr_lut3d_mem[0x20d] = "0362a8bb";
    szQStr_lut3d_mem[0x20e] = "03d310bd";
    szQStr_lut3d_mem[0x20f] = "044314b9";
    szQStr_lut3d_mem[0x210] = "0522a886";
    szQStr_lut3d_mem[0x211] = "06c29c6e";
    szQStr_lut3d_mem[0x212] = "0582f086";
    szQStr_lut3d_mem[0x213] = "06f2ec76";
    szQStr_lut3d_mem[0x214] = "0402c0b9";
    szQStr_lut3d_mem[0x215] = "0602d4ae";
    szQStr_lut3d_mem[0x216] = "04c314b5";
    szQStr_lut3d_mem[0x217] = "06731cad";
    szQStr_lut3d_mem[0x218] = "07f29453";
    szQStr_lut3d_mem[0x219] = "0972a045";
    szQStr_lut3d_mem[0x21a] = "0832e462";
    szQStr_lut3d_mem[0x21b] = "0932e048";
    szQStr_lut3d_mem[0x21c] = "07b2d09e";
    szQStr_lut3d_mem[0x21d] = "09a2e494";
    szQStr_lut3d_mem[0x21e] = "07f318a0";
    szQStr_lut3d_mem[0x21f] = "0963108c";
    szQStr_lut3d_mem[0x220] = "0ac2ac44";
    szQStr_lut3d_mem[0x221] = "0b82ac40";
    szQStr_lut3d_mem[0x222] = "0ae2f841";
    szQStr_lut3d_mem[0x223] = "0be2f83f";
    szQStr_lut3d_mem[0x224] = "0b62e88a";
    szQStr_lut3d_mem[0x225] = "0bb2cc66";
    szQStr_lut3d_mem[0x226] = "0af31069";
    szQStr_lut3d_mem[0x227] = "0c23145e";
    szQStr_lut3d_mem[0x228] = "0be2a035";
    szQStr_lut3d_mem[0x229] = "00000000";
    szQStr_lut3d_mem[0x22a] = "0c62ec3d";
    szQStr_lut3d_mem[0x22b] = "00000000";
    szQStr_lut3d_mem[0x22c] = "0c32c056";
    szQStr_lut3d_mem[0x22d] = "00000000";
    szQStr_lut3d_mem[0x22e] = "0c92fc4d";
    szQStr_lut3d_mem[0x22f] = "00000000";
    szQStr_lut3d_mem[0x230] = "04832088";
    szQStr_lut3d_mem[0x231] = "04e31c82";
    szQStr_lut3d_mem[0x232] = "00000000";
    szQStr_lut3d_mem[0x233] = "00000000";
    szQStr_lut3d_mem[0x234] = "045340ac";
    szQStr_lut3d_mem[0x235] = "04c33ca8";
    szQStr_lut3d_mem[0x236] = "00000000";
    szQStr_lut3d_mem[0x237] = "00000000";
    szQStr_lut3d_mem[0x238] = "06131878";
    szQStr_lut3d_mem[0x239] = "0743186e";
    szQStr_lut3d_mem[0x23a] = "00000000";
    szQStr_lut3d_mem[0x23b] = "00000000";
    szQStr_lut3d_mem[0x23c] = "053338a4";
    szQStr_lut3d_mem[0x23d] = "06d3389c";
    szQStr_lut3d_mem[0x23e] = "00000000";
    szQStr_lut3d_mem[0x23f] = "00000000";
    szQStr_lut3d_mem[0x240] = "08431460";
    szQStr_lut3d_mem[0x241] = "09130c4b";
    szQStr_lut3d_mem[0x242] = "00000000";
    szQStr_lut3d_mem[0x243] = "00000000";
    szQStr_lut3d_mem[0x244] = "08033893";
    szQStr_lut3d_mem[0x245] = "09333887";
    szQStr_lut3d_mem[0x246] = "00000000";
    szQStr_lut3d_mem[0x247] = "00000000";
    szQStr_lut3d_mem[0x248] = "0a731c3f";
    szQStr_lut3d_mem[0x249] = "0be3303a";
    szQStr_lut3d_mem[0x24a] = "00000000";
    szQStr_lut3d_mem[0x24b] = "00000000";
    szQStr_lut3d_mem[0x24c] = "0a632c63";
    szQStr_lut3d_mem[0x24d] = "0be33c50";
    szQStr_lut3d_mem[0x24e] = "00000000";
    szQStr_lut3d_mem[0x24f] = "00000000";
    szQStr_lut3d_mem[0x250] = "0ca3283d";
    szQStr_lut3d_mem[0x251] = "00000000";
    szQStr_lut3d_mem[0x252] = "00000000";
    szQStr_lut3d_mem[0x253] = "00000000";
    szQStr_lut3d_mem[0x254] = "0cc3384f";
    szQStr_lut3d_mem[0x255] = "00000000";
    szQStr_lut3d_mem[0x256] = "00000000";
    szQStr_lut3d_mem[0x257] = "00000000";
    szQStr_lut3d_mem[0x258] = "003088b3";
    szQStr_lut3d_mem[0x259] = "00a058ad";
    szQStr_lut3d_mem[0x25a] = "0020b0b9";
    szQStr_lut3d_mem[0x25b] = "00a0c8bb";
    szQStr_lut3d_mem[0x25c] = "0030a0c4";
    szQStr_lut3d_mem[0x25d] = "00b080c0";
    szQStr_lut3d_mem[0x25e] = "0020c8ca";
    szQStr_lut3d_mem[0x25f] = "00a0e0cb";
    szQStr_lut3d_mem[0x260] = "01304cae";
    szQStr_lut3d_mem[0x261] = "02d050b0";
    szQStr_lut3d_mem[0x262] = "0110b0b7";
    szQStr_lut3d_mem[0x263] = "026074b3";
    szQStr_lut3d_mem[0x264] = "013058bd";
    szQStr_lut3d_mem[0x265] = "02b058be";
    szQStr_lut3d_mem[0x266] = "0110d0c8";
    szQStr_lut3d_mem[0x267] = "01c084c1";
    szQStr_lut3d_mem[0x268] = "03d070b2";
    szQStr_lut3d_mem[0x269] = "04d080b3";
    szQStr_lut3d_mem[0x26a] = "03b0a0b6";
    szQStr_lut3d_mem[0x26b] = "04d0b4b8";
    szQStr_lut3d_mem[0x26c] = "03d074c0";
    szQStr_lut3d_mem[0x26d] = "04d08cc2";
    szQStr_lut3d_mem[0x26e] = "0390a4c3";
    szQStr_lut3d_mem[0x26f] = "04c0c0c7";
    szQStr_lut3d_mem[0x270] = "05d084b3";
    szQStr_lut3d_mem[0x271] = "06a090af";
    szQStr_lut3d_mem[0x272] = "05e0b4b8";
    szQStr_lut3d_mem[0x273] = "06b0b8b0";
    szQStr_lut3d_mem[0x274] = "05b094c3";
    szQStr_lut3d_mem[0x275] = "06a098c3";
    szQStr_lut3d_mem[0x276] = "05c0c8c8";
    szQStr_lut3d_mem[0x277] = "06b0ccc7";
    szQStr_lut3d_mem[0x278] = "074090a6";
    szQStr_lut3d_mem[0x279] = "00000000";
    szQStr_lut3d_mem[0x27a] = "0740c0a5";
    szQStr_lut3d_mem[0x27b] = "00000000";
    szQStr_lut3d_mem[0x27c] = "0750acc1";
    szQStr_lut3d_mem[0x27d] = "00000000";
    szQStr_lut3d_mem[0x27e] = "0750dcc4";
    szQStr_lut3d_mem[0x27f] = "00000000";
    szQStr_lut3d_mem[0x280] = "0020e8bf";
    szQStr_lut3d_mem[0x281] = "0090f0c1";
    szQStr_lut3d_mem[0x282] = "003144c5";
    szQStr_lut3d_mem[0x283] = "008130c7";
    szQStr_lut3d_mem[0x284] = "0020f8d0";
    szQStr_lut3d_mem[0x285] = "009104d1";
    szQStr_lut3d_mem[0x286] = "00214cd4";
    szQStr_lut3d_mem[0x287] = "00813cd7";
    szQStr_lut3d_mem[0x288] = "01d120c0";
    szQStr_lut3d_mem[0x289] = "02710cbb";
    szQStr_lut3d_mem[0x28a] = "019144c6";
    szQStr_lut3d_mem[0x28b] = "034188c2";
    szQStr_lut3d_mem[0x28c] = "01812cd0";
    szQStr_lut3d_mem[0x28d] = "025120cb";
    szQStr_lut3d_mem[0x28e] = "014150d6";
    szQStr_lut3d_mem[0x28f] = "02f18cd3";
    szQStr_lut3d_mem[0x290] = "03a0f0ba";
    szQStr_lut3d_mem[0x291] = "04e100bc";
    szQStr_lut3d_mem[0x292] = "03c15cbd";
    szQStr_lut3d_mem[0x293] = "051158be";
    szQStr_lut3d_mem[0x294] = "0350f0c7";
    szQStr_lut3d_mem[0x295] = "04c104ca";
    szQStr_lut3d_mem[0x296] = "03a178ce";
    szQStr_lut3d_mem[0x297] = "04d154cd";
    szQStr_lut3d_mem[0x298] = "05f0fcbc";
    szQStr_lut3d_mem[0x299] = "06c0f8b0";
    szQStr_lut3d_mem[0x29a] = "061150bf";
    szQStr_lut3d_mem[0x29b] = "06e144ae";
    szQStr_lut3d_mem[0x29c] = "05d10ccd";
    szQStr_lut3d_mem[0x29d] = "06b10ccc";
    szQStr_lut3d_mem[0x29e] = "05e160d0";
    szQStr_lut3d_mem[0x29f] = "06c154cf";
    szQStr_lut3d_mem[0x2a0] = "0750f4a1";
    szQStr_lut3d_mem[0x2a1] = "00000000";
    szQStr_lut3d_mem[0x2a2] = "07a1409d";
    szQStr_lut3d_mem[0x2a3] = "00000000";
    szQStr_lut3d_mem[0x2a4] = "076110c7";
    szQStr_lut3d_mem[0x2a5] = "00000000";
    szQStr_lut3d_mem[0x2a6] = "076154c8";
    szQStr_lut3d_mem[0x2a7] = "00000000";
    szQStr_lut3d_mem[0x2a8] = "00a1b4c8";
    szQStr_lut3d_mem[0x2a9] = "00c1accb";
    szQStr_lut3d_mem[0x2aa] = "014204cc";
    szQStr_lut3d_mem[0x2ab] = "01720cd0";
    szQStr_lut3d_mem[0x2ac] = "00a1c8d9";
    szQStr_lut3d_mem[0x2ad] = "00b1acdc";
    szQStr_lut3d_mem[0x2ae] = "015224dd";
    szQStr_lut3d_mem[0x2af] = "01a230e1";
    szQStr_lut3d_mem[0x2b0] = "01319ccc";
    szQStr_lut3d_mem[0x2b1] = "0341b8c9";
    szQStr_lut3d_mem[0x2b2] = "01f21cd1";
    szQStr_lut3d_mem[0x2b3] = "038238d0";
    szQStr_lut3d_mem[0x2b4] = "01219cdd";
    szQStr_lut3d_mem[0x2b5] = "02f1bcda";
    szQStr_lut3d_mem[0x2b6] = "02023ce3";
    szQStr_lut3d_mem[0x2b7] = "02e238e4";
    szQStr_lut3d_mem[0x2b8] = "0521f8c3";
    szQStr_lut3d_mem[0x2b9] = "05c1ccbe";
    szQStr_lut3d_mem[0x2ba] = "05a258cd";
    szQStr_lut3d_mem[0x2bb] = "08d280c2";
    szQStr_lut3d_mem[0x2bc] = "04b1fcd7";
    szQStr_lut3d_mem[0x2bd] = "0541ccd0";
    szQStr_lut3d_mem[0x2be] = "050244e2";
    szQStr_lut3d_mem[0x2bf] = "070280dd";
    szQStr_lut3d_mem[0x2c0] = "06b1c8c0";
    szQStr_lut3d_mem[0x2c1] = "0791acaa";
    szQStr_lut3d_mem[0x2c2] = "0a4274c0";
    szQStr_lut3d_mem[0x2c3] = "092244ab";
    szQStr_lut3d_mem[0x2c4] = "0671ccd3";
    szQStr_lut3d_mem[0x2c5] = "0711b4d2";
    szQStr_lut3d_mem[0x2c6] = "07b258d4";
    szQStr_lut3d_mem[0x2c7] = "085248d6";
    szQStr_lut3d_mem[0x2c8] = "08419c9b";
    szQStr_lut3d_mem[0x2c9] = "00000000";
    szQStr_lut3d_mem[0x2ca] = "09721c9e";
    szQStr_lut3d_mem[0x2cb] = "00000000";
    szQStr_lut3d_mem[0x2cc] = "07a1a8c8";
    szQStr_lut3d_mem[0x2cd] = "00000000";
    szQStr_lut3d_mem[0x2ce] = "089224c9";
    szQStr_lut3d_mem[0x2cf] = "00000000";
    szQStr_lut3d_mem[0x2d0] = "023268cf";
    szQStr_lut3d_mem[0x2d1] = "028274d2";
    szQStr_lut3d_mem[0x2d2] = "0322dcd3";
    szQStr_lut3d_mem[0x2d3] = "0382e8d5";
    szQStr_lut3d_mem[0x2d4] = "02026ce0";
    szQStr_lut3d_mem[0x2d5] = "026280e5";
    szQStr_lut3d_mem[0x2d6] = "02a2bce2";
    szQStr_lut3d_mem[0x2d7] = "0312cce6";
    szQStr_lut3d_mem[0x2d8] = "02f280d3";
    szQStr_lut3d_mem[0x2d9] = "042294d2";
    szQStr_lut3d_mem[0x2da] = "0402fcd5";
    szQStr_lut3d_mem[0x2db] = "050314d4";
    szQStr_lut3d_mem[0x2dc] = "02d290e7";
    szQStr_lut3d_mem[0x2dd] = "0382ace8";
    szQStr_lut3d_mem[0x2de] = "0382dce8";
    szQStr_lut3d_mem[0x2df] = "0412f0e9";
    szQStr_lut3d_mem[0x2e0] = "0652b8cd";
    szQStr_lut3d_mem[0x2e1] = "0942f4c3";
    szQStr_lut3d_mem[0x2e2] = "075338d0";
    szQStr_lut3d_mem[0x2e3] = "091348c5";
    szQStr_lut3d_mem[0x2e4] = "05d2cce8";
    szQStr_lut3d_mem[0x2e5] = "07d2ece6";
    szQStr_lut3d_mem[0x2e6] = "06330ce9";
    szQStr_lut3d_mem[0x2e7] = "08232ce6";
    szQStr_lut3d_mem[0x2e8] = "0c0300c0";
    szQStr_lut3d_mem[0x2e9] = "0ca304b8";
    szQStr_lut3d_mem[0x2ea] = "0b4360b9";
    szQStr_lut3d_mem[0x2eb] = "0d0364b0";
    szQStr_lut3d_mem[0x2ec] = "0ac304e0";
    szQStr_lut3d_mem[0x2ed] = "0c32fcdd";
    szQStr_lut3d_mem[0x2ee] = "0b036ce1";
    szQStr_lut3d_mem[0x2ef] = "0e0380e0";
    szQStr_lut3d_mem[0x2f0] = "0b92dc9f";
    szQStr_lut3d_mem[0x2f1] = "00000000";
    szQStr_lut3d_mem[0x2f2] = "0cd33487";
    szQStr_lut3d_mem[0x2f3] = "00000000";
    szQStr_lut3d_mem[0x2f4] = "0a92cccb";
    szQStr_lut3d_mem[0x2f5] = "00000000";
    szQStr_lut3d_mem[0x2f6] = "0e3378d8";
    szQStr_lut3d_mem[0x2f7] = "00000000";
    szQStr_lut3d_mem[0x2f8] = "03f34cce";
    szQStr_lut3d_mem[0x2f9] = "047350ca";
    szQStr_lut3d_mem[0x2fa] = "00000000";
    szQStr_lut3d_mem[0x2fb] = "00000000";
    szQStr_lut3d_mem[0x2fc] = "035318e2";
    szQStr_lut3d_mem[0x2fd] = "03c328e3";
    szQStr_lut3d_mem[0x2fe] = "00000000";
    szQStr_lut3d_mem[0x2ff] = "00000000";
    szQStr_lut3d_mem[0x300] = "04e350c6";
    szQStr_lut3d_mem[0x301] = "05c358c3";
    szQStr_lut3d_mem[0x302] = "00000000";
    szQStr_lut3d_mem[0x303] = "00000000";
    szQStr_lut3d_mem[0x304] = "044338e3";
    szQStr_lut3d_mem[0x305] = "04d348e4";
    szQStr_lut3d_mem[0x306] = "00000000";
    szQStr_lut3d_mem[0x307] = "00000000";
    szQStr_lut3d_mem[0x308] = "079360bf";
    szQStr_lut3d_mem[0x309] = "08c360b7";
    szQStr_lut3d_mem[0x30a] = "00000000";
    szQStr_lut3d_mem[0x30b] = "00000000";
    szQStr_lut3d_mem[0x30c] = "06e364e3";
    szQStr_lut3d_mem[0x30d] = "08737cdf";
    szQStr_lut3d_mem[0x30e] = "00000000";
    szQStr_lut3d_mem[0x30f] = "00000000";
    szQStr_lut3d_mem[0x310] = "0a135cab";
    szQStr_lut3d_mem[0x311] = "0bb35886";
    szQStr_lut3d_mem[0x312] = "00000000";
    szQStr_lut3d_mem[0x313] = "00000000";
    szQStr_lut3d_mem[0x314] = "09d38cd9";
    szQStr_lut3d_mem[0x315] = "0c83c4d7";
    szQStr_lut3d_mem[0x316] = "00000000";
    szQStr_lut3d_mem[0x317] = "00000000";
    szQStr_lut3d_mem[0x318] = "0cf3485e";
    szQStr_lut3d_mem[0x319] = "00000000";
    szQStr_lut3d_mem[0x31a] = "00000000";
    szQStr_lut3d_mem[0x31b] = "00000000";
    szQStr_lut3d_mem[0x31c] = "0e83c0c1";
    szQStr_lut3d_mem[0x31d] = "00000000";
    szQStr_lut3d_mem[0x31e] = "00000000";
    szQStr_lut3d_mem[0x31f] = "00000000";
    szQStr_lut3d_mem[0x320] = "0040bcd4";
    szQStr_lut3d_mem[0x321] = "00b0b0d1";
    szQStr_lut3d_mem[0x322] = "0020dcd8";
    szQStr_lut3d_mem[0x323] = "00a0f8d9";
    szQStr_lut3d_mem[0x324] = "00000000";
    szQStr_lut3d_mem[0x325] = "00000000";
    szQStr_lut3d_mem[0x326] = "00000000";
    szQStr_lut3d_mem[0x327] = "00000000";
    szQStr_lut3d_mem[0x328] = "013074cb";
    szQStr_lut3d_mem[0x329] = "021070cb";
    szQStr_lut3d_mem[0x32a] = "0120f8d7";
    szQStr_lut3d_mem[0x32b] = "0180c0d1";
    szQStr_lut3d_mem[0x32c] = "00000000";
    szQStr_lut3d_mem[0x32d] = "00000000";
    szQStr_lut3d_mem[0x32e] = "00000000";
    szQStr_lut3d_mem[0x32f] = "00000000";
    szQStr_lut3d_mem[0x330] = "03907ccd";
    szQStr_lut3d_mem[0x331] = "04b0a8d1";
    szQStr_lut3d_mem[0x332] = "0310a0cf";
    szQStr_lut3d_mem[0x333] = "0480d0d2";
    szQStr_lut3d_mem[0x334] = "00000000";
    szQStr_lut3d_mem[0x335] = "00000000";
    szQStr_lut3d_mem[0x336] = "00000000";
    szQStr_lut3d_mem[0x337] = "00000000";
    szQStr_lut3d_mem[0x338] = "05b0b8d2";
    szQStr_lut3d_mem[0x339] = "0690b8d3";
    szQStr_lut3d_mem[0x33a] = "05b0e8d6";
    szQStr_lut3d_mem[0x33b] = "0690ecd7";
    szQStr_lut3d_mem[0x33c] = "00000000";
    szQStr_lut3d_mem[0x33d] = "00000000";
    szQStr_lut3d_mem[0x33e] = "00000000";
    szQStr_lut3d_mem[0x33f] = "00000000";
    szQStr_lut3d_mem[0x340] = "0750c8d4";
    szQStr_lut3d_mem[0x341] = "00000000";
    szQStr_lut3d_mem[0x342] = "0760f8d7";
    szQStr_lut3d_mem[0x343] = "00000000";
    szQStr_lut3d_mem[0x344] = "00000000";
    szQStr_lut3d_mem[0x345] = "00000000";
    szQStr_lut3d_mem[0x346] = "00000000";
    szQStr_lut3d_mem[0x347] = "00000000";
    szQStr_lut3d_mem[0x348] = "00210cdc";
    szQStr_lut3d_mem[0x349] = "009114dc";
    szQStr_lut3d_mem[0x34a] = "003154df";
    szQStr_lut3d_mem[0x34b] = "008144e0";
    szQStr_lut3d_mem[0x34c] = "00000000";
    szQStr_lut3d_mem[0x34d] = "00000000";
    szQStr_lut3d_mem[0x34e] = "00000000";
    szQStr_lut3d_mem[0x34f] = "00000000";
    szQStr_lut3d_mem[0x350] = "01213cdd";
    szQStr_lut3d_mem[0x351] = "025144d9";
    szQStr_lut3d_mem[0x352] = "01115ce0";
    szQStr_lut3d_mem[0x353] = "02b190df";
    szQStr_lut3d_mem[0x354] = "00000000";
    szQStr_lut3d_mem[0x355] = "00000000";
    szQStr_lut3d_mem[0x356] = "00000000";
    szQStr_lut3d_mem[0x357] = "00000000";
    szQStr_lut3d_mem[0x358] = "02d110d4";
    szQStr_lut3d_mem[0x359] = "045108d4";
    szQStr_lut3d_mem[0x35a] = "039198dc";
    szQStr_lut3d_mem[0x35b] = "043150d6";
    szQStr_lut3d_mem[0x35c] = "00000000";
    szQStr_lut3d_mem[0x35d] = "00000000";
    szQStr_lut3d_mem[0x35e] = "00000000";
    szQStr_lut3d_mem[0x35f] = "00000000";
    szQStr_lut3d_mem[0x360] = "05a120d8";
    szQStr_lut3d_mem[0x361] = "069128da";
    szQStr_lut3d_mem[0x362] = "05b168da";
    szQStr_lut3d_mem[0x363] = "06b174dd";
    szQStr_lut3d_mem[0x364] = "00000000";
    szQStr_lut3d_mem[0x365] = "00000000";
    szQStr_lut3d_mem[0x366] = "00000000";
    szQStr_lut3d_mem[0x367] = "00000000";
    szQStr_lut3d_mem[0x368] = "076130d9";
    szQStr_lut3d_mem[0x369] = "00000000";
    szQStr_lut3d_mem[0x36a] = "078178dc";
    szQStr_lut3d_mem[0x36b] = "00000000";
    szQStr_lut3d_mem[0x36c] = "00000000";
    szQStr_lut3d_mem[0x36d] = "00000000";
    szQStr_lut3d_mem[0x36e] = "00000000";
    szQStr_lut3d_mem[0x36f] = "00000000";
    szQStr_lut3d_mem[0x370] = "0091c4e2";
    szQStr_lut3d_mem[0x371] = "00b1a0e4";
    szQStr_lut3d_mem[0x372] = "01723ce6";
    szQStr_lut3d_mem[0x373] = "01a238e9";
    szQStr_lut3d_mem[0x374] = "00000000";
    szQStr_lut3d_mem[0x375] = "00000000";
    szQStr_lut3d_mem[0x376] = "00000000";
    szQStr_lut3d_mem[0x377] = "00000000";
    szQStr_lut3d_mem[0x378] = "011198e4";
    szQStr_lut3d_mem[0x379] = "02b1b8e3";
    szQStr_lut3d_mem[0x37a] = "01d228ea";
    szQStr_lut3d_mem[0x37b] = "029218ea";
    szQStr_lut3d_mem[0x37c] = "00000000";
    szQStr_lut3d_mem[0x37d] = "00000000";
    szQStr_lut3d_mem[0x37e] = "00000000";
    szQStr_lut3d_mem[0x37f] = "00000000";
    szQStr_lut3d_mem[0x380] = "0441f4e2";
    szQStr_lut3d_mem[0x381] = "0511e8dd";
    szQStr_lut3d_mem[0x382] = "04822ce9";
    szQStr_lut3d_mem[0x383] = "06626ce8";
    szQStr_lut3d_mem[0x384] = "00000000";
    szQStr_lut3d_mem[0x385] = "00000000";
    szQStr_lut3d_mem[0x386] = "00000000";
    szQStr_lut3d_mem[0x387] = "00000000";
    szQStr_lut3d_mem[0x388] = "0611c4dc";
    szQStr_lut3d_mem[0x389] = "0721d4e0";
    szQStr_lut3d_mem[0x38a] = "07224cdf";
    szQStr_lut3d_mem[0x38b] = "083250e4";
    szQStr_lut3d_mem[0x38c] = "00000000";
    szQStr_lut3d_mem[0x38d] = "00000000";
    szQStr_lut3d_mem[0x38e] = "00000000";
    szQStr_lut3d_mem[0x38f] = "00000000";
    szQStr_lut3d_mem[0x390] = "07d1d0df";
    szQStr_lut3d_mem[0x391] = "00000000";
    szQStr_lut3d_mem[0x392] = "08c248e3";
    szQStr_lut3d_mem[0x393] = "00000000";
    szQStr_lut3d_mem[0x394] = "00000000";
    szQStr_lut3d_mem[0x395] = "00000000";
    szQStr_lut3d_mem[0x396] = "00000000";
    szQStr_lut3d_mem[0x397] = "00000000";
    szQStr_lut3d_mem[0x398] = "021280e9";
    szQStr_lut3d_mem[0x399] = "027294ec";
    szQStr_lut3d_mem[0x39a] = "0292c0eb";
    szQStr_lut3d_mem[0x39b] = "0302d0ee";
    szQStr_lut3d_mem[0x39c] = "00000000";
    szQStr_lut3d_mem[0x39d] = "00000000";
    szQStr_lut3d_mem[0x39e] = "00000000";
    szQStr_lut3d_mem[0x39f] = "00000000";
    szQStr_lut3d_mem[0x3a0] = "02e2a4ee";
    szQStr_lut3d_mem[0x3a1] = "0382b4ef";
    szQStr_lut3d_mem[0x3a2] = "0382e4ef";
    szQStr_lut3d_mem[0x3a3] = "0422f8f0";
    szQStr_lut3d_mem[0x3a4] = "00000000";
    szQStr_lut3d_mem[0x3a5] = "00000000";
    szQStr_lut3d_mem[0x3a6] = "00000000";
    szQStr_lut3d_mem[0x3a7] = "00000000";
    szQStr_lut3d_mem[0x3a8] = "0552bcf0";
    szQStr_lut3d_mem[0x3a9] = "0722c4ef";
    szQStr_lut3d_mem[0x3aa] = "062318f1";
    szQStr_lut3d_mem[0x3ab] = "08133cf1";
    szQStr_lut3d_mem[0x3ac] = "00000000";
    szQStr_lut3d_mem[0x3ad] = "00000000";
    szQStr_lut3d_mem[0x3ae] = "00000000";
    szQStr_lut3d_mem[0x3af] = "00000000";
    szQStr_lut3d_mem[0x3b0] = "08e2f8ed";
    szQStr_lut3d_mem[0x3b1] = "09b2e0e5";
    szQStr_lut3d_mem[0x3b2] = "09c360f1";
    szQStr_lut3d_mem[0x3b3] = "0c937cf8";
    szQStr_lut3d_mem[0x3b4] = "00000000";
    szQStr_lut3d_mem[0x3b5] = "00000000";
    szQStr_lut3d_mem[0x3b6] = "00000000";
    szQStr_lut3d_mem[0x3b7] = "00000000";
    szQStr_lut3d_mem[0x3b8] = "0a62e0e9";
    szQStr_lut3d_mem[0x3b9] = "00000000";
    szQStr_lut3d_mem[0x3ba] = "0df378f7";
    szQStr_lut3d_mem[0x3bb] = "00000000";
    szQStr_lut3d_mem[0x3bc] = "00000000";
    szQStr_lut3d_mem[0x3bd] = "00000000";
    szQStr_lut3d_mem[0x3be] = "00000000";
    szQStr_lut3d_mem[0x3bf] = "00000000";
    szQStr_lut3d_mem[0x3c0] = "031300ed";
    szQStr_lut3d_mem[0x3c1] = "03830cee";
    szQStr_lut3d_mem[0x3c2] = "00000000";
    szQStr_lut3d_mem[0x3c3] = "00000000";
    szQStr_lut3d_mem[0x3c4] = "00000000";
    szQStr_lut3d_mem[0x3c5] = "00000000";
    szQStr_lut3d_mem[0x3c6] = "00000000";
    szQStr_lut3d_mem[0x3c7] = "00000000";
    szQStr_lut3d_mem[0x3c8] = "03e318ef";
    szQStr_lut3d_mem[0x3c9] = "046328f0";
    szQStr_lut3d_mem[0x3ca] = "00000000";
    szQStr_lut3d_mem[0x3cb] = "00000000";
    szQStr_lut3d_mem[0x3cc] = "00000000";
    szQStr_lut3d_mem[0x3cd] = "00000000";
    szQStr_lut3d_mem[0x3ce] = "00000000";
    szQStr_lut3d_mem[0x3cf] = "00000000";
    szQStr_lut3d_mem[0x3d0] = "05e33cf0";
    szQStr_lut3d_mem[0x3d1] = "079354f0";
    szQStr_lut3d_mem[0x3d2] = "00000000";
    szQStr_lut3d_mem[0x3d3] = "00000000";
    szQStr_lut3d_mem[0x3d4] = "00000000";
    szQStr_lut3d_mem[0x3d5] = "00000000";
    szQStr_lut3d_mem[0x3d6] = "00000000";
    szQStr_lut3d_mem[0x3d7] = "00000000";
    szQStr_lut3d_mem[0x3d8] = "090370f0";
    szQStr_lut3d_mem[0x3d9] = "0c53d0f8";
    szQStr_lut3d_mem[0x3da] = "00000000";
    szQStr_lut3d_mem[0x3db] = "00000000";
    szQStr_lut3d_mem[0x3dc] = "00000000";
    szQStr_lut3d_mem[0x3dd] = "00000000";
    szQStr_lut3d_mem[0x3de] = "00000000";
    szQStr_lut3d_mem[0x3df] = "00000000";
    szQStr_lut3d_mem[0x3e0] = "10040100";
    szQStr_lut3d_mem[0x3e1] = "00000000";
    szQStr_lut3d_mem[0x3e2] = "00000000";
    szQStr_lut3d_mem[0x3e3] = "00000000";
    szQStr_lut3d_mem[0x3e4] = "00000000";
    szQStr_lut3d_mem[0x3e5] = "00000000";
    szQStr_lut3d_mem[0x3e6] = "00000000";
    szQStr_lut3d_mem[0x3e7] = "00000000";

    return;
}

void IspPPsinter::init_rm_Shading_lut()
{
    szQStr_sinter_shading_rm_shading_lut[0x0] = "00000003";
    szQStr_sinter_shading_rm_shading_lut[0x1] = "00000004";
    szQStr_sinter_shading_rm_shading_lut[0x2] = "00000004";
    szQStr_sinter_shading_rm_shading_lut[0x3] = "00000007";
    szQStr_sinter_shading_rm_shading_lut[0x4] = "00000009";
    szQStr_sinter_shading_rm_shading_lut[0x5] = "0000000d";
    szQStr_sinter_shading_rm_shading_lut[0x6] = "00000014";
    szQStr_sinter_shading_rm_shading_lut[0x7] = "0000001a";
    szQStr_sinter_shading_rm_shading_lut[0x8] = "0000001c";
    szQStr_sinter_shading_rm_shading_lut[0x9] = "00000025";
    szQStr_sinter_shading_rm_shading_lut[0xa] = "0000002c";
    szQStr_sinter_shading_rm_shading_lut[0xb] = "0000002d";
    szQStr_sinter_shading_rm_shading_lut[0xc] = "00000035";
    szQStr_sinter_shading_rm_shading_lut[0xd] = "0000003c";
    szQStr_sinter_shading_rm_shading_lut[0xe] = "0000003f";
    szQStr_sinter_shading_rm_shading_lut[0xf] = "00000049";
    szQStr_sinter_shading_rm_shading_lut[0x10] = "0000004b";
    szQStr_sinter_shading_rm_shading_lut[0x11] = "0000004c";
    szQStr_sinter_shading_rm_shading_lut[0x12] = "00000058";
    szQStr_sinter_shading_rm_shading_lut[0x13] = "00000059";
    szQStr_sinter_shading_rm_shading_lut[0x14] = "0000005c";
    szQStr_sinter_shading_rm_shading_lut[0x15] = "00000065";
    szQStr_sinter_shading_rm_shading_lut[0x16] = "00000069";
    szQStr_sinter_shading_rm_shading_lut[0x17] = "00000071";
    szQStr_sinter_shading_rm_shading_lut[0x18] = "00000072";
    szQStr_sinter_shading_rm_shading_lut[0x19] = "00000089";
    szQStr_sinter_shading_rm_shading_lut[0x1a] = "0000009f";
    szQStr_sinter_shading_rm_shading_lut[0x1b] = "000000ab";
    szQStr_sinter_shading_rm_shading_lut[0x1c] = "000000d3";
    szQStr_sinter_shading_rm_shading_lut[0x1d] = "000000e2";
    szQStr_sinter_shading_rm_shading_lut[0x1e] = "000000e3";
    szQStr_sinter_shading_rm_shading_lut[0x1f] = "000000fa";
    szQStr_sinter_shading_rm_shading_lut[0x20] = "000000fa";
}

void IspPPsinter::init_sinter_noise_profile_lut_weight_lut()
{
    szQStr_sinter_noise_profile_lut_weight_lut[0x0] = "00000004";
    szQStr_sinter_noise_profile_lut_weight_lut[0x1] = "00000004";
    szQStr_sinter_noise_profile_lut_weight_lut[0x2] = "00000004";
    szQStr_sinter_noise_profile_lut_weight_lut[0x3] = "00000009";
    szQStr_sinter_noise_profile_lut_weight_lut[0x4] = "0000000f";
    szQStr_sinter_noise_profile_lut_weight_lut[0x5] = "00000012";
    szQStr_sinter_noise_profile_lut_weight_lut[0x6] = "00000017";
    szQStr_sinter_noise_profile_lut_weight_lut[0x7] = "0000001d";
    szQStr_sinter_noise_profile_lut_weight_lut[0x8] = "0000001d";
    szQStr_sinter_noise_profile_lut_weight_lut[0x9] = "0000001e";
    szQStr_sinter_noise_profile_lut_weight_lut[0xa] = "0000001e";
    szQStr_sinter_noise_profile_lut_weight_lut[0xb] = "00000020";
    szQStr_sinter_noise_profile_lut_weight_lut[0xc] = "00000024";
    szQStr_sinter_noise_profile_lut_weight_lut[0xd] = "00000026";
    szQStr_sinter_noise_profile_lut_weight_lut[0xe] = "00000027";
    szQStr_sinter_noise_profile_lut_weight_lut[0xf] = "00000028";
    szQStr_sinter_noise_profile_lut_weight_lut[0x10] = "00000029";
    szQStr_sinter_noise_profile_lut_weight_lut[0x11] = "00000029";
    szQStr_sinter_noise_profile_lut_weight_lut[0x12] = "0000002c";
    szQStr_sinter_noise_profile_lut_weight_lut[0x13] = "0000002c";
    szQStr_sinter_noise_profile_lut_weight_lut[0x14] = "0000002c";
    szQStr_sinter_noise_profile_lut_weight_lut[0x15] = "0000002d";
    szQStr_sinter_noise_profile_lut_weight_lut[0x16] = "0000002e";
    szQStr_sinter_noise_profile_lut_weight_lut[0x17] = "0000002f";
    szQStr_sinter_noise_profile_lut_weight_lut[0x18] = "00000030";
    szQStr_sinter_noise_profile_lut_weight_lut[0x19] = "00000033";
    szQStr_sinter_noise_profile_lut_weight_lut[0x1a] = "00000033";
    szQStr_sinter_noise_profile_lut_weight_lut[0x1b] = "00000034";
    szQStr_sinter_noise_profile_lut_weight_lut[0x1c] = "00000035";
    szQStr_sinter_noise_profile_lut_weight_lut[0x1d] = "00000035";
    szQStr_sinter_noise_profile_lut_weight_lut[0x1e] = "00000036";
    szQStr_sinter_noise_profile_lut_weight_lut[0x1f] = "00000039";
    szQStr_sinter_noise_profile_lut_weight_lut[0x20] = "00000039";
    szQStr_sinter_noise_profile_lut_weight_lut[0x21] = "0000003a";
    szQStr_sinter_noise_profile_lut_weight_lut[0x22] = "0000003c";
    szQStr_sinter_noise_profile_lut_weight_lut[0x23] = "0000003e";
    szQStr_sinter_noise_profile_lut_weight_lut[0x24] = "00000042";
    szQStr_sinter_noise_profile_lut_weight_lut[0x25] = "00000045";
    szQStr_sinter_noise_profile_lut_weight_lut[0x26] = "00000045";
    szQStr_sinter_noise_profile_lut_weight_lut[0x27] = "00000048";
    szQStr_sinter_noise_profile_lut_weight_lut[0x28] = "0000004a";
    szQStr_sinter_noise_profile_lut_weight_lut[0x29] = "0000004e";
    szQStr_sinter_noise_profile_lut_weight_lut[0x2a] = "00000050";
    szQStr_sinter_noise_profile_lut_weight_lut[0x2b] = "00000051";
    szQStr_sinter_noise_profile_lut_weight_lut[0x2c] = "00000051";
    szQStr_sinter_noise_profile_lut_weight_lut[0x2d] = "00000053";
    szQStr_sinter_noise_profile_lut_weight_lut[0x2e] = "00000053";
    szQStr_sinter_noise_profile_lut_weight_lut[0x2f] = "00000055";
    szQStr_sinter_noise_profile_lut_weight_lut[0x30] = "00000056";
    szQStr_sinter_noise_profile_lut_weight_lut[0x31] = "00000057";
    szQStr_sinter_noise_profile_lut_weight_lut[0x32] = "0000005e";
    szQStr_sinter_noise_profile_lut_weight_lut[0x33] = "00000061";
    szQStr_sinter_noise_profile_lut_weight_lut[0x34] = "00000061";
    szQStr_sinter_noise_profile_lut_weight_lut[0x35] = "00000064";
    szQStr_sinter_noise_profile_lut_weight_lut[0x36] = "00000067";
    szQStr_sinter_noise_profile_lut_weight_lut[0x37] = "00000068";
    szQStr_sinter_noise_profile_lut_weight_lut[0x38] = "00000069";
    szQStr_sinter_noise_profile_lut_weight_lut[0x39] = "0000006d";
    szQStr_sinter_noise_profile_lut_weight_lut[0x3a] = "0000006f";
    szQStr_sinter_noise_profile_lut_weight_lut[0x3b] = "0000006f";
    szQStr_sinter_noise_profile_lut_weight_lut[0x3c] = "0000006f";
    szQStr_sinter_noise_profile_lut_weight_lut[0x3d] = "00000070";
    szQStr_sinter_noise_profile_lut_weight_lut[0x3e] = "00000075";
    szQStr_sinter_noise_profile_lut_weight_lut[0x3f] = "00000076";
    szQStr_sinter_noise_profile_lut_weight_lut[0x40] = "0000007b";
    szQStr_sinter_noise_profile_lut_weight_lut[0x41] = "0000007d";
    szQStr_sinter_noise_profile_lut_weight_lut[0x42] = "0000007e";
    szQStr_sinter_noise_profile_lut_weight_lut[0x43] = "0000007f";
    szQStr_sinter_noise_profile_lut_weight_lut[0x44] = "0000007f";
    szQStr_sinter_noise_profile_lut_weight_lut[0x45] = "00000082";
    szQStr_sinter_noise_profile_lut_weight_lut[0x46] = "00000082";
    szQStr_sinter_noise_profile_lut_weight_lut[0x47] = "00000084";
    szQStr_sinter_noise_profile_lut_weight_lut[0x48] = "00000087";
    szQStr_sinter_noise_profile_lut_weight_lut[0x49] = "00000089";
    szQStr_sinter_noise_profile_lut_weight_lut[0x4a] = "00000089";
    szQStr_sinter_noise_profile_lut_weight_lut[0x4b] = "0000008c";
    szQStr_sinter_noise_profile_lut_weight_lut[0x4c] = "0000008f";
    szQStr_sinter_noise_profile_lut_weight_lut[0x4d] = "0000008f";
    szQStr_sinter_noise_profile_lut_weight_lut[0x4e] = "00000090";
    szQStr_sinter_noise_profile_lut_weight_lut[0x4f] = "00000091";
    szQStr_sinter_noise_profile_lut_weight_lut[0x50] = "00000091";
    szQStr_sinter_noise_profile_lut_weight_lut[0x51] = "00000094";
    szQStr_sinter_noise_profile_lut_weight_lut[0x52] = "00000095";
    szQStr_sinter_noise_profile_lut_weight_lut[0x53] = "00000095";
    szQStr_sinter_noise_profile_lut_weight_lut[0x54] = "00000098";
    szQStr_sinter_noise_profile_lut_weight_lut[0x55] = "0000009a";
    szQStr_sinter_noise_profile_lut_weight_lut[0x56] = "0000009d";
    szQStr_sinter_noise_profile_lut_weight_lut[0x57] = "0000009e";
    szQStr_sinter_noise_profile_lut_weight_lut[0x58] = "0000009f";
    szQStr_sinter_noise_profile_lut_weight_lut[0x59] = "000000a0";
    szQStr_sinter_noise_profile_lut_weight_lut[0x5a] = "000000a1";
    szQStr_sinter_noise_profile_lut_weight_lut[0x5b] = "000000a5";
    szQStr_sinter_noise_profile_lut_weight_lut[0x5c] = "000000a6";
    szQStr_sinter_noise_profile_lut_weight_lut[0x5d] = "000000a7";
    szQStr_sinter_noise_profile_lut_weight_lut[0x5e] = "000000ad";
    szQStr_sinter_noise_profile_lut_weight_lut[0x5f] = "000000b2";
    szQStr_sinter_noise_profile_lut_weight_lut[0x60] = "000000b4";
    szQStr_sinter_noise_profile_lut_weight_lut[0x61] = "000000b6";
    szQStr_sinter_noise_profile_lut_weight_lut[0x62] = "000000b6";
    szQStr_sinter_noise_profile_lut_weight_lut[0x63] = "000000b7";
    szQStr_sinter_noise_profile_lut_weight_lut[0x64] = "000000bb";
    szQStr_sinter_noise_profile_lut_weight_lut[0x65] = "000000bb";
    szQStr_sinter_noise_profile_lut_weight_lut[0x66] = "000000bc";
    szQStr_sinter_noise_profile_lut_weight_lut[0x67] = "000000bd";
    szQStr_sinter_noise_profile_lut_weight_lut[0x68] = "000000bd";
    szQStr_sinter_noise_profile_lut_weight_lut[0x69] = "000000be";
    szQStr_sinter_noise_profile_lut_weight_lut[0x6a] = "000000c4";
    szQStr_sinter_noise_profile_lut_weight_lut[0x6b] = "000000c4";
    szQStr_sinter_noise_profile_lut_weight_lut[0x6c] = "000000c7";
    szQStr_sinter_noise_profile_lut_weight_lut[0x6d] = "000000c8";
    szQStr_sinter_noise_profile_lut_weight_lut[0x6e] = "000000c9";
    szQStr_sinter_noise_profile_lut_weight_lut[0x6f] = "000000cc";
    szQStr_sinter_noise_profile_lut_weight_lut[0x70] = "000000d1";
    szQStr_sinter_noise_profile_lut_weight_lut[0x71] = "000000d8";
    szQStr_sinter_noise_profile_lut_weight_lut[0x72] = "000000db";
    szQStr_sinter_noise_profile_lut_weight_lut[0x73] = "000000dd";
    szQStr_sinter_noise_profile_lut_weight_lut[0x74] = "000000e0";
    szQStr_sinter_noise_profile_lut_weight_lut[0x75] = "000000e1";
    szQStr_sinter_noise_profile_lut_weight_lut[0x76] = "000000e3";
    szQStr_sinter_noise_profile_lut_weight_lut[0x77] = "000000e4";
    szQStr_sinter_noise_profile_lut_weight_lut[0x78] = "000000eb";
    szQStr_sinter_noise_profile_lut_weight_lut[0x79] = "000000ee";
    szQStr_sinter_noise_profile_lut_weight_lut[0x7a] = "000000f0";
    szQStr_sinter_noise_profile_lut_weight_lut[0x7b] = "000000f2";
    szQStr_sinter_noise_profile_lut_weight_lut[0x7c] = "000000f6";
    szQStr_sinter_noise_profile_lut_weight_lut[0x7d] = "000000f7";
    szQStr_sinter_noise_profile_lut_weight_lut[0x7e] = "000000fb";
    szQStr_sinter_noise_profile_lut_weight_lut[0x7f] = "000000fb";
}

void IspPPsinter::step1()
{

    for(unsigned int i = 0;i < M_LUT3D_MEM_NUMBER; ++i)
    {
        QString strLine;
        strLine.sprintf("lut3d_mem[%x]",i);

        writeLine(E_ACTION_WR,strLine,szQStr_lut3d_mem[i]);
        writeLine(E_ACTION_RR,strLine);
        writeLine(E_ACTION_RR,strLine);
    }
}

void IspPPsinter::step2()
{
    writeLine(E_ACTION_WR,"isp_config_ping.sinter.config1",ptEdit_config1->text());
    writeLine(E_ACTION_RR,"isp_config_ping.sinter.config1");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter.config2",ptEdit_config2->text());
    writeLine(E_ACTION_RR,"isp_config_ping.sinter.config2");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter.sad_filt_thresh",ptEdit_sad_filt_thresh->text());
    writeLine(E_ACTION_RR,"isp_config_ping.sinter.sad_filt_thresh");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter.reg_rm_center_x","01680041");
    writeLine(E_ACTION_RR,"isp_config_ping.sinter.reg_rm_center_x");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter.reg_rm_center_x",ptEdit_reg_rm_center_x->text());
    writeLine(E_ACTION_RR,"isp_config_ping.sinter.reg_rm_center_x");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter.rm_off_center_mult",ptEdit_rm_off_center_mult->text());
    writeLine(E_ACTION_RR,"isp_config_ping.sinter.rm_off_center_mult");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter.reg_thresh_0h","0000006c");
    writeLine(E_ACTION_RR,"isp_config_ping.sinter.reg_thresh_0h");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter.reg_thresh_0h","0000566c");
    writeLine(E_ACTION_RR,"isp_config_ping.sinter.reg_thresh_0h");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter.reg_thresh_0h","0089566c");
    writeLine(E_ACTION_RR,"isp_config_ping.sinter.reg_thresh_0h");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter.reg_thresh_0h",ptEdit_reg_thresh_0h->text());
    writeLine(E_ACTION_RR,"isp_config_ping.sinter.reg_thresh_0h");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter.reg_thresh_0v","000000be");
    writeLine(E_ACTION_RR,"isp_config_ping.sinter.reg_thresh_0v");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter.reg_thresh_0v","000009be");
    writeLine(E_ACTION_RR,"isp_config_ping.sinter.reg_thresh_0v");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter.reg_thresh_0v","009709be");
    writeLine(E_ACTION_RR,"isp_config_ping.sinter.reg_thresh_0v");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter.reg_thresh_0v",ptEdit_reg_thresh_0v->text());
    writeLine(E_ACTION_RR,"isp_config_ping.sinter.reg_thresh_0v");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter.reg_strength_0","ffffffd6");
    writeLine(E_ACTION_RR,"isp_config_ping.sinter.reg_strength_0");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter.reg_strength_0","ffff22d6");
    writeLine(E_ACTION_RR,"isp_config_ping.sinter.reg_strength_0");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter.reg_strength_0","fff722d6");
    writeLine(E_ACTION_RR,"isp_config_ping.sinter.reg_strength_0");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter.reg_strength_0",ptEdit_reg_strength_0->text());
    writeLine(E_ACTION_RR,"isp_config_ping.sinter.reg_strength_0");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter_noise_profile.reg_use_lut","00000802");
    writeLine(E_ACTION_RR,"isp_config_ping.sinter_noise_profile.reg_use_lut");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter_noise_profile.reg_use_lut","00000800");
    writeLine(E_ACTION_RR,"isp_config_ping.sinter_noise_profile.reg_use_lut");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter_noise_profile.reg_use_lut","00000804");
    writeLine(E_ACTION_RR,"isp_config_ping.sinter_noise_profile.reg_use_lut");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter_noise_profile.black_level",ptEdit_black_level->text());
    writeLine(E_ACTION_RR,"isp_config_ping.sinter_noise_profile.black_level");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter_noise_profile.thresh1",ptEdit_thresh1->text());
    writeLine(E_ACTION_RR,"isp_config_ping.sinter_noise_profile.thresh1");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter_noise_profile.thresh2",ptEdit_thresh2->text());
    writeLine(E_ACTION_RR,"isp_config_ping.sinter_noise_profile.thresh2");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter_noise_profile.thresh3",ptEdit_thresh3->text());
    writeLine(E_ACTION_RR,"isp_config_ping.sinter_noise_profile.thresh3");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter_noise_profile.reg_use_lut",ptEdit_reg_use_lut->text());
    writeLine(E_ACTION_RR,"isp_config_ping.sinter_noise_profile.reg_use_lut");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter_noise_profile.reg_noise_level_0","0000003d");
    writeLine(E_ACTION_RR,"isp_config_ping.sinter_noise_profile.reg_noise_level_0");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter_noise_profile.reg_noise_level_0","00003d3d");
    writeLine(E_ACTION_RR,"isp_config_ping.sinter_noise_profile.reg_noise_level_0");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter_noise_profile.reg_noise_level_0","003d3d3d");
    writeLine(E_ACTION_RR,"isp_config_ping.sinter_noise_profile.reg_noise_level_0");

    writeLine(E_ACTION_WR,"isp_config_ping.sinter_noise_profile.reg_noise_level_0",ptEdit_reg_noise_level_0->text());
    writeLine(E_ACTION_RR,"isp_config_ping.sinter_noise_profile.reg_noise_level_0");

    for(unsigned int i = 0;i < M_SINTER_SHADING_RM_SHADING_LUT_NUMBER; ++i)
    {
        QString strLine;
        strLine.sprintf("isp_config_ping.sinter_shading.rm_shading_lut[%x]",i);

        writeLine(E_ACTION_WR,strLine,szQStr_sinter_shading_rm_shading_lut[i]);
        writeLine(E_ACTION_RR,strLine);
    }

    for(unsigned int i = 0;i < M_SINTER_NOISE_PROFILE_LUT_WEIGHT_LUT_NUMBER; ++i)
    {
        QString strLine;
        strLine.sprintf("isp_config_ping.sinter_noise_profile_lut.weight_lut[%x]",i);

        writeLine(E_ACTION_WR,strLine,szQStr_sinter_noise_profile_lut_weight_lut[i]);
        writeLine(E_ACTION_RR,strLine);
    }
}

void IspPPsinter::clickedSlot(bool checked)
{
    if(checked)
        return;

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
