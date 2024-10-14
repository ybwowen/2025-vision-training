#include <functional>
#include <memory>
#include <thread>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "robot_action_demo/action/move.hpp"

class MoveActionServer : public rclcpp::Node
{
public:
  using Move = robot_action_demo::action::Move;
  using GoalHandleMove = rclcpp_action::ServerGoalHandle<Move>;

  explicit MoveActionServer(const rclcpp::NodeOptions & options = rclcpp::NodeOptions())
  : Node("move_action_server", options)
  {
    using namespace std::placeholders;

    this->declare_parameter("v", 1.0);
    this->declare_parameter("time_limit", 10.0);

    this->action_server_ = rclcpp_action::create_server<Move>(
      this,
      "move",
      std::bind(&MoveActionServer::handle_goal, this, _1, _2),
      std::bind(&MoveActionServer::handle_cancel, this, _1),
      std::bind(&MoveActionServer::handle_accepted, this, _1));
  }

private:
  rclcpp_action::Server<Move>::SharedPtr action_server_;

  rclcpp_action::GoalResponse handle_goal(
    const rclcpp_action::GoalUUID & uuid,
    std::shared_ptr<const Move::Goal> goal)
  {
    RCLCPP_INFO(this->get_logger(), "Received goal request with distance %f", goal->distance);
    (void)uuid;
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }

  rclcpp_action::CancelResponse handle_cancel(
    const std::shared_ptr<GoalHandleMove> goal_handle)
  {
    RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
    (void)goal_handle;
    return rclcpp_action::CancelResponse::ACCEPT;
  }

  void handle_accepted(const std::shared_ptr<GoalHandleMove> goal_handle)
  {
    using namespace std::placeholders;
    std::thread{std::bind(&MoveActionServer::execute, this, _1), goal_handle}.detach();
  }

void execute(const std::shared_ptr<GoalHandleMove> goal_handle)
{
  RCLCPP_INFO(this->get_logger(), "Executing goal");
  const auto goal = goal_handle->get_goal();
  auto feedback = std::make_shared<Move::Feedback>();
  auto result = std::make_shared<Move::Result>();

  auto v = this->get_parameter("v").as_double();
  auto time_limit = this->get_parameter("time_limit").as_double();

  rclcpp::Rate loop_rate(10);  // 增加更新频率到10Hz
  auto start_time = this->now();

  feedback->remaining_distance = goal->distance;

  while (rclcpp::ok() && feedback->remaining_distance > 0) {
    // 检查是否超时
    if ((this->now() - start_time).seconds() > time_limit) {
      result->success = false;
      result->final_distance = feedback->remaining_distance;
      goal_handle->abort(result);
      RCLCPP_INFO(this->get_logger(), "Goal aborted due to time limit");
      return;
    }

    if (goal_handle->is_canceling()) {
      result->success = false;
      result->final_distance = feedback->remaining_distance;
      goal_handle->canceled(result);
      RCLCPP_INFO(this->get_logger(), "Goal canceled");
      return;
    }

    // 使用 v 参数来更新剩余距离，考虑到循环频率
    feedback->remaining_distance -= v / 10.0;  // 因为我们现在是10Hz
    if (feedback->remaining_distance < 0) {
      feedback->remaining_distance = 0;
    }
    goal_handle->publish_feedback(feedback);
    RCLCPP_INFO(this->get_logger(), "Remaining distance: %f", feedback->remaining_distance);

    loop_rate.sleep();
  }

  if (rclcpp::ok()) {
    result->success = true;
    result->final_distance = 0.0;
    goal_handle->succeed(result);
    RCLCPP_INFO(this->get_logger(), "Goal succeeded");
  }
}
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MoveActionServer>());
  rclcpp::shutdown();
  return 0;
}