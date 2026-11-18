//
// Created by lesco on 18.11.2026.
//

#include "functions.h"

void push(std::array<int, max_size>& arr, size_t& current_length, int new_value) {
    arr[current_length] = new_value;
    current_length++;
}

void pop(std::array<int, max_size>& arr, size_t& current_length) {
    current_length--;
    arr[current_length] = 0;
}

void clear(std::array<int, max_size>& arr, size_t& current_length) {
    current_length = 0;
    for (int& i : arr) {
        i = 0;
    }
}
