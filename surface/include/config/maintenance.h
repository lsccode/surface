#ifndef MAINTENACE_H
#define MAINTENACE_H
#include "commonHeader.h"
#include "commonDef.h"
class Maintence:public QWidget
{
    Q_OBJECT

public:
    Maintence(QWidget *parent = 0);
public:
    QLabel *conf;
    QLabel *softFacRest;
    QLabel *hardFacRest;
    QLabel *reboot;
    QLabel *firmware;
    QPushButton *backupBtn;
    QPushButton *restoreBtn;
    QPushButton *softRstBtn;
    QPushButton *hardRstBtn;
    QPushButton *rebootBtn;
    QPushButton *upGradeBtn;
    QLineEdit   *Softversion;
public slots:
    void doUpdateWgt(UrlInfo info);
    void doSoftRestSt();
    void doHardRestSt();
    void doRebootStSt();
private:
    QString devType;
    QString devUrl;
    UrlInfo info;
};
#endif // MAINTENACE_H
