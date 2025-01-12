#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char* dado;
    struct No* esquerdo;
    struct No* direito;
    int altura;
} No;


int obter_altura(No* no);

int calcular_fator_de_balanceamento(No* no);

No* criar_no_avl(char* dado);

No* rotacao_direita(No* y);

No* rotacao_esquerda(No* x);

No* inserir_no_avl(No* no, const char* dado);

void imprimir_em_ordem(No* raiz);



