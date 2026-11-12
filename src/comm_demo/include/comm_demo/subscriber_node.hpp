#ifndef COMM_DEMO__SUBSCRIBER_NODE_HPP_
#define COMM_DEMO__SUBSCRIBER_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

namespace comm_demo
{

class SubscriberNode : public rclcpp::Node
{
public:
  SubscriberNode();

private:
  // 订阅回调：收到消息后执行
  void topic_callback(const example_interfaces::msg::String::SharedPtr msg);

  // Subscriber 对象：订阅 "demo_topic"
  rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscription_;
};

}  // namespace comm_demo

#endif  // COMM_DEMO__SUBSCRIBER_NODE_HPP_