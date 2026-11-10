#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

cellule *NouvCel(point p) {
    cellule *nouvelle = malloc(sizeof *nouvelle);
    if (nouvelle == NULL) {
        fprintf(stderr, "Erreur : allocation memoire impossible.\n");
        return NULL;
    }
    nouvelle->p = p;
    nouvelle->prec = NULL;
    nouvelle->suiv = NULL;
    return nouvelle;
}

cellule *CreerListe(void) {
    point p = {0, 0};
    return NouvCel(p);
}

size_t TailleListe(const cellule *liste) {
    size_t n = 0;
    if (liste == NULL) return 0;
    for (const cellule *courant = liste->suiv; courant != NULL; courant = courant->suiv) {
        ++n;
    }
    return n;
}

/* La position 0 correspond à la sentinelle, donc à une insertion en tête.
 * En cas d'erreur, la cellule n'est pas libérée par cette fonction. */
void InsererCellule(int pl, cellule *cel, cellule *liste) {
    if (liste == NULL || cel == NULL || pl < 0) {
        fprintf(stderr, "Insertion impossible : arguments invalides.\n");
        return;
    }
    if (cel == liste || cel->prec != NULL || cel->suiv != NULL) {
        fprintf(stderr, "Insertion impossible : cellule deja liee ou sentinelle.\n");
        return;
    }
    cellule *courant = liste;
    for (int i = 0; i < pl && courant != NULL; ++i) {
        courant = courant->suiv;
    }
    if (courant == NULL) {
        fprintf(stderr, "Insertion impossible : position %d hors limites.\n", pl);
        return;
    }
    cel->prec = courant;
    cel->suiv = courant->suiv;
    if (courant->suiv != NULL) {
        courant->suiv->prec = cel;
    }
    courant->suiv = cel;
}

/* Les positions de suppression commencent à 1. */
void SupprimeCellule(int pl, cellule *liste) {
    if (liste == NULL || pl < 1) {
        fprintf(stderr, "Suppression impossible : arguments invalides.\n");
        return;
    }
    cellule *courant = liste->suiv;
    for (int i = 1; i < pl && courant != NULL; ++i) {
        courant = courant->suiv;
    }
    if (courant == NULL) {
        fprintf(stderr, "Suppression impossible : position %d hors limites.\n", pl);
        return;
    }
    courant->prec->suiv = courant->suiv;
    if (courant->suiv != NULL) {
        courant->suiv->prec = courant->prec;
    }
    free(courant);
}

void Afficher(cellule *liste) {
    if (liste == NULL) {
        puts("Liste non initialisee.");
        return;
    }
    if (liste->suiv == NULL) {
        puts("Polygone : liste vide.");
        return;
    }
    printf("Points du polygone (%zu) : ", TailleListe(liste));
    for (cellule *courant = liste->suiv; courant != NULL; courant = courant->suiv) {
        printf("(%d, %d)", courant->p.x, courant->p.y);
        if (courant->suiv != NULL) printf(" -> ");
    }
    putchar('\n');
}

void DetruireListe(cellule *liste) {
    while (liste != NULL) {
        cellule *suivante = liste->suiv;
        free(liste);
        liste = suivante;
    }
}
