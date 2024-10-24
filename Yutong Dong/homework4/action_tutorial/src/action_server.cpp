#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include "action_tutorial/action/move.hpp"

using Move = action_tutorial::action::Move;
using GoalHandleMove = rclcpp_action::ServerGoalHandle<Move>;

class ActionServer : public rclcpp::Node {
public:
    ActionServer() : Node("action_server"), speed_(1.0), time_limit_(10.0) {
        this->action_server_ = rclcpp_action::create_server<Move>(
            this,
            "move_action",
            std::bind(&ActionServer::handle_goal, this, std::placeholders::_1, std::placeholders::_2),//目标处理
            std::bind(&ActionServer::handle_cancel, this, std::placeholders::_1),//取消处理
            std::bind(&ActionServer::handle_accepted, this, std::placeholders::_1));//接受处理
    }

private:
    rclcpp_action::Server<Move>::SharedPtr action_server_;
    double speed_;
    double time_limit_;

    rclcpp_action::GoalResponse handle_goal(
        const rclcpp_action::GoalUUID &uuid,
        std::shared_ptr<const Move::Goal> goal) {
        (void)uuid; // Suppress unused parameter warning
        RCLCPP_INFO(this->get_logger(), "Received goal request with distance: %f", goal->distance);
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    rclcpp_action::CancelResponse handle_cancel(
        const std::shared_ptr<GoalHandleMove> goal_handle) {
        (void)goal_handle; // Suppress unused parameter warning
        RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
        return rclcpp_action::CancelResponse::ACCEPT;
    }

    void handle_accepted(const std::shared_ptr<GoalHandleMove> goal_handle) {
        std::thread{
            [this, goal_handle]() {
                const auto goal = goal_handle->get_goal();
                double remaining_distance = goal->distance;
                rclcpp::Rate rate(1);

                while (remaining_distance > 0) {
                    remaining_distance -= speed_;
                    RCLCPP_INFO(this->get_logger(), "Remaining distance: %f", remaining_distance);
                    
                    // Create shared pointer for feedback
                    auto feedback = std::make_shared<Move::Feedback>();
                    feedback->remaining_distance = remaining_distance; 
                    goal_handle->publish_feedback(feedback);

                    rate.sleep();
                }

                // Create shared pointer for result
                auto result = std::make_shared<Move::Result>();
                result->success = true; // Ensure this field exists
                goal_handle->succeed(result);
            }
        }.detach();
    }
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ActionServer>());
    rclcpp::shutdown();
    return 0;
}
