#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "action_interfaces/action/move_robot.hpp"
#include "action_demo/robot.h"

class action_robot : public rclcpp::Node{

    public:
        using MoveRobot = action_interfaces::action::MoveRobot;
        using GoalHandleMoveRobot = rclcpp_action::ServerGoalHandle<MoveRobot>;
        explicit action_robot(std::string name) : Node(name){
            RCLCPP_INFO(this->get_logger(),"%s节点已启动",name.c_str());
            using namespace std::placeholders;
            this->declare_parameter("v",2.);
            this->get_parameter("v", velo);
            this->server_ = rclcpp_action::create_server<MoveRobot>(
                this, "move_robot",
                std::bind(&action_robot::handle_goal,this,_1,_2),
                std::bind(&action_robot::handle_cancel,this, _1),
                std::bind(&action_robot::handle_accepted,this, _1)
            );

        }

    private:
        rclcpp_action::Server<MoveRobot>::SharedPtr server_;
        Robot robot;
        float velo;
        rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID& uuid, std::shared_ptr<const MoveRobot::Goal> goal){
            RCLCPP_INFO(this->get_logger(),"收到命令，移动距离：%f",goal->distance);
            (void) uuid;
            if (goal->distance > 0){
            return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
            }
            else {
                RCLCPP_WARN(this->get_logger(),"无效距离！");
                return rclcpp_action::GoalResponse::REJECT;
            }

        }

        rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<GoalHandleMoveRobot> goal_handle){
            RCLCPP_INFO(this->get_logger(),"收到终止命令");
            (void) goal_handle;
            robot.stop_move();
            return rclcpp_action::CancelResponse::ACCEPT;
        }

        void handle_accepted(const std::shared_ptr<GoalHandleMoveRobot> goal_handle){
            using namespace std::placeholders;
            std::thread{std::bind(&action_robot::execute_move,this,_1),goal_handle}
                .detach();
        }

        void execute_move(const std::shared_ptr<GoalHandleMoveRobot> goal_handle){
            this->robot.reset();
            const auto goal = goal_handle->get_goal();
            RCLCPP_INFO(this->get_logger(),"开始移动%f",goal->distance);
            float dist = goal->distance;
            auto result = std::make_shared<MoveRobot::Result>();
            rclcpp::Rate rate = rclcpp::Rate(this->velo);
            robot.set_goal(goal->distance);
            double time_1 = this->get_clock()->now().seconds();
            while(rclcpp::ok()&&!robot.close_goal()){
                robot.move_step();
                auto feedback = std::make_shared<MoveRobot::Feedback>();
                double time_2 = this->get_clock()->now().seconds();
                feedback->time = time_2 - time_1;
                feedback->yet = dist - robot.get_curr();
                feedback->status = robot.get_status();
                goal_handle->publish_feedback(feedback);
                if(goal_handle->is_canceling()){
                    result->makeit = (fabs(dist - robot.get_curr())<0.01)? true : false;
                    goal_handle->canceled(result);
                    RCLCPP_INFO(this->get_logger(),"任务已被取消");
                    return;
                }
                RCLCPP_INFO(this->get_logger(),"发布反馈");
                rate.sleep();

            }
            result->makeit = true;
            goal_handle->succeed(result);
            RCLCPP_INFO(this->get_logger(),"Mission Success");
        }
};

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto action_server = std::make_shared<action_robot>("action_robot");
  rclcpp::spin(action_server);
  rclcpp::shutdown();
  return 0;
}