#include <stdio.h>

int somme_entiers(int n) {
  int somme = 0;
  for (int i = 0; i < n + 1; i++) {
    somme += i;
  }
  return somme;
}

int main(int argc, char const *argv[]) {
  printf("%d", somme_entiers(100));
  return 0;
}

/*
  2) Le type de retour de somme_entiers est int
  3) Le type de cette valeur est un flotant (double ou float)
  4) Le resultat sera toujours 5050 et pas 5050.0 car c va convertir notre flottant en entier
  5) Si l'on convertit le flottant 0.1 en entier, on va garder sa partie entiere, soit 0. L'avertissement permet de savoir que l'on passe de 0.1 à 0.
*/