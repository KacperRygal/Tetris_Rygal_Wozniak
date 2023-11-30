#include "mainwindowtetris.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowTetris w;
    w.show();
    return a.exec();
}
