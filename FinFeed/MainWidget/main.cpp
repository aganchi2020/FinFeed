
#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Config c; // do not remove!
    MainWindow w;
    w.show();
    return a.exec();
}
