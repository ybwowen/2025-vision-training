// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from divide_interface:srv/Divide.idl
// generated code does not contain a copyright notice

#ifndef DIVIDE_INTERFACE__SRV__DETAIL__DIVIDE__TRAITS_HPP_
#define DIVIDE_INTERFACE__SRV__DETAIL__DIVIDE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "divide_interface/srv/detail/divide__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace divide_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const Divide_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: dividend
  {
    out << "dividend: ";
    rosidl_generator_traits::value_to_yaml(msg.dividend, out);
    out << ", ";
  }

  // member: divisor
  {
    out << "divisor: ";
    rosidl_generator_traits::value_to_yaml(msg.divisor, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Divide_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: dividend
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dividend: ";
    rosidl_generator_traits::value_to_yaml(msg.dividend, out);
    out << "\n";
  }

  // member: divisor
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "divisor: ";
    rosidl_generator_traits::value_to_yaml(msg.divisor, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Divide_Request & msg, bool use_flow_style = false)
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

}  // namespace divide_interface

namespace rosidl_generator_traits
{

[[deprecated("use divide_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const divide_interface::srv::Divide_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  divide_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use divide_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const divide_interface::srv::Divide_Request & msg)
{
  return divide_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<divide_interface::srv::Divide_Request>()
{
  return "divide_interface::srv::Divide_Request";
}

template<>
inline const char * name<divide_interface::srv::Divide_Request>()
{
  return "divide_interface/srv/Divide_Request";
}

template<>
struct has_fixed_size<divide_interface::srv::Divide_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<divide_interface::srv::Divide_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<divide_interface::srv::Divide_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace divide_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const Divide_Response & msg,
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
  const Divide_Response & msg,
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

inline std::string to_yaml(const Divide_Response & msg, bool use_flow_style = false)
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

}  // namespace divide_interface

namespace rosidl_generator_traits
{

[[deprecated("use divide_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const divide_interface::srv::Divide_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  divide_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use divide_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const divide_interface::srv::Divide_Response & msg)
{
  return divide_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<divide_interface::srv::Divide_Response>()
{
  return "divide_interface::srv::Divide_Response";
}

template<>
inline const char * name<divide_interface::srv::Divide_Response>()
{
  return "divide_interface/srv/Divide_Response";
}

template<>
struct has_fixed_size<divide_interface::srv::Divide_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<divide_interface::srv::Divide_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<divide_interface::srv::Divide_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<divide_interface::srv::Divide>()
{
  return "divide_interface::srv::Divide";
}

template<>
inline const char * name<divide_interface::srv::Divide>()
{
  return "divide_interface/srv/Divide";
}

template<>
struct has_fixed_size<divide_interface::srv::Divide>
  : std::integral_constant<
    bool,
    has_fixed_size<divide_interface::srv::Divide_Request>::value &&
    has_fixed_size<divide_interface::srv::Divide_Response>::value
  >
{
};

template<>
struct has_bounded_size<divide_interface::srv::Divide>
  : std::integral_constant<
    bool,
    has_bounded_size<divide_interface::srv::Divide_Request>::value &&
    has_bounded_size<divide_interface::srv::Divide_Response>::value
  >
{
};

template<>
struct is_service<divide_interface::srv::Divide>
  : std::true_type
{
};

template<>
struct is_service_request<divide_interface::srv::Divide_Request>
  : std::true_type
{
};

template<>
struct is_service_response<divide_interface::srv::Divide_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DIVIDE_INTERFACE__SRV__DETAIL__DIVIDE__TRAITS_HPP_
