#include <iostream>
#include <sstream>
#include <limits>
#include <array>

#include "functions.h"

using namespace std;

int main()
{
    std::array<int, max_size> arr = {};
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
            }
            case 4: {
                // try {
                //     top(arr, current_length);
                // } catch (exception& error) {
                //     cout << "Erreur : " << error.what() << endl;
                //     break;
                // }
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
            }

            default :
                break;
        }



    cout << endl;
    } while (user_input != 0);

    cout << "Fin de programme.";

    return EXIT_SUCCESS;
}
