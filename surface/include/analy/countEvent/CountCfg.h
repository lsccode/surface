#ifndef COUNTCFG_H
#define COUNTCFG_H
#include "commonHeader.h"
#include "commonDef.h"
class CountCfg:public QWidget
{
    Q_OBJECT
public:
    CountCfg(QWidget *parent = 0);
    void createListWidgetIcons();

    QLabel *cameralabel;
    ComboBoxUrl *camereComboBox;
    QListWidget *analyListWdt;
    QStackedWidget *analyStackWgt;

private slots:
//    void changePage(QListWidgetItem *current, QListWidgetItem *previous);
};
#endif // COUNTCFG_H
