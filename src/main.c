#include <stdio.h>
#include "../include/jogo.h"

int main(){
    char *nomeDoArquivoPalavras = "data/palavras.txt";
    char * nomeDoArquivoTabuleiro = "data/tabuleiro.txt";
    /*No *raiz = criar_no();

    const char *palavras[] = {"ganimedes", "calisto", "io", "metis", "adrasteia", "ananke", "carme", "pheme", "europa", "himalia", "elara", "pasifae", "sinope", "leda", "agape"}; 

    ler_palavras(raiz, nomeDoArquivoPalavras);

    for(int i = 0; i < 15; i++){
        if(buscar(raiz, palavras[i])) printf("Palavra %s encontrada!\n", palavras[i]);
        else printf("Palavra %s não encontrada!\n", palavras[i]);
    }*/

    int indices_matriz[2];
    char **matriz;

    lerTamanhoDoTabuleiro(nomeDoArquivoTabuleiro, indices_matriz);
    alocarMatrizTabuleiro(&matriz, indices_matriz[0], indices_matriz[1]);
    ler_tabuleiro(nomeDoArquivoTabuleiro, indices_matriz[0], indices_matriz[1], matriz);
    
    return 0;
}
