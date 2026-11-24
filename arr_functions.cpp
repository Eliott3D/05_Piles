//
// Created by lesco on 18.11.2026.
//

#include "arr_functions.h"
# include <array>
# include <stdexcept>

using namespace std;

void push(array<int, max_size>& arr, size_t& current_length, int new_value) {
    if (current_length >= max_size) {
        throw overflow_error("impossible d'empiler dans une pile pleine.");
    }
    arr.at(current_length) = new_value;
    current_length++;
}

void pop(size_t& current_length) {
    if (current_length == 0) {
        throw underflow_error("impossible de dépiler une pile vide.");
    }
    current_length--;
}

int& top(array<int, max_size>& arr, size_t& current_length)
{
    if (current_length == 0)
    {
        throw underflow_error ("impossible de consulter le sommet d'une pile vide.");
    }

    return arr.at(current_length-1);
}

void top(array<int, max_size>& arr, size_t& current_length, int new_value)
{
    if (current_length == 0)
    {
        throw underflow_error ("impossible de remplacer le sommet d'une pile vide.");
    }

    arr.at(current_length - 1) = new_value;
}

bool empty(size_t& current_length)
{
    return current_length == 0;
}

size_t size(size_t& current_length)
{
    return current_length;
}

void clear(size_t& current_length) {
    current_length = 0;
}