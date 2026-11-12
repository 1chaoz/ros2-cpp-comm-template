#include "comm_demo/service_server_node.hpp"

namespace comm_demo
{

ServiceServerNode::ServiceServerNode()
: Node("service_server_node")
{
  // 创建 Service Server，服务名 "add_two_ints"
  service_ = this->create_service<example_interfaces::srv::AddTwoInts>(
    "add_two_ints",
    std::bind(
      &ServiceServerNode::handle_add, this,
      std::placeholders::_1, std::placeholders::_2));

  RCLCPP_INFO(this->get_logger(), "Service server ready: add_two_ints");
}

void ServiceServerNode::handle_add(
  const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
  std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response)
{
  // 服务端计算逻辑
  response->sum = request->a + request->b;

  RCLCPP_INFO(
    this->get_logger(),
    "Request: a=%ld, b=%ld | Response: sum=%ld",
    request->a, request->b, response->sum);
}

}  // namespace comm_demo