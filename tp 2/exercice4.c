#include <stdio.h>
#include <stdlib.h>

void dec_bin_rec(int n, char *binary, int index) {
    if (index == 32) {
        binary[32] = '\0';
        return;
    }    
    dec_bin_rec(n >> 1, binary, index + 1);
    
    binary[31-index] = (n & 1) + '0';
}

void print_binary(int n) {
  char *res = malloc(sizeof(char) * 33);
  res[32] = '\0';
  int k = 31;
  
  for(int i = 0; i < 32; i++) {
    res[k--] = (n & 1) + '0';
    n >>= 1;
  }
  printf("%s\n",res);
  free(res);
}

void mystere(int n) {
  if (n != 0) {
    mystere(n / 2);
    printf("%d", n % 2);
  } else {
    fflush(stdout);
  }
}

int main()
{
  char binary[33];
  dec_bin_rec(255,binary,0);
  printf("%s",binary);
  printf("\n");
  print_binary(255);

  /*
  Voici une representation de la stack :
  Entrée/sortie vers la droite : <->[]
  [mystere(n)]
  [mystere(n/2),mystere(n)]
  [mystere(n/4),mystere(n/2),mystere(n)]
  [mystere(n/8),mystere(n/4),mystere(n/2),mystere(n)]
  ..
  [mystere(0),...mystere(n)]
  Puis le programme va terminer les fonctions dans la pile en la dépilant.
  Le programme va donc afficher, en remontant le nombre, n en base binaire
  */
  
  return 0;
}
