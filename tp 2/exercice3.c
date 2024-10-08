#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool bissextile(int a)
{
  return ((a % 4 == 0) && (a % 100 != 0)) || (a % 400 == 0);
}

bool date_correcte(unsigned int j, unsigned int m, int a)
{
  int nb_jours[] = {31, bissextile(m) ? 28 : 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  return m <= 12 && m >= 1 && j <= nb_jours[m - 1];
}

int *jour_suivant(int j, int m, int a)
{
  int *res = (int *)malloc(sizeof(int) * 3);
  if (date_correcte(j + 1, m, a)) {
    res[0] = j + 1;
    res[1] = m;
    res[2] = a;
    return res;
  }

  if (m < 12) {

    res[0] = 1;
    res[1] = m + 1;
    res[2] = a;
    return res;
  }
  else {
    res[0] = 1;
    res[1] = 1;
    res[2] = a + 1;
    return res;
  }
}

int main(int argc, char const *argv[])
{
  int *next_day = jour_suivant(01, 01, 2024);
  for (int i = 0; i < 366; i++) {
    printf("%02d-%02d-%04d \n", next_day[0], next_day[1], next_day[2]);
    next_day = jour_suivant(next_day[0], next_day[1], next_day[2]);
  }
  return 0;
}
