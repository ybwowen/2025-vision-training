// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from division_interface:msg/Robot.idl
// generated code does not contain a copyright notice

#ifndef DIVISION_INTERFACE__MSG__DETAIL__ROBOT__STRUCT_HPP_
#define DIVISION_INTERFACE__MSG__DETAIL__ROBOT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__division_interface__msg__Robot __attribute__((deprecated))
#else
# define DEPRECATED__division_interface__msg__Robot __declspec(deprecated)
#endif

namespace division_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Robot_
{
  using Type = Robot_<ContainerAllocator>;

  explicit Robot_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num1 = 0ll;
      this->num2 = 0ll;
    }
  }

  explicit Robot_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num1 = 0ll;
      this->num2 = 0ll;
    }
  }

  // field types and members
  using _num1_type =
    int64_t;
  _num1_type num1;
  using _num2_type =
    int64_t;
  _num2_type num2;

  // setters for named parameter idiom
  Type & set__num1(
    const int64_t & _arg)
  {
    this->num1 = _arg;
    return *this;
  }
  Type & set__num2(
    const int64_t & _arg)
  {
    this->num2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    division_interface::msg::Robot_<ContainerAllocator> *;
  using ConstRawPtr =
    const division_interface::msg::Robot_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<division_interface::msg::Robot_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<division_interface::msg::Robot_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      division_interface::msg::Robot_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<division_interface::msg::Robot_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      division_interface::msg::Robot_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<division_interface::msg::Robot_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<division_interface::msg::Robot_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<division_interface::msg::Robot_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__division_interface__msg__Robot
    std::shared_ptr<division_interface::msg::Robot_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__division_interface__msg__Robot
    std::shared_ptr<division_interface::msg::Robot_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Robot_ & other) const
  {
    if (this->num1 != other.num1) {
      return false;
    }
    if (this->num2 != other.num2) {
      return false;
    }
    return true;
  }
  bool operator!=(const Robot_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Robot_

// alias to use template instance with default allocator
using Robot =
  division_interface::msg::Robot_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace division_interface

#endif  // DIVISION_INTERFACE__MSG__DETAIL__ROBOT__STRUCT_HPP_
