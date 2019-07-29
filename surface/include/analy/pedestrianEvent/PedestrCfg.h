#ifndef PEDESTRCFG_H
#define PEDESTRCFG_H
#include "commonHeader.h"
#include "commonDef.h"
#include "pedestrianEvent/intra.h"
#include "pedestrianEvent/pass.h"
class PedestrCfg:public QWidget
{
    Q_OBJECT
public:
    PedestrCfg(QWidget *parent = 0);
    void createListWidgetIcons();

    QLabel *cameralabel;
    ComboBoxUrl *camereComboBox;
    QListWidget *analyListWdt;
    QStackedWidget *analyStackWgt;
    IntraCfg *intraCfg;
    PassCfg *passCfg;
private slots:
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);
};
#endif // PEDESTRCFG_H
