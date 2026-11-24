#include <iostream>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <array>
#include <iomanip>
#include "stack.h"
#include "display.h"

using namespace std;

int main()
{
    array<int, max_size> arr = {};
    const array<int, max_size>& arr_read = arr;
    size_t current_length = 0;

    cout << "Ce programme permet de manipuler une pile d'entiers." << endl << endl;

    int user_input = -1;
    do {
        display_menu();
        cout << "Votre choix : ";

        if (!(cin >> user_input) || user_input < 0 || user_input > 8) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            user_input = -1;
            continue;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        try {
            //Switch for the function that the user choses
            switch (user_input) {
                case 1: { // case Push
                    int new_value = 0;
                    cout << "Valeur : ";
                    if (!(cin >> new_value)) {
                        cout << "Seul un entier peut être ajouté à la pile." << endl;
                    } else {
                        push(arr, current_length, new_value);
                        cout << "Valeur empilée." << endl;
                    }
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                case 2: { // case Pop
                    int removed = 0;
                    if (!empty(current_length)) {
                        removed = top(arr_read, current_length);
                    }
                    pop(current_length);
                    cout << "Valeur retirée : " << removed << endl;
                    break;
                }
                case 3: { // case Top
                    const int current_top = top(arr_read, current_length);
                    cout << "Sommet : " << current_top << endl;
                    break;
                }
                case 4: { // case Modify Top
                    int new_value = 0;
                    cout << "Valeur de remplacement : ";
                    if (!(cin >> new_value)) {
                        cout << "Seul un entier peut être ajouté à la pile." << endl;
                    } else {
                        top(arr, current_length) = new_value;
                        cout << "Valeur remplacée." << endl;
                    }
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
        } catch (const exception& error) {
            cout << "Erreur : " << error.what() << endl;
        }

    cout << endl;
    } while (user_input != 0);

    cout << "Fin de programme.";

    return EXIT_SUCCESS;
}
