//
// Created by m01 on 24/11/2026.
//

#include "display.h"
#include <iostream>
#include <iomanip>


using namespace std;

void display_menu() {
    cout << "1 - Empiler" << endl
         << "2 - Dépiler" << endl
         << "3 - Consulter le sommet" << endl
         << "4 - Modifier l'élément au sommet" << endl
         << "5 - Vérifier si la pile est vide" << endl
         << "6 - Afficher le nombre de valeurs" << endl
         << "7 - Vider la pile" << endl
         << "8 - Afficher toute la pile" << endl
         << "0 - Quitter" << endl << endl;
}

void display_stack(const array<int,max_size>& arr, size_t current_size)
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