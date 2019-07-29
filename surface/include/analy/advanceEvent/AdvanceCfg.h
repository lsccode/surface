#ifndef ADVANCECFG_H
#define ADVANCECFG_H
#include "commonHeader.h"
#include "commonDef.h"
class AdvanceCfg:public QWidget
{
    Q_OBJECT
public:
    AdvanceCfg(QWidget *parent = 0);
    void createListWidgetIcons();

    QLabel *cameralabel;
    ComboBoxUrl *camereComboBox;
    QListWidget *analyListWdt;
    QStackedWidget *analyStackWgt;

private slots:
//    void changePage(QListWidgetItem *current, QListWidgetItem *previous);
};
#endif // ADVANCECFG_H
