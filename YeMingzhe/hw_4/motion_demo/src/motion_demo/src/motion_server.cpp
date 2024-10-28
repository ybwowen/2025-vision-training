#include <chrono>
#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <example_interfaces/action/fibonacci.hpp>

using namespace std::chrono_literals;

class MotionServer : public rclcpp::Node {
public:
    using Fibonacci = example_interfaces::action::Fibonacci;
    using GoalHandleFibonacci = rclcpp_action::ServerGoalHandle<Fibonacci>;

    explicit MotionServer()
    : Node("motion_server") {
        // 声明参数并获取值
        this->declare_parameter("s", 10.0);
        this->declare_parameter("v", 1.0);
        this->declare_parameter("time_limit", 10);

        s_ = this->get_parameter("s").as_double();
        v_ = this->get_parameter("v").as_double();
        time_limit_ = this->get_parameter("time_limit").as_int();

        action_server_ = rclcpp_action::create_server<Fibonacci>(
            this,
            "move_robot",
            std::bind(&MotionServer::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
            std::bind(&MotionServer::handle_cancel, this, std::placeholders::_1),
            std::bind(&MotionServer::handle_accepted, this, std::placeholders::_1));
    }

private:
    rclcpp_action::GoalResponse handle_goal(
        const rclcpp_action::GoalUUID &,
        std::shared_ptr<const Fibonacci::Goal>) {
        RCLCPP_INFO(this->get_logger(), "Goal received");
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    rclcpp_action::CancelResponse handle_cancel(
        const std::shared_ptr<GoalHandleFibonacci> goal_handle) {
        RCLCPP_INFO(this->get_logger(), "Goal canceled");
        return rclcpp_action::CancelResponse::ACCEPT;
    }

    void handle_accepted(const std::shared_ptr<GoalHandleFibonacci> goal_handle) {
        std::thread([this, goal_handle]() {
            auto feedback = std::make_shared<Fibonacci::Feedback>();
            auto result = std::make_shared<Fibonacci::Result>();

            double remaining_distance = s_;
            int remaining_time = time_limit_;
            auto start_time = this->now();

            while (remaining_distance > 0 && remaining_time > 0) {
                remaining_distance -= v_;

                // 清空反馈序列，并更新为当前剩余距离
                feedback->sequence.clear();  // 清空反馈序列
                feedback->sequence.push_back(static_cast<int>(remaining_distance));  // 添加更新后的距离

                goal_handle->publish_feedback(feedback);
                RCLCPP_INFO(this->get_logger(), "Remaining distance: %f", remaining_distance);

                // 等待1秒并减少剩余时间
                if ((this->now() - start_time).seconds() >= 1.0) {
                    remaining_time--;
                    start_time = this->now();
                }

                // 检查是否取消请求
                if (goal_handle->is_canceling()) {
                    result->sequence.push_back(static_cast<int>(remaining_distance));
                    goal_handle->canceled(result);
                    RCLCPP_INFO(this->get_logger(), "Goal canceled");
                    return;
                }
            }

            // 动作成功或超时处理
            if (remaining_distance <= 0) {
                result->sequence.push_back(0);
                goal_handle->succeed(result);
                RCLCPP_INFO(this->get_logger(), "Goal succeeded");
            } else {
                result->sequence.push_back(static_cast<int>(remaining_distance));
                goal_handle->abort(result);
                RCLCPP_INFO(this->get_logger(), "Goal failed due to timeout");
            }
        }).detach();
    }

    double s_, v_;
    int time_limit_;
    rclcpp_action::Server<Fibonacci>::SharedPtr action_server_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MotionServer>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

