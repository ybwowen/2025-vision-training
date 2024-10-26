#include "rclcpp/rclcpp.hpp"
#include "divide_interface/srv/divide.hpp"

#include <memory>

class DivisionServer : public rclcpp::Node
{
public:
  DivisionServer()
  : Node("division_server")
  {
    RCLCPP_INFO(this->get_logger(), "节点已启动：%s.","division_server");
    service_ = create_service<divide_interface::srv::Divide>(
      "divide", std::bind(&DivisionServer::handle_division_request, this,
      std::placeholders::_1, std::placeholders::_2));
  }

private:
  void handle_division_request(
    const std::shared_ptr<divide_interface::srv::Divide::Request> request,
    std::shared_ptr<divide_interface::srv::Divide::Response> response)
  {
    RCLCPP_INFO(
      this->get_logger(),
      "Incoming request\ndividend: %ld\ndivisor: %ld",
      request->dividend, request->divisor);

    if (request->divisor == 0) {
      RCLCPP_ERROR(this->get_logger(), "Division by zero is not allowed");
      response->quotient = 0;
      response->remainder = 0;
      return;
    } 
    response->quotient = request->dividend / request->divisor;
    response->remainder = request->dividend % request->divisor;
  
  }

  rclcpp::Service<divide_interface::srv::Divide>::SharedPtr service_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DivisionServer>());
  rclcpp::shutdown();
  return 0;
}