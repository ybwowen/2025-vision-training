#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class TopicSubscribe01 : public rclcpp::Node
{
public:
    TopicSubscribe01(std::string name) : Node(name)
    {
        
          // 创建一个订阅者订阅话题，指定其接受的话题的数据结构以及订阅的话题名称command
        command_subscribe_ = this->create_subscription<std_msgs::msg::String>("command", 10, std::bind(&TopicSubscribe01::command_callback, this,std::placeholders::_1));
    }

private:
     // 声明一个订阅者
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr command_subscribe_;
     // 收到话题数据的回调函数
    void command_callback(const std_msgs::msg::String::SharedPtr msg)
    {
        std::istringstream iss(msg->data);
        int numerator, denominator;
        iss >> numerator >> denominator;
        if (denominator == 0) {
            RCLCPP_ERROR(this->get_logger(), "不能除以0!");
            return;
        }

        int quotient = numerator / denominator;
        int remain = numerator % denominator;
        RCLCPP_INFO(this->get_logger(), "商：%i，余数: %i", quotient , remain);
    }
};
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    /*创建对应节点的共享指针对象*/
    auto node = std::make_shared<TopicSubscribe01>("division");
    /* 运行节点，并检测退出信号*/
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}