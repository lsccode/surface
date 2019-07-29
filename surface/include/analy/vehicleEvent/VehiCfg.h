#ifndef VEHICFG_H
#define VEHICFG_H
#include "commonHeader.h"
#include "commonDef.h"
class VehiCfg:public QWidget
{
    Q_OBJECT
public:
    VehiCfg(QWidget *parent = 0);
    void createListWidgetIcons();

    QLabel *cameralabel;
    ComboBoxUrl *camereComboBox;
    QListWidget *analyListWdt;
    QStackedWidget *analyStackWgt;

private slots:
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);
};
#endif // VEHICFG_H
