#ifndef VIDEOIMAGESET_H
#define VIDEOIMAGESET_H
#include "commonHeader.h"
#include "commonDef.h"
class VideoImage:public QWidget
{
    Q_OBJECT
public:
    VideoImage(QWidget *parent = 0);
    QLabel *resLabel;
    QComboBox *resCombox;
    QLabel *frameRateLabel;
    QSpinBox *frameRateSpinBox;
    QLabel *encodeInterLabel;
    //QScrollBar *encodeScrollBar;
    QSlider *encodeScrollBar;
    QLabel *bitLabel;
    QSpinBox *bitSpinBox;
    QLabel *qualityLabel;
    //QScrollBar *qualityScrollBar;
    QSlider *qualityScrollBar;
    QLabel *govLabel;
    QSpinBox *govSpinBox;

    QLabel *brightLabel;
    //QScrollBar *brightScrollBar;
    QSlider *brightScrollBar;
    QLabel *colorLabel;
    //QScrollBar *colorScrollBar;
    QSlider *colorScrollBar;
    QLabel *contrastLabel;
    //QScrollBar *contrastScrollBar;
    QSlider *contrastScrollBar;
public slots:
    void doUpdateWgt(UrlInfo info){}
};
#endif // VIDEOIMAGESET_H
