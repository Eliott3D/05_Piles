//
// Created by lesco on 18.11.2026.
//
#ifndef INC_05_PILES_ARR_FUNCTIONS_H
#define INC_05_PILES_ARR_FUNCTIONS_H
#include <array>


static const std::size_t max_size = 5;

/// Add a value on top of an array
/// @param arr Array to add the value to
/// @param current_length Current length of the array to modify
/// @param new_value Value to add
void push(std::array<int, max_size>& arr, std::size_t& current_length, int new_value);

/// Remove last value from an array
/// @param current_length Current length of the array to which a value is removed
void pop(std::size_t& current_length);

/// Get value on top of an array
/// @param arr Array to get the value from
/// @param current_length Current length of the array to get the value from
/// @return Value on top of the array
int top(const std::array<int, max_size>& arr, std::size_t& current_length);

/// Modify value on top of an array
/// @param arr Array to get the value from
/// @param current_length Current length of the array to get the value from
/// @param new_value Value that will replace the value
/// @return Adress of the top value
int& top(std::array<int, max_size>& arr, std::size_t& current_length);

/// Say if an array is empty
/// @param current_length Current length of the array
/// @return true for an array without value
bool empty(std::size_t& current_length);

/// Get the number of elements in an array
/// @param current_length Length of the array
/// @return Size of the array
std::size_t size(std::size_t& current_length);

/// Remove all elements of an array
/// @param current_length Current length of an array
void clear(std::size_t& current_length);

#endif //INC_05_PILES_ARR_FUNCTIONS_H
