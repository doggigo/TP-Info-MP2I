#include <stdio.h>
int mystere(int *x, int *y)
{
  *x = *x - *y;
  *y = *x + *y;
  *x = *y - *x;
}

int main()
{
  int x3 = 3;
  mystere(&x3, &x3);
  printf("x3 = %d \n", x3);
  return 0;
}
