#ifndef TIMECONFIGURE_H
#define TIMECONFIGURE_H
#include "commonHeader.h"
#include "commonDef.h"
class TimeConfigure:public QWidget
{
    Q_OBJECT

public:
    TimeConfigure(QWidget *parent = 0);
public:
    QGroupBox *groupTimeZone;
    QComboBox *timeZone;
    QCheckBox *autoAjust;
    QPushButton *applyZone;

    QGroupBox *timeSet;
    QComboBox *timeType;
    QLineEdit *timeShow;
    QLineEdit *ntpServer;
    QDateTimeEdit *dateTimeSet;
    QPushButton *applyTimeSet;

    QLabel *localtimeLabel;
    QLabel *ntpTimeLabel;
    QLabel *userSetLabel;

    UrlInfo info;
public Q_SLOTS:
    void setTimeindex(const QString &);
private:
    int m_timerId;
    QString type;
    QString url;
protected:
    void timerEvent(QTimerEvent *);
public slots:
    void doUpdateWgt(UrlInfo info);
    void doSetTimgSt();
};
#endif // TIMECONFIGURE_H
