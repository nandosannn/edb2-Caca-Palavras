#include "../include/util.h"
#include <stdlib.h>

FILE *abrirArquivo(char *nomeDoArquivo, const char *tipoDeAbertura){
    FILE *arquivo = fopen(nomeDoArquivo, tipoDeAbertura);

    if(arquivo == NULL){
        printf("Erro ao abrir arquivo");
    }

    return arquivo;
}

void alocarMatrizTabuleiro(char ***matriz, int linhas, int colunas){
    *matriz = (char **)malloc(linhas * sizeof(char *));
    for (int i = 0; i < linhas; i++) {
        (*matriz)[i] = (char *)malloc(colunas * sizeof(char));
    }
}

void lerTamanhoDoTabuleiro(char *nomeDoArquivo, int indices_matriz[]){
    FILE *arquivo = abrirArquivo(nomeDoArquivo, "r");

    if(arquivo){
        int numero;
        int contadorDeNumeros = 0;

        while(fscanf(arquivo, "%d", &numero) == 1){
            indices_matriz[contadorDeNumeros] = numero;
            contadorDeNumeros++;

            if(contadorDeNumeros == 2){
                break;
            }
        } 
    }
}

void imprimirMatriz(char **matriz, int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%c", matriz[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}