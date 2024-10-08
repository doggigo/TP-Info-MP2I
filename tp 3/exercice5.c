#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void remplir_int(int tab[], int taille) {
  
  for(int i ; i < taille ; i++) {
    tab[i] = 1 + (int) (100.0*rand()/(RAND_MAX+1.0));
  }
}

void remplir_float(float tab[], int taille) {
  
  for(int i ; i < taille ; i++) {
    tab[i] = 1.0f + (float) (100.0*rand()/(RAND_MAX+1.0f));
  }
}

void remplir_bool(bool tab[], int taille) {
  
  for(int i ; i < taille ; i++) {
    tab[i] = (bool) rand() % 2;
  }
}

int mini(int tab[], int taille)
{
  int plus_petit = tab[0];
  if (taille == 1)
    return plus_petit;
  for (int i = 0; i < taille; i++)
  {
    plus_petit = plus_petit > tab[i] ? tab[i] : plus_petit;
  }
  return plus_petit;
}

int nb_superieurs_a(int tab[], int taille, int n)
{
  int k = 0;
  for (int i = 0; i < taille; i++)
  {
    k = tab[i] > n ? k + 1 : k;
  }
  return k;
}

float moyenne(float tab[], int taille)
{
  float res = 0;
  for (int i = 0; i < taille; i++)
  {
    res += tab[i];
  }
  return res / taille;
}

bool all(bool tab[], int taille)
{
  for (int i = 0; i < taille; i++)
  {
    if (!tab[i])
      return false;
  }
  return true;
}

bool any(bool tab[], int taille)
{
  for (int i = 0; i < taille; i++)
  {
    if (tab[i])
      return true;
  }
  return false;
}

bool vrais_maj(bool tab[], int taille)
{
  int v = 0, f = 0;
  for (int i = 0; i < taille; i++)
  {
    if (tab[i])
    {
      v++;
    }
    else
    {
      f++;
    };
  }
  return v > f;
}

bool contigus(bool tab[],int taille) {
  bool entre = false;
  bool sorti = false;
  for (int i = 0; i < taille; i++)
  {
    if(tab[i]) entre = true;
    if(entre && !tab[i]) sorti = true;
    if(sorti && tab[i]) return false;
  }

  return true;
}

int main(int argc, char const *argv[])
{

  srand(time(NULL));

  int tab_int[30];
  float tab_float[30];
  bool tab_bool[30];
  remplir_int(tab_int, 30);
  remplir_float(tab_float, 30);
  remplir_bool(tab_bool,30);
  printf("mini(tab_int) = %d\n", mini(tab_int,30));
  printf("nb_superieurs_a(tab_int) = %d\n", nb_superieurs_a(tab_int,30,20));
  printf("moyenne(tab_float) = %f\n", moyenne(tab_float,30));
  printf("all(tab_bool) = %s\n", all(tab_bool,30)? "true" : "false");
  printf("any(tab_bool) = %s\n", any(tab_bool,30)? "true" : "false");
  printf("vrais_maj(tab_bool) = %s\n", vrais_maj(tab_bool,30)? "true" : "false");
  printf("contigus(tab_bool) = %s\n", contigus(tab_bool,30)? "true" : "false");

  return 0;
}
