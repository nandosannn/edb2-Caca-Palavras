#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALFABETO 26

typedef struct No{
  struct No *filhos[ALFABETO];
  bool fim_da_palavra;
}No;