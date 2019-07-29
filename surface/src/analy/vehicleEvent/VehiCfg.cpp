#include "vehicleEvent/VehiCfg.h"

VehiCfg::VehiCfg(QWidget *parent):QWidget(parent)
{
    cameralabel = new QLabel("Select Camrer");
    camereComboBox = new ComboBoxUrl;
    analyListWdt = new QListWidget;
    analyStackWgt = new QStackedWidget;

    analyListWdt->setViewMode(QListView::IconMode);
    analyListWdt->setIconSize(QSize(32, 32));
    analyListWdt->setMovement(QListView::Static);
    analyListWdt->setMaximumWidth(80);
    analyListWdt->setSpacing(5);
    createListWidgetIcons();

//    analyStackWgt->addWidget(intraCfg);
//    analyStackWgt->addWidget(passCfg);

    QGridLayout *layoutRight = new QGridLayout;
    layoutRight->addWidget(cameralabel,0,0);
    layoutRight->addWidget(camereComboBox,0,1);
    layoutRight->setColumnStretch(1,1);
    layoutRight->addWidget(analyStackWgt,1,0,1,2);
    QHBoxLayout *layoutMain = new QHBoxLayout;
    layoutMain->addWidget(analyListWdt);
    layoutMain->addLayout(layoutRight);
    setLayout(layoutMain);
    analyListWdt->setCurrentRow(0);

}
void VehiCfg::createListWidgetIcons()
{
    QListWidgetItem *configButton1 = new QListWidgetItem(analyListWdt);
    configButton1->setIcon(QIcon(":/images/intra.png"));
    configButton1->setText(tr("闯入分析"));
    configButton1->setTextAlignment(Qt::AlignHCenter);
    configButton1->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem *configButton2 = new QListWidgetItem(analyListWdt);
    configButton2->setIcon(QIcon(":/images/pass.png"));
    configButton2->setText(tr("越界侦测"));
    configButton2->setTextAlignment(Qt::AlignHCenter);
    configButton2->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    connect(analyListWdt,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));
}
void VehiCfg::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current)
        current = previous;

    analyStackWgt->setCurrentIndex(analyListWdt->row(current));
}
