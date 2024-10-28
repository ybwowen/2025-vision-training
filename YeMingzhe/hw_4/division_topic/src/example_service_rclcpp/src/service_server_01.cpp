#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/srv/modulus_division.hpp"

class ModulusDivisionServer : public rclcpp::Node {
public:
  ModulusDivisionServer(std::string name) : Node(name) {
    RCLCPP_INFO(this->get_logger(), "节点已启动：%s.", name.c_str());
    // 创建服务
    division_server_ = this->create_service<custom_interfaces::srv::ModulusDivision>(
      "modulus_division_srv",
      std::bind(&ModulusDivisionServer::handle_modulus_division, this,
                std::placeholders::_1, std::placeholders::_2));
  }

private:
  // 声明一个服务
  rclcpp::Service<custom_interfaces::srv::ModulusDivision>::SharedPtr division_server_;

  // 处理请求的回调函数
  void handle_modulus_division(
    const std::shared_ptr<custom_interfaces::srv::ModulusDivision::Request> request,
    std::shared_ptr<custom_interfaces::srv::ModulusDivision::Response> response) {
    if (request->divisor == 0) {
      RCLCPP_WARN(this->get_logger(), "除数不能为 0");
      response->quotient = 0;
      response->remainder = request->dividend;
    } else {
      response->quotient = request->dividend / request->divisor;
      response->remainder = request->dividend % request->divisor;
      RCLCPP_INFO(this->get_logger(), "计算结果：商=%ld, 余数=%ld", response->quotient, response->remainder);
    }
  }
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<ModulusDivisionServer>("modulus_division_server");
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
