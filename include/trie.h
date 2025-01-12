#include <stdbool.h>

#define NUMERO_DE_LETRAS 26

typedef struct No_trie{
  struct No_trie *filhos[NUMERO_DE_LETRAS];
  bool fim_da_palavra;
}No_trie;

No_trie *criar_no();
void inserir_trie(No_trie *raiz, const char *palavra);
int buscar_trie(No_trie *raiz, const char *palavra);
void liberar_trie(No_trie *raiz);