// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from division_interface:msg/Robot.idl
// generated code does not contain a copyright notice

#ifndef DIVISION_INTERFACE__MSG__DETAIL__ROBOT__BUILDER_HPP_
#define DIVISION_INTERFACE__MSG__DETAIL__ROBOT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "division_interface/msg/detail/robot__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace division_interface
{

namespace msg
{

namespace builder
{

class Init_Robot_num2
{
public:
  explicit Init_Robot_num2(::division_interface::msg::Robot & msg)
  : msg_(msg)
  {}
  ::division_interface::msg::Robot num2(::division_interface::msg::Robot::_num2_type arg)
  {
    msg_.num2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::division_interface::msg::Robot msg_;
};

class Init_Robot_num1
{
public:
  Init_Robot_num1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Robot_num2 num1(::division_interface::msg::Robot::_num1_type arg)
  {
    msg_.num1 = std::move(arg);
    return Init_Robot_num2(msg_);
  }

private:
  ::division_interface::msg::Robot msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::division_interface::msg::Robot>()
{
  return division_interface::msg::builder::Init_Robot_num1();
}

}  // namespace division_interface

#endif  // DIVISION_INTERFACE__MSG__DETAIL__ROBOT__BUILDER_HPP_
