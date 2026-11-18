//
// Created by lesco on 18.11.2026.
//

#include "functions.h"
# include <array>
# include <stdexcept>

using namespace std;

void push(array<int, max_size>& arr, size_t& current_length, int new_value) {
    if (current_length + 1 == max_size) {
        throw overflow_error("impossible d'empiler dans une pile pleine");
    }
    arr[current_length] = new_value;
    current_length++;
}

void pop(size_t& current_length) {
    if (current_length == 0) {
        throw underflow_error("impossible de dépiler une pile vide");
    }
    current_length--;
}

int& top(array<int, Size>& array, size_t& number)
{
    if (number == 0)
    {
        throw underflow_error ("impossible de consulter le sommet d'une pile vide.");
    }

    return array[number-1];
}

int& top(array<int, Size>& array, size_t& number, int value)
{
    if (number == 0)
    {
        throw underflow_error ("impossible de remplacer le sommet d'une pile vide.");
    }

    return array[number-1] = value;
}

bool empty(size_t& number)
{
    return number == 0;
}

size_t size(size_t& number)
{
    return number;
}

void clear(size_t& current_length) {
    current_length = 0;
}