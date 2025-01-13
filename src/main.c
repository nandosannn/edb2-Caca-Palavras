#include <stdio.h>
#include "../include/jogo.h"

int main(){
    char *nomeDoArquivoPalavras = "data/palavras.txt";
    char * nomeDoArquivoTabuleiro = "data/tabuleiro.txt";
    int indices_matriz[2];
    char **matriz;
    No_trie *raiz_trie = criar_no_trie();
    No *raiz_avl = NULL;
    
    ler_palavras(raiz_trie, nomeDoArquivoPalavras);

    lerTamanhoDoTabuleiro(nomeDoArquivoTabuleiro, indices_matriz);
    alocarMatrizTabuleiro(&matriz, indices_matriz[0], indices_matriz[1]);
    ler_tabuleiro(nomeDoArquivoTabuleiro, indices_matriz[0], indices_matriz[1], matriz);
    imprimirMatriz(matriz, indices_matriz[0], indices_matriz[1]);

    busca_horizontal(matriz, indices_matriz[0], indices_matriz[1], raiz_trie, &raiz_avl);
    busca_vertical(matriz, indices_matriz[0], indices_matriz[1], raiz_trie, &raiz_avl);
    busca_diagonal(matriz, indices_matriz[0], indices_matriz[1], raiz_trie, &raiz_avl);
    imprimir_em_ordem(raiz_avl);

    //Liberar memória
    for (int i = 0; i < indices_matriz[0]; i++) {
        free(matriz[i]);
    }

    free(matriz);
    liberar_trie(raiz_trie);
    liberar_avl(raiz_avl);

    return 0;
}
