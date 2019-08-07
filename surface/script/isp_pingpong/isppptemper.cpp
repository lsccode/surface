#include "isppptemper.h"
#include <QGridLayout>
IspPPtemper::IspPPtemper(QWidget *parent) :
    QWidget(parent)
{

    initArray();
    QGridLayout *layoutGrid = new QGridLayout;

    // add edit
    ptLabel_format  = new QLabel("format :");
    ptEdit_format  = new QLineEdit("00000034");
    layoutGrid->addWidget(ptLabel_format ,0,0);layoutGrid->addWidget(ptEdit_format ,0,1);

    ptLabel_line_offset  = new QLabel("line_offset :");
    ptEdit_line_offset  = new QLineEdit("00000180");
    layoutGrid->addWidget(ptLabel_line_offset ,1,0);layoutGrid->addWidget(ptEdit_line_offset ,1,1);

    ptLabel_msb_bank_base_reader  = new QLabel("msb_bank_base_reader :");
    ptEdit_msb_bank_base_reader  = new QLineEdit("20000000");
    layoutGrid->addWidget(ptLabel_msb_bank_base_reader ,2,0);layoutGrid->addWidget(ptEdit_msb_bank_base_reader ,2,1);

    ptLabel_msb_bank_base_writer  = new QLabel("msb_bank_base_writer :");
    ptEdit_msb_bank_base_writer  = new QLineEdit("20000000");
    layoutGrid->addWidget(ptLabel_msb_bank_base_writer ,3,0);layoutGrid->addWidget(ptEdit_msb_bank_base_writer ,3,1);

    ptLabel_reg_frame_write_on_msb_dma  = new QLabel("reg_frame_write_on_msb_dma :");
    ptEdit_reg_frame_write_on_msb_dma  = new QLineEdit("0000000a");
    layoutGrid->addWidget(ptLabel_reg_frame_write_on_msb_dma ,4,0);layoutGrid->addWidget(ptEdit_reg_frame_write_on_msb_dma ,4,1);

    ptLabel_reg_msb_reader_axi_id_value  = new QLabel("reg_msb_reader_axi_id_value :");
    ptEdit_reg_msb_reader_axi_id_value  = new QLineEdit("0f007edb");
    layoutGrid->addWidget(ptLabel_reg_msb_reader_axi_id_value ,5,0);layoutGrid->addWidget(ptEdit_reg_msb_reader_axi_id_value ,5,1);

    ptLabel_reg_msb_writer_axi_id_value  = new QLabel("reg_msb_writer_axi_id_value :");
    ptEdit_reg_msb_writer_axi_id_value  = new QLineEdit("0f007e1b");
    layoutGrid->addWidget(ptLabel_reg_msb_writer_axi_id_value ,6,0);layoutGrid->addWidget(ptEdit_reg_msb_writer_axi_id_value ,6,1);

    ptLabel_black_level  = new QLabel("black_level :");
    ptEdit_black_level  = new QLineEdit("0000c19d");
    layoutGrid->addWidget(ptLabel_black_level ,7,0);layoutGrid->addWidget(ptEdit_black_level ,7,1);

    ptLabel_weight_lut  = new QLabel("weight_lut :");
    ptEdit_weight_lut  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_weight_lut ,8,0);layoutGrid->addWidget(ptEdit_weight_lut ,8,1);

    ptLabel_reg_noise_level_0  = new QLabel("reg_noise_level_0 :");
    ptEdit_reg_noise_level_0  = new QLineEdit("08050505");
    layoutGrid->addWidget(ptLabel_reg_noise_level_0 ,9,0);layoutGrid->addWidget(ptEdit_reg_noise_level_0 ,9,1);

    ptLabel_reg_use_lut  = new QLabel("reg_use_lut :");
    ptEdit_reg_use_lut  = new QLineEdit("00000801");
    layoutGrid->addWidget(ptLabel_reg_use_lut ,10,0);layoutGrid->addWidget(ptEdit_reg_use_lut ,10,1);

    ptLabel_thresh1  = new QLabel("thresh1 :");
    ptEdit_thresh1  = new QLineEdit("00001023");
    layoutGrid->addWidget(ptLabel_thresh1 ,11,0);layoutGrid->addWidget(ptEdit_thresh1 ,11,1);

    ptLabel_thresh2  = new QLabel("thresh2 :");
    ptEdit_thresh2  = new QLineEdit("000019c6");
    layoutGrid->addWidget(ptLabel_thresh2 ,12,0);layoutGrid->addWidget(ptEdit_thresh2 ,12,1);

    ptLabel_thresh3  = new QLabel("thresh3 :");
    ptEdit_thresh3  = new QLineEdit("00008b5a");
    layoutGrid->addWidget(ptLabel_thresh3 ,13,0);layoutGrid->addWidget(ptEdit_thresh3 ,13,1);

    ptLabel_reg_enable  = new QLabel("reg_enable :");
    ptEdit_reg_enable  = new QLineEdit("00000003");
    layoutGrid->addWidget(ptLabel_reg_enable ,14,0);layoutGrid->addWidget(ptEdit_reg_enable ,14,1);

    ptLabel_reg_recursion_limit  = new QLabel("reg_recursion_limit :");
    ptEdit_reg_recursion_limit  = new QLineEdit("0000a406");
    layoutGrid->addWidget(ptLabel_reg_recursion_limit ,15,0);layoutGrid->addWidget(ptEdit_reg_recursion_limit ,15,1);

    ptCb_temper_noise_profile_lut_weight_lut  = new QComboBox;
    ptEdit_temper_noise_profile_lut_weight_lut = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_temper_noise_profile_lut_weight_lut,16,0);layoutGrid->addWidget(ptEdit_temper_noise_profile_lut_weight_lut,16,1);
    for(unsigned int i = 0;i < M_TEMPER_NOISE_PROFILE_LUT_WEIGHT_LUT_NUMBER; ++i)
    {
        QString str;
        str.sprintf("temper_noise_profile_lut_weight_lut[%x]",i);
        ptCb_temper_noise_profile_lut_weight_lut->addItem(str);
//        szQStr_temper_noise_profile_lut_weight_lut[i].sprintf("%x",i);
    }
    ptEdit_temper_noise_profile_lut_weight_lut->setText(szQStr_temper_noise_profile_lut_weight_lut[ptCb_temper_noise_profile_lut_weight_lut->currentIndex()]);

//    ptPBtn = new QPushButton("确定");
//    layoutGrid->addWidget(ptPBtn,40,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

//    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

    connect(ptCb_temper_noise_profile_lut_weight_lut,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_temper_noise_profile_lut_weight_lut(int)));
    connect(ptEdit_temper_noise_profile_lut_weight_lut,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_temper_noise_profile_lut_weight_lut(const QString)));

    setLayout(mainLayout);
}

void IspPPtemper::step1()
{
    writeLine(E_ACTION_WR,"isp_config_ping.temper_dma.reg_msb_writer_axi_id_value","0f007e10");
    writeLine(E_ACTION_RR,"isp_config_ping.temper_dma.reg_msb_writer_axi_id_value");

    writeLine(E_ACTION_WR,"isp_config_ping.temper_dma.reg_msb_writer_axi_id_value",ptEdit_reg_msb_writer_axi_id_value->text());
    writeLine(E_ACTION_RR,"isp_config_ping.temper_dma.reg_msb_writer_axi_id_value");

    writeLine(E_ACTION_WR,"isp_config_ping.temper_dma.reg_msb_reader_axi_id_value","0f007ed0");
    writeLine(E_ACTION_RR,"isp_config_ping.temper_dma.reg_msb_reader_axi_id_value");

    writeLine(E_ACTION_WR,"isp_config_ping.temper_dma.reg_msb_reader_axi_id_value",ptEdit_reg_msb_reader_axi_id_value->text());
    writeLine(E_ACTION_RR,"isp_config_ping.temper_dma.reg_msb_reader_axi_id_value");

    writeLine(E_ACTION_WR,"isp_config_pong.temper_dma.reg_msb_writer_axi_id_value","0f007e10");
    writeLine(E_ACTION_RR,"isp_config_pong.temper_dma.reg_msb_writer_axi_id_value");

    writeLine(E_ACTION_WR,"isp_config_pong.temper_dma.reg_msb_writer_axi_id_value",ptEdit_reg_msb_writer_axi_id_value->text());
    writeLine(E_ACTION_RR,"isp_config_pong.temper_dma.reg_msb_writer_axi_id_value");

    writeLine(E_ACTION_WR,"isp_config_pong.temper_dma.reg_msb_reader_axi_id_value","0f007ed0");
    writeLine(E_ACTION_RR,"isp_config_pong.temper_dma.reg_msb_reader_axi_id_value");

    writeLine(E_ACTION_WR,"isp_config_pong.temper_dma.reg_msb_reader_axi_id_value",ptEdit_reg_msb_reader_axi_id_value->text());
    writeLine(E_ACTION_RR,"isp_config_pong.temper_dma.reg_msb_reader_axi_id_value");


}

void IspPPtemper::step2()
{
    writeLine(E_ACTION_WR,"isp_config_ping.temper.reg_enable","00000002");
    writeLine(E_ACTION_RR,"isp_config_ping.temper.reg_enable");

    writeLine(E_ACTION_WR,"isp_config_ping.temper.reg_recursion_limit","00000206");
    writeLine(E_ACTION_RR,"isp_config_ping.temper.reg_recursion_limit");

    writeLine(E_ACTION_WR,"isp_config_ping.temper.reg_recursion_limit",ptEdit_reg_recursion_limit->text());
    writeLine(E_ACTION_RR,"isp_config_ping.temper.reg_recursion_limit");

    writeLine(E_ACTION_WR,"isp_config_ping.temper_noise_profile.reg_use_lut",ptEdit_reg_use_lut->text());
    writeLine(E_ACTION_RR,"isp_config_ping.temper_noise_profile.reg_use_lut");

    writeLine(E_ACTION_WR,"isp_config_ping.temper_noise_profile.black_level",ptEdit_black_level->text());
    writeLine(E_ACTION_RR,"isp_config_ping.temper_noise_profile.black_level");

    writeLine(E_ACTION_WR,"isp_config_ping.temper_noise_profile.thresh1",ptEdit_thresh1->text());
    writeLine(E_ACTION_RR,"isp_config_ping.temper_noise_profile.thresh1");

    writeLine(E_ACTION_WR,"isp_config_ping.temper_noise_profile.thresh2",ptEdit_thresh2->text());
    writeLine(E_ACTION_RR,"isp_config_ping.temper_noise_profile.thresh2");

    writeLine(E_ACTION_WR,"isp_config_ping.temper_noise_profile.thresh3",ptEdit_thresh3->text());
    writeLine(E_ACTION_RR,"isp_config_ping.temper_noise_profile.thresh3");

    writeLine(E_ACTION_WR,"isp_config_ping.temper_noise_profile.reg_noise_level_0","00000005");
    writeLine(E_ACTION_RR,"isp_config_ping.temper_noise_profile.reg_noise_level_0");

    writeLine(E_ACTION_WR,"isp_config_ping.temper_noise_profile.reg_noise_level_0","00000505");
    writeLine(E_ACTION_RR,"isp_config_ping.temper_noise_profile.reg_noise_level_0");

    writeLine(E_ACTION_WR,"isp_config_ping.temper_noise_profile.reg_noise_level_0","00050505");
    writeLine(E_ACTION_RR,"isp_config_ping.temper_noise_profile.reg_noise_level_0");

    writeLine(E_ACTION_WR,"isp_config_ping.temper_noise_profile.reg_noise_level_0",ptEdit_reg_noise_level_0->text());
    writeLine(E_ACTION_RR,"isp_config_ping.temper_noise_profile.reg_noise_level_0");

    for(unsigned int i = 0;i < M_TEMPER_NOISE_PROFILE_LUT_WEIGHT_LUT_NUMBER; ++i)
    {
        QString strLine;
        strLine.sprintf("isp_config_ping.temper_noise_profile_lut.weight_lut[%x]",i);

        writeLine(E_ACTION_WR,strLine,szQStr_temper_noise_profile_lut_weight_lut[i]);
        writeLine(E_ACTION_RR,strLine);
    }

    writeLine(E_ACTION_WR,"isp_config_ping.temper_dma.reg_frame_write_on_msb_dma","0000000e");
    writeLine(E_ACTION_RR,"isp_config_ping.temper_dma.reg_frame_write_on_msb_dma");

    writeLine(E_ACTION_WR,"isp_config_ping.temper_dma.reg_frame_write_on_msb_dma",ptEdit_reg_frame_write_on_msb_dma->text());
    writeLine(E_ACTION_RR,"isp_config_ping.temper_dma.reg_frame_write_on_msb_dma");

    writeLine(E_ACTION_WR,"isp_config_ping.temper_dma.format",ptEdit_format->text());
    writeLine(E_ACTION_RR,"isp_config_ping.temper_dma.format");

    writeLine(E_ACTION_WR,"isp_config_ping.temper_dma.msb_bank_base_writer",ptEdit_msb_bank_base_writer->text());
    writeLine(E_ACTION_RR,"isp_config_ping.temper_dma.msb_bank_base_writer");

    writeLine(E_ACTION_WR,"isp_config_ping.temper_dma.msb_bank_base_reader",ptEdit_msb_bank_base_reader->text());
    writeLine(E_ACTION_RR,"isp_config_ping.temper_dma.msb_bank_base_reader");

    writeLine(E_ACTION_WR,"isp_config_ping.temper_dma.line_offset",ptEdit_line_offset->text());
    writeLine(E_ACTION_RR,"isp_config_ping.temper_dma.line_offset");
}

void IspPPtemper::step3()
{
    writeLine(E_ACTION_WR,"isp_config_ping.temper.reg_enable",ptEdit_reg_enable->text());
    writeLine(E_ACTION_RR,"isp_config_ping.temper.reg_enable");
}

void IspPPtemper::initArray()
{
    szQStr_temper_noise_profile_lut_weight_lut[0x0] = "00000023";
    szQStr_temper_noise_profile_lut_weight_lut[0x1] = "000000fa";
    szQStr_temper_noise_profile_lut_weight_lut[0x2] = "000000c1";
    szQStr_temper_noise_profile_lut_weight_lut[0x3] = "00000044";
    szQStr_temper_noise_profile_lut_weight_lut[0x4] = "00000022";
    szQStr_temper_noise_profile_lut_weight_lut[0x5] = "000000d6";
    szQStr_temper_noise_profile_lut_weight_lut[0x6] = "000000ce";
    szQStr_temper_noise_profile_lut_weight_lut[0x7] = "0000006c";
    szQStr_temper_noise_profile_lut_weight_lut[0x8] = "00000064";
    szQStr_temper_noise_profile_lut_weight_lut[0x9] = "000000a5";
    szQStr_temper_noise_profile_lut_weight_lut[0xa] = "0000007b";
    szQStr_temper_noise_profile_lut_weight_lut[0xb] = "00000015";
    szQStr_temper_noise_profile_lut_weight_lut[0xc] = "0000001d";
    szQStr_temper_noise_profile_lut_weight_lut[0xd] = "00000014";
    szQStr_temper_noise_profile_lut_weight_lut[0xe] = "000000ad";
    szQStr_temper_noise_profile_lut_weight_lut[0xf] = "000000a0";
    szQStr_temper_noise_profile_lut_weight_lut[0x10] = "00000024";
    szQStr_temper_noise_profile_lut_weight_lut[0x11] = "00000052";
    szQStr_temper_noise_profile_lut_weight_lut[0x12] = "0000001f";
    szQStr_temper_noise_profile_lut_weight_lut[0x13] = "0000001b";
    szQStr_temper_noise_profile_lut_weight_lut[0x14] = "000000fe";
    szQStr_temper_noise_profile_lut_weight_lut[0x15] = "0000009c";
    szQStr_temper_noise_profile_lut_weight_lut[0x16] = "00000053";
    szQStr_temper_noise_profile_lut_weight_lut[0x17] = "000000de";
    szQStr_temper_noise_profile_lut_weight_lut[0x18] = "00000044";
    szQStr_temper_noise_profile_lut_weight_lut[0x19] = "000000a9";
    szQStr_temper_noise_profile_lut_weight_lut[0x1a] = "00000026";
    szQStr_temper_noise_profile_lut_weight_lut[0x1b] = "00000044";
    szQStr_temper_noise_profile_lut_weight_lut[0x1c] = "00000032";
    szQStr_temper_noise_profile_lut_weight_lut[0x1d] = "00000033";
    szQStr_temper_noise_profile_lut_weight_lut[0x1e] = "000000d5";
    szQStr_temper_noise_profile_lut_weight_lut[0x1f] = "000000d4";
    szQStr_temper_noise_profile_lut_weight_lut[0x20] = "000000cd";
    szQStr_temper_noise_profile_lut_weight_lut[0x21] = "0000008b";
    szQStr_temper_noise_profile_lut_weight_lut[0x22] = "000000ee";
    szQStr_temper_noise_profile_lut_weight_lut[0x23] = "0000002d";
    szQStr_temper_noise_profile_lut_weight_lut[0x24] = "00000058";
    szQStr_temper_noise_profile_lut_weight_lut[0x25] = "000000bf";
    szQStr_temper_noise_profile_lut_weight_lut[0x26] = "00000067";
    szQStr_temper_noise_profile_lut_weight_lut[0x27] = "000000ff";
    szQStr_temper_noise_profile_lut_weight_lut[0x28] = "0000007e";
    szQStr_temper_noise_profile_lut_weight_lut[0x29] = "00000005";
    szQStr_temper_noise_profile_lut_weight_lut[0x2a] = "00000090";
    szQStr_temper_noise_profile_lut_weight_lut[0x2b] = "0000002b";
    szQStr_temper_noise_profile_lut_weight_lut[0x2c] = "000000b8";
    szQStr_temper_noise_profile_lut_weight_lut[0x2d] = "0000001f";
    szQStr_temper_noise_profile_lut_weight_lut[0x2e] = "00000092";
    szQStr_temper_noise_profile_lut_weight_lut[0x2f] = "000000dd";
    szQStr_temper_noise_profile_lut_weight_lut[0x30] = "00000078";
    szQStr_temper_noise_profile_lut_weight_lut[0x31] = "0000007f";
    szQStr_temper_noise_profile_lut_weight_lut[0x32] = "00000058";
    szQStr_temper_noise_profile_lut_weight_lut[0x33] = "00000035";
    szQStr_temper_noise_profile_lut_weight_lut[0x34] = "00000014";
    szQStr_temper_noise_profile_lut_weight_lut[0x35] = "00000053";
    szQStr_temper_noise_profile_lut_weight_lut[0x36] = "0000002d";
    szQStr_temper_noise_profile_lut_weight_lut[0x37] = "0000005e";
    szQStr_temper_noise_profile_lut_weight_lut[0x38] = "000000d0";
    szQStr_temper_noise_profile_lut_weight_lut[0x39] = "0000006e";
    szQStr_temper_noise_profile_lut_weight_lut[0x3a] = "0000008b";
    szQStr_temper_noise_profile_lut_weight_lut[0x3b] = "00000032";
    szQStr_temper_noise_profile_lut_weight_lut[0x3c] = "0000008a";
    szQStr_temper_noise_profile_lut_weight_lut[0x3d] = "0000003b";
    szQStr_temper_noise_profile_lut_weight_lut[0x3e] = "0000007d";
    szQStr_temper_noise_profile_lut_weight_lut[0x3f] = "000000c6";
    szQStr_temper_noise_profile_lut_weight_lut[0x40] = "00000011";
    szQStr_temper_noise_profile_lut_weight_lut[0x41] = "000000c1";
    szQStr_temper_noise_profile_lut_weight_lut[0x42] = "00000052";
    szQStr_temper_noise_profile_lut_weight_lut[0x43] = "00000024";
    szQStr_temper_noise_profile_lut_weight_lut[0x44] = "00000006";
    szQStr_temper_noise_profile_lut_weight_lut[0x45] = "000000d9";
    szQStr_temper_noise_profile_lut_weight_lut[0x46] = "0000005e";
    szQStr_temper_noise_profile_lut_weight_lut[0x47] = "000000d5";
    szQStr_temper_noise_profile_lut_weight_lut[0x48] = "00000056";
    szQStr_temper_noise_profile_lut_weight_lut[0x49] = "00000023";
    szQStr_temper_noise_profile_lut_weight_lut[0x4a] = "00000017";
    szQStr_temper_noise_profile_lut_weight_lut[0x4b] = "0000003d";
    szQStr_temper_noise_profile_lut_weight_lut[0x4c] = "000000cf";
    szQStr_temper_noise_profile_lut_weight_lut[0x4d] = "000000b7";
    szQStr_temper_noise_profile_lut_weight_lut[0x4e] = "000000ba";
    szQStr_temper_noise_profile_lut_weight_lut[0x4f] = "00000020";
    szQStr_temper_noise_profile_lut_weight_lut[0x50] = "0000009e";
    szQStr_temper_noise_profile_lut_weight_lut[0x51] = "000000f6";
    szQStr_temper_noise_profile_lut_weight_lut[0x52] = "00000028";
    szQStr_temper_noise_profile_lut_weight_lut[0x53] = "0000006f";
    szQStr_temper_noise_profile_lut_weight_lut[0x54] = "00000022";
    szQStr_temper_noise_profile_lut_weight_lut[0x55] = "00000023";
    szQStr_temper_noise_profile_lut_weight_lut[0x56] = "00000048";
    szQStr_temper_noise_profile_lut_weight_lut[0x57] = "00000075";
    szQStr_temper_noise_profile_lut_weight_lut[0x58] = "00000057";
    szQStr_temper_noise_profile_lut_weight_lut[0x59] = "000000b7";
    szQStr_temper_noise_profile_lut_weight_lut[0x5a] = "000000cb";
    szQStr_temper_noise_profile_lut_weight_lut[0x5b] = "0000008c";
    szQStr_temper_noise_profile_lut_weight_lut[0x5c] = "00000029";
    szQStr_temper_noise_profile_lut_weight_lut[0x5d] = "000000b0";
    szQStr_temper_noise_profile_lut_weight_lut[0x5e] = "00000003";
    szQStr_temper_noise_profile_lut_weight_lut[0x5f] = "00000057";
    szQStr_temper_noise_profile_lut_weight_lut[0x60] = "000000bb";
    szQStr_temper_noise_profile_lut_weight_lut[0x61] = "00000023";
    szQStr_temper_noise_profile_lut_weight_lut[0x62] = "0000009c";
    szQStr_temper_noise_profile_lut_weight_lut[0x63] = "000000e4";
    szQStr_temper_noise_profile_lut_weight_lut[0x64] = "00000076";
    szQStr_temper_noise_profile_lut_weight_lut[0x65] = "000000dc";
    szQStr_temper_noise_profile_lut_weight_lut[0x66] = "00000068";
    szQStr_temper_noise_profile_lut_weight_lut[0x67] = "00000029";
    szQStr_temper_noise_profile_lut_weight_lut[0x68] = "0000004a";
    szQStr_temper_noise_profile_lut_weight_lut[0x69] = "000000d1";
    szQStr_temper_noise_profile_lut_weight_lut[0x6a] = "00000038";
    szQStr_temper_noise_profile_lut_weight_lut[0x6b] = "000000db";
    szQStr_temper_noise_profile_lut_weight_lut[0x6c] = "00000055";
    szQStr_temper_noise_profile_lut_weight_lut[0x6d] = "00000070";
    szQStr_temper_noise_profile_lut_weight_lut[0x6e] = "00000044";
    szQStr_temper_noise_profile_lut_weight_lut[0x6f] = "00000003";
    szQStr_temper_noise_profile_lut_weight_lut[0x70] = "000000bf";
    szQStr_temper_noise_profile_lut_weight_lut[0x71] = "0000004a";
    szQStr_temper_noise_profile_lut_weight_lut[0x72] = "000000e7";
    szQStr_temper_noise_profile_lut_weight_lut[0x73] = "000000cd";
    szQStr_temper_noise_profile_lut_weight_lut[0x74] = "00000079";
    szQStr_temper_noise_profile_lut_weight_lut[0x75] = "0000009e";
    szQStr_temper_noise_profile_lut_weight_lut[0x76] = "0000000f";
    szQStr_temper_noise_profile_lut_weight_lut[0x77] = "000000b3";
    szQStr_temper_noise_profile_lut_weight_lut[0x78] = "00000049";
    szQStr_temper_noise_profile_lut_weight_lut[0x79] = "00000083";
    szQStr_temper_noise_profile_lut_weight_lut[0x7a] = "00000032";
    szQStr_temper_noise_profile_lut_weight_lut[0x7b] = "000000db";
    szQStr_temper_noise_profile_lut_weight_lut[0x7c] = "00000021";
    szQStr_temper_noise_profile_lut_weight_lut[0x7d] = "0000002a";
    szQStr_temper_noise_profile_lut_weight_lut[0x7e] = "000000e7";
    szQStr_temper_noise_profile_lut_weight_lut[0x7f] = "000000f6";
}

void IspPPtemper::clickedSlot(bool checked)
{
    QString str_format = ptEdit_format->text();
    QString str_line_offset = ptEdit_line_offset->text();
    QString str_msb_bank_base_reader = ptEdit_msb_bank_base_reader->text();
    QString str_msb_bank_base_writer = ptEdit_msb_bank_base_writer->text();
    QString str_reg_frame_write_on_msb_dma = ptEdit_reg_frame_write_on_msb_dma->text();
    QString str_reg_msb_reader_axi_id_value = ptEdit_reg_msb_reader_axi_id_value->text();
    QString str_reg_msb_writer_axi_id_value = ptEdit_reg_msb_writer_axi_id_value->text();
    QString str_black_level = ptEdit_black_level->text();
    QString str_weight_lut = ptEdit_weight_lut->text();
    QString str_reg_noise_level_0 = ptEdit_reg_noise_level_0->text();
    QString str_reg_use_lut = ptEdit_reg_use_lut->text();
    QString str_thresh1 = ptEdit_thresh1->text();
    QString str_thresh2 = ptEdit_thresh2->text();
    QString str_thresh3 = ptEdit_thresh3->text();
    QString str_reg_enable = ptEdit_reg_enable->text();
}

void IspPPtemper::activatedSlot_temper_noise_profile_lut_weight_lut(int index)
{
    ptEdit_temper_noise_profile_lut_weight_lut->setText(szQStr_temper_noise_profile_lut_weight_lut[index]);
}

void IspPPtemper::textChangedSlot_temper_noise_profile_lut_weight_lut(const QString &text)
{
    int index = ptCb_temper_noise_profile_lut_weight_lut->currentIndex();
    szQStr_temper_noise_profile_lut_weight_lut[index] = text;
}
