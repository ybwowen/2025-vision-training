#include "rclcpp/rclcpp.hpp"
#include "division_interface/srv/robot.hpp"

class ServiceServer01 : public rclcpp::Node {
public:
    ServiceServer01(std::string name) : Node(name) {
        RCLCPP_INFO(this->get_logger(), "节点已启动：%s.", name.c_str());
    // 创建服务
        add_ints_server_ =
            this->create_service<division_interface::srv::Robot>(
                "division",
                std::bind(&ServiceServer01::handle_division, this,
                    std::placeholders::_1, std::placeholders::_2));
    }

private:
    // 声明一个服务
    rclcpp::Service<division_interface::srv::Robot>::SharedPtr
        add_ints_server_;

    // 收到请求的处理函数
    void handle_division(
        const std::shared_ptr<division_interface::srv::Robot::Request> request,
        std::shared_ptr<division_interface::srv::Robot::Response> response) {
            RCLCPP_INFO(this->get_logger(), "收到num1: %ld num2: %ld", request->num1,
                request->num2);
        response->quotient = request->num1 / request->num2;
        response->remainder = request->num1 % request->num2;
    };
};
int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    /*创建对应节点的共享指针对象*/
    auto node = std::make_shared<ServiceServer01>("service_client_01");
    /* 运行节点，并检测退出信号*/
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}