#include <stdlib.h>
#include <string.h>
#include "../include/trie.h"
#include "../include/util.h"

No_trie *criar_no(){
    No_trie *novo_no = (No_trie *)malloc(sizeof(No_trie));

    if(novo_no){
        novo_no->fim_da_palavra = false;
        for(int i = 0; i < NUMERO_DE_LETRAS; i++) novo_no->filhos[i] = NULL;
    }

    return novo_no;
}

void inserir_trie(No_trie *raiz, const char *palavra){
    No_trie *atual = raiz;

    for(int i = 0; palavra[i] != '\0'; i++){
        int indice = palavra[i] - 'a';

        if(atual->filhos[indice] == NULL) atual->filhos[indice] = criar_no();

        atual = atual->filhos[indice];
    }

    atual->fim_da_palavra = true;
}

int buscar_trie(No_trie *raiz, const char *palavra){
    No_trie *atual = raiz;

    for(int i = 0; palavra[i] != '\0'; i++){
        int indice = palavra[i] - 'a';

        if(atual->filhos[indice] == NULL) return -1;

        atual = atual->filhos[indice];
    }

    if(atual->fim_da_palavra) return 1;
    else return 0;
}

void liberar_trie(No_trie *raiz){
    if(raiz == NULL) return;

    for(int i = 0; i < NUMERO_DE_LETRAS; i++) liberar_trie(raiz->filhos[i]);

    free(raiz);
}