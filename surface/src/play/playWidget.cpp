#include "playWidget.h"
#include "commonDef.h"
//rtsp://user:pass@192.168.9.63/onvif-media/media.amp?profile=profile_1_h264&sessiontimeout=60&streamtype=unicast
//rtsp://user:pass@192.168.9.63/onvif-media/media.amp?profile=profile_1_h264&sessiontimeout=60&streamtype=unicast
ListWidgetUrl::ListWidgetUrl(QWidget *parent)
    : QListWidget(parent)
{
    setAcceptDrops(true);
}

void ListWidgetUrl::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        startPos = event->pos();
    QListWidget::mousePressEvent(event);
}

void ListWidgetUrl::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        int distance = (event->pos() - startPos).manhattanLength();
        if (distance >= QApplication::startDragDistance())
            performDrag();
    }
    QListWidget::mouseMoveEvent(event);
}

void ListWidgetUrl::dragEnterEvent(QDragEnterEvent *event)
{
    ListWidgetUrl *source = qobject_cast<ListWidgetUrl *>(event->source());
    if (source && source != this) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void ListWidgetUrl::dragMoveEvent(QDragMoveEvent *event)
{
    ListWidgetUrl *source = qobject_cast<ListWidgetUrl *>(event->source());
    if (source && source != this) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void ListWidgetUrl::dropEvent(QDropEvent *event)
{
    ListWidgetUrl *source = qobject_cast<ListWidgetUrl *>(event->source());
    if (source && source != this) {
        addItem(event->mimeData()->text());
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void ListWidgetUrl::performDrag()
{
    QVariant variant;
    UrlInfo info;
    QString strUrlInfo;
    QListWidgetItem *item = currentItem();
    if (item)
    {
        variant = item->data(Qt::UserRole);
        info = variant.value<UrlInfo>();
        strUrlInfo.sprintf("%s\n%s\n%s\n%s",\
                           info.type.toLatin1().data(),info.url.toLatin1().data(),\
                           info.user.toLatin1().data(),info.passWord.toLatin1().data());
        QMimeData *mimeData = new QMimeData;
        mimeData->setText(strUrlInfo);

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        drag->setPixmap(QPixmap(":/images/drag.png"));
        if (drag->exec(Qt::MoveAction) == Qt::MoveAction)
        {
            //  delete item;
        }
    }
#if 0
//    QVariant variant;
//    UrlInfo info;
//    QListWidgetItem *item = currentItem();
//    variant = item->data(Qt::UserRole);
//    info = variant.value<UrlInfo>();
//    if (item) {
//        QMimeData *mimeData = new QMimeData;
//        mimeData->setText(item->text());

//        QDrag *drag = new QDrag(this);
//        drag->setMimeData(mimeData);
//        drag->setPixmap(QPixmap(":/images/drag.png"));
//        if (drag->exec(Qt::MoveAction) == Qt::MoveAction)
//        {
//          //  delete item;
//        }
//    }
#endif
}
playWidget::playWidget(QWidget *parent):QWidget(parent)
{
    ptpicWin04 = new picWindow04;
    ptpicWin09 = new picWindow09;
    ptpicWin17 = new picWindow17;
    stackedLayout = new QStackedLayout;
    deviceListLabel = new QLabel("Device list");
    listWidget = new ListWidgetUrl;
    listWidget->setSpacing(3);
    stackedLayout->addWidget(ptpicWin04);
    stackedLayout->addWidget(ptpicWin09);
    stackedLayout->addWidget(ptpicWin17);

    addBtn = new QPushButton("add");
    refreshBtn = new QPushButton("refresh");
    logBtn = new QPushButton("Log in");
    addNerUrlDialog = new addNewDlg;
    addNerUrlDialog->setModal(true);
    addNerUrlDialog->hide();
    logDlg = new LoginDlg;
    logDlg->setModal(true);
    logDlg->hide();
    QHBoxLayout *mainLayout = new QHBoxLayout;
    QGridLayout *leftLayout = new QGridLayout;
    setContentsMargins(0,0,0,0);
    leftLayout->addWidget(listWidget,0,0,1,3);
    leftLayout->addWidget(logBtn,1,0);
    leftLayout->addWidget(addBtn,1,1);
    leftLayout->addWidget(refreshBtn,1,2);

    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(stackedLayout,0);
    setLayout(mainLayout);
    stackedLayout->setCurrentIndex(2);

    connect(addBtn, SIGNAL(clicked(bool)),this, SLOT(addBtnStHdl(bool)));
    connect(logBtn,SIGNAL(clicked(bool)),this, SLOT(logBtnStHdl(bool)));
    connect(addNerUrlDialog,SIGNAL(applyBtnSgHdl(QString,QString)),this,SLOT(addNewUrlStHdl(QString,QString)));
    connect(refreshBtn,SIGNAL(clicked()),this,SLOT(refreshBtnstHdl()));
    connect(&disThread,SIGNAL(FindNewItemSg(QString,QString)),this,SLOT(addNewUrlStHdl(QString,QString)));
}
void playWidget::addBtnStHdl(bool)
{
    addNerUrlDialog->show();
}
void playWidget::logBtnStHdl(bool)
{
//    QVariant variant;
//    UrlInfo info;
//    QListWidgetItem *item = listWidget->currentItem();
//    variant = item->data(Qt::UserRole);
//    info = variant.value<UrlInfo>();
//    logDlg->devTypeEdit->setText(info.type);
//    logDlg->devUrlEdit->setText(info.url);
//    logDlg->show();
    QListWidgetItem *item = listWidget->currentItem();
    logDlg->setRefItem(item);
    logDlg->show();
}
void playWidget::addNewUrlStHdl(QString type, QString url)
{
//    QString newStrUrl;
//    newStrUrl.sprintf("%s\n%s",type.toLatin1().data(),url.toLatin1().data());
//    listWidget->addItem(newStrUrl);
    QString newStrUrl;
    QVariant variant;
    newStrUrl.sprintf("%s\n%s",type.toLatin1().data(),url.toLatin1().data());
    QListWidgetItem *item = new QListWidgetItem;
    item->setText(newStrUrl);

    variant.setValue(UrlInfo(type,url,"none","none"));
    item->setData(Qt::UserRole,variant);
    listWidget->addItem(item);

}
void playWidget::refreshBtnstHdl()
{

    if(disThread.isRunning())
    {
        //disThread.stop();
        return;
    }
    //vectItems.clear();
    listWidget->clear();
    disThread.start();
//    if(disThread.isFinished())
//    {
//        disThread.start();
//    }
}
DiscoveryThread::DiscoveryThread(QObject *parent) :
    QThread(parent)
{
    stopped = false;
}
void DiscoveryThread::setDisRef()
{

}
void DiscoveryThread::run()
{
#define ClientPoint "soap.udp://239.255.255.250:3702/datagram"
#define CLIENTWSATO "urn:schemas-xmlsoap-org:ws:2005:04:discovery"
#define CLIENTACTION "http://schemas.xmlsoap.org/ws/2005/04/discovery/Probe"
    QVector<QString> vectItems;
    vectItems.clear();
    emit ClearALLItemSg();
    while(!stopped)
    {
        int ret = 0;
        wsddProxy myProxy;
        myProxy.soap_endpoint = ClientPoint;
        myProxy.soap_header(NULL, const_cast<char *>(soap_wsa_rand_uuid((soap *)&myProxy)),
                            NULL, NULL, NULL, NULL, CLIENTWSATO, CLIENTACTION, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

        wsdd__ProbeType wsdd__Probe = {0};
        __wsdd__ProbeMatches wsdd_ProbeMatchs = {0};
        ret = myProxy.send_Probe(&wsdd__Probe);
        if(ret < 0)
        {
            //printf("ret = %d\n",ret);
            myProxy.destroy();
            break;
        }
        myProxy.recv_timeout = 5;
        while(1)
        {
            ret = myProxy.recv_ProbeMatches(wsdd_ProbeMatchs);
            if(ret != SOAP_OK)
            {
                stopped = true;
                break;
            }
            if(wsdd_ProbeMatchs.wsdd__ProbeMatches != NULL)
            {
                for(int i = 0;i < wsdd_ProbeMatchs.wsdd__ProbeMatches->__sizeProbeMatch;++i)
                {
                    // cout << "addr = "<<wsdd_ProbeMatchs.wsdd__ProbeMatches->ProbeMatch[i].XAddrs<<endl;
                    //newStrUrl.sprintf("%s\n%s","onvif",wsdd_ProbeMatchs.wsdd__ProbeMatches->ProbeMatch[i].XAddrs);
                    QString newStrUrl;
                    newStrUrl.sprintf("%s",wsdd_ProbeMatchs.wsdd__ProbeMatches->ProbeMatch[i].XAddrs);
                    int urlNumber = newStrUrl.count(' ');
                    for(int i = 0;i <= urlNumber;++i)
                    {
                        QString urlSec = newStrUrl.section(' ',i,i);
                        if(urlSec.contains("http://169"))
                        {
                            continue;
                        }
                        if(vectItems.contains(urlSec))
                            continue;
                        vectItems.append(urlSec);
                        emit FindNewItemSg("onvif",urlSec);
                    }
                }
            }
        }
        myProxy.destroy();
       // stopped = true;
    }
    stopped = false;
}


void DiscoveryThread::stop()
{
    stopped = true;
}
