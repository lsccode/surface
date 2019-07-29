#ifndef COMMONDEF_H
#define COMMONDEF_H
#include <QString>
#include <QComboBox>
#include <sys/time.h>

class UrlInfo
{
public:
    UrlInfo(QString type = "none",QString url = "none")
    {
        this->type = type;
        this->url = url;
    }
    UrlInfo(QString type,QString url,QString user,QString passWord)
    {
        this->type = type;
        this->url = url;
        this->user = user;
        this->passWord = passWord;
    }
    QString type;
    QString url;
    QString user;
    QString passWord;
    QString autoOrHand;
};
Q_DECLARE_METATYPE(UrlInfo)
class ComboBoxUrl:public QComboBox
{
    Q_OBJECT
public:
    ComboBoxUrl(QWidget *parent = 0);
public slots:
    void addNewItemStHdl(QString type,QString url);
    void clearItemStHdl();
    void modItemStHdl(UrlInfo info);
};
class TimeDateUser
{
public:
    TimeDateUser();
    TimeDateUser(int ye,int mo,int da,int ho,int mi,int se,int ms);
    void setTimeDate(int ye,int mo,int da,int ho,int mi,int se,int ms);
    char *created();
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int msecond;
    timeval start;
    timeval end;
};
#endif // COMMONDEF_H
