#include "certificate.h"

Certificate::Certificate(QWidget *parent):QWidget(parent)
{
//    setAutoFillBackground(true);
//    QPalette palette;
//    palette.setColor(QPalette::Background, QColor(7080,80));
//    setPalette(palette);
    certifLable = new QLabel("upload Certificate");
    uploadCertBtn = new QPushButton("upload...");
    //splitLine = new QLine;
    listCert = new QListWidget;
    applyBtn = new QPushButton("Apply");
    QGridLayout *layoutGrid = new QGridLayout;
    layoutGrid->addWidget(certifLable,0,0);
    layoutGrid->addWidget(uploadCertBtn,0,1);
    //layoutGrid->addWidget(splitLine,1,0,1,2);
    layoutGrid->addWidget(listCert,1,0,1,2);
    layoutGrid->addWidget(applyBtn,2,1);
    QHBoxLayout *layoutInter = new QHBoxLayout;
    layoutInter->addLayout(layoutGrid);
    layoutInter->addStretch();
    QVBoxLayout *layoutmain = new QVBoxLayout;
    layoutmain->addLayout(layoutInter);
    layoutmain->addStretch();
    setLayout(layoutmain);
}
