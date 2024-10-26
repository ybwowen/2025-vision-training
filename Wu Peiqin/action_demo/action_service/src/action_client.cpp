#include "rclcpp/rclcpp.hpp"
#include "action_interfaces/srv/action_data.hpp"

using ActionData = action_interfaces::srv::ActionData;

class ActionClient : public rclcpp::Node
{
public:
    ActionClient(std::string name) : Node(name)
    {
        RCLCPP_INFO(this->get_logger(), "Action Client Node has been started: %s.", name.c_str());
        client_ = this->create_client<ActionData>("action_data");
    }

    void send_request(float s)
    {
        get_s = s;
        RCLCPP_INFO(this->get_logger(), "初始距离: %f", s);

        while (!client_->wait_for_service(std::chrono::seconds(1)))
        {
            if (!rclcpp::ok())
            {
                RCLCPP_ERROR(this->get_logger(), "Action Client was interrupted while waiting for the service. Exiting.");
                return;
            }
            RCLCPP_INFO(this->get_logger(), "service not available, waiting again...");
        }

        auto request = std::make_shared<ActionData::Request>();
        request->s = s;
        client_->async_send_request(request, std::bind(&ActionClient::handle_response, this, std::placeholders::_1));
    }

private:
    rclcpp::Client<ActionData>::SharedPtr client_;
    float get_s;

    void handle_response(rclcpp::Client<ActionData>::SharedFuture future)
    {
        auto result = future.get();
        RCLCPP_INFO(this->get_logger(), "Final Distance: %f", result->s_remain);

        if (result->s_remain > 0)
        {
            RCLCPP_INFO(this->get_logger(), "Action failed. Retrying with half the distance.");
            send_request(get_s / 2);
        }
        else
        {
            RCLCPP_INFO(this->get_logger(), "Action succeeded.");
        }
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto action_client = std::make_shared<ActionClient>("action_client");
    action_client->send_request(10.0); // 示例距离
    rclcpp::spin(action_client);
    rclcpp::shutdown();
    return 0;
}