#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* Les numéros dépendent de l'ordre de création des nœuds. */
    noeud *b = nouvNoeud('B');
    noeud *a = nouvNoeud('A');
    noeud *o = nouvNoeud('O');
    noeud *r = nouvNoeud('R');
    noeud *v = nouvNoeud('V');
    if (b == NULL || a == NULL || o == NULL || r == NULL || v == NULL) {
        free(b); free(a); free(o); free(r); free(v);
        return EXIT_FAILURE;
    }

    insererFG(a, b, b->num);
    insererFD(o, b, b->num);
    printf("Arbre initial, parcours prefixe : ");
    parcoursPrefixe(b);
    putchar('\n');

    insererFG(r, b, b->num);
    printf("Apres insertion de R, parcours prefixe : ");
    parcoursPrefixe(b);
    putchar('\n');

    insererFD(v, b, r->num);
    printf("Apres insertion de V, parcours prefixe : ");
    parcoursPrefixe(b);
    putchar('\n');

    noeud *cherche = rechercheNoeud(b, 4);
    if (cherche != NULL) {
        printf("Recherche du noeud 4 : caractere %c.\n", cherche->val);
    }
    detruireArbre(b);
    puts("Memoire liberee.");
    return EXIT_SUCCESS;
}
