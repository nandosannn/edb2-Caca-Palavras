#include "trie.h"
#include "avl.h"
#include "util.h"
#include <string.h>

void ler_palavras(No_trie *raiz, char *nomeDoArquivo);
void ler_tabuleiro(char *nomeDoArquivo, int linhas, int colunas, char **matriz);
void busca_horizontal(char** matriz, int linha, int coluna, No* arvore_avl, No_trie* arvore_trie);