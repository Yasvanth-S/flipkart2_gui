#include "../include/flipkart2_gui/mainwindow.hpp"

static const int size = 20;
static const QString green = QString("color: white;border-radius: %1;background-color: qlineargradient(spread:pad, x1:0.145, y1:0.16, x2:1, y2:1, stop:0 rgba(20, 252, 7, 255), stop:1 rgba(25, 134, 5, 255));").arg(size/2);
static const QString red = QString("color: white;border-radius: %1;background-color: qlineargradient(spread:pad, x1:0.145, y1:0.16, x2:0.92, y2:0.988636, stop:0 rgba(255, 12, 12, 255), stop:0.869347 rgba(103, 0, 0, 255));").arg(size/2);
MainWindow::MainWindow(QWidget *parent):QMainWindow (parent),ui(new Ui::MainWindow),bot_1(0,nullptr,"1"),bot_2(0,nullptr,"2"),bot_3(0,nullptr,"3"),bot_4(0,nullptr,"4")
{
    ui->setupUi(this);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listView_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listView_4->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listView->setModel(bot_1.loggingModel());
    ui->listView_2->setModel(bot_2.loggingModel());
    ui->listView_3->setModel(bot_3.loggingModel());
    ui->listView_4->setModel(bot_4.loggingModel());
    connections();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connections()
{
    connect(&bot_1, SIGNAL(param_1(int)),this,SLOT(slot_induct_1(int)));
    connect(&bot_1, SIGNAL(param_2(int)),this,SLOT(slot_induct_2(int)));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(slot_pub_bot_1()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(slot_pub_bot_1()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(slot_pub_bot_1()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(slot_pub_bot_1()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(slot_pub_bot_1()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(slot_pub_bot_1()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(slot_pub_bot_1()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(slot_pub_bot_1()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(slot_pub_bot_1()));
    connect(ui->pushButton_10, SIGNAL(clicked()), this, SLOT(slot_pub_bot_2()));
    connect(ui->pushButton_11, SIGNAL(clicked()), this, SLOT(slot_pub_bot_2()));
    connect(ui->pushButton_12, SIGNAL(clicked()), this, SLOT(slot_pub_bot_2()));
    connect(ui->pushButton_13, SIGNAL(clicked()), this, SLOT(slot_pub_bot_2()));
    connect(ui->pushButton_14, SIGNAL(clicked()), this, SLOT(slot_pub_bot_2()));
    connect(ui->pushButton_15, SIGNAL(clicked()), this, SLOT(slot_pub_bot_2()));
    connect(ui->pushButton_16, SIGNAL(clicked()), this, SLOT(slot_pub_bot_2()));
    connect(ui->pushButton_17, SIGNAL(clicked()), this, SLOT(slot_pub_bot_2()));
    connect(ui->pushButton_18, SIGNAL(clicked()), this, SLOT(slot_pub_bot_2()));
    connect(ui->pushButton_19, SIGNAL(clicked()), this, SLOT(slot_pub_bot_3()));
    connect(ui->pushButton_20, SIGNAL(clicked()), this, SLOT(slot_pub_bot_3()));
    connect(ui->pushButton_21, SIGNAL(clicked()), this, SLOT(slot_pub_bot_3()));
    connect(ui->pushButton_22, SIGNAL(clicked()), this, SLOT(slot_pub_bot_3()));
    connect(ui->pushButton_23, SIGNAL(clicked()), this, SLOT(slot_pub_bot_3()));
    connect(ui->pushButton_24, SIGNAL(clicked()), this, SLOT(slot_pub_bot_3()));
    connect(ui->pushButton_25, SIGNAL(clicked()), this, SLOT(slot_pub_bot_3()));
    connect(ui->pushButton_26, SIGNAL(clicked()), this, SLOT(slot_pub_bot_3()));
    connect(ui->pushButton_27, SIGNAL(clicked()), this, SLOT(slot_pub_bot_3()));
    connect(ui->pushButton_28, SIGNAL(clicked()), this, SLOT(slot_pub_bot_4()));
    connect(ui->pushButton_29, SIGNAL(clicked()), this, SLOT(slot_pub_bot_4()));
    connect(ui->pushButton_30, SIGNAL(clicked()), this, SLOT(slot_pub_bot_4()));
    connect(ui->pushButton_31, SIGNAL(clicked()), this, SLOT(slot_pub_bot_4()));
    connect(ui->pushButton_32, SIGNAL(clicked()), this, SLOT(slot_pub_bot_4()));
    connect(ui->pushButton_33, SIGNAL(clicked()), this, SLOT(slot_pub_bot_4()));
    connect(ui->pushButton_34, SIGNAL(clicked()), this, SLOT(slot_pub_bot_4()));
    connect(ui->pushButton_35, SIGNAL(clicked()), this, SLOT(slot_pub_bot_4()));
    connect(ui->pushButton_36, SIGNAL(clicked()), this, SLOT(slot_pub_bot_4()));
    connect(ui->pushButton_37, SIGNAL(clicked()), this, SLOT(slot_srv_start_bot_1()));
    connect(ui->pushButton_38, SIGNAL(clicked()), this, SLOT(slot_srv_stop_bot_1()));
    connect(ui->pushButton_39, SIGNAL(clicked()), this, SLOT(slot_srv_start_bot_2()));
    connect(ui->pushButton_40, SIGNAL(clicked()), this, SLOT(slot_srv_stop_bot_2()));
    connect(ui->pushButton_41, SIGNAL(clicked()), this, SLOT(slot_srv_start_bot_3()));
    connect(ui->pushButton_42, SIGNAL(clicked()), this, SLOT(slot_srv_stop_bot_3()));
    connect(ui->pushButton_43, SIGNAL(clicked()), this, SLOT(slot_srv_start_bot_4()));
    connect(ui->pushButton_44, SIGNAL(clicked()), this, SLOT(slot_srv_stop_bot_4()));
    connect(&bot_1, SIGNAL(lin_x_bot_1(double)),this,SLOT(slot_bot_1_lin_x(double)));
    connect(&bot_2, SIGNAL(lin_x_bot_2(double)),this,SLOT(slot_bot_2_lin_x(double)));
    connect(&bot_3, SIGNAL(lin_x_bot_3(double)),this,SLOT(slot_bot_3_lin_x(double)));
    connect(&bot_4, SIGNAL(lin_x_bot_4(double)),this,SLOT(slot_bot_4_lin_x(double)));
    connect(&bot_1, SIGNAL(lin_y_bot_1(double)),this,SLOT(slot_bot_1_lin_y(double)));
    connect(&bot_2, SIGNAL(lin_y_bot_2(double)),this,SLOT(slot_bot_2_lin_y(double)));
    connect(&bot_3, SIGNAL(lin_y_bot_3(double)),this,SLOT(slot_bot_3_lin_y(double)));
    connect(&bot_4, SIGNAL(lin_y_bot_4(double)),this,SLOT(slot_bot_4_lin_y(double)));
    connect(&bot_1, SIGNAL(ang_z_bot_1(double)),this,SLOT(slot_bot_1_ang_z(double)));
    connect(&bot_2, SIGNAL(ang_z_bot_2(double)),this,SLOT(slot_bot_2_ang_z(double)));
    connect(&bot_3, SIGNAL(ang_z_bot_3(double)),this,SLOT(slot_bot_3_ang_z(double)));
    connect(&bot_4, SIGNAL(ang_z_bot_4(double)),this,SLOT(slot_bot_4_ang_z(double)));
    connect(ui->pushButton_45, SIGNAL(clicked()), this, SLOT(slot_flipbot1_botcontrol()));
    connect(ui->pushButton_46, SIGNAL(clicked()), this, SLOT(slot_flipbot2_botcontrol()));
    connect(ui->pushButton_47, SIGNAL(clicked()), this, SLOT(slot_flipbot3_botcontrol()));
    connect(ui->pushButton_48, SIGNAL(clicked()), this, SLOT(slot_flipbot4_botcontrol()));
}

void MainWindow::slot_pub_bot_1()
{
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    char key = btn->text().toStdString()[0];
    switch(key)
    {
        case '1':
        bot_1.goalpub(1);
        ui->listView->scrollToBottom();
        break;

        case '2':
        bot_1.goalpub(2);
        ui->listView->scrollToBottom();
        break;

        case '3':
        bot_1.goalpub(3);
        ui->listView->scrollToBottom();
        break;

        case '4':
        bot_1.goalpub(4);
        ui->listView->scrollToBottom();
        break;

        case '5':
        bot_1.goalpub(5);
        ui->listView->scrollToBottom();
        break;

        case '6':
        bot_1.goalpub(6);
        ui->listView->scrollToBottom();
        break;

        case '7':
        bot_1.goalpub(7);
        ui->listView->scrollToBottom();
        break;

        case '8':
        bot_1.goalpub(8);
        ui->listView->scrollToBottom();
        break;

        case '9':
        bot_1.goalpub(9);
        ui->listView->scrollToBottom();
        break;
    }

}

void MainWindow::slot_pub_bot_2()
{
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    char key = btn->text().toStdString()[0];
    switch(key)
    {
        case '1':
        bot_2.goalpub(1);
        ui->listView_2->scrollToBottom();
        break;

        case '2':
        bot_2.goalpub(2);
        ui->listView_2->scrollToBottom();
        break;

        case '3':
        bot_2.goalpub(3);
        ui->listView_2->scrollToBottom();
        break;

        case '4':
        bot_2.goalpub(4);
        ui->listView_2->scrollToBottom();
        break;

        case '5':
        bot_2.goalpub(5);
        ui->listView_2->scrollToBottom();
        break;

        case '6':
        bot_2.goalpub(6);
        ui->listView_2->scrollToBottom();
        break;

        case '7':
        bot_2.goalpub(7);
        ui->listView_2->scrollToBottom();
        break;

        case '8':
        bot_2.goalpub(8);
        ui->listView_2->scrollToBottom();
        break;

        case '9':
        bot_2.goalpub(9);
        ui->listView_2->scrollToBottom();
        break;
    }

}

void MainWindow::slot_pub_bot_3()
{
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    char key = btn->text().toStdString()[0];
    switch(key)
    {
        case '1':
        bot_3.goalpub(1);
        ui->listView_3->scrollToBottom();
        break;

        case '2':
        bot_3.goalpub(2);
        ui->listView_3->scrollToBottom();
        break;

        case '3':
        bot_3.goalpub(3);
        ui->listView_3->scrollToBottom();
        break;

        case '4':
        bot_3.goalpub(4);
        ui->listView_3->scrollToBottom();
        break;

        case '5':
        bot_3.goalpub(5);
        ui->listView_3->scrollToBottom();
        break;

        case '6':
        bot_3.goalpub(6);
        ui->listView_3->scrollToBottom();
        break;

        case '7':
        bot_3.goalpub(7);
        ui->listView_3->scrollToBottom();
        break;

        case '8':
        bot_3.goalpub(8);
        ui->listView_3->scrollToBottom();
        break;

        case '9':
        bot_3.goalpub(9);
        ui->listView_3->scrollToBottom();
        break;
    }

}

void MainWindow::slot_pub_bot_4()
{
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    char key = btn->text().toStdString()[0];
    switch(key)
    {
        case '1':
        bot_4.goalpub(1);
        ui->listView_4->scrollToBottom();
        break;

        case '2':
        bot_4.goalpub(2);
        ui->listView_4->scrollToBottom();
        break;

        case '3':
        bot_4.goalpub(3);
        ui->listView_4->scrollToBottom();
        break;

        case '4':
        bot_4.goalpub(4);
        ui->listView_4->scrollToBottom();
        break;

        case '5':
        bot_4.goalpub(5);
        ui->listView_4->scrollToBottom();
        break;

        case '6':
        bot_4.goalpub(6);
        ui->listView_4->scrollToBottom();
        break;

        case '7':
        bot_4.goalpub(7);
        ui->listView_4->scrollToBottom();
        break;

        case '8':
        bot_4.goalpub(8);
        ui->listView_4->scrollToBottom();
        break;

        case '9':
        bot_4.goalpub(9);
        ui->listView_4->scrollToBottom();
        break;
    }

}

void MainWindow::slot_bot_1_lin_x(double x)
{
    if (x == 0)
    {
        ui->label_4->setStyleSheet(red);
    }
    else
    {
        ui->label_4->setStyleSheet(green);
    }
}

void MainWindow::slot_bot_2_lin_x(double x)
{
    if (x == 0)
    {
        ui->label_10->setStyleSheet(red);
    }
    else
    {
        ui->label_10->setStyleSheet(green);
    }
}

void MainWindow::slot_bot_3_lin_x(double x)
{
    if (x == 0)
    {
        ui->label_16->setStyleSheet(red);
    }
    else
    {
        ui->label_16->setStyleSheet(green);
    }
}

void MainWindow::slot_bot_4_lin_x(double x)
{
    if (x == 0)
    {
        ui->label_22->setStyleSheet(red);
    }
    else
    {
        ui->label_22->setStyleSheet(green);
    }
}

void MainWindow::slot_bot_1_lin_y(double x)
{
    if (x == 0)
    {
        ui->label_5->setStyleSheet(red);
    }
    else
    {
        ui->label_5->setStyleSheet(green);
    }
}

void MainWindow::slot_bot_2_lin_y(double x)
{
    if (x == 0)
    {
        ui->label_11->setStyleSheet(red);
    }
    else
    {
        ui->label_11->setStyleSheet(green);
    }
}

void MainWindow::slot_bot_3_lin_y(double x)
{
    if (x == 0)
    {
        ui->label_17->setStyleSheet(red);
    }
    else
    {
        ui->label_17->setStyleSheet(green);
    }
}

void MainWindow::slot_bot_4_lin_y(double x)
{
    if (x == 0)
    {
        ui->label_23->setStyleSheet(red);
    }
    else
    {
        ui->label_23->setStyleSheet(green);
    }
}

void MainWindow::slot_bot_1_ang_z(double x)
{
    if (x == 0)
    {
        ui->label_6->setStyleSheet(red);
    }
    else
    {
        ui->label_6->setStyleSheet(green);
    }
}

void MainWindow::slot_bot_2_ang_z(double x)
{
    if (x == 0)
    {
        ui->label_12->setStyleSheet(red);
    }
    else
    {
        ui->label_12->setStyleSheet(green);
    }
}

void MainWindow::slot_bot_3_ang_z(double x)
{
    if (x == 0)
    {
        ui->label_18->setStyleSheet(red);
    }
    else
    {
        ui->label_18->setStyleSheet(green);
    }
}

void MainWindow::slot_bot_4_ang_z(double x)
{
    if (x == 0)
    {
        ui->label_24->setStyleSheet(red);
    }
    else
    {
        ui->label_24->setStyleSheet(green);
    }
}

void MainWindow::slot_induct_1(int x)
{
    if (x == 1)
    {
        ui->label_30->setStyleSheet(red);
    }
    else
    {
        ui->label_30->setStyleSheet(green);
    }
}

void MainWindow::slot_induct_2(int x)
{
    if (x == 1)
    {
        ui->label_32->setStyleSheet(red);
    }
    else
    {
        ui->label_32->setStyleSheet(green);
    }
}

void MainWindow::slot_srv_start_bot_1()
{
    bot_1.service(0);
}

void MainWindow::slot_srv_stop_bot_1()
{
    bot_1.service(1);
}

void MainWindow::slot_srv_start_bot_2()
{
    bot_2.service(0);
}

void MainWindow::slot_srv_stop_bot_2()
{
    bot_2.service(1);
}

void MainWindow::slot_srv_start_bot_3()
{
    bot_3.service(0);
}

void MainWindow::slot_srv_stop_bot_3()
{
    bot_3.service(1);
}

void MainWindow::slot_srv_start_bot_4()
{
    bot_4.service(0);
}

void MainWindow::slot_srv_stop_bot_4()
{
    bot_4.service(1);
}

void MainWindow::slot_flipbot1_botcontrol()
{
    Rosnode::botcontrol1();
}

void MainWindow::slot_flipbot2_botcontrol()
{
    Rosnode::botcontrol2();
}

void MainWindow::slot_flipbot3_botcontrol()
{
    Rosnode::botcontrol3();
}

void MainWindow::slot_flipbot4_botcontrol()
{
    Rosnode::botcontrol4();
}
