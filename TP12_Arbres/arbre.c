#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>

noeud *nouvNoeud(char carac) {
    static int prochain_numero = 1;
    noeud *nouveau = malloc(sizeof *nouveau);
    if (nouveau == NULL) {
        fprintf(stderr, "Erreur : allocation memoire impossible.\n");
        return NULL;
    }
    nouveau->val = carac;
    nouveau->num = prochain_numero++;
    nouveau->filsG = NULL;
    nouveau->filsD = NULL;
    return nouveau;
}

noeud *rechercheNoeud(noeud *racine, int num_noeud) {
    if (racine == NULL) return NULL;
    if (racine->num == num_noeud) return racine;
    noeud *trouve = rechercheNoeud(racine->filsG, num_noeud);
    if (trouve != NULL) return trouve;
    return rechercheNoeud(racine->filsD, num_noeud);
}

void insererFG(noeud *nouveau, noeud *arbre, int num_parent) {
    if (nouveau == NULL || arbre == NULL) {
        fprintf(stderr, "Insertion gauche impossible : argument NULL.\n");
        return;
    }
    noeud *parent = rechercheNoeud(arbre, num_parent);
    if (parent == NULL) {
        fprintf(stderr, "Insertion gauche impossible : parent %d absent.\n", num_parent);
        return;
    }
    if (nouveau->filsG != NULL || nouveau->filsD != NULL ||
        rechercheNoeud(arbre, nouveau->num) != NULL) {
        fprintf(stderr, "Insertion gauche impossible : noeud non detache.\n");
        return;
    }
    nouveau->filsG = parent->filsG;
    parent->filsG = nouveau;
}

/* Cette fonction sert à répondre à la dernière question du TP. */
void insererFD(noeud *nouveau, noeud *arbre, int num_parent) {
    if (nouveau == NULL || arbre == NULL) {
        fprintf(stderr, "Insertion droite impossible : argument NULL.\n");
        return;
    }
    noeud *parent = rechercheNoeud(arbre, num_parent);
    if (parent == NULL) {
        fprintf(stderr, "Insertion droite impossible : parent %d absent.\n", num_parent);
        return;
    }
    if (nouveau->filsG != NULL || nouveau->filsD != NULL ||
        rechercheNoeud(arbre, nouveau->num) != NULL) {
        fprintf(stderr, "Insertion droite impossible : noeud non detache.\n");
        return;
    }
    nouveau->filsD = parent->filsD;
    parent->filsD = nouveau;
}

void parcoursPrefixe(const noeud *racine) {
    if (racine == NULL) return;
    printf("%c ", racine->val);
    parcoursPrefixe(racine->filsG);
    parcoursPrefixe(racine->filsD);
}

void detruireArbre(noeud *racine) {
    if (racine == NULL) return;
    detruireArbre(racine->filsG);
    detruireArbre(racine->filsD);
    free(racine);
}
