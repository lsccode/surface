#include "ispppdecompander.h"
#include <QGridLayout>
IspPPdecompander::IspPPdecompander(QWidget *parent) :
    QWidget(parent)
{
    init_array();

    QGridLayout *layoutGrid = new QGridLayout;

    ptLabel_decompander0_reg_enable = new QLabel("decompander0 reg_enable :");
    ptEdit_decompander0_reg_enable  = new QLineEdit("00000001");
    layoutGrid->addWidget(ptLabel_decompander0_reg_enable,0,0);layoutGrid->addWidget(ptEdit_decompander0_reg_enable,0,1);

    ptLabel_decompander1_reg_enable = new QLabel("decompander1 reg_enable :");
    ptEdit_decompander1_reg_enable  = new QLineEdit("00000011");
    layoutGrid->addWidget(ptLabel_decompander1_reg_enable,1,0);layoutGrid->addWidget(ptEdit_decompander1_reg_enable,1,1);

    ptCb_decompander0_ping_mem = new QComboBox;
    ptEdit_decompander0_ping_mem  = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_decompander0_ping_mem,2,0);layoutGrid->addWidget(ptEdit_decompander0_ping_mem,2,1);
    for(unsigned int i = 0;i < M_DECOMPANDER0_PING_MEN; ++i)
    {
        QString str;
        str.sprintf("decompander0_ping_mem[%x]",i);
        ptCb_decompander0_ping_mem->addItem(str);
//        szQStr_decompander0_ping_mem[i].sprintf("%x",i);
    }
    ptEdit_decompander0_ping_mem->setText(szQStr_decompander0_ping_mem[ptCb_decompander0_ping_mem->currentIndex()]);

    ptCb_decompander1_ping_mem  = new QComboBox;
    ptEdit_decompander1_ping_mem = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_decompander1_ping_mem,3,0);layoutGrid->addWidget(ptEdit_decompander1_ping_mem,3,1);
    for(unsigned int i = 0;i < M_DECOMPANDER1_PING_MEN; ++i)
    {
        QString str;
        str.sprintf("decompander1_ping_mem[%x]",i);
        ptCb_decompander1_ping_mem->addItem(str);
//        szQStr_decompander1_ping_mem[i].sprintf("%x",i);
    }
    ptEdit_decompander1_ping_mem->setText(szQStr_decompander1_ping_mem[ptCb_decompander1_ping_mem->currentIndex()]);

//    ptPBtn = new QPushButton("确定");
//    layoutGrid->addWidget(ptPBtn,5,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

//    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

    connect(ptCb_decompander0_ping_mem,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_decompander0_ping(int)));
    connect(ptEdit_decompander0_ping_mem,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_decompander0_ping(const QString)));

    connect(ptCb_decompander1_ping_mem,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_decompander1_ping(int)));
    connect(ptEdit_decompander1_ping_mem,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_decompander1_ping(const QString)));

    setLayout(mainLayout);
}

void IspPPdecompander::init_array()
{
    szQStr_decompander0_ping_mem[0x0] = "000914bd";
    szQStr_decompander0_ping_mem[0x1] = "000a7ea7";
    szQStr_decompander0_ping_mem[0x2] = "000d5bf8";
    szQStr_decompander0_ping_mem[0x3] = "000f0c12";
    szQStr_decompander0_ping_mem[0x4] = "000fdcce";
    szQStr_decompander0_ping_mem[0x5] = "00073fc6";
    szQStr_decompander0_ping_mem[0x6] = "000c5c48";
    szQStr_decompander0_ping_mem[0x7] = "0000eca3";
    szQStr_decompander0_ping_mem[0x8] = "00074cff";
    szQStr_decompander0_ping_mem[0x9] = "000c3e01";
    szQStr_decompander0_ping_mem[0xa] = "00080776";
    szQStr_decompander0_ping_mem[0xb] = "000f9e5e";
    szQStr_decompander0_ping_mem[0xc] = "000a82a0";
    szQStr_decompander0_ping_mem[0xd] = "000f3c0e";
    szQStr_decompander0_ping_mem[0xe] = "00088be7";
    szQStr_decompander0_ping_mem[0xf] = "00063a65";
    szQStr_decompander0_ping_mem[0x10] = "000e9454";
    szQStr_decompander0_ping_mem[0x11] = "0004ee29";
    szQStr_decompander0_ping_mem[0x12] = "000bdcbb";
    szQStr_decompander0_ping_mem[0x13] = "000bb398";
    szQStr_decompander0_ping_mem[0x14] = "000e05a9";
    szQStr_decompander0_ping_mem[0x15] = "000aad63";
    szQStr_decompander0_ping_mem[0x16] = "000f1b45";
    szQStr_decompander0_ping_mem[0x17] = "000a3027";
    szQStr_decompander0_ping_mem[0x18] = "000ac057";
    szQStr_decompander0_ping_mem[0x19] = "00051603";
    szQStr_decompander0_ping_mem[0x1a] = "000e82cb";
    szQStr_decompander0_ping_mem[0x1b] = "000137a8";
    szQStr_decompander0_ping_mem[0x1c] = "0006aef0";
    szQStr_decompander0_ping_mem[0x1d] = "0008c387";
    szQStr_decompander0_ping_mem[0x1e] = "00056322";
    szQStr_decompander0_ping_mem[0x1f] = "00060c9b";
    szQStr_decompander0_ping_mem[0x20] = "00084add";


    szQStr_decompander1_ping_mem[0x0] = "000017f5";
    szQStr_decompander1_ping_mem[0x1] = "0000219a";
    szQStr_decompander1_ping_mem[0x2] = "00003a18";
    szQStr_decompander1_ping_mem[0x3] = "00004d78";
    szQStr_decompander1_ping_mem[0x4] = "0000575f";
    szQStr_decompander1_ping_mem[0x5] = "000059e7";
    szQStr_decompander1_ping_mem[0x6] = "00007c2c";
    szQStr_decompander1_ping_mem[0x7] = "0000967b";
    szQStr_decompander1_ping_mem[0x8] = "00009c86";
    szQStr_decompander1_ping_mem[0x9] = "00009cbb";
    szQStr_decompander1_ping_mem[0xa] = "0000b4f0";
    szQStr_decompander1_ping_mem[0xb] = "0000cf13";
    szQStr_decompander1_ping_mem[0xc] = "0000e860";
    szQStr_decompander1_ping_mem[0xd] = "0000e9e0";
    szQStr_decompander1_ping_mem[0xe] = "00011e9c";
    szQStr_decompander1_ping_mem[0xf] = "0001264f";
    szQStr_decompander1_ping_mem[0x10] = "00012a18";
    szQStr_decompander1_ping_mem[0x11] = "00013894";
    szQStr_decompander1_ping_mem[0x12] = "000143be";
    szQStr_decompander1_ping_mem[0x13] = "000143ee";
    szQStr_decompander1_ping_mem[0x14] = "0001544a";
    szQStr_decompander1_ping_mem[0x15] = "00016c7a";
    szQStr_decompander1_ping_mem[0x16] = "0001898b";
    szQStr_decompander1_ping_mem[0x17] = "00018ded";
    szQStr_decompander1_ping_mem[0x18] = "0001996a";
    szQStr_decompander1_ping_mem[0x19] = "0001b085";
    szQStr_decompander1_ping_mem[0x1a] = "0001e12f";
    szQStr_decompander1_ping_mem[0x1b] = "0001e1b8";
    szQStr_decompander1_ping_mem[0x1c] = "0001ea5b";
    szQStr_decompander1_ping_mem[0x1d] = "00021c1a";
    szQStr_decompander1_ping_mem[0x1e] = "000221c5";
    szQStr_decompander1_ping_mem[0x1f] = "0002476f";
    szQStr_decompander1_ping_mem[0x20] = "00024773";
    szQStr_decompander1_ping_mem[0x21] = "000248d7";
    szQStr_decompander1_ping_mem[0x22] = "00025425";
    szQStr_decompander1_ping_mem[0x23] = "00025e9d";
    szQStr_decompander1_ping_mem[0x24] = "000270e5";
    szQStr_decompander1_ping_mem[0x25] = "00028015";
    szQStr_decompander1_ping_mem[0x26] = "000288f8";
    szQStr_decompander1_ping_mem[0x27] = "00029968";
    szQStr_decompander1_ping_mem[0x28] = "0002b375";
    szQStr_decompander1_ping_mem[0x29] = "0002b559";
    szQStr_decompander1_ping_mem[0x2a] = "0002b892";
    szQStr_decompander1_ping_mem[0x2b] = "0002bee9";
    szQStr_decompander1_ping_mem[0x2c] = "0002c87e";
    szQStr_decompander1_ping_mem[0x2d] = "0002dec3";
    szQStr_decompander1_ping_mem[0x2e] = "0002e02d";
    szQStr_decompander1_ping_mem[0x2f] = "0002f7bf";
    szQStr_decompander1_ping_mem[0x30] = "0002f9fc";
    szQStr_decompander1_ping_mem[0x31] = "0003019a";
    szQStr_decompander1_ping_mem[0x32] = "00030bcd";
    szQStr_decompander1_ping_mem[0x33] = "00031dc2";
    szQStr_decompander1_ping_mem[0x34] = "000337c5";
    szQStr_decompander1_ping_mem[0x35] = "00033fe8";
    szQStr_decompander1_ping_mem[0x36] = "00034f18";
    szQStr_decompander1_ping_mem[0x37] = "0003511d";
    szQStr_decompander1_ping_mem[0x38] = "000351dd";
    szQStr_decompander1_ping_mem[0x39] = "0003531d";
    szQStr_decompander1_ping_mem[0x3a] = "0003627f";
    szQStr_decompander1_ping_mem[0x3b] = "00038e7f";
    szQStr_decompander1_ping_mem[0x3c] = "00039200";
    szQStr_decompander1_ping_mem[0x3d] = "0003a7ed";
    szQStr_decompander1_ping_mem[0x3e] = "0003ad9e";
    szQStr_decompander1_ping_mem[0x3f] = "0003be63";
    szQStr_decompander1_ping_mem[0x40] = "0003c3ce";
    szQStr_decompander1_ping_mem[0x41] = "0003d5fc";
    szQStr_decompander1_ping_mem[0x42] = "0003f528";
    szQStr_decompander1_ping_mem[0x43] = "00040ec5";
    szQStr_decompander1_ping_mem[0x44] = "000422af";
    szQStr_decompander1_ping_mem[0x45] = "00044cbe";
    szQStr_decompander1_ping_mem[0x46] = "00045f3c";
    szQStr_decompander1_ping_mem[0x47] = "00046c5a";
    szQStr_decompander1_ping_mem[0x48] = "00047020";
    szQStr_decompander1_ping_mem[0x49] = "00048057";
    szQStr_decompander1_ping_mem[0x4a] = "000483ac";
    szQStr_decompander1_ping_mem[0x4b] = "0004a632";
    szQStr_decompander1_ping_mem[0x4c] = "0004ad38";
    szQStr_decompander1_ping_mem[0x4d] = "0004b260";
    szQStr_decompander1_ping_mem[0x4e] = "0004baf7";
    szQStr_decompander1_ping_mem[0x4f] = "0004bbb4";
    szQStr_decompander1_ping_mem[0x50] = "0004c2bf";
    szQStr_decompander1_ping_mem[0x51] = "0004c86f";
    szQStr_decompander1_ping_mem[0x52] = "0004d315";
    szQStr_decompander1_ping_mem[0x53] = "0004d960";
    szQStr_decompander1_ping_mem[0x54] = "0004dba8";
    szQStr_decompander1_ping_mem[0x55] = "0004dd4a";
    szQStr_decompander1_ping_mem[0x56] = "0004f3ad";
    szQStr_decompander1_ping_mem[0x57] = "00050381";
    szQStr_decompander1_ping_mem[0x58] = "000522f4";
    szQStr_decompander1_ping_mem[0x59] = "00057172";
    szQStr_decompander1_ping_mem[0x5a] = "00057661";
    szQStr_decompander1_ping_mem[0x5b] = "000577f8";
    szQStr_decompander1_ping_mem[0x5c] = "000582b8";
    szQStr_decompander1_ping_mem[0x5d] = "00058340";
    szQStr_decompander1_ping_mem[0x5e] = "00058d46";
    szQStr_decompander1_ping_mem[0x5f] = "00059bc0";
    szQStr_decompander1_ping_mem[0x60] = "00059df1";
    szQStr_decompander1_ping_mem[0x61] = "0005bca1";
    szQStr_decompander1_ping_mem[0x62] = "0005d99c";
    szQStr_decompander1_ping_mem[0x63] = "0005dd04";
    szQStr_decompander1_ping_mem[0x64] = "0005e806";
    szQStr_decompander1_ping_mem[0x65] = "0005e815";
    szQStr_decompander1_ping_mem[0x66] = "000600e8";
    szQStr_decompander1_ping_mem[0x67] = "00060d02";
    szQStr_decompander1_ping_mem[0x68] = "00060d83";
    szQStr_decompander1_ping_mem[0x69] = "00060e1b";
    szQStr_decompander1_ping_mem[0x6a] = "00061f79";
    szQStr_decompander1_ping_mem[0x6b] = "0006212b";
    szQStr_decompander1_ping_mem[0x6c] = "00062fc0";
    szQStr_decompander1_ping_mem[0x6d] = "00065a8f";
    szQStr_decompander1_ping_mem[0x6e] = "00065fa9";
    szQStr_decompander1_ping_mem[0x6f] = "00066ebc";
    szQStr_decompander1_ping_mem[0x70] = "000696fc";
    szQStr_decompander1_ping_mem[0x71] = "0006a854";
    szQStr_decompander1_ping_mem[0x72] = "0006b058";
    szQStr_decompander1_ping_mem[0x73] = "0006bdd3";
    szQStr_decompander1_ping_mem[0x74] = "0006cb92";
    szQStr_decompander1_ping_mem[0x75] = "0006e06a";
    szQStr_decompander1_ping_mem[0x76] = "00070927";
    szQStr_decompander1_ping_mem[0x77] = "0007180f";
    szQStr_decompander1_ping_mem[0x78] = "00071ffc";
    szQStr_decompander1_ping_mem[0x79] = "00072249";
    szQStr_decompander1_ping_mem[0x7a] = "00073316";
    szQStr_decompander1_ping_mem[0x7b] = "00074629";
    szQStr_decompander1_ping_mem[0x7c] = "0007614b";
    szQStr_decompander1_ping_mem[0x7d] = "00076a29";
    szQStr_decompander1_ping_mem[0x7e] = "00078d26";
    szQStr_decompander1_ping_mem[0x7f] = "0007b0eb";
    szQStr_decompander1_ping_mem[0x80] = "0007b24b";
    szQStr_decompander1_ping_mem[0x81] = "0007f25b";
    szQStr_decompander1_ping_mem[0x82] = "0007fb40";
    szQStr_decompander1_ping_mem[0x83] = "0007ffbc";
    szQStr_decompander1_ping_mem[0x84] = "00081360";
    szQStr_decompander1_ping_mem[0x85] = "00081e88";
    szQStr_decompander1_ping_mem[0x86] = "00082047";
    szQStr_decompander1_ping_mem[0x87] = "00082987";
    szQStr_decompander1_ping_mem[0x88] = "0008370a";
    szQStr_decompander1_ping_mem[0x89] = "0008483a";
    szQStr_decompander1_ping_mem[0x8a] = "00087aa0";
    szQStr_decompander1_ping_mem[0x8b] = "00087fd7";
    szQStr_decompander1_ping_mem[0x8c] = "00089728";
    szQStr_decompander1_ping_mem[0x8d] = "00089934";
    szQStr_decompander1_ping_mem[0x8e] = "00089f05";
    szQStr_decompander1_ping_mem[0x8f] = "0008bfbc";
    szQStr_decompander1_ping_mem[0x90] = "0008c212";
    szQStr_decompander1_ping_mem[0x91] = "0008c243";
    szQStr_decompander1_ping_mem[0x92] = "0008c36e";
    szQStr_decompander1_ping_mem[0x93] = "0008ca5b";
    szQStr_decompander1_ping_mem[0x94] = "0008e574";
    szQStr_decompander1_ping_mem[0x95] = "00090ff5";
    szQStr_decompander1_ping_mem[0x96] = "000910f2";
    szQStr_decompander1_ping_mem[0x97] = "00091a12";
    szQStr_decompander1_ping_mem[0x98] = "00091c36";
    szQStr_decompander1_ping_mem[0x99] = "00091f61";
    szQStr_decompander1_ping_mem[0x9a] = "00092b44";
    szQStr_decompander1_ping_mem[0x9b] = "00092b56";
    szQStr_decompander1_ping_mem[0x9c] = "00093fd6";
    szQStr_decompander1_ping_mem[0x9d] = "00094263";
    szQStr_decompander1_ping_mem[0x9e] = "0009458f";
    szQStr_decompander1_ping_mem[0x9f] = "00096966";
    szQStr_decompander1_ping_mem[0xa0] = "000977e5";
    szQStr_decompander1_ping_mem[0xa1] = "00099a98";
    szQStr_decompander1_ping_mem[0xa2] = "0009a5ea";
    szQStr_decompander1_ping_mem[0xa3] = "0009df24";
    szQStr_decompander1_ping_mem[0xa4] = "0009e4c6";
    szQStr_decompander1_ping_mem[0xa5] = "0009e4d8";
    szQStr_decompander1_ping_mem[0xa6] = "0009ee85";
    szQStr_decompander1_ping_mem[0xa7] = "0009f0ef";
    szQStr_decompander1_ping_mem[0xa8] = "0009fb38";
    szQStr_decompander1_ping_mem[0xa9] = "000a0fb0";
    szQStr_decompander1_ping_mem[0xaa] = "000a10dd";
    szQStr_decompander1_ping_mem[0xab] = "000a2816";
    szQStr_decompander1_ping_mem[0xac] = "000a31f9";
    szQStr_decompander1_ping_mem[0xad] = "000a4376";
    szQStr_decompander1_ping_mem[0xae] = "000a53f0";
    szQStr_decompander1_ping_mem[0xaf] = "000a5dd6";
    szQStr_decompander1_ping_mem[0xb0] = "000a67b8";
    szQStr_decompander1_ping_mem[0xb1] = "000a6a17";
    szQStr_decompander1_ping_mem[0xb2] = "000a7339";
    szQStr_decompander1_ping_mem[0xb3] = "000a76a5";
    szQStr_decompander1_ping_mem[0xb4] = "000aa3be";
    szQStr_decompander1_ping_mem[0xb5] = "000ab9a2";
    szQStr_decompander1_ping_mem[0xb6] = "000ac1e0";
    szQStr_decompander1_ping_mem[0xb7] = "000ad039";
    szQStr_decompander1_ping_mem[0xb8] = "000aefc4";
    szQStr_decompander1_ping_mem[0xb9] = "000af8bb";
    szQStr_decompander1_ping_mem[0xba] = "000afb61";
    szQStr_decompander1_ping_mem[0xbb] = "000b121a";
    szQStr_decompander1_ping_mem[0xbc] = "000b1998";
    szQStr_decompander1_ping_mem[0xbd] = "000b1cf0";
    szQStr_decompander1_ping_mem[0xbe] = "000b4ad0";
    szQStr_decompander1_ping_mem[0xbf] = "000b56ae";
    szQStr_decompander1_ping_mem[0xc0] = "000b5f44";
    szQStr_decompander1_ping_mem[0xc1] = "000b7177";
    szQStr_decompander1_ping_mem[0xc2] = "000b73d6";
    szQStr_decompander1_ping_mem[0xc3] = "000b9946";
    szQStr_decompander1_ping_mem[0xc4] = "000be753";
    szQStr_decompander1_ping_mem[0xc5] = "000bfb5f";
    szQStr_decompander1_ping_mem[0xc6] = "000bfc37";
    szQStr_decompander1_ping_mem[0xc7] = "000c0520";
    szQStr_decompander1_ping_mem[0xc8] = "000c224f";
    szQStr_decompander1_ping_mem[0xc9] = "000c50b2";
    szQStr_decompander1_ping_mem[0xca] = "000c5637";
    szQStr_decompander1_ping_mem[0xcb] = "000c56b3";
    szQStr_decompander1_ping_mem[0xcc] = "000c8643";
    szQStr_decompander1_ping_mem[0xcd] = "000c8eeb";
    szQStr_decompander1_ping_mem[0xce] = "000cce21";
    szQStr_decompander1_ping_mem[0xcf] = "000cd15e";
    szQStr_decompander1_ping_mem[0xd0] = "000cd7e4";
    szQStr_decompander1_ping_mem[0xd1] = "000d0e51";
    szQStr_decompander1_ping_mem[0xd2] = "000d2f57";
    szQStr_decompander1_ping_mem[0xd3] = "000d3aa1";
    szQStr_decompander1_ping_mem[0xd4] = "000d402f";
    szQStr_decompander1_ping_mem[0xd5] = "000d4c21";
    szQStr_decompander1_ping_mem[0xd6] = "000d5589";
    szQStr_decompander1_ping_mem[0xd7] = "000d8dba";
    szQStr_decompander1_ping_mem[0xd8] = "000dbca3";
    szQStr_decompander1_ping_mem[0xd9] = "000dbf40";
    szQStr_decompander1_ping_mem[0xda] = "000dc4a7";
    szQStr_decompander1_ping_mem[0xdb] = "000ddbd8";
    szQStr_decompander1_ping_mem[0xdc] = "000de615";
    szQStr_decompander1_ping_mem[0xdd] = "000dfec8";
    szQStr_decompander1_ping_mem[0xde] = "000e0ec5";
    szQStr_decompander1_ping_mem[0xdf] = "000e164f";
    szQStr_decompander1_ping_mem[0xe0] = "000e3320";
    szQStr_decompander1_ping_mem[0xe1] = "000e432b";
    szQStr_decompander1_ping_mem[0xe2] = "000e45cd";
    szQStr_decompander1_ping_mem[0xe3] = "000e50ee";
    szQStr_decompander1_ping_mem[0xe4] = "000e53df";
    szQStr_decompander1_ping_mem[0xe5] = "000e5527";
    szQStr_decompander1_ping_mem[0xe6] = "000e5913";
    szQStr_decompander1_ping_mem[0xe7] = "000e5f63";
    szQStr_decompander1_ping_mem[0xe8] = "000e7e77";
    szQStr_decompander1_ping_mem[0xe9] = "000eaa98";
    szQStr_decompander1_ping_mem[0xea] = "000eac5b";
    szQStr_decompander1_ping_mem[0xeb] = "000eb7be";
    szQStr_decompander1_ping_mem[0xec] = "000ebd35";
    szQStr_decompander1_ping_mem[0xed] = "000ed920";
    szQStr_decompander1_ping_mem[0xee] = "000ee140";
    szQStr_decompander1_ping_mem[0xef] = "000ee755";
    szQStr_decompander1_ping_mem[0xf0] = "000f02a8";
    szQStr_decompander1_ping_mem[0xf1] = "000f2a2d";
    szQStr_decompander1_ping_mem[0xf2] = "000f3f25";
    szQStr_decompander1_ping_mem[0xf3] = "000f4752";
    szQStr_decompander1_ping_mem[0xf4] = "000f5650";
    szQStr_decompander1_ping_mem[0xf5] = "000f5937";
    szQStr_decompander1_ping_mem[0xf6] = "000f5a0f";
    szQStr_decompander1_ping_mem[0xf7] = "000f7528";
    szQStr_decompander1_ping_mem[0xf8] = "000f964f";
    szQStr_decompander1_ping_mem[0xf9] = "000f9ac2";
    szQStr_decompander1_ping_mem[0xfa] = "000fb01f";
    szQStr_decompander1_ping_mem[0xfb] = "000fb95b";
    szQStr_decompander1_ping_mem[0xfc] = "000fc6ad";
    szQStr_decompander1_ping_mem[0xfd] = "000fe3cf";
    szQStr_decompander1_ping_mem[0xfe] = "000ff1c6";
    szQStr_decompander1_ping_mem[0xff] = "000ff82b";
    szQStr_decompander1_ping_mem[0x100] = "000ff91a";

}

void IspPPdecompander::step1()
{
    writeLine(E_ACTION_WR,"isp_config_ping.decompander0.reg_enable",ptEdit_decompander0_reg_enable->text());
    writeLine(E_ACTION_RR,"isp_config_ping.decompander0.reg_enable");

    writeLine(E_ACTION_WR,"isp_config_ping.decompander1.reg_enable","00000001");
    writeLine(E_ACTION_RR,"isp_config_ping.decompander1.reg_enable");

    writeLine(E_ACTION_WR,"isp_config_ping.decompander1.reg_enable",ptEdit_decompander1_reg_enable->text());
    writeLine(E_ACTION_RR,"isp_config_ping.decompander1.reg_enable");

    for(unsigned int i = 0;i < M_DECOMPANDER0_PING_MEN; ++i)
    {
        QString strLine;
        strLine.sprintf("decompander0_ping_mem[%x]",i);

        writeLine(E_ACTION_WR,strLine,szQStr_decompander0_ping_mem[i]);
        writeLine(E_ACTION_RR,strLine);
    }

    for(unsigned int i = 0;i < M_DECOMPANDER1_PING_MEN; ++i)
    {
        QString strLine;
        strLine.sprintf("decompander1_ping_mem[%x]",i);

        writeLine(E_ACTION_WR,strLine,szQStr_decompander1_ping_mem[i]);
        writeLine(E_ACTION_RR,strLine);
    }
}

void IspPPdecompander::clickedSlot(bool checked)
{
    if(checked)
        return;
    QString str_decompander0_reg_enable = ptEdit_decompander0_reg_enable->text();
    QString str_decompander1_reg_enable = ptEdit_decompander1_reg_enable->text();
}

void IspPPdecompander::activatedSlot_decompander0_ping(int index)
{
    ptEdit_decompander0_ping_mem->setText(szQStr_decompander0_ping_mem[index]);
}

void IspPPdecompander::textChangedSlot_decompander0_ping(const QString &text)
{
    int index = ptCb_decompander0_ping_mem->currentIndex();
    szQStr_decompander0_ping_mem[index] = text;
}

void IspPPdecompander::activatedSlot_decompander1_ping(int index)
{
    ptEdit_decompander1_ping_mem->setText(szQStr_decompander1_ping_mem[index]);
}

void IspPPdecompander::textChangedSlot_decompander1_ping(const QString &text)
{
    int index = ptCb_decompander0_ping_mem->currentIndex();
    szQStr_decompander1_ping_mem[index] = text;
}
