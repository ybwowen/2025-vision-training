#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "action_interface/action/move_robot.hpp"

class Robot {
    public:
        using MoveRobot = action_interface::action::MoveRobot;
        Robot() = default;
        ~Robot() = default;
        float move(float speed);
        bool set_goal(float distance);
        float get_pose();
        bool close_goal();
    private:
        float current_pose_ = 0.0;  
        
};

float Robot::move(float speed) {
    current_pose_ -= speed;
    return current_pose_;
}

bool Robot::set_goal(float distance) {

    current_pose_ = distance;

    return true;
}
float Robot::get_pose() { return current_pose_; }

bool Robot::close_goal() { return current_pose_ < 1e-6; } //判断是否到达目标

class ActionRobot01 : public rclcpp::Node {
    public:
        using MoveRobot = action_interface::action::MoveRobot;
        using GoalHandleMoveRobot = rclcpp_action::ServerGoalHandle<MoveRobot>;

        explicit ActionRobot01(std::string name) : Node(name) {
            RCLCPP_INFO(this->get_logger(), "Node started：%s.", name.c_str());

            using namespace std::placeholders;  

            this->declare_parameter("v", 0.0);
            this->get_parameter("v", speed);
            RCLCPP_INFO(this->get_logger(), "Parameter v: %f", speed);

            this->action_server_ = rclcpp_action::create_server<MoveRobot>(
                    this, "move_robot",
                    std::bind(&ActionRobot01::handle_goal, this, _1, _2),
                    std::bind(&ActionRobot01::handle_cancel, this, _1),
                    std::bind(&ActionRobot01::handle_accepted, this, _1));
        }

    private:
        float speed;
        Robot robot;
        rclcpp_action::Server<MoveRobot>::SharedPtr action_server_;

        rclcpp_action::GoalResponse handle_goal(
                const rclcpp_action::GoalUUID& uuid,
                std::shared_ptr<const MoveRobot::Goal> goal) {
            RCLCPP_INFO(this->get_logger(), "Received goal request with distance %f",
                    goal->distance);
            (void)uuid;
            return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
        }

        rclcpp_action::CancelResponse handle_cancel(
                const std::shared_ptr<GoalHandleMoveRobot> goal_handle) {
            RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
            (void)goal_handle;
            return rclcpp_action::CancelResponse::ACCEPT;
        }

        void execute_move(const std::shared_ptr<GoalHandleMoveRobot> goal_handle) {
            const auto goal = goal_handle->get_goal();
            auto result = std::make_shared<MoveRobot::Result>();
            rclcpp::Rate rate = rclcpp::Rate(1);
            robot.set_goal(goal->distance);
            while (rclcpp::ok() && !robot.close_goal()) {
                robot.move(speed);
                auto feedback = std::make_shared<MoveRobot::Feedback>();
                feedback->remain = robot.get_pose();
                goal_handle->publish_feedback(feedback);
                //检测任务是否被取消
                if (goal_handle->is_canceling()) {
                    result->remain = robot.get_pose();
                    goal_handle->canceled(result);
                    RCLCPP_INFO(this->get_logger(), "Goal Canceled");
                    return;
                }
                RCLCPP_INFO(this->get_logger(), "Publish Feedback"); //发布 feedback
                rate.sleep();
            }

            result->remain = robot.get_pose();
            goal_handle->succeed(result);
            RCLCPP_INFO(this->get_logger(), "Goal Succeeded");
        }

        void handle_accepted(const std::shared_ptr<GoalHandleMoveRobot> goal_handle) {
            using std::placeholders::_1;
            std::thread{std::bind(&ActionRobot01::execute_move, this, _1), goal_handle}.detach();
        }
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto action_server = std::make_shared<ActionRobot01>("action_srv");
    rclcpp::spin(action_server);
    rclcpp::shutdown();
    return 0;
}