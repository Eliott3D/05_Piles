#include <iostream>
#include <sstream>
#include <limits>

using namespace std;

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
