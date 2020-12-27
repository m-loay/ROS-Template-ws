#include <ros/ros.h>
#include <ros1_tutorials_msgs/HardwareStatus.h>

int main (int argc, char **argv)
{
    ros::init(argc,argv,"Hardware_Status_Publisher");
    ros::NodeHandle nh;

    ros::Publisher pub(nh.advertise<ros1_tutorials_msgs::HardwareStatus>("/ros1_tutorials/hardware_status",10));
    ros::Rate rate(10);

    while(ros::ok())
    {
        ros1_tutorials_msgs::HardwareStatus msg;
        msg.are_motors_up = true;
        msg.debug_message = "Updating...No Errors";
        msg.temperature = 30;
        pub.publish(msg);
        rate.sleep();
    }
}