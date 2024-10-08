#include <stdio.h>

void f(int n, int *nmax)
{
  printf("Debut de l'appel de f(%d, _)\n", n);
  printf("n = %d\n", n); // valeur de n
  printf("&n = %p\n", &n); // valeur de l'adresse de n
  printf("nmax = %p\n", nmax); // valeur de l'adresse de la variable vers laquelle pointe nmax
  printf("*nmax = %d\n", *nmax); // valeur de la variable vers laquelle pointe nmax
  printf("&nmax = %p\n", &nmax); // valeur de l'adresse du pointeur nmax
  if (n < *nmax)
  {
    f(n + 1, nmax);
  }
  printf("Fin de l'appel de f(%d, _)\n", n);
}

int main()
{

  int N = 2;
  f(0, &N);
  return 0;
}