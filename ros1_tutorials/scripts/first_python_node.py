#!/usr/bin/env python3
import rospy

if __name__ == '__main__':

    #Initialize the node
    rospy.init_node('first_python_node')

    #Print a ROS info
    rospy.loginfo('ROS Python Node has been started')

    #Select rate to execute the node
    rate = rospy.Rate(10)

    while not rospy.is_shutdown():

        #Print a ROS info
        rospy.loginfo('ROS Python Node is runining')

        #put node to sleep according to periode defined in Rate
        rate.sleep()