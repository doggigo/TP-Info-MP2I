## Question 1
Alloué dans la stack :
```c
#define N 5
#define M 5

void main() {
  int tab[N][M];
}
```

Alloué dans la heap :
```c
#include <stdlib.h>

int **cree_tab_2d(int N, int M) {
  int **tableau = (int **) malloc(sizeof(int *) * N);
  for(int i = 0 ; i < N ; i++) {
    tableau[i] = malloc(sizeof(int) * M);
  }
  return tableau;
}

void main() {
  int **tableau = cree_tab_2d(5,5);
}
```

Avec un tableau de dimension 1
```c
#define M 5;
#define N 5;
int get_elem(int *tab, int a, int b) {
  return tab[a * N + b];
}

int *cree_tab2d(int N, int M) {
  return (int *) malloc(sizeof(int) * N * M);
}