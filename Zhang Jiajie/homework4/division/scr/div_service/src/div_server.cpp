#include "rclcpp/rclcpp.hpp"
#include "div_interface/srv/division.hpp" //接口头文件

class DivisionServer: public rclcpp::Node{
    public:
        DivisionServer(std::string name): Node(name){
            RCLCPP_INFO(this->get_logger(), "节点已启动：%s.", name.c_str());
            // 创建服务
            division_server_ = this->create_service<div_interface::srv::Division>(
                "division_srv",
                std::bind(&DivisionServer::handle_division, this,
                    std::placeholders::_1, std::placeholders::_2));
        }

    private:
        // 声明一个服务
        rclcpp::Service<div_interface::srv::Division>::SharedPtr division_server_;

        // 收到请求的处理函数
        void handle_division(const std::shared_ptr<div_interface::srv::Division::Request> request,
                                   std::shared_ptr<div_interface::srv::Division::Response> response){
            RCLCPP_INFO(this->get_logger(), "收到a: %ld b: %ld", request->a, request->b);
            response->quotient = request->a / request->b;
            response->remainder = request->a % request->b;
        };
};

int main(int argc, char** argv){
    rclcpp::init(argc, argv);
    /*创建对应节点的共享指针对象*/
    auto node = std::make_shared<DivisionServer>("division_server");
    /* 运行节点，并检测退出信号*/
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}