#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "move_interface/action/move.hpp" //接口头文件

class MoveServer: public rclcpp::Node{
    public:
        using MoveRobot = move_interface::action::Move;
        using ServerGoalHandle = rclcpp_action::ServerGoalHandle<MoveRobot>;

        explicit MoveServer(std::string name): Node(name){
            RCLCPP_INFO(this->get_logger(), "节点已启动：%s.", name.c_str());

            this->declare_parameter("v", 1.0);
            this->declare_parameter("time_limit", 1.0);
            this->declare_parameter("refresh_rate", 100);
            this->get_parameter("v", v);
            this->get_parameter("time_limit", time_limit);
            this->get_parameter("refresh_rate", refresh_rate);

            RCLCPP_INFO(this->get_logger(), "收到参数v: %lf, time_limit: %lf", v, time_limit);
            // 创建服务
            this->move_server_ = rclcpp_action::create_server<MoveRobot>(
                this, "move_srv",
                std::bind(&MoveServer::handle_goal, this,
                          std::placeholders::_1, std::placeholders::_2),
                std::bind(&MoveServer::handle_cancel, this,
                          std::placeholders::_1),
                std::bind(&MoveServer::handle_accepted, this,
                          std::placeholders::_1));
        }

    private:
        double v;
        double time_limit;
        int refresh_rate;

        // 声明一个服务
        rclcpp_action::Server<MoveRobot>::SharedPtr move_server_;

        // 收到请求的处理函数
        rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID& uuid,
                                                std::shared_ptr<const MoveRobot::Goal> goal){
            RCLCPP_INFO(this->get_logger(), "收到目标距离%f", goal->distance);
            (void) uuid;
            return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
        }

        rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<ServerGoalHandle> goal_handle){
            RCLCPP_INFO(this->get_logger(), "收到取消目标请求");
            (void) goal_handle;
            return rclcpp_action::CancelResponse::ACCEPT;
        }

        void execute_move(const std::shared_ptr<ServerGoalHandle> goal_handle) {
            RCLCPP_INFO(this->get_logger(), "准备就绪，开始移动");

            const auto goal = goal_handle->get_goal();
            auto result = std::make_shared<MoveRobot::Result>();
            double distance = goal->distance;
            double remaining_distance = distance;
            
            // 检查时间限制
            rclcpp::Time start_time = this->now();
            while(remaining_distance > 0){
                // 每个周期更新剩余距离
                rclcpp::sleep_for(std::chrono::milliseconds(refresh_rate)); // 模拟运动的时间
                double time_passed = (this->now() - start_time).seconds();
                
                if(time_passed > time_limit){
                    RCLCPP_INFO(this->get_logger(), "超过时间限制，动作失败");
                    goal_handle->abort(result);
                    return;
                }

                // 计算当前移动的距离
                double move_distance = v * refresh_rate / 1000;
                remaining_distance -= move_distance;

                // 反馈当前剩余距离
                auto feedback = std::make_shared<MoveRobot::Feedback>();
                feedback->pose = remaining_distance; // 反馈当前的剩余距离
                goal_handle->publish_feedback(feedback);

                if (remaining_distance <= 0) {
                    RCLCPP_INFO(this->get_logger(), "动作成功，耗时%lf，距离%lf", time_passed, goal->distance);
                    goal_handle->succeed(result);
                    return;
                }
            }
        }

        void handle_accepted(const std::shared_ptr<ServerGoalHandle> goal_handle){
            std::thread{std::bind(&MoveServer::execute_move, this, std::placeholders::_1),
                        goal_handle}.detach();
        }
};

int main(int argc, char** argv){
    rclcpp::init(argc, argv);
    auto move_server = std::make_shared<MoveServer>("move_server");
    rclcpp::spin(move_server);
    rclcpp::shutdown();
    return 0;
}