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
    
    int entrada;
    do
    {
        menu();
        entrada = leitor_de_numeros();

        switch (entrada)
        {
        case 1:
            printf("=== Tabuleiro do Jogo ===\n\n");
            imprimirMatriz(matriz, indices_matriz[0], indices_matriz[1]);
            break;
        case 2:
            printf("Procurando palavras...\n");
            busca_horizontal(matriz, indices_matriz[0], indices_matriz[1], raiz_trie, &raiz_avl);
            busca_vertical(matriz, indices_matriz[0], indices_matriz[1], raiz_trie, &raiz_avl);
            busca_diagonal(matriz, indices_matriz[0], indices_matriz[1], raiz_trie, &raiz_avl);
            break;
        case 3:
            printf("Palavras encontradas em ordem:\n");
            imprimir_em_ordem(raiz_avl);
            break;
        case 4:
            printf("Saindo...\n");
            break;

        default:
            break;
        }
    } while (entrada != 4);

    //Liberar memória
    for (int i = 0; i < indices_matriz[0]; i++) {
        free(matriz[i]);
    }

    free(matriz);
    liberar_trie(raiz_trie);
    liberar_avl(raiz_avl);

    return 0;
}
