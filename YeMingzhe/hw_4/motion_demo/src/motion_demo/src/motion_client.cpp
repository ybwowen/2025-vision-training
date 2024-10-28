#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <example_interfaces/action/fibonacci.hpp>
#include <chrono>

using namespace std::chrono_literals;

class MotionClient : public rclcpp::Node {
public:
    using Fibonacci = example_interfaces::action::Fibonacci;
    using GoalHandleFibonacci = rclcpp_action::ClientGoalHandle<Fibonacci>;

    explicit MotionClient()
    : Node("motion_client") {
        this->declare_parameter("s", 10.0);
        s_ = this->get_parameter("s").as_double();
        
        client_ = rclcpp_action::create_client<Fibonacci>(this, "move_robot");
        send_goal(s_);
    }

private:
    void send_goal(double distance) {
        if (!client_->wait_for_action_server(std::chrono::seconds(10))) {
            RCLCPP_ERROR(this->get_logger(), "Action server not available");
            return;
        }

        auto goal_msg = Fibonacci::Goal();
        goal_msg.order = static_cast<int>(distance);
        
        auto send_goal_options = rclcpp_action::Client<Fibonacci>::SendGoalOptions();
        
        // 设置目标响应回调函数，确保参数类型为 std::shared_ptr<GoalHandleFibonacci>
        send_goal_options.goal_response_callback = [this](const GoalHandleFibonacci::SharedPtr goal_handle) {
            if (!goal_handle) {
                RCLCPP_ERROR(this->get_logger(), "Goal was rejected by server");
            } else {
                RCLCPP_INFO(this->get_logger(), "Goal accepted by server");
            }
        };

        // 设置反馈回调函数
        send_goal_options.feedback_callback = [this](GoalHandleFibonacci::SharedPtr, const std::shared_ptr<const Fibonacci::Feedback> feedback) {
            RCLCPP_INFO(this->get_logger(), "Remaining distance: %d", feedback->sequence.back());
        };

        // 设置结果回调函数
        send_goal_options.result_callback = [this](const GoalHandleFibonacci::WrappedResult &result) {
            if (result.code == rclcpp_action::ResultCode::SUCCEEDED) {
                RCLCPP_INFO(this->get_logger(), "Goal succeeded");
            } else if (result.code == rclcpp_action::ResultCode::ABORTED) {
                RCLCPP_INFO(this->get_logger(), "Goal failed, retrying with half distance");
                send_goal(result.result->sequence[0] / 2.0);
            } else {
                RCLCPP_WARN(this->get_logger(), "Goal was canceled");
            }
        };

        client_->async_send_goal(goal_msg, send_goal_options);
    }

    rclcpp_action::Client<Fibonacci>::SharedPtr client_;
    double s_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MotionClient>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

