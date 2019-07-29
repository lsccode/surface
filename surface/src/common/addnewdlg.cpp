#include "addnewdlg.h"
#include "commonDef.h"
addNewDlg::addNewDlg(QWidget *parent):QDialog(parent)
{
    devTypeLabel = new QLabel("Device Type");
    devTypeCbx   = new QComboBox;
    devTypeCbx->addItem("onvif");
    devTypeCbx->addItem("gato");
    devTypeCbx->addItem("rtsp");
    devUrlLabel  = new QLabel("Url");
    devurlEdit   = new QLineEdit;
    applyBtn     = new QPushButton("apply");
    cancelBtn    = new QPushButton("cancel");
    devurlEdit->setClearButtonEnabled(true);
    QGridLayout *layoutGrid = new QGridLayout;
    layoutGrid->addWidget(devTypeLabel,0,0,1,1);
    layoutGrid->addWidget(devTypeCbx,0,1,1,2);
    layoutGrid->addWidget(devUrlLabel,1,0);
    layoutGrid->addWidget(devurlEdit,1,1,1,2);
    layoutGrid->addWidget(applyBtn,2,1,1,1);
    layoutGrid->addWidget(cancelBtn,2,2,1,1);
    setLayout(layoutGrid);
    connect(applyBtn,SIGNAL(clicked(bool)),this,SLOT(applyFun(bool)));
    connect(cancelBtn,SIGNAL(clicked(bool)),this,SLOT(cancelFun(bool)));

}
void addNewDlg::applyFun(bool)
{
    emit applyBtnSgHdl(devTypeCbx->currentText(),devurlEdit->text());
    hide();
}
void addNewDlg::cancelFun(bool)
{
    hide();
}
void addNewDlg::paintEvent(QPaintEvent *event)
{

}
LoginDlg::LoginDlg(QDialog *parent):QDialog(parent)
{
    devType     = new QLabel("type");
    devUrl      = new QLabel("url");
    devUser     = new QLabel("user");
    devPass     = new QLabel("password");
    devTypeEdit = new QLineEdit;devTypeEdit->setFixedWidth(320);
    devUrlEdit  = new QLineEdit;
    devUserEdit = new QLineEdit;
    devPassEdit = new QLineEdit;
    applyBtn     = new QPushButton("apply");
    cancelBtn    = new QPushButton("cancel");
    QGridLayout *layoutGrid = new QGridLayout;
    layoutGrid->addWidget(devType,0,0,1,1);
    layoutGrid->addWidget(devTypeEdit,0,1,1,2);
    layoutGrid->addWidget(devUrl,1,0);
    layoutGrid->addWidget(devUrlEdit,1,1,1,2);
    layoutGrid->addWidget(devUser,2,0);
    layoutGrid->addWidget(devUserEdit,2,1,1,2);
    layoutGrid->addWidget(devPass,3,0);
    layoutGrid->addWidget(devPassEdit,3,1,1,2);
    layoutGrid->addWidget(applyBtn,4,1,1,1);
    layoutGrid->addWidget(cancelBtn,4,2,1,1);
    setLayout(layoutGrid);

    connect(applyBtn,SIGNAL(clicked(bool)),this,SLOT(applyFun(bool)));
    connect(cancelBtn,SIGNAL(clicked(bool)),this,SLOT(cancelFun(bool)));
}
void LoginDlg::applyFun(bool)
{
    setUserInfo();
    hide();
}
void LoginDlg::cancelFun(bool)
{
    hide();
}
void LoginDlg::setUserInfo()
{
    QVariant variant = item->data(Qt::UserRole);
    UrlInfo info = variant.value<UrlInfo>();
    info.user = devUserEdit->text();
    info.passWord = devPassEdit->text();
    variant.setValue(info);
    item->setData(Qt::UserRole,variant);

    emit modItemSgHdl(info);
}
void LoginDlg::setRefItem(QListWidgetItem *item)
{
    this->item = NULL;
    this->item = item;
    if(this->item == NULL)
        return;
    QVariant variant = this->item->data(Qt::UserRole);
    UrlInfo info = variant.value<UrlInfo>();
    devTypeEdit->setText(info.type);
    devUrlEdit->setText(info.url);
}
