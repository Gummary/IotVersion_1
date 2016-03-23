#include <QtGui/QApplication>
#include "mainwindow.h"
#include "clock.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //Clock c;
    //c.show();
    return a.exec();
}
