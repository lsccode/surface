//#include "analyCfg.h"

//AnalyCfg::AnalyCfg(QWidget *parent):QWidget(parent)
//{
//    cameralabel = new QLabel("Select Camrer");
//    camereComboBox = new ComboBoxUrl;
//    //cameralabel->setMargin(10);
////    camereComboBox->addItem("Please push here and then select the camera from the list!");
//    analyListWdt = new QListWidget;
//    analyStackWgt = new QStackedWidget;

//    intraCfg = new IntraCfg;
//    passCfg = new PassCfg;

////    intraCfg->playWidget->setCurImage("intra.jpg");
////    passCfg->playWidget->setCurImage("pass.jpg");
//    analyListWdt->setViewMode(QListView::IconMode);
//    analyListWdt->setIconSize(QSize(32, 32));
//    analyListWdt->setMovement(QListView::Static);
//    analyListWdt->setMaximumWidth(80);
//    analyListWdt->setSpacing(5);
//    createListWidgetIcons();

//    analyStackWgt->addWidget(intraCfg);
//    analyStackWgt->addWidget(passCfg);

//    QGridLayout *layoutRight = new QGridLayout;
//    layoutRight->addWidget(cameralabel,0,0);
//    layoutRight->addWidget(camereComboBox,0,1);
//    layoutRight->setColumnStretch(1,1);
//    layoutRight->addWidget(analyStackWgt,1,0,1,2);
//    QHBoxLayout *layoutMain = new QHBoxLayout;
//    layoutMain->addWidget(analyListWdt);
//    layoutMain->addLayout(layoutRight);
//    setLayout(layoutMain);
//    analyListWdt->setCurrentRow(0);

//}
//void AnalyCfg::createListWidgetIcons()
//{
//    QListWidgetItem *configButton1 = new QListWidgetItem(analyListWdt);
//    configButton1->setIcon(QIcon(":/images/intra.png"));
//    configButton1->setText(tr("闯入分析"));
//    configButton1->setTextAlignment(Qt::AlignHCenter);
//    configButton1->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

//    QListWidgetItem *configButton2 = new QListWidgetItem(analyListWdt);
//    configButton2->setIcon(QIcon(":/images/pass.png"));
//    configButton2->setText(tr("越界侦测"));
//    configButton2->setTextAlignment(Qt::AlignHCenter);
//    configButton2->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

////    QListWidgetItem *configButton3 = new QListWidgetItem(analyListWdt);
////    configButton3->setIcon(QIcon(":/images/devMan.png"));
////    configButton3->setText(tr("设备维护"));
////    configButton3->setTextAlignment(Qt::AlignHCenter);
////    configButton3->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

////    QListWidgetItem *configButton4 = new QListWidgetItem(analyListWdt);
////    configButton4->setIcon(QIcon(":/images/netSet.png"));
////    configButton4->setText(tr("网络设置"));
////    configButton4->setTextAlignment(Qt::AlignHCenter);
////    configButton4->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

////    QListWidgetItem *configButton5 = new QListWidgetItem(analyListWdt);
////    configButton5->setIcon(QIcon(":/images/usrMng.png"));
////    configButton5->setText(tr("用户管理"));
////    configButton5->setTextAlignment(Qt::AlignHCenter);
////    configButton5->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

////    QListWidgetItem *configButton6 = new QListWidgetItem(analyListWdt);
////    configButton6->setIcon(QIcon(":/images/usrCert.png"));
////    configButton6->setText(tr("用户授权"));
////    configButton6->setTextAlignment(Qt::AlignHCenter);
////    configButton6->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

////    QListWidgetItem *configButton7 = new QListWidgetItem(analyListWdt);
////    configButton7->setIcon(QIcon(":/images/sysLog.png"));
////    configButton7->setText(tr("系统日志"));
////    configButton7->setTextAlignment(Qt::AlignHCenter);
////    configButton7->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

////    QListWidgetItem *configButton8 = new QListWidgetItem(analyListWdt);
////    configButton8->setIcon(QIcon(":/images/event.png"));
////    configButton8->setText(tr("事件展示"));
////    configButton8->setTextAlignment(Qt::AlignHCenter);
////    configButton8->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

////    QListWidgetItem *configButton9 = new QListWidgetItem(analyListWdt);
////    configButton9->setIcon(QIcon(":/images/vdImg.png"));
////    configButton9->setText(tr("视频图像"));
////    configButton9->setTextAlignment(Qt::AlignHCenter);
////    configButton9->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

//    connect(analyListWdt,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
//            this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));
//}
//void AnalyCfg::changePage(QListWidgetItem *current, QListWidgetItem *previous)
//{
//    if (!current)
//        current = previous;

//    analyStackWgt->setCurrentIndex(analyListWdt->row(current));
//}
