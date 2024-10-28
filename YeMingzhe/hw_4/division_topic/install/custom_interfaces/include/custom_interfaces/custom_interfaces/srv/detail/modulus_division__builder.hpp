// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:srv/ModulusDivision.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__MODULUS_DIVISION__BUILDER_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__MODULUS_DIVISION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/srv/detail/modulus_division__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_ModulusDivision_Request_divisor
{
public:
  explicit Init_ModulusDivision_Request_divisor(::custom_interfaces::srv::ModulusDivision_Request & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::ModulusDivision_Request divisor(::custom_interfaces::srv::ModulusDivision_Request::_divisor_type arg)
  {
    msg_.divisor = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::ModulusDivision_Request msg_;
};

class Init_ModulusDivision_Request_dividend
{
public:
  Init_ModulusDivision_Request_dividend()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ModulusDivision_Request_divisor dividend(::custom_interfaces::srv::ModulusDivision_Request::_dividend_type arg)
  {
    msg_.dividend = std::move(arg);
    return Init_ModulusDivision_Request_divisor(msg_);
  }

private:
  ::custom_interfaces::srv::ModulusDivision_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::ModulusDivision_Request>()
{
  return custom_interfaces::srv::builder::Init_ModulusDivision_Request_dividend();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_ModulusDivision_Response_remainder
{
public:
  explicit Init_ModulusDivision_Response_remainder(::custom_interfaces::srv::ModulusDivision_Response & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::ModulusDivision_Response remainder(::custom_interfaces::srv::ModulusDivision_Response::_remainder_type arg)
  {
    msg_.remainder = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::ModulusDivision_Response msg_;
};

class Init_ModulusDivision_Response_quotient
{
public:
  Init_ModulusDivision_Response_quotient()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ModulusDivision_Response_remainder quotient(::custom_interfaces::srv::ModulusDivision_Response::_quotient_type arg)
  {
    msg_.quotient = std::move(arg);
    return Init_ModulusDivision_Response_remainder(msg_);
  }

private:
  ::custom_interfaces::srv::ModulusDivision_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::ModulusDivision_Response>()
{
  return custom_interfaces::srv::builder::Init_ModulusDivision_Response_quotient();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__MODULUS_DIVISION__BUILDER_HPP_
