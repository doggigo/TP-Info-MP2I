#include <stdbool.h>
#include <stdio.h>


int plus_grande_sous_suite_croissante_monotone(int liste[], int taille)
{
  if(taille == 0) return 0;

  int longueur_max = 1;
  int taille_actuelle = 1;
  int dernier_nb = liste[0];

  for (int i = 1; i < taille; i++)
  {
    if (liste[i] > dernier_nb)
    {
      taille_actuelle++;
    }
    else
    {
      longueur_max = taille_actuelle > longueur_max ? taille_actuelle : longueur_max;
      taille_actuelle = 1;
    }
    dernier_nb = liste[i];
  }
  return longueur_max;
}

int plus_grande_sous_suite_decroissante_monotone(int liste[], int taille)
{
  if(taille == 0) return 0;

  int longueur_max = 1;
  int taille_actuelle = 1;
  int dernier_nb = liste[0];

  for (int i = 1; i < taille; i++)
  {
    if (liste[i] < dernier_nb)
    {
      taille_actuelle++;
    }
    else
    {
      longueur_max = taille_actuelle > longueur_max ? taille_actuelle : longueur_max;
      taille_actuelle = 1;
    }
    dernier_nb = liste[i];
  }
  return longueur_max;
}


int plus_grande_sous_suite_croissante_decroissante_monotone(int liste[], int taille) 
{
  int plus_grande_croissante = plus_grande_sous_suite_croissante_monotone(liste,taille);
  int plus_grande_decroissante = plus_grande_sous_suite_decroissante_monotone(liste,taille);  
  return plus_grande_croissante > plus_grande_decroissante ? plus_grande_croissante : plus_grande_decroissante;
}

int main(int argc, char const *argv[])
{
  int liste[] = {1, 2, 3, 4, 7, 6, 5, 4, 3, 2, 1};
  printf("plus_grande_sous_suite_croissante_decroissante_monotone(liste, 11) = %d \n", plus_grande_sous_suite_croissante_decroissante_monotone(liste, 11));
  printf("plus_grande_sous_suite_croissante_monotone(liste, 11) = %d \n", plus_grande_sous_suite_croissante_monotone(liste, 11));
  return 0;
}
