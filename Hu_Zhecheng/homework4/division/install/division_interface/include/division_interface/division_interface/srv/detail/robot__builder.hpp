// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from division_interface:srv/Robot.idl
// generated code does not contain a copyright notice

#ifndef DIVISION_INTERFACE__SRV__DETAIL__ROBOT__BUILDER_HPP_
#define DIVISION_INTERFACE__SRV__DETAIL__ROBOT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "division_interface/srv/detail/robot__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace division_interface
{

namespace srv
{

namespace builder
{

class Init_Robot_Request_num2
{
public:
  explicit Init_Robot_Request_num2(::division_interface::srv::Robot_Request & msg)
  : msg_(msg)
  {}
  ::division_interface::srv::Robot_Request num2(::division_interface::srv::Robot_Request::_num2_type arg)
  {
    msg_.num2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::division_interface::srv::Robot_Request msg_;
};

class Init_Robot_Request_num1
{
public:
  Init_Robot_Request_num1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Robot_Request_num2 num1(::division_interface::srv::Robot_Request::_num1_type arg)
  {
    msg_.num1 = std::move(arg);
    return Init_Robot_Request_num2(msg_);
  }

private:
  ::division_interface::srv::Robot_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::division_interface::srv::Robot_Request>()
{
  return division_interface::srv::builder::Init_Robot_Request_num1();
}

}  // namespace division_interface


namespace division_interface
{

namespace srv
{

namespace builder
{

class Init_Robot_Response_remainder
{
public:
  explicit Init_Robot_Response_remainder(::division_interface::srv::Robot_Response & msg)
  : msg_(msg)
  {}
  ::division_interface::srv::Robot_Response remainder(::division_interface::srv::Robot_Response::_remainder_type arg)
  {
    msg_.remainder = std::move(arg);
    return std::move(msg_);
  }

private:
  ::division_interface::srv::Robot_Response msg_;
};

class Init_Robot_Response_quotient
{
public:
  Init_Robot_Response_quotient()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Robot_Response_remainder quotient(::division_interface::srv::Robot_Response::_quotient_type arg)
  {
    msg_.quotient = std::move(arg);
    return Init_Robot_Response_remainder(msg_);
  }

private:
  ::division_interface::srv::Robot_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::division_interface::srv::Robot_Response>()
{
  return division_interface::srv::builder::Init_Robot_Response_quotient();
}

}  // namespace division_interface

#endif  // DIVISION_INTERFACE__SRV__DETAIL__ROBOT__BUILDER_HPP_
