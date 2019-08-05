#ifndef ISPPPMETERING_AWB_H
#define ISPPPMETERING_AWB_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class IspPPmetering_awb : public QWidget
{
    Q_OBJECT
public:
    explicit IspPPmetering_awb(QWidget *parent = 0);

    QPushButton *ptPBtn;
signals:

public slots:
    void clickedSlot(bool checked = false);

};

#endif // ISPPPMETERING_AWB_H
