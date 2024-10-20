#include "rclcpp/rclcpp.hpp"
#include "divide_interfaces/srv/divide_two_ints.hpp"

using DivideTwoInts = divide_interfaces::srv::DivideTwoInts;

class DivideClient:public rclcpp::Node
{
private:
    rclcpp::Client<DivideTwoInts>::SharedPtr client_;
public:
    DivideClient():Node("divide_client")
    {
        client_=this->create_client<DivideTwoInts>("divide_two_ints");
    }

    void send_request(int32_t dividend,int32_t divisor)
    {
        auto request=std::make_shared<DivideTwoInts::Request>();
        request->dividend=dividend;
        request->divisor=divisor;

        while (!client_->wait_for_service(std::chrono::seconds(1)))
        {
            if (!rclcpp::ok())
            {
                RCLCPP_ERROR(this->get_logger(),"Interrupted while waiting for the service. Exiting.");
                return;
            }
            RCLCPP_INFO(this->get_logger(), "Service not available, waiting again...");
        }

        auto result_future=client_->async_send_request(request);

        if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result_future) ==
            rclcpp::FutureReturnCode::SUCCESS)
        {
            auto result = result_future.get();
            RCLCPP_INFO(this->get_logger(), "商: %d, 余数: %d", result.get()->quotient, result.get()->remainder);
        }
        else
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to call service divide_two_ints");
        }
    }
};

int main(int argc,char* argv[])
{
    rclcpp::init(argc,argv);
    auto node=std::make_shared<DivideClient>();
    int32_t dividend = std::stoi(argv[1]);
    int32_t divisor = std::stoi(argv[2]);
    node->send_request(dividend, divisor);

    rclcpp::shutdown();
    return 0;
}

