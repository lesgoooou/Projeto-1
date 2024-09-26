#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "funcoes.h"

int main(void) {
    char cpf[12];
    int senha;
    int esc;

    Usuario usuarios[10]; // Array para armazenar os usuários
    criarUsuarios(usuarios); // Populando o array com os usuários

    printf("Seja bem vindo, insira seu CPF e sua senha!\n");

    // Loop para solicitar o CPF e a senha
    while (1) {
        printf("CPF: ");
        scanf("%s", cpf);
        printf("Senha: ");
        scanf("%d", &senha);  

        printf("\n");

        int usuario_autenticado = -1;
        for (int i = 0; i < 10; i++) {
            if (strcmp(usuarios[i].cpf, cpf) == 0 && usuarios[i].senha == senha) {
                usuario_autenticado = i;
                break;
            }
        }

        if (usuario_autenticado != -1) {
            printf("Acesso permitido!\n");
            // Loop para o menu após login bem-sucedido

            while (1) {
                menu();
                printf("Escolha uma opcao: ");
                scanf("%d", &esc);
                printf("\n");

                if (esc < 1 || esc > 8) {
                    printf("Escolha uma opcao valida!\n");
                } else {
                    if (esc == 1) {consultar_saldo(usuarios[usuario_autenticado].nome, usuarios[usuario_autenticado].cpf);}
                    else if (esc == 2) { consultar_extrato(); }
                    else if (esc == 3) { depositar(&real); }
                    else if (esc == 4) { sacar(senha, &real); }
                    else if (esc == 5) { comprar_cripto(senha, &real ,&bit ,&eth ,&rip ,&cot_bit, &cot_eth, &cot_rip); }
                    else if (esc == 6) { vender_cripto(senha, &real ,&bit ,&eth ,&rip ,&cot_bit, &cot_eth, &cot_rip); }
                    else if (esc == 7) { atualizar_cot(); }
                    else if (esc == 8) {return 0;}
                }
            }
        } else {
            printf("CPF ou senha incorretos.\n");
        }
    }

    return 0;
}



