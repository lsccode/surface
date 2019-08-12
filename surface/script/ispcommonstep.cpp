#include <QTime>
#include <QProcess>
#include "ispcommonstep.h"


IspExeThread::IspExeThread()
{

}

IspExeThread::~IspExeThread()
{

}

void IspExeThread::setExeCmd(QString strcmd)
{
    this->cmd = strcmd;
}

void IspExeThread::run()
{
    QProcess process;

    process.start(this->cmd);
    process.waitForFinished(-1);
    process.close();

    emit execFinished();
}

QFile* IspCommonStep::pQfile = Q_NULLPTR;
IspCommonStep::IspCommonStep()
{
    //    pQfile = NULL;
}

IspCommonStep::~IspCommonStep()
{

}

void IspCommonStep::step1()
{

}

void IspCommonStep::step2()
{

}

void IspCommonStep::step3()
{

}

void IspCommonStep::step4()
{

}

void IspCommonStep::step5()
{

}

void IspCommonStep::step6()
{

}

void IspCommonStep::step7()
{

}

void IspCommonStep::initFile()
{
#if 1
    QDateTime qDateTime = QDateTime::currentDateTime();
    QString strDateString = qDateTime.toString("yyyy_MM_dd_hh_mm_ss");
    QString strFilename = "arm_" + strDateString + ".scr";
#else
    QTime currentTime = QTime::currentTime();
    qsrand(currentTime.second() + currentTime.msec());
    QString strFilename;
    strFilename.sprintf("test_%d.script",qrand());
#endif


    if(pQfile != NULL)
        delete pQfile;
    pQfile = NULL;

    pQfile = new QFile(strFilename);
    pQfile->open(QIODevice::WriteOnly);
}

void IspCommonStep::writeLine(E_SCRIPT_ACTION eAction, QString strRegisterName, QString strValue)
{
    QString strLine;
    if(pQfile == NULL)
        return;

    const char *data[] =
    {
        "wr",
        "rr",
        "indata",
        "outdata",
        "process",
    };

    if(strValue.size() > 0)
        strLine.sprintf("%s %s %s",data[eAction],strRegisterName.toStdString().c_str(),strValue.toStdString().c_str());
    else if(strRegisterName.size() > 0)
        strLine.sprintf("%s %s",data[eAction],strRegisterName.toStdString().c_str());
    else
        strLine.sprintf("%s",data[eAction]);

    strLine += "\n";
    pQfile->write(strLine.toStdString().c_str());

    return;
}

void IspCommonStep::execFile()
{
#if 0
    //    if(pQfile == NULL)
    //       return;

    //    QString strFileName = pQfile->fileName();
    //    pQfile->flush();
    //    pQfile->close();

    //    QString strExe = "./Lloyd_R0P0 -i " + strFileName + " -o output" + strFileName;

    //    //QProcess::execute(strExe);

    //    QProcess process;

    //    process.start(strExe);
    //    process.waitForFinished(-1);
    //    process.close();
    //start();
#else
    if(pQfile == NULL)
        return;

    QString strFileName = pQfile->fileName();
    pQfile->flush();
    pQfile->close();

    QString strExe = "./Lloyd_R0P0 -i " + strFileName + " -o output" + strFileName;
    ctIspExeThread.setExeCmd(strExe);
    ctIspExeThread.start();
#endif
    return;
}

