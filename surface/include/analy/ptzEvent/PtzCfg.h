#ifndef PTZCFG_H
#define PTZCFG_H
#include "commonHeader.h"
#include "commonDef.h"
class PtzCfg:public QWidget
{
    Q_OBJECT
public:
    PtzCfg(QWidget *parent = 0);
    void createListWidgetIcons();

    QLabel *cameralabel;
    ComboBoxUrl *camereComboBox;
    QListWidget *analyListWdt;
    QStackedWidget *analyStackWgt;

private slots:
//    void changePage(QListWidgetItem *current, QListWidgetItem *previous);
};
#endif // PTZCFG_H
