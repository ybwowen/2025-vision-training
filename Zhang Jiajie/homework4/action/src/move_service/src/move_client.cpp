#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "move_interface/action/move.hpp" //接口头文件

class MoveClient: public rclcpp::Node{
    public:
        using MoveRobot = move_interface::action::Move;
        using ClientGoalHandle = rclcpp_action::ClientGoalHandle<MoveRobot>;

        // 构造函数,有一个参数为节点名称
        explicit MoveClient(std::string name,
                            const rclcpp::NodeOptions& node_options = rclcpp::NodeOptions()): Node(name, node_options){
            RCLCPP_INFO(this->get_logger(), "节点已启动：%s.", name.c_str());
            this->declare_parameter("s", 0.0);
            this->get_parameter("s", s);
            RCLCPP_INFO(this->get_logger(), "收到参数s: %lf", s);
            target = s;
            // 创建客户端
            this->client_ptr_ = rclcpp_action::create_client<MoveRobot>(this, "move_srv");

            this->timer_ = this->create_wall_timer(std::chrono::milliseconds(500),
                                                   std::bind(&MoveClient::send_goal, this));
        }

        void send_goal(){
            this->timer_->cancel();
            auto goal_msg = MoveRobot::Goal();
            goal_msg.distance = target;

            RCLCPP_INFO(this->get_logger(), "正在发送目标，尝试次数%d", trial);

            auto send_goal_options = rclcpp_action::Client<MoveRobot>::SendGoalOptions();
            send_goal_options.goal_response_callback = std::bind(&MoveClient::goal_response_callback, this, std::placeholders::_1);
            send_goal_options.feedback_callback = std::bind(&MoveClient::feedback_callback, this, std::placeholders::_1, std::placeholders::_2);
            send_goal_options.result_callback = std::bind(&MoveClient::result_callback, this, std::placeholders::_1);
            this->client_ptr_->async_send_goal(goal_msg, send_goal_options);
    }

    private:
        double s;
        int trial=1;
        double target;
        rclcpp_action::Client<MoveRobot>::SharedPtr client_ptr_;
        rclcpp::TimerBase::SharedPtr timer_;

        void goal_response_callback(ClientGoalHandle::SharedPtr goal_handle){
            if(!goal_handle){
                RCLCPP_ERROR(this->get_logger(), "目标被服务器拒绝");
            }else{
                RCLCPP_INFO(this->get_logger(), "目标被服务器接受，等待结果");
            }
        }

        void feedback_callback(ClientGoalHandle::SharedPtr,
                               const std::shared_ptr<const MoveRobot::Feedback> feedback) {
            RCLCPP_INFO(this->get_logger(), "收到反馈,剩余距离%lf", feedback->pose);
        }

        void result_callback(const ClientGoalHandle::WrappedResult& result) {
            switch (result.code) {
                case rclcpp_action::ResultCode::SUCCEEDED:
                    RCLCPP_INFO(this->get_logger(), "收到结果：动作成功，尝试%d次", trial);
                    break;
                case rclcpp_action::ResultCode::ABORTED:
                    RCLCPP_ERROR(this->get_logger(), "收到结果：目标中止");
                    trial += 1;
                    target = s/pow(2,trial-1);
                    send_goal();
                    return;
                case rclcpp_action::ResultCode::CANCELED:
                    RCLCPP_ERROR(this->get_logger(), "收到结果：目标取消");
                    return;
                default:
                    RCLCPP_ERROR(this->get_logger(), "Unknown result code");
                    return;
                }
                // rclcpp::shutdown();
        }
};

int main(int argc, char** argv){
    rclcpp::init(argc, argv);
    auto move_client = std::make_shared<MoveClient>("move_client");
    rclcpp::spin(move_client);
    rclcpp::shutdown();
    return 0;
}