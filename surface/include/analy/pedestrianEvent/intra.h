#ifndef INTRA_H
#define INTRA_H
#include "commonHeader.h"
#include "picwindow.h"
class IntraCfg:public QWidget
{
    Q_OBJECT
public:
    IntraCfg(QWidget *parent = 0);
    picWindow *playWidget;
};

#endif
