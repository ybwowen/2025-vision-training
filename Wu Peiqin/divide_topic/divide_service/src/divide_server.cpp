#include "rclcpp/rclcpp.hpp"
#include "divide_interfaces/srv/divide_two_ints.hpp"

using DivideTwoInts = divide_interfaces::srv::DivideTwoInts;

class DivideServer : public rclcpp::Node
{
private:
    rclcpp::Service<DivideTwoInts>::SharedPtr service_;

public:
    DivideServer() : Node("divide_pub")
    {
        service_ = this->create_service<DivideTwoInts>("divide_two_ints", std::bind(&DivideServer::handle_service, this, std::placeholders::_1, std::placeholders::_2));
    }

private:
    void handle_service(const std::shared_ptr<DivideTwoInts::Request> request,
                        std::shared_ptr<DivideTwoInts::Response> response)
    {
        response->quotient = request->dividend / request->divisor;
        response->remainder = request->dividend % request->divisor;
    }
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<DivideServer>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}