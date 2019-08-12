#include "ispppradial_shading.h"
#include <QGridLayout>
IspPPradial_shading::IspPPradial_shading(QWidget *parent) :
    QWidget(parent)
{
    init_array();

    QGridLayout *layoutGrid = new QGridLayout;

    // add edit
    ptLabel_enable  = new QLabel("enable :");
    ptEdit_enable  = new QLineEdit("00000001");
    layoutGrid->addWidget(ptLabel_enable ,0,0);layoutGrid->addWidget(ptEdit_enable ,0,1);

    ptLabel_reg_centerb_x  = new QLabel("reg_centerb_x :");
    ptEdit_reg_centerb_x  = new QLineEdit("0068006d");
    layoutGrid->addWidget(ptLabel_reg_centerb_x ,1,0);layoutGrid->addWidget(ptEdit_reg_centerb_x ,1,1);

    ptLabel_reg_centerg_x  = new QLabel("reg_centerg_x :");
    ptEdit_reg_centerg_x  = new QLineEdit("005b0001");
    layoutGrid->addWidget(ptLabel_reg_centerg_x ,2,0);layoutGrid->addWidget(ptEdit_reg_centerg_x ,2,1);

    ptLabel_reg_centerir_x  = new QLabel("reg_centerir_x :");
    ptEdit_reg_centerir_x  = new QLineEdit("00760054");
    layoutGrid->addWidget(ptLabel_reg_centerir_x ,3,0);layoutGrid->addWidget(ptEdit_reg_centerir_x ,3,1);

    ptLabel_reg_centerr_x  = new QLabel("reg_centerr_x :");
    ptEdit_reg_centerr_x  = new QLineEdit("00700019");
    layoutGrid->addWidget(ptLabel_reg_centerr_x ,4,0);layoutGrid->addWidget(ptEdit_reg_centerr_x ,4,1);

    ptLabel_reg_off_center_multbx  = new QLabel("reg_off_center_multbx :");
    ptEdit_reg_off_center_multbx  = new QLineEdit("ffffffff");
    layoutGrid->addWidget(ptLabel_reg_off_center_multbx ,5,0);layoutGrid->addWidget(ptEdit_reg_off_center_multbx ,5,1);

    ptLabel_reg_off_center_multgx  = new QLabel("reg_off_center_multgx :");
    ptEdit_reg_off_center_multgx  = new QLineEdit("ffffffff");
    layoutGrid->addWidget(ptLabel_reg_off_center_multgx ,6,0);layoutGrid->addWidget(ptEdit_reg_off_center_multgx ,6,1);

    ptLabel_reg_off_center_multirx  = new QLabel("reg_off_center_multirx :");
    ptEdit_reg_off_center_multirx  = new QLineEdit("ffffffff");
    layoutGrid->addWidget(ptLabel_reg_off_center_multirx ,7,0);layoutGrid->addWidget(ptEdit_reg_off_center_multirx ,7,1);

    ptLabel_reg_off_center_multrx  = new QLabel("reg_off_center_multrx :");
    ptEdit_reg_off_center_multrx  = new QLineEdit("ffffffff");
    layoutGrid->addWidget(ptLabel_reg_off_center_multrx ,8,0);layoutGrid->addWidget(ptEdit_reg_off_center_multrx ,8,1);

    ptCb_radial_shading_ping_mem  = new QComboBox;
    ptEdit_radial_shading_ping_mem = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_radial_shading_ping_mem,9,0);layoutGrid->addWidget(ptEdit_radial_shading_ping_mem,9,1);
    for(unsigned int i = 0;i < M_RADIAL_SHADING_PING_MEM_NUMBER; ++i)
    {
        QString str;
        str.sprintf("radial_shading_ping_mem[%x]",i);
        ptCb_radial_shading_ping_mem->addItem(str);
//        szQStr_radial_shading_ping_mem[i].sprintf("%x",i);
    }
    ptEdit_radial_shading_ping_mem->setText(szQStr_radial_shading_ping_mem[ptCb_radial_shading_ping_mem->currentIndex()]);

//    ptPBtn = new QPushButton("确定");
//    layoutGrid->addWidget(ptPBtn,40,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

//    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

    connect(ptCb_radial_shading_ping_mem,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_radial_shading_ping_mem(int)));
    connect(ptEdit_radial_shading_ping_mem,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_radial_shading_ping_mem(const QString)));

    setLayout(mainLayout);
}

void IspPPradial_shading::init_array()
{
    szQStr_radial_shading_ping_mem[0x0] = "00001000";
    szQStr_radial_shading_ping_mem[0x1] = "0000103e";
    szQStr_radial_shading_ping_mem[0x2] = "00001074";
    szQStr_radial_shading_ping_mem[0x3] = "000010a8";
    szQStr_radial_shading_ping_mem[0x4] = "000010da";
    szQStr_radial_shading_ping_mem[0x5] = "0000110b";
    szQStr_radial_shading_ping_mem[0x6] = "0000113b";
    szQStr_radial_shading_ping_mem[0x7] = "0000116b";
    szQStr_radial_shading_ping_mem[0x8] = "0000119a";
    szQStr_radial_shading_ping_mem[0x9] = "000011c8";
    szQStr_radial_shading_ping_mem[0xa] = "000011f6";
    szQStr_radial_shading_ping_mem[0xb] = "00001224";
    szQStr_radial_shading_ping_mem[0xc] = "00001251";
    szQStr_radial_shading_ping_mem[0xd] = "0000127e";
    szQStr_radial_shading_ping_mem[0xe] = "000012aa";
    szQStr_radial_shading_ping_mem[0xf] = "000012d7";
    szQStr_radial_shading_ping_mem[0x10] = "00001303";
    szQStr_radial_shading_ping_mem[0x11] = "0000132f";
    szQStr_radial_shading_ping_mem[0x12] = "0000135b";
    szQStr_radial_shading_ping_mem[0x13] = "00001386";
    szQStr_radial_shading_ping_mem[0x14] = "000013b2";
    szQStr_radial_shading_ping_mem[0x15] = "000013dd";
    szQStr_radial_shading_ping_mem[0x16] = "00001408";
    szQStr_radial_shading_ping_mem[0x17] = "00001433";
    szQStr_radial_shading_ping_mem[0x18] = "0000145e";
    szQStr_radial_shading_ping_mem[0x19] = "00001489";
    szQStr_radial_shading_ping_mem[0x1a] = "000014b3";
    szQStr_radial_shading_ping_mem[0x1b] = "000014de";
    szQStr_radial_shading_ping_mem[0x1c] = "00001508";
    szQStr_radial_shading_ping_mem[0x1d] = "00001533";
    szQStr_radial_shading_ping_mem[0x1e] = "0000155d";
    szQStr_radial_shading_ping_mem[0x1f] = "00001587";
    szQStr_radial_shading_ping_mem[0x20] = "000015b2";
    szQStr_radial_shading_ping_mem[0x21] = "000015dc";
    szQStr_radial_shading_ping_mem[0x22] = "00001606";
    szQStr_radial_shading_ping_mem[0x23] = "00001630";
    szQStr_radial_shading_ping_mem[0x24] = "0000165a";
    szQStr_radial_shading_ping_mem[0x25] = "00001684";
    szQStr_radial_shading_ping_mem[0x26] = "000016ae";
    szQStr_radial_shading_ping_mem[0x27] = "000016d7";
    szQStr_radial_shading_ping_mem[0x28] = "00001701";
    szQStr_radial_shading_ping_mem[0x29] = "0000172b";
    szQStr_radial_shading_ping_mem[0x2a] = "00001755";
    szQStr_radial_shading_ping_mem[0x2b] = "0000177f";
    szQStr_radial_shading_ping_mem[0x2c] = "000017a8";
    szQStr_radial_shading_ping_mem[0x2d] = "000017d2";
    szQStr_radial_shading_ping_mem[0x2e] = "000017fc";
    szQStr_radial_shading_ping_mem[0x2f] = "00001826";
    szQStr_radial_shading_ping_mem[0x30] = "00001850";
    szQStr_radial_shading_ping_mem[0x31] = "0000187a";
    szQStr_radial_shading_ping_mem[0x32] = "000018a3";
    szQStr_radial_shading_ping_mem[0x33] = "000018cd";
    szQStr_radial_shading_ping_mem[0x34] = "000018f7";
    szQStr_radial_shading_ping_mem[0x35] = "00001921";
    szQStr_radial_shading_ping_mem[0x36] = "0000194b";
    szQStr_radial_shading_ping_mem[0x37] = "00001975";
    szQStr_radial_shading_ping_mem[0x38] = "0000199f";
    szQStr_radial_shading_ping_mem[0x39] = "000019c9";
    szQStr_radial_shading_ping_mem[0x3a] = "000019f4";
    szQStr_radial_shading_ping_mem[0x3b] = "00001a1e";
    szQStr_radial_shading_ping_mem[0x3c] = "00001a48";
    szQStr_radial_shading_ping_mem[0x3d] = "00001a73";
    szQStr_radial_shading_ping_mem[0x3e] = "00001a9e";
    szQStr_radial_shading_ping_mem[0x3f] = "00001ac8";
    szQStr_radial_shading_ping_mem[0x40] = "00001af3";
    szQStr_radial_shading_ping_mem[0x41] = "00001b1e";
    szQStr_radial_shading_ping_mem[0x42] = "00001b49";
    szQStr_radial_shading_ping_mem[0x43] = "00001b74";
    szQStr_radial_shading_ping_mem[0x44] = "00001ba0";
    szQStr_radial_shading_ping_mem[0x45] = "00001bcb";
    szQStr_radial_shading_ping_mem[0x46] = "00001bf7";
    szQStr_radial_shading_ping_mem[0x47] = "00001c23";
    szQStr_radial_shading_ping_mem[0x48] = "00001c4f";
    szQStr_radial_shading_ping_mem[0x49] = "00001c7b";
    szQStr_radial_shading_ping_mem[0x4a] = "00001ca7";
    szQStr_radial_shading_ping_mem[0x4b] = "00001cd4";
    szQStr_radial_shading_ping_mem[0x4c] = "00001d01";
    szQStr_radial_shading_ping_mem[0x4d] = "00001d2e";
    szQStr_radial_shading_ping_mem[0x4e] = "00001d5b";
    szQStr_radial_shading_ping_mem[0x4f] = "00001d89";
    szQStr_radial_shading_ping_mem[0x50] = "00001db6";
    szQStr_radial_shading_ping_mem[0x51] = "00001de5";
    szQStr_radial_shading_ping_mem[0x52] = "00001e13";
    szQStr_radial_shading_ping_mem[0x53] = "00001e42";
    szQStr_radial_shading_ping_mem[0x54] = "00001e71";
    szQStr_radial_shading_ping_mem[0x55] = "00001ea0";
    szQStr_radial_shading_ping_mem[0x56] = "00001ed0";
    szQStr_radial_shading_ping_mem[0x57] = "00001f00";
    szQStr_radial_shading_ping_mem[0x58] = "00001f30";
    szQStr_radial_shading_ping_mem[0x59] = "00001f61";
    szQStr_radial_shading_ping_mem[0x5a] = "00001f92";
    szQStr_radial_shading_ping_mem[0x5b] = "00001fc4";
    szQStr_radial_shading_ping_mem[0x5c] = "00001ff6";
    szQStr_radial_shading_ping_mem[0x5d] = "00002028";
    szQStr_radial_shading_ping_mem[0x5e] = "0000205b";
    szQStr_radial_shading_ping_mem[0x5f] = "0000208f";
    szQStr_radial_shading_ping_mem[0x60] = "000020c3";
    szQStr_radial_shading_ping_mem[0x61] = "000020f7";
    szQStr_radial_shading_ping_mem[0x62] = "0000212c";
    szQStr_radial_shading_ping_mem[0x63] = "00002162";
    szQStr_radial_shading_ping_mem[0x64] = "00002198";
    szQStr_radial_shading_ping_mem[0x65] = "000021ce";
    szQStr_radial_shading_ping_mem[0x66] = "00002206";
    szQStr_radial_shading_ping_mem[0x67] = "0000223e";
    szQStr_radial_shading_ping_mem[0x68] = "00002277";
    szQStr_radial_shading_ping_mem[0x69] = "000022b0";
    szQStr_radial_shading_ping_mem[0x6a] = "000022ea";
    szQStr_radial_shading_ping_mem[0x6b] = "00002325";
    szQStr_radial_shading_ping_mem[0x6c] = "00002361";
    szQStr_radial_shading_ping_mem[0x6d] = "0000239d";
    szQStr_radial_shading_ping_mem[0x6e] = "000023da";
    szQStr_radial_shading_ping_mem[0x6f] = "00002418";
    szQStr_radial_shading_ping_mem[0x70] = "00002457";
    szQStr_radial_shading_ping_mem[0x71] = "00002497";
    szQStr_radial_shading_ping_mem[0x72] = "000024d8";
    szQStr_radial_shading_ping_mem[0x73] = "0000251a";
    szQStr_radial_shading_ping_mem[0x74] = "0000255d";
    szQStr_radial_shading_ping_mem[0x75] = "000025a1";
    szQStr_radial_shading_ping_mem[0x76] = "000025e6";
    szQStr_radial_shading_ping_mem[0x77] = "0000262c";
    szQStr_radial_shading_ping_mem[0x78] = "00002673";
    szQStr_radial_shading_ping_mem[0x79] = "000026bc";
    szQStr_radial_shading_ping_mem[0x7a] = "00002706";
    szQStr_radial_shading_ping_mem[0x7b] = "00002751";
    szQStr_radial_shading_ping_mem[0x7c] = "0000279d";
    szQStr_radial_shading_ping_mem[0x7d] = "000027eb";
    szQStr_radial_shading_ping_mem[0x7e] = "0000283b";
    szQStr_radial_shading_ping_mem[0x7f] = "0000288b";
    szQStr_radial_shading_ping_mem[0x80] = "000028c5";
    szQStr_radial_shading_ping_mem[0x100] = "00001000";
    szQStr_radial_shading_ping_mem[0x101] = "0000103e";
    szQStr_radial_shading_ping_mem[0x102] = "00001074";
    szQStr_radial_shading_ping_mem[0x103] = "000010a8";
    szQStr_radial_shading_ping_mem[0x104] = "000010da";
    szQStr_radial_shading_ping_mem[0x105] = "0000110b";
    szQStr_radial_shading_ping_mem[0x106] = "0000113b";
    szQStr_radial_shading_ping_mem[0x107] = "0000116b";
    szQStr_radial_shading_ping_mem[0x108] = "0000119a";
    szQStr_radial_shading_ping_mem[0x109] = "000011c8";
    szQStr_radial_shading_ping_mem[0x10a] = "000011f6";
    szQStr_radial_shading_ping_mem[0x10b] = "00001224";
    szQStr_radial_shading_ping_mem[0x10c] = "00001251";
    szQStr_radial_shading_ping_mem[0x10d] = "0000127e";
    szQStr_radial_shading_ping_mem[0x10e] = "000012aa";
    szQStr_radial_shading_ping_mem[0x10f] = "000012d7";
    szQStr_radial_shading_ping_mem[0x110] = "00001303";
    szQStr_radial_shading_ping_mem[0x111] = "0000132f";
    szQStr_radial_shading_ping_mem[0x112] = "0000135b";
    szQStr_radial_shading_ping_mem[0x113] = "00001386";
    szQStr_radial_shading_ping_mem[0x114] = "000013b2";
    szQStr_radial_shading_ping_mem[0x115] = "000013dd";
    szQStr_radial_shading_ping_mem[0x116] = "00001408";
    szQStr_radial_shading_ping_mem[0x117] = "00001433";
    szQStr_radial_shading_ping_mem[0x118] = "0000145e";
    szQStr_radial_shading_ping_mem[0x119] = "00001489";
    szQStr_radial_shading_ping_mem[0x11a] = "000014b3";
    szQStr_radial_shading_ping_mem[0x11b] = "000014de";
    szQStr_radial_shading_ping_mem[0x11c] = "00001508";
    szQStr_radial_shading_ping_mem[0x11d] = "00001533";
    szQStr_radial_shading_ping_mem[0x11e] = "0000155d";
    szQStr_radial_shading_ping_mem[0x11f] = "00001587";
    szQStr_radial_shading_ping_mem[0x120] = "000015b2";
    szQStr_radial_shading_ping_mem[0x121] = "000015dc";
    szQStr_radial_shading_ping_mem[0x122] = "00001606";
    szQStr_radial_shading_ping_mem[0x123] = "00001630";
    szQStr_radial_shading_ping_mem[0x124] = "0000165a";
    szQStr_radial_shading_ping_mem[0x125] = "00001684";
    szQStr_radial_shading_ping_mem[0x126] = "000016ae";
    szQStr_radial_shading_ping_mem[0x127] = "000016d7";
    szQStr_radial_shading_ping_mem[0x128] = "00001701";
    szQStr_radial_shading_ping_mem[0x129] = "0000172b";
    szQStr_radial_shading_ping_mem[0x12a] = "00001755";
    szQStr_radial_shading_ping_mem[0x12b] = "0000177f";
    szQStr_radial_shading_ping_mem[0x12c] = "000017a8";
    szQStr_radial_shading_ping_mem[0x12d] = "000017d2";
    szQStr_radial_shading_ping_mem[0x12e] = "000017fc";
    szQStr_radial_shading_ping_mem[0x12f] = "00001826";
    szQStr_radial_shading_ping_mem[0x130] = "00001850";
    szQStr_radial_shading_ping_mem[0x131] = "0000187a";
    szQStr_radial_shading_ping_mem[0x132] = "000018a3";
    szQStr_radial_shading_ping_mem[0x133] = "000018cd";
    szQStr_radial_shading_ping_mem[0x134] = "000018f7";
    szQStr_radial_shading_ping_mem[0x135] = "00001921";
    szQStr_radial_shading_ping_mem[0x136] = "0000194b";
    szQStr_radial_shading_ping_mem[0x137] = "00001975";
    szQStr_radial_shading_ping_mem[0x138] = "0000199f";
    szQStr_radial_shading_ping_mem[0x139] = "000019c9";
    szQStr_radial_shading_ping_mem[0x13a] = "000019f4";
    szQStr_radial_shading_ping_mem[0x13b] = "00001a1e";
    szQStr_radial_shading_ping_mem[0x13c] = "00001a48";
    szQStr_radial_shading_ping_mem[0x13d] = "00001a73";
    szQStr_radial_shading_ping_mem[0x13e] = "00001a9e";
    szQStr_radial_shading_ping_mem[0x13f] = "00001ac8";
    szQStr_radial_shading_ping_mem[0x140] = "00001af3";
    szQStr_radial_shading_ping_mem[0x141] = "00001b1e";
    szQStr_radial_shading_ping_mem[0x142] = "00001b49";
    szQStr_radial_shading_ping_mem[0x143] = "00001b74";
    szQStr_radial_shading_ping_mem[0x144] = "00001ba0";
    szQStr_radial_shading_ping_mem[0x145] = "00001bcb";
    szQStr_radial_shading_ping_mem[0x146] = "00001bf7";
    szQStr_radial_shading_ping_mem[0x147] = "00001c23";
    szQStr_radial_shading_ping_mem[0x148] = "00001c4f";
    szQStr_radial_shading_ping_mem[0x149] = "00001c7b";
    szQStr_radial_shading_ping_mem[0x14a] = "00001ca7";
    szQStr_radial_shading_ping_mem[0x14b] = "00001cd4";
    szQStr_radial_shading_ping_mem[0x14c] = "00001d01";
    szQStr_radial_shading_ping_mem[0x14d] = "00001d2e";
    szQStr_radial_shading_ping_mem[0x14e] = "00001d5b";
    szQStr_radial_shading_ping_mem[0x14f] = "00001d89";
    szQStr_radial_shading_ping_mem[0x150] = "00001db6";
    szQStr_radial_shading_ping_mem[0x151] = "00001de5";
    szQStr_radial_shading_ping_mem[0x152] = "00001e13";
    szQStr_radial_shading_ping_mem[0x153] = "00001e42";
    szQStr_radial_shading_ping_mem[0x154] = "00001e71";
    szQStr_radial_shading_ping_mem[0x155] = "00001ea0";
    szQStr_radial_shading_ping_mem[0x156] = "00001ed0";
    szQStr_radial_shading_ping_mem[0x157] = "00001f00";
    szQStr_radial_shading_ping_mem[0x158] = "00001f30";
    szQStr_radial_shading_ping_mem[0x159] = "00001f61";
    szQStr_radial_shading_ping_mem[0x15a] = "00001f92";
    szQStr_radial_shading_ping_mem[0x15b] = "00001fc4";
    szQStr_radial_shading_ping_mem[0x15c] = "00001ff6";
    szQStr_radial_shading_ping_mem[0x15d] = "00002028";
    szQStr_radial_shading_ping_mem[0x15e] = "0000205b";
    szQStr_radial_shading_ping_mem[0x15f] = "0000208f";
    szQStr_radial_shading_ping_mem[0x160] = "000020c3";
    szQStr_radial_shading_ping_mem[0x161] = "000020f7";
    szQStr_radial_shading_ping_mem[0x162] = "0000212c";
    szQStr_radial_shading_ping_mem[0x163] = "00002162";
    szQStr_radial_shading_ping_mem[0x164] = "00002198";
    szQStr_radial_shading_ping_mem[0x165] = "000021ce";
    szQStr_radial_shading_ping_mem[0x166] = "00002206";
    szQStr_radial_shading_ping_mem[0x167] = "0000223e";
    szQStr_radial_shading_ping_mem[0x168] = "00002277";
    szQStr_radial_shading_ping_mem[0x169] = "000022b0";
    szQStr_radial_shading_ping_mem[0x16a] = "000022ea";
    szQStr_radial_shading_ping_mem[0x16b] = "00002325";
    szQStr_radial_shading_ping_mem[0x16c] = "00002361";
    szQStr_radial_shading_ping_mem[0x16d] = "0000239d";
    szQStr_radial_shading_ping_mem[0x16e] = "000023da";
    szQStr_radial_shading_ping_mem[0x16f] = "00002418";
    szQStr_radial_shading_ping_mem[0x170] = "00002457";
    szQStr_radial_shading_ping_mem[0x171] = "00002497";
    szQStr_radial_shading_ping_mem[0x172] = "000024d8";
    szQStr_radial_shading_ping_mem[0x173] = "0000251a";
    szQStr_radial_shading_ping_mem[0x174] = "0000255d";
    szQStr_radial_shading_ping_mem[0x175] = "000025a1";
    szQStr_radial_shading_ping_mem[0x176] = "000025e6";
    szQStr_radial_shading_ping_mem[0x177] = "0000262c";
    szQStr_radial_shading_ping_mem[0x178] = "00002673";
    szQStr_radial_shading_ping_mem[0x179] = "000026bc";
    szQStr_radial_shading_ping_mem[0x17a] = "00002706";
    szQStr_radial_shading_ping_mem[0x17b] = "00002751";
    szQStr_radial_shading_ping_mem[0x17c] = "0000279d";
    szQStr_radial_shading_ping_mem[0x17d] = "000027eb";
    szQStr_radial_shading_ping_mem[0x17e] = "0000283b";
    szQStr_radial_shading_ping_mem[0x17f] = "0000288b";
    szQStr_radial_shading_ping_mem[0x180] = "000028c5";
    szQStr_radial_shading_ping_mem[0x200] = "00001000";
    szQStr_radial_shading_ping_mem[0x201] = "0000103e";
    szQStr_radial_shading_ping_mem[0x202] = "00001074";
    szQStr_radial_shading_ping_mem[0x203] = "000010a8";
    szQStr_radial_shading_ping_mem[0x204] = "000010da";
    szQStr_radial_shading_ping_mem[0x205] = "0000110b";
    szQStr_radial_shading_ping_mem[0x206] = "0000113b";
    szQStr_radial_shading_ping_mem[0x207] = "0000116b";
    szQStr_radial_shading_ping_mem[0x208] = "0000119a";
    szQStr_radial_shading_ping_mem[0x209] = "000011c8";
    szQStr_radial_shading_ping_mem[0x20a] = "000011f6";
    szQStr_radial_shading_ping_mem[0x20b] = "00001224";
    szQStr_radial_shading_ping_mem[0x20c] = "00001251";
    szQStr_radial_shading_ping_mem[0x20d] = "0000127e";
    szQStr_radial_shading_ping_mem[0x20e] = "000012aa";
    szQStr_radial_shading_ping_mem[0x20f] = "000012d7";
    szQStr_radial_shading_ping_mem[0x210] = "00001303";
    szQStr_radial_shading_ping_mem[0x211] = "0000132f";
    szQStr_radial_shading_ping_mem[0x212] = "0000135b";
    szQStr_radial_shading_ping_mem[0x213] = "00001386";
    szQStr_radial_shading_ping_mem[0x214] = "000013b2";
    szQStr_radial_shading_ping_mem[0x215] = "000013dd";
    szQStr_radial_shading_ping_mem[0x216] = "00001408";
    szQStr_radial_shading_ping_mem[0x217] = "00001433";
    szQStr_radial_shading_ping_mem[0x218] = "0000145e";
    szQStr_radial_shading_ping_mem[0x219] = "00001489";
    szQStr_radial_shading_ping_mem[0x21a] = "000014b3";
    szQStr_radial_shading_ping_mem[0x21b] = "000014de";
    szQStr_radial_shading_ping_mem[0x21c] = "00001508";
    szQStr_radial_shading_ping_mem[0x21d] = "00001533";
    szQStr_radial_shading_ping_mem[0x21e] = "0000155d";
    szQStr_radial_shading_ping_mem[0x21f] = "00001587";
    szQStr_radial_shading_ping_mem[0x220] = "000015b2";
    szQStr_radial_shading_ping_mem[0x221] = "000015dc";
    szQStr_radial_shading_ping_mem[0x222] = "00001606";
    szQStr_radial_shading_ping_mem[0x223] = "00001630";
    szQStr_radial_shading_ping_mem[0x224] = "0000165a";
    szQStr_radial_shading_ping_mem[0x225] = "00001684";
    szQStr_radial_shading_ping_mem[0x226] = "000016ae";
    szQStr_radial_shading_ping_mem[0x227] = "000016d7";
    szQStr_radial_shading_ping_mem[0x228] = "00001701";
    szQStr_radial_shading_ping_mem[0x229] = "0000172b";
    szQStr_radial_shading_ping_mem[0x22a] = "00001755";
    szQStr_radial_shading_ping_mem[0x22b] = "0000177f";
    szQStr_radial_shading_ping_mem[0x22c] = "000017a8";
    szQStr_radial_shading_ping_mem[0x22d] = "000017d2";
    szQStr_radial_shading_ping_mem[0x22e] = "000017fc";
    szQStr_radial_shading_ping_mem[0x22f] = "00001826";
    szQStr_radial_shading_ping_mem[0x230] = "00001850";
    szQStr_radial_shading_ping_mem[0x231] = "0000187a";
    szQStr_radial_shading_ping_mem[0x232] = "000018a3";
    szQStr_radial_shading_ping_mem[0x233] = "000018cd";
    szQStr_radial_shading_ping_mem[0x234] = "000018f7";
    szQStr_radial_shading_ping_mem[0x235] = "00001921";
    szQStr_radial_shading_ping_mem[0x236] = "0000194b";
    szQStr_radial_shading_ping_mem[0x237] = "00001975";
    szQStr_radial_shading_ping_mem[0x238] = "0000199f";
    szQStr_radial_shading_ping_mem[0x239] = "000019c9";
    szQStr_radial_shading_ping_mem[0x23a] = "000019f4";
    szQStr_radial_shading_ping_mem[0x23b] = "00001a1e";
    szQStr_radial_shading_ping_mem[0x23c] = "00001a48";
    szQStr_radial_shading_ping_mem[0x23d] = "00001a73";
    szQStr_radial_shading_ping_mem[0x23e] = "00001a9e";
    szQStr_radial_shading_ping_mem[0x23f] = "00001ac8";
    szQStr_radial_shading_ping_mem[0x240] = "00001af3";
    szQStr_radial_shading_ping_mem[0x241] = "00001b1e";
    szQStr_radial_shading_ping_mem[0x242] = "00001b49";
    szQStr_radial_shading_ping_mem[0x243] = "00001b74";
    szQStr_radial_shading_ping_mem[0x244] = "00001ba0";
    szQStr_radial_shading_ping_mem[0x245] = "00001bcb";
    szQStr_radial_shading_ping_mem[0x246] = "00001bf7";
    szQStr_radial_shading_ping_mem[0x247] = "00001c23";
    szQStr_radial_shading_ping_mem[0x248] = "00001c4f";
    szQStr_radial_shading_ping_mem[0x249] = "00001c7b";
    szQStr_radial_shading_ping_mem[0x24a] = "00001ca7";
    szQStr_radial_shading_ping_mem[0x24b] = "00001cd4";
    szQStr_radial_shading_ping_mem[0x24c] = "00001d01";
    szQStr_radial_shading_ping_mem[0x24d] = "00001d2e";
    szQStr_radial_shading_ping_mem[0x24e] = "00001d5b";
    szQStr_radial_shading_ping_mem[0x24f] = "00001d89";
    szQStr_radial_shading_ping_mem[0x250] = "00001db6";
    szQStr_radial_shading_ping_mem[0x251] = "00001de5";
    szQStr_radial_shading_ping_mem[0x252] = "00001e13";
    szQStr_radial_shading_ping_mem[0x253] = "00001e42";
    szQStr_radial_shading_ping_mem[0x254] = "00001e71";
    szQStr_radial_shading_ping_mem[0x255] = "00001ea0";
    szQStr_radial_shading_ping_mem[0x256] = "00001ed0";
    szQStr_radial_shading_ping_mem[0x257] = "00001f00";
    szQStr_radial_shading_ping_mem[0x258] = "00001f30";
    szQStr_radial_shading_ping_mem[0x259] = "00001f61";
    szQStr_radial_shading_ping_mem[0x25a] = "00001f92";
    szQStr_radial_shading_ping_mem[0x25b] = "00001fc4";
    szQStr_radial_shading_ping_mem[0x25c] = "00001ff6";
    szQStr_radial_shading_ping_mem[0x25d] = "00002028";
    szQStr_radial_shading_ping_mem[0x25e] = "0000205b";
    szQStr_radial_shading_ping_mem[0x25f] = "0000208f";
    szQStr_radial_shading_ping_mem[0x260] = "000020c3";
    szQStr_radial_shading_ping_mem[0x261] = "000020f7";
    szQStr_radial_shading_ping_mem[0x262] = "0000212c";
    szQStr_radial_shading_ping_mem[0x263] = "00002162";
    szQStr_radial_shading_ping_mem[0x264] = "00002198";
    szQStr_radial_shading_ping_mem[0x265] = "000021ce";
    szQStr_radial_shading_ping_mem[0x266] = "00002206";
    szQStr_radial_shading_ping_mem[0x267] = "0000223e";
    szQStr_radial_shading_ping_mem[0x268] = "00002277";
    szQStr_radial_shading_ping_mem[0x269] = "000022b0";
    szQStr_radial_shading_ping_mem[0x26a] = "000022ea";
    szQStr_radial_shading_ping_mem[0x26b] = "00002325";
    szQStr_radial_shading_ping_mem[0x26c] = "00002361";
    szQStr_radial_shading_ping_mem[0x26d] = "0000239d";
    szQStr_radial_shading_ping_mem[0x26e] = "000023da";
    szQStr_radial_shading_ping_mem[0x26f] = "00002418";
    szQStr_radial_shading_ping_mem[0x270] = "00002457";
    szQStr_radial_shading_ping_mem[0x271] = "00002497";
    szQStr_radial_shading_ping_mem[0x272] = "000024d8";
    szQStr_radial_shading_ping_mem[0x273] = "0000251a";
    szQStr_radial_shading_ping_mem[0x274] = "0000255d";
    szQStr_radial_shading_ping_mem[0x275] = "000025a1";
    szQStr_radial_shading_ping_mem[0x276] = "000025e6";
    szQStr_radial_shading_ping_mem[0x277] = "0000262c";
    szQStr_radial_shading_ping_mem[0x278] = "00002673";
    szQStr_radial_shading_ping_mem[0x279] = "000026bc";
    szQStr_radial_shading_ping_mem[0x27a] = "00002706";
    szQStr_radial_shading_ping_mem[0x27b] = "00002751";
    szQStr_radial_shading_ping_mem[0x27c] = "0000279d";
    szQStr_radial_shading_ping_mem[0x27d] = "000027eb";
    szQStr_radial_shading_ping_mem[0x27e] = "0000283b";
    szQStr_radial_shading_ping_mem[0x27f] = "0000288b";
    szQStr_radial_shading_ping_mem[0x280] = "000028c5";
    szQStr_radial_shading_ping_mem[0x300] = "00001000";
    szQStr_radial_shading_ping_mem[0x301] = "0000103e";
    szQStr_radial_shading_ping_mem[0x302] = "00001074";
    szQStr_radial_shading_ping_mem[0x303] = "000010a8";
    szQStr_radial_shading_ping_mem[0x304] = "000010da";
    szQStr_radial_shading_ping_mem[0x305] = "0000110b";
    szQStr_radial_shading_ping_mem[0x306] = "0000113b";
    szQStr_radial_shading_ping_mem[0x307] = "0000116b";
    szQStr_radial_shading_ping_mem[0x308] = "0000119a";
    szQStr_radial_shading_ping_mem[0x309] = "000011c8";
    szQStr_radial_shading_ping_mem[0x30a] = "000011f6";
    szQStr_radial_shading_ping_mem[0x30b] = "00001224";
    szQStr_radial_shading_ping_mem[0x30c] = "00001251";
    szQStr_radial_shading_ping_mem[0x30d] = "0000127e";
    szQStr_radial_shading_ping_mem[0x30e] = "000012aa";
    szQStr_radial_shading_ping_mem[0x30f] = "000012d7";
    szQStr_radial_shading_ping_mem[0x310] = "00001303";
    szQStr_radial_shading_ping_mem[0x311] = "0000132f";
    szQStr_radial_shading_ping_mem[0x312] = "0000135b";
    szQStr_radial_shading_ping_mem[0x313] = "00001386";
    szQStr_radial_shading_ping_mem[0x314] = "000013b2";
    szQStr_radial_shading_ping_mem[0x315] = "000013dd";
    szQStr_radial_shading_ping_mem[0x316] = "00001408";
    szQStr_radial_shading_ping_mem[0x317] = "00001433";
    szQStr_radial_shading_ping_mem[0x318] = "0000145e";
    szQStr_radial_shading_ping_mem[0x319] = "00001489";
    szQStr_radial_shading_ping_mem[0x31a] = "000014b3";
    szQStr_radial_shading_ping_mem[0x31b] = "000014de";
    szQStr_radial_shading_ping_mem[0x31c] = "00001508";
    szQStr_radial_shading_ping_mem[0x31d] = "00001533";
    szQStr_radial_shading_ping_mem[0x31e] = "0000155d";
    szQStr_radial_shading_ping_mem[0x31f] = "00001587";
    szQStr_radial_shading_ping_mem[0x320] = "000015b2";
    szQStr_radial_shading_ping_mem[0x321] = "000015dc";
    szQStr_radial_shading_ping_mem[0x322] = "00001606";
    szQStr_radial_shading_ping_mem[0x323] = "00001630";
    szQStr_radial_shading_ping_mem[0x324] = "0000165a";
    szQStr_radial_shading_ping_mem[0x325] = "00001684";
    szQStr_radial_shading_ping_mem[0x326] = "000016ae";
    szQStr_radial_shading_ping_mem[0x327] = "000016d7";
    szQStr_radial_shading_ping_mem[0x328] = "00001701";
    szQStr_radial_shading_ping_mem[0x329] = "0000172b";
    szQStr_radial_shading_ping_mem[0x32a] = "00001755";
    szQStr_radial_shading_ping_mem[0x32b] = "0000177f";
    szQStr_radial_shading_ping_mem[0x32c] = "000017a8";
    szQStr_radial_shading_ping_mem[0x32d] = "000017d2";
    szQStr_radial_shading_ping_mem[0x32e] = "000017fc";
    szQStr_radial_shading_ping_mem[0x32f] = "00001826";
    szQStr_radial_shading_ping_mem[0x330] = "00001850";
    szQStr_radial_shading_ping_mem[0x331] = "0000187a";
    szQStr_radial_shading_ping_mem[0x332] = "000018a3";
    szQStr_radial_shading_ping_mem[0x333] = "000018cd";
    szQStr_radial_shading_ping_mem[0x334] = "000018f7";
    szQStr_radial_shading_ping_mem[0x335] = "00001921";
    szQStr_radial_shading_ping_mem[0x336] = "0000194b";
    szQStr_radial_shading_ping_mem[0x337] = "00001975";
    szQStr_radial_shading_ping_mem[0x338] = "0000199f";
    szQStr_radial_shading_ping_mem[0x339] = "000019c9";
    szQStr_radial_shading_ping_mem[0x33a] = "000019f4";
    szQStr_radial_shading_ping_mem[0x33b] = "00001a1e";
    szQStr_radial_shading_ping_mem[0x33c] = "00001a48";
    szQStr_radial_shading_ping_mem[0x33d] = "00001a73";
    szQStr_radial_shading_ping_mem[0x33e] = "00001a9e";
    szQStr_radial_shading_ping_mem[0x33f] = "00001ac8";
    szQStr_radial_shading_ping_mem[0x340] = "00001af3";
    szQStr_radial_shading_ping_mem[0x341] = "00001b1e";
    szQStr_radial_shading_ping_mem[0x342] = "00001b49";
    szQStr_radial_shading_ping_mem[0x343] = "00001b74";
    szQStr_radial_shading_ping_mem[0x344] = "00001ba0";
    szQStr_radial_shading_ping_mem[0x345] = "00001bcb";
    szQStr_radial_shading_ping_mem[0x346] = "00001bf7";
    szQStr_radial_shading_ping_mem[0x347] = "00001c23";
    szQStr_radial_shading_ping_mem[0x348] = "00001c4f";
    szQStr_radial_shading_ping_mem[0x349] = "00001c7b";
    szQStr_radial_shading_ping_mem[0x34a] = "00001ca7";
    szQStr_radial_shading_ping_mem[0x34b] = "00001cd4";
    szQStr_radial_shading_ping_mem[0x34c] = "00001d01";
    szQStr_radial_shading_ping_mem[0x34d] = "00001d2e";
    szQStr_radial_shading_ping_mem[0x34e] = "00001d5b";
    szQStr_radial_shading_ping_mem[0x34f] = "00001d89";
    szQStr_radial_shading_ping_mem[0x350] = "00001db6";
    szQStr_radial_shading_ping_mem[0x351] = "00001de5";
    szQStr_radial_shading_ping_mem[0x352] = "00001e13";
    szQStr_radial_shading_ping_mem[0x353] = "00001e42";
    szQStr_radial_shading_ping_mem[0x354] = "00001e71";
    szQStr_radial_shading_ping_mem[0x355] = "00001ea0";
    szQStr_radial_shading_ping_mem[0x356] = "00001ed0";
    szQStr_radial_shading_ping_mem[0x357] = "00001f00";
    szQStr_radial_shading_ping_mem[0x358] = "00001f30";
    szQStr_radial_shading_ping_mem[0x359] = "00001f61";
    szQStr_radial_shading_ping_mem[0x35a] = "00001f92";
    szQStr_radial_shading_ping_mem[0x35b] = "00001fc4";
    szQStr_radial_shading_ping_mem[0x35c] = "00001ff6";
    szQStr_radial_shading_ping_mem[0x35d] = "00002028";
    szQStr_radial_shading_ping_mem[0x35e] = "0000205b";
    szQStr_radial_shading_ping_mem[0x35f] = "0000208f";
    szQStr_radial_shading_ping_mem[0x360] = "000020c3";
    szQStr_radial_shading_ping_mem[0x361] = "000020f7";
    szQStr_radial_shading_ping_mem[0x362] = "0000212c";
    szQStr_radial_shading_ping_mem[0x363] = "00002162";
    szQStr_radial_shading_ping_mem[0x364] = "00002198";
    szQStr_radial_shading_ping_mem[0x365] = "000021ce";
    szQStr_radial_shading_ping_mem[0x366] = "00002206";
    szQStr_radial_shading_ping_mem[0x367] = "0000223e";
    szQStr_radial_shading_ping_mem[0x368] = "00002277";
    szQStr_radial_shading_ping_mem[0x369] = "000022b0";
    szQStr_radial_shading_ping_mem[0x36a] = "000022ea";
    szQStr_radial_shading_ping_mem[0x36b] = "00002325";
    szQStr_radial_shading_ping_mem[0x36c] = "00002361";
    szQStr_radial_shading_ping_mem[0x36d] = "0000239d";
    szQStr_radial_shading_ping_mem[0x36e] = "000023da";
    szQStr_radial_shading_ping_mem[0x36f] = "00002418";
    szQStr_radial_shading_ping_mem[0x370] = "00002457";
    szQStr_radial_shading_ping_mem[0x371] = "00002497";
    szQStr_radial_shading_ping_mem[0x372] = "000024d8";
    szQStr_radial_shading_ping_mem[0x373] = "0000251a";
    szQStr_radial_shading_ping_mem[0x374] = "0000255d";
    szQStr_radial_shading_ping_mem[0x375] = "000025a1";
    szQStr_radial_shading_ping_mem[0x376] = "000025e6";
    szQStr_radial_shading_ping_mem[0x377] = "0000262c";
    szQStr_radial_shading_ping_mem[0x378] = "00002673";
    szQStr_radial_shading_ping_mem[0x379] = "000026bc";
    szQStr_radial_shading_ping_mem[0x37a] = "00002706";
    szQStr_radial_shading_ping_mem[0x37b] = "00002751";
    szQStr_radial_shading_ping_mem[0x37c] = "0000279d";
    szQStr_radial_shading_ping_mem[0x37d] = "000027eb";
    szQStr_radial_shading_ping_mem[0x37e] = "0000283b";
    szQStr_radial_shading_ping_mem[0x37f] = "0000288b";
    szQStr_radial_shading_ping_mem[0x380] = "000028c5";
}

void IspPPradial_shading::step1()
{
    writeLine(E_ACTION_WR,"isp_config_ping.radial_shading.enable",ptEdit_enable->text());
    writeLine(E_ACTION_RR,"isp_config_ping.radial_shading.enable");

    writeLine(E_ACTION_WR,"isp_config_ping.radial_shading.reg_centerr_x","021c0019");
    writeLine(E_ACTION_RR,"isp_config_ping.radial_shading.reg_centerr_x");

    writeLine(E_ACTION_WR,"isp_config_ping.radial_shading.reg_centerr_x",ptEdit_reg_centerr_x->text());
    writeLine(E_ACTION_RR,"isp_config_ping.radial_shading.reg_centerr_x");

    writeLine(E_ACTION_WR,"isp_config_ping.radial_shading.reg_centerg_x","021c0001");
    writeLine(E_ACTION_RR,"isp_config_ping.radial_shading.reg_centerg_x");

    writeLine(E_ACTION_WR,"isp_config_ping.radial_shading.reg_centerg_x",ptEdit_reg_centerg_x->text());
    writeLine(E_ACTION_RR,"isp_config_ping.radial_shading.reg_centerg_x");

    writeLine(E_ACTION_WR,"isp_config_ping.radial_shading.reg_centerb_x","021c006d");
    writeLine(E_ACTION_RR,"isp_config_ping.radial_shading.reg_centerb_x");

    writeLine(E_ACTION_WR,"isp_config_ping.radial_shading.reg_centerb_x",ptEdit_reg_centerb_x->text());
    writeLine(E_ACTION_RR,"isp_config_ping.radial_shading.reg_centerb_x");

    writeLine(E_ACTION_WR,"isp_config_ping.radial_shading.reg_centerir_x","021c0054");
    writeLine(E_ACTION_RR,"isp_config_ping.radial_shading.reg_centerir_x");

    writeLine(E_ACTION_WR,"isp_config_ping.radial_shading.reg_centerir_x",ptEdit_reg_centerir_x->text());
    writeLine(E_ACTION_RR,"isp_config_ping.radial_shading.reg_centerir_x");

    writeLine(E_ACTION_WR,"isp_config_ping.radial_shading.reg_off_center_multrx","06eaffff");
    writeLine(E_ACTION_RR,"isp_config_ping.radial_shading.reg_off_center_multrx");

    writeLine(E_ACTION_WR,"isp_config_ping.radial_shading.reg_off_center_multrx",ptEdit_reg_off_center_multrx->text());
    writeLine(E_ACTION_RR,"isp_config_ping.radial_shading.reg_off_center_multrx");

    writeLine(E_ACTION_WR,"isp_config_ping.radial_shading.reg_off_center_multgx","06eaffff");
    writeLine(E_ACTION_RR,"isp_config_ping.radial_shading.reg_off_center_multgx");

    writeLine(E_ACTION_WR,"isp_config_ping.radial_shading.reg_off_center_multgx",ptEdit_reg_off_center_multgx->text());
    writeLine(E_ACTION_RR,"isp_config_ping.radial_shading.reg_off_center_multgx");

    writeLine(E_ACTION_WR,"isp_config_ping.radial_shading.reg_off_center_multbx","06eaffff");
    writeLine(E_ACTION_RR,"isp_config_ping.radial_shading.reg_off_center_multbx");

    writeLine(E_ACTION_WR,"isp_config_ping.radial_shading.reg_off_center_multbx",ptEdit_reg_off_center_multbx->text());
    writeLine(E_ACTION_RR,"isp_config_ping.radial_shading.reg_off_center_multbx");

    writeLine(E_ACTION_WR,"isp_config_ping.radial_shading.reg_off_center_multirx","06eaffff");
    writeLine(E_ACTION_RR,"isp_config_ping.radial_shading.reg_off_center_multirx");

    writeLine(E_ACTION_WR,"isp_config_ping.radial_shading.reg_off_center_multirx",ptEdit_reg_off_center_multirx->text());
    writeLine(E_ACTION_RR,"isp_config_ping.radial_shading.reg_off_center_multirx");

    for(unsigned int i = 0;i < M_RADIAL_SHADING_PING_MEM_NUMBER; ++i)
    {
        QString strLine;
        strLine.sprintf("radial_shading_ping_mem[%x]",i);

        if(szQStr_radial_shading_ping_mem[i].length() > 0)
        {
            writeLine(E_ACTION_WR,strLine,szQStr_radial_shading_ping_mem[i]);
            writeLine(E_ACTION_RR,strLine);
        }
    }
}

void IspPPradial_shading::clickedSlot(bool checked)
{
    if(checked)
        return;
    QString str_enable = ptEdit_enable->text();
    QString str_reg_centerb_x = ptEdit_reg_centerb_x->text();
    QString str_reg_centerg_x = ptEdit_reg_centerg_x->text();
    QString str_reg_centerir_x = ptEdit_reg_centerir_x->text();
    QString str_reg_centerr_x = ptEdit_reg_centerr_x->text();
    QString str_reg_off_center_multbx = ptEdit_reg_off_center_multbx->text();
    QString str_reg_off_center_multgx = ptEdit_reg_off_center_multgx->text();
    QString str_reg_off_center_multirx = ptEdit_reg_off_center_multirx->text();
    QString str_reg_off_center_multrx = ptEdit_reg_off_center_multrx->text();
}

void IspPPradial_shading::activatedSlot_radial_shading_ping_mem(int index)
{
    ptEdit_radial_shading_ping_mem->setText(szQStr_radial_shading_ping_mem[index]);
}

void IspPPradial_shading::textChangedSlot_radial_shading_ping_mem(const QString &text)
{
    int index = ptCb_radial_shading_ping_mem->currentIndex();
    szQStr_radial_shading_ping_mem[index] = text;
}
