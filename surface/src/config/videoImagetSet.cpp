#include "videoImageSet.h"
VideoImage::VideoImage(QWidget *parent):QWidget(parent)
{
    resLabel = new QLabel("Reslution");
    resCombox = new QComboBox;
    //resCombox->setFixedWidth(96);

    frameRateLabel = new QLabel("Framerate");
    frameRateSpinBox = new QSpinBox;
    frameRateSpinBox->setRange(0,100);
    //frameRateSpinBox->setFixedWidth(96);

    encodeInterLabel = new QLabel("Encode Interal");
    //encodeScrollBar = new QScrollBar(Qt::Horizontal);
    encodeScrollBar = new QSlider(Qt::Horizontal);
    encodeScrollBar->setRange(0,100);

    bitLabel = new QLabel("Bitrate");
    bitSpinBox = new QSpinBox;
    bitSpinBox->setRange(0,100);

    qualityLabel = new QLabel("Quality");
    //qualityScrollBar = new QScrollBar(Qt::Horizontal);
    qualityScrollBar = new QSlider(Qt::Horizontal);
    qualityScrollBar->setRange(0,100);

    govLabel = new QLabel("Gov Length");
    govSpinBox = new QSpinBox;
    govSpinBox->setRange(0,100);

    brightLabel = new QLabel("Bright");
    //brightScrollBar = new QScrollBar(Qt::Horizontal);
    brightScrollBar = new QSlider(Qt::Horizontal);
    brightScrollBar->setRange(0,100);

    colorLabel = new QLabel("Bright");
    //colorScrollBar = new QScrollBar(Qt::Horizontal);
    colorScrollBar = new QSlider(Qt::Horizontal);
    colorScrollBar->setRange(0,100);

    contrastLabel = new QLabel("Bright");
    //contrastScrollBar = new QScrollBar(Qt::Horizontal);
    contrastScrollBar = new QSlider(Qt::Horizontal);
    contrastScrollBar->setRange(0,100);

    QGridLayout *layoutGrid = new QGridLayout;
//    layoutGrid->addWidget(resLabel,0,0);
//    layoutGrid->addWidget(resCombox,0,1,1,2);
//    layoutGrid->addWidget(frameRateLabel,0,3,1,1);
//    layoutGrid->addWidget(frameRateSpinBox,0,4,1,2);

//    layoutGrid->addWidget(encodeInterLabel,1,0);
//    layoutGrid->addWidget(encodeScrollBar,1,1,1,2);
//    layoutGrid->addWidget(bitLabel,1,3,1,1);
//    layoutGrid->addWidget(bitSpinBox,1,4,1,2);

//    layoutGrid->addWidget(qualityLabel,2,0);
//    layoutGrid->addWidget(qualityScrollBar,2,1,1,2);
//    layoutGrid->addWidget(govLabel,2,3,1,1);
//    layoutGrid->addWidget(govSpinBox,2,4,1,2);

//    layoutGrid->addWidget(brightLabel,3,0);
//    layoutGrid->addWidget(brightScrollBar,3,1,1,3);
//    layoutGrid->addWidget(colorLabel,4,0);
//    layoutGrid->addWidget(colorScrollBar,4,1,1,3);
//    layoutGrid->addWidget(contrastLabel,5,0);
//    layoutGrid->addWidget(contrastScrollBar,5,1,1,3);
    layoutGrid->addWidget(resLabel,0,0);
    layoutGrid->addWidget(resCombox,0,1);
    layoutGrid->addWidget(frameRateLabel,1,0);
    layoutGrid->addWidget(frameRateSpinBox,1,1);
    layoutGrid->addWidget(bitLabel,2,0);
    layoutGrid->addWidget(bitSpinBox,2,1);

    layoutGrid->addWidget(govLabel,3,0);
    layoutGrid->addWidget(govSpinBox,3,1);
    layoutGrid->addWidget(encodeInterLabel,4,0);
    layoutGrid->addWidget(encodeScrollBar,4,1);
    layoutGrid->addWidget(qualityLabel,5,0);
    layoutGrid->addWidget(qualityScrollBar,5,1);

    layoutGrid->addWidget(brightLabel,6,0);
    layoutGrid->addWidget(brightScrollBar,6,1);
    layoutGrid->addWidget(colorLabel,7,0);
    layoutGrid->addWidget(colorScrollBar,7,1);
    layoutGrid->addWidget(contrastLabel,8,0);
    layoutGrid->addWidget(contrastScrollBar,8,1);

    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch(1);

    QVBoxLayout *layoutMain = new QVBoxLayout;
    layoutMain->addLayout(layoutInter);
    layoutMain->addStretch(1);
    setLayout(layoutMain);

}
