#include <stdio.h>
#include <inttypes.h>

int32_t facto1(int n)
{
  int k = 1; // k est un variant de boucle car il détermine lorsque la boucle va s'arrêter.
  int32_t res = 1;
  while (k <= n)
  {
    res *= k;
    // Invariant : res = k!
    k++;
  }
  return res;
}

int64_t facto2(int n)
{
  int k = 1;
  int64_t res = 1;
  while (k <= n)
  {
    res *= k;
    k++;
  }
  return res;
}

uint32_t facto3(int n)
{
  int k = 1;
  uint32_t res = 1;
  while (k <= n)
  {
    res *= k;
    k++;
  }
  return res;
}

uint64_t facto4(int n)
{
  int k = 1;
  uint64_t res = 1;
  while (k <= n)
  {
    res *= k;
    k++;
  }
  return res;
}

int main(int argc, char const *argv[])
{

  // On effectue cet algorithme pour toutes les fonctions factorielles, en changeant le type de last
  for (int n = 1; ; n++)
  {
    uint64_t res = facto4(n);
    if (res < 0 || res / n != facto4(n - 1))
    {
      printf("Overflow pour n = %d\n", n);
      break;
    }
    printf("facto1(%d) = %lld\n", n, res);
  }

  return 0;
}
/*
2)
le maximum pour int32_t est 12!
le maximum pour int64_t est 20!
le maximum pour uint32_t est 12!
le maximum pour uint64_t est 21!
3)
On remarque Que la factorielle maximale est légèrement plus haute pour un uint64_t qu'un int64_t.

4)
Il faudrait créer, s'ils n'existent pas déjà, des entiers encore plus grands, codés sur 128, 256, 512... bits
*/