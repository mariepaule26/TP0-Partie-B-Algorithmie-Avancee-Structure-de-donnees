TP/TD d'algorithmie avancee - Partie B
======================================

Cette partie reprend les deux structures vues dans les TP de
programmation impérative :

- TP11 : une liste doublement chaînée pour représenter un polygone ;
- TP12 : un arbre binaire chaîné.

Organisation des fichiers
-------------------------

TP11_Listes/
  liste.h       structures et prototypes
  liste.c       fonctions qui manipulent la liste
  maListe.c     programme de démonstration

TP12_Arbres/
  arbre.h       structure et prototypes
  arbre.c       fonctions qui manipulent l'arbre
  maArbre.c     programme de démonstration

Compilation
-----------

Depuis le dossier TP_Partie_B :

  gcc -std=c11 -Wall -Wextra -Wpedantic TP11_Listes/maListe.c TP11_Listes/liste.c -o TP11_Listes/maListe
  gcc -std=c11 -Wall -Wextra -Wpedantic TP12_Arbres/maArbre.c TP12_Arbres/arbre.c -o TP12_Arbres/maArbre

Avec Make :

  make

Sous Windows avec MSYS2 UCRT64, utiliser `mingw32-make` et les chemins
avec des `/`. Il ne faut pas compiler tous les fichiers ensemble, car
les deux programmes ont chacun leur propre fonction `main`.

Exécution
---------

Linux/macOS :

  ./TP11_Listes/maListe
  ./TP12_Arbres/maArbre

Windows :

  ./TP11_Listes/maListe.exe
  ./TP12_Arbres/maArbre.exe

Tests
-----

Après la compilation :

  python tests/test_tp.py

La liste utilise une cellule sentinelle. Elle ne compte pas comme un
sommet : la position 0 désigne cette cellule et les vraies positions
commencent à 1.

Pour l'arbre, les numéros sont donnés automatiquement dans l'ordre de
création. Lorsqu'un nœud est inséré comme fils gauche ou droit, l'ancien
sous-arbre est conservé sous le nouveau nœud.

La documentation sur les extensions possibles vers les arbres génériques
et les graphes se trouve dans `Documentation/Extensions_arbres_graphes.txt`.

Nettoyage
---------

  make clean
