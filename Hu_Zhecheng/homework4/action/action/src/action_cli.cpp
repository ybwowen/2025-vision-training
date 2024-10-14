#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "action_interface/action/move_robot.hpp"
#include <cmath>
#include <functional>

class ActionControl01 : public rclcpp::Node {
    public:

        using MoveRobot = action_interface::action::MoveRobot;
        using GoalHandleMoveRobot = rclcpp_action::ClientGoalHandle<MoveRobot>;
        
        explicit ActionControl01(
                std::string name,
                const rclcpp::NodeOptions& node_options = rclcpp::NodeOptions())
                : Node(name, node_options) {
            
            RCLCPP_INFO(this->get_logger(), "Node started：%s.", name.c_str()); 
            
            //取出客户端paramter
            this->declare_parameter("s", 0.0);
            this->get_parameter("s", distance);
            this->declare_parameter("time_limit", 1);
            this->get_parameter("time_limit", time_limit);
            RCLCPP_INFO(this->get_logger(), "Parameter s: %f, Parameter time_limit: %d", distance,time_limit);

            this->client_ptr_ =
                rclcpp_action::create_client<MoveRobot>(this, "move_robot");

            this->timer_ =
                this->create_wall_timer(std::chrono::seconds(1),
                        std::bind(&ActionControl01::send_goal, this));
        }


        void cancel_goal() {
            this->timer_->cancel();
            RCLCPP_INFO(this->get_logger(), "Timeout,canceling goal");
            auto cancel_future = client_ptr_->async_cancel_goal(goal_future.get());

        }

        void send_goal() {
            using namespace std::placeholders;
            this->timer_->cancel();
            this->timer_ =
                this->create_wall_timer(std::chrono::seconds(time_limit), //设置超时时间
                        std::bind(&ActionControl01::cancel_goal, this));

            if (!this->client_ptr_->wait_for_action_server(std::chrono::seconds(10))) {
                RCLCPP_ERROR(this->get_logger(),
                        "Action server not available after waiting");
                rclcpp::shutdown();
                return;
            }

            auto goal_msg = MoveRobot::Goal();
            goal_msg.distance = distance/pow(2,retry_count); //每次重试距离减半

            RCLCPP_INFO(this->get_logger(), "Sending goal");
            //设置回调函数
            auto send_goal_options =
                    rclcpp_action::Client<MoveRobot>::SendGoalOptions();
            send_goal_options.goal_response_callback =
                    std::bind(&ActionControl01::goal_response_callback, this, _1);
            send_goal_options.feedback_callback =
                    std::bind(&ActionControl01::feedback_callback, this, _1, _2);
            send_goal_options.result_callback =
                    std::bind(&ActionControl01::result_callback, this, _1);
            goal_future = this->client_ptr_->async_send_goal(goal_msg, send_goal_options); //拿到该goal的future

            

        }
    private:
        float distance;
        int time_limit,retry_count{0};
        rclcpp_action::Client<MoveRobot>::SharedPtr client_ptr_;
        rclcpp::TimerBase::SharedPtr timer_;
        std::shared_future<GoalHandleMoveRobot::SharedPtr> goal_future;

        void goal_response_callback(GoalHandleMoveRobot::SharedPtr goal_handle) {
            if (!goal_handle) {
                RCLCPP_ERROR(this->get_logger(), "Goal was rejected by server");
            } else {
                RCLCPP_INFO(this->get_logger(),
                        "Goal accepted by server, waiting for result");
            }
        }

        void feedback_callback(
                GoalHandleMoveRobot::SharedPtr,
                const std::shared_ptr<const MoveRobot::Feedback> feedback) {
            RCLCPP_INFO(this->get_logger(), "current remaining distance:%f", feedback->remain);
        }

        void result_callback(const GoalHandleMoveRobot::WrappedResult& result) {
            switch (result.code) {
                case rclcpp_action::ResultCode::SUCCEEDED:
                break;
            case rclcpp_action::ResultCode::ABORTED:
                RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
                return;
            case rclcpp_action::ResultCode::CANCELED:
                RCLCPP_ERROR(this->get_logger(), "Timeout,goal was canceled,retrying...");//超时重试
                retry_count++;
                send_goal();
                return;
            default:
                RCLCPP_ERROR(this->get_logger(), "Unknown result code");
                return;
            }

            RCLCPP_INFO(this->get_logger(), "Result received: %f", result.result->remain);
            retry_count=0;//重新设定goal
            send_goal();
        }
};  

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto action_client = std::make_shared<ActionControl01>("action_cli");
    rclcpp::spin(action_client);
    rclcpp::shutdown();
    return 0;
}