#include "division/srv/DivideInt.hpp"
#include "rclcpp/rclcpp.hpp"

using DivideInt = division::srv::Divideint;

class DivisionServer : public rclcpp::Node {
public:
  DivisionServer() : Node("division_server") {
    service_ = this->create_service<DivideInt>(
        "divide_two_ints",
        std::bind(&DivisionServer::handle_service, this, std::placeholders::_1,
                  std::placeholders::_2));
    RCLCPP_INFO(this->get_logger(),
                "Service 'divide_two_ints' ready to receive requests.");
  }

private:
  void handle_service(const std::shared_ptr<DivideInt::Request> request,
                      std::shared_ptr<DivideInt::Response> response) {
    if (request->b == 0) {
      RCLCPP_WARN(this->get_logger(), "Division by zero is undefined.");
      response->q = 0;
      response->r = 0;
    } else {
      response->q = request->a / request->b;
      response->r = request->a % request->b;
      RCLCPP_INFO(this->get_logger(), "Request: a=%ld, b=%ld => q=%ld, r=%ld",
                  request->a, request->b, response->q, response->r);
    }
  }

  rclcpp::Service<DivideInt>::SharedPtr service_;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<DivisionServer>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
