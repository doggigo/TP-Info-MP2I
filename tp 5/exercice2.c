#include <stdio.h>

typedef struct t_r_d {
  int taille;
  int capacite;
  double* donnees;
} trd;

void assertion_indice(trd* t, int i) {
  if (i < t->taille) {
    fprintf(stderr, "le tableau n'a pas d'élément à l'indice i \n", i);
    exit(1);
  };
}

void assertion_allocation(trd* t) {
  if (t->donnees == NULL) {
    fprintf(stderr, "L'allocation de mémoire a échoué\n");
  };
}

trd creer_trd(int capacite) {
  trd tableau = {0, capacite, malloc(sizeof(double) * capacite)};
  return tableau;
};
int taille_trd(trd t) { return t.taille; };

double get_trd(trd t, int i) {
  assertion_indice(&t, i);
  return t.donnees[i];
};

void set_trd(trd t, int i, double x) {
  assertion_indice(&t, i);
  t.donnees[i] = x;
};

void append_trd(trd* t, double x) {
  if (t->taille == t->capacite) {
    t->capacite *= 2;
    t->donnees = realloc(t->donnees, sizeof(double) * t->capacite);
    assertion_allocation(t);
  }
  t->donnees[t->taille] = x;
  t->taille++;
};
double pop_trd(trd* t) { t->taille--; };
void free_trd(trd* t) { free(t->donnees); };

