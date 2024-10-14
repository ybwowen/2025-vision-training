#include "rclcpp/rclcpp.hpp"
#include "division_interfaces/srv/division_service.hpp"

#include <chrono>
#include <cstdlib>
#include <memory>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  if (argc != 3) {
      RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Usage: division_client <dividend> <divisor>");
      return 1;
  }

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("division_client");
  rclcpp::Client<division_interfaces::srv::DivisionService>::SharedPtr client =
    node->create_client<division_interfaces::srv::DivisionService>("division");

  auto request = std::make_shared<division_interfaces::srv::DivisionService::Request>();
  request->dividend = atoll(argv[1]);
  request->divisor = atoll(argv[2]);

  if (request->divisor == 0) {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Division by zero is not allowed");
    rclcpp::shutdown();
    return 1;
  }

  while (!client->wait_for_service(1s)) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
      return 0;
    }
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
  }

  auto result_future = client->async_send_request(request);
  
  if (rclcpp::spin_until_future_complete(node, result_future) ==
    rclcpp::FutureReturnCode::SUCCESS)
  {
    auto result = result_future.get();
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Result of %ld / %ld: Quotient = %ld, Remainder = %ld",
                request->dividend, request->divisor, result->quotient, result->remainder);
  } else {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service division");
  }

  rclcpp::shutdown();
  return 0;
}