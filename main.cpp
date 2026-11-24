#include <iostream>
#include <sstream>
#include <limits>
#include <array>
#include <iomanip>
#include "stack.h"

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

int main()
{
    array<int, max_size> arr = {};
    size_t current_length = 0;
    stringstream introduction;

    introduction << "1 - Empiler" << endl
                 << "2 - Dépiler" << endl
                 << "3 - Consulter le sommet" << endl
                 << "4 - Modifier l'élément au sommet" << endl
                 << "5 - Vérifier si la pile est vide" << endl
                 << "6 - Afficher le nombre de valeurs" << endl
                 << "7 - Vider la pile" << endl
                 << "8 - Afficher toute la pile" << endl
                 << "0 - Quitter" << endl;

    cout << "Ce programme permet de manipuler une pile d'entiers." << endl << endl;

    int user_input = -1;
    do {
        cout << introduction.str() << endl;
        cout << "Votre choix : ";

        if (!(cin >> user_input) || user_input < 0 || user_input > 8) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            user_input = -1;
            continue;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //Switch for the function that the user choses
        switch (user_input) {
            case 1: { // case Push
                int new_value = 0;
                cout << "Valeur : ";
                if (!(cin >> new_value)) {
                    cout << "Seul un entier peut être ajouté à la pile." << endl;
                } else {
                    try {
                        push(arr, current_length, new_value);
                        cout << "Valeur empilée." << endl;
                    }
                    catch (const exception& error) {
                        cout << "Erreur : " << error.what() << endl;
                    }
                }
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            case 2: { // case Pop
                try {
                    pop(current_length);
                    cout << "Valeur retirée : " << arr[current_length] << endl;
                } catch (const exception& error) {
                    cout << "Erreur : " << error.what() << endl;
                }
                break;
            }
            case 3: { // case Top
                try {
                    const int current_top = top(arr, current_length);
                    cout << "Sommet : " << current_top << endl;
                } catch (const exception& error) {
                    cout << "Erreur : " << error.what() << endl;
                }
                break;
            }
            case 4: { // case Modify Top
                int new_value = 0;
                cout << "Valeur de remplacement : ";
                if (!(cin >> new_value)) {
                    cout << "Seul un entier peut être ajouté à la pile." << endl;
                } else {
                    try {
                        top(arr, current_length, new_value);
                        cout << "Valeur remplacée." << endl;
                    }
                    catch (const exception& error) {
                        cout << "Erreur : " << error.what() << endl;
                    }
                }
                break;
            }
            case 5: { // case Empty
                cout << (empty(current_length) ? "La pile est vide." : "La pile n'est pas vide.") << endl;
                break;
            }
            case 6: { // case Size
                cout << "Nombre de valeurs : " << size(current_length) << endl;
                break;
            }
            case 7: { // case Clear
                clear(current_length);
                cout << "Pile vidée." << endl;
                break;
            }
            case 8: { // case Display
                display_stack(arr, current_length);
                break;
            }
            default :
                break;
        }



    cout << endl;
    } while (user_input != 0);

    cout << "Fin de programme.";

    return EXIT_SUCCESS;
}
