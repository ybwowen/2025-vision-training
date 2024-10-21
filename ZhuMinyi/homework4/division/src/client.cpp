#include "division/srv/division.hpp"
#include <chrono>
#include <memory>
#include <rclcpp/rclcpp.hpp>

class Service_client : public rclcpp::Node {
public:
  Service_client(std::string name) : Node(name) {
    client_ = this->create_client<division::srv::Division>("division");
    RCLCPP_INFO(this->get_logger(), "Start the client: %s.", name.c_str());
    std::cout << "Input dividend and divisor: " << std::endl;
    int a, b;
    std::cin >> a >> b;
    send_request(a, b);
  }

  void send_request(int64_t dividend, int64_t divisor) {
    while (!client_->wait_for_service(std::chrono::seconds(1))) {
      if (!rclcpp::ok()) {
        RCLCPP_ERROR(this->get_logger(),
                     "Client interrupted while waiting for service.");
        return;
      }
      RCLCPP_INFO(this->get_logger(), "Waiting...");
    }
    auto request = std::make_shared<division::srv::Division::Request>();
    request->dividend = dividend;
    request->divisor = divisor;

    auto result = client_->async_send_request(request);
  }

private:
  void handle_response(
      std::shared_future<std::shared_ptr<division::srv::Division::Response>>
          future) {
    auto response = future.get();
    RCLCPP_INFO(this->get_logger(),
                "Received result: quotient = %ld, remainder = %ld",
                response->quotient, response->remainder);
  }

  rclcpp::Client<division::srv::Division>::SharedPtr client_;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto client_node = std::make_shared<Service_client>("division_client");
  rclcpp::spin(client_node);
  rclcpp::shutdown();
  return 0;
}