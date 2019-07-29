#ifndef STATICCFG_H
#define STATICCFG_H
#include "commonHeader.h"
#include "commonDef.h"
class StaticCfg:public QWidget
{
    Q_OBJECT
public:
    StaticCfg(QWidget *parent = 0);
    void createListWidgetIcons();

    QLabel *cameralabel;
    ComboBoxUrl *camereComboBox;
    QListWidget *analyListWdt;
    QStackedWidget *analyStackWgt;

private slots:
//    void changePage(QListWidgetItem *current, QListWidgetItem *previous);
};
#endif // STATICCFG_H
