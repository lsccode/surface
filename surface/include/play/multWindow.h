#ifndef PIC4WINDOW_H
#define PIC4WINDOW_H
#include "commonHeader.h"
#include "picwindow.h"
class picWindow04:public QWidget
{
    Q_OBJECT
public:
    picWindow04(QWidget *parent = 0);
    picWindow *pic04[4];
};

class picWindow09:public QWidget
{
    Q_OBJECT
public:
    picWindow09(QWidget *parent = 0);
    picWindow *pic09[9];
};
class picWindow17:public QWidget
{
    Q_OBJECT
public:
    picWindow17(QWidget *parent = 0);
    picWindow *pic17[17];
};
#endif // PIC4WINDOW_H
