#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"

#include "comm_demo/publisher_node.hpp"
#include "comm_demo/subscriber_node.hpp"
#include "comm_demo/service_server_node.hpp"
#include "comm_demo/service_client_node.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  if (argc < 2) {
    RCLCPP_ERROR(
      rclcpp::get_logger("main"),
      "Usage: ros2 run comm_demo comm_demo_node <publisher|subscriber|service_server|service_client>");
    rclcpp::shutdown();
    return 1;
  }

  std::string mode = argv[1];
  rclcpp::Node::SharedPtr node;

  if (mode == "publisher") {
    node = std::make_shared<comm_demo::PublisherNode>();
  } else if (mode == "subscriber") {
    node = std::make_shared<comm_demo::SubscriberNode>();
  } else if (mode == "service_server") {
    node = std::make_shared<comm_demo::ServiceServerNode>();
  } else if (mode == "service_client") {
    auto client_node = std::make_shared<comm_demo::ServiceClientNode>();
    
    // 发送请求（不阻塞，直接返回）
    client_node->send_request(3, 5);
    
    // 让节点转起来，等待回调触发
    rclcpp::spin(client_node);
    
    rclcpp::shutdown();
    return 0;
  } else {
    RCLCPP_ERROR(rclcpp::get_logger("main"), "Unknown mode: %s", mode.c_str());
    rclcpp::shutdown();
    return 1;
  }

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}