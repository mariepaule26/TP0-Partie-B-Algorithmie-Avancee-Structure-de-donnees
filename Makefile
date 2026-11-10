CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -g
ifeq ($(OS),Windows_NT)
  EXE = .exe
  PYTHON = python
  RM = cmd /C del /Q
else
  EXE =
  PYTHON = python3
  RM = rm -f
endif

.PHONY: all test clean
all: TP11_Listes/maListe$(EXE) TP12_Arbres/maArbre$(EXE)

TP11_Listes/maListe$(EXE): TP11_Listes/maListe.c TP11_Listes/liste.c TP11_Listes/liste.h
	$(CC) $(CFLAGS) TP11_Listes/maListe.c TP11_Listes/liste.c -o $@

TP12_Arbres/maArbre$(EXE): TP12_Arbres/maArbre.c TP12_Arbres/arbre.c TP12_Arbres/arbre.h
	$(CC) $(CFLAGS) TP12_Arbres/maArbre.c TP12_Arbres/arbre.c -o $@

test: all
	$(PYTHON) tests/test_tp.py

clean:
ifeq ($(OS),Windows_NT)
	-$(RM) TP11_Listes\maListe.exe TP12_Arbres\maArbre.exe
else
	$(RM) TP11_Listes/maListe TP12_Arbres/maArbre
endif
