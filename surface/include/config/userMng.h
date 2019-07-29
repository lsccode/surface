#ifndef USERMNG_H
#define USERMNG_H
#include "commonHeader.h"
#include "commonDef.h"
class AddUserDialog:public QDialog
{
    Q_OBJECT
public:
    AddUserDialog(QDialog *parent = 0);
    QLabel *user;
    QLabel *password;
    QLabel *rol;
    QLineEdit *userEdit;
    QLineEdit *passEdit;
    QComboBox *rolCbx;
    QPushButton *apply;
    QPushButton *cancel;
signals:
    void doApplySg(QString,QString,QString);
public slots:
    void doApplySt();
    void doCancelSt();
};
class UserMng:public QWidget
{
    Q_OBJECT
public:
    UserMng(QWidget *parent = 0);
    QLabel *policy;
    QPushButton *backupBtn;
    QPushButton *restoreBtn;
    QPushButton *createBtn;
    QPushButton *modifyBtn;
    QPushButton *deleteBtn;
    AddUserDialog *addUserDlg;
    QLabel *userList;
    QTableWidget *userTable;
public slots:
    void doUpdateWgt(UrlInfo info);
    void doCreateSt();
    void doModifySt();
    void doDeleteSt();
    void doAddUserSt(QString user,QString pass,QString rol);
private:
    QString devType;
    QString devUrl;
    UrlInfo info;
};
#endif // USERMNG_H
