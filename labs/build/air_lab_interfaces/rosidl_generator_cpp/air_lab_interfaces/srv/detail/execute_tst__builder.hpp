// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from air_lab_interfaces:srv/ExecuteTst.idl
// generated code does not contain a copyright notice

#ifndef AIR_LAB_INTERFACES__SRV__DETAIL__EXECUTE_TST__BUILDER_HPP_
#define AIR_LAB_INTERFACES__SRV__DETAIL__EXECUTE_TST__BUILDER_HPP_

#include "air_lab_interfaces/srv/detail/execute_tst__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace air_lab_interfaces
{

namespace srv
{

namespace builder
{

class Init_ExecuteTst_Request_tst_file
{
public:
  Init_ExecuteTst_Request_tst_file()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::air_lab_interfaces::srv::ExecuteTst_Request tst_file(::air_lab_interfaces::srv::ExecuteTst_Request::_tst_file_type arg)
  {
    msg_.tst_file = std::move(arg);
    return std::move(msg_);
  }

private:
  ::air_lab_interfaces::srv::ExecuteTst_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::air_lab_interfaces::srv::ExecuteTst_Request>()
{
  return air_lab_interfaces::srv::builder::Init_ExecuteTst_Request_tst_file();
}

}  // namespace air_lab_interfaces


namespace air_lab_interfaces
{

namespace srv
{

namespace builder
{

class Init_ExecuteTst_Response_my_error
{
public:
  explicit Init_ExecuteTst_Response_my_error(::air_lab_interfaces::srv::ExecuteTst_Response & msg)
  : msg_(msg)
  {}
  ::air_lab_interfaces::srv::ExecuteTst_Response my_error(::air_lab_interfaces::srv::ExecuteTst_Response::_my_error_type arg)
  {
    msg_.my_error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::air_lab_interfaces::srv::ExecuteTst_Response msg_;
};

class Init_ExecuteTst_Response_success
{
public:
  Init_ExecuteTst_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteTst_Response_my_error success(::air_lab_interfaces::srv::ExecuteTst_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ExecuteTst_Response_my_error(msg_);
  }

private:
  ::air_lab_interfaces::srv::ExecuteTst_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::air_lab_interfaces::srv::ExecuteTst_Response>()
{
  return air_lab_interfaces::srv::builder::Init_ExecuteTst_Response_success();
}

}  // namespace air_lab_interfaces

#endif  // AIR_LAB_INTERFACES__SRV__DETAIL__EXECUTE_TST__BUILDER_HPP_
