#include "isppptemper.h"
#include <QGridLayout>
IspPPtemper::IspPPtemper(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout *layoutGrid = new QGridLayout;

    // add edit
    ptLabel_format  = new QLabel("format :");
    ptEdit_format  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_format ,0,0);layoutGrid->addWidget(ptEdit_format ,0,1);

    ptLabel_line_offset  = new QLabel("line_offset :");
    ptEdit_line_offset  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_line_offset ,1,0);layoutGrid->addWidget(ptEdit_line_offset ,1,1);

    ptLabel_msb_bank_base_reader  = new QLabel("msb_bank_base_reader :");
    ptEdit_msb_bank_base_reader  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_msb_bank_base_reader ,2,0);layoutGrid->addWidget(ptEdit_msb_bank_base_reader ,2,1);

    ptLabel_msb_bank_base_writer  = new QLabel("msb_bank_base_writer :");
    ptEdit_msb_bank_base_writer  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_msb_bank_base_writer ,3,0);layoutGrid->addWidget(ptEdit_msb_bank_base_writer ,3,1);

    ptLabel_reg_frame_write_on_msb_dma  = new QLabel("reg_frame_write_on_msb_dma :");
    ptEdit_reg_frame_write_on_msb_dma  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_frame_write_on_msb_dma ,4,0);layoutGrid->addWidget(ptEdit_reg_frame_write_on_msb_dma ,4,1);

    ptLabel_reg_msb_reader_axi_id_value  = new QLabel("reg_msb_reader_axi_id_value :");
    ptEdit_reg_msb_reader_axi_id_value  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_msb_reader_axi_id_value ,5,0);layoutGrid->addWidget(ptEdit_reg_msb_reader_axi_id_value ,5,1);

    ptLabel_reg_msb_writer_axi_id_value  = new QLabel("reg_msb_writer_axi_id_value :");
    ptEdit_reg_msb_writer_axi_id_value  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_msb_writer_axi_id_value ,6,0);layoutGrid->addWidget(ptEdit_reg_msb_writer_axi_id_value ,6,1);

    ptLabel_black_level  = new QLabel("black_level :");
    ptEdit_black_level  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_black_level ,7,0);layoutGrid->addWidget(ptEdit_black_level ,7,1);

    ptLabel_weight_lut  = new QLabel("weight_lut :");
    ptEdit_weight_lut  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_weight_lut ,8,0);layoutGrid->addWidget(ptEdit_weight_lut ,8,1);

    ptLabel_reg_noise_level_0  = new QLabel("reg_noise_level_0 :");
    ptEdit_reg_noise_level_0  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_noise_level_0 ,9,0);layoutGrid->addWidget(ptEdit_reg_noise_level_0 ,9,1);

    ptLabel_reg_use_lut  = new QLabel("reg_use_lut :");
    ptEdit_reg_use_lut  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_use_lut ,10,0);layoutGrid->addWidget(ptEdit_reg_use_lut ,10,1);

    ptLabel_thresh1  = new QLabel("thresh1 :");
    ptEdit_thresh1  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_thresh1 ,11,0);layoutGrid->addWidget(ptEdit_thresh1 ,11,1);

    ptLabel_thresh2  = new QLabel("thresh2 :");
    ptEdit_thresh2  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_thresh2 ,12,0);layoutGrid->addWidget(ptEdit_thresh2 ,12,1);

    ptLabel_thresh3  = new QLabel("thresh3 :");
    ptEdit_thresh3  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_thresh3 ,13,0);layoutGrid->addWidget(ptEdit_thresh3 ,13,1);

    ptLabel_reg_enable  = new QLabel("reg_enable :");
    ptEdit_reg_enable  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_enable ,14,0);layoutGrid->addWidget(ptEdit_reg_enable ,14,1);

    ptLabel_reg_recursion_limit  = new QLabel("reg_recursion_limit :");
    ptEdit_reg_recursion_limit  = new QLineEdit("000000001");
    layoutGrid->addWidget(ptLabel_reg_recursion_limit ,15,0);layoutGrid->addWidget(ptEdit_reg_recursion_limit ,15,1);

    ptCb_temper_noise_profile_lut_weight_lut  = new QComboBox;
    ptEdit_temper_noise_profile_lut_weight_lut = new QLineEdit("null");
    layoutGrid->addWidget(ptCb_temper_noise_profile_lut_weight_lut,16,0);layoutGrid->addWidget(ptEdit_temper_noise_profile_lut_weight_lut,16,1);
    for(unsigned int i = 0;i < M_TEMPER_NOISE_PROFILE_LUT_WEIGHT_LUT_NUMBER; ++i)
    {
        QString str;
        str.sprintf("temper_noise_profile_lut_weight_lut[%x]",i);
        ptCb_temper_noise_profile_lut_weight_lut->addItem(str);
        szQStr_temper_noise_profile_lut_weight_lut[i].sprintf("%x",i);
    }
    ptEdit_temper_noise_profile_lut_weight_lut->setText(szQStr_temper_noise_profile_lut_weight_lut[ptCb_temper_noise_profile_lut_weight_lut->currentIndex()]);

    ptPBtn = new QPushButton("确定");
    layoutGrid->addWidget(ptPBtn,40,1,1,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(layoutInter);
    mainLayout->addStretch();

    connect(ptPBtn,SIGNAL(clicked(bool)),this,SLOT(clickedSlot(bool)));

    connect(ptCb_temper_noise_profile_lut_weight_lut,SIGNAL(activated(int)),
            this,SLOT(activatedSlot_temper_noise_profile_lut_weight_lut(int)));
    connect(ptEdit_temper_noise_profile_lut_weight_lut,SIGNAL(textChanged(const QString)),
            this,SLOT(textChangedSlot_temper_noise_profile_lut_weight_lut(const QString)));

    setLayout(mainLayout);
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
