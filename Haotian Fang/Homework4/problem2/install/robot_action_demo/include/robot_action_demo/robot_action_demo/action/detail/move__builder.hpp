// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_action_demo:action/Move.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_ACTION_DEMO__ACTION__DETAIL__MOVE__BUILDER_HPP_
#define ROBOT_ACTION_DEMO__ACTION__DETAIL__MOVE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_action_demo/action/detail/move__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_action_demo
{

namespace action
{

namespace builder
{

class Init_Move_Goal_distance
{
public:
  Init_Move_Goal_distance()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_action_demo::action::Move_Goal distance(::robot_action_demo::action::Move_Goal::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_action_demo::action::Move_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_action_demo::action::Move_Goal>()
{
  return robot_action_demo::action::builder::Init_Move_Goal_distance();
}

}  // namespace robot_action_demo


namespace robot_action_demo
{

namespace action
{

namespace builder
{

class Init_Move_Result_final_distance
{
public:
  explicit Init_Move_Result_final_distance(::robot_action_demo::action::Move_Result & msg)
  : msg_(msg)
  {}
  ::robot_action_demo::action::Move_Result final_distance(::robot_action_demo::action::Move_Result::_final_distance_type arg)
  {
    msg_.final_distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_action_demo::action::Move_Result msg_;
};

class Init_Move_Result_success
{
public:
  Init_Move_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Move_Result_final_distance success(::robot_action_demo::action::Move_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Move_Result_final_distance(msg_);
  }

private:
  ::robot_action_demo::action::Move_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_action_demo::action::Move_Result>()
{
  return robot_action_demo::action::builder::Init_Move_Result_success();
}

}  // namespace robot_action_demo


namespace robot_action_demo
{

namespace action
{

namespace builder
{

class Init_Move_Feedback_remaining_distance
{
public:
  Init_Move_Feedback_remaining_distance()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_action_demo::action::Move_Feedback remaining_distance(::robot_action_demo::action::Move_Feedback::_remaining_distance_type arg)
  {
    msg_.remaining_distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_action_demo::action::Move_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_action_demo::action::Move_Feedback>()
{
  return robot_action_demo::action::builder::Init_Move_Feedback_remaining_distance();
}

}  // namespace robot_action_demo


namespace robot_action_demo
{

namespace action
{

namespace builder
{

class Init_Move_SendGoal_Request_goal
{
public:
  explicit Init_Move_SendGoal_Request_goal(::robot_action_demo::action::Move_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::robot_action_demo::action::Move_SendGoal_Request goal(::robot_action_demo::action::Move_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_action_demo::action::Move_SendGoal_Request msg_;
};

class Init_Move_SendGoal_Request_goal_id
{
public:
  Init_Move_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Move_SendGoal_Request_goal goal_id(::robot_action_demo::action::Move_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Move_SendGoal_Request_goal(msg_);
  }

private:
  ::robot_action_demo::action::Move_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_action_demo::action::Move_SendGoal_Request>()
{
  return robot_action_demo::action::builder::Init_Move_SendGoal_Request_goal_id();
}

}  // namespace robot_action_demo


namespace robot_action_demo
{

namespace action
{

namespace builder
{

class Init_Move_SendGoal_Response_stamp
{
public:
  explicit Init_Move_SendGoal_Response_stamp(::robot_action_demo::action::Move_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::robot_action_demo::action::Move_SendGoal_Response stamp(::robot_action_demo::action::Move_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_action_demo::action::Move_SendGoal_Response msg_;
};

class Init_Move_SendGoal_Response_accepted
{
public:
  Init_Move_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Move_SendGoal_Response_stamp accepted(::robot_action_demo::action::Move_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Move_SendGoal_Response_stamp(msg_);
  }

private:
  ::robot_action_demo::action::Move_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_action_demo::action::Move_SendGoal_Response>()
{
  return robot_action_demo::action::builder::Init_Move_SendGoal_Response_accepted();
}

}  // namespace robot_action_demo


namespace robot_action_demo
{

namespace action
{

namespace builder
{

class Init_Move_GetResult_Request_goal_id
{
public:
  Init_Move_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::robot_action_demo::action::Move_GetResult_Request goal_id(::robot_action_demo::action::Move_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_action_demo::action::Move_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_action_demo::action::Move_GetResult_Request>()
{
  return robot_action_demo::action::builder::Init_Move_GetResult_Request_goal_id();
}

}  // namespace robot_action_demo


namespace robot_action_demo
{

namespace action
{

namespace builder
{

class Init_Move_GetResult_Response_result
{
public:
  explicit Init_Move_GetResult_Response_result(::robot_action_demo::action::Move_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::robot_action_demo::action::Move_GetResult_Response result(::robot_action_demo::action::Move_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_action_demo::action::Move_GetResult_Response msg_;
};

class Init_Move_GetResult_Response_status
{
public:
  Init_Move_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Move_GetResult_Response_result status(::robot_action_demo::action::Move_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Move_GetResult_Response_result(msg_);
  }

private:
  ::robot_action_demo::action::Move_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_action_demo::action::Move_GetResult_Response>()
{
  return robot_action_demo::action::builder::Init_Move_GetResult_Response_status();
}

}  // namespace robot_action_demo


namespace robot_action_demo
{

namespace action
{

namespace builder
{

class Init_Move_FeedbackMessage_feedback
{
public:
  explicit Init_Move_FeedbackMessage_feedback(::robot_action_demo::action::Move_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::robot_action_demo::action::Move_FeedbackMessage feedback(::robot_action_demo::action::Move_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_action_demo::action::Move_FeedbackMessage msg_;
};

class Init_Move_FeedbackMessage_goal_id
{
public:
  Init_Move_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Move_FeedbackMessage_feedback goal_id(::robot_action_demo::action::Move_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Move_FeedbackMessage_feedback(msg_);
  }

private:
  ::robot_action_demo::action::Move_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_action_demo::action::Move_FeedbackMessage>()
{
  return robot_action_demo::action::builder::Init_Move_FeedbackMessage_goal_id();
}

}  // namespace robot_action_demo

#endif  // ROBOT_ACTION_DEMO__ACTION__DETAIL__MOVE__BUILDER_HPP_
