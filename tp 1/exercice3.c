#include <stdio.h>
#include <stdlib.h>
int main(void) {
  int i;
  printf("Bonjour la variable i vaut %d !\n", i);
}
/* 1) A la compilation on observe que la valeur de i est un nombre aléatoire. Si on affecte i à 0 on obtient bien 0.
   2) Ces options signifient qu'on veut etre au courant de toutes les alertes (signalements), utiliser la norme C `c11` et exporter notre fichier sous le nom `hello2`
*/
