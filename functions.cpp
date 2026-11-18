//
// Created by lesco on 18.11.2026.
//

#include "functions.h"

#include <stdexcept>

void push(std::array<int, max_size>& arr, size_t& current_length, int new_value) {
    if (current_length + 1 == max_size) {
        throw std::overflow_error("impossible d'empiler dans une pile pleine");
    }
    arr[current_length] = new_value;
    current_length++;
}

void pop(size_t& current_length) {
    if (current_length == 0) {
        throw std::underflow_error("impossible de dépiler une pile vide");
    }
    current_length--;
}

void clear(size_t& current_length) {
    current_length = 0;
}
