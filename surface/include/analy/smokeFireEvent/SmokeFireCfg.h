#ifndef SMOKEFIRECFG_H
#define SMOKEFIRECFG_H
#include "commonHeader.h"
#include "commonDef.h"
class SmokeFireCfg:public QWidget
{
    Q_OBJECT
public:
    SmokeFireCfg(QWidget *parent = 0);
    void createListWidgetIcons();

    QLabel *cameralabel;
    ComboBoxUrl *camereComboBox;
    QListWidget *analyListWdt;
    QStackedWidget *analyStackWgt;

private slots:
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);
};
#endif // SMOKEFIRECFG_H
