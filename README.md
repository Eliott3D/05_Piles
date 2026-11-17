# Pile d’entiers

### Objectif

Écrire un programme permettant de gérer une pile d’entiers à l’aide d’un `std::array`.

Une pile suit le principe **dernier arrivé, premier sorti** : les valeurs sont ajoutées et retirées uniquement au sommet, comme des assiettes empilées.

```text
Opération         Pile, du fond vers le sommet
push(12)          [12]
push(7)           [12, 7]
push(-3)          [12, 7, -3]
pop()             [12, 7]
top() retourne 7  [12, 7]
```

### Travail à faire

1. Représenter la pile par :
   - un `std::array` d’entiers dont la capacité est définie par une constante ;
   - un compteur indiquant le nombre de valeurs présentes.

   Les valeurs occupent les premières cases du tableau. Par exemple, pour une capacité de 5 :

   ```text
   Tableau : [12, 7, -3, ?, ?]
   Compteur : 3
   ```

   Les cases marquées `?` sont disponibles, mais ne font pas partie de la pile. Leur contenu n’a donc pas à être pris en compte.

2. Écrire une fonction pour chacune des opérations suivantes.

   | Fonction | Rôle |
   |---|---|
   | `push` | Ajouter une valeur au sommet. |
   | `pop` | Retirer le sommet, sans retourner sa valeur. |
   | `top` | Retourner la valeur du sommet, ou modifier l'élément au sommet de la pile. |
   | `empty` | Indiquer si la pile est vide. |
   | `size` | Retourner le nombre de valeurs présentes. |
   | `clear` | Vider la pile. |
   
3. Écrire une surcharge de la fonction `top`, de sorte qu'elle puisse être utilisée aussi pour remplacer l'élément au sommet de la pile. Pour une pile `ma_pile` avec `nombre` d'éléments, on remplace l'élément au sommet avec cet appel de la surcharge :

	```cpp
	top(ma_pile, nombre) = 12;
	```

4. Gérer les opérations impossibles par des exceptions de `<stdexcept>` :
   - `push` sur une pile pleine : `std::overflow_error` ;
   - `pop` ou `top` sur une pile vide : `std::underflow_error`.

   **Une opération refusée doit laisser la pile inchangée.** Vider une pile déjà vide est autorisé.

5. Proposer un menu permettant d’exécuter ces opérations, d’afficher la pile et de quitter le programme.
   - Un choix hors du menu provoque une nouvelle saisie.
   - Les exceptions sont capturées dans la partie interactive. Un message est affiché, puis le programme continue.
   - Vous pouvez supposer que les saisies sont des entiers valides.

   Les messages suivants doivent être affichés lorsqu’une opération est impossible :

   | Situation | Message affiché |
   |---|---|
   | `push` sur une pile pleine | `Erreur : impossible d'empiler dans une pile pleine.` |
   | `pop` sur une pile vide | `Erreur : impossible de dépiler une pile vide.` |
   | `top` sur une pile vide | `Erreur : impossible de consulter le sommet d'une pile vide.` |
   | surcharge de `top` sur une pile vide | `Erreur : impossible de remplacer le sommet d'une pile vide.` |

   Le message fourni lors de la levée d’une exception est accessible avec la méthode `.what()`. Le préfixe `Erreur : ` est ajouté lors de l’affichage :

   ```cpp
   catch (const std::exception& erreur) {
       cout << "Erreur : " << erreur.what() << endl;
   }
   ```

6. Afficher la pile **du sommet vers le fond**, à raison d’une valeur par ligne, en identifiant le sommet et le fond (voir l’exemple d’exécution ci-après). Si la pile ne contient qu’une valeur, celle-ci est à la fois le sommet et le fond. Si elle est vide, afficher un message approprié. L’affichage ne doit pas modifier la pile.

### Exemple d’exécution

```text
Ce programme permet de manipuler une pile d'entiers.

1 - Empiler
2 - Dépiler
3 - Consulter le sommet
4 - Modifier l'élément au sommet
5 - Vérifier si la pile est vide
6 - Afficher le nombre de valeurs
7 - Vider la pile
8 - Afficher toute la pile
0 - Quitter

Votre choix : 1
Valeur : 42
Valeur empilée.

Votre choix : 1
Valeur : 12
Valeur empilée.

Votre choix : 1
Valeur : 7
Valeur empilée.

Votre choix : 1
Valeur : -3
Valeur empilée.

Votre choix : 8
Sommet -> -3
           7
          12
Fond   -> 42

Votre choix : 5
La pile n'est pas vide.

Votre choix : 2
Valeur retirée : -3

Votre choix : 3
Sommet : 7

Votre choix : 6
Nombre de valeurs : 3

Votre choix : 7
Pile vidée.

Votre choix : 5
La pile est vide.

Votre choix : 8
La pile est vide.

Votre choix : 2
Erreur : impossible de dépiler une pile vide.

Votre choix : 1
Valeur : 12
Valeur empilée.

Votre choix : 8
Sommet / Fond -> 12

Votre choix : 4
Valeur de remplacement : 42
Valeur remplacée.

Votre choix : 8
Sommet / Fond -> 42

Votre choix : 0
Fin de programme.
```

Le menu est réaffiché avant chaque choix ; il n’est reproduit qu’une fois dans cet exemple.

### Compléments

- Répartir les fonctions dans des fichiers externes.
- Les fonctions de gestion de la pile ne font aucune saisie ni aucun affichage.
- Toutes les valeurs de type `int` sont autorisées ; aucune ne représente une case vide.
- Ne pas décaler les éléments lors d’un ajout ou d’un retrait.
- Ne pas utiliser de classe ou de structure personnelle, d’itérateur ni de `std::stack`.
- Aucune variable globale modifiable n’est autorisée.
- Soigner la présentation et éviter les redondances.

### Modalités

- **6 périodes**
- **À faire en équipes de 2**
- À rendre dans Git selon les indications des assistants.

---

Bon travail !