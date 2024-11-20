#include "mainwindow.h"

#include <QApplication>
#include <qdebug.h> // this is so you can print things to the console when debugging

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
