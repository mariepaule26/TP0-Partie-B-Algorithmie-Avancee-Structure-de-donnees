#ifndef ARBRE_H
#define ARBRE_H

typedef struct noeud {
    char val;
    int num;
    struct noeud *filsG;
    struct noeud *filsD;
} noeud;

noeud *nouvNoeud(char carac);
noeud *rechercheNoeud(noeud *racine, int num_noeud);
void insererFG(noeud *nouveau, noeud *arbre, int num_parent);
void insererFD(noeud *nouveau, noeud *arbre, int num_parent);
void parcoursPrefixe(const noeud *racine);
void detruireArbre(noeud *racine);

#endif
