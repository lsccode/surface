#ifndef PASS_H
#define PASS_H
#include "commonHeader.h"
#include "picwindow.h"
class PassCfg:public QWidget
{
    Q_OBJECT
public:
    PassCfg(QWidget *parent = 0);
    picWindow *playWidget;
};

#endif
