// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from division_interfaces:srv/DivisionService.idl
// generated code does not contain a copyright notice

#ifndef DIVISION_INTERFACES__SRV__DETAIL__DIVISION_SERVICE__TRAITS_HPP_
#define DIVISION_INTERFACES__SRV__DETAIL__DIVISION_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "division_interfaces/srv/detail/division_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace division_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DivisionService_Request & msg,
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
  const DivisionService_Request & msg,
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

inline std::string to_yaml(const DivisionService_Request & msg, bool use_flow_style = false)
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

}  // namespace division_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use division_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const division_interfaces::srv::DivisionService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  division_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use division_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const division_interfaces::srv::DivisionService_Request & msg)
{
  return division_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<division_interfaces::srv::DivisionService_Request>()
{
  return "division_interfaces::srv::DivisionService_Request";
}

template<>
inline const char * name<division_interfaces::srv::DivisionService_Request>()
{
  return "division_interfaces/srv/DivisionService_Request";
}

template<>
struct has_fixed_size<division_interfaces::srv::DivisionService_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<division_interfaces::srv::DivisionService_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<division_interfaces::srv::DivisionService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace division_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DivisionService_Response & msg,
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
  const DivisionService_Response & msg,
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

inline std::string to_yaml(const DivisionService_Response & msg, bool use_flow_style = false)
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

}  // namespace division_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use division_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const division_interfaces::srv::DivisionService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  division_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use division_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const division_interfaces::srv::DivisionService_Response & msg)
{
  return division_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<division_interfaces::srv::DivisionService_Response>()
{
  return "division_interfaces::srv::DivisionService_Response";
}

template<>
inline const char * name<division_interfaces::srv::DivisionService_Response>()
{
  return "division_interfaces/srv/DivisionService_Response";
}

template<>
struct has_fixed_size<division_interfaces::srv::DivisionService_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<division_interfaces::srv::DivisionService_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<division_interfaces::srv::DivisionService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<division_interfaces::srv::DivisionService>()
{
  return "division_interfaces::srv::DivisionService";
}

template<>
inline const char * name<division_interfaces::srv::DivisionService>()
{
  return "division_interfaces/srv/DivisionService";
}

template<>
struct has_fixed_size<division_interfaces::srv::DivisionService>
  : std::integral_constant<
    bool,
    has_fixed_size<division_interfaces::srv::DivisionService_Request>::value &&
    has_fixed_size<division_interfaces::srv::DivisionService_Response>::value
  >
{
};

template<>
struct has_bounded_size<division_interfaces::srv::DivisionService>
  : std::integral_constant<
    bool,
    has_bounded_size<division_interfaces::srv::DivisionService_Request>::value &&
    has_bounded_size<division_interfaces::srv::DivisionService_Response>::value
  >
{
};

template<>
struct is_service<division_interfaces::srv::DivisionService>
  : std::true_type
{
};

template<>
struct is_service_request<division_interfaces::srv::DivisionService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<division_interfaces::srv::DivisionService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DIVISION_INTERFACES__SRV__DETAIL__DIVISION_SERVICE__TRAITS_HPP_
