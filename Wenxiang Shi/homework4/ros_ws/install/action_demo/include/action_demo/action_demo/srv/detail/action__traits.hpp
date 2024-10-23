// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from action_demo:srv/Action.idl
// generated code does not contain a copyright notice

#ifndef ACTION_DEMO__SRV__DETAIL__ACTION__TRAITS_HPP_
#define ACTION_DEMO__SRV__DETAIL__ACTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "action_demo/srv/detail/action__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace action_demo
{

namespace srv
{

inline void to_flow_style_yaml(
  const Action_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: distance
  {
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Action_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Action_Request & msg, bool use_flow_style = false)
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

}  // namespace action_demo

namespace rosidl_generator_traits
{

[[deprecated("use action_demo::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_demo::srv::Action_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_demo::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_demo::srv::to_yaml() instead")]]
inline std::string to_yaml(const action_demo::srv::Action_Request & msg)
{
  return action_demo::srv::to_yaml(msg);
}

template<>
inline const char * data_type<action_demo::srv::Action_Request>()
{
  return "action_demo::srv::Action_Request";
}

template<>
inline const char * name<action_demo::srv::Action_Request>()
{
  return "action_demo/srv/Action_Request";
}

template<>
struct has_fixed_size<action_demo::srv::Action_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<action_demo::srv::Action_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<action_demo::srv::Action_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace action_demo
{

namespace srv
{

inline void to_flow_style_yaml(
  const Action_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: remaining_distance
  {
    out << "remaining_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.remaining_distance, out);
    out << ", ";
  }

  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Action_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: remaining_distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "remaining_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.remaining_distance, out);
    out << "\n";
  }

  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Action_Response & msg, bool use_flow_style = false)
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

}  // namespace action_demo

namespace rosidl_generator_traits
{

[[deprecated("use action_demo::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_demo::srv::Action_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_demo::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_demo::srv::to_yaml() instead")]]
inline std::string to_yaml(const action_demo::srv::Action_Response & msg)
{
  return action_demo::srv::to_yaml(msg);
}

template<>
inline const char * data_type<action_demo::srv::Action_Response>()
{
  return "action_demo::srv::Action_Response";
}

template<>
inline const char * name<action_demo::srv::Action_Response>()
{
  return "action_demo/srv/Action_Response";
}

template<>
struct has_fixed_size<action_demo::srv::Action_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<action_demo::srv::Action_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<action_demo::srv::Action_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_demo::srv::Action>()
{
  return "action_demo::srv::Action";
}

template<>
inline const char * name<action_demo::srv::Action>()
{
  return "action_demo/srv/Action";
}

template<>
struct has_fixed_size<action_demo::srv::Action>
  : std::integral_constant<
    bool,
    has_fixed_size<action_demo::srv::Action_Request>::value &&
    has_fixed_size<action_demo::srv::Action_Response>::value
  >
{
};

template<>
struct has_bounded_size<action_demo::srv::Action>
  : std::integral_constant<
    bool,
    has_bounded_size<action_demo::srv::Action_Request>::value &&
    has_bounded_size<action_demo::srv::Action_Response>::value
  >
{
};

template<>
struct is_service<action_demo::srv::Action>
  : std::true_type
{
};

template<>
struct is_service_request<action_demo::srv::Action_Request>
  : std::true_type
{
};

template<>
struct is_service_response<action_demo::srv::Action_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ACTION_DEMO__SRV__DETAIL__ACTION__TRAITS_HPP_
