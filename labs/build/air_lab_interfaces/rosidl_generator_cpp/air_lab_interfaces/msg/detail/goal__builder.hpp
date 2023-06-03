// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from air_lab_interfaces:msg/Goal.idl
// generated code does not contain a copyright notice

#ifndef AIR_LAB_INTERFACES__MSG__DETAIL__GOAL__BUILDER_HPP_
#define AIR_LAB_INTERFACES__MSG__DETAIL__GOAL__BUILDER_HPP_

#include "air_lab_interfaces/msg/detail/goal__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace air_lab_interfaces
{

namespace msg
{

namespace builder
{

class Init_Goal_destination
{
public:
  explicit Init_Goal_destination(::air_lab_interfaces::msg::Goal & msg)
  : msg_(msg)
  {}
  ::air_lab_interfaces::msg::Goal destination(::air_lab_interfaces::msg::Goal::_destination_type arg)
  {
    msg_.destination = std::move(arg);
    return std::move(msg_);
  }

private:
  ::air_lab_interfaces::msg::Goal msg_;
};

class Init_Goal_object
{
public:
  explicit Init_Goal_object(::air_lab_interfaces::msg::Goal & msg)
  : msg_(msg)
  {}
  Init_Goal_destination object(::air_lab_interfaces::msg::Goal::_object_type arg)
  {
    msg_.object = std::move(arg);
    return Init_Goal_destination(msg_);
  }

private:
  ::air_lab_interfaces::msg::Goal msg_;
};

class Init_Goal_type
{
public:
  Init_Goal_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Goal_object type(::air_lab_interfaces::msg::Goal::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_Goal_object(msg_);
  }

private:
  ::air_lab_interfaces::msg::Goal msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::air_lab_interfaces::msg::Goal>()
{
  return air_lab_interfaces::msg::builder::Init_Goal_type();
}

}  // namespace air_lab_interfaces

#endif  // AIR_LAB_INTERFACES__MSG__DETAIL__GOAL__BUILDER_HPP_
