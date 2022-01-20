#ifndef ROSNODE_HPP
#define ROSNODE_HPP
#include <ros/ros.h>
#include <ros/network.h>
#include <iostream>
#include <string>
#include <std_msgs/String.h>
#include <std_msgs/Int64.h>
#include <geometry_msgs/Twist.h>
#include "flipbot2_msg/BotInterupt.h"
#include <thread>
#include <boost/core/ref.hpp>
#include <sstream>
#include <QDebug>
#include <QThread>
#include <QLabel>
#include <QStringListModel>

namespace Ui {
  class Rosnode;
}

class Rosnode : public QThread{
    Q_OBJECT
public:
    Rosnode(int argc, char **argv,std::string bot);
    virtual ~Rosnode();
    void run();
    enum LogLevel {
             Debug,
             Info,
             Warn,
             Error,
             Fatal
     };
    void goalpub(int num);
    void service(int num);
    QStringListModel * loggingModel() { return &logging_model; }
    void log( const LogLevel &level, const std::string &msg, const double &dest);

Q_SIGNALS:
    void loggingUpdated();
    void rosShutdown();
    void param_1(int p);
    void param_2(int p);

private:
    int init_argc;
    char **init_argv;
    std::string bot_no;
    ros::Publisher goal_num;
    ros::ServiceClient srv_start_stop;
    QStringListModel logging_model;
};

#endif // ROSNODE_HPP

