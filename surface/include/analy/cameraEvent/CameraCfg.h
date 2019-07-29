#ifndef CAMERACFG_H
#define CAMERACFG_H
#include "commonHeader.h"
#include "commonDef.h"
class CameraCfg:public QWidget
{
    Q_OBJECT
public:
    CameraCfg(QWidget *parent = 0);
    void createListWidgetIcons();

    QLabel *cameralabel;
    ComboBoxUrl *camereComboBox;
    QListWidget *analyListWdt;
    QStackedWidget *analyStackWgt;

private slots:
   void changePage(QListWidgetItem *current, QListWidgetItem *previous);
};
#endif // CAMERACFG_H
