#include "division/srv/division.hpp"
#include <memory>
#include <rclcpp/rclcpp.hpp>

class Service_server : public rclcpp::Node {
public:
  Service_server(std::string name) : Node(name) {
    service_ = this->create_service<division::srv::Division>(
        "division", std::bind(&Service_server::division_service, this,
                              std::placeholders::_1, std::placeholders::_2));
    RCLCPP_INFO(this->get_logger(), "Start the server: %s.", name.c_str());
  }

private:
  void division_service(
      const std::shared_ptr<division::srv::Division::Request> request,
      std::shared_ptr<division::srv::Division::Response> response) {
    if (request->divisor == 0) {
      RCLCPP_ERROR(this->get_logger(), "Can't be divided by zero.");
      return;
    }
    response->quotient = request->dividend / request->divisor;
    response->remainder = request->dividend % request->divisor;
    RCLCPP_INFO(this->get_logger(),
                "Request: dividend=%ld, divisor=%ld; Response: quotient=%ld, "
                "remainder=%ld",
                request->dividend, request->divisor, response->quotient,
                response->remainder);
  }
  rclcpp::Service<division::srv::Division>::SharedPtr service_;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto server_node = std::make_shared<Service_server>("division_server");
  rclcpp::spin(server_node);
  rclcpp::shutdown();
  return 0;
}