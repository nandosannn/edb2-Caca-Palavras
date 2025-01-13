#include "../include/util.h"
#include <stdlib.h>

void menu(){
    printf("\n======== MENU PRINCIPAL ========\n\n");

    printf("Selecione uma das operacoes abaixo:\n");

    printf("1 - Imprimir tabuleiro\n");
    printf("2 - Procurar Palavras\n");
    printf("3 - Imprimir palavras encontradas na ordem\n");
    printf("4 - Sair\n");

    printf("\nDigite o numero da operacao desejada: ");
}

void limpador_de_buffer(){
    while (getchar() != '\n');
}

int leitor_de_numeros(){
    int numero;
    int resultado;

    resultado = scanf("%d", &numero);

    if(resultado != 1 || numero <= 0 || numero >= 500000){
        printf("Numero invalido!\nDigite o numero novamente: ");
        limpador_de_buffer();
        return leitor_de_numeros();
    }

    limpador_de_buffer();
    return numero;
}

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