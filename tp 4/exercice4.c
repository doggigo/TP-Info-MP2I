#define TAILLE_ALPHA 26

#include <stdbool.h>
#include <stdio.h>

void frequences(const char *chaine, int freq[TAILLE_ALPHA]) {
  for (int i = 0; chaine[i]; i++) {
    if ('a' > chaine[i] || 'z' < chaine[i]) {
      return;
    }
    freq[chaine[i] - 'a']++;
  }
}

void initialise(int freq[TAILLE_ALPHA]) {
  for (int i = 0; i < TAILLE_ALPHA; i++) {
    freq[i] = 0;
  }
}

bool compare(int freq1[TAILLE_ALPHA], int freq2[TAILLE_ALPHA]) {
  for (int i = 0; i < TAILLE_ALPHA; i++) {
    if (freq1[i] != freq2[i]) return false;
  }
  return true;
}

int main(int argc, char const *argv[]) {
  if (argc != 3) return 1;
  const char *s1 = argv[1];
  const char *s2 = argv[2];

  int freq1[TAILLE_ALPHA];
  initialise(freq1);
  frequences(s1, freq1);
  int freq2[TAILLE_ALPHA];
  initialise(freq2);
  frequences(s2, freq2);
  printf("%s et %s %s \n", s1, s2, compare(freq1, freq2)? "sont anagrammes" : "ne sont pas anagrammes");
  return 0;
}
