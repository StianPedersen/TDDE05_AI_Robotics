// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from air_lab_interfaces:msg/Goal.idl
// generated code does not contain a copyright notice

#ifndef AIR_LAB_INTERFACES__MSG__DETAIL__GOAL__STRUCT_HPP_
#define AIR_LAB_INTERFACES__MSG__DETAIL__GOAL__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__air_lab_interfaces__msg__Goal __attribute__((deprecated))
#else
# define DEPRECATED__air_lab_interfaces__msg__Goal __declspec(deprecated)
#endif

namespace air_lab_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Goal_
{
  using Type = Goal_<ContainerAllocator>;

  explicit Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = "";
      this->object = "";
      this->destination = "";
    }
  }

  explicit Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : type(_alloc),
    object(_alloc),
    destination(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = "";
      this->object = "";
      this->destination = "";
    }
  }

  // field types and members
  using _type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _type_type type;
  using _object_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _object_type object;
  using _destination_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _destination_type destination;

  // setters for named parameter idiom
  Type & set__type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__object(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->object = _arg;
    return *this;
  }
  Type & set__destination(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->destination = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    air_lab_interfaces::msg::Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const air_lab_interfaces::msg::Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<air_lab_interfaces::msg::Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<air_lab_interfaces::msg::Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      air_lab_interfaces::msg::Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<air_lab_interfaces::msg::Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      air_lab_interfaces::msg::Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<air_lab_interfaces::msg::Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<air_lab_interfaces::msg::Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<air_lab_interfaces::msg::Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__air_lab_interfaces__msg__Goal
    std::shared_ptr<air_lab_interfaces::msg::Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__air_lab_interfaces__msg__Goal
    std::shared_ptr<air_lab_interfaces::msg::Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Goal_ & other) const
  {
    if (this->type != other.type) {
      return false;
    }
    if (this->object != other.object) {
      return false;
    }
    if (this->destination != other.destination) {
      return false;
    }
    return true;
  }
  bool operator!=(const Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Goal_

// alias to use template instance with default allocator
using Goal =
  air_lab_interfaces::msg::Goal_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace air_lab_interfaces

#endif  // AIR_LAB_INTERFACES__MSG__DETAIL__GOAL__STRUCT_HPP_
