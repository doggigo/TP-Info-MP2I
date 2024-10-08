#include <stdio.h>
#define nl printf("\n")


void affiche_k_fois(char c, int k) {
  for (int i = 0; i < k; i++)
  {
  printf("%c",c);
  }
}

void carre(int n) {
  for (int i = 0; i < n; i++)
  {
    affiche_k_fois('*',n);
    printf("\n");
  }
  
}

void pyramide(int h) {
  for(int i = 1 ; i <= h ; i++) {
    affiche_k_fois(' ',h-i);
    affiche_k_fois('*',i*2-1);
    nl;
  }
}

void rectangle_vide(int l, int h) {
  affiche_k_fois('*',l+1);
  nl;
  for(int i = 1 ; i < h-1 ; i++ ){
    for(int j = 0 ; j <= l ; j++) {
      char c = (j % l == 0)? '*' : ' ';
      printf("%c",c);
    }
    nl;
  }
  affiche_k_fois('*',l+1);
}

void losange(int t) {
  // for (int i = 0; i < t >> 1; i++)
  // {
  //   affiche_k_fois(' ',(t>>1)-i);
  //   affiche_k_fois('*',i*2-1);
  //   nl;
  // }

  int t2 = t - (t>>1);
  for (int i = 0; i < t2; i++)
  {
    affiche_k_fois(' ',i);
    affiche_k_fois('*',t-i*2);
    nl;
  }
  
}

int main(int argc, char const *argv[])
{
  pyramide(3);
  nl;
  carre(5);
  nl;
  rectangle_vide(7,5);
  nl;
  losange(5);
  return 0;
}
