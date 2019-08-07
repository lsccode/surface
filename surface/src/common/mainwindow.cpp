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
    ptIspCm = new IspCommon;
    //ptIspPingPong = new IspPingPong;
    ptIspPingPongF1 = new IspPingPongFrag1;
    ptIspPingPongF2 = new IspPingPongFrag2;
    ptIspPingPongF3 = new IspPingPongFrag3;
    mywidget->setIconSize(QSize(40, 20));
    mywidget->setTabShape(QTabWidget::Triangular);
#if 0
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
#else
    mywidget->addTab(ptIspCm,QIcon(":/images/devCfg.png"),"isp common");
    //mywidget->addTab(ptIspCm,QIcon(":/images/isp_common.png"),"");
    mywidget->addTab(ptIspPingPongF1,QIcon(":/images/devCfg.png"),"isp pingpong frag1");
    mywidget->addTab(ptIspPingPongF2,QIcon(":/images/devCfg.png"),"isp pingpong frag2");
//    mywidget->addTab(ptIspPingPongF3,QIcon(":/images/devCfg.png"),"isp pingpong frag3");
#endif

    setMinimumSize(1080,720);
    setCentralWidget(mywidget);
    setWindowIcon(QIcon(":/images/nextvpu.png"));
    setWindowTitle(tr("nextvpu ISP script test"));

//    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_SetPalette);

    readSettings();
    connect(ptIspCm,SIGNAL(clickedCommonSig(bool)),
            this,SLOT(clickedMainSlot(bool)));
    connect(ptIspPingPongF1,SIGNAL(clickedPingPongF1Sig(bool)),
            this,SLOT(clickedMainSlot(bool)));
    connect(ptIspPingPongF2,SIGNAL(clickedPingPongF2Sig(bool)),
            this,SLOT(clickedMainSlot(bool)));
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

//void MainWindow::paintEvent(QPaintEvent *)
//{
//    QPainter painter(this);
//    QRect framerect = rect();
//    framerect.adjust(1,1,-1,-1);

//    QRect titleRect = framerect;

//    titleRect.setBottom(framerect.top() + 80);
//    painter.fillRect(titleRect,Qt::yellow);

//}
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
    //ptIspCm->
}

//void MainWindow::closeEvent(QCloseEvent *event)
//{
//    writeSettings();
//}

void MainWindow::clickedMainSlot(bool checked)
{
    if(ptIspCm->ptWidgtIspCmGlobal->checkInputFrame() < 0)
    {
        return ;
    }

    ptIspCm->step1();
    ptIspCm->ptWidgtIspCmGlobal->step1();
    ptIspCm->ptWidgtIspCmInputPort->step1();
    ptIspCm->ptWidgtIspCmGlobal->step2();
    ptIspPingPongF2->pt_temper->step1();
    ptIspPingPongF2->pt_sinter->step1();
    ptIspCm->ptWidgtIspCmGlobal->step3();
    ptIspPingPongF2->pt_top->step1();
    ptIspPingPongF1->pt_input_formatter->step1();
    ptIspPingPongF1->pt_misc->step1();
    ptIspPingPongF2->pt_sinter->step2();
    ptIspPingPongF2->pt_temper->step2();
    ptIspPingPongF1->pt_Ca_correction->step1();
    ptIspPingPongF1->pt_misc->step2();
    ptIspPingPongF2->pt_white_balance_aexp->step1();
    ptIspPingPongF2->pt_radial_shading->step1();
    ptIspPingPongF2->pt_mesh_shading->step1();
    ptIspPingPongF1->pt_demosaic_rgbir->step1();
    ptIspPingPongF1->pt_Ccm->step1();
    ptIspPingPongF1->pt_misc->step3();
    ptIspPingPongF1->pt_decompander->step1();
    ptIspPingPongF1->pt_misc->step4();
    ptIspPingPongF1->pt_fr_config->step1();
    ptIspPingPongF1->pt_ds_config->step1();
    ptIspPingPongF1->pt_misc->step5();
    ptIspPingPongF1->pt_frame_stitch->step1();
    ptIspPingPongF1->pt_misc->step6();
    ptIspPingPongF1->pt_Cnr->step1();
    ptIspPingPongF2->pt_sensor_offset->step1();
    ptIspPingPongF2->pt_raw_frontend->step1();
    ptIspPingPongF1->pt_fr_config->step2();
    ptIspPingPongF2->pt_metering->step1();
    ptIspPingPongF2->pt_metering->step2();
    ptIspPingPongF1->pt_fr_config->step3();
    ptIspPingPongF2->pt_temper->step3();;
    ptIspCm->ptWidgtIspCmGlobal->step4();
    ptIspPingPongF2->pt_metering->step3();
    ptIspCm->ptWidgtIspCmGlobal->step5();
    ptIspPingPongF2->pt_metering->step4();
    ptIspPingPongF1->pt_misc->step7();
    ptIspPingPongF2->pt_metering->step3();
    ptIspPingPongF2->pt_metering->step4();
    ptIspPingPongF1->pt_misc->step7();
    ptIspPingPongF2->pt_metering->step3();
    ptIspPingPongF2->pt_metering->step4();
    ptIspPingPongF1->pt_misc->step7();
    ptIspCm->ptWidgtIspCmGlobal->step4();

    ptIspCm->execFile();
}
void MainWindow::showCurrent(int index)
{
    printf("index = %d\n",index);
    if(index == 1)
    {
        emit showDevConfig();
    }
}

void MainWindow::writeSettings()
{
    QSettings settings;
    settings.beginGroup("solodevice_mainwindow");
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    settings.setValue("splitterState", this->saveState());
    settings.endGroup();
}

void MainWindow::readSettings()
{
    QSettings settings;
    settings.beginGroup("solodevice_mainwindow");
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    this->restoreState(settings.value("splitterState").toByteArray());
    settings.endGroup();
}
