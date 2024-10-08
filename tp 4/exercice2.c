#define N 5
#define M 5
#include <stdbool.h>

// tableau de taille N x M

bool ligne_vraie(bool *mat[]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (!mat[i][j]) break;
      if (mat[i][j] && j == M - 1) return true;
    }
  }
}

bool colonne_vraie(bool *mat[]) {
  for (int j = 0; j < M; j++) {
    for (int i = 0; i < N; i++) {
      if (!mat[i][j]) return;
      if (mat[i][j] && i == N - 1) return true;
    }
  }
}

int *min_lignes(int mat[][colonnes], int lignes, int colonnes) {
  int *tab = malloc(sizeof(int) * lignes);

  for (int i = 0; i < lignes; i++) {
    int mini = mat[i][0];
    for (int j = 1; j < colonnes; j++) {
      if (j < mini) {
        mini = j;
      }
    }
    tab[i] = mini;
  }
  return tab;
}

bool est_present(int n, int *tab, int longueur) {
  for (int i = 0; i < longueur; i++) {
    if (tab[i] == n) return true;
  }
  return false;
}

bool tous_differents(int *mat[]) {
  int *temp = malloc(sizeof(int) * N * M);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (est_present(mat[i][j], temp, N * M)) return false;
      temp[i * N + j] = mat[i][j];
    }
  }
  return true;
}

bool connecte(int *mat[], int i, int j) {
  for (int x = i - 1; x <= i + 1; x++) {
    for (int y = j - 1; y <= j + 1; y++) {
      if (mat[x][y] && !(x == i && y == j) && x >= 0 && x < N && y >= 0 &&
          y < N)
        return true;
    }
  }
  return false;
}

bool connexe(bool *mat[]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (mat[i][j] && !connecte(mat, i, j)) return false;
    }
  }
  return true;
}
