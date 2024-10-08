#include <stdio.h>

int max2_moche(int a, int b) {
  if (a > b)
    return a;
  return b;
}

int max2(int a, int b) {
  return a > b ? a : b;
}

int max3_moche(int a, int b, int c) {
  if (a > b)
  {
    if (a > c)
      return a;
    return c;
  }
  else if (b > c)
  {
    return b;
  }
  return c;
}

int max3(int a, int b, int c) {
  return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

int main(void) {
  printf("max2(3,89) = %d\n", max2(3, 89));
  return 0;
}
