// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from action_interface:action/MoveRobot.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACE__ACTION__DETAIL__MOVE_ROBOT__BUILDER_HPP_
#define ACTION_INTERFACE__ACTION__DETAIL__MOVE_ROBOT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "action_interface/action/detail/move_robot__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_MoveRobot_Goal_distance
{
public:
  Init_MoveRobot_Goal_distance()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interface::action::MoveRobot_Goal distance(::action_interface::action::MoveRobot_Goal::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::MoveRobot_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::MoveRobot_Goal>()
{
  return action_interface::action::builder::Init_MoveRobot_Goal_distance();
}

}  // namespace action_interface


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_MoveRobot_Result_remain
{
public:
  Init_MoveRobot_Result_remain()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interface::action::MoveRobot_Result remain(::action_interface::action::MoveRobot_Result::_remain_type arg)
  {
    msg_.remain = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::MoveRobot_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::MoveRobot_Result>()
{
  return action_interface::action::builder::Init_MoveRobot_Result_remain();
}

}  // namespace action_interface


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_MoveRobot_Feedback_remain
{
public:
  Init_MoveRobot_Feedback_remain()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interface::action::MoveRobot_Feedback remain(::action_interface::action::MoveRobot_Feedback::_remain_type arg)
  {
    msg_.remain = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::MoveRobot_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::MoveRobot_Feedback>()
{
  return action_interface::action::builder::Init_MoveRobot_Feedback_remain();
}

}  // namespace action_interface


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_MoveRobot_SendGoal_Request_goal
{
public:
  explicit Init_MoveRobot_SendGoal_Request_goal(::action_interface::action::MoveRobot_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::action_interface::action::MoveRobot_SendGoal_Request goal(::action_interface::action::MoveRobot_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::MoveRobot_SendGoal_Request msg_;
};

class Init_MoveRobot_SendGoal_Request_goal_id
{
public:
  Init_MoveRobot_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveRobot_SendGoal_Request_goal goal_id(::action_interface::action::MoveRobot_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveRobot_SendGoal_Request_goal(msg_);
  }

private:
  ::action_interface::action::MoveRobot_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::MoveRobot_SendGoal_Request>()
{
  return action_interface::action::builder::Init_MoveRobot_SendGoal_Request_goal_id();
}

}  // namespace action_interface


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_MoveRobot_SendGoal_Response_stamp
{
public:
  explicit Init_MoveRobot_SendGoal_Response_stamp(::action_interface::action::MoveRobot_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::action_interface::action::MoveRobot_SendGoal_Response stamp(::action_interface::action::MoveRobot_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::MoveRobot_SendGoal_Response msg_;
};

class Init_MoveRobot_SendGoal_Response_accepted
{
public:
  Init_MoveRobot_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveRobot_SendGoal_Response_stamp accepted(::action_interface::action::MoveRobot_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_MoveRobot_SendGoal_Response_stamp(msg_);
  }

private:
  ::action_interface::action::MoveRobot_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::MoveRobot_SendGoal_Response>()
{
  return action_interface::action::builder::Init_MoveRobot_SendGoal_Response_accepted();
}

}  // namespace action_interface


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_MoveRobot_GetResult_Request_goal_id
{
public:
  Init_MoveRobot_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interface::action::MoveRobot_GetResult_Request goal_id(::action_interface::action::MoveRobot_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::MoveRobot_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::MoveRobot_GetResult_Request>()
{
  return action_interface::action::builder::Init_MoveRobot_GetResult_Request_goal_id();
}

}  // namespace action_interface


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_MoveRobot_GetResult_Response_result
{
public:
  explicit Init_MoveRobot_GetResult_Response_result(::action_interface::action::MoveRobot_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::action_interface::action::MoveRobot_GetResult_Response result(::action_interface::action::MoveRobot_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::MoveRobot_GetResult_Response msg_;
};

class Init_MoveRobot_GetResult_Response_status
{
public:
  Init_MoveRobot_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveRobot_GetResult_Response_result status(::action_interface::action::MoveRobot_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_MoveRobot_GetResult_Response_result(msg_);
  }

private:
  ::action_interface::action::MoveRobot_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::MoveRobot_GetResult_Response>()
{
  return action_interface::action::builder::Init_MoveRobot_GetResult_Response_status();
}

}  // namespace action_interface


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_MoveRobot_FeedbackMessage_feedback
{
public:
  explicit Init_MoveRobot_FeedbackMessage_feedback(::action_interface::action::MoveRobot_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::action_interface::action::MoveRobot_FeedbackMessage feedback(::action_interface::action::MoveRobot_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::MoveRobot_FeedbackMessage msg_;
};

class Init_MoveRobot_FeedbackMessage_goal_id
{
public:
  Init_MoveRobot_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveRobot_FeedbackMessage_feedback goal_id(::action_interface::action::MoveRobot_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveRobot_FeedbackMessage_feedback(msg_);
  }

private:
  ::action_interface::action::MoveRobot_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::MoveRobot_FeedbackMessage>()
{
  return action_interface::action::builder::Init_MoveRobot_FeedbackMessage_goal_id();
}

}  // namespace action_interface

#endif  // ACTION_INTERFACE__ACTION__DETAIL__MOVE_ROBOT__BUILDER_HPP_
