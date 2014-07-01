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
  
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  ros::Subscriber controller_sub = n.subscribe("controller",1000,controllerCallback);


  ros::spin();
  switch(finger_name){
  case "ff":
    // ff est l'index  a attache au 9 
     ros::Publisher servo_pub = n.advertise<std_msgs/UInt16>("servo");
  default:
    break;

}
  return 0;
}
