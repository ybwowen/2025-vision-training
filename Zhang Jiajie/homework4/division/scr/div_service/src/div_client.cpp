#include <rclcpp/rclcpp.hpp>
#include "div_interface/srv/division.hpp"

class DivisionClient: public rclcpp::Node{
    public:
        // 构造函数,有一个参数为节点名称
        DivisionClient(std::string name): Node(name){
            RCLCPP_INFO(this->get_logger(), "节点已启动：%s.", name.c_str());
            // 创建客户端
            client_ = this->create_client<div_interface::srv::Division>("division_srv");
        }

        void send_request(int a, int b){
            RCLCPP_INFO(this->get_logger(), "计算%d/%d", a, b);

            // 1.等待服务端上线
            while(!client_->wait_for_service(std::chrono::seconds(1))){
                //等待时检测rclcpp的状态
                if(!rclcpp::ok()){
                    RCLCPP_ERROR(this->get_logger(), "等待服务的过程中被打断...");
                    return;
                }
                RCLCPP_INFO(this->get_logger(), "等待服务端上线中");
            }

            // 2.构造请求的
            auto request =
                std::make_shared<div_interface::srv::Division_Request>();
            request->a = a;
            request->b = b;

            // 3.发送异步请求，然后等待返回，返回时调用回调函数
            client_->async_send_request(request, std::bind(&DivisionClient::result_callback_, this,
                                        std::placeholders::_1));
        };

    private:
        // 声明客户端
        rclcpp::Client<div_interface::srv::Division>::SharedPtr client_;

        void result_callback_(rclcpp::Client<div_interface::srv::Division>::SharedFuture result_future){
            auto response = result_future.get();
            RCLCPP_INFO(this->get_logger(), "商：%ld, 余数：%ld", response->quotient, response->remainder);
        }
};

int main(int argc, char** argv){
    rclcpp::init(argc, argv);
    /*创建对应节点的共享指针对象*/
    auto node = std::make_shared<DivisionClient>("division_client");
    node->send_request(std::stoull(argv[1]), std::stoull(argv[2]));
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}