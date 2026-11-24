//
// Created by m01 on 24/11/2026.
//

#include "display.h"
#include <iostream>
#include <iomanip>

using namespace std;

/// Display an array in a readable format
/// @param arr Array to display
/// @param current_size Current size of the array to display
void display_stack(const array<int,max_size>& arr, const size_t& current_size)
{
    const int label_width = 7;
    const int arrow_width = 3;
    const int prefix_width = label_width + arrow_width;
    const int value_width = 11;

    if (current_size == 0) {
        cout << "La pile est vide." << endl;
        return;
    }

    if (current_size == 1) {
        cout << "Sommet / Fond -> " << arr.at(0) << endl;
        return;
    }

    cout << left << setw(label_width) << "Sommet" << "-> " << right << setw(value_width) << arr.at(current_size - 1) << endl;
    for (size_t i = current_size - 2; i > 0; --i) {
        cout << setw(prefix_width + value_width) << arr.at(i) << endl;
    }
    cout << left << setw(label_width) << "Fond" << "-> " << right << setw(value_width) << arr.at(0) << endl;
}