#ifndef COMM_DEMO__SERVICE_SERVER_NODE_HPP_
#define COMM_DEMO__SERVICE_SERVER_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

namespace comm_demo
{

class ServiceServerNode : public rclcpp::Node
{
public:
  ServiceServerNode();

private:
  // 服务回调：处理加法请求
  void handle_add(
    const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
    std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response);

  // Service Server 对象：服务名 "add_two_ints"
  rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr service_;
};

}  // namespace comm_demo

#endif  // COMM_DEMO__SERVICE_SERVER_NODE_HPP_