#ifndef PILE_H
#define PILE_H
#include <stdbool.h>
struct pil;
typedef struct pil pile;
pile *creer();
bool est_vide(const pile*);
void push(pile **, int);
int pop(pile **);
int sommet(pile *);
void liberer_pile(pile* p);
#endif