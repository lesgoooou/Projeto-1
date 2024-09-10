#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int consultar_saldo(){
    puts("Funcionando 1...\n");
}

int consultar_extrato(){
    puts("Funcionando 2...\n");
}

int depositar(){
    puts("Funcionando 3...\n");
}

int sacar(){
    puts("Funcionando 4...\n");
}

int comprar_cripto(){
    puts("Funcionando 5...\n");
}

int vender_cripto(){
    puts("Funcionando 6...\n");
}

int atualizar_cot(){
    puts("Funcionando 7...\n");
}

int menu(){
    printf("1. Consultar saldo\n");
    printf("2. Consultar extrato\n");
    printf("3. Depositar\n");
    printf("4. Sacar\n");
    printf("5. Comprar Criptomoedas\n");
    printf("6. Vender Criptomoedas\n");
    printf("7. Atualizar cotacao\n");
    printf("8. Sair\n");
    printf("\n");

    return 0;
}

int main(void){
    char cpf[12];
    char senha[11];
    int esc;
    
    printf("Seja bem vindo, ensira seu CPF e sua senha!\n");

    printf("CPF: ");
    fgets(cpf, 12, stdin);
    printf("Senha: ");
    fgets(senha, 11, stdin);
    printf(" \n");
    printf("%s", senha);
    printf("%s\n", cpf);

    while(1){
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &esc);

        if(esc<1 || esc>8){
            printf("Escolha uma opcao valida!\n");
        }
        else {
            if(esc==1){consultar_saldo();}
            else if(esc==2){consultar_extrato();}
            else if(esc==3){depositar();}
            else if(esc==4){sacar();}
            else if(esc==5){comprar_cripto();}
            else if(esc==6){vender_cripto();}
            else if(esc==7){atualizar_cot();}
            else {
                return 0;
            }
        } 
    }



    return 0;
}


.
