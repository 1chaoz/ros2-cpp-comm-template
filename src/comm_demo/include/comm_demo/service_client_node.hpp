#ifndef COMM_DEMO__SERVICE_CLIENT_NODE_HPP_
#define COMM_DEMO__SERVICE_CLIENT_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

namespace comm_demo
{

class ServiceClientNode : public rclcpp::Node
{
public:
  ServiceClientNode();

  // 对外暴露一个同步风格的发送方法：等待服务端，发送请求，等待响应
  void send_request(int64_t a, int64_t b);

private:
  // Service Client 对象：连接到 "add_two_ints"
  rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedPtr client_;
};

}  // namespace comm_demo

#endif  // COMM_DEMO__SERVICE_CLIENT_NODE_HPP_