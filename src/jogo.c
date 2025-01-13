#include "../include/jogo.h"
#include <ctype.h>

void ler_palavras(No_trie *raiz, char *nomeDoArquivo){
    FILE* arquivo = abrirArquivo(nomeDoArquivo, "r");

    if(arquivo){
        char palavra[50];
        while(fscanf(arquivo, "%s", palavra) == 1) inserir_trie(raiz, palavra);
    }
}

void ler_tabuleiro(char *nomeDoArquivo, int linhas, int colunas, char **matriz_tabuleiro){
    FILE* arquivo = abrirArquivo(nomeDoArquivo, "r");

    if(arquivo){
        char letra;
        int contadorLinha = 0;
        int contadorColuna = 0;

        while(fscanf(arquivo, "%c", &letra) == 1){
            if(!isspace(letra) && !isdigit(letra)){
                matriz_tabuleiro[contadorLinha][contadorColuna] = tolower(letra);
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

void busca_horizontal(char** matriz_tabuleiro, int linha, int coluna, No_trie* arvore_trie, No** arvore_avl){
    char palavra[50];
    int posicao_insercao_caracter = 0;
    int posicao_inicial_palavra = 0;

    for(int i = 0; i < linha; i++){

        while(posicao_inicial_palavra < coluna){
           
            for(int j = posicao_inicial_palavra; j < coluna; j++){

                palavra[posicao_insercao_caracter++] = matriz_tabuleiro[i][j];
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

                palavra[posicao_insercao_caracter++] = matriz_tabuleiro[i][j];
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

void busca_vertical(char** matriz_tabuleiro, int linha, int coluna, No_trie* arvore_trie, No** arvore_avl){
    char palavra[50];
    int posicao_insercao_caracter = 0;
    int posicao_inicial_palavra = 0;

    for(int i = 0; i < coluna; i++){

        while(posicao_inicial_palavra < linha){
           
            for(int j = posicao_inicial_palavra; j < linha; j++){

                palavra[posicao_insercao_caracter++] = matriz_tabuleiro[j][i];
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

                palavra[posicao_insercao_caracter++] = matriz_tabuleiro[j][i];
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

void busca_diagonal(char** matriz_tabuleiro, int linha, int coluna, No_trie* arvore_trie, No** arvore_avl){
    char palavra[50];
    int posicao_insercao_caracter = 0;
    int posicao_inicial_palavra = 0;
    int tamanho_limite_da_palavra;

    if(linha < coluna){
        tamanho_limite_da_palavra = linha;
    }else if(coluna < linha){
        tamanho_limite_da_palavra = coluna;
    }else{
        tamanho_limite_da_palavra = linha;
    }

    for(int h = 0; h < linha; h++){

        while(posicao_inicial_palavra < tamanho_limite_da_palavra){

            for(int i = posicao_inicial_palavra; i < linha - h; i++){

                palavra[posicao_insercao_caracter++] = matriz_tabuleiro[i + h][i];
                palavra[posicao_insercao_caracter] = '\0';
                int valor = buscar_trie(arvore_trie, palavra);

                if (valor == 1){
                    *arvore_avl = inserir_no_avl(*arvore_avl, palavra);
                    break;
                }else if(valor == -1) break;
            }

            palavra[0] = '\0';
            posicao_insercao_caracter = 0;
            posicao_inicial_palavra++;
        }

        posicao_inicial_palavra = 0;
    }

    posicao_inicial_palavra = linha - 1;
    posicao_insercao_caracter = 0;
    int inicializador_de_pulador = 0;
    if(linha > coluna){
        inicializador_de_pulador = linha - coluna;
    }

    for(int h = inicializador_de_pulador; h < linha; h++){

        while(posicao_inicial_palavra >= 0){

            for(int i = posicao_inicial_palavra; i - h >= 0; i--){

                palavra[posicao_insercao_caracter++] = matriz_tabuleiro[i][i - h];
                palavra[posicao_insercao_caracter] = '\0';
                int valor = buscar_trie(arvore_trie, palavra);

                if (valor == 1){
                    *arvore_avl = inserir_no_avl(*arvore_avl, palavra);
                    break;
                }else if(valor == -1) break;
            }

            palavra[0] = '\0';
            posicao_insercao_caracter = 0;
            posicao_inicial_palavra--;
        }

        posicao_inicial_palavra = linha - 1;
    }

    posicao_insercao_caracter = 0;
    posicao_inicial_palavra = 0;
    inicializador_de_pulador = 0;
    if(linha < coluna){
        inicializador_de_pulador = coluna - linha;
    }

    for(int h = inicializador_de_pulador; h < coluna; h++){

        while(posicao_inicial_palavra < linha){

            for(int i = posicao_inicial_palavra; i < coluna - h; i++){

                palavra[posicao_insercao_caracter++] = matriz_tabuleiro[i][i + h];
                palavra[posicao_insercao_caracter] = '\0';
                int valor = buscar_trie(arvore_trie, palavra);

                if (valor == 1){
                    *arvore_avl = inserir_no_avl(*arvore_avl, palavra);
                    break;
                }else if(valor == -1) break;
            }

            palavra[0] = '\0';
            posicao_insercao_caracter = 0;
            posicao_inicial_palavra++;
        }

        posicao_inicial_palavra = 0;
    }

    posicao_inicial_palavra = coluna - 1;
    posicao_insercao_caracter = 0;
    inicializador_de_pulador = 0;
    if(linha > coluna){
        inicializador_de_pulador = linha - coluna;
    }else if(coluna > linha){
        inicializador_de_pulador = coluna - linha;
    }

    for(int h = inicializador_de_pulador; h < coluna; h++){

        while(posicao_inicial_palavra >= 0){

            for(int i = posicao_inicial_palavra; i - h >= 0; i--){

                palavra[posicao_insercao_caracter++] = matriz_tabuleiro[i - h][i];
                palavra[posicao_insercao_caracter] = '\0';
                int valor = buscar_trie(arvore_trie, palavra);

                if (valor == 1){
                    *arvore_avl = inserir_no_avl(*arvore_avl, palavra);
                    break;
                }else if(valor == -1) break;
            }

            palavra[0] = '\0';
            posicao_insercao_caracter = 0;
            posicao_inicial_palavra--;
        }

        posicao_inicial_palavra = coluna - 1;
    }

    posicao_insercao_caracter = 0;
    posicao_inicial_palavra = 0;

    for(int h = tamanho_limite_da_palavra - 1; h >= 0; h--){

        while(posicao_inicial_palavra < coluna){

            for(int i = posicao_inicial_palavra; i <= h; i++){

                palavra[posicao_insercao_caracter++] = matriz_tabuleiro[i][h - i];
                palavra[posicao_insercao_caracter] = '\0';
                int valor = buscar_trie(arvore_trie, palavra);

                if (valor == 1){
                    *arvore_avl = inserir_no_avl(*arvore_avl, palavra);
                    break;
                }else if(valor == -1) break;
            }

            palavra[0] = '\0';
            posicao_insercao_caracter = 0;
            posicao_inicial_palavra++;
        }
        posicao_inicial_palavra = 0;
    }

    posicao_insercao_caracter = 0;
    posicao_inicial_palavra = 0;

    for(int h = linha - 1; h >= 0; h--){

        while(posicao_inicial_palavra < coluna){

            for(int i = posicao_inicial_palavra; i <= h; i++){

                palavra[posicao_insercao_caracter++] = matriz_tabuleiro[h - i][i];
                palavra[posicao_insercao_caracter] = '\0';
                int valor = buscar_trie(arvore_trie, palavra);

                if (valor == 1){
                    *arvore_avl = inserir_no_avl(*arvore_avl, palavra);
                    break;
                }else if(valor == -1) break;
            }

            palavra[0] = '\0';
            posicao_insercao_caracter = 0;
            posicao_inicial_palavra++;
        }

        posicao_inicial_palavra = 0;
    }

    posicao_insercao_caracter = 0;
    posicao_inicial_palavra = coluna - 1;
    inicializador_de_pulador = 0;
    if(coluna > linha){
        inicializador_de_pulador = coluna - linha;
    }else if(linha > coluna){
        inicializador_de_pulador = linha - coluna;
    }

    for(int h = inicializador_de_pulador; h <= linha; h++){

        while(posicao_inicial_palavra >= 0){

            for(int i = posicao_inicial_palavra; i >= h; i--){

                palavra[posicao_insercao_caracter++] = matriz_tabuleiro[h + ((linha - 1) - i)][i];
                palavra[posicao_insercao_caracter] = '\0';
                int valor = buscar_trie(arvore_trie, palavra);

                if (valor == 1){
                    *arvore_avl = inserir_no_avl(*arvore_avl, palavra);
                    break;
                }else if(valor == -1) break;
            }

            palavra[0] = '\0';
            posicao_insercao_caracter = 0;
            posicao_inicial_palavra--;
        }

        posicao_inicial_palavra = coluna - 1;
    }

    posicao_insercao_caracter = 0;
    posicao_inicial_palavra = linha - 1;

    for(int h = 0; h <= coluna; h++){

        while(posicao_inicial_palavra >= 0){

            for(int i = posicao_inicial_palavra; i >= h; i--){

                palavra[posicao_insercao_caracter++] = matriz_tabuleiro[i][h + ((coluna - 1) - i)];
                palavra[posicao_insercao_caracter] = '\0';
                int valor = buscar_trie(arvore_trie, palavra);

                if (valor == 1){
                    *arvore_avl = inserir_no_avl(*arvore_avl, palavra);
                    break;
                }else if(valor == -1) break;
            }

            palavra[0] = '\0';
            posicao_insercao_caracter = 0;
            posicao_inicial_palavra--;
        }
        
        posicao_inicial_palavra = linha - 1;
    }
}