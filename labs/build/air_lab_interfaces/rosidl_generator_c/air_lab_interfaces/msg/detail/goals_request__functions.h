// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from air_lab_interfaces:msg/GoalsRequest.idl
// generated code does not contain a copyright notice

#ifndef AIR_LAB_INTERFACES__MSG__DETAIL__GOALS_REQUEST__FUNCTIONS_H_
#define AIR_LAB_INTERFACES__MSG__DETAIL__GOALS_REQUEST__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "air_lab_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "air_lab_interfaces/msg/detail/goals_request__struct.h"

/// Initialize msg/GoalsRequest message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * air_lab_interfaces__msg__GoalsRequest
 * )) before or use
 * air_lab_interfaces__msg__GoalsRequest__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_air_lab_interfaces
bool
air_lab_interfaces__msg__GoalsRequest__init(air_lab_interfaces__msg__GoalsRequest * msg);

/// Finalize msg/GoalsRequest message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_air_lab_interfaces
void
air_lab_interfaces__msg__GoalsRequest__fini(air_lab_interfaces__msg__GoalsRequest * msg);

/// Create msg/GoalsRequest message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * air_lab_interfaces__msg__GoalsRequest__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_air_lab_interfaces
air_lab_interfaces__msg__GoalsRequest *
air_lab_interfaces__msg__GoalsRequest__create();

/// Destroy msg/GoalsRequest message.
/**
 * It calls
 * air_lab_interfaces__msg__GoalsRequest__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_air_lab_interfaces
void
air_lab_interfaces__msg__GoalsRequest__destroy(air_lab_interfaces__msg__GoalsRequest * msg);

/// Check for msg/GoalsRequest message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_air_lab_interfaces
bool
air_lab_interfaces__msg__GoalsRequest__are_equal(const air_lab_interfaces__msg__GoalsRequest * lhs, const air_lab_interfaces__msg__GoalsRequest * rhs);

/// Copy a msg/GoalsRequest message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_air_lab_interfaces
bool
air_lab_interfaces__msg__GoalsRequest__copy(
  const air_lab_interfaces__msg__GoalsRequest * input,
  air_lab_interfaces__msg__GoalsRequest * output);

/// Initialize array of msg/GoalsRequest messages.
/**
 * It allocates the memory for the number of elements and calls
 * air_lab_interfaces__msg__GoalsRequest__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_air_lab_interfaces
bool
air_lab_interfaces__msg__GoalsRequest__Sequence__init(air_lab_interfaces__msg__GoalsRequest__Sequence * array, size_t size);

/// Finalize array of msg/GoalsRequest messages.
/**
 * It calls
 * air_lab_interfaces__msg__GoalsRequest__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_air_lab_interfaces
void
air_lab_interfaces__msg__GoalsRequest__Sequence__fini(air_lab_interfaces__msg__GoalsRequest__Sequence * array);

/// Create array of msg/GoalsRequest messages.
/**
 * It allocates the memory for the array and calls
 * air_lab_interfaces__msg__GoalsRequest__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_air_lab_interfaces
air_lab_interfaces__msg__GoalsRequest__Sequence *
air_lab_interfaces__msg__GoalsRequest__Sequence__create(size_t size);

/// Destroy array of msg/GoalsRequest messages.
/**
 * It calls
 * air_lab_interfaces__msg__GoalsRequest__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_air_lab_interfaces
void
air_lab_interfaces__msg__GoalsRequest__Sequence__destroy(air_lab_interfaces__msg__GoalsRequest__Sequence * array);

/// Check for msg/GoalsRequest message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_air_lab_interfaces
bool
air_lab_interfaces__msg__GoalsRequest__Sequence__are_equal(const air_lab_interfaces__msg__GoalsRequest__Sequence * lhs, const air_lab_interfaces__msg__GoalsRequest__Sequence * rhs);

/// Copy an array of msg/GoalsRequest messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_air_lab_interfaces
bool
air_lab_interfaces__msg__GoalsRequest__Sequence__copy(
  const air_lab_interfaces__msg__GoalsRequest__Sequence * input,
  air_lab_interfaces__msg__GoalsRequest__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // AIR_LAB_INTERFACES__MSG__DETAIL__GOALS_REQUEST__FUNCTIONS_H_
