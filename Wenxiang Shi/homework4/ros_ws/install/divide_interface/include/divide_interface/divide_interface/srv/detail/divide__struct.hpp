// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from divide_interface:srv/Divide.idl
// generated code does not contain a copyright notice

#ifndef DIVIDE_INTERFACE__SRV__DETAIL__DIVIDE__STRUCT_HPP_
#define DIVIDE_INTERFACE__SRV__DETAIL__DIVIDE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__divide_interface__srv__Divide_Request __attribute__((deprecated))
#else
# define DEPRECATED__divide_interface__srv__Divide_Request __declspec(deprecated)
#endif

namespace divide_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Divide_Request_
{
  using Type = Divide_Request_<ContainerAllocator>;

  explicit Divide_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dividend = 0l;
      this->divisor = 0l;
    }
  }

  explicit Divide_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dividend = 0l;
      this->divisor = 0l;
    }
  }

  // field types and members
  using _dividend_type =
    int32_t;
  _dividend_type dividend;
  using _divisor_type =
    int32_t;
  _divisor_type divisor;

  // setters for named parameter idiom
  Type & set__dividend(
    const int32_t & _arg)
  {
    this->dividend = _arg;
    return *this;
  }
  Type & set__divisor(
    const int32_t & _arg)
  {
    this->divisor = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    divide_interface::srv::Divide_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const divide_interface::srv::Divide_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<divide_interface::srv::Divide_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<divide_interface::srv::Divide_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      divide_interface::srv::Divide_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<divide_interface::srv::Divide_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      divide_interface::srv::Divide_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<divide_interface::srv::Divide_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<divide_interface::srv::Divide_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<divide_interface::srv::Divide_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__divide_interface__srv__Divide_Request
    std::shared_ptr<divide_interface::srv::Divide_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__divide_interface__srv__Divide_Request
    std::shared_ptr<divide_interface::srv::Divide_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Divide_Request_ & other) const
  {
    if (this->dividend != other.dividend) {
      return false;
    }
    if (this->divisor != other.divisor) {
      return false;
    }
    return true;
  }
  bool operator!=(const Divide_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Divide_Request_

// alias to use template instance with default allocator
using Divide_Request =
  divide_interface::srv::Divide_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace divide_interface


#ifndef _WIN32
# define DEPRECATED__divide_interface__srv__Divide_Response __attribute__((deprecated))
#else
# define DEPRECATED__divide_interface__srv__Divide_Response __declspec(deprecated)
#endif

namespace divide_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Divide_Response_
{
  using Type = Divide_Response_<ContainerAllocator>;

  explicit Divide_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->quotient = 0l;
      this->remainder = 0l;
    }
  }

  explicit Divide_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->quotient = 0l;
      this->remainder = 0l;
    }
  }

  // field types and members
  using _quotient_type =
    int32_t;
  _quotient_type quotient;
  using _remainder_type =
    int32_t;
  _remainder_type remainder;

  // setters for named parameter idiom
  Type & set__quotient(
    const int32_t & _arg)
  {
    this->quotient = _arg;
    return *this;
  }
  Type & set__remainder(
    const int32_t & _arg)
  {
    this->remainder = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    divide_interface::srv::Divide_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const divide_interface::srv::Divide_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<divide_interface::srv::Divide_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<divide_interface::srv::Divide_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      divide_interface::srv::Divide_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<divide_interface::srv::Divide_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      divide_interface::srv::Divide_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<divide_interface::srv::Divide_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<divide_interface::srv::Divide_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<divide_interface::srv::Divide_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__divide_interface__srv__Divide_Response
    std::shared_ptr<divide_interface::srv::Divide_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__divide_interface__srv__Divide_Response
    std::shared_ptr<divide_interface::srv::Divide_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Divide_Response_ & other) const
  {
    if (this->quotient != other.quotient) {
      return false;
    }
    if (this->remainder != other.remainder) {
      return false;
    }
    return true;
  }
  bool operator!=(const Divide_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Divide_Response_

// alias to use template instance with default allocator
using Divide_Response =
  divide_interface::srv::Divide_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace divide_interface

namespace divide_interface
{

namespace srv
{

struct Divide
{
  using Request = divide_interface::srv::Divide_Request;
  using Response = divide_interface::srv::Divide_Response;
};

}  // namespace srv

}  // namespace divide_interface

#endif  // DIVIDE_INTERFACE__SRV__DETAIL__DIVIDE__STRUCT_HPP_
