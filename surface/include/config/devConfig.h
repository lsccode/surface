#ifndef DEVCONFIG_H
#define DEVCONFIG_H
#include "commonHeader.h"
#include "deviceInfo.h"
#include "timeConfigure.h"
#include "maintenance.h"
#include "netWorkSet.h"
#include "userMng.h"
#include "certificate.h"
#include "sysLog.h"
#include "events.h"
#include "videoImageSet.h"
#include "commonDef.h"
//QString strlist[] = {"","","",""};
class ListWidget:public QListWidget
{
public:
    ListWidget(QWidget *parent = 0):QListWidget(parent)
    {

    }
};

class DevConfig:public QWidget
{
    Q_OBJECT
public:
    DevConfig(QWidget *parent = 0);
    QLabel *cameralabel;
    ComboBoxUrl *camereComboBox;
    ListWidget *cfgListWidget;
    QStackedLayout *stackedLayout;
    DeviceInfo *devInfo;
    TimeConfigure *timeSet;
    Maintence *mainTence;
    NetWorkSet *netWorkConifg;
    UserMng *userMng;
    Certificate *certifConfig;
    SystemLog *sysLogConfig;
    Events    *eventConfig;
    VideoImage *videoImgConfig;

   // QTabWidget *tabConfig;
private:
    void createListWidgetIcons();
    void setAllConnect();
public slots:
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);
    void currentShowIndex();
signals:
    void devinfoSg(UrlInfo info);
    void timesetSg(UrlInfo info);
    void mainTenceSg(UrlInfo info);
    void netWorkSg(UrlInfo info);
    void userMngSg(UrlInfo info);
    void certifSg(UrlInfo info);
    void sysLogSg(UrlInfo info);
    void eventSg(UrlInfo info);
    void videoImgSg(UrlInfo info);

};
#endif // CERTIFICATE_H
