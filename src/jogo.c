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

void busca_horizontal(char** matriz, int linha, int coluna, No_trie* arvore_trie, No* arvore_avl){
    char vetor[50];
    int k = 0;
    int coluna_aux = 0;

    for (int i = 0; i < linha; i++)
    {
        while (coluna_aux != coluna){
           

            for (int j = coluna_aux; j < coluna; j++)
            {
                vetor[k++] = matriz[i][j];
                vetor[k] = '\0';
                printf("palavra: %s \n", vetor);
                int valor = buscar_trie(arvore_trie, vetor);
                //printf("valor do resultado: %d \n", valor);

                if (valor == 1)
                {
                    arvore_avl = inserir_no_avl(arvore_avl, vetor);
                    printf("%s inserido na arvore", vetor);
                }
                else
                {
                    break;
                }
            }

            coluna_aux++;
            //printf("valor coluna_aux: %d\n",coluna_aux);
        }

        coluna_aux=0;
        k=0;
        vetor[k]='\0';
    } 

    // for (int i = 0; i < linha; i++)
    // {
    //     printf("%c ", vetor[i]);
    // }
    
}
