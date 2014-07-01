#include "Arduino.h"
#include <Servo.h> 
#include "ros/ros.h"
#include "ros_inmoov_hand/moov.h"
#include <std_msgs/UInt16.h>

String finger_name ;
int move_finger ;

void controllerCallback(const ros_inmoov_hand::moov& mv)
{
  ROS_INFO("I heard: %s  %d ", mv.finger.c_str(),mv.angle);
  finger_name = mv.finger ;
  move_finger = mv.angle ;
}

int main(int argc, char **argv)
{
  // node init 
  ros::init(argc, argv, "hand");
  
  // The node's handler  
  ros::NodeHandle n;

  // subsribe to the topic "controller"   
  ros::Subscriber controller_sub = n.subscribe("controller",1000,controllerCallback);

  default:
    break;
    
}
  return 0;
}
