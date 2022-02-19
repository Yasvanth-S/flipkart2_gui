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
    void slot_flipbot1_botcontrol();
    void slot_flipbot2_botcontrol();
    void slot_flipbot3_botcontrol();
    void slot_flipbot4_botcontrol();
    void slot_induct_1(int x);
    void slot_induct_2(int y);
    void slot_bot_1_lin_x(double x);
    void slot_bot_1_lin_y(double y);
    void slot_bot_1_ang_z(double z);
    void slot_bot_2_lin_x(double x);
    void slot_bot_2_lin_y(double y);
    void slot_bot_2_ang_z(double z);
    void slot_bot_3_lin_x(double x);
    void slot_bot_3_lin_y(double y);
    void slot_bot_3_ang_z(double z);
    void slot_bot_4_lin_x(double x);
    void slot_bot_4_lin_y(double y);
    void slot_bot_4_ang_z(double z);

private:
    Ui::MainWindow *ui;
    Rosnode bot_1;
    Rosnode bot_2;
    Rosnode bot_3;
    Rosnode bot_4;
    void connections();
};

#endif // MAINWINDOW_HPP

