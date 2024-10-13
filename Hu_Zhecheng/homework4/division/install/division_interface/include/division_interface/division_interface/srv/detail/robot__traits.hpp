// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from division_interface:srv/Robot.idl
// generated code does not contain a copyright notice

#ifndef DIVISION_INTERFACE__SRV__DETAIL__ROBOT__TRAITS_HPP_
#define DIVISION_INTERFACE__SRV__DETAIL__ROBOT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "division_interface/srv/detail/robot__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace division_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const Robot_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: num1
  {
    out << "num1: ";
    rosidl_generator_traits::value_to_yaml(msg.num1, out);
    out << ", ";
  }

  // member: num2
  {
    out << "num2: ";
    rosidl_generator_traits::value_to_yaml(msg.num2, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Robot_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: num1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num1: ";
    rosidl_generator_traits::value_to_yaml(msg.num1, out);
    out << "\n";
  }

  // member: num2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "num2: ";
    rosidl_generator_traits::value_to_yaml(msg.num2, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Robot_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace division_interface

namespace rosidl_generator_traits
{

[[deprecated("use division_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const division_interface::srv::Robot_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  division_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use division_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const division_interface::srv::Robot_Request & msg)
{
  return division_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<division_interface::srv::Robot_Request>()
{
  return "division_interface::srv::Robot_Request";
}

template<>
inline const char * name<division_interface::srv::Robot_Request>()
{
  return "division_interface/srv/Robot_Request";
}

template<>
struct has_fixed_size<division_interface::srv::Robot_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<division_interface::srv::Robot_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<division_interface::srv::Robot_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace division_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const Robot_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: quotient
  {
    out << "quotient: ";
    rosidl_generator_traits::value_to_yaml(msg.quotient, out);
    out << ", ";
  }

  // member: remainder
  {
    out << "remainder: ";
    rosidl_generator_traits::value_to_yaml(msg.remainder, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Robot_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: quotient
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "quotient: ";
    rosidl_generator_traits::value_to_yaml(msg.quotient, out);
    out << "\n";
  }

  // member: remainder
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "remainder: ";
    rosidl_generator_traits::value_to_yaml(msg.remainder, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Robot_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace division_interface

namespace rosidl_generator_traits
{

[[deprecated("use division_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const division_interface::srv::Robot_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  division_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use division_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const division_interface::srv::Robot_Response & msg)
{
  return division_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<division_interface::srv::Robot_Response>()
{
  return "division_interface::srv::Robot_Response";
}

template<>
inline const char * name<division_interface::srv::Robot_Response>()
{
  return "division_interface/srv/Robot_Response";
}

template<>
struct has_fixed_size<division_interface::srv::Robot_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<division_interface::srv::Robot_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<division_interface::srv::Robot_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<division_interface::srv::Robot>()
{
  return "division_interface::srv::Robot";
}

template<>
inline const char * name<division_interface::srv::Robot>()
{
  return "division_interface/srv/Robot";
}

template<>
struct has_fixed_size<division_interface::srv::Robot>
  : std::integral_constant<
    bool,
    has_fixed_size<division_interface::srv::Robot_Request>::value &&
    has_fixed_size<division_interface::srv::Robot_Response>::value
  >
{
};

template<>
struct has_bounded_size<division_interface::srv::Robot>
  : std::integral_constant<
    bool,
    has_bounded_size<division_interface::srv::Robot_Request>::value &&
    has_bounded_size<division_interface::srv::Robot_Response>::value
  >
{
};

template<>
struct is_service<division_interface::srv::Robot>
  : std::true_type
{
};

template<>
struct is_service_request<division_interface::srv::Robot_Request>
  : std::true_type
{
};

template<>
struct is_service_response<division_interface::srv::Robot_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DIVISION_INTERFACE__SRV__DETAIL__ROBOT__TRAITS_HPP_
