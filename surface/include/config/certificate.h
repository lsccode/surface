#ifndef CERTIFICATE_H
#define CERTIFICATE_H
#include "commonHeader.h"
#include "commonDef.h"
class Certificate:public QWidget
{
    Q_OBJECT
 public:
    Certificate(QWidget *parent = 0);
    QLabel *certifLable;
    QPushButton *uploadCertBtn;
    QLine *splitLine;
    QListWidget *listCert;
    QPushButton *applyBtn;
public slots:
    void doUpdateWgt(UrlInfo info){}
};
#endif // CERTIFICATE_H
