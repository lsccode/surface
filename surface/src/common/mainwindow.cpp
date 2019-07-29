#include "mainwindow.h"
MainWindow::MainWindow()
{
    setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(123,123,123));
    setPalette(palette);
    mywidget = new QTabWidget;
    playWin = new playWidget;
    devConfg = new DevConfig;
    //analyConfg = new AnalyCfg;
    advanceConfg = new AdvanceCfg;
    cameraConfg = new CameraCfg;
    countConfg = new CountCfg;
    pedConfg = new PedestrCfg;
    vehiConfg = new VehiCfg;
    ptzConfg = new PtzCfg;
    sfConfig = new SmokeFireCfg;
    stConfig = new StaticCfg;

    mywidget->setIconSize(QSize(24, 24));
    mywidget->setTabShape(QTabWidget::Triangular);
    mywidget->addTab(playWin,QIcon(":/images/films.png"),"实时预览");
    mywidget->addTab(devConfg,QIcon(":/images/devCfg.png"),"设备配置");
    //mywidget->addTab(analyConfg,QIcon(":/images/analy.png"),"智能分析");
    mywidget->addTab(pedConfg,QIcon(":/images/analy.png"),"行人分析");
    mywidget->addTab(vehiConfg,QIcon(":/images/analy.png"),"车辆分析");
    mywidget->addTab(cameraConfg,QIcon(":/images/analy.png"),"相机事件");
    mywidget->addTab(countConfg,QIcon(":/images/analy.png"),"计数事件");
    mywidget->addTab(ptzConfg,QIcon(":/images/analy.png"),"PTZ事件");
    mywidget->addTab(sfConfig,QIcon(":/images/analy.png"),"烟火事件");
    mywidget->addTab(stConfig,QIcon(":/images/analy.png"),"静态事件");
    mywidget->addTab(advanceConfg,QIcon(":/images/analy.png"),"高级事件");

    setMinimumSize(900,480);
    setCentralWidget(mywidget);
    setWindowIcon(QIcon(":/images/appMain.png"));
    setWindowTitle(tr("Smart Nvt"));

    setAllConnect();

}
void MainWindow::setAllConnect()
{
    connect(&playWin->disThread,SIGNAL(FindNewItemSg(QString,QString)),
            devConfg->camereComboBox,SLOT(addNewItemStHdl(QString,QString)));
    connect(&playWin->disThread,SIGNAL(FindNewItemSg(QString,QString)),
            pedConfg->camereComboBox,SLOT(addNewItemStHdl(QString,QString)));
    connect(&playWin->disThread,SIGNAL(FindNewItemSg(QString,QString)),
            vehiConfg->camereComboBox,SLOT(addNewItemStHdl(QString,QString)));
    connect(&playWin->disThread,SIGNAL(FindNewItemSg(QString,QString)),
            cameraConfg->camereComboBox,SLOT(addNewItemStHdl(QString,QString)));

    connect(playWin->addNerUrlDialog,SIGNAL(applyBtnSgHdl(QString,QString)),
            devConfg->camereComboBox,SLOT(addNewItemStHdl(QString,QString)));
    connect(playWin->addNerUrlDialog,SIGNAL(applyBtnSgHdl(QString,QString)),
            pedConfg->camereComboBox,SLOT(addNewItemStHdl(QString,QString)));
    connect(playWin->addNerUrlDialog,SIGNAL(applyBtnSgHdl(QString,QString)),
            vehiConfg->camereComboBox,SLOT(addNewItemStHdl(QString,QString)));
    connect(playWin->addNerUrlDialog,SIGNAL(applyBtnSgHdl(QString,QString)),
            cameraConfg->camereComboBox,SLOT(addNewItemStHdl(QString,QString)));

    connect(&playWin->disThread,SIGNAL(ClearALLItemSg()),
            devConfg->camereComboBox,SLOT(clearItemStHdl()));
    connect(&playWin->disThread,SIGNAL(ClearALLItemSg()),
            pedConfg->camereComboBox,SLOT(clearItemStHdl()));
    connect(&playWin->disThread,SIGNAL(ClearALLItemSg()),
            vehiConfg->camereComboBox,SLOT(clearItemStHdl()));
    connect(&playWin->disThread,SIGNAL(ClearALLItemSg()),
            cameraConfg->camereComboBox,SLOT(clearItemStHdl()));


    connect(playWin->logDlg,SIGNAL(modItemSgHdl(UrlInfo)),
            devConfg->camereComboBox,SLOT(modItemStHdl(UrlInfo)));
    connect(playWin->logDlg,SIGNAL(modItemSgHdl(UrlInfo)),
            pedConfg->camereComboBox,SLOT(modItemStHdl(UrlInfo)));
    connect(playWin->logDlg,SIGNAL(modItemSgHdl(UrlInfo)),
            vehiConfg->camereComboBox,SLOT(modItemStHdl(UrlInfo)));
    connect(playWin->logDlg,SIGNAL(modItemSgHdl(UrlInfo)),
            cameraConfg->camereComboBox,SLOT(modItemStHdl(UrlInfo)));

    connect(mywidget,SIGNAL(currentChanged(int)),this,SLOT(showCurrent(int)));
    connect(this,SIGNAL(showDevConfig()),devConfg,SLOT(currentShowIndex()));
}
QSize MainWindow::minimumSizeHint() const
{
    return QSize(870,378);
}
QSize MainWindow::sizeHint() const
{
    return QSize(870,378);
}
void MainWindow::resizeEvent(QResizeEvent *event)
{
//    printf("I'm here!");
}
void MainWindow::showCurrent(int index)
{
    printf("index = %d\n",index);
    if(index == 1)
    {
        emit showDevConfig();
    }
}
