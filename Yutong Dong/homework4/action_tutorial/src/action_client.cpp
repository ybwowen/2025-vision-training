#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include "action_tutorial/action/move.hpp"

using Move = action_tutorial::action::Move;

class ActionClient : public rclcpp::Node {
public:
    ActionClient() : Node("action_client"), distance_(10.0), speed_(1.0), time_limit_(10.0) {
        this->client_ = rclcpp_action::create_client<Move>(this, "move_action");
        
        while (!client_->wait_for_action_server(std::chrono::seconds(1))) {
            RCLCPP_INFO(this->get_logger(), "Waiting for action server...");
        }
        send_goal();
    }

private:
    rclcpp_action::Client<Move>::SharedPtr client_;
    double distance_;
    double speed_;
    double time_limit_;

    void send_goal() {
        while (distance_ > 0) {
            auto goal = Move::Goal();
            goal.distance = distance_;

            RCLCPP_INFO(this->get_logger(), "Sending goal: %f", goal.distance);
            auto send_goal_options = rclcpp_action::Client<Move>::SendGoalOptions();
            send_goal_options.result_callback =
                std::bind(&ActionClient::handle_result, this, std::placeholders::_1);

            auto goal_handle_future = client_->async_send_goal(goal, send_goal_options);
            if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), goal_handle_future) !=
                rclcpp::FutureReturnCode::SUCCESS) {
                RCLCPP_ERROR(this->get_logger(), "Failed to send goal");
                return;
            }

            
            auto goal_handle = goal_handle_future.get();
            if (!goal_handle) {
                RCLCPP_ERROR(this->get_logger(), "Goal was rejected");
                distance_ /= 2; // 距离减半
                continue;
            }

            
            auto start_time = this->now();
            while (rclcpp::ok()) {
                // 检查是否超时
                if (this->now() - start_time > rclcpp::Duration::from_seconds(time_limit_)) {
                    RCLCPP_WARN(this->get_logger(), "Action timeout! Reducing distance.");
                    distance_ /= 2; // 距离减半
                    break; 
                }

                // 检查目标状态
                if (goal_handle->get_status() == rclcpp_action::GoalStatus::STATUS_SUCCEEDED) {
                    RCLCPP_INFO(this->get_logger(), "Action succeeded!");
                    break; 
                }

                rclcpp::sleep_for(std::chrono::milliseconds(100));
            }
        }
    }

    void handle_result(const rclcpp_action::ClientGoalHandle<Move>::WrappedResult &result) {
        if (result.code == rclcpp_action::ResultCode::SUCCEEDED) {
            RCLCPP_INFO(this->get_logger(), "Action succeeded!");
        } else {
            RCLCPP_INFO(this->get_logger(), "Action failed!");
        }
    }
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ActionClient>());
    rclcpp::shutdown();
    return 0;
}
