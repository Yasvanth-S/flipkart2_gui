#include "../include/flipkart2_gui/rosnode.hpp"
#include <QDebug>
#include <sstream>


Rosnode::Rosnode(int argc, char **argv,std::string bot):init_argc(argc),init_argv(argv),bot_no(bot)
{
    ros::init(init_argc,init_argv,"goal_dest_pub");
    ros::NodeHandle n;
    ros::start();
    goal_num = n.advertise<std_msgs::Int64>("/flipbot"+bot_no+"/dest",1000);
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


