#include "../include/flipkart2_gui/mainwindow.hpp"
#include <QApplication>
#include <QtGui>
#include <QWidget>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

