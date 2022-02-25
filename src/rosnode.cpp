#include "../include/flipkart2_gui/rosnode.hpp"
#include <QDebug>
#include <sstream>


Rosnode::Rosnode(int argc, char **argv,std::string bot):init_argc(argc),init_argv(argv),bot_no(bot)
{
    ros::init(init_argc,init_argv,"goal_dest_pub");
    ros::NodeHandle n;
    ros::start();
    goal_num = n.advertise<std_msgs::Int64>("/flipbot"+bot_no+"/dest",1000);
    srv_start_stop = n.serviceClient<flipbot2_msg::BotInterupt>("flipbot"+bot_no+"botStop");
    start();
}

Rosnode::~Rosnode()
{
    if(ros::isStarted()){
        ros::shutdown();
        ros::waitForShutdown();
    }
    wait();
}

void Rosnode::run()
{
    ros::Rate loop_rate(20);
    ros::AsyncSpinner spinner(2);
    spinner.start();
    ros::NodeHandle n;
    cmd1_sub = n.subscribe("/flipbot1/cmd_vel",1000,&Rosnode::cmd1callback,this);
    cmd2_sub = n.subscribe("/flipbot2/cmd_vel",1000,&Rosnode::cmd2callback,this);
    cmd3_sub = n.subscribe("/flipbot3/cmd_vel",1000,&Rosnode::cmd3callback,this);
    cmd4_sub = n.subscribe("/flipbot4/cmd_vel",1000,&Rosnode::cmd4callback,this);
    while(ros::ok())
    {
    int induct_1,induct_2;
    ros::param::get("/induct1_occupancy",induct_1);
    if (induct_1 == 0)
        {
            Q_EMIT param_1(0);
        }
    else
        {
            Q_EMIT param_1(1);
        }
    ros::param::get("/induct2_occupancy",induct_2);
    if (induct_2 == 0)
        {
            Q_EMIT param_2(0);
        }
    else
        {
            Q_EMIT param_2(1);
        }
    }
    loop_rate.sleep();
}

void Rosnode::goalpub(int num)
{
    std_msgs::Int64 msg;
    msg.data = num;
    goal_num.publish(msg);
    log(Info,"dest",num);
}

void Rosnode::service(int num)
{
    flipbot2_msg::BotInterupt srv;
    srv.request.pause = num;
    log(Info,"SERVICE",srv.request.pause);
    if(srv_start_stop.call(srv))
    {
        log(Info,"SERVICE",num);
    }
}

void Rosnode::cmd1callback(const geometry_msgs::Twist::ConstPtr &vel)
{
    Q_EMIT lin_x_bot_1(vel->linear.x);
    Q_EMIT lin_y_bot_1(vel->linear.y);
    Q_EMIT ang_z_bot_1(vel->angular.z);
//    log(Info,"X",vel->linear.x);
//    log(Info,"Y",vel->linear.y);
//    log(Info,"YAW",vel->angular.z);
}

void Rosnode::cmd2callback(const geometry_msgs::Twist::ConstPtr &vel)
{
    Q_EMIT lin_x_bot_2(vel->linear.x);
    Q_EMIT lin_y_bot_2(vel->linear.y);
    Q_EMIT ang_z_bot_2(vel->angular.z);
//    log(Info,"X",vel->linear.x);
//    log(Info,"Y",vel->linear.y);
//    log(Info,"YAW",vel->angular.z);
}

void Rosnode::cmd3callback(const geometry_msgs::Twist::ConstPtr &vel)
{
    Q_EMIT lin_x_bot_3(vel->linear.x);
    Q_EMIT lin_y_bot_3(vel->linear.y);
    Q_EMIT ang_z_bot_3(vel->angular.z);
//    log(Info,"X",vel->linear.x);
//    log(Info,"Y",vel->linear.y);
//    log(Info,"YAW",vel->angular.z);
}

void Rosnode::cmd4callback(const geometry_msgs::Twist::ConstPtr &vel)
{
    Q_EMIT lin_x_bot_4(vel->linear.x);
    Q_EMIT lin_y_bot_4(vel->linear.y);
    Q_EMIT ang_z_bot_4(vel->angular.z);
//    log(Info,"X",vel->linear.x);
//    log(Info,"Y",vel->linear.y);
//    log(Info,"YAW",vel->angular.z);
}

bool Rosnode::botcontrol1()
{
    int check;
    ros::param::get("flipbot1/bot_control",check);
    if (check == 0)
        {
            ros::param::set("flipbot1/bot_control",1);
            return true;
        }
    else
        {
            ros::param::set("flipbot1/bot_control",0);
            return false;
        }
}

bool Rosnode::botcontrol2()
{
    int check;
    ros::param::get("flipbot2/bot_control",check);
    if (check == 0)
        {
            ros::param::set("flipbot2/bot_control",1);
            return true;
        }
    else
        {
            ros::param::set("flipbot2/bot_control",0);
            return false;
        }
}

bool Rosnode::botcontrol3()
{
    int check;
    ros::param::get("flipbot3/bot_control",check);
    if (check == 0)
        {
            ros::param::set("flipbot3/bot_control",1);
            return true;
        }
    else
        {
            ros::param::set("flipbot3/bot_control",0);
            return false;
        }
}

bool Rosnode::botcontrol4()
{
    int check;
    ros::param::get("flipbot4/bot_control",check);
    if (check == 0)
        {
            ros::param::set("flipbot4/bot_control",1);
            return true;
        }
    else
        {
            ros::param::set("flipbot4/bot_control",0);
            return false;
        }
}

void Rosnode::log(const LogLevel &level,const std::string &msg,const double &dest)
{
    logging_model.insertRows(logging_model.rowCount(),1);
    std::stringstream logging_model_msg;
    switch (level)
    {
        case(Debug):
    {
        logging_model_msg<<"DEBUG : "<<msg<<" "<<dest;
        break;
    }
        case(Info):
    {
        logging_model_msg<<"INFO : "<<msg<<" "<<dest;
        break;
    }
        case(Warn):
    {
        logging_model_msg<<"WARN : "<<msg<<" "<<dest;
        break;
    }
        case(Error):
    {
        logging_model_msg<<"ERROR : "<<msg<<" "<<dest;
        break;
    }
        case(Fatal):
    {
        logging_model_msg<<"FATAL : "<<msg<<" "<<dest;
        break;
    }
    }
    QVariant new_row(QString(logging_model_msg.str().c_str()));
    logging_model.setData(logging_model.index(logging_model.rowCount()-1),new_row);
    Q_EMIT loggingUpdated();
}



