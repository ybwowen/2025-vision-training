#ifndef ROBOT_H
#define ROBOT_H
#include "action_interfaces/action/move_robot.hpp"
#include "rclcpp/rclcpp.hpp"

class Robot{
    public:
        using MoveRobot = action_interfaces::action::MoveRobot;
        Robot() = default;
        ~Robot() = default;
        float move_step();
        bool set_goal(float distance);
        float get_curr();
        bool close_goal();
        void stop_move();
        int get_status();
        void reset();

    private:
        int status_ = MoveRobot::Feedback::STATUS_STOP;
        float curr_pose = 0.;
        float goal_pose = 0.;
        float step = 0.1;
        std::atomic<bool> cancel_flag_{false};
}; 
#endif