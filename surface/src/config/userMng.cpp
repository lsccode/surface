#include "userMng.h"

UserMng::UserMng(QWidget *parent):QWidget(parent)
{
    policy = new QLabel("Policies");
    backupBtn = new QPushButton("Backup");
    restoreBtn = new QPushButton("Restore");
    userList = new QLabel("User list");
    userTable = new QTableWidget(0, 3);
    createBtn = new QPushButton("Create");
    modifyBtn = new QPushButton("Modify");
    deleteBtn = new QPushButton("Delete");
    addUserDlg = new AddUserDialog;
    QHBoxLayout *layoutbtn = new QHBoxLayout;
    QHBoxLayout *layoutPobtn = new QHBoxLayout;

    addUserDlg->hide();

    userTable->setHorizontalHeaderLabels(QStringList() << tr("Name") << tr("PassWord")<<tr("Role"));

   // userTable->add
    layoutbtn->addWidget(createBtn);
    layoutbtn->addWidget(modifyBtn);
    layoutbtn->addWidget(deleteBtn);
    layoutPobtn->addWidget(backupBtn);
    layoutPobtn->addWidget(restoreBtn);

    QGridLayout *layoutGrid = new QGridLayout;
    layoutGrid->addWidget(policy,0,0);
    layoutGrid->addLayout(layoutPobtn,0,2);
    layoutGrid->addWidget(userList,1,0);
    layoutGrid->addWidget(userTable,2,0,1,20);
    layoutGrid->addLayout(layoutbtn,3,2,1,1);

    QVBoxLayout *layoutInter = new QVBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();

    QHBoxLayout *layoutmain = new QHBoxLayout;
    layoutmain->addLayout(layoutInter);
    layoutmain->addStretch();

    setLayout(layoutmain);

    //connect(addUserDlg)
    connect(createBtn,SIGNAL(clicked()),this,SLOT(doCreateSt()));
    connect(deleteBtn,SIGNAL(clicked()),this,SLOT(doDeleteSt()));
    connect(addUserDlg,SIGNAL(doApplySg(QString,QString,QString)),this,SLOT(doAddUserSt(QString, QString, QString)));

}
void UserMng::doUpdateWgt(UrlInfo info)
{
    this->info = info;
    if(info.type == "onvif")
    {
        int ret = SOAP_ERR;
        TimeDateUser syncTime;
        DeviceBindingProxy deviceMg;
        std::string strUrl = info.url.toStdString();
        std::string strUsr = info.user.toStdString();
        std::string strPass = info.passWord.toStdString();
        deviceMg.soap_endpoint = strUrl.c_str();

        _tds__GetUsers reqGetUsers;
        _tds__GetUsersResponse resGetUsers;
        _tds__GetSystemDateAndTime reqGetSystemDateAndTime;
        _tds__GetSystemDateAndTimeResponse resGetSystemDateAndTime;
        ret = deviceMg.GetSystemDateAndTime(&reqGetSystemDateAndTime, &resGetSystemDateAndTime);
        if(ret != SOAP_OK)
        {
            return;
        }
        syncTime.setTimeDate(resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Date->Year,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Date->Month,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Date->Day,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Time->Hour,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Time->Minute,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Time->Second,
                             0);
        if(info.user != "none" && info.passWord != "none")
        {
            soap_wsse_add_UsernameTokenDigestCreated((soap *)&deviceMg, "User",
                                                     strUsr.c_str(),strPass.c_str(),syncTime.created());
        }
        ret = deviceMg.GetUsers(&reqGetUsers,&resGetUsers);
        if(ret != SOAP_OK)
        {
            return;
        }
        if(resGetUsers.__sizeUser > 0 && resGetUsers.User != NULL)
        {
            tt__User **User = resGetUsers.User;

            int row = userTable->rowCount();
            for(int j = 0;j < row;++j)
            {
                //userTable->rowCount()
                userTable->removeRow(userTable->rowCount()-1);
            }
            userTable->clearContents();

            for(int i = 0 ;i < resGetUsers.__sizeUser;++i)
            {
                if(User[i] != NULL)
                {
                    userTable->insertRow(i);
                    QTableWidgetItem *item0 = new QTableWidgetItem;
                    item0->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
                    userTable->setItem(i, 0, item0);

                    QTableWidgetItem *item1 = new QTableWidgetItem;
                    item1->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
                    userTable->setItem(i, 1, item1);

                    QTableWidgetItem *item2 = new QTableWidgetItem;
                    item2->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
                    userTable->setItem(i, 2, item2);

                    userTable->item(i,0)->setText(User[i]->Username);
                    userTable->item(i,1)->setText(User[i]->Password);
                    if(User[i]->UserLevel == tt__UserLevel__Administrator)
                    {
                        userTable->item(i,2)->setText("Administrator");
                    }
                    else if(User[i]->UserLevel == tt__UserLevel__Operator)
                    {
                        userTable->item(i,2)->setText("Operator");
                    }
                    else if(User[i]->UserLevel == tt__UserLevel__User)
                    {
                        userTable->item(i,2)->setText("User");
                    }
                    else
                    {
                         userTable->item(i,2)->setText("Other");
                    }

                }

            }
        }
        deviceMg.destroy();
    }
}
void UserMng::doCreateSt()
{
    addUserDlg->show();
}
void UserMng::doAddUserSt(QString user, QString pass, QString rol)
{
    int row = userTable->rowCount();

    userTable->insertRow(row);

    userTable->insertRow(row);
    QTableWidgetItem *item0 = new QTableWidgetItem;
    item0->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    userTable->setItem(row, 0, item0);

    QTableWidgetItem *item1 = new QTableWidgetItem;
    item1->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    userTable->setItem(row, 1, item1);

    QTableWidgetItem *item2 = new QTableWidgetItem;
    item2->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    userTable->setItem(row, 2, item2);
    userTable->item(row,0)->setText(user);
    userTable->item(row,1)->setText(pass);
    userTable->item(row,2)->setText(rol);
    if(info.type == "onvif")
    {
#if 1
        int ret = SOAP_ERR;
        TimeDateUser syncTime;
        DeviceBindingProxy deviceMg;
        std::string strUrl = info.url.toStdString();
        std::string strUsr = info.user.toStdString();
        std::string strPass = info.passWord.toStdString();
        _tds__CreateUsers reqCreateUsers;
        _tds__CreateUsersResponse resCreateUsers;
        static tt__User User;
        tt__User *ptUser = &User;
        reqCreateUsers.__sizeUser = 1;
        reqCreateUsers.User = &ptUser;

        _tds__GetSystemDateAndTime reqGetSystemDateAndTime;
        _tds__GetSystemDateAndTimeResponse resGetSystemDateAndTime;
        deviceMg.soap_endpoint = strUrl.c_str();
        ret = deviceMg.GetSystemDateAndTime(&reqGetSystemDateAndTime, &resGetSystemDateAndTime);
        if(ret != SOAP_OK)
        {
            return;
        }
        syncTime.setTimeDate(resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Date->Year,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Date->Month,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Date->Day,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Time->Hour,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Time->Minute,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Time->Second,
                             0);
        {
            ptUser->Username = soap_strdup((soap *)&deviceMg,user.toStdString().c_str());
            ptUser->Password = soap_strdup((soap *)&deviceMg,pass.toStdString().c_str());
            ptUser->Extension = NULL;
            ptUser->__anyAttribute = NULL;
            ptUser->__item = NULL;
            if(rol == "Administrator")
            {
                ptUser->UserLevel = tt__UserLevel__Administrator;
            }
            else if(rol == "Operator")
            {
                ptUser->UserLevel = tt__UserLevel__Operator;
            }
            else if(rol == "User")
            {
                ptUser->UserLevel = tt__UserLevel__User;
            }

        }

        if(info.user != "none" && info.passWord != "none")
        {
            soap_wsse_add_UsernameTokenDigestCreated((soap *)&deviceMg, "User",
                                                     strUsr.c_str(),strPass.c_str(),syncTime.created());
        }
        ret = deviceMg.CreateUsers(&reqCreateUsers,&resCreateUsers);
        if(ret != SOAP_OK)
        {
            return;
        }

        deviceMg.destroy();
#endif
    }
}
void UserMng::doModifySt()
{

}
void UserMng::doDeleteSt()
{
    int currentRow = userTable->currentRow();
    QString strUser = userTable->item(currentRow,0)->text();
    std::string strtemp = strUser.toStdString();
    if(info.type == "onvif")
    {
        int ret = SOAP_ERR;
        TimeDateUser syncTime;
        DeviceBindingProxy deviceMg;
        std::string strUrl = info.url.toStdString();
        std::string strUsr = info.user.toStdString();
        std::string strPass = info.passWord.toStdString();
        _tds__DeleteUsers  reqDeleteUsers;
        _tds__DeleteUsersResponse resDeleteUsers;
        _tds__GetSystemDateAndTime reqGetSystemDateAndTime;
        _tds__GetSystemDateAndTimeResponse resGetSystemDateAndTime;
        deviceMg.soap_endpoint = strUrl.c_str();
        reqDeleteUsers.__sizeUsername = 1;
        char *tempUserName = strtemp.c_str();
        reqDeleteUsers.Username = &tempUserName;
        ret = deviceMg.GetSystemDateAndTime(&reqGetSystemDateAndTime, &resGetSystemDateAndTime);
        if(ret != SOAP_OK)
        {
            return;
        }
        syncTime.setTimeDate(resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Date->Year,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Date->Month,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Date->Day,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Time->Hour,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Time->Minute,
                             resGetSystemDateAndTime.SystemDateAndTime->UTCDateTime->Time->Second,
                             0);
        if(info.user != "none" && info.passWord != "none")
        {
            soap_wsse_add_UsernameTokenDigestCreated((soap *)&deviceMg, "User",
                                                     strUsr.c_str(),strPass.c_str(),syncTime.created());
        }
        ret = deviceMg.DeleteUsers(&reqDeleteUsers,&resDeleteUsers);
        if(ret != SOAP_OK)
        {
            return;
        }
        deviceMg.destroy();
        userTable->removeRow(currentRow);
    }

}
void AddUserDialog::doApplySt()
{
    emit doApplySg(userEdit->text(),passEdit->text(),rolCbx->currentText());
    hide();
}
void AddUserDialog::doCancelSt()
{
    userEdit->clear();
    passEdit->clear();
    rolCbx->setCurrentIndex(0);
    hide();
}
AddUserDialog::AddUserDialog(QDialog *parent):QDialog(parent)
{
    user = new QLabel("User");
    password = new QLabel("Password");
    rol = new QLabel("Rol");
    userEdit = new QLineEdit;
    passEdit = new QLineEdit;
    rolCbx = new QComboBox;
    rolCbx->addItem("Administrator");
    rolCbx->addItem("Operator");
    rolCbx->addItem("User");
    apply = new QPushButton("apply");
    cancel = new QPushButton("cancel");
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(user,0,0);
    layout->addWidget(userEdit,0,1);
    layout->addWidget(password,1,0);
    layout->addWidget(passEdit,1,1);
    layout->addWidget(rol,2,0);
    layout->addWidget(rolCbx,2,1);
    layout->addWidget(apply,3,0);
    layout->addWidget(cancel,3,1);

    setLayout(layout);

    connect(apply,SIGNAL(clicked()),this,SLOT(doApplySt()));
    connect(cancel,SIGNAL(clicked()),this,SLOT(doCancelSt()));

}
