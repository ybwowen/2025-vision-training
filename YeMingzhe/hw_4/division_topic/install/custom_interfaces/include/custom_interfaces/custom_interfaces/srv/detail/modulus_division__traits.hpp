// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:srv/ModulusDivision.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__MODULUS_DIVISION__TRAITS_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__MODULUS_DIVISION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/srv/detail/modulus_division__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ModulusDivision_Request & msg,
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
  const ModulusDivision_Request & msg,
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

inline std::string to_yaml(const ModulusDivision_Request & msg, bool use_flow_style = false)
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

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::srv::ModulusDivision_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::ModulusDivision_Request & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::ModulusDivision_Request>()
{
  return "custom_interfaces::srv::ModulusDivision_Request";
}

template<>
inline const char * name<custom_interfaces::srv::ModulusDivision_Request>()
{
  return "custom_interfaces/srv/ModulusDivision_Request";
}

template<>
struct has_fixed_size<custom_interfaces::srv::ModulusDivision_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_interfaces::srv::ModulusDivision_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_interfaces::srv::ModulusDivision_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ModulusDivision_Response & msg,
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
  const ModulusDivision_Response & msg,
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

inline std::string to_yaml(const ModulusDivision_Response & msg, bool use_flow_style = false)
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

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::srv::ModulusDivision_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::ModulusDivision_Response & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::ModulusDivision_Response>()
{
  return "custom_interfaces::srv::ModulusDivision_Response";
}

template<>
inline const char * name<custom_interfaces::srv::ModulusDivision_Response>()
{
  return "custom_interfaces/srv/ModulusDivision_Response";
}

template<>
struct has_fixed_size<custom_interfaces::srv::ModulusDivision_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_interfaces::srv::ModulusDivision_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_interfaces::srv::ModulusDivision_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interfaces::srv::ModulusDivision>()
{
  return "custom_interfaces::srv::ModulusDivision";
}

template<>
inline const char * name<custom_interfaces::srv::ModulusDivision>()
{
  return "custom_interfaces/srv/ModulusDivision";
}

template<>
struct has_fixed_size<custom_interfaces::srv::ModulusDivision>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_interfaces::srv::ModulusDivision_Request>::value &&
    has_fixed_size<custom_interfaces::srv::ModulusDivision_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_interfaces::srv::ModulusDivision>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_interfaces::srv::ModulusDivision_Request>::value &&
    has_bounded_size<custom_interfaces::srv::ModulusDivision_Response>::value
  >
{
};

template<>
struct is_service<custom_interfaces::srv::ModulusDivision>
  : std::true_type
{
};

template<>
struct is_service_request<custom_interfaces::srv::ModulusDivision_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_interfaces::srv::ModulusDivision_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__MODULUS_DIVISION__TRAITS_HPP_
