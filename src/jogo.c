#include "../include/jogo.h"
#include <ctype.h>

void ler_palavras(No_trie *raiz, char *nomeDoArquivo){
    FILE* arquivo = abrirArquivo(nomeDoArquivo, "r");

    if(arquivo){
        char palavra[50];
        while(fscanf(arquivo, "%s", palavra) == 1) inserir_trie(raiz, palavra);
    }
}

void ler_tabuleiro(char *nomeDoArquivo, int linhas, int colunas, char **matriz){
    FILE* arquivo = abrirArquivo(nomeDoArquivo, "r");

    if(arquivo){
        char letra;
        int contadorLinha = 0;
        int contadorColuna = 0;

        while(fscanf(arquivo, "%c", &letra) == 1){
            if(!isspace(letra) && !isdigit(letra)){
                matriz[contadorLinha][contadorColuna] = letra;
                contadorColuna++;

                if(contadorColuna == colunas){
                    contadorColuna = 0;
                    contadorLinha++;
                }

                if(contadorLinha == linhas){
                    break;
                }
            } 
        }
    }

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%c", matriz[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}

// void busca_horizontal(char** matriz, int linha, int coluna, No* arvore_avl, No_trie* arvore_trie){
//     char k = 0;
//     char* string[k];
//     int linhas_aux = 0;
//     int colunas_aux = 0;

//     for (int i = linhas_aux; i < linha; i++)
//     {
//         for (int j = 0; j < coluna; j++)
//         {
//             string[k]=matriz[i][j];
//             k++;
//         }
//     } 
// }