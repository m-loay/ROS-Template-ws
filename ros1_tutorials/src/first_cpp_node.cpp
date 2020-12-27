#include <ros/ros.h>

int main (int argc, char **argv)
{
    //Initialize the node
    ros::init(argc, argv, "first_cpp_node");

    //Create a node handle
    ros::NodeHandle nh;

    //Print a ROS info
    ROS_INFO("ROS CPP Node has been started");
    
    //Select rate to execute the node
    ros::Rate rate(10);

    while (ros::ok()) 
    {
        //Print a ROS info
        ROS_INFO("ROS CPP Node is runining");

        //put node to sleep according to periode defined in Rate
        rate.sleep();
    }
}