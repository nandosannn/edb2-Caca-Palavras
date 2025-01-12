#include <stdio.h>

FILE* abrirArquivo(char* nomeDoArquivo, const char *tipoDeAbertura);
void alocarMatrizTabuleiro(char ***matriz, int linhas, int colunas);
void lerTamanhoDoTabuleiro(char *nomeDoArquivo, int indices_matriz[]);