#include "comm_demo/subscriber_node.hpp"

namespace comm_demo
{

SubscriberNode::SubscriberNode()
: Node("subscriber_node")
{
  // 创建 Subscriber，话题名必须与 Publisher 一致
  subscription_ = this->create_subscription<example_interfaces::msg::String>(
    "demo_topic", 10,
    std::bind(&SubscriberNode::topic_callback, this, std::placeholders::_1));

  RCLCPP_INFO(this->get_logger(), "Subscriber node started, listening: demo_topic");
}

void SubscriberNode::topic_callback(
  const example_interfaces::msg::String::SharedPtr msg)
{
  RCLCPP_INFO(this->get_logger(), "Received: '%s'", msg->data.c_str());
}

}  // namespace comm_demo