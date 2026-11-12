#include "comm_demo/service_client_node.hpp"

namespace comm_demo
{

ServiceClientNode::ServiceClientNode()
: Node("service_client_node")
{
  // 创建 Service Client，服务名必须与服务端一致
  client_ = this->create_client<example_interfaces::srv::AddTwoInts>(
    "add_two_ints");

  RCLCPP_INFO(this->get_logger(), "Service client created: add_two_ints");
}

void ServiceClientNode::send_request(int64_t a, int64_t b)
{
  // 1. 等待服务端上线，最多等 2 秒
  if (!client_->wait_for_service(std::chrono::seconds(2))) {
    RCLCPP_ERROR(this->get_logger(), "Service 'add_two_ints' not available");
    return;
  }

  // 2. 构造请求
  auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
  request->a = a;
  request->b = b;

  // 3. 异步发送请求，并指定回调函数处理响应
  client_->async_send_request(request,
    [this, a, b](rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedFuture future) {
      // 这个 lambda 函数会在收到响应时自动执行
      auto response = future.get();
      RCLCPP_INFO(
        this->get_logger(), "Request: a=%ld, b=%ld | Result: sum=%ld", 
        a, b, response->sum);
      
      // 收到结果后，如果不再需要客户端，可以直接让节点退出
      rclcpp::shutdown();
    });
}

}  // namespace comm_demo