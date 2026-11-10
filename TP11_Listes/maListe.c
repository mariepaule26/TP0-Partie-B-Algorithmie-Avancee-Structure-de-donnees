#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

static int ajouter(int position, int x, int y, cellule *liste) {
    point p = {x, y};
    cellule *nouvelle = NouvCel(p);
    if (nouvelle == NULL) return 0;
    /* La fonction demandée ne renvoie pas d'erreur, on vérifie donc ici. */
    if (position < 0 || (size_t)position > TailleListe(liste)) {
        fprintf(stderr, "Position d'insertion invalide : %d\n", position);
        free(nouvelle);
        return 0;
    }
    InsererCellule(position, nouvelle, liste);
    return 1;
}

int main(void) {
    cellule *liste = CreerListe();
    if (liste == NULL) return EXIT_FAILURE;

    puts("TP 11 - Liste doublement chainee d'une forme polygonale");
    if (!ajouter(0, 0, 0, liste) ||
        !ajouter(1, 4, 0, liste) ||
        !ajouter(2, 4, 3, liste) ||
        !ajouter(3, 0, 3, liste)) {
        DetruireListe(liste);
        return EXIT_FAILURE;
    }
    puts("1. Creation de quatre sommets :");
    Afficher(liste);

    puts("2. Insertion de (2, 1) apres le point 2 :");
    if (!ajouter(2, 2, 1, liste)) {
        DetruireListe(liste);
        return EXIT_FAILURE;
    }
    Afficher(liste);

    puts("3. Suppression du point 3 :");
    SupprimeCellule(3, liste);
    Afficher(liste);

    puts("4. Suppression du premier point :");
    SupprimeCellule(1, liste);
    Afficher(liste);

    printf("5. Taille finale : %zu\n", TailleListe(liste));
    DetruireListe(liste);
    puts("Memoire liberee.");
    return EXIT_SUCCESS;
}
