//#include "commonHeader.h"
#include <QApplication>
#include <QFile>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWin;
    QFile file(":/qss/app.qss");
    file.open(QFile::ReadOnly);
    app.setStyleSheet(file.readAll());
    mainWin.show();
    return app.exec();

}
