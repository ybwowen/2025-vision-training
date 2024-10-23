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

        RCLCPP_INFO(this->get_logger(), "节点已启动:client");
        client_ = this->create_client<DivideWithRemainder>("divide");

        // Wait for the service to be available
        while (!client_->wait_for_service(std::chrono::seconds(1))) {
            if (!rclcpp::ok()) {
                RCLCPP_ERROR(this->get_logger(), "等待服务的过程中被打断...");
                return;
            }
            RCLCPP_INFO(this->get_logger(), "等待服务端上线中");
        }

        // Create a request and send it
        auto request = std::make_shared<DivideWithRemainder::Request>();
        request->dividend = dividend;
        request->divisor = divisor;

        RCLCPP_INFO(this->get_logger(), "Sending request: %ld / %ld", request->dividend, request->divisor);

        // Send the request and process the response asynchronously

    client_->async_send_request(
      request, std::bind(&DivideClientNode::result_callback_, this,
                         std::placeholders::_1));

    }

private:
    rclcpp::Client<DivideWithRemainder>::SharedPtr client_;

    void result_callback_(
        rclcpp::Client<DivideWithRemainder>::SharedFuture
        result_future) {
        auto response = result_future.get();
        RCLCPP_INFO(this->get_logger(), "计算结果:%ld,%ld", response->quotient,response->remainder);
  }
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