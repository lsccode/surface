#ifndef ISPPPDECOMPANDER0_H
#define ISPPPDECOMPANDER0_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>

#define M_DECOMPANDER0_PING_MEN (0x20 + 1)
#define M_DECOMPANDER1_PING_MEN (0x100 + 1)
class IspPPdecompander : public QWidget
{
    Q_OBJECT
public:
    explicit IspPPdecompander(QWidget *parent = 0);
public:
    QLabel *ptLabel_decompander0_reg_enable ;
    QLineEdit *ptEdit_decompander0_reg_enable ;

    QLabel *ptLabel_decompander1_reg_enable;
    QLineEdit *ptEdit_decompander1_reg_enable;

    QComboBox *ptCb_decompander0_ping_mem;
    QLineEdit *ptEdit_decompander0_ping_mem;
    QString szQStr_decompander0_ping_mem[M_DECOMPANDER0_PING_MEN];

    QComboBox *ptCb_decompander1_ping_mem;
    QLineEdit *ptEdit_decompander1_ping_mem;
    QString szQStr_decompander1_ping_mem[M_DECOMPANDER1_PING_MEN];

    QPushButton *ptPBtn;
signals:

public slots:
    void clickedSlot(bool checked = false);

    void activatedSlot_decompander0_ping(int index);
    void textChangedSlot_decompander0_ping(const QString & text);

    void activatedSlot_decompander1_ping(int index);
    void textChangedSlot_decompander1_ping(const QString & text);
};

#endif // ISPPPDECOMPANDER0_H
