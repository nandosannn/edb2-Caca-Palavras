#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/util.h"

void menu(){
    printf("\n======== MENU PRINCIPAL ========\n\n");

    printf("Selecione uma das operacoes abaixo:\n");

    printf("1 - Cadastrar uma nova aeronave\n");
    printf("2 - Consultar maior prioridade\n");
    printf("3 - Remover maior prioridade\n");
    printf("4 - Exibir todas as aeronaves\n");
    printf("5 - Consultar aeronave\n");
    printf("6 - Finalizar o programa\n");

    printf("\nDigite o numero da operacao desejada: ");
}

void menu_alterar(){
    printf("\n======== MENU ALTERADOR DE AERONAVES ========\n\n");

    printf("Selecione uma das operacoes abaixo:\n");

    printf("1 - Alterar combustivel\n");
    printf("2 - Alterar horario_em_minutos\n");
    printf("3 - Alterar tipo (decolagem ou pouso)\n");
    printf("4 - Alterar situacao de emergencia (em emergencia ou sem emergencia)\n");
    printf("5 - Voltar para o Menu Principal\n");

    printf("\nDigite o numero da operacao desejada: ");
}

void limpador_de_buffer(){
    while (getchar() != '\n');
}

int leitor_de_numeros(){
    int numero;
    int resultado;

    resultado = scanf("%d", &numero);

    if(resultado != 1 || numero <= 0 || numero >= 500000){
        printf("Numero invalido!\nDigite o numero novamente: ");
        limpador_de_buffer();
        return leitor_de_numeros();
    }

    limpador_de_buffer();
    return numero;
}

int leitor_de_tipo(){
    int numero;
    int resultado;

    resultado = scanf("%d", &numero);

    if(resultado != 1 || (numero != 0 && numero != 1)){
        printf("Numero invalido!\nDigite o numero novamente: ");
        limpador_de_buffer();
        return leitor_de_numeros();
    }

    limpador_de_buffer();
    return numero;
}

char* leitor_de_palavras(){
    char* palavra = (char*)malloc(50 * sizeof(char));

    if (palavra == NULL){
        printf("Erro: Memoria insuficiente.\n");
        return NULL;
    }

    if(fgets(palavra, 50, stdin) != NULL){
        palavra[strcspn(palavra, "\n")] = '\0';
        
        if(strlen(palavra) == 49) {
            limpador_de_buffer();
        }

        return palavra;
    }else{
        printf("Erro ao ler o nome!\nDigite novamente: ");
        free(palavra);
        return leitor_de_palavras();
    }
}

void para_maisculo(char* palavra){
    if (palavra == NULL) return;

    for(int i = 0; palavra[i] != '\0'; i++){
        palavra[i] = toupper_personalizado(&palavra[i]);
    }
}

int comparador_de_palavras(char* palavra1, char* palavra2){
    char temp1[strlen(palavra1) + 1]; 
    char temp2[strlen(palavra2) + 1]; 

    strcpy(temp1, palavra1);
    strcpy(temp2, palavra2);

    para_maisculo(temp1);
    para_maisculo(temp2);

    return strcmp(temp1, temp2);
}

char toupper_personalizado(char* letra){
    if (strcmp(letra, "á") == 0) {
        strcpy(letra, "Á");
    } else if (strcmp(letra, "é") == 0) {
        strcpy(letra, "É");
    } else if (strcmp(letra, "í") == 0) {
        strcpy(letra, "Í");
    } else if (strcmp(letra, "ó") == 0) {
        strcpy(letra, "Ó");
    } else if (strcmp(letra, "ú") == 0) {
        strcpy(letra, "Ú");
    } else if (strcmp(letra, "ç") == 0) {
        strcpy(letra, "Ç");
    } else if (strcmp(letra, "ã") == 0) {
        strcpy(letra, "Ã");
    } else if (strcmp(letra, "õ") == 0) {
        strcpy(letra, "Õ");
    } else {
        letra[0] = toupper(letra[0]);
        letra[1] = '\0';
    }
    
    return *letra;
}

void reiniciar_arquivo(char* nome_arquivo){
    FILE* arquivo = fopen(nome_arquivo, "w");
    fclose(arquivo);
}

void exibir_alteracao_sucedida(){
    printf("Alteracao bem sucedida!");
}

