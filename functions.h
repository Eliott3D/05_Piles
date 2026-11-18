//
// Created by lesco on 18.11.2026.
//

#ifndef INC_05_PILES_FUNCTIONS_H
#define INC_05_PILES_FUNCTIONS_H
# include <array>

using namespace std;
static const size_t Size = 10;


int& top(array<int, Size>&, size_t&);
int& top(array<int, Size>&, size_t&, int);
bool empty(size_t&);
size_t size(size_t&);


#endif //INC_05_PILES_FUNCTIONS_H
