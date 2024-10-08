#include "pile.h"

#include <stdio.h>
#include <stdlib.h>

struct pil {
  int valeur;
  struct pil *suivant;
};

pile *creer() { return NULL; }

bool est_vide(const pile *p) { return p == NULL; }
int sommet(pile *p) {
  if (est_vide(p)) {
    fprintf(stderr, "vide!");
    exit(EXIT_FAILURE);
  }
  return p->valeur;
}

void push(pile **p, int valeur) {
  pile *nouveau = malloc(sizeof(pile));
  // A compléter
  nouveau->valeur =  ? ;
  nouveau->suivant = ? ;
  *p =               ? ;
}

int pop(pile **p) {
  // A compléter
}

void liberer_pile(pile *p) {
  // A compléter
}

int main() {
  pile *p = creer();
  // A compléter
  return 0;
}