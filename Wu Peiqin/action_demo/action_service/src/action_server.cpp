#include "rclcpp/rclcpp.hpp"
#include "action_interfaces/srv/action_data.hpp"

using ActionData = action_interfaces::srv::ActionData;

class ActionServer : public rclcpp::Node
{
private:
    rclcpp::Service<ActionData>::SharedPtr server_;

    void handle_request(const std::shared_ptr<ActionData::Request> request, std::shared_ptr<ActionData::Response> response)
    {
        float v = this->get_parameter("v").as_double();
        float time_limit = this->get_parameter("time_limit").as_double();

        float s_remain = request->s;
        float time_elapsed = 0.0;

        while (s_remain > 0 && time_elapsed < time_limit)
        {
            rclcpp::sleep_for(std::chrono::milliseconds(100));
            s_remain -= v * 0.1;
            time_elapsed += 0.1;
            RCLCPP_INFO(this->get_logger(), "Remaining Distance: %f", s_remain);
        }

        if (s_remain <= 0)
        {
            RCLCPP_INFO(this->get_logger(), "Action succeeded.");
        }
        else
        {
            RCLCPP_INFO(this->get_logger(), "Action failed. Time limit exceeded.");
        }

        response->s_remain = s_remain;
    }

public:
    ActionServer(std::string name) : Node(name)
    {
        this->declare_parameter<float>("v", 1.0);
        this->declare_parameter<float>("time_limit", 10.0);

        RCLCPP_INFO(this->get_logger(), "Action Server Node has been started: %s.", name.c_str());
        server_ = this->create_service<ActionData>("action_data", std::bind(&ActionServer::handle_request, this, std::placeholders::_1, std::placeholders::_2));
    }
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto action_server = std::make_shared<ActionServer>("action_server");
    rclcpp::spin(action_server);
    rclcpp::shutdown();
    return 0;
}