#include <ros.h>
#include <std_msgs/UInt32.h>

ros::NodeHandle  nh;
std_msgs::UInt32 my_data;
ros::Publisher pub_ardu("/arduino_data", &my_data);

long publisher_timer;

void setup()
{
  nh.initNode();
  nh.advertise(pub_ardu);
}

void loop()
{
  if (millis() > publisher_timer) {
    delay(10);
    my_data.data = random(1000);
    pub_ardu.publish(&my_data);
    publisher_timer = millis() + 1000;
  }
  nh.spinOnce();
}
