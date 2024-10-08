#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

int nb_chiffres(int n) {
  return (int) log10l(n) + 1;
};

int nb_chiffres_bis(int n) {
  int dz = 1;
  int k = 0;
  while(dz < n) {
    dz *= 10;
    k++;
  }
  return k;
}

bool est_narcissique(int n) {
  if(n == 0) return true;
  int chiffres = nb_chiffres_bis(n); 
  int somme = 0;
  int m = n;
  int reste = 0;
  while(m != 0) {
    reste = m % 10;
    somme += powl(reste,chiffres);
    m /= 10;
  }
  return somme == n;
}

void affiche_narcissiques(int n) {
  for (int i = 0; i <= n; i++)
  {
    if(est_narcissique(i)) printf("%d \n",i);
  }
}

int main(int argc, char const *argv[])
{
  affiche_narcissiques(atoi(argv[1]));
  return 0;
}

