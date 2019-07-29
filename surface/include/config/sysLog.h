#ifndef SYSLOG_H
#define SYSLOG_H
#include "commonHeader.h"
#include "commonDef.h"
class SystemLog:public QWidget
{
    Q_OBJECT
public:
    SystemLog(QWidget *parent = 0);
    QLabel *selectLogLabel;
    QComboBox *logCombox;
    QPushButton *getBtn;
    QLabel *logInfo;
    QTextEdit *textLog;
    QPushButton *saveBtn;
public slots:
    void doUpdateWgt(UrlInfo info);
private:
    QString devType;
    QString devUrl;
    UrlInfo info;
};
#endif // SYSLOG_H
