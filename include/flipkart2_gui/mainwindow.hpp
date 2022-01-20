#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include <QMainWindow>
#include <QDebug>
#include <QObject>
#include <QString>
#include <QAbstractItemView>
#include "../flipkart2_gui/rosnode.hpp"
#include "ui_mainwindow.h"

namespace Ui{
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void logview();

public slots:
    void slot_pub_bot_1();
    void slot_pub_bot_2();
    void slot_pub_bot_3();
    void slot_pub_bot_4();
    void slot_srv_start_bot_1();
    void slot_srv_start_bot_2();
    void slot_srv_start_bot_3();
    void slot_srv_start_bot_4();
    void slot_srv_stop_bot_1();
    void slot_srv_stop_bot_2();
    void slot_srv_stop_bot_3();
    void slot_srv_stop_bot_4();
    void slot_induct_1(int x);
    void slot_induct_2(int y);

private:
    Ui::MainWindow *ui;
    Rosnode bot_1;
    Rosnode bot_2;
    Rosnode bot_3;
    Rosnode bot_4;
    void connections();
};

#endif // MAINWINDOW_HPP

