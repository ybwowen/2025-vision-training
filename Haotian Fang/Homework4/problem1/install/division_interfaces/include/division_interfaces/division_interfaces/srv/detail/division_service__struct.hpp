// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from division_interfaces:srv/DivisionService.idl
// generated code does not contain a copyright notice

#ifndef DIVISION_INTERFACES__SRV__DETAIL__DIVISION_SERVICE__STRUCT_HPP_
#define DIVISION_INTERFACES__SRV__DETAIL__DIVISION_SERVICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__division_interfaces__srv__DivisionService_Request __attribute__((deprecated))
#else
# define DEPRECATED__division_interfaces__srv__DivisionService_Request __declspec(deprecated)
#endif

namespace division_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DivisionService_Request_
{
  using Type = DivisionService_Request_<ContainerAllocator>;

  explicit DivisionService_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dividend = 0ll;
      this->divisor = 0ll;
    }
  }

  explicit DivisionService_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dividend = 0ll;
      this->divisor = 0ll;
    }
  }

  // field types and members
  using _dividend_type =
    int64_t;
  _dividend_type dividend;
  using _divisor_type =
    int64_t;
  _divisor_type divisor;

  // setters for named parameter idiom
  Type & set__dividend(
    const int64_t & _arg)
  {
    this->dividend = _arg;
    return *this;
  }
  Type & set__divisor(
    const int64_t & _arg)
  {
    this->divisor = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    division_interfaces::srv::DivisionService_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const division_interfaces::srv::DivisionService_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<division_interfaces::srv::DivisionService_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<division_interfaces::srv::DivisionService_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      division_interfaces::srv::DivisionService_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<division_interfaces::srv::DivisionService_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      division_interfaces::srv::DivisionService_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<division_interfaces::srv::DivisionService_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<division_interfaces::srv::DivisionService_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<division_interfaces::srv::DivisionService_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__division_interfaces__srv__DivisionService_Request
    std::shared_ptr<division_interfaces::srv::DivisionService_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__division_interfaces__srv__DivisionService_Request
    std::shared_ptr<division_interfaces::srv::DivisionService_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DivisionService_Request_ & other) const
  {
    if (this->dividend != other.dividend) {
      return false;
    }
    if (this->divisor != other.divisor) {
      return false;
    }
    return true;
  }
  bool operator!=(const DivisionService_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DivisionService_Request_

// alias to use template instance with default allocator
using DivisionService_Request =
  division_interfaces::srv::DivisionService_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace division_interfaces


#ifndef _WIN32
# define DEPRECATED__division_interfaces__srv__DivisionService_Response __attribute__((deprecated))
#else
# define DEPRECATED__division_interfaces__srv__DivisionService_Response __declspec(deprecated)
#endif

namespace division_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DivisionService_Response_
{
  using Type = DivisionService_Response_<ContainerAllocator>;

  explicit DivisionService_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->quotient = 0ll;
      this->remainder = 0ll;
    }
  }

  explicit DivisionService_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    division_interfaces::srv::DivisionService_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const division_interfaces::srv::DivisionService_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<division_interfaces::srv::DivisionService_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<division_interfaces::srv::DivisionService_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      division_interfaces::srv::DivisionService_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<division_interfaces::srv::DivisionService_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      division_interfaces::srv::DivisionService_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<division_interfaces::srv::DivisionService_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<division_interfaces::srv::DivisionService_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<division_interfaces::srv::DivisionService_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__division_interfaces__srv__DivisionService_Response
    std::shared_ptr<division_interfaces::srv::DivisionService_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__division_interfaces__srv__DivisionService_Response
    std::shared_ptr<division_interfaces::srv::DivisionService_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DivisionService_Response_ & other) const
  {
    if (this->quotient != other.quotient) {
      return false;
    }
    if (this->remainder != other.remainder) {
      return false;
    }
    return true;
  }
  bool operator!=(const DivisionService_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DivisionService_Response_

// alias to use template instance with default allocator
using DivisionService_Response =
  division_interfaces::srv::DivisionService_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace division_interfaces

namespace division_interfaces
{

namespace srv
{

struct DivisionService
{
  using Request = division_interfaces::srv::DivisionService_Request;
  using Response = division_interfaces::srv::DivisionService_Response;
};

}  // namespace srv

}  // namespace division_interfaces

#endif  // DIVISION_INTERFACES__SRV__DETAIL__DIVISION_SERVICE__STRUCT_HPP_
