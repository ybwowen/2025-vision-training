// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from division_interface:srv/Robot.idl
// generated code does not contain a copyright notice

#ifndef DIVISION_INTERFACE__SRV__DETAIL__ROBOT__STRUCT_HPP_
#define DIVISION_INTERFACE__SRV__DETAIL__ROBOT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__division_interface__srv__Robot_Request __attribute__((deprecated))
#else
# define DEPRECATED__division_interface__srv__Robot_Request __declspec(deprecated)
#endif

namespace division_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Robot_Request_
{
  using Type = Robot_Request_<ContainerAllocator>;

  explicit Robot_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->num1 = 0ll;
      this->num2 = 0ll;
    }
  }

  explicit Robot_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    division_interface::srv::Robot_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const division_interface::srv::Robot_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<division_interface::srv::Robot_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<division_interface::srv::Robot_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      division_interface::srv::Robot_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<division_interface::srv::Robot_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      division_interface::srv::Robot_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<division_interface::srv::Robot_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<division_interface::srv::Robot_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<division_interface::srv::Robot_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__division_interface__srv__Robot_Request
    std::shared_ptr<division_interface::srv::Robot_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__division_interface__srv__Robot_Request
    std::shared_ptr<division_interface::srv::Robot_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Robot_Request_ & other) const
  {
    if (this->num1 != other.num1) {
      return false;
    }
    if (this->num2 != other.num2) {
      return false;
    }
    return true;
  }
  bool operator!=(const Robot_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Robot_Request_

// alias to use template instance with default allocator
using Robot_Request =
  division_interface::srv::Robot_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace division_interface


#ifndef _WIN32
# define DEPRECATED__division_interface__srv__Robot_Response __attribute__((deprecated))
#else
# define DEPRECATED__division_interface__srv__Robot_Response __declspec(deprecated)
#endif

namespace division_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Robot_Response_
{
  using Type = Robot_Response_<ContainerAllocator>;

  explicit Robot_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->quotient = 0ll;
      this->remainder = 0ll;
    }
  }

  explicit Robot_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->quotient = 0ll;
      this->remainder = 0ll;
    }
  }

  // field types and members
  using _quotient_type =
    int64_t;
  _quotient_type quotient;
  using _remainder_type =
    int64_t;
  _remainder_type remainder;

  // setters for named parameter idiom
  Type & set__quotient(
    const int64_t & _arg)
  {
    this->quotient = _arg;
    return *this;
  }
  Type & set__remainder(
    const int64_t & _arg)
  {
    this->remainder = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    division_interface::srv::Robot_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const division_interface::srv::Robot_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<division_interface::srv::Robot_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<division_interface::srv::Robot_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      division_interface::srv::Robot_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<division_interface::srv::Robot_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      division_interface::srv::Robot_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<division_interface::srv::Robot_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<division_interface::srv::Robot_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<division_interface::srv::Robot_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__division_interface__srv__Robot_Response
    std::shared_ptr<division_interface::srv::Robot_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__division_interface__srv__Robot_Response
    std::shared_ptr<division_interface::srv::Robot_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Robot_Response_ & other) const
  {
    if (this->quotient != other.quotient) {
      return false;
    }
    if (this->remainder != other.remainder) {
      return false;
    }
    return true;
  }
  bool operator!=(const Robot_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Robot_Response_

// alias to use template instance with default allocator
using Robot_Response =
  division_interface::srv::Robot_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace division_interface

namespace division_interface
{

namespace srv
{

struct Robot
{
  using Request = division_interface::srv::Robot_Request;
  using Response = division_interface::srv::Robot_Response;
};

}  // namespace srv

}  // namespace division_interface

#endif  // DIVISION_INTERFACE__SRV__DETAIL__ROBOT__STRUCT_HPP_
