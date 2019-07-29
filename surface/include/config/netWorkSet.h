#ifndef NETWORKSET_H
#define NETWORKSET_H
#include "commonHeader.h"
#include "commonDef.h"
class NetWorkSet:public QWidget
{
    Q_OBJECT
public:
    NetWorkSet(QWidget *parent = 0);
public:
    QLabel *dhcpLabel;
    QComboBox *dhcpCombox;
    QLabel *ipaddrLabel;
    QLineEdit *ipaddrEdit;
    QLabel *subMaskLabel;
    QLineEdit *subMaskEdit;
    QLabel *gateWayLabel;
    QLineEdit *gateWayEdit;

    QLabel *dnsLabel;
    QComboBox *dnsCombox;
    QLineEdit *dnsEdit;
    QLabel *hostnameLabel;
    QComboBox *hostnameCombox;
    QLineEdit *hostnameEdit;

    QLabel *httpPortsLabel;
    QComboBox *httpCombox;
    QLineEdit *httpPortsEdit;

    QLabel *httpsPortsLabel;
    QComboBox *httpsCombox;
    QLineEdit *httpsPortsEdit;

    QLabel *rtspPortsLabel;
    QComboBox *rtspCombox;
    QLineEdit *rtspPortsEdit;

    QLabel *zeroLable;
    QCheckBox *zeroText;

    QLabel *onvifDisLabel;
    QComboBox *onvifCombox;

    QPushButton *applyBtn;
public slots:
    void doUpdateWgt(UrlInfo info);
private:
    QString devType;
    QString devUrl;
    UrlInfo info;
};

#endif // NETWORKSET_H
