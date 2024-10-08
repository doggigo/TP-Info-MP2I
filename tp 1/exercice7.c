#include <stdbool.h>
#include <stdio.h>

double expo_rapide(double x, int n) {
  if (n < 0) return expo_rapide(x, -n);

  int acc = 1;

  while (n > 0) {
    
    if (n % 2 == 1) acc *= x;
    
    x *= x;
    n = n >> 1;
  }
  return acc;
}

bool est_premier(int n) {
  int k = 2;
  while(k*k < n) {
    if(n % k == 0) return false;
    k+= 1;
  }
  return true;
}

void affiche_diviseurs(int n) {
  for(int k = 1 ; k <= n ; k++) {
    if(n % k == 0) printf("%d\n",k);
  }
}

int main(int argc, char const *argv[])
{
  affiche_diviseurs(60);
  return 0;
}
