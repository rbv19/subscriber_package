#include "publisher_package/topic_name.h"

#include "ros/ros.h"

#include "std_msgs/String.h"

#ifndef TOPIC_NAME_H
#define TOPIC_NAME_H

#include <string>

std::string topic_name("new_topic_name");

#endif


void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
	ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main	(int argc, char **argv)
	
{

	ros::init(argc, argv, "subscriber_node");

	ros::NodeHandle n;

	ros::Subscriber sub = n.subscribe("publisher_topic", 1000, chatterCallback);

	ros::spin();

	return 0;
}




