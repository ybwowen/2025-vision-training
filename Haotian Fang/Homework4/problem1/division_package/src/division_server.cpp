#include "rclcpp/rclcpp.hpp"
#include "division_interfaces/srv/division_service.hpp"

#include <memory>

class DivisionServer : public rclcpp::Node
{
public:
  DivisionServer()
  : Node("division_server")
  {
    service_ = create_service<division_interfaces::srv::DivisionService>(
      "division", std::bind(&DivisionServer::handle_division_request, this,
      std::placeholders::_1, std::placeholders::_2));
  }

private:
  void handle_division_request(
    const std::shared_ptr<division_interfaces::srv::DivisionService::Request> request,
    std::shared_ptr<division_interfaces::srv::DivisionService::Response> response)
  {
    RCLCPP_INFO(
      this->get_logger(),
      "Incoming request\ndividend: %ld\ndivisor: %ld",
      request->dividend, request->divisor);

    if (request->divisor == 0) {
      RCLCPP_ERROR(this->get_logger(), "Division by zero is not allowed");
      response->quotient = 0;
      response->remainder = 0;
    } else {
      response->quotient = request->dividend / request->divisor;
      response->remainder = request->dividend % request->divisor;
    }
  }

  rclcpp::Service<division_interfaces::srv::DivisionService>::SharedPtr service_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DivisionServer>());
  rclcpp::shutdown();
  return 0;
}