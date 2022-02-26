#include "../include/flipkart2_gui/mainwindow.hpp"

static const int size = 20;
static const QString black = QString("color: white;border-radius: %1;background-color: qlineargradient(spread:pad, x1:0.145, y1:0.16, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 255));").arg(size/2);
static const QString green = QString("color: white;border-radius: %1;background-color: qlineargradient(spread:pad, x1:0.145, y1:0.16, x2:1, y2:1, stop:0 rgba(20, 252, 7, 255), stop:1 rgba(25, 134, 5, 255));").arg(size/2);
static const QString red = QString("color: white;border-radius: %1;background-color: qlineargradient(spread:pad, x1:0.145, y1:0.16, x2:0.92, y2:0.988636, stop:0 rgba(255, 12, 12, 255), stop:0.869347 rgba(150, 0, 0, 255));").arg(size/2);
static const QString mumbai = QString("color: white;border-radius: %1;background-color: qlineargradient(spread:pad, x1:0.145, y1:0.16, x2:1, y2:1, stop:0 rgba(249, 207, 205, 255), stop:1 rgba(254, 217, 215, 255));").arg(size/2);
static const QString delhi = QString("color: white;border-radius: %1;background-color: qlineargradient(spread:pad, x1:0.145, y1:0.16, x2:1, y2:1, stop:0 rgba(212, 232, 212, 255), stop:1 rgba(222, 242, 222, 255));").arg(size/2);
static const QString kolkata = QString("color: white;border-radius: %1;background-color: qlineargradient(spread:pad, x1:0.145, y1:0.16, x2:1, y2:1, stop:0 rgba(219, 232, 248, 255), stop:1 rgba(229, 242, 253, 255));").arg(size/2);
static const QString chennai = QString("color: white;border-radius: %1;background-color: qlineargradient(spread:pad, x1:0.145, y1:0.16, x2:1, y2:1, stop:0 rgba(178, 221, 226, 255), stop:1 rgba(188, 231, 236, 255));").arg(size/2);
static const QString bengaluru = QString("color: white;border-radius: %1;background-color: qlineargradient(spread:pad, x1:0.145, y1:0.16, x2:1, y2:1, stop:0 rgba(226, 213, 231, 255), stop:1 rgba(236, 223, 241, 255));").arg(size/2);
static const QString hyderabad = QString("color: white;border-radius: %1;background-color: qlineargradient(spread:pad, x1:0.145, y1:0.16, x2:1, y2:1, stop:0 rgba(254, 230, 205, 255), stop:1 rgba(255, 240, 215, 255));").arg(size/2);
static const QString pune = QString("color: white;border-radius: %1;background-color: qlineargradient(spread:pad, x1:0.145, y1:0.16, x2:1, y2:1, stop:0 rgba(178, 222, 240, 255), stop:1 rgba(188, 232, 250, 255));").arg(size/2);
static const QString ahemdabad = QString("color: white;border-radius: %1;background-color: qlineargradient(spread:pad, x1:0.145, y1:0.16, x2:1, y2:1, stop:0 rgba(250, 215, 172, 255), stop:1 rgba(254, 225, 182, 255));").arg(size/2);
static const QString jaipur = QString("color: white;border-radius: %1;background-color: qlineargradient(spread:pad, x1:0.145, y1:0.16, x2:1, y2:1, stop:0 rgba(187, 201, 212, 255), stop:1 rgba(197, 211, 222, 255));").arg(size/2);

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
    slot_flipbot1_botcontrol();
    slot_flipbot2_botcontrol();
    slot_flipbot3_botcontrol();
    slot_flipbot4_botcontrol();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connections()
{
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
    connect(&bot_1, SIGNAL(param_1(int)),this,SLOT(slot_induct_1(int)));
    connect(&bot_1, SIGNAL(param_2(int)),this,SLOT(slot_induct_2(int)));
    connect(&bot_4, SIGNAL(scroll(int)),this,SLOT(scrol(int)));
    connect(&bot_1, SIGNAL(scroll(int)),this,SLOT(scrol(int)));
    connect(&bot_2, SIGNAL(scroll(int)),this,SLOT(scrol(int)));
    connect(&bot_3, SIGNAL(scroll(int)),this,SLOT(scrol(int)));
    connect(&bot_4, SIGNAL(scroll(int)),this,SLOT(scrol(int)));
    connect(&bot_1, SIGNAL(dest1_subs(int)),this,SLOT(slot_dest1_sub(int)));
    connect(&bot_2, SIGNAL(dest2_subs(int)),this,SLOT(slot_dest2_sub(int)));
    connect(&bot_3, SIGNAL(dest3_subs(int)),this,SLOT(slot_dest3_sub(int)));
    connect(&bot_4, SIGNAL(dest4_subs(int)),this,SLOT(slot_dest4_sub(int)));
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
    connect(ui->pushButton_45, SIGNAL(clicked()), this, SLOT(slot_flipbot1_botcontrol()));
    connect(ui->pushButton_46, SIGNAL(clicked()), this, SLOT(slot_flipbot2_botcontrol()));
    connect(ui->pushButton_47, SIGNAL(clicked()), this, SLOT(slot_flipbot3_botcontrol()));
    connect(ui->pushButton_48, SIGNAL(clicked()), this, SLOT(slot_flipbot4_botcontrol()));
    connect(ui->pushButton_49, SIGNAL(clicked()), this, SLOT(slot_flipbot_controllall()));
}

void MainWindow::slot_pub_bot_1()
{
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    char key = btn->text().toStdString()[0];
    switch(key)
    {
        case 'P':
        bot_1.goalpub(1);
        ui->listView->scrollToBottom();
        break;

        case 'A':
        bot_1.goalpub(2);
        ui->listView->scrollToBottom();
        break;

        case 'J':
        bot_1.goalpub(3);
        ui->listView->scrollToBottom();
        break;

        case 'C':
        bot_1.goalpub(4);
        ui->listView->scrollToBottom();
        break;

        case 'B':
        bot_1.goalpub(5);
        ui->listView->scrollToBottom();
        break;

        case 'H':
        bot_1.goalpub(6);
        ui->listView->scrollToBottom();
        break;

        case 'M':
        bot_1.goalpub(7);
        ui->listView->scrollToBottom();
        break;

        case 'D':
        bot_1.goalpub(8);
        ui->listView->scrollToBottom();
        break;

        case 'K':
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
        case 'P':
        bot_2.goalpub(1);
        ui->listView->scrollToBottom();
        break;

        case 'A':
        bot_2.goalpub(2);
        ui->listView->scrollToBottom();
        break;

        case 'J':
        bot_2.goalpub(3);
        ui->listView->scrollToBottom();
        break;

        case 'C':
        bot_2.goalpub(4);
        ui->listView->scrollToBottom();
        break;

        case 'B':
        bot_2.goalpub(5);
        ui->listView->scrollToBottom();
        break;

        case 'H':
        bot_2.goalpub(6);
        ui->listView->scrollToBottom();
        break;

        case 'M':
        bot_2.goalpub(7);
        ui->listView->scrollToBottom();
        break;

        case 'D':
        bot_2.goalpub(8);
        ui->listView->scrollToBottom();
        break;

        case 'K':
        bot_2.goalpub(9);
        ui->listView->scrollToBottom();
        break;
    }

}

void MainWindow::slot_pub_bot_3()
{
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    char key = btn->text().toStdString()[0];
    switch(key)
    {
        case 'P':
        bot_3.goalpub(1);
        ui->listView->scrollToBottom();
        break;

        case 'A':
        bot_3.goalpub(2);
        ui->listView->scrollToBottom();
        break;

        case 'J':
        bot_3.goalpub(3);
        ui->listView->scrollToBottom();
        break;

        case 'C':
        bot_3.goalpub(4);
        ui->listView->scrollToBottom();
        break;

        case 'B':
        bot_3.goalpub(5);
        ui->listView->scrollToBottom();
        break;

        case 'H':
        bot_3.goalpub(6);
        ui->listView->scrollToBottom();
        break;

        case 'M':
        bot_3.goalpub(7);
        ui->listView->scrollToBottom();
        break;

        case 'D':
        bot_3.goalpub(8);
        ui->listView->scrollToBottom();
        break;

        case 'K':
        bot_3.goalpub(9);
        ui->listView->scrollToBottom();
        break;
    }
}

void MainWindow::slot_pub_bot_4()
{
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    char key = btn->text().toStdString()[0];
    switch(key)
    {
        case 'P':
        bot_4.goalpub(1);
        ui->listView->scrollToBottom();
        break;

        case 'A':
        bot_4.goalpub(2);
        ui->listView->scrollToBottom();
        break;

        case 'J':
        bot_4.goalpub(3);
        ui->listView->scrollToBottom();
        break;

        case 'C':
        bot_4.goalpub(4);
        ui->listView->scrollToBottom();
        break;

        case 'B':
        bot_4.goalpub(5);
        ui->listView->scrollToBottom();
        break;

        case 'H':
        bot_4.goalpub(6);
        ui->listView->scrollToBottom();
        break;

        case 'M':
        bot_4.goalpub(7);
        ui->listView->scrollToBottom();
        break;

        case 'D':
        bot_4.goalpub(8);
        ui->listView->scrollToBottom();
        break;

        case 'K':
        bot_4.goalpub(9);
        ui->listView->scrollToBottom();
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
    bool check =  Rosnode::botcontrol1();
    if (check == true)
    {
        ui->pushButton_45->setStyleSheet(green);
    }
    else
    {
        ui->pushButton_45->setStyleSheet(red);
    }
}

void MainWindow::slot_flipbot2_botcontrol()
{
    bool check =  Rosnode::botcontrol2();
    if (check == true)
    {
        ui->pushButton_46->setStyleSheet(green);
    }
    else
    {
        ui->pushButton_46->setStyleSheet(red);
    }
}

void MainWindow::slot_flipbot3_botcontrol()
{
    bool check =  Rosnode::botcontrol3();
    if (check == true)
    {
        ui->pushButton_47->setStyleSheet(green);
    }
    else
    {
        ui->pushButton_47->setStyleSheet(red);
    }
}

void MainWindow::slot_flipbot4_botcontrol()
{
    bool check =  Rosnode::botcontrol4();
    if (check == true)
    {
        ui->pushButton_48->setStyleSheet(green);
    }
    else
    {
        ui->pushButton_48->setStyleSheet(red);
    }
}

void MainWindow::slot_flipbot_controllall()
{
    bool check1 = Rosnode::botcontrol1();
    bool check2 = Rosnode::botcontrol2();
    bool check3 = Rosnode::botcontrol3();
    bool check4 = Rosnode::botcontrol4();
    if (check1 == true)
    {
        ui->pushButton_45->setStyleSheet(green);
    }
    else
    {
        ui->pushButton_45->setStyleSheet(red);
    }
    if (check2 == true)
    {
        ui->pushButton_46->setStyleSheet(green);
    }
    else
    {
        ui->pushButton_46->setStyleSheet(red);
    }
    if (check3 == true)
    {
        ui->pushButton_47->setStyleSheet(green);
    }
    else
    {
        ui->pushButton_47->setStyleSheet(red);
    }
    if (check4 == true)
    {
        ui->pushButton_48->setStyleSheet(green);
    }
    else
    {
        ui->pushButton_48->setStyleSheet(red);
    }
    if(check1 == check2 == check4 == true)
    {
        ui->pushButton_49->setStyleSheet(green);
    }
    else
    {
        ui->pushButton_49->setStyleSheet(red);
    }
}

void MainWindow::scrol(int num)
{
    if (num == 1)
    {
        ui->listView->scrollToBottom();
        ui->listView_2->scrollToBottom();
        ui->listView_3->scrollToBottom();
        ui->listView_4->scrollToBottom();
    }
}

void MainWindow::slot_dest1_sub(int p)
{
    switch(p)
    {
        case 1:
        ui->pushButton->setStyleSheet(pune);
        ui->pushButton_2->setStyleSheet(black);
        ui->pushButton_3->setStyleSheet(black);
        ui->pushButton_4->setStyleSheet(black);
        ui->pushButton_5->setStyleSheet(black);
        ui->pushButton_6->setStyleSheet(black);
        ui->pushButton_7->setStyleSheet(black);
        ui->pushButton_8->setStyleSheet(black);
        ui->pushButton_9->setStyleSheet(black);
        break;
    case 2:
    ui->pushButton->setStyleSheet(black);
    ui->pushButton_2->setStyleSheet(ahemdabad);
    ui->pushButton_3->setStyleSheet(black);
    ui->pushButton_4->setStyleSheet(black);
    ui->pushButton_5->setStyleSheet(black);
    ui->pushButton_6->setStyleSheet(black);
    ui->pushButton_7->setStyleSheet(black);
    ui->pushButton_8->setStyleSheet(black);
    ui->pushButton_9->setStyleSheet(black);
    break;
    case 3:
    ui->pushButton->setStyleSheet(black);
    ui->pushButton_2->setStyleSheet(black);
    ui->pushButton_3->setStyleSheet(jaipur);
    ui->pushButton_4->setStyleSheet(black);
    ui->pushButton_5->setStyleSheet(black);
    ui->pushButton_6->setStyleSheet(black);
    ui->pushButton_7->setStyleSheet(black);
    ui->pushButton_8->setStyleSheet(black);
    ui->pushButton_9->setStyleSheet(black);
    break;
    case 4:
    ui->pushButton->setStyleSheet(black);
    ui->pushButton_2->setStyleSheet(black);
    ui->pushButton_3->setStyleSheet(black);
    ui->pushButton_4->setStyleSheet(chennai);
    ui->pushButton_5->setStyleSheet(black);
    ui->pushButton_6->setStyleSheet(black);
    ui->pushButton_7->setStyleSheet(black);
    ui->pushButton_8->setStyleSheet(black);
    ui->pushButton_9->setStyleSheet(black);
    break;
    case 5:
    ui->pushButton->setStyleSheet(black);
    ui->pushButton_2->setStyleSheet(black);
    ui->pushButton_3->setStyleSheet(black);
    ui->pushButton_4->setStyleSheet(black);
    ui->pushButton_5->setStyleSheet(bengaluru);
    ui->pushButton_6->setStyleSheet(black);
    ui->pushButton_7->setStyleSheet(black);
    ui->pushButton_8->setStyleSheet(black);
    ui->pushButton_9->setStyleSheet(black);
    break;
    case 6:
    ui->pushButton->setStyleSheet(black);
    ui->pushButton_2->setStyleSheet(black);
    ui->pushButton_3->setStyleSheet(black);
    ui->pushButton_4->setStyleSheet(black);
    ui->pushButton_5->setStyleSheet(black);
    ui->pushButton_6->setStyleSheet(hyderabad);
    ui->pushButton_7->setStyleSheet(black);
    ui->pushButton_8->setStyleSheet(black);
    ui->pushButton_9->setStyleSheet(black);
    break;
    case 7:
    ui->pushButton->setStyleSheet(black);
    ui->pushButton_2->setStyleSheet(black);
    ui->pushButton_3->setStyleSheet(black);
    ui->pushButton_4->setStyleSheet(black);
    ui->pushButton_5->setStyleSheet(black);
    ui->pushButton_6->setStyleSheet(black);
    ui->pushButton_7->setStyleSheet(mumbai);
    ui->pushButton_8->setStyleSheet(black);
    ui->pushButton_9->setStyleSheet(black);
    break;
    case 8:
    ui->pushButton->setStyleSheet(black);
    ui->pushButton_2->setStyleSheet(black);
    ui->pushButton_3->setStyleSheet(black);
    ui->pushButton_4->setStyleSheet(black);
    ui->pushButton_5->setStyleSheet(black);
    ui->pushButton_6->setStyleSheet(black);
    ui->pushButton_7->setStyleSheet(black);
    ui->pushButton_8->setStyleSheet(delhi);
    ui->pushButton_9->setStyleSheet(black);
    break;
    case 9:
    ui->pushButton->setStyleSheet(black);
    ui->pushButton_2->setStyleSheet(black);
    ui->pushButton_3->setStyleSheet(black);
    ui->pushButton_4->setStyleSheet(black);
    ui->pushButton_5->setStyleSheet(black);
    ui->pushButton_6->setStyleSheet(black);
    ui->pushButton_7->setStyleSheet(black);
    ui->pushButton_8->setStyleSheet(black);
    ui->pushButton_9->setStyleSheet(kolkata);
    break;


    }
}

void MainWindow::slot_dest2_sub(int p)
{
    switch(p)
    {
        case 1:
        ui->pushButton_12->setStyleSheet(pune);
        ui->pushButton_10->setStyleSheet(black);
        ui->pushButton_18->setStyleSheet(black);
        ui->pushButton_17->setStyleSheet(black);
        ui->pushButton_15->setStyleSheet(black);
        ui->pushButton_16->setStyleSheet(black);
        ui->pushButton_14->setStyleSheet(black);
        ui->pushButton_11->setStyleSheet(black);
        ui->pushButton_13->setStyleSheet(black);
        break;
    case 2:
    ui->pushButton_12->setStyleSheet(black);
    ui->pushButton_10->setStyleSheet(ahemdabad);
    ui->pushButton_18->setStyleSheet(black);
    ui->pushButton_17->setStyleSheet(black);
    ui->pushButton_15->setStyleSheet(black);
    ui->pushButton_16->setStyleSheet(black);
    ui->pushButton_14->setStyleSheet(black);
    ui->pushButton_11->setStyleSheet(black);
    ui->pushButton_13->setStyleSheet(black);
    break;
    case 3:
    ui->pushButton_12->setStyleSheet(black);
    ui->pushButton_10->setStyleSheet(black);
    ui->pushButton_18->setStyleSheet(jaipur);
    ui->pushButton_17->setStyleSheet(black);
    ui->pushButton_15->setStyleSheet(black);
    ui->pushButton_16->setStyleSheet(black);
    ui->pushButton_14->setStyleSheet(black);
    ui->pushButton_11->setStyleSheet(black);
    ui->pushButton_13->setStyleSheet(black);
    break;
    case 4:
    ui->pushButton_12->setStyleSheet(black);
    ui->pushButton_10->setStyleSheet(black);
    ui->pushButton_18->setStyleSheet(black);
    ui->pushButton_17->setStyleSheet(chennai);
    ui->pushButton_15->setStyleSheet(black);
    ui->pushButton_16->setStyleSheet(black);
    ui->pushButton_14->setStyleSheet(black);
    ui->pushButton_11->setStyleSheet(black);
    ui->pushButton_13->setStyleSheet(black);
    break;
    case 5:
    ui->pushButton_12->setStyleSheet(black);
    ui->pushButton_10->setStyleSheet(black);
    ui->pushButton_18->setStyleSheet(black);
    ui->pushButton_17->setStyleSheet(black);
    ui->pushButton_15->setStyleSheet(bengaluru);
    ui->pushButton_16->setStyleSheet(black);
    ui->pushButton_14->setStyleSheet(black);
    ui->pushButton_11->setStyleSheet(black);
    ui->pushButton_13->setStyleSheet(black);
    break;
    case 6:
    ui->pushButton_12->setStyleSheet(black);
    ui->pushButton_10->setStyleSheet(black);
    ui->pushButton_18->setStyleSheet(black);
    ui->pushButton_17->setStyleSheet(black);
    ui->pushButton_15->setStyleSheet(black);
    ui->pushButton_16->setStyleSheet(hyderabad);
    ui->pushButton_14->setStyleSheet(black);
    ui->pushButton_11->setStyleSheet(black);
    ui->pushButton_13->setStyleSheet(black);
    break;
    case 7:
    ui->pushButton_12->setStyleSheet(black);
    ui->pushButton_10->setStyleSheet(black);
    ui->pushButton_18->setStyleSheet(black);
    ui->pushButton_17->setStyleSheet(black);
    ui->pushButton_15->setStyleSheet(black);
    ui->pushButton_16->setStyleSheet(black);
    ui->pushButton_14->setStyleSheet(mumbai);
    ui->pushButton_11->setStyleSheet(black);
    ui->pushButton_13->setStyleSheet(black);
    break;
    case 8:
    ui->pushButton_12->setStyleSheet(black);
    ui->pushButton_10->setStyleSheet(black);
    ui->pushButton_18->setStyleSheet(black);
    ui->pushButton_17->setStyleSheet(black);
    ui->pushButton_15->setStyleSheet(black);
    ui->pushButton_16->setStyleSheet(black);
    ui->pushButton_14->setStyleSheet(black);
    ui->pushButton_11->setStyleSheet(delhi);
    ui->pushButton_13->setStyleSheet(black);
    break;
    case 9:
    ui->pushButton_12->setStyleSheet(black);
    ui->pushButton_10->setStyleSheet(black);
    ui->pushButton_18->setStyleSheet(black);
    ui->pushButton_17->setStyleSheet(black);
    ui->pushButton_15->setStyleSheet(black);
    ui->pushButton_16->setStyleSheet(black);
    ui->pushButton_14->setStyleSheet(black);
    ui->pushButton_11->setStyleSheet(black);
    ui->pushButton_13->setStyleSheet(kolkata);
    break;


    }
}

void MainWindow::slot_dest3_sub(int p)
{
    switch(p)
    {
        case 1:
        ui->pushButton_21->setStyleSheet(pune);
        ui->pushButton_19->setStyleSheet(black);
        ui->pushButton_27->setStyleSheet(black);
        ui->pushButton_26->setStyleSheet(black);
        ui->pushButton_24->setStyleSheet(black);
        ui->pushButton_25->setStyleSheet(black);
        ui->pushButton_23->setStyleSheet(black);
        ui->pushButton_20->setStyleSheet(black);
        ui->pushButton_22->setStyleSheet(black);
        break;
    case 2:
    ui->pushButton_21->setStyleSheet(black);
    ui->pushButton_19->setStyleSheet(ahemdabad);
    ui->pushButton_27->setStyleSheet(black);
    ui->pushButton_26->setStyleSheet(black);
    ui->pushButton_24->setStyleSheet(black);
    ui->pushButton_25->setStyleSheet(black);
    ui->pushButton_23->setStyleSheet(black);
    ui->pushButton_20->setStyleSheet(black);
    ui->pushButton_22->setStyleSheet(black);
    break;
    case 3:
    ui->pushButton_21->setStyleSheet(black);
    ui->pushButton_19->setStyleSheet(black);
    ui->pushButton_27->setStyleSheet(jaipur);
    ui->pushButton_26->setStyleSheet(black);
    ui->pushButton_24->setStyleSheet(black);
    ui->pushButton_25->setStyleSheet(black);
    ui->pushButton_23->setStyleSheet(black);
    ui->pushButton_20->setStyleSheet(black);
    ui->pushButton_22->setStyleSheet(black);
    break;
    case 4:
    ui->pushButton_21->setStyleSheet(black);
    ui->pushButton_19->setStyleSheet(black);
    ui->pushButton_27->setStyleSheet(black);
    ui->pushButton_26->setStyleSheet(chennai);
    ui->pushButton_24->setStyleSheet(black);
    ui->pushButton_25->setStyleSheet(black);
    ui->pushButton_23->setStyleSheet(black);
    ui->pushButton_20->setStyleSheet(black);
    ui->pushButton_22->setStyleSheet(black);
    break;
    case 5:
    ui->pushButton_21->setStyleSheet(black);
    ui->pushButton_19->setStyleSheet(black);
    ui->pushButton_27->setStyleSheet(black);
    ui->pushButton_26->setStyleSheet(black);
    ui->pushButton_24->setStyleSheet(bengaluru);
    ui->pushButton_25->setStyleSheet(black);
    ui->pushButton_23->setStyleSheet(black);
    ui->pushButton_20->setStyleSheet(black);
    ui->pushButton_22->setStyleSheet(black);
    break;
    case 6:
    ui->pushButton_21->setStyleSheet(black);
    ui->pushButton_19->setStyleSheet(black);
    ui->pushButton_27->setStyleSheet(black);
    ui->pushButton_26->setStyleSheet(black);
    ui->pushButton_24->setStyleSheet(black);
    ui->pushButton_25->setStyleSheet(hyderabad);
    ui->pushButton_23->setStyleSheet(black);
    ui->pushButton_20->setStyleSheet(black);
    ui->pushButton_22->setStyleSheet(black);
    break;
    case 7:
    ui->pushButton_21->setStyleSheet(black);
    ui->pushButton_19->setStyleSheet(black);
    ui->pushButton_27->setStyleSheet(black);
    ui->pushButton_26->setStyleSheet(black);
    ui->pushButton_24->setStyleSheet(black);
    ui->pushButton_25->setStyleSheet(black);
    ui->pushButton_23->setStyleSheet(mumbai);
    ui->pushButton_20->setStyleSheet(black);
    ui->pushButton_22->setStyleSheet(black);
    break;
    case 8:
    ui->pushButton_21->setStyleSheet(black);
    ui->pushButton_19->setStyleSheet(black);
    ui->pushButton_27->setStyleSheet(black);
    ui->pushButton_26->setStyleSheet(black);
    ui->pushButton_24->setStyleSheet(black);
    ui->pushButton_25->setStyleSheet(black);
    ui->pushButton_23->setStyleSheet(black);
    ui->pushButton_20->setStyleSheet(delhi);
    ui->pushButton_22->setStyleSheet(black);
    break;
    case 9:
    ui->pushButton_21->setStyleSheet(black);
    ui->pushButton_19->setStyleSheet(black);
    ui->pushButton_27->setStyleSheet(black);
    ui->pushButton_26->setStyleSheet(black);
    ui->pushButton_24->setStyleSheet(black);
    ui->pushButton_25->setStyleSheet(black);
    ui->pushButton_23->setStyleSheet(black);
    ui->pushButton_20->setStyleSheet(black);
    ui->pushButton_22->setStyleSheet(kolkata);
    break;


    }
}

void MainWindow::slot_dest4_sub(int p)
{
    switch(p)
    {
        case 1:
        ui->pushButton_30->setStyleSheet(pune);
        ui->pushButton_28->setStyleSheet(black);
        ui->pushButton_36->setStyleSheet(black);
        ui->pushButton_35->setStyleSheet(black);
        ui->pushButton_33->setStyleSheet(black);
        ui->pushButton_34->setStyleSheet(black);
        ui->pushButton_32->setStyleSheet(black);
        ui->pushButton_29->setStyleSheet(black);
        ui->pushButton_31->setStyleSheet(black);
        break;
    case 2:
    ui->pushButton_30->setStyleSheet(black);
    ui->pushButton_28->setStyleSheet(ahemdabad);
    ui->pushButton_36->setStyleSheet(black);
    ui->pushButton_35->setStyleSheet(black);
    ui->pushButton_33->setStyleSheet(black);
    ui->pushButton_34->setStyleSheet(black);
    ui->pushButton_32->setStyleSheet(black);
    ui->pushButton_29->setStyleSheet(black);
    ui->pushButton_31->setStyleSheet(black);
    break;
    case 3:
    ui->pushButton_30->setStyleSheet(black);
    ui->pushButton_28->setStyleSheet(black);
    ui->pushButton_36->setStyleSheet(jaipur);
    ui->pushButton_35->setStyleSheet(black);
    ui->pushButton_33->setStyleSheet(black);
    ui->pushButton_34->setStyleSheet(black);
    ui->pushButton_32->setStyleSheet(black);
    ui->pushButton_29->setStyleSheet(black);
    ui->pushButton_31->setStyleSheet(black);
    break;
    case 4:
    ui->pushButton_30->setStyleSheet(black);
    ui->pushButton_28->setStyleSheet(black);
    ui->pushButton_36->setStyleSheet(black);
    ui->pushButton_35->setStyleSheet(chennai);
    ui->pushButton_33->setStyleSheet(black);
    ui->pushButton_34->setStyleSheet(black);
    ui->pushButton_32->setStyleSheet(black);
    ui->pushButton_29->setStyleSheet(black);
    ui->pushButton_31->setStyleSheet(black);
    break;
    case 5:
    ui->pushButton_30->setStyleSheet(black);
    ui->pushButton_28->setStyleSheet(black);
    ui->pushButton_36->setStyleSheet(black);
    ui->pushButton_35->setStyleSheet(black);
    ui->pushButton_33->setStyleSheet(bengaluru);
    ui->pushButton_34->setStyleSheet(black);
    ui->pushButton_32->setStyleSheet(black);
    ui->pushButton_29->setStyleSheet(black);
    ui->pushButton_31->setStyleSheet(black);
    break;
    case 6:
    ui->pushButton_30->setStyleSheet(black);
    ui->pushButton_28->setStyleSheet(black);
    ui->pushButton_36->setStyleSheet(black);
    ui->pushButton_35->setStyleSheet(black);
    ui->pushButton_33->setStyleSheet(black);
    ui->pushButton_34->setStyleSheet(hyderabad);
    ui->pushButton_32->setStyleSheet(black);
    ui->pushButton_29->setStyleSheet(black);
    ui->pushButton_31->setStyleSheet(black);
    break;
    case 7:
    ui->pushButton_30->setStyleSheet(black);
    ui->pushButton_28->setStyleSheet(black);
    ui->pushButton_36->setStyleSheet(black);
    ui->pushButton_35->setStyleSheet(black);
    ui->pushButton_33->setStyleSheet(black);
    ui->pushButton_34->setStyleSheet(black);
    ui->pushButton_32->setStyleSheet(mumbai);
    ui->pushButton_29->setStyleSheet(black);
    ui->pushButton_31->setStyleSheet(black);
    break;
    case 8:
    ui->pushButton_30->setStyleSheet(black);
    ui->pushButton_28->setStyleSheet(black);
    ui->pushButton_36->setStyleSheet(black);
    ui->pushButton_35->setStyleSheet(black);
    ui->pushButton_33->setStyleSheet(black);
    ui->pushButton_34->setStyleSheet(black);
    ui->pushButton_32->setStyleSheet(black);
    ui->pushButton_29->setStyleSheet(delhi);
    ui->pushButton_31->setStyleSheet(black);
    break;
    case 9:
    ui->pushButton_30->setStyleSheet(black);
    ui->pushButton_28->setStyleSheet(black);
    ui->pushButton_36->setStyleSheet(black);
    ui->pushButton_35->setStyleSheet(black);
    ui->pushButton_33->setStyleSheet(black);
    ui->pushButton_34->setStyleSheet(black);
    ui->pushButton_32->setStyleSheet(black);
    ui->pushButton_29->setStyleSheet(black);
    ui->pushButton_31->setStyleSheet(kolkata);
    break;
    }
}
