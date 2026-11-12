#include "comm_demo/publisher_node.hpp"

namespace comm_demo
{

PublisherNode::PublisherNode()
: Node("publisher_node"), count_(0)
{
  // 创建 Publisher，话题名 "demo_topic"，队列长度 10
  publisher_ = this->create_publisher<example_interfaces::msg::String>(
    "demo_topic", 10);

  // 创建 500ms 定时器，周期性调用 timer_callback
  timer_ = this->create_wall_timer(
    std::chrono::milliseconds(500),
    std::bind(&PublisherNode::timer_callback, this));

  RCLCPP_INFO(this->get_logger(), "Publisher node started, topic: demo_topic");
}

void PublisherNode::timer_callback()
{
  auto message = example_interfaces::msg::String();
  message.data = "Hello from publisher, count = " + std::to_string(count_++);

  // 发布消息
  publisher_->publish(message);

  RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
}

}  // namespace comm_demo