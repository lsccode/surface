#ifndef DEVICEINFO_H
#define DEVICEINFO_H
#include "commonHeader.h"
#include "commonDef.h"
class DeviceInfo:public QDialog
{
    Q_OBJECT
public:
    DeviceInfo(QWidget *parent = 0);
public:
    QLabel *nameLabel;
    QLabel *locationLabel;
    QLabel *manuFacturerLabel;
    QLabel *modelLabel;
    QLabel *hardWareLabel;
    QLabel *firmwareLabel;
    QLabel *deviceIdLabel;
    QLabel *ipaddressLabel;
    QLabel *macLabel;
    QLabel *onvifVersionLabel;
    QLabel *urlLabel;

    QLineEdit *nameEdit;
    QLineEdit *locationEdit;
    QLineEdit *manuFacturerEdit;
    QLineEdit *modelEdit;
    QLineEdit *hardWareEdit;
    QLineEdit *firmwareEdit;
    QLineEdit *deviceIdEdit;
    QLineEdit *ipaddressEdit;
    QLineEdit *macEdit;
    QLineEdit *onvifVersionEdit;
    QLineEdit *urlEdit;
public slots:
    void doUpdateWgt(UrlInfo info);
private:
    UrlInfo info;


};
#endif // DEVICEINFO_H
