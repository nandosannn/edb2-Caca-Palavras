#include "trie.h"
#include "avl.h"
#include "util.h"
#include <string.h>

void ler_palavras(No_trie *raiz, char *nomeDoArquivo);

void ler_tabuleiro(char *nomeDoArquivo, int linhas, int colunas, char **matriz_tabuleiro);

void busca_horizontal(char** matriz_tabuleiro, int linha, int coluna, No_trie* arvore_trie, No** arvore_avl);

void busca_vertical(char** matriz_tabuleiro, int linha, int coluna, No_trie* arvore_trie, No** arvore_avl);

void busca_diagonal(char** matriz_tabuleiro, int linha, int coluna, No_trie* arvore_trie, No** arvore_avl);