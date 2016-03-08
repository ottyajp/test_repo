#include "mainwindow.h"
#include <QApplication>

std::list<Web_test*> list;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
