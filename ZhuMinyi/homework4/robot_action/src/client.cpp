#include "rclcpp/rclcpp.hpp"
#include "robot_action/action/move.hpp"
#include <rclcpp_action/rclcpp_action.hpp>

class ActionClient : public rclcpp::Node {
public:
  ActionClient() : Node("action_client") {
    this->declare_parameter<double>("s", 20.0);
    client_ = rclcpp_action::create_client<robot_action::action::Move>(
        this, "move_robot");
    RCLCPP_INFO(this->get_logger(), "Starting the action client...");
    send_request();
  }

private:
  void send_request() {
    double distance;
    this->get_parameter("s", distance);

    while (true) {
      if (!client_->wait_for_action_server(std::chrono::seconds(1))) {
        RCLCPP_INFO(this->get_logger(),
                    "Waiting for action server to be available...");
        continue;
      }

      auto goal_msg = robot_action::action::Move::Goal();
      goal_msg.distance = distance;

      rclcpp_action::Client<robot_action::action::Move>::SendGoalOptions
          options;
      options.result_callback =
          [this,
           &distance](const rclcpp_action::ClientGoalHandle<
                      robot_action::action::Move>::WrappedResult &result) {
            if (result.code != rclcpp_action::ResultCode::SUCCEEDED) {
              RCLCPP_ERROR(this->get_logger(), "Goal was rejected!");
              distance /= 2; // 失败时将距离减半
              RCLCPP_INFO(this->get_logger(), "Retrying with distance: %f",
                          distance);
              this->declare_parameter<double>("action.s", distance);
              send_request(); // 重新发送请求
            } else {
              RCLCPP_INFO(this->get_logger(), "Goal succeeded!");
              return; // 确保成功后不再继续发送请求
            }
          };

      auto future_result = client_->async_send_goal(goal_msg, options);
      rclcpp::spin_until_future_complete(this->get_node_base_interface(),
                                         future_result);

      if (future_result.get() == nullptr) {
        RCLCPP_ERROR(this->get_logger(), "Failed to send goal");
      } else {
        RCLCPP_INFO(this->get_logger(), "Goal sent successfully");
        break; // 成功发送目标后退出循环
      }
    }
  }

  rclcpp_action::Client<robot_action::action::Move>::SharedPtr client_;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ActionClient>());
  rclcpp::shutdown();
  return 0;
}
