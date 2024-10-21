#include "rclcpp/rclcpp.hpp"
#include "robot_action/action/move.hpp"
#include <chrono>
#include <rclcpp_action/rclcpp_action.hpp>
#include <thread>

class ActionServer : public rclcpp::Node {
public:
  ActionServer() : Node("action_server") {
    this->declare_parameter("v", 1.0);
    this->declare_parameter("time_limit", 6.0);

    this->get_parameter("v", v_);
    this->get_parameter("time_limit", time_limit_);

    server_ = rclcpp_action::create_server<robot_action::action::Move>(
        this, "move_robot",
        std::bind(&ActionServer::handle_goal, this, std::placeholders::_1,
                  std::placeholders::_2),
        std::bind(&ActionServer::handle_cancel, this, std::placeholders::_1),
        std::bind(&ActionServer::handle_accepted, this, std::placeholders::_1));
  }

private:
  rclcpp_action::GoalResponse
  handle_goal(const rclcpp_action::GoalUUID &uuid,
              std::shared_ptr<const robot_action::action::Move::Goal> goal) {
    RCLCPP_INFO(this->get_logger(), "Received goal request with distance: %f",
                goal->distance);
    (void)uuid;
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }

  rclcpp_action::CancelResponse
  handle_cancel(const std::shared_ptr<
                rclcpp_action::ServerGoalHandle<robot_action::action::Move>>
                    goal_handle) {
    RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
    return rclcpp_action::CancelResponse::ACCEPT;
    (void)goal_handle;
  }

  void
  handle_accepted(const std::shared_ptr<
                  rclcpp_action::ServerGoalHandle<robot_action::action::Move>>
                      goal_handle) {
    auto goal = goal_handle->get_goal();
    double initial_distance = goal->distance; // save the initial distance
    auto start_time = this->now();

    execute_action(goal_handle, initial_distance,
                   start_time); // execute the first time
  }

  void execute_action(
      const std::shared_ptr<
          rclcpp_action::ServerGoalHandle<robot_action::action::Move>>
          goal_handle,
      double distance, rclcpp::Time start_time) {
    std::thread([this, goal_handle, distance, start_time]() mutable {
      double remaining_distance = distance;
      rclcpp::Rate rate(1.0);

      while (remaining_distance > 0) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        remaining_distance -= v_;
        auto elapsed_time = (this->now() - start_time).seconds();

        if (elapsed_time > time_limit_) {
          RCLCPP_INFO(this->get_logger(), "Time exceeds.");
          remaining_distance = distance / 2;
          RCLCPP_INFO(this->get_logger(),
                      "Retrying with remaining distance: %f",
                      remaining_distance);

          auto start_time = this->now();
          // resend
          execute_action(goal_handle, remaining_distance, start_time);
          return;
        }

        RCLCPP_INFO(this->get_logger(),
                    "Remaining distance: %f, Elapsed time: %f seconds",
                    remaining_distance, elapsed_time);
      }

      auto result_msg = std::make_shared<robot_action::action::Move::Result>();
      goal_handle->succeed(result_msg);
      RCLCPP_INFO(this->get_logger(), "Goal executed successfully!");
    }).detach();
  }

  rclcpp_action::Server<robot_action::action::Move>::SharedPtr server_;
  double v_, time_limit_;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ActionServer>());
  rclcpp::shutdown();
  return 0;
}
