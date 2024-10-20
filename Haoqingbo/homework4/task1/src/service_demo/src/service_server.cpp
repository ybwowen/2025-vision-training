#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

class Service_Server : public rclcpp::Node{
    public:
        Service_Server(std::string name) : Node(name){
            RCLCPP_INFO(this->get_logger(),"启动%s节点",name.c_str());
            server_ = this->create_service<example_interfaces::srv::AddTwoInts>(
                "sum",
                std::bind(&Service_Server::getsum,this, std::placeholders::_1, std::placeholders::_2)
            );
        }
    
    private:
        rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr server_;

        void getsum(
            std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
            std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response

        ) {
            response->sum = request->a + request->b;
        }

};

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Service_Server>("service_server");
    rclcpp::spin(node);
    rclcpp::shutdown();
}