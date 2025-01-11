#include <stdbool.h>

#define NUMERO_DE_LETRAS 26

typedef struct No{
  struct No *filhos[NUMERO_DE_LETRAS];
  bool fim_da_palavra;
}No;

No *criar_no();
void inserir(No *raiz, const char *palavra);
bool buscar(No *raiz, const char *palavra);
void liberar_trie(No *raiz);