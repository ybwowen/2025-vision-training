// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from action_demo:srv/Action.idl
// generated code does not contain a copyright notice

#ifndef ACTION_DEMO__SRV__DETAIL__ACTION__STRUCT_HPP_
#define ACTION_DEMO__SRV__DETAIL__ACTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__action_demo__srv__Action_Request __attribute__((deprecated))
#else
# define DEPRECATED__action_demo__srv__Action_Request __declspec(deprecated)
#endif

namespace action_demo
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Action_Request_
{
  using Type = Action_Request_<ContainerAllocator>;

  explicit Action_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distance = 0.0;
    }
  }

  explicit Action_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distance = 0.0;
    }
  }

  // field types and members
  using _distance_type =
    double;
  _distance_type distance;

  // setters for named parameter idiom
  Type & set__distance(
    const double & _arg)
  {
    this->distance = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_demo::srv::Action_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_demo::srv::Action_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_demo::srv::Action_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_demo::srv::Action_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_demo::srv::Action_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_demo::srv::Action_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_demo::srv::Action_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_demo::srv::Action_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_demo::srv::Action_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_demo::srv::Action_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_demo__srv__Action_Request
    std::shared_ptr<action_demo::srv::Action_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_demo__srv__Action_Request
    std::shared_ptr<action_demo::srv::Action_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Action_Request_ & other) const
  {
    if (this->distance != other.distance) {
      return false;
    }
    return true;
  }
  bool operator!=(const Action_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Action_Request_

// alias to use template instance with default allocator
using Action_Request =
  action_demo::srv::Action_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace action_demo


#ifndef _WIN32
# define DEPRECATED__action_demo__srv__Action_Response __attribute__((deprecated))
#else
# define DEPRECATED__action_demo__srv__Action_Response __declspec(deprecated)
#endif

namespace action_demo
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Action_Response_
{
  using Type = Action_Response_<ContainerAllocator>;

  explicit Action_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->remaining_distance = 0.0;
      this->success = false;
    }
  }

  explicit Action_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->remaining_distance = 0.0;
      this->success = false;
    }
  }

  // field types and members
  using _remaining_distance_type =
    double;
  _remaining_distance_type remaining_distance;
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__remaining_distance(
    const double & _arg)
  {
    this->remaining_distance = _arg;
    return *this;
  }
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_demo::srv::Action_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_demo::srv::Action_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_demo::srv::Action_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_demo::srv::Action_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_demo::srv::Action_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_demo::srv::Action_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_demo::srv::Action_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_demo::srv::Action_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_demo::srv::Action_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_demo::srv::Action_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_demo__srv__Action_Response
    std::shared_ptr<action_demo::srv::Action_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_demo__srv__Action_Response
    std::shared_ptr<action_demo::srv::Action_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Action_Response_ & other) const
  {
    if (this->remaining_distance != other.remaining_distance) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const Action_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Action_Response_

// alias to use template instance with default allocator
using Action_Response =
  action_demo::srv::Action_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace action_demo

namespace action_demo
{

namespace srv
{

struct Action
{
  using Request = action_demo::srv::Action_Request;
  using Response = action_demo::srv::Action_Response;
};

}  // namespace srv

}  // namespace action_demo

#endif  // ACTION_DEMO__SRV__DETAIL__ACTION__STRUCT_HPP_
