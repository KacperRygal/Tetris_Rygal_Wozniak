#include "mainwindowtetris.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowTetris w;

    QObject::connect(&w,&MainWindowTetris::Zamknij,&a, &QApplication::quit);
    return a.exec();
}
