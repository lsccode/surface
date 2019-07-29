#include "commonHeader.h"
#include "mainwindow.h"
//#include "mainwindow.h"
//#ifdef __MINGW32__
//#undef main /* Prevents SDL from overriding main() */
//#endif
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
