// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:srv/ModulusDivision.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__MODULUS_DIVISION__STRUCT_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__MODULUS_DIVISION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__srv__ModulusDivision_Request __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__srv__ModulusDivision_Request __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ModulusDivision_Request_
{
  using Type = ModulusDivision_Request_<ContainerAllocator>;

  explicit ModulusDivision_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dividend = 0ll;
      this->divisor = 0ll;
    }
  }

  explicit ModulusDivision_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    custom_interfaces::srv::ModulusDivision_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::srv::ModulusDivision_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::srv::ModulusDivision_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::srv::ModulusDivision_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::ModulusDivision_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::ModulusDivision_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::ModulusDivision_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::ModulusDivision_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::srv::ModulusDivision_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::srv::ModulusDivision_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__srv__ModulusDivision_Request
    std::shared_ptr<custom_interfaces::srv::ModulusDivision_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__srv__ModulusDivision_Request
    std::shared_ptr<custom_interfaces::srv::ModulusDivision_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ModulusDivision_Request_ & other) const
  {
    if (this->dividend != other.dividend) {
      return false;
    }
    if (this->divisor != other.divisor) {
      return false;
    }
    return true;
  }
  bool operator!=(const ModulusDivision_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ModulusDivision_Request_

// alias to use template instance with default allocator
using ModulusDivision_Request =
  custom_interfaces::srv::ModulusDivision_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_interfaces


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__srv__ModulusDivision_Response __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__srv__ModulusDivision_Response __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ModulusDivision_Response_
{
  using Type = ModulusDivision_Response_<ContainerAllocator>;

  explicit ModulusDivision_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->quotient = 0ll;
      this->remainder = 0ll;
    }
  }

  explicit ModulusDivision_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    custom_interfaces::srv::ModulusDivision_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::srv::ModulusDivision_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::srv::ModulusDivision_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::srv::ModulusDivision_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::ModulusDivision_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::ModulusDivision_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::ModulusDivision_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::ModulusDivision_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::srv::ModulusDivision_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::srv::ModulusDivision_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__srv__ModulusDivision_Response
    std::shared_ptr<custom_interfaces::srv::ModulusDivision_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__srv__ModulusDivision_Response
    std::shared_ptr<custom_interfaces::srv::ModulusDivision_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ModulusDivision_Response_ & other) const
  {
    if (this->quotient != other.quotient) {
      return false;
    }
    if (this->remainder != other.remainder) {
      return false;
    }
    return true;
  }
  bool operator!=(const ModulusDivision_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ModulusDivision_Response_

// alias to use template instance with default allocator
using ModulusDivision_Response =
  custom_interfaces::srv::ModulusDivision_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_interfaces

namespace custom_interfaces
{

namespace srv
{

struct ModulusDivision
{
  using Request = custom_interfaces::srv::ModulusDivision_Request;
  using Response = custom_interfaces::srv::ModulusDivision_Response;
};

}  // namespace srv

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__MODULUS_DIVISION__STRUCT_HPP_
