#include "rclcpp/rclcpp.hpp"
#include "divide_interface/srv/divide.hpp"

#include <chrono>
#include <cstdlib>
#include <memory>

using namespace std::chrono_literals;


using DivideWithRemainder = divide_interface::srv::Divide;

class DivideClientNode : public rclcpp::Node {
public:
    DivideClientNode(int dividend, int divisor) : Node("divide_client") {
        client_ = this->create_client<DivideWithRemainder>("divide");

        // Wait for the service to be available
        while (!client_->wait_for_service(1s)) {
            RCLCPP_INFO(this->get_logger(), "Waiting for the service to be available...");
        }

        // Create a request and send it
        auto request = std::make_shared<DivideWithRemainder::Request>();
        request->dividend = dividend;
        request->divisor = divisor;

        RCLCPP_INFO(this->get_logger(), "Sending request: %d / %d", request->dividend, request->divisor);

        // Send the request and process the response asynchronously

        while (!client_->wait_for_service(1s)) {
          if (!rclcpp::ok()) {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
          }
          RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
        }

        auto result_future = client_->async_send_request(request);

		auto result = result_future.get();
		RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Result of %d / %d: Quotient = %d, Remainder = %d",
					request->dividend, request->divisor, result->quotient, result->remainder);

    }

private:
    rclcpp::Client<DivideWithRemainder>::SharedPtr client_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    if (argc != 3) {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Usage: divide_client dividend divisor");
        return 1;
    }
    int dividend = std::atoi(argv[1]);
    int divisor = std::atoi(argv[2]);

    auto node = std::make_shared<DivideClientNode>(dividend, divisor);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}