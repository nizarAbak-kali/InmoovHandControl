#include "ros/ros.h"
#include "ros_inmoov_hand/moov.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "commander");
  ros::NodeHandle n;
  ros::Publisher controller_pub = n.advertise<ros_inmoov_hand::moov>("controller", 1000);
  ros::Rate loop_rate(10);

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
  int count = 0;
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    ros_inmoov_hand::moov mv;
    mv.angle=1;
    mv.finger="ff";
    ROS_INFO("%s  %d %d", mv.finger.c_str(),mv.angle,count);

  
    controller_pub.publish(mv);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;

}
