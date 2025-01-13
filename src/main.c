#include <stdio.h>
#include "../include/jogo.h"

int main(){
    char *nomeDoArquivoPalavras = "data/palavras.txt";
    char * nomeDoArquivoTabuleiro = "data/tabuleiro.txt";
    No_trie *raiz = criar_no_trie();
    No* raiz_avl = NULL;
    ler_palavras(raiz, nomeDoArquivoPalavras);


    //const char *palavras[] = {"ganimedes", "calisto", "io", "metis", "adrasteia", "ananke", "carme", "pheme", "europa", "himalia", "elara", "pasifae", "sinope", "leda", "agape"}; 
    // for(int i = 0; i < 15; i++){
    //     if(buscar_trie(raiz, palavras[i])) printf("Palavra %s encontrada!\n", palavras[i]);
    //     else printf("Palavra %s não encontrada!\n", palavras[i]);
    // }

    int indices_matriz[2];
    char **matriz;

    lerTamanhoDoTabuleiro(nomeDoArquivoTabuleiro, indices_matriz);
    alocarMatrizTabuleiro(&matriz, indices_matriz[0], indices_matriz[1]);
    ler_tabuleiro(nomeDoArquivoTabuleiro, indices_matriz[0], indices_matriz[1], matriz);

    busca_horizontal(matriz, indices_matriz[0], indices_matriz[1], raiz, &raiz_avl);
    busca_vertical(matriz, indices_matriz[0], indices_matriz[1], raiz, &raiz_avl);
    imprimir_em_ordem(raiz_avl);

    //Liberar memória
    for (int i = 0; i < indices_matriz[0]; i++) {
        free(matriz[i]);
    }

    free(matriz);

    liberar_trie(raiz);
    liberar_avl(raiz_avl);

    return 0;


   

    return 0;
}
