#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

class Service_Client : public rclcpp::Node{

    public:
        Service_Client(std::string name): Node(name){
            RCLCPP_INFO(this->get_logger(),"启动%s节点",name.c_str());
            client_ = this->create_client<example_interfaces::srv::AddTwoInts>("sum");
        }
        void send_request(int a, int b){
            while(!client_->wait_for_service(std::chrono::seconds(1))){
                if(!rclcpp::ok()){
                    return;
                }
                RCLCPP_INFO(this->get_logger(),"waiting...");
            }

            auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
            request->a = a;
            request->b = b;

            client_->async_send_request(
                request, std::bind(&Service_Client::result_callback,this, std::placeholders::_1)
            );
        }

    private:
        rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedPtr client_;
        void result_callback(
            rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedFuture result
        ){
            auto response = result.get();
            RCLCPP_INFO(this->get_logger(),"sum:%ld",response->sum);
        }
};

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Service_Client>("service_server");
    node->send_request(5,6);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}