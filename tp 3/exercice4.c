#include <stdio.h>

int main(void)
{
  int n = 0;
  float x = 0.;
  float y = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%f %f", &x, &y);
    printf("%f \n", x + y);
  }
  return 0;
}