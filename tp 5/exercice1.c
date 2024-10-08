#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20
#define MAX_VAL 30.0

typedef struct point2d point2d;

struct point2d {
  double x, y;
};

void remplit_tab(point2d tab[]) {
  for (int i = 0; i < N; i++) {
    tab[i].x = (double)rand() / (double)(RAND_MAX / MAX_VAL);
    tab[i].y = (double)rand() / (double)(RAND_MAX / MAX_VAL);
  }
}

double distance(point2d p1, point2d p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
};

double distance_origine(point2d p1) { return sqrt(p1.x * p1.x + p1.y * p1.y); }

point2d plus_proche_origine(point2d *tab) {
  point2d mini = tab[0];
  double mini_dist = distance_origine(mini);
  for (int i = 1; i < N; i++) {
    double dist = distance_origine(tab[i]);
    if (dist < mini_dist) {
      mini = tab[i];
      mini_dist = dist;
    }
  }
  return mini;
}

point2d *cree_tab_points() {
  point2d *tab = malloc(sizeof(point2d) * N);
  return tab;
}

void affiche_point(point2d p) { printf("[%.2lf,%.2lf]", p.x, p.y); }

void affiche_tab_points(point2d *tab) {
  printf("[\n");
  for (int i = 0; i < N; i++) {
    printf("\t");
    affiche_point(tab[i]);
    if (i < N - 1) printf(",\n");
  }
  printf("\n]\n");
}

point2d *couple_plus_proche(point2d *tab) {
  point2d *couple_mini = malloc(sizeof(point2d) * 2);
  couple_mini[0] = tab[0];
  couple_mini[1] = tab[1];
  double dist_mini = distance(tab[0],tab[1]);
  for (int i = 0; i < N; i++) {
    point2d plus_proche_de_i = tab[i + 1];
    double dist_mini_i = distance(tab[i], tab[i + 1]);

    for (int j = i + 2; j < N; j++) {
      double dist = distance(tab[i], tab[j]);
      if (dist < dist_mini_i) {
        dist_mini_i = dist;
        plus_proche_de_i = tab[j];
      }
    }

    if(dist_mini_i < dist_mini) {
      couple_mini[0] = tab[i];
      couple_mini[1] = plus_proche_de_i;
    }
  }
  return couple_mini;
} // TODO Modulariser

int main() {
  srand(time(NULL));

  point2d *tab = cree_tab_points();
  remplit_tab(tab);
  affiche_tab_points(tab);

  // printf("point le plus proche de l'origine :");
  // affiche_point(plus_proche_origine(tab));
  // printf("\n");

  printf("couple le plus proche : \n");
  point2d *couple = couple_plus_proche(tab);
  affiche_point(couple[0]);
  printf("et \n");
  affiche_point(couple[1]);
  free(tab);
  return 0;
}