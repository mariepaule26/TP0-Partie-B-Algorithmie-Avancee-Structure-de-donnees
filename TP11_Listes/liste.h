#ifndef LISTE_H
#define LISTE_H

#include <stddef.h>

typedef struct {
    int x;
    int y;
} point;

typedef struct cellule {
    point p;
    struct cellule *prec;
    struct cellule *suiv;
} cellule;

/* La première cellule sert de sentinelle et ne représente pas un sommet.
 * Les sommets sont numérotés à partir de 1. */
cellule *CreerListe(void);
cellule *NouvCel(point p);
void InsererCellule(int pl, cellule *cel, cellule *liste);
void SupprimeCellule(int pl, cellule *liste);
void Afficher(cellule *liste);
size_t TailleListe(const cellule *liste);
void DetruireListe(cellule *liste);

#endif
