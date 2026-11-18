//
// Created by lesco on 18.11.2026.
//

#include "functions.h"
# include <array>
# include <stdexcept>

using namespace std;

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