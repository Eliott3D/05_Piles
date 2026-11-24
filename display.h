//
// Created by m01 on 24/11/2026.
//

#ifndef INC_05_PILES_DISPLAY_H
#define INC_05_PILES_DISPLAY_H
#include <array>
#include <cstddef>
#include "stack.h"

/// Display the principal menu
void display_menu();

/// Display the stack from top to bottom
/// @param arr Array to display
/// @param current_size Current size of the array to display
void display_stack(const std::array<int,max_size>& arr, std::size_t current_size);



#endif //INC_05_PILES_DISPLAY_H
