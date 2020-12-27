#include <ros/ros.h>
#include <std_msgs/Int64.h>
int counter;
ros::Publisher pub;

void callback_number(const std_msgs::Int64 msgs)
{
    counter+= msgs.data;
    std_msgs::Int64 new_msgs;
    new_msgs.data = counter;
    pub.publish(new_msgs);
}

int main (int argc, char **argv)
{
    ros::init(argc,argv,"number_counter");
    ros::NodeHandle nh;

    ros::Subscriber sub(nh.subscribe("/number", 1000, callback_number));
    pub = nh.advertise<std_msgs::Int64>("/number_count", 10);

    ros::spin();
}