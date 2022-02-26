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
    void log( const LogLevel &level, const std::string &msg, const std::string &dest);
    void cmd1callback(const geometry_msgs::Twist::ConstPtr &vel);
    void cmd2callback(const geometry_msgs::Twist::ConstPtr &vel);
    void cmd3callback(const geometry_msgs::Twist::ConstPtr &vel);
    void cmd4callback(const geometry_msgs::Twist::ConstPtr &vel);
    void pckcallback(const std_msgs::String::ConstPtr &id);
    void dest1callback(const std_msgs::Int64::ConstPtr &dest);
    void dest2callback(const std_msgs::Int64::ConstPtr &dest);
    void dest3callback(const std_msgs::Int64::ConstPtr &dest);
    void dest4callback(const std_msgs::Int64::ConstPtr &dest);
    static bool botcontrol1();
    static bool botcontrol2();
    static bool botcontrol3();
    static bool botcontrol4();

Q_SIGNALS:
    void loggingUpdated();
    void scroll(int num);
    void rosShutdown();
    void lin_x_bot_1(double x);
    void lin_y_bot_1(double y);
    void ang_z_bot_1(double z);
    void lin_x_bot_2(double x);
    void lin_y_bot_2(double y);
    void ang_z_bot_2(double z);
    void lin_x_bot_3(double x);
    void lin_y_bot_3(double y);
    void ang_z_bot_3(double z);
    void lin_x_bot_4(double x);
    void lin_y_bot_4(double y);
    void ang_z_bot_4(double z);
    void param_1(int p);
    void param_2(int p);
    void dest1_subs(int p);
    void dest2_subs(int p);
    void dest3_subs(int p);
    void dest4_subs(int p);

private:
    int init_argc;
    char **init_argv;
    std::string bot_no;
    ros::Publisher goal_num;
    ros::Subscriber cmd1_sub;
    ros::Subscriber cmd2_sub;
    ros::Subscriber cmd3_sub;
    ros::Subscriber cmd4_sub;
    ros::Subscriber pck_sub;
    ros::Subscriber dest1_sub;
    ros::Subscriber dest2_sub;
    ros::Subscriber dest3_sub;
    ros::Subscriber dest4_sub;
    ros::ServiceClient srv_start_stop;
    QStringListModel logging_model;
};

#endif // ROSNODE_HPP

