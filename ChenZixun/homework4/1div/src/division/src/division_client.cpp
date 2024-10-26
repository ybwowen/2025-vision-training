#include "rclcpp/rclcpp.hpp"
#include "division/srv/DivideInt.hpp"
#include <chrono>

using DivideInt = division::srv::Divideint;
using namespace std::chrono_literals;

class DivisionClient : public rclcpp::Node {
public:
    DivisionClient() : Node("division_client")
    {
        client_ = this->create_client<DivideInt>("divide_two_ints");
    }

    void send_request(int64_t a, int64_t b)
    {
        auto request = std::make_shared<DivideInt::Request>();
        request->a = a;
        request->b = b;

        while (!client_->wait_for_service(1s))
        {
            RCLCPP_WARN(this->get_logger(), "Waiting for the service to be available...");
        }

        auto result = client_->async_send_request(request);
        if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result) == rclcpp::FutureReturnCode::SUCCESS)
        {
            auto response = result.get();
            RCLCPP_INFO(this->get_logger(), "Response: q=%ld, r=%ld", response->q, response->r);
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to call service divide_two_ints");
        }
    }
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<DivisionClient>();

    if (argc != 3) {
        RCLCPP_ERROR(node->get_logger(), "Usage: division_client a b");
        return 1;
    }

    int64_t a = std::stoll(argv[1]);
    int64_t b = std::stoll(argv[2]);

    node->send_request(a, b);
    rclcpp::shutdown();
    return 0;
}
