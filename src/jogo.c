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
}

void busca_horizontal(char** matriz, int linha, int coluna, No_trie* arvore_trie, No** arvore_avl){
    char palavra[50];
    int posicao_insercao_caracter = 0;
    int posicao_inicial_palavra = 0;

    for(int i = 0; i < linha; i++){

        while(posicao_inicial_palavra < coluna){
           
            for(int j = posicao_inicial_palavra; j < coluna; j++){

                palavra[posicao_insercao_caracter++] = matriz[i][j];
                palavra[posicao_insercao_caracter] = '\0';
                int valor = buscar_trie(arvore_trie, palavra);

                if(valor == 1){
                    *arvore_avl = inserir_no_avl(*arvore_avl, palavra);
                    j = coluna;
                }else if(valor == -1) j = coluna;
            }

            palavra[0] = '\0';
            posicao_insercao_caracter = 0;
            posicao_inicial_palavra++;
        }

        posicao_inicial_palavra = 0;
    } 

    posicao_inicial_palavra = coluna - 1;
    posicao_insercao_caracter = 0;

    for(int i = 0; i < linha; i++){

        while(posicao_inicial_palavra >= 0){
           
            for (int j = posicao_inicial_palavra; j >= 0; j--){

                palavra[posicao_insercao_caracter++] = matriz[i][j];
                palavra[posicao_insercao_caracter] = '\0';
                int valor = buscar_trie(arvore_trie, palavra);

                if (valor == 1){
                    *arvore_avl = inserir_no_avl(*arvore_avl, palavra);
                    j = -1;
                }else if(valor == -1) j = -1;
            }

            palavra[0] = '\0';
            posicao_insercao_caracter = 0;
            posicao_inicial_palavra--;
        }

        posicao_inicial_palavra = coluna - 1;
    } 
}

void busca_vertical(char** matriz, int linha, int coluna, No_trie* arvore_trie, No** arvore_avl){
    char palavra[50];
    int posicao_insercao_caracter = 0;
    int posicao_inicial_palavra = 0;

    for(int i = 0; i < coluna; i++){

        while(posicao_inicial_palavra < linha){
           
            for(int j = posicao_inicial_palavra; j < linha; j++){

                palavra[posicao_insercao_caracter++] = matriz[j][i];
                palavra[posicao_insercao_caracter] = '\0';
                int valor = buscar_trie(arvore_trie, palavra);

                if(valor == 1){
                    *arvore_avl = inserir_no_avl(*arvore_avl, palavra);
                    j = linha;
                }else if(valor == -1) j = linha;
            }

            palavra[0] = '\0';
            posicao_insercao_caracter = 0;
            posicao_inicial_palavra++;
        }

        posicao_inicial_palavra = 0;
    } 

    posicao_inicial_palavra = linha - 1;
    posicao_insercao_caracter = 0;

    for(int i = 0; i < coluna; i++){

        while(posicao_inicial_palavra >= 0){
           
            for (int j = posicao_inicial_palavra; j >= 0; j--){

                palavra[posicao_insercao_caracter++] = matriz[j][i];
                palavra[posicao_insercao_caracter] = '\0';
                int valor = buscar_trie(arvore_trie, palavra);

                if (valor == 1){
                    *arvore_avl = inserir_no_avl(*arvore_avl, palavra);
                    j = -1;
                }else if(valor == -1) j = -1;
            }

            palavra[0] = '\0';
            posicao_insercao_caracter = 0;
            posicao_inicial_palavra--;
        }

        posicao_inicial_palavra = linha - 1;
    } 
}

void busca_diagonal(char** matriz, int coluna, int linha, No_trie* arvore_trie, No** arvore_avl){
    char palavra[50];
    int posicao_insercao_caracter = 0;
    int posicao_inicial_palavra = 0;

    for(int h = 0; h < linha; h++){

        while(posicao_inicial_palavra < linha){

            for(int l = posicao_inicial_palavra; l < linha - h; l++){

                palavra[posicao_insercao_caracter++] = matriz[l + h][l];
                palavra[posicao_insercao_caracter] = '\0';
                int valor = buscar_trie(arvore_trie, palavra);

                if (valor == 1){
                    *arvore_avl = inserir_no_avl(*arvore_avl, palavra);
                    l = linha;
                }else if(valor == -1) l = linha;
            }

            palavra[0] = '\0';
            posicao_insercao_caracter = 0;
            posicao_inicial_palavra++;
        }

        posicao_inicial_palavra = 0;
    }

    posicao_inicial_palavra = linha - 1;
    posicao_insercao_caracter = 0;

    for(int h = 0; h < linha; h++){

        while(posicao_inicial_palavra >= 0){

            for(int l = posicao_inicial_palavra; l - h >= 0; l--){

                palavra[posicao_insercao_caracter++] = matriz[l][l - h];
                palavra[posicao_insercao_caracter] = '\0';
                int valor = buscar_trie(arvore_trie, palavra);

                if (valor == 1){
                    *arvore_avl = inserir_no_avl(*arvore_avl, palavra);
                    l = -1;
                }else if(valor == -1) l = -1;
            }

            palavra[0] = '\0';
            posicao_insercao_caracter = 0;
            posicao_inicial_palavra--;
        }

        posicao_inicial_palavra = linha - 1;
    }

    posicao_insercao_caracter = 0;
    posicao_inicial_palavra = 0;

    for(int h = 1; h < linha; h++){

        while(posicao_inicial_palavra < linha){

            for(int l = posicao_inicial_palavra; l < linha - h; l++){

                palavra[posicao_insercao_caracter++] = matriz[l][l + h];
                palavra[posicao_insercao_caracter] = '\0';
                int valor = buscar_trie(arvore_trie, palavra);

                if (valor == 1){
                    *arvore_avl = inserir_no_avl(*arvore_avl, palavra);
                    l = linha;
                }else if(valor == -1) l = linha;
            }

            palavra[0] = '\0';
            posicao_insercao_caracter = 0;
            posicao_inicial_palavra++;
        }

        posicao_inicial_palavra = 0;
    }

    posicao_inicial_palavra = linha - 1;
    posicao_insercao_caracter = 0;

    for(int h = 1; h < linha; h++){

        while(posicao_inicial_palavra >= 0){

            for(int l = posicao_inicial_palavra; l - h >= 0; l--){

                palavra[posicao_insercao_caracter++] = matriz[l - h][l];
                palavra[posicao_insercao_caracter] = '\0';
                int valor = buscar_trie(arvore_trie, palavra);

                if (valor == 1){
                    *arvore_avl = inserir_no_avl(*arvore_avl, palavra);
                    l = -1;
                }else if(valor == -1) l = -1;
            }

            palavra[0] = '\0';
            posicao_insercao_caracter = 0;
            posicao_inicial_palavra--;
        }

        posicao_inicial_palavra = linha - 1;
    }

    posicao_insercao_caracter = 0;
    posicao_inicial_palavra = 0;

    for(int h = coluna - 1; h >= 0; h--){

        while(posicao_inicial_palavra < coluna){

            for(int c = posicao_inicial_palavra; c <= h; c++){

                palavra[posicao_insercao_caracter++] = matriz[c][h - c];
                palavra[posicao_insercao_caracter] = '\0';
                int valor = buscar_trie(arvore_trie, palavra);

                if (valor == 1){
                    *arvore_avl = inserir_no_avl(*arvore_avl, palavra);
                    c = coluna;
                }else if(valor == -1) c = coluna;
            }

            palavra[0] = '\0';
            posicao_insercao_caracter = 0;
            posicao_inicial_palavra++;
        }

        posicao_inicial_palavra = 0;
    }

    posicao_insercao_caracter = 0;
    posicao_inicial_palavra = 0;

    for(int h = coluna - 1; h >= 0; h--){

        while(posicao_inicial_palavra < coluna){

            for(int c = posicao_inicial_palavra; c <= h; c++){

                palavra[posicao_insercao_caracter++] = matriz[h - c][c];
                palavra[posicao_insercao_caracter] = '\0';
                int valor = buscar_trie(arvore_trie, palavra);

                if (valor == 1){
                    *arvore_avl = inserir_no_avl(*arvore_avl, palavra);
                    c = coluna;
                }else if(valor == -1) c = coluna;
            }

            palavra[0] = '\0';
            posicao_insercao_caracter = 0;
            posicao_inicial_palavra++;
        }

        posicao_inicial_palavra = 0;
    }

    posicao_insercao_caracter = 0;
    posicao_inicial_palavra = coluna - 1;

    for(int h = 1; h < coluna; h++){

        while(posicao_inicial_palavra >= 0){

            for(int c = posicao_inicial_palavra; c >= h; c--){

                palavra[posicao_insercao_caracter++] = matriz[h + ((coluna - 1) - c)][c];
                palavra[posicao_insercao_caracter] = '\0';
                int valor = buscar_trie(arvore_trie, palavra);

                if (valor == 1){
                    *arvore_avl = inserir_no_avl(*arvore_avl, palavra);
                    c = -1;
                }else if(valor == -1) c = -1;
            }

            palavra[0] = '\0';
            posicao_insercao_caracter = 0;
            posicao_inicial_palavra--;
        }

        posicao_inicial_palavra = coluna - 1;
    }

    posicao_insercao_caracter = 0;
    posicao_inicial_palavra = coluna - 1;

    for(int h = 1; h < coluna; h++){

        while(posicao_inicial_palavra >= 0){

            for(int c = posicao_inicial_palavra; c >= h; c--){

                palavra[posicao_insercao_caracter++] = matriz[c][h + ((coluna - 1) - c)];
                palavra[posicao_insercao_caracter] = '\0';
                int valor = buscar_trie(arvore_trie, palavra);

                if (valor == 1){
                    *arvore_avl = inserir_no_avl(*arvore_avl, palavra);
                    c = -1;
                }else if(valor == -1) c = -1;
            }

            palavra[0] = '\0';
            posicao_insercao_caracter = 0;
            posicao_inicial_palavra--;
        }

        posicao_inicial_palavra = coluna - 1;
    }
}
