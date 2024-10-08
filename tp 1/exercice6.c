#include <stdio.h>

int main(int argc, char const *argv[])
{
  printf("Nombre d'arguments : %d\n",argc);
  printf("Arguments : \n[\n");
  for(int i = 0 ; i < argc ; i++) {
    printf("%s\n",argv[i]);
  }
  printf("]\n");
  return 0;
}

