#include <iostream>
#include <sstream>
#include <limits>
#include <iomanip>

#include "functions.h"

using namespace std;

int display_pile(const array<int,max_size>& arr, const size_t& current_size)
{
    switch (current_size){
    case 0:
        cout << "La pile est vide" << endl; break;
        case 1:
        cout << "Sommet / fond" << setw(5) << " -> " << arr.at(current_size-1) ; break;
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

        cout << user_input << endl;

    } while (user_input != 0);

    cout << "Fin de programme.";

    return EXIT_SUCCESS;
}
