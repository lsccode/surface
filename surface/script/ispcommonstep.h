#ifndef ISPCOMMONSTEP_H
#define ISPCOMMONSTEP_H

#include <QFile>
#include <QString>
#include <QObject>
#include <QThread>

enum E_SCRIPT_ACTION {
    E_ACTION_WR,
    E_ACTION_RR,
    E_ACTION_INDATA,
    E_ACTION_OUTDATA,
    E_ACTION_PROCESS,
    E_ACTION_END,
};

class IspExeThread:public QThread
{
    Q_OBJECT
public:
    IspExeThread();
    virtual ~IspExeThread();
public:
    void setExeCmd(QString strcmd);
    virtual void run();
private:
    QString cmd;

signals:
    void execFinished();
};

class IspCommonStep
{
public:
    IspCommonStep();
    virtual ~IspCommonStep();
public:
    virtual void step1();
    virtual void step2();
    virtual void step3();
    virtual void step4();
    virtual void step5();
    virtual void step6();
    virtual void step7();

public:
    IspExeThread ctIspExeThread;
    static QFile *pQfile;

public:
    void initFile();
    void writeLine(E_SCRIPT_ACTION,QString strRegisterName="",QString strValue="");
    void execFile();
};

#endif // ISPCOMMONSTEP_H
