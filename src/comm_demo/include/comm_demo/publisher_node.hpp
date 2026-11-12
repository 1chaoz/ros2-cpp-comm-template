#ifndef COMM_DEMO__PUBLISHER_NODE_HPP_
#define COMM_DEMO__PUBLISHER_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

namespace comm_demo
{

class PublisherNode : public rclcpp::Node
{
public:
  PublisherNode();

private:
  // 定时器回调：周期性发布消息
  void timer_callback();

  // Publisher 对象：发布 std_msgs/String 到话题 "demo_topic"
  rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;

  // 定时器对象：驱动发布周期
  rclcpp::TimerBase::SharedPtr timer_;

  // 发布计数器，用于让每条消息内容不同
  size_t count_;
};

}  // namespace comm_demo

#endif  // COMM_DEMO__PUBLISHER_NODE_HPP_