#include <iostream>
#include <sstream>
#include <limits>
#include <array>
#include <iomanip>
#include "functions.h"

using namespace std;

int display_pile(const array<int,max_size>& arr, const size_t& current_size)
{
    switch (current_size){
    case 0:
        cout << "La pile est vide" << endl; break;
        case 1:
        cout << "Sommet / fond" << setw(5) << " -> " << arr.at(current_size-1) << endl ; break;
        default:
        cout << left << setw(6) << "Sommet" << setw(5) << " -> " << right << setw(10) << arr.at(current_size-1) << endl;

        for (size_t index = current_size-2; index > 0; index--)
        {
            cout << right << setw(21) << arr[index] << endl;
        }

        cout << left << setw(6) << "Fond" << setw(5) << " -> " << setw(10) << right << arr.at(0) << endl;

        break;
    }
    return 1;
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

    cout << introduction.str() << endl;

    int user_input = -1;
    do {
        cout << "Votre choix : ";

        if (!(cin >> user_input) || user_input < 0 || user_input > 8) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            user_input = -1;
            continue;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (user_input) {
            case 1: {
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
            case 2: {
                try {
                    pop(current_length);
                    cout << "Valeur retirée : " << arr[current_length] << endl;
                } catch (const exception& error) {
                    cout << "Erreur : " << error.what() << endl;
                }
                break;
            }
            case 3: {
                try {
                    const int current_top = top(arr, current_length);
                    cout << "Sommet : " << current_top << endl;
                } catch (const exception& error) {
                    cout << "Erreur : " << error.what() << endl;
                }
                break;
            }
            case 4: {
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
            case 5: {
                cout << (empty(current_length) ? "La pile est vide." : "La pile n'est pas vide.") << endl;
                break;
            }
            case 6: {
                cout << "Nombre de valeurs : " << size(current_length) << endl;
                break;
            }
            case 7: {
                clear(current_length);
                cout << "Pile vidée" << endl;
                break;
            }
            case 8: {
                display_pile(arr, current_length);
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
