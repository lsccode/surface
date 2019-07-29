#include "devConfig.h"

DevConfig::DevConfig(QWidget *parent):QWidget(parent)
{
 //   QStringList strList;
    cameralabel = new QLabel(" Select Camrer ");
    //cameralabel->setMargin(10);
    camereComboBox = new ComboBoxUrl;
    cfgListWidget = new ListWidget;
    stackedLayout = new QStackedLayout;

    devInfo = new DeviceInfo;
    timeSet = new TimeConfigure;
    mainTence = new Maintence;
    netWorkConifg = new NetWorkSet;
    userMng = new UserMng;
    certifConfig = new Certificate;
    sysLogConfig = new SystemLog;
    eventConfig = new Events;
    videoImgConfig = new VideoImage;
    cfgListWidget->setViewMode(QListView::IconMode);
    cfgListWidget->setIconSize(QSize(32, 32));
    cfgListWidget->setMovement(QListView::Static);
    cfgListWidget->setMaximumWidth(80);
    cfgListWidget->setSpacing(5);
    cfgListWidget->setFrameShape(QFrame::NoFrame);
    stackedLayout->addWidget(devInfo);
    stackedLayout->addWidget(timeSet);
    stackedLayout->addWidget(mainTence);
    stackedLayout->addWidget(netWorkConifg);
    stackedLayout->addWidget(userMng);
    stackedLayout->addWidget(certifConfig);
    stackedLayout->addWidget(sysLogConfig);
    stackedLayout->addWidget(eventConfig);
    stackedLayout->addWidget(videoImgConfig);
    createListWidgetIcons();

    QGridLayout *layoutRight = new QGridLayout;
    layoutRight->addWidget(cameralabel,0,0);
    layoutRight->addWidget(camereComboBox,0,1);
    layoutRight->setColumnStretch(1,1);
    layoutRight->addLayout(stackedLayout,1,0,1,2);
    QHBoxLayout *layoutMain = new QHBoxLayout;
    layoutMain->addWidget(cfgListWidget);
    layoutMain->addLayout(layoutRight);
    setLayout(layoutMain);

    cfgListWidget->setCurrentRow(0);

    setAllConnect();
   }
void DevConfig::setAllConnect()
{
    connect(cfgListWidget,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));
    connect(this,SIGNAL(devinfoSg(UrlInfo)),devInfo,SLOT(doUpdateWgt(UrlInfo)));
    connect(this,SIGNAL(timesetSg(UrlInfo)),timeSet,SLOT(doUpdateWgt(UrlInfo)));
    connect(this,SIGNAL(mainTenceSg(UrlInfo)),mainTence,SLOT(doUpdateWgt(UrlInfo)));
    connect(this,SIGNAL(netWorkSg(UrlInfo)),netWorkConifg,SLOT(doUpdateWgt(UrlInfo)));
    connect(this,SIGNAL(userMngSg(UrlInfo)),userMng,SLOT(doUpdateWgt(UrlInfo)));
    connect(this,SIGNAL(certifSg(UrlInfo)),certifConfig,SLOT(doUpdateWgt(UrlInfo)));
    connect(this,SIGNAL(sysLogSg(UrlInfo)),sysLogConfig,SLOT(doUpdateWgt(UrlInfo)));
    connect(this,SIGNAL(eventSg(UrlInfo)),eventConfig,SLOT(doUpdateWgt(UrlInfo)));
    connect(this,SIGNAL(videoImgSg(UrlInfo)),videoImgConfig,SLOT(doUpdateWgt(UrlInfo)));
}
void DevConfig::createListWidgetIcons()
{
    QListWidgetItem *configButton1 = new QListWidgetItem(cfgListWidget);
    configButton1->setIcon(QIcon(":/images/devInfo.png"));
    configButton1->setText(tr("设备信息"));
    configButton1->setTextAlignment(Qt::AlignHCenter);
    configButton1->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    //connect(configButton1,)

    QListWidgetItem *configButton2 = new QListWidgetItem(cfgListWidget);
    configButton2->setIcon(QIcon(":/images/timSet.png"));
    configButton2->setText(tr("时间设置"));
    configButton2->setTextAlignment(Qt::AlignHCenter);
    configButton2->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *configButton3 = new QListWidgetItem(cfgListWidget);
    configButton3->setIcon(QIcon(":/images/devMan.png"));
    configButton3->setText(tr("设备维护"));
    configButton3->setTextAlignment(Qt::AlignHCenter);
    configButton3->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *configButton4 = new QListWidgetItem(cfgListWidget);
    configButton4->setIcon(QIcon(":/images/netSet.png"));
    configButton4->setText(tr("网络设置"));
    configButton4->setTextAlignment(Qt::AlignHCenter);
    configButton4->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *configButton5 = new QListWidgetItem(cfgListWidget);
    configButton5->setIcon(QIcon(":/images/usrMng.png"));
    configButton5->setText(tr("用户管理"));
    configButton5->setTextAlignment(Qt::AlignHCenter);
    configButton5->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *configButton6 = new QListWidgetItem(cfgListWidget);
    configButton6->setIcon(QIcon(":/images/usrCert.png"));
    configButton6->setText(tr("用户授权"));
    configButton6->setTextAlignment(Qt::AlignHCenter);
    configButton6->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *configButton7 = new QListWidgetItem(cfgListWidget);
    configButton7->setIcon(QIcon(":/images/sysLog.png"));
    configButton7->setText(tr("系统日志"));
    configButton7->setTextAlignment(Qt::AlignHCenter);
    configButton7->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *configButton8 = new QListWidgetItem(cfgListWidget);
    configButton8->setIcon(QIcon(":/images/event.png"));
    configButton8->setText(tr("事件展示"));
    configButton8->setTextAlignment(Qt::AlignHCenter);
    configButton8->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *configButton9 = new QListWidgetItem(cfgListWidget);
    configButton9->setIcon(QIcon(":/images/vdImg.png"));
    configButton9->setText(tr("视频图像"));
    configButton9->setTextAlignment(Qt::AlignHCenter);
    configButton9->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

}
void DevConfig::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
    int rowIndex;
    QVariant variant;
    UrlInfo info;
    if (!current)
        current = previous;

    rowIndex = cfgListWidget->row(current);
    stackedLayout->setCurrentIndex(rowIndex);
    variant = camereComboBox->currentData();
    info = variant.value<UrlInfo>();
//    if(rowIndex == 0)
//    {
//        emit devinfoSg(info.type,info.url);
//    }
    switch(rowIndex)
    {
    case 0:
    {
        emit devinfoSg(info);
    }break;
    case 1:
    {
        emit timesetSg(info);
    }break;
    case 2:
    {
        emit mainTenceSg(info);
    }break;
    case 3:
    {
        emit netWorkSg(info);
    }break;
    case 4:
    {
        emit userMngSg(info);
    }break;
    case 5:
    {
        emit certifSg(info);
    }break;
    case 6:
    {
        emit sysLogSg(info);
    }break;
    case 7:
    {
        emit eventSg(info);
    }break;
    case 8:
    {
        emit videoImgSg(info);
    }break;
    }
}
void DevConfig::currentShowIndex()
{
    int rowIndex =  cfgListWidget->currentRow();
    UrlInfo info = camereComboBox->currentData().value<UrlInfo>();
    switch(rowIndex)
    {
    case 0:
    {
        emit devinfoSg(info);
    }break;
    case 1:
    {
        emit timesetSg(info);
    }break;
    case 2:
    {
        emit mainTenceSg(info);
    }break;
    case 3:
    {
        emit netWorkSg(info);
    }break;
    case 4:
    {
        emit userMngSg(info);
    }break;
    case 5:
    {
        emit certifSg(info);
    }break;
    case 6:
    {
        emit sysLogSg(info);
    }break;
    case 7:
    {
        emit eventSg(info);
    }break;
    case 8:
    {
        emit videoImgSg(info);
    }break;
    }
}
