// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from action_demo:srv/Action.idl
// generated code does not contain a copyright notice

#ifndef ACTION_DEMO__SRV__DETAIL__ACTION__BUILDER_HPP_
#define ACTION_DEMO__SRV__DETAIL__ACTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "action_demo/srv/detail/action__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace action_demo
{

namespace srv
{

namespace builder
{

class Init_Action_Request_distance
{
public:
  Init_Action_Request_distance()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_demo::srv::Action_Request distance(::action_demo::srv::Action_Request::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_demo::srv::Action_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_demo::srv::Action_Request>()
{
  return action_demo::srv::builder::Init_Action_Request_distance();
}

}  // namespace action_demo


namespace action_demo
{

namespace srv
{

namespace builder
{

class Init_Action_Response_success
{
public:
  explicit Init_Action_Response_success(::action_demo::srv::Action_Response & msg)
  : msg_(msg)
  {}
  ::action_demo::srv::Action_Response success(::action_demo::srv::Action_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_demo::srv::Action_Response msg_;
};

class Init_Action_Response_remaining_distance
{
public:
  Init_Action_Response_remaining_distance()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Action_Response_success remaining_distance(::action_demo::srv::Action_Response::_remaining_distance_type arg)
  {
    msg_.remaining_distance = std::move(arg);
    return Init_Action_Response_success(msg_);
  }

private:
  ::action_demo::srv::Action_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_demo::srv::Action_Response>()
{
  return action_demo::srv::builder::Init_Action_Response_remaining_distance();
}

}  // namespace action_demo

#endif  // ACTION_DEMO__SRV__DETAIL__ACTION__BUILDER_HPP_
