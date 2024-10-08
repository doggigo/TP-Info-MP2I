#define GREATER 1
#define EQUAL 0
#define LOWER -1

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int compta_c(char *txt) {
  int n = 0;
  for (int i = 0; txt[i]; i++) {
    if (txt[i] == 'a') n++;
  }
}

int longueur(char *str) {
  int i = 0;
  while (str[i]) {
    i++;
  }
  return i;
}

int vide(char *str) { return str[0] == '\0'; }

void concatener(char *s1, char *s2, char *out, int out_size) {
  out[out_size - 1] = '\0';
  int cursor = 0;

  // Premier string
  for (int i = 0; s1[i] && cursor < out_size; i++) {
    out[cursor] = s1[i];
    cursor++;
  }

  // 2e string
  for (int i = 0; s2[i] && cursor < out_size; i++) {
    out[cursor] = s2[i];
    cursor++;
  }

  // remplit `out` de '\0' pour qu'il n'y ait pas de UB
  while (cursor < out_size) {
    out[cursor] = '\0';
  }
}

void copier(char *src, char *dst, int dst_size) {
  dst[dst_size - 1] = '\0';
  int i = 0;
  while (src[i] && dst[i]) {
    dst[i] = src[i];
  }

  for (int j = i; j < dst_size; j++) {
    dst[j] = '\0';
  }
}

int comparer(char *s1, char *s2) {
  int i = 0;
  while (s1[i] && s2[i]) {
    if (s1[i] > s2[i]) return GREATER;
    if (s1[i] < s2[i]) return LOWER;
    i++;
  }

  if (s1[i] > s2[i]) {
    return GREATER;
  } else if (s1[i] < s2[i]) {
    return LOWER;
  } else {
    return EQUAL;
  }
}

void inverser(char *s1) {
  int l = longueur(s1) - 1;
  for (int i = 0; i < (l >> 1); i++) {
    s1[i] = s1[i] ^ s1[l - i];
    s1[l - i] = s1[l - i] ^ s1[i];
    s1[i] = s1[i] ^ s1[l - i];
  }
}

char *lire_string() {
  char *temp = malloc(sizeof(char) * 256);
  scanf("%256[^\n]", temp);

  temp = realloc(temp, sizeof(char) * longueur(temp));
  return temp;
}

char head(char *s) {
  if (s == NULL) return '\0';
  return s[0];
}

char *tail(char *s) {
  if (!head(s)) return s;
  return s + 1;
}

void plus_grande_monotonie(char *s, int *pos, int *lon) {
  int longueur_actuelle = 1;
  int i = 1;
  int j = 1;
  char dernier = head(s);
  char *substring = tail(s);

  while (head(substring)) {
    if (head(s) < head(tail(s))) {
      longueur_actuelle++;
      j++;
    } else {
      longueur_actuelle = 1;
      if (*lon < longueur_actuelle) {
        *lon = longueur_actuelle;
        *pos = i;
      };
      i = j;
    }
    substring = tail(substring);
  }
}

bool est_palindrome_1(char *c) {
  int l = longueur(c);
  for (int i = 0; i < l; i++) {
    char *cp = malloc(sizeof(char) * l);
    copier(c, cp, l); 
    inverser(cp);
    bool res = comparer(c, cp) == EQUAL;
    free(cp);
    return res;
  }
}

bool est_palindrome_2(char *c) {
  int l = longueur(c) - 1;
  for (int i = 0; i < (l >> 1); i++) {
    if (c[i] != c[l - i]) return false;
  }
  return true;
}

int main(int argc, char const *argv[]) { return 0; }
