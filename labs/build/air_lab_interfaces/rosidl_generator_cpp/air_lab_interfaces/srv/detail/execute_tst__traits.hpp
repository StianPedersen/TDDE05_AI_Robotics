// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from air_lab_interfaces:srv/ExecuteTst.idl
// generated code does not contain a copyright notice

#ifndef AIR_LAB_INTERFACES__SRV__DETAIL__EXECUTE_TST__TRAITS_HPP_
#define AIR_LAB_INTERFACES__SRV__DETAIL__EXECUTE_TST__TRAITS_HPP_

#include "air_lab_interfaces/srv/detail/execute_tst__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const air_lab_interfaces::srv::ExecuteTst_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: tst_file
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tst_file: ";
    value_to_yaml(msg.tst_file, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const air_lab_interfaces::srv::ExecuteTst_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<air_lab_interfaces::srv::ExecuteTst_Request>()
{
  return "air_lab_interfaces::srv::ExecuteTst_Request";
}

template<>
inline const char * name<air_lab_interfaces::srv::ExecuteTst_Request>()
{
  return "air_lab_interfaces/srv/ExecuteTst_Request";
}

template<>
struct has_fixed_size<air_lab_interfaces::srv::ExecuteTst_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<air_lab_interfaces::srv::ExecuteTst_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<air_lab_interfaces::srv::ExecuteTst_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

inline void to_yaml(
  const air_lab_interfaces::srv::ExecuteTst_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: my_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "my_error: ";
    value_to_yaml(msg.my_error, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const air_lab_interfaces::srv::ExecuteTst_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<air_lab_interfaces::srv::ExecuteTst_Response>()
{
  return "air_lab_interfaces::srv::ExecuteTst_Response";
}

template<>
inline const char * name<air_lab_interfaces::srv::ExecuteTst_Response>()
{
  return "air_lab_interfaces/srv/ExecuteTst_Response";
}

template<>
struct has_fixed_size<air_lab_interfaces::srv::ExecuteTst_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<air_lab_interfaces::srv::ExecuteTst_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<air_lab_interfaces::srv::ExecuteTst_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<air_lab_interfaces::srv::ExecuteTst>()
{
  return "air_lab_interfaces::srv::ExecuteTst";
}

template<>
inline const char * name<air_lab_interfaces::srv::ExecuteTst>()
{
  return "air_lab_interfaces/srv/ExecuteTst";
}

template<>
struct has_fixed_size<air_lab_interfaces::srv::ExecuteTst>
  : std::integral_constant<
    bool,
    has_fixed_size<air_lab_interfaces::srv::ExecuteTst_Request>::value &&
    has_fixed_size<air_lab_interfaces::srv::ExecuteTst_Response>::value
  >
{
};

template<>
struct has_bounded_size<air_lab_interfaces::srv::ExecuteTst>
  : std::integral_constant<
    bool,
    has_bounded_size<air_lab_interfaces::srv::ExecuteTst_Request>::value &&
    has_bounded_size<air_lab_interfaces::srv::ExecuteTst_Response>::value
  >
{
};

template<>
struct is_service<air_lab_interfaces::srv::ExecuteTst>
  : std::true_type
{
};

template<>
struct is_service_request<air_lab_interfaces::srv::ExecuteTst_Request>
  : std::true_type
{
};

template<>
struct is_service_response<air_lab_interfaces::srv::ExecuteTst_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // AIR_LAB_INTERFACES__SRV__DETAIL__EXECUTE_TST__TRAITS_HPP_
