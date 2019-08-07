#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "commonHeader.h"
#include "playWidget.h"
#include "devConfig.h"
#include "analyCfg.h"
#include "advanceEvent/AdvanceCfg.h"
#include "cameraEvent/CameraCfg.h"
#include "countEvent/CountCfg.h"
#include "pedestrianEvent/PedestrCfg.h"
#include "vehicleEvent/VehiCfg.h"
#include "ptzEvent/PtzCfg.h"
#include "smokeFireEvent/SmokeFireCfg.h"
#include "staticEvent/StaticCfg.h"
#include "script/isp_common/ispcommon.h"
#include "script/isp_pingpong/isppingpongfrag1.h"
#include "script/isp_pingpong/isppingpongfrag2.h"
#include "script/isp_pingpong/isppingpongfrag3.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    QTabWidget *mywidget;
    playWidget *playWin;
    DevConfig *devConfg;
//    AnalyCfg *analyConfg;
    AdvanceCfg *advanceConfg;
    CameraCfg *cameraConfg;
    CountCfg *countConfg;
    PedestrCfg *pedConfg;
    VehiCfg *vehiConfg;
    PtzCfg *ptzConfg;
    SmokeFireCfg *sfConfig;
    StaticCfg *stConfig;
    IspCommon *ptIspCm;
    //IspPingPong *ptIspPingPong;
    IspPingPongFrag1 *ptIspPingPongF1;
    IspPingPongFrag2 *ptIspPingPongF2;
    IspPingPongFrag3 *ptIspPingPongF3;
    virtual QSize minimumSizeHint() const;
    virtual QSize sizeHint() const;
    void setAllConnect();

public:
//    virtual void paintEvent(QPaintEvent *);
protected:
    void resizeEvent(QResizeEvent * event);
//    void closeEvent(QCloseEvent *event);
public slots:
    void clickedMainSlot(bool checked = false);
    void showCurrent(int index);
signals:
    void showDevConfig();

public:
    void writeSettings();
    void readSettings();
};
#endif // MAINWINDOW_H
