// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from division_interfaces:srv/DivisionService.idl
// generated code does not contain a copyright notice

#ifndef DIVISION_INTERFACES__SRV__DETAIL__DIVISION_SERVICE__BUILDER_HPP_
#define DIVISION_INTERFACES__SRV__DETAIL__DIVISION_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "division_interfaces/srv/detail/division_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace division_interfaces
{

namespace srv
{

namespace builder
{

class Init_DivisionService_Request_divisor
{
public:
  explicit Init_DivisionService_Request_divisor(::division_interfaces::srv::DivisionService_Request & msg)
  : msg_(msg)
  {}
  ::division_interfaces::srv::DivisionService_Request divisor(::division_interfaces::srv::DivisionService_Request::_divisor_type arg)
  {
    msg_.divisor = std::move(arg);
    return std::move(msg_);
  }

private:
  ::division_interfaces::srv::DivisionService_Request msg_;
};

class Init_DivisionService_Request_dividend
{
public:
  Init_DivisionService_Request_dividend()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DivisionService_Request_divisor dividend(::division_interfaces::srv::DivisionService_Request::_dividend_type arg)
  {
    msg_.dividend = std::move(arg);
    return Init_DivisionService_Request_divisor(msg_);
  }

private:
  ::division_interfaces::srv::DivisionService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::division_interfaces::srv::DivisionService_Request>()
{
  return division_interfaces::srv::builder::Init_DivisionService_Request_dividend();
}

}  // namespace division_interfaces


namespace division_interfaces
{

namespace srv
{

namespace builder
{

class Init_DivisionService_Response_remainder
{
public:
  explicit Init_DivisionService_Response_remainder(::division_interfaces::srv::DivisionService_Response & msg)
  : msg_(msg)
  {}
  ::division_interfaces::srv::DivisionService_Response remainder(::division_interfaces::srv::DivisionService_Response::_remainder_type arg)
  {
    msg_.remainder = std::move(arg);
    return std::move(msg_);
  }

private:
  ::division_interfaces::srv::DivisionService_Response msg_;
};

class Init_DivisionService_Response_quotient
{
public:
  Init_DivisionService_Response_quotient()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DivisionService_Response_remainder quotient(::division_interfaces::srv::DivisionService_Response::_quotient_type arg)
  {
    msg_.quotient = std::move(arg);
    return Init_DivisionService_Response_remainder(msg_);
  }

private:
  ::division_interfaces::srv::DivisionService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::division_interfaces::srv::DivisionService_Response>()
{
  return division_interfaces::srv::builder::Init_DivisionService_Response_quotient();
}

}  // namespace division_interfaces

#endif  // DIVISION_INTERFACES__SRV__DETAIL__DIVISION_SERVICE__BUILDER_HPP_
