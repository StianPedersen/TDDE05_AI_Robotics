// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from air_lab_interfaces:srv/ExecuteTst.idl
// generated code does not contain a copyright notice

#ifndef AIR_LAB_INTERFACES__SRV__DETAIL__EXECUTE_TST__STRUCT_HPP_
#define AIR_LAB_INTERFACES__SRV__DETAIL__EXECUTE_TST__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__air_lab_interfaces__srv__ExecuteTst_Request __attribute__((deprecated))
#else
# define DEPRECATED__air_lab_interfaces__srv__ExecuteTst_Request __declspec(deprecated)
#endif

namespace air_lab_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ExecuteTst_Request_
{
  using Type = ExecuteTst_Request_<ContainerAllocator>;

  explicit ExecuteTst_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tst_file = "";
    }
  }

  explicit ExecuteTst_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : tst_file(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tst_file = "";
    }
  }

  // field types and members
  using _tst_file_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _tst_file_type tst_file;

  // setters for named parameter idiom
  Type & set__tst_file(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->tst_file = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    air_lab_interfaces::srv::ExecuteTst_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const air_lab_interfaces::srv::ExecuteTst_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<air_lab_interfaces::srv::ExecuteTst_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<air_lab_interfaces::srv::ExecuteTst_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      air_lab_interfaces::srv::ExecuteTst_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<air_lab_interfaces::srv::ExecuteTst_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      air_lab_interfaces::srv::ExecuteTst_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<air_lab_interfaces::srv::ExecuteTst_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<air_lab_interfaces::srv::ExecuteTst_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<air_lab_interfaces::srv::ExecuteTst_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__air_lab_interfaces__srv__ExecuteTst_Request
    std::shared_ptr<air_lab_interfaces::srv::ExecuteTst_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__air_lab_interfaces__srv__ExecuteTst_Request
    std::shared_ptr<air_lab_interfaces::srv::ExecuteTst_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExecuteTst_Request_ & other) const
  {
    if (this->tst_file != other.tst_file) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExecuteTst_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExecuteTst_Request_

// alias to use template instance with default allocator
using ExecuteTst_Request =
  air_lab_interfaces::srv::ExecuteTst_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace air_lab_interfaces


#ifndef _WIN32
# define DEPRECATED__air_lab_interfaces__srv__ExecuteTst_Response __attribute__((deprecated))
#else
# define DEPRECATED__air_lab_interfaces__srv__ExecuteTst_Response __declspec(deprecated)
#endif

namespace air_lab_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ExecuteTst_Response_
{
  using Type = ExecuteTst_Response_<ContainerAllocator>;

  explicit ExecuteTst_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->my_error = "";
    }
  }

  explicit ExecuteTst_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : my_error(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->my_error = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _my_error_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _my_error_type my_error;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__my_error(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->my_error = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    air_lab_interfaces::srv::ExecuteTst_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const air_lab_interfaces::srv::ExecuteTst_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<air_lab_interfaces::srv::ExecuteTst_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<air_lab_interfaces::srv::ExecuteTst_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      air_lab_interfaces::srv::ExecuteTst_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<air_lab_interfaces::srv::ExecuteTst_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      air_lab_interfaces::srv::ExecuteTst_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<air_lab_interfaces::srv::ExecuteTst_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<air_lab_interfaces::srv::ExecuteTst_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<air_lab_interfaces::srv::ExecuteTst_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__air_lab_interfaces__srv__ExecuteTst_Response
    std::shared_ptr<air_lab_interfaces::srv::ExecuteTst_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__air_lab_interfaces__srv__ExecuteTst_Response
    std::shared_ptr<air_lab_interfaces::srv::ExecuteTst_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExecuteTst_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->my_error != other.my_error) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExecuteTst_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExecuteTst_Response_

// alias to use template instance with default allocator
using ExecuteTst_Response =
  air_lab_interfaces::srv::ExecuteTst_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace air_lab_interfaces

namespace air_lab_interfaces
{

namespace srv
{

struct ExecuteTst
{
  using Request = air_lab_interfaces::srv::ExecuteTst_Request;
  using Response = air_lab_interfaces::srv::ExecuteTst_Response;
};

}  // namespace srv

}  // namespace air_lab_interfaces

#endif  // AIR_LAB_INTERFACES__SRV__DETAIL__EXECUTE_TST__STRUCT_HPP_
