#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/srv/modulus_division.hpp"

class ModulusDivisionClient : public rclcpp::Node {
public:
  ModulusDivisionClient(std::string name) : Node(name) {
    RCLCPP_INFO(this->get_logger(), "节点已启动：%s.", name.c_str());
    // 创建客户端
    client_ = this->create_client<custom_interfaces::srv::ModulusDivision>("modulus_division_srv");
  }

  void send_request(int dividend, int divisor) {
    RCLCPP_INFO(this->get_logger(), "请求计算 %d / %d", dividend, divisor);

    // 等待服务端上线
    while (!client_->wait_for_service(std::chrono::seconds(1))) {
      if (!rclcpp::ok()) {
        RCLCPP_ERROR(this->get_logger(), "等待服务的过程中被打断...");
        return;
      }
      RCLCPP_INFO(this->get_logger(), "等待服务端上线中");
    }

    // 构造请求
    auto request = std::make_shared<custom_interfaces::srv::ModulusDivision::Request>();
    request->dividend = dividend;
    request->divisor = divisor;

    // 发送异步请求
    client_->async_send_request(
      request, std::bind(&ModulusDivisionClient::result_callback_, this, std::placeholders::_1));
  }

private:
  // 声明客户端
  rclcpp::Client<custom_interfaces::srv::ModulusDivision>::SharedPtr client_;

  void result_callback_(rclcpp::Client<custom_interfaces::srv::ModulusDivision>::SharedFuture result_future) {
    auto response = result_future.get();
    RCLCPP_INFO(this->get_logger(), "计算结果：商=%ld, 余数=%ld", response->quotient, response->remainder);
  }
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<ModulusDivisionClient>("modulus_division_client");
  node->send_request(10, 3);  // 示例请求
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
