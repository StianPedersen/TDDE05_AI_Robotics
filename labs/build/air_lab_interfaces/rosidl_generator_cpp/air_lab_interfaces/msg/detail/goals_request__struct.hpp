// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from air_lab_interfaces:msg/GoalsRequest.idl
// generated code does not contain a copyright notice

#ifndef AIR_LAB_INTERFACES__MSG__DETAIL__GOALS_REQUEST__STRUCT_HPP_
#define AIR_LAB_INTERFACES__MSG__DETAIL__GOALS_REQUEST__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'goals'
#include "air_lab_interfaces/msg/detail/goal__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__air_lab_interfaces__msg__GoalsRequest __attribute__((deprecated))
#else
# define DEPRECATED__air_lab_interfaces__msg__GoalsRequest __declspec(deprecated)
#endif

namespace air_lab_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GoalsRequest_
{
  using Type = GoalsRequest_<ContainerAllocator>;

  explicit GoalsRequest_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit GoalsRequest_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _goals_type =
    std::vector<air_lab_interfaces::msg::Goal_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<air_lab_interfaces::msg::Goal_<ContainerAllocator>>>;
  _goals_type goals;

  // setters for named parameter idiom
  Type & set__goals(
    const std::vector<air_lab_interfaces::msg::Goal_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<air_lab_interfaces::msg::Goal_<ContainerAllocator>>> & _arg)
  {
    this->goals = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    air_lab_interfaces::msg::GoalsRequest_<ContainerAllocator> *;
  using ConstRawPtr =
    const air_lab_interfaces::msg::GoalsRequest_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<air_lab_interfaces::msg::GoalsRequest_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<air_lab_interfaces::msg::GoalsRequest_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      air_lab_interfaces::msg::GoalsRequest_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<air_lab_interfaces::msg::GoalsRequest_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      air_lab_interfaces::msg::GoalsRequest_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<air_lab_interfaces::msg::GoalsRequest_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<air_lab_interfaces::msg::GoalsRequest_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<air_lab_interfaces::msg::GoalsRequest_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__air_lab_interfaces__msg__GoalsRequest
    std::shared_ptr<air_lab_interfaces::msg::GoalsRequest_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__air_lab_interfaces__msg__GoalsRequest
    std::shared_ptr<air_lab_interfaces::msg::GoalsRequest_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GoalsRequest_ & other) const
  {
    if (this->goals != other.goals) {
      return false;
    }
    return true;
  }
  bool operator!=(const GoalsRequest_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GoalsRequest_

// alias to use template instance with default allocator
using GoalsRequest =
  air_lab_interfaces::msg::GoalsRequest_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace air_lab_interfaces

#endif  // AIR_LAB_INTERFACES__MSG__DETAIL__GOALS_REQUEST__STRUCT_HPP_
