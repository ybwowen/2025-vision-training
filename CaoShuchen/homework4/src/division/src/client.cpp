#include "rclcpp/rclcpp.hpp"
#include "division_interface/srv/division.hpp"

class ServiceClient01 : public rclcpp::Node {
public:
  // 构造函数,有一个参数为节点名称
  ServiceClient01(std::string name) : Node(name) {
    RCLCPP_INFO(this->get_logger(), "节点已启动：%s.", name.c_str());
    // 创建客户端
    client_ = this->create_client<division_interface::srv::Division>("division");
  }

  void send_request(int a, int b) {
    RCLCPP_INFO(this->get_logger(), "计算%d/%d", a, b);

    // 1.等待服务端上线
    while (!client_->wait_for_service(std::chrono::seconds(1))) {
      //等待时检测rclcpp的状态
      if (!rclcpp::ok()) {
        RCLCPP_ERROR(this->get_logger(), "等待服务的过程中被打断...");
        return;
      }
      RCLCPP_INFO(this->get_logger(), "等待服务端上线中");
    }

    // 2.构造请求的
    auto request =
      std::make_shared<division_interface::srv::Division_Request>();
    request->dividend = a;
    request->divisor = b;

    // 3.发送异步请求，然后等待返回，返回时调用回调函数
    client_->async_send_request(
      request, std::bind(&ServiceClient01::result_callback_, this,
                         std::placeholders::_1));
  };

private:
  // 声明客户端
  rclcpp::Client<division_interface::srv::Division>::SharedPtr client_;

  void result_callback_(
    rclcpp::Client<division_interface::srv::Division>::SharedFuture
      result_future) {
    auto response = result_future.get();
    RCLCPP_INFO(this->get_logger(), "商：%ld，余： %ld", response->quotient, response->remainder);
  }
};
int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  /*创建对应节点的共享指针对象*/
  auto node = std::make_shared<ServiceClient01>("service_client_01");
  node->send_request(1919810, 114514);
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}