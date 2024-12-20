#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "ackermann_msgs/msg/ackermann_drive_stamped.hpp"


class Talker : public rclcpp::Node
{
    rclcpp::Publisher<ackermann_msgs::msg::AckermannDriveStamped>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    void publishMessage()
    {
        auto message = ackermann_msgs::msg::AckermannDriveStamped();
        message.header.stamp = this->get_clock()->now();
        message.header.frame_id = "base_link";
        message.drive.speed = this->get_parameter("v").as_double();    
        message.drive.steering_angle = this->get_parameter("d").as_double();  
        RCLCPP_INFO(this->get_logger(), "Publishing: speed=%f, steering_angle=%f",
                    message.drive.speed, message.drive.steering_angle);
        publisher_->publish(message);
    }
  public:
    Talker()
    : Node("talker")
    {
        this->declare_parameter("v", 0.0);
        this->declare_parameter("d", 0.0);
        publisher_ = this->create_publisher<ackermann_msgs::msg::AckermannDriveStamped>("drive", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(500),std::bind(&Talker::publishMessage, this));
      //std::chrono::nanoseconds(1)
    }

    
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Talker>());
    rclcpp::shutdown();
    return 0;
}