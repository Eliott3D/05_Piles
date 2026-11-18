//
// Created by lesco on 18.11.2026.
//
#ifndef INC_05_PILES_FUNCTIONS_H
#define INC_05_PILES_FUNCTIONS_H

#include <array>
#include <cstddef>

static const size_t max_size = 5;

void push(std::array<int, max_size>& arr, size_t& current_length, int new_value);

void pop(std::array<int, max_size>& arr, size_t& current_length);

void clear(std::array<int, max_size>& arr, size_t& current_length);

#endif //INC_05_PILES_FUNCTIONS_H
