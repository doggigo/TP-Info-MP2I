#include <stdio.h>
void cesar(char *phrase, int n) {
  for(int i = 0; phrase[i]; i++) {
    char *c = &phrase[i];
    if('A' <= *c && *c <= 'Z') {
      *c = (*c + n - 'A' + 26) % 26 + 'A'; // le +26 assure que c + n - 'A' soit positif
    } else if('a' <= *c && *c <= 'z') {
      *c = (*c + n - 'a' + 26) % 26 + 'a';
    }
  }
}

/*
TODO FAIRE LES QUESTIONS 2 ET 3
*/

int main()
{
  char phrase[] = "POUR TOI, BELLE CHLEOPATRE, JE POURRAIS CONQUERIR L'EGYPTE";
  cesar(phrase,3);
  printf(phrase);
  cesar(phrase,-3);
  printf(phrase);
  return 0;
}
