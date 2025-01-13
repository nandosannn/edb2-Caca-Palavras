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
                matriz[contadorLinha][contadorColuna] = tolower(letra);
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

void busca_horizontal(char** matriz, int linha, int coluna, No_trie* arvore_trie, No** arvore_avl){
    char palavra[50];
    int posicao_de_insercao_do_caractere = 0;
    int posicao_inicial_palavra = 0;

    for (int i = 0; i < linha; i++)
    {
        while (posicao_inicial_palavra < coluna){
           
            for (int j = posicao_inicial_palavra; j < coluna; j++)
            {
                palavra[posicao_de_insercao_do_caractere++] = matriz[i][j];
                palavra[posicao_de_insercao_do_caractere] = '\0';
                int valor = buscar_trie(arvore_trie, palavra);

                if(valor == 1)
                {
                    *arvore_avl = inserir_no_avl(*arvore_avl, palavra);
                    j = coluna;
                }else if(valor == -1)
                {
                    j = coluna;
                }
            }

            palavra[0] = '\0';
            posicao_de_insercao_do_caractere = 0;
            posicao_inicial_palavra++;
        }

        posicao_inicial_palavra = 0;
    } 
}
