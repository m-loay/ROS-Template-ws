#include <ros/ros.h>
#include <std_msgs/Int64.h>
#include <std_srvs/SetBool.h>
int counter;
ros::Publisher pub;

void callback_number(const std_msgs::Int64 msgs)
{
    counter+= msgs.data;
    std_msgs::Int64 new_msgs;
    new_msgs.data = counter;
    pub.publish(new_msgs);
}

bool callback_reset_counter(std_srvs::SetBool::Request& req, std_srvs::SetBool::Response& resp)
{
    if(req.data)
    {
        counter = 0;
        resp.success = true;
        resp.message = "Counter has been successfully reset";
    }
    else
    {
        resp.success = false;
        resp.message = "Counter has not been reset";
    }
    return true;
}

int main (int argc, char **argv)
{
    ros::init(argc,argv,"number_counter");
    ros::NodeHandle nh;

    ros::Subscriber sub(nh.subscribe("/number", 1000, callback_number));
    pub = nh.advertise<std_msgs::Int64>("/number_count", 10);

    ros::ServiceServer reset_service(nh.advertiseService("/reset_counter", callback_reset_counter));

    ros::spin();
}
