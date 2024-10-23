#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "action_demo/srv/action.hpp"

class ActionServer : public rclcpp::Node {
public:
    ActionServer() : Node("action_server") {
        this->declare_parameter<double>("speed", 1.0);
        this->declare_parameter<double>("time_limit", 10.0);
        service_ = this->create_service<action_demo::srv::Action>(
            "move_robot", std::bind(&ActionServer::handle_request, this, std::placeholders::_1, std::placeholders::_2));
    }

private:
    void handle_request(const std::shared_ptr<action_demo::srv::Action::Request> request,
                        std::shared_ptr<action_demo::srv::Action::Response> response) {
        double remaining_distance = request->distance;
        double speed = this->get_parameter("speed").get_value<double>();
        double time_limit = this->get_parameter("time_limit").get_value<double>();
        
        double time_elapsed = 0.0;

        while (remaining_distance > 0 && time_elapsed < time_limit) {
            remaining_distance -= speed;
            time_elapsed += 1.0; // 假设每秒循环一次
            RCLCPP_INFO(this->get_logger(), "Remaining distance: %.2f", remaining_distance);
            rclcpp::sleep_for(std::chrono::seconds(1));
        }

        response->remaining_distance = remaining_distance;
        response->success = (remaining_distance <= 0);
    }

    rclcpp::Service<action_demo::srv::Action>::SharedPtr service_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ActionServer>());
    rclcpp::shutdown();
    return 0;
}
