#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "action_demo/srv/action.hpp"

class ActionClient : public rclcpp::Node {
public:
    ActionClient() : Node("action_client") {
        client_ = this->create_client<action_demo::srv::Action>("move_robot");
        while (!client_->wait_for_service(std::chrono::seconds(1))) {
            RCLCPP_INFO(this->get_logger(), "Service not available, waiting...");
        }
        send_request(10.0);  // 初始请求距离
    }

private:
    void send_request(double distance) {
        auto request = std::make_shared<action_demo::srv::Action::Request>();
        request->distance = distance;

        auto result_future = client_->async_send_request(request);
        if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result_future) ==
            rclcpp::FutureReturnCode::SUCCESS) {
            auto response = result_future.get();
            if (response->success) {
                RCLCPP_INFO(this->get_logger(), "Move completed successfully, remaining distance: %.2f", response->remaining_distance);
            } else {
                RCLCPP_INFO(this->get_logger(), "Move failed, retrying with half distance: %.2f", distance / 2);
                send_request(distance / 2);
            }
        } else {
            RCLCPP_ERROR(this->get_logger(), "Failed to call service");
        }
    }

    rclcpp::Client<action_demo::srv::Action>::SharedPtr client_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ActionClient>());
    rclcpp::shutdown();
    return 0;
}
