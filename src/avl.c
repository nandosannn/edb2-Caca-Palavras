
#include "../include/avl.h"
#include "../include/util.h"

int obter_altura(No* no) {
    if (no == NULL) {
        return -1;
    } else {
        return no->altura;
    }
}

int calcular_fator_de_balanceamento(No* no) {
    if (no == NULL) {
        return 0;
    } else {
        return obter_altura(no->esquerdo) - obter_altura(no->direito);
    }
}

No* criar_no_avl(char* dado) {
    No* no = (No*)malloc(sizeof(No));
    if (no == NULL)
    {
        printf("Erro na alocação de memória!\n");
        return NULL;
    }

    no->dado = (char*)malloc(strlen(dado) + 1);
    if (no->dado == NULL) {
        printf("Erro na alocação de memória para a string!\n");

        free(no);
        return NULL;
    }

    strcpy(no->dado, dado);
    no->esquerdo = NULL;
    no->direito = NULL;
    no->altura = 0;
    return no;
}

No* rotacao_direita(No* y) {
    No* x = y->esquerdo;
    No* z = x->direito;

    x->direito = y;
    y->esquerdo = z;

    if (obter_altura(y->esquerdo) > obter_altura(y->direito)) {
        y->altura = 1 + obter_altura(y->esquerdo);
    } else {
        y->altura = 1 + obter_altura(y->direito);
    }

    if (obter_altura(x->esquerdo) > obter_altura(x->direito)) {
        x->altura = 1 + obter_altura(x->esquerdo);
    } else {
        x->altura = 1 + obter_altura(x->direito);
    }

    return x;
}

No* rotacao_esquerda(No* x) {
    No* y = x->direito;
    No* z = y->esquerdo;

    y->esquerdo = x;
    x->direito = z;

    if (obter_altura(x->esquerdo) > obter_altura(x->direito)) {
        x->altura = 1 + obter_altura(x->esquerdo);
    } else {
        x->altura = 1 + obter_altura(x->direito);
    }

    if (obter_altura(y->esquerdo) > obter_altura(y->direito)) {
        y->altura = 1 + obter_altura(y->esquerdo);
    } else {
        y->altura = 1 + obter_altura(y->direito);
    }

    return y;
}

No* inserir_no_avl(No* no, char* dado) {
    if (no == NULL)
        return criar_no_avl(dado);

    if (strcmp(dado, no->dado) < 0) {
        no->esquerdo = inserir_no_avl(no->esquerdo, dado);
    } else if (strcmp(dado, no->dado) > 0) {
        no->direito = inserir_no_avl(no->direito, dado);
    } else {
        return no;
    }
    
    int altura_esquerda = obter_altura(no->esquerdo);
    int altura_direita = obter_altura(no->direito);

    if (altura_esquerda > altura_direita)
    {
      no->altura = 1 + altura_esquerda;
    }
    else
    {
      no->altura = 1 + altura_direita;
    }
    
    int balanceamento = calcular_fator_de_balanceamento(no);

    // Caso 1: Desbalanceamento à esquerda (Rotação à direita).
    if (balanceamento > 1 && strcmp(dado, no->esquerdo->dado) < 0)
        return rotacao_direita(no);

    // Caso 2: Desbalanceamento à direita (Rotação à esquerda).
    if (balanceamento < -1 && strcmp(dado, no->direito->dado) > 0)
        return rotacao_esquerda(no);

    // Caso 3: Desbalanceamento esquerda-direita (Rotação dupla esquerda-direita).
    if (balanceamento > 1 && strcmp(dado, no->esquerdo->dado) > 0) {
        no->esquerdo = rotacao_esquerda(no->esquerdo);
        return rotacao_direita(no);
    }

    // Caso 4: Desbalanceamento direita-esquerda (Rotação dupla direita-esquerda).
    if (balanceamento < -1 && strcmp(dado, no->direito->dado) < 0) {
        no->direito = rotacao_direita(no->direito);
        return rotacao_esquerda(no);
    }

    return no;
}

void imprimir_em_ordem(No* raiz) {
    if(raiz){
        imprimir_em_ordem(raiz->esquerdo);
        printf("%s\n", raiz->dado);
        imprimir_em_ordem(raiz->direito);
    }
}

void liberar_avl(No* avl){
    if (avl ==NULL)
    {
        return;
    }

    liberar_avl(avl->esquerdo);
    liberar_avl(avl->direito);
    free(avl->dado);
    free(avl);
}
