"""Tests automatiques des sorties des deux programmes C."""
import os
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

def run(path):
    exe = ROOT / (path + (".exe" if os.name == "nt" else ""))
    return subprocess.run([str(exe)], capture_output=True, text=True, check=True).stdout

def main():
    liste = run('TP11_Listes/maListe')
    assert 'Points du polygone (4) : (0, 0) -> (4, 0) -> (4, 3) -> (0, 3)' in liste
    assert 'Points du polygone (5) : (0, 0) -> (4, 0) -> (2, 1) -> (4, 3) -> (0, 3)' in liste
    assert 'Points du polygone (3) : (4, 0) -> (4, 3) -> (0, 3)' in liste
    assert 'Taille finale : 3' in liste

    arbre = run('TP12_Arbres/maArbre')
    assert 'Arbre initial, parcours prefixe : B A O' in arbre
    assert 'Apres insertion de R, parcours prefixe : B R A O' in arbre
    assert 'Apres insertion de V, parcours prefixe : B R A V O' in arbre
    assert 'Recherche du noeud 4 : caractere R.' in arbre
    print('OK - Tests TP11 et TP12 reussis.')

if __name__ == '__main__':
    main()
