// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from air_lab_interfaces:msg/GoalsRequest.idl
// generated code does not contain a copyright notice

#ifndef AIR_LAB_INTERFACES__MSG__DETAIL__GOALS_REQUEST__BUILDER_HPP_
#define AIR_LAB_INTERFACES__MSG__DETAIL__GOALS_REQUEST__BUILDER_HPP_

#include "air_lab_interfaces/msg/detail/goals_request__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace air_lab_interfaces
{

namespace msg
{

namespace builder
{

class Init_GoalsRequest_goals
{
public:
  Init_GoalsRequest_goals()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::air_lab_interfaces::msg::GoalsRequest goals(::air_lab_interfaces::msg::GoalsRequest::_goals_type arg)
  {
    msg_.goals = std::move(arg);
    return std::move(msg_);
  }

private:
  ::air_lab_interfaces::msg::GoalsRequest msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::air_lab_interfaces::msg::GoalsRequest>()
{
  return air_lab_interfaces::msg::builder::Init_GoalsRequest_goals();
}

}  // namespace air_lab_interfaces

#endif  // AIR_LAB_INTERFACES__MSG__DETAIL__GOALS_REQUEST__BUILDER_HPP_
