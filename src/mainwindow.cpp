#include "../include/flipkart2_gui/mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent):QMainWindow (parent),ui(new Ui::MainWindow),bot_1(0,nullptr,"1"),bot_2(0,nullptr,"2"),bot_3(0,nullptr,"3"),bot_4(0,nullptr,"4")
{
    ui->setupUi(this);
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

void MainWindow::updateLoggingView()
{
    ui->listView->scrollToBottom();
}

void MainWindow::connections()
{
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
}

void MainWindow::slot_pub_bot_1()
{
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    char key = btn->text().toStdString()[0];
    switch(key)
    {
        case '1':
        qDebug()<<key;
        bot_1.goalpub(1);
        break;

        case '2':
        qDebug()<<key;
        bot_1.goalpub(2);
        break;

        case '3':
        qDebug()<<key;
        bot_1.goalpub(3);
        break;

        case '4':
        qDebug()<<key;
        bot_1.goalpub(4);
        break;

        case '5':
        qDebug()<<key;
        bot_1.goalpub(5);
        break;

        case '6':
        qDebug()<<key;
        bot_1.goalpub(6);
        break;

        case '7':
        qDebug()<<key;
        bot_1.goalpub(7);
        break;

        case '8':
        qDebug()<<key;
        bot_1.goalpub(8);
        break;

        case '9':
        qDebug()<<key;
        bot_1.goalpub(9);
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
        qDebug()<<key;
        bot_2.goalpub(1);
        break;

        case '2':
        qDebug()<<key;
        bot_2.goalpub(2);
        break;

        case '3':
        qDebug()<<key;
        bot_2.goalpub(3);
        break;

        case '4':
        qDebug()<<key;
        bot_2.goalpub(4);
        break;

        case '5':
        qDebug()<<key;
        bot_2.goalpub(5);
        break;

        case '6':
        qDebug()<<key;
        bot_2.goalpub(6);
        break;

        case '7':
        qDebug()<<key;
        bot_2.goalpub(7);
        break;

        case '8':
        qDebug()<<key;
        bot_2.goalpub(8);
        break;

        case '9':
        qDebug()<<key;
        bot_2.goalpub(9);
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
        qDebug()<<key;
        bot_3.goalpub(1);
        break;

        case '2':
        qDebug()<<key;
        bot_3.goalpub(2);
        break;

        case '3':
        qDebug()<<key;
        bot_3.goalpub(3);
        break;

        case '4':
        qDebug()<<key;
        bot_3.goalpub(4);
        break;

        case '5':
        qDebug()<<key;
        bot_3.goalpub(5);
        break;

        case '6':
        qDebug()<<key;
        bot_3.goalpub(6);
        break;

        case '7':
        qDebug()<<key;
        bot_3.goalpub(7);
        break;

        case '8':
        qDebug()<<key;
        bot_3.goalpub(8);
        break;

        case '9':
        qDebug()<<key;
        bot_3.goalpub(9);
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
        qDebug()<<key;
        bot_4.goalpub(1);
        break;

        case '2':
        qDebug()<<key;
        bot_4.goalpub(2);
        break;

        case '3':
        qDebug()<<key;
        bot_4.goalpub(3);
        break;

        case '4':
        qDebug()<<key;
        bot_4.goalpub(4);
        break;

        case '5':
        qDebug()<<key;
        bot_4.goalpub(5);
        break;

        case '6':
        qDebug()<<key;
        bot_4.goalpub(6);
        break;

        case '7':
        qDebug()<<key;
        bot_4.goalpub(7);
        break;

        case '8':
        qDebug()<<key;
        bot_4.goalpub(8);
        break;

        case '9':
        qDebug()<<key;
        bot_4.goalpub(9);
        break;
    }

}
