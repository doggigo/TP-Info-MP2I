#include <stdbool.h>
#include <stddef.h>
bool a_sequence_de_3(int *liste, size_t taille) // Complexité : O(n)
/**
 * Vérifie s'il existe au moins une séquence contiguë de nombres égaux de longueur >= 3 dans la liste.
 */
{
  bool existence = false;
  int p = 0;
  int consecutifs = 0;
  for (size_t i = 0; i < taille; ++i)
  {
    int elem = liste[i];

    if (p == elem)
    {
      consecutifs++;
    }
    else
    {
      consecutifs = 1;
    }

    p = elem;

    if (consecutifs >= 3)
    {
      existence = true;
    }
  }
  return existence;
}