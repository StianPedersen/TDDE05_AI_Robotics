// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from air_lab_interfaces:msg/Goal.idl
// generated code does not contain a copyright notice

#ifndef AIR_LAB_INTERFACES__MSG__DETAIL__GOAL__TRAITS_HPP_
#define AIR_LAB_INTERFACES__MSG__DETAIL__GOAL__TRAITS_HPP_

#include "air_lab_interfaces/msg/detail/goal__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const air_lab_interfaces::msg::Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: object
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "object: ";
    value_to_yaml(msg.object, out);
    out << "\n";
  }

  // member: destination
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "destination: ";
    value_to_yaml(msg.destination, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const air_lab_interfaces::msg::Goal & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<air_lab_interfaces::msg::Goal>()
{
  return "air_lab_interfaces::msg::Goal";
}

template<>
inline const char * name<air_lab_interfaces::msg::Goal>()
{
  return "air_lab_interfaces/msg/Goal";
}

template<>
struct has_fixed_size<air_lab_interfaces::msg::Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<air_lab_interfaces::msg::Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<air_lab_interfaces::msg::Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AIR_LAB_INTERFACES__MSG__DETAIL__GOAL__TRAITS_HPP_
