#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  printf("Bonjour tout le monde !\n%d",argc);
  return EXIT_SUCCESS;
}

/*
il ne se passe rien si on enleve return (dans ce contexte)

EXIT_SUCCESS nécessite la librairie standard stdlib.h
*/