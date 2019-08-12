#include <QProcess>
#include <QSettings>

#include "mainwindow.h"
MainWindow::MainWindow()
{
    setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(123,123,123));
    setPalette(palette);
    mywidget = new QTabWidget;
    ptIspCm = new IspCommon;
    ptIspPingPongF1 = new IspPingPongFrag1;
    ptIspPingPongF2 = new IspPingPongFrag2;
    ptIspPingPongF3 = new IspPingPongFrag3;
    mywidget->setIconSize(QSize(80, 30));
    mywidget->setTabShape(QTabWidget::Triangular);

    mywidget->addTab(ptIspCm,QIcon(":/images/isp_com.png"),""); // "common"
    mywidget->addTab(ptIspPingPongF1,QIcon(":/images/isp_pip1.png"),""); // "pingpong frag1"
    mywidget->addTab(ptIspPingPongF2,QIcon(":/images/isp_pip2.png"),"");// "pingpong frag2"

    setMinimumSize(1080,720);
    setCentralWidget(mywidget);
    setWindowIcon(QIcon(":/images/nextvpu.png"));
    setWindowTitle(tr("nextvpu ISP script test"));

//    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_SetPalette);

//    readSettings();
    connect(ptIspCm,SIGNAL(clickedCommonSig(bool)),
            this,SLOT(clickedMainSlot(bool)));
    connect(ptIspPingPongF1,SIGNAL(clickedPingPongF1Sig(bool)),
            this,SLOT(clickedMainSlot(bool)));
    connect(ptIspPingPongF2,SIGNAL(clickedPingPongF2Sig(bool)),
            this,SLOT(clickedMainSlot(bool)));

    connect(this,SIGNAL(setClickBtnDisSignal()),
            ptIspPingPongF1,SLOT(clickedF1OKDisableSlot()));
    connect(this,SIGNAL(setClickBtnEnaSignal()),
            ptIspPingPongF1,SLOT(clickedF1OKEnableSlot()));

    connect(this,SIGNAL(setClickBtnDisSignal()),
            ptIspPingPongF2,SLOT(clickedF2OKDisableSlot()));
    connect(this,SIGNAL(setClickBtnEnaSignal()),
            ptIspPingPongF2,SLOT(clickedF2OKEnableSlot()));

    connect(this,SIGNAL(setClickBtnDisSignal()),
            ptIspCm,SLOT(clickedCommonDisableSlot()));
    connect(this,SIGNAL(setClickBtnEnaSignal()),
            ptIspCm,SLOT(clickedCommonEnableSlot()));


    setAllConnect();

}
void MainWindow::setAllConnect()
{
    connect(mywidget,SIGNAL(currentChanged(int)),this,SLOT(showCurrent(int)));
//    connect(this,SIGNAL(showDevConfig()),devConfg,SLOT(currentShowIndex()));
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

    emit setClickBtnDisSignal();
    ptIspCm->execFile();
    emit setClickBtnEnaSignal();
    //QProcess::execute("ls");
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
