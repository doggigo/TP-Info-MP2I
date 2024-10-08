#include <stdio.h>
int plus_longue_sequence(int liste[], int taille) // Complexité : O(n)
{
  /** 
   * Renvoie la longueur de la plus longue séquence contiguë de nombres égaux dans la liste.
   */
  int longueur = 1;
  int longueur_max = 0;
  int p = liste[0];
  for (int i = 1; i < taille; i++)
  {
    if (p == liste[i])
    {
      longueur++;
    }
    else
    {
      longueur = 1;
    }
    p = liste[i];

    if (longueur > longueur_max)
    {
      longueur_max = longueur;
    }
  }
  return longueur_max;
}

int main(int argc, char const *argv[])
{
  int liste[] = {1, 1, 2, 2, 2, 3, 3, 1, 1, 1};
  int tl = 10;
  printf("plus_longue_sequence(liste, tl) = %d \n", plus_longue_sequence(liste, tl));
  return 0;
}