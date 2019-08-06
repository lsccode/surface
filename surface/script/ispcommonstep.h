#ifndef ISPCOMMONSTEP_H
#define ISPCOMMONSTEP_H

#include <QFile>
#include <QString>

enum E_SCRIPT_ACTION {
    E_ACTION_WR,
    E_ACTION_RR,
    E_ACTION_IN,

    E_ACTION_END,
};

class IspCommonStep
{
public:
    IspCommonStep();
public:
    virtual void step1();
    virtual void step2();
    virtual void step3();
    virtual void step4();
    virtual void step5();
    virtual void step6();

public:
    static QFile *pQfile;

public:
    void initFile();
    void writeLine(E_SCRIPT_ACTION,QString strRegisterName,QString strValue="");
    void execFile();
};

#endif // ISPCOMMONSTEP_H
