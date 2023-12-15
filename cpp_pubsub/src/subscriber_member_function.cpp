#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <nav_msgs/msg/odometry.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>


using std::placeholders::_1;

std::ofstream gps_out("e.txt");


class MinimalSubscriber : public rclcpp::Node
{
  public:
    MinimalSubscriber()
    : Node("minimal_subscriber")
    {
      subscription_ = this->create_subscription<nav_msgs::msg::Odometry>(
      "/stereo_slam/estimated_pose", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
    }

  private:
    void topic_callback(const nav_msgs::msg::Odometry & msg) const
    {
      double time = rclcpp::Time(msg.header.stamp.sec, msg.header.stamp.nanosec).seconds();
      RCLCPP_INFO(this->get_logger(), "I heard: '%f'", msg.pose.pose.position.x);
      gps_out << std::setw(20) << std::fixed<< time << " " << msg.pose.pose.position.x << " " << msg.pose.pose.position.y << " " << msg.pose.pose.position.z << " " 
              << msg.pose.pose.orientation.x << " " << msg.pose.pose.orientation.y << " " << msg.pose.pose.orientation.z << " " 
              << msg.pose.pose.orientation.w << std::endl;
    }
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}