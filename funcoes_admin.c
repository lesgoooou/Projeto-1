#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h" 

void criarAdmin(Admin admins[]) {
    strcpy(admins[0].cpf, "12345678901");
    admins[0].senha = 111;
    strcpy(admins[0].nome, "Gabriel");

    strcpy(admins[1].cpf, "12345678902");
    admins[1].senha = 222;
    strcpy(admins[1].nome, "Bruno");

    strcpy(admins[2].cpf, "12345678903");
    admins[2].senha = 333;
    strcpy(admins[2].nome, "Daniel");

}

int menu_admin(){
    printf("\n");
    printf("1. Cadastrar Investidor\n");
    printf("2. Excluir Investidor\n");
    printf("3. Cadastrar Criptomoeda\n");
    printf("4. Excluir Criptomoeda\n");
    printf("5. Atualizar Cotacao\n");
    printf("6. Sair\n");
    printf("\n");

    return 0;
}

int cadastrar_invest() {
    printf("cadastrar investidor\n");
    return 0;
}

int exc_invest() {
    printf("excluir investidor\n");
    return 0;
}

int cadastrar_cripto() {
    printf("cadastrar cripto\n");
    return 0;
}

int exc_cripto() {
    printf("excluir cripto\n");
    return 0;
}

int atualizar_cota() {
    printf("atualizar cotacao\n");
    return 0;
}