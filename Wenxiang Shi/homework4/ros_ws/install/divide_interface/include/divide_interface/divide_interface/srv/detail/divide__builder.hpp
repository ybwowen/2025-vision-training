// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from divide_interface:srv/Divide.idl
// generated code does not contain a copyright notice

#ifndef DIVIDE_INTERFACE__SRV__DETAIL__DIVIDE__BUILDER_HPP_
#define DIVIDE_INTERFACE__SRV__DETAIL__DIVIDE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "divide_interface/srv/detail/divide__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace divide_interface
{

namespace srv
{

namespace builder
{

class Init_Divide_Request_divisor
{
public:
  explicit Init_Divide_Request_divisor(::divide_interface::srv::Divide_Request & msg)
  : msg_(msg)
  {}
  ::divide_interface::srv::Divide_Request divisor(::divide_interface::srv::Divide_Request::_divisor_type arg)
  {
    msg_.divisor = std::move(arg);
    return std::move(msg_);
  }

private:
  ::divide_interface::srv::Divide_Request msg_;
};

class Init_Divide_Request_dividend
{
public:
  Init_Divide_Request_dividend()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Divide_Request_divisor dividend(::divide_interface::srv::Divide_Request::_dividend_type arg)
  {
    msg_.dividend = std::move(arg);
    return Init_Divide_Request_divisor(msg_);
  }

private:
  ::divide_interface::srv::Divide_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::divide_interface::srv::Divide_Request>()
{
  return divide_interface::srv::builder::Init_Divide_Request_dividend();
}

}  // namespace divide_interface


namespace divide_interface
{

namespace srv
{

namespace builder
{

class Init_Divide_Response_remainder
{
public:
  explicit Init_Divide_Response_remainder(::divide_interface::srv::Divide_Response & msg)
  : msg_(msg)
  {}
  ::divide_interface::srv::Divide_Response remainder(::divide_interface::srv::Divide_Response::_remainder_type arg)
  {
    msg_.remainder = std::move(arg);
    return std::move(msg_);
  }

private:
  ::divide_interface::srv::Divide_Response msg_;
};

class Init_Divide_Response_quotient
{
public:
  Init_Divide_Response_quotient()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Divide_Response_remainder quotient(::divide_interface::srv::Divide_Response::_quotient_type arg)
  {
    msg_.quotient = std::move(arg);
    return Init_Divide_Response_remainder(msg_);
  }

private:
  ::divide_interface::srv::Divide_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::divide_interface::srv::Divide_Response>()
{
  return divide_interface::srv::builder::Init_Divide_Response_quotient();
}

}  // namespace divide_interface

#endif  // DIVIDE_INTERFACE__SRV__DETAIL__DIVIDE__BUILDER_HPP_
