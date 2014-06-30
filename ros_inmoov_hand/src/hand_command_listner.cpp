#include "ros/ros.h""
#include "ros_inmoov_hand/moov.h"
 
void controllerCallback(const ros_inmoov_hand::moov& mv)
{
  ROS_INFO("I heard: %s  %d ", mv.finger.c_str(),mv.angle);
}

int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber controller_sub = n.subscribe("controller", 1000,controllerCallback);
  ros::spin();

  return 0;
}
