// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from air_lab_interfaces:msg/GoalsRequest.idl
// generated code does not contain a copyright notice

#ifndef AIR_LAB_INTERFACES__MSG__DETAIL__GOALS_REQUEST__TRAITS_HPP_
#define AIR_LAB_INTERFACES__MSG__DETAIL__GOALS_REQUEST__TRAITS_HPP_

#include "air_lab_interfaces/msg/detail/goals_request__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'goals'
#include "air_lab_interfaces/msg/detail/goal__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const air_lab_interfaces::msg::GoalsRequest & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goals
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.goals.size() == 0) {
      out << "goals: []\n";
    } else {
      out << "goals:\n";
      for (auto item : msg.goals) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const air_lab_interfaces::msg::GoalsRequest & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<air_lab_interfaces::msg::GoalsRequest>()
{
  return "air_lab_interfaces::msg::GoalsRequest";
}

template<>
inline const char * name<air_lab_interfaces::msg::GoalsRequest>()
{
  return "air_lab_interfaces/msg/GoalsRequest";
}

template<>
struct has_fixed_size<air_lab_interfaces::msg::GoalsRequest>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<air_lab_interfaces::msg::GoalsRequest>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<air_lab_interfaces::msg::GoalsRequest>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AIR_LAB_INTERFACES__MSG__DETAIL__GOALS_REQUEST__TRAITS_HPP_
