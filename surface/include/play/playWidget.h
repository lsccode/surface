#ifndef PlAYWIDGET_H
#define PlAYWIDGET_H
#include "commonHeader.h"
#include "picwindow.h"
#include "multWindow.h"
#include "addnewdlg.h"
//class addNewDlg;
class playWidget;
class DiscoveryThread;
class ListWidgetUrl:public QListWidget
{
    Q_OBJECT

public:
    ListWidgetUrl(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);

private:
    void performDrag();

    QPoint startPos;
};
class addNewDlg:public QDialog
{
Q_OBJECT
public:
    addNewDlg(QWidget *parent = 0);
    QLabel *devTypeLabel;
    QComboBox *devTypeCbx;
    QLabel *devUrlLabel;
    QLineEdit *devurlEdit;
    QPushButton *applyBtn;
    QPushButton *cancelBtn;

    playWidget *play;
public slots:
    void applyFun(bool);
    void cancelFun(bool);
public:
    void setplayWidget(QObject *qobj);
signals:
    void applyBtnSgHdl(QString type,QString url);
protected:
    void paintEvent(QPaintEvent *event);
};
class DiscoveryThread : public QThread
{
    Q_OBJECT
public:
    explicit DiscoveryThread(QObject *parent = 0);
    void setDisRef();
    void stop();
protected:
    void run();
private:
    volatile bool stopped;

signals:
    void FindNewItemSg(QString type,QString url);
    void ClearALLItemSg();
public slots:

};
class LoginDlg:public QDialog
{
Q_OBJECT
public:
    LoginDlg(QDialog *parent = 0);
private:
    QLabel *devType;
    QLabel *devUrl;
    QLabel *devUser;
    QLabel *devPass;
    QLineEdit *devTypeEdit;
    QLineEdit *devUrlEdit;
    QLineEdit *devUserEdit;
    QLineEdit *devPassEdit;
    QPushButton *applyBtn;
    QPushButton *cancelBtn;
    QListWidgetItem *item;
public slots:
    void applyFun(bool);
    void cancelFun(bool);
private:
    void setUserInfo();
public:
    void setRefItem(QListWidgetItem *item);
signals:
    void modItemSgHdl(UrlInfo info);
};
class playWidget : public QWidget
{
    Q_OBJECT

public:
    playWidget(QWidget *parent = 0);
    picWindow04 *ptpicWin04;
    picWindow09 *ptpicWin09;
    picWindow17 *ptpicWin17;
    QStackedLayout *stackedLayout;
    QLabel      *deviceListLabel;
    ListWidgetUrl *listWidget;
    QPushButton *addBtn;
    QPushButton *refreshBtn;
    QPushButton *logBtn;
    addNewDlg *addNerUrlDialog;
    LoginDlg *logDlg;
    DiscoveryThread disThread;
//    QVector<QString> vectItems;
public slots:
    void addBtnStHdl(bool);
    void logBtnStHdl(bool);
    void addNewUrlStHdl(QString type,QString url);
    void refreshBtnstHdl();


};

#endif // PICWINDOW_H
