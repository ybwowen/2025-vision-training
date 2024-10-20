#include "action_demo/robot.h"

float Robot::move_step(){
    curr_pose += step;
    std::cout<< "移动：" << step << "当前：" << curr_pose<<std::endl;
    return curr_pose;
}

bool Robot::set_goal(float distance){
    goal_pose = 0.;
    goal_pose += distance;
    status_ = MoveRobot::Feedback::STATUS_MOVEING;
    return true;
}

float Robot::get_curr(){return curr_pose;}
bool Robot::close_goal(){return fabs(curr_pose - goal_pose)<0.2;}
int Robot::get_status(){return status_;}
void Robot::stop_move(){
    status_ = MoveRobot::Feedback::STATUS_STOP;
}
void Robot::reset(){
    curr_pose = 0.;
}