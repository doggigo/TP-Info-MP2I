#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
    1*1=121
  11*11=12321
111*111=1234321

-> 2(t-i-1) fois ' '

pour t = 3, on commence avec un espacement de 2
on commence avec un espace de t-1 jusqu'à 0
*/

void affiche_n_fois(char c, int n) {
  for (int i = 0; i < n; i++)
  {
    printf("%c",c);
  }
}

void talkhys(int t) {
  unsigned long long gauche = 1;
  for (int i = 0; i < t; i++)
  {
    affiche_n_fois(' ', 2*(t-i-1));
    printf("%llu*%llu=", gauche, gauche);
    unsigned long long prochain = gauche * 10 + 1;
    printf("%llu",prochain*prochain);
    gauche = prochain;
    printf("\n");
  }
}


int main(int argc, char const *argv[])
{
  talkhys(9);
  return 0;
}
