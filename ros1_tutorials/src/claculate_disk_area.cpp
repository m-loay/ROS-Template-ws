#include <ros/ros.h>
#include <ros1_tutorials_msgs/ComputeDiskArea.h>
#include <math.h>
#include <iostream>
#define _USE_MATH_DEFINES

bool handle_disk_area(ros1_tutorials_msgs::ComputeDiskArea::Request &req,
                      ros1_tutorials_msgs::ComputeDiskArea::Response &res)
{
    res.area = M_PI * pow(req.radius,2);
    ROS_INFO("Area of radius(%f) = %f",(double)req.radius, (double)res.area);
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Calculate_Disk_Area");
    ros::NodeHandle nh;

    ros::ServiceServer server(nh.advertiseService("/ros1_tutorials/Calculate_Disk_Area", handle_disk_area));
    ros::spin();
}