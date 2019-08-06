#include "ispppraw_frontend.h"
#include <QGridLayout>
IspPPraw_frontend::IspPPraw_frontend(QWidget *parent) :
    QWidget(parent)
{
    init_array();

    QGridLayout *layoutGrid = new QGridLayout;

    // add edit
    ptLabel_exp_thresh  = new QLabel("exp_thresh :");
    ptEdit_exp_thresh  = new QLineEdit("0000fed4");
    layoutGrid->addWidget(ptLabel_exp_thresh ,0,0);layoutGrid->addWidget(ptEdit_exp_thresh ,0,1);

//    ptLabel_weight_lut  = new QLabel("weight_lut :");
//    ptEdit_weight_lut  = new QLineEdit("000000001");
//    layoutGrid->addWidget(ptLabel_weight_lut ,1,0);layoutGrid->addWidget(ptEdit_weight_lut ,1,1);

    ptLabel_reg_short_ratio  = new QLabel("reg_short_ratio :");
    ptEdit_reg_short_ratio  = new QLineEdit("0000021e");
    layoutGrid->addWidget(ptLabel_reg_short_ratio ,2,0);layoutGrid->addWidget(ptEdit_reg_short_ratio ,2,1);

    ptLabel_reg_dpdev_threshold  = new QLabel("reg_dpdev_threshold :");
    ptEdit_reg_dpdev_threshold  = new QLineEdit("008a02c0");
    layoutGrid->addWidget(ptLabel_reg_dpdev_threshold ,3,0);layoutGrid->addWidget(ptEdit_reg_dpdev_threshold ,3,1);

    ptLabel_reg_dp_slope  = new QLabel("reg_dp_slope :");
    ptEdit_reg_dp_slope  = new QLineEdit("004001db");
    layoutGrid->addWidget(ptLabel_reg_dp_slope ,4,0);layoutGrid->addWidget(ptEdit_reg_dp_slope ,4,1);

    ptLabel_reg_ge_slope  = new QLabel("reg_ge_slope :");
    ptEdit_reg_ge_slope  = new QLineEdit("008800de");
    layoutGrid->addWidget(ptLabel_reg_ge_slope ,5,0);layoutGrid->addWidget(ptEdit_reg_ge_slope ,5,1);

    ptLabel_reg_ge_strength  = new QLabel("reg_ge_strength :");
    ptEdit_reg_ge_strength  = new QLineEdit("045c0029");
    layoutGrid->addWidget(ptLabel_reg_ge_strength ,6,0);layoutGrid->addWidget(ptEdit_reg_ge_strength ,6,1);

    ptLabel_reg_line_thresh  = new QLabel("reg_line_thresh :");
    ptEdit_reg_line_thresh  = new QLineEdit("004000ea");
    layoutGrid->addWidget(ptLabel_reg_line_thresh ,7,0);layoutGrid->addWidget(ptEdit_reg_line_thresh ,7,1);

    ptLabel_reg_thresh_short  = new QLabel("reg_thresh_short :");
    ptEdit_reg_thresh_short  = new QLineEdit("00000c09");
    layoutGrid->addWidget(ptLabel_reg_thresh_short ,8,0);layoutGrid->addWidget(ptEdit_reg_thresh_short ,8,1);

    ptCb_raw_frontend_np_lut_weight_lut  = new QComboBox;
    ptEdit_raw_frontend_np_lut_weight_lut = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_raw_frontend_np_lut_weight_lut,9,0);layoutGrid->addWidget(ptEdit_raw_frontend_np_lut_weight_lut,9,1);
    for(unsigned int i = 0;i < M_RAW_FRONTED_NP_LUT_WEIGHT_LUT_NUMBER; ++i)
    {
        QString str;
        str.sprintf("raw_frontend_np_lut.weight_lut[%x]",i);
        ptCb_raw_frontend_np_lut_weight_lut->addItem(str);
//        szQStr_raw_frontend_np_lut_weight_lut[i].sprintf("%x",i);
    }
    ptEdit_raw_frontend_np_lut_weight_lut->setText(szQStr_raw_frontend_np_lut_weight_lut[ptCb_raw_frontend_np_lut_weight_lut->currentIndex()]);

//    ptPBtn = new QPushButton("确定");
//    layoutGrid->addWidget(ptPBtn,40,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

//    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

    connect(ptCb_raw_frontend_np_lut_weight_lut,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_raw_frontend_np_lut_weight_lut(int)));
    connect(ptEdit_raw_frontend_np_lut_weight_lut,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_raw_frontend_np_lut_weight_lut(const QString)));

    setLayout(mainLayout);
}

void IspPPraw_frontend::init_array()
{
    szQStr_raw_frontend_np_lut_weight_lut[0x7c] = "00000057";
    szQStr_raw_frontend_np_lut_weight_lut[0x7d] = "00000058";
    szQStr_raw_frontend_np_lut_weight_lut[0x7e] = "00000059";
    szQStr_raw_frontend_np_lut_weight_lut[0x7f] = "00000052";
    szQStr_raw_frontend_np_lut_weight_lut[0x78] = "00000059";
    szQStr_raw_frontend_np_lut_weight_lut[0x79] = "0000005a";
    szQStr_raw_frontend_np_lut_weight_lut[0x7a] = "00000057";
    szQStr_raw_frontend_np_lut_weight_lut[0x7b] = "00000050";
    szQStr_raw_frontend_np_lut_weight_lut[0x74] = "00000055";
    szQStr_raw_frontend_np_lut_weight_lut[0x75] = "0000005a";
    szQStr_raw_frontend_np_lut_weight_lut[0x76] = "00000058";
    szQStr_raw_frontend_np_lut_weight_lut[0x77] = "00000050";
    szQStr_raw_frontend_np_lut_weight_lut[0x70] = "00000056";
    szQStr_raw_frontend_np_lut_weight_lut[0x71] = "00000058";
    szQStr_raw_frontend_np_lut_weight_lut[0x72] = "00000052";
    szQStr_raw_frontend_np_lut_weight_lut[0x73] = "00000054";
    szQStr_raw_frontend_np_lut_weight_lut[0x6c] = "00000059";
    szQStr_raw_frontend_np_lut_weight_lut[0x6d] = "00000054";
    szQStr_raw_frontend_np_lut_weight_lut[0x6e] = "00000056";
    szQStr_raw_frontend_np_lut_weight_lut[0x6f] = "00000052";
    szQStr_raw_frontend_np_lut_weight_lut[0x68] = "00000050";
    szQStr_raw_frontend_np_lut_weight_lut[0x69] = "00000057";
    szQStr_raw_frontend_np_lut_weight_lut[0x6a] = "0000005a";
    szQStr_raw_frontend_np_lut_weight_lut[0x6b] = "00000052";
    szQStr_raw_frontend_np_lut_weight_lut[0x64] = "00000050";
    szQStr_raw_frontend_np_lut_weight_lut[0x65] = "00000054";
    szQStr_raw_frontend_np_lut_weight_lut[0x66] = "00000056";
    szQStr_raw_frontend_np_lut_weight_lut[0x67] = "00000051";
    szQStr_raw_frontend_np_lut_weight_lut[0x60] = "00000057";
    szQStr_raw_frontend_np_lut_weight_lut[0x61] = "00000055";
    szQStr_raw_frontend_np_lut_weight_lut[0x62] = "0000005a";
    szQStr_raw_frontend_np_lut_weight_lut[0x63] = "00000055";
    szQStr_raw_frontend_np_lut_weight_lut[0x5c] = "00000056";
    szQStr_raw_frontend_np_lut_weight_lut[0x5d] = "00000059";
    szQStr_raw_frontend_np_lut_weight_lut[0x5e] = "00000051";
    szQStr_raw_frontend_np_lut_weight_lut[0x5f] = "00000054";
    szQStr_raw_frontend_np_lut_weight_lut[0x58] = "00000056";
    szQStr_raw_frontend_np_lut_weight_lut[0x59] = "00000057";
    szQStr_raw_frontend_np_lut_weight_lut[0x5a] = "00000055";
    szQStr_raw_frontend_np_lut_weight_lut[0x5b] = "00000055";
    szQStr_raw_frontend_np_lut_weight_lut[0x54] = "00000053";
    szQStr_raw_frontend_np_lut_weight_lut[0x55] = "00000058";
    szQStr_raw_frontend_np_lut_weight_lut[0x56] = "00000053";
    szQStr_raw_frontend_np_lut_weight_lut[0x57] = "00000055";
    szQStr_raw_frontend_np_lut_weight_lut[0x50] = "00000059";
    szQStr_raw_frontend_np_lut_weight_lut[0x51] = "00000055";
    szQStr_raw_frontend_np_lut_weight_lut[0x52] = "00000057";
    szQStr_raw_frontend_np_lut_weight_lut[0x53] = "00000057";
    szQStr_raw_frontend_np_lut_weight_lut[0x4c] = "0000005a";
    szQStr_raw_frontend_np_lut_weight_lut[0x4d] = "00000051";
    szQStr_raw_frontend_np_lut_weight_lut[0x4e] = "00000050";
    szQStr_raw_frontend_np_lut_weight_lut[0x4f] = "00000052";
    szQStr_raw_frontend_np_lut_weight_lut[0x48] = "00000056";
    szQStr_raw_frontend_np_lut_weight_lut[0x49] = "00000058";
    szQStr_raw_frontend_np_lut_weight_lut[0x4a] = "00000053";
    szQStr_raw_frontend_np_lut_weight_lut[0x4b] = "00000050";
    szQStr_raw_frontend_np_lut_weight_lut[0x44] = "00000050";
    szQStr_raw_frontend_np_lut_weight_lut[0x45] = "00000055";
    szQStr_raw_frontend_np_lut_weight_lut[0x46] = "00000057";
    szQStr_raw_frontend_np_lut_weight_lut[0x47] = "00000050";
    szQStr_raw_frontend_np_lut_weight_lut[0x40] = "00000051";
    szQStr_raw_frontend_np_lut_weight_lut[0x41] = "00000058";
    szQStr_raw_frontend_np_lut_weight_lut[0x42] = "00000057";
    szQStr_raw_frontend_np_lut_weight_lut[0x43] = "00000053";
    szQStr_raw_frontend_np_lut_weight_lut[0x3c] = "00000050";
    szQStr_raw_frontend_np_lut_weight_lut[0x3d] = "00000055";
    szQStr_raw_frontend_np_lut_weight_lut[0x3e] = "00000058";
    szQStr_raw_frontend_np_lut_weight_lut[0x3f] = "00000051";
    szQStr_raw_frontend_np_lut_weight_lut[0x38] = "00000057";
    szQStr_raw_frontend_np_lut_weight_lut[0x39] = "00000059";
    szQStr_raw_frontend_np_lut_weight_lut[0x3a] = "00000054";
    szQStr_raw_frontend_np_lut_weight_lut[0x3b] = "00000054";
    szQStr_raw_frontend_np_lut_weight_lut[0x34] = "00000053";
    szQStr_raw_frontend_np_lut_weight_lut[0x35] = "00000056";
    szQStr_raw_frontend_np_lut_weight_lut[0x36] = "00000051";
    szQStr_raw_frontend_np_lut_weight_lut[0x37] = "00000051";
    szQStr_raw_frontend_np_lut_weight_lut[0x30] = "0000005a";
    szQStr_raw_frontend_np_lut_weight_lut[0x31] = "00000053";
    szQStr_raw_frontend_np_lut_weight_lut[0x32] = "00000057";
    szQStr_raw_frontend_np_lut_weight_lut[0x33] = "00000050";
    szQStr_raw_frontend_np_lut_weight_lut[0x2c] = "00000059";
    szQStr_raw_frontend_np_lut_weight_lut[0x2d] = "0000005a";
    szQStr_raw_frontend_np_lut_weight_lut[0x2e] = "00000051";
    szQStr_raw_frontend_np_lut_weight_lut[0x2f] = "00000051";
    szQStr_raw_frontend_np_lut_weight_lut[0x28] = "0000005a";
    szQStr_raw_frontend_np_lut_weight_lut[0x29] = "0000005a";
    szQStr_raw_frontend_np_lut_weight_lut[0x2a] = "00000058";
    szQStr_raw_frontend_np_lut_weight_lut[0x2b] = "00000052";
    szQStr_raw_frontend_np_lut_weight_lut[0x24] = "00000053";
    szQStr_raw_frontend_np_lut_weight_lut[0x25] = "00000050";
    szQStr_raw_frontend_np_lut_weight_lut[0x26] = "00000050";
    szQStr_raw_frontend_np_lut_weight_lut[0x27] = "00000054";
    szQStr_raw_frontend_np_lut_weight_lut[0x20] = "00000054";
    szQStr_raw_frontend_np_lut_weight_lut[0x21] = "00000058";
    szQStr_raw_frontend_np_lut_weight_lut[0x22] = "00000057";
    szQStr_raw_frontend_np_lut_weight_lut[0x23] = "00000059";
    szQStr_raw_frontend_np_lut_weight_lut[0x1c] = "00000057";
    szQStr_raw_frontend_np_lut_weight_lut[0x1d] = "00000051";
    szQStr_raw_frontend_np_lut_weight_lut[0x1e] = "00000051";
    szQStr_raw_frontend_np_lut_weight_lut[0x1f] = "00000050";
    szQStr_raw_frontend_np_lut_weight_lut[0x18] = "00000056";
    szQStr_raw_frontend_np_lut_weight_lut[0x19] = "00000050";
    szQStr_raw_frontend_np_lut_weight_lut[0x1a] = "00000052";
    szQStr_raw_frontend_np_lut_weight_lut[0x1b] = "0000005a";
    szQStr_raw_frontend_np_lut_weight_lut[0x14] = "00000054";
    szQStr_raw_frontend_np_lut_weight_lut[0x15] = "0000005a";
    szQStr_raw_frontend_np_lut_weight_lut[0x16] = "00000059";
    szQStr_raw_frontend_np_lut_weight_lut[0x17] = "00000052";
    szQStr_raw_frontend_np_lut_weight_lut[0x10] = "00000052";
    szQStr_raw_frontend_np_lut_weight_lut[0x11] = "00000051";
    szQStr_raw_frontend_np_lut_weight_lut[0x12] = "00000053";
    szQStr_raw_frontend_np_lut_weight_lut[0x13] = "00000052";
    szQStr_raw_frontend_np_lut_weight_lut[0xc] = "00000039";
    szQStr_raw_frontend_np_lut_weight_lut[0xd] = "00000044";
    szQStr_raw_frontend_np_lut_weight_lut[0xe] = "00000058";
    szQStr_raw_frontend_np_lut_weight_lut[0xf] = "00000056";
    szQStr_raw_frontend_np_lut_weight_lut[0x8] = "0000002c";
    szQStr_raw_frontend_np_lut_weight_lut[0x9] = "00000036";
    szQStr_raw_frontend_np_lut_weight_lut[0xa] = "00000032";
    szQStr_raw_frontend_np_lut_weight_lut[0xb] = "00000039";
    szQStr_raw_frontend_np_lut_weight_lut[0x4] = "0000000a";
    szQStr_raw_frontend_np_lut_weight_lut[0x5] = "00000009";
    szQStr_raw_frontend_np_lut_weight_lut[0x6] = "00000002";
    szQStr_raw_frontend_np_lut_weight_lut[0x7] = "00000009";
    szQStr_raw_frontend_np_lut_weight_lut[0x0] = "00000004";
    szQStr_raw_frontend_np_lut_weight_lut[0x1] = "00000003";
    szQStr_raw_frontend_np_lut_weight_lut[0x2] = "0000000a";
    szQStr_raw_frontend_np_lut_weight_lut[0x3] = "00000002";
}

void IspPPraw_frontend::step1()
{
    writeLine(E_ACTION_WR,"isp_config_ping.raw_frontend.reg_ge_strength","04000029");
    writeLine(E_ACTION_RR,"isp_config_ping.raw_frontend.reg_ge_strength");
    writeLine(E_ACTION_WR,"isp_config_ping.raw_frontend.reg_ge_strength",ptEdit_reg_ge_strength->text());
    writeLine(E_ACTION_RR,"isp_config_ping.raw_frontend.reg_ge_strength");

    writeLine(E_ACTION_WR,"isp_config_ping.raw_frontend.reg_dp_slope",ptEdit_reg_dp_slope->text());
    writeLine(E_ACTION_RR,"isp_config_ping.raw_frontend.reg_dp_slope");

    writeLine(E_ACTION_WR,"isp_config_ping.raw_frontend.reg_ge_slope","008000de");
    writeLine(E_ACTION_RR,"isp_config_ping.raw_frontend.reg_ge_slope");

    writeLine(E_ACTION_WR,"isp_config_ping.raw_frontend.reg_ge_slope",ptEdit_reg_ge_slope->text());
    writeLine(E_ACTION_RR,"isp_config_ping.raw_frontend.reg_ge_slope");

    writeLine(E_ACTION_WR,"isp_config_ping.raw_frontend.reg_dpdev_threshold","000002c0");
    writeLine(E_ACTION_RR,"isp_config_ping.raw_frontend.reg_dpdev_threshold");

    writeLine(E_ACTION_WR,"isp_config_ping.raw_frontend.reg_line_thresh","000000ea");
    writeLine(E_ACTION_RR,"isp_config_ping.raw_frontend.reg_line_thresh");

    writeLine(E_ACTION_WR,"isp_config_ping.raw_frontend.reg_dpdev_threshold",ptEdit_reg_dpdev_threshold->text());
    writeLine(E_ACTION_RR,"isp_config_ping.raw_frontend.reg_dpdev_threshold");

    writeLine(E_ACTION_WR,"isp_config_ping.raw_frontend.reg_line_thresh",ptEdit_reg_line_thresh->text());
    writeLine(E_ACTION_RR,"isp_config_ping.raw_frontend.reg_line_thresh");

    writeLine(E_ACTION_WR,"isp_config_ping.raw_frontend.reg_thresh_short","00003009");
    writeLine(E_ACTION_RR,"isp_config_ping.raw_frontend.reg_thresh_short");

    writeLine(E_ACTION_WR,"isp_config_ping.raw_frontend.reg_thresh_short",ptEdit_reg_thresh_short->text());
    writeLine(E_ACTION_RR,"isp_config_ping.raw_frontend.reg_thresh_short");

    writeLine(E_ACTION_WR,"isp_config_ping.raw_frontend_np.exp_thresh",ptEdit_exp_thresh->text());
    writeLine(E_ACTION_RR,"isp_config_ping.raw_frontend_np.exp_thresh");

    writeLine(E_ACTION_WR,"isp_config_ping.raw_frontend_np.reg_short_ratio","0000041e");
    writeLine(E_ACTION_RR,"isp_config_ping.raw_frontend_np.reg_short_ratio");

    writeLine(E_ACTION_WR,"isp_config_ping.raw_frontend_np.reg_short_ratio",ptEdit_reg_short_ratio->text());
    writeLine(E_ACTION_RR,"isp_config_ping.raw_frontend_np.reg_short_ratio");

    for(int i = M_RAW_FRONTED_NP_LUT_WEIGHT_LUT_NUMBER - 1; i >0; i-=4)
    {
        for(int j = 3; j >=0; j--)
        {
            QString strLine;
            strLine.sprintf("isp_config_ping.raw_frontend_np_lut.weight_lut[%x]",i-j);

            writeLine(E_ACTION_WR,strLine,szQStr_raw_frontend_np_lut_weight_lut[i-j]);
            writeLine(E_ACTION_RR,strLine);
        }
    }
}

void IspPPraw_frontend::clickedSlot(bool checked)
{
    QString str_exp_thresh = ptEdit_exp_thresh->text();
//    QString str_weight_lut = ptEdit_weight_lut->text();
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
