#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "action_interfaces/action/move_robot.hpp"

class action_control : public rclcpp::Node{
    public:
        using MoveRobot = action_interfaces::action::MoveRobot;
        using GoalHandleMoveRobot = rclcpp_action::ClientGoalHandle<MoveRobot>;
        explicit action_control(std::string name): Node(name){
            RCLCPP_INFO(this->get_logger(),"节点%s已启动",name.c_str());
            this->client_ = rclcpp_action::create_client<MoveRobot>(this, "move_robot");
            this->timer_ = this->create_wall_timer(std::chrono::milliseconds(500),std::bind(&action_control::send_goal,this));
            this->declare_parameter("s",10.);
            this->declare_parameter("time_limit",3.);
            this->get_parameter("s",this->s);
            this->get_parameter("time_limit", this->time_limit);

        }

        void send_goal(){
            using namespace std::placeholders;
            if(!client_->wait_for_action_server(std::chrono::seconds(20))){
                RCLCPP_ERROR(this->get_logger(),"服务器未上线");
                rclcpp::shutdown();
                return;
            }
            auto goal_msg = MoveRobot::Goal();
            goal_msg.distance = this->s;
            auto send_goal_options = rclcpp_action::Client<MoveRobot>::SendGoalOptions();
            send_goal_options.goal_response_callback = 
                std::bind(&action_control::goal_response_callback, this,_1);
            send_goal_options.feedback_callback = 
                std::bind(&action_control::feedback_callback,this, _1, _2);
            send_goal_options.result_callback = 
                std::bind(&action_control::result_callback, this, _1);
            if ( this->status_now == MoveRobot::Feedback::STATUS_STOP){
                RCLCPP_INFO(this->get_logger(),"发送指令，运动%f",goal_msg.distance);
                this->client_->async_send_goal(goal_msg, send_goal_options);
            }
            else if( this->time_now > this->time_limit){
                this->s /= 2.;
                goal_msg.distance = this->s;
                RCLCPP_INFO(this->get_logger(),"发送指令，运动%f",goal_msg.distance);
                this->client_->async_send_goal(goal_msg, send_goal_options);
            }
        }


    private:
        rclcpp_action::Client<MoveRobot>::SharedPtr client_;
        rclcpp::TimerBase::SharedPtr timer_;
        float s;
        float time_limit;
        float yet;
        float time_now;
        int status_now = MoveRobot::Feedback::STATUS_STOP;
        void goal_response_callback(GoalHandleMoveRobot::SharedPtr goal_handle){
            if(!goal_handle){
                RCLCPP_ERROR(this->get_logger(),"目标被拒绝执行");
            }else {
                RCLCPP_INFO(this->get_logger(),"目标被接受，正在执行");
            }
        }
        void feedback_callback(GoalHandleMoveRobot::SharedPtr, const std::shared_ptr<const MoveRobot::Feedback> feedback){
            RCLCPP_INFO(this->get_logger(), "距离目标：%f 当前时间：%f", feedback->yet, feedback->time);
            this->yet = feedback->yet;
            this->time_now = feedback->time;
            this->status_now = feedback->status;
        }
        void result_callback(const GoalHandleMoveRobot::WrappedResult& result){
            switch (result.code) {
                case rclcpp_action::ResultCode::SUCCEEDED:
                    break;
                case rclcpp_action::ResultCode::ABORTED:
                    RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
                    return;
                case rclcpp_action::ResultCode::CANCELED:
                    RCLCPP_ERROR(this->get_logger(), "Goal was canceled");
                    return;
                default:
                    RCLCPP_ERROR(this->get_logger(), "Unknown result code");
                    return;
                }

            RCLCPP_INFO(this->get_logger(), "Result received: %s", result.result->makeit ? "true" : "false");
            rclcpp::shutdown();
        }
};

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto action_client = std::make_shared<action_control>("action_control");
  rclcpp::spin(action_client);
  rclcpp::shutdown();
  return 0;
}