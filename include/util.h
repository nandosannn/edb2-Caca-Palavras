#include <stdio.h>

void menu();

void limpador_de_buffer();

int leitor_de_numeros();

FILE* abrirArquivo(char* nomeDoArquivo, const char *tipoDeAbertura);

void alocarMatrizTabuleiro(char ***matriz_tabuleiro, int linhas, int colunas);

void lerTamanhoDoTabuleiro(char *nomeDoArquivo, int indices_matriz[]);

void imprimirMatriz(char **matriz_tabuleiro, int linhas, int colunas);