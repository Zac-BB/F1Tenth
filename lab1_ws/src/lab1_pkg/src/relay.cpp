#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "ackermann_msgs/msg/ackermann_drive_stamped.hpp"



class Relay : public rclcpp::Node
{
    rclcpp::Publisher<ackermann_msgs::msg::AckermannDriveStamped>::SharedPtr publisher_;
    rclcpp::Subscription<ackermann_msgs::msg::AckermannDriveStamped>::SharedPtr subscription_;
  public:
    Relay()
    : Node("relay")
    {
      subscription_ = this->create_subscription<ackermann_msgs::msg::AckermannDriveStamped>("drive", 10, std::bind(&Relay::callback, this,std::placeholders::_1));
      publisher_ = this->create_publisher<ackermann_msgs::msg::AckermannDriveStamped>("drive_relay", 10);
    }

  private:
    void callback(const ackermann_msgs::msg::AckermannDriveStamped::SharedPtr msg)
    {
    //   RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
        auto message = ackermann_msgs::msg::AckermannDriveStamped();
        message.header.stamp = this->get_clock()->now();
        message.header.frame_id = "base_link";
        message.drive.speed = msg->drive.speed * 3.0;    
        message.drive.steering_angle = msg->drive.steering_angle * 3.0;  
        // RCLCPP_INFO(this->get_logger(), "Publishing: speed=%f, steering_angle=%f",message.drive.speed, message.drive.steering_angle);
        publisher_->publish(message);
    }
    
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Relay>());
  rclcpp::shutdown();
  return 0;
}