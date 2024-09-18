#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "funcoes.h" 

float bit = 0;
float eth = 0;
float rip = 0;
float real = 0;

int cot_bit = 5000;
int cot_eth = 2000;
int cot_rip = 500;

int menu(){
    printf("\n");
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

int menu2(){
    puts("\n");
    printf("1.Bitcoin\n");
    printf("2.Ethereum\n");
    printf("3.Ripple\n");
    puts("\n");

    return 0;
}

// Função que cria os usuários e retorna o array de usuários
void criarUsuarios(Usuario usuarios[]) {
    strcpy(usuarios[0].cpf, "12345678901");
    usuarios[0].senha = 111;
    strcpy(usuarios[0].nome, "Gabriel");

    strcpy(usuarios[1].cpf, "12345678902");
    usuarios[1].senha = 222;
    strcpy(usuarios[1].nome, "Bruno");

    strcpy(usuarios[2].cpf, "12345678903");
    usuarios[2].senha = 333;
    strcpy(usuarios[2].nome, "Daniel");

    strcpy(usuarios[3].cpf, "12345678904");
    usuarios[3].senha = 444;
    strcpy(usuarios[3].nome, "Livia");

    strcpy(usuarios[4].cpf, "12345678905");
    usuarios[4].senha = 555;
    strcpy(usuarios[4].nome, "Julia");

    strcpy(usuarios[5].cpf, "12345678906");
    usuarios[5].senha = 666;
    strcpy(usuarios[5].nome, "Ana");

    strcpy(usuarios[6].cpf, "12345678907");
    usuarios[6].senha = 777;
    strcpy(usuarios[6].nome, "Ravi");

    strcpy(usuarios[7].cpf, "12345678908");
    usuarios[7].senha = 888;
    strcpy(usuarios[7].nome, "Sergio");

    strcpy(usuarios[8].cpf, "12345678909");
    usuarios[8].senha = 999;
    strcpy(usuarios[8].nome, "Catarina");

    strcpy(usuarios[9].cpf, "12345678910");
    usuarios[9].senha = 000;
    strcpy(usuarios[9].nome, "Mario");

}

int verificarUsuario(Usuario usuarios[], int quantidade, char cpf[], int senha) {
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(usuarios[i].cpf, cpf) == 0 && usuarios[i].senha == senha) {
            return 1; // Usuário encontrado e senha correta
        }
    }
    return 0; // Usuário não encontrado ou senha incorreta
}

void formatar_cpf(char cpf[], char cpf_formatado[]) {
    snprintf(cpf_formatado, 15, "%c%c%c.%c%c%c.%c%c%c-%c%c",
             cpf[0], cpf[1], cpf[2], 
             cpf[3], cpf[4], cpf[5], 
             cpf[6], cpf[7], cpf[8], 
             cpf[9], cpf[10]);       
}

void consultar_saldo(char nome[], char cpf[]){
    char cpf_formatado[15];  
    formatar_cpf(cpf, cpf_formatado);

    printf("Saldo de %s (CPF: %s):\n", nome, cpf_formatado); 
    printf("Bitcoin: %.2f\n", bit);
    printf("Ethereum: %.2f\n", eth);
    printf("Ripple: %.2f\n", rip);
    printf("Reais: %.2f\n", real);
}

int consultar_extrato(){
    puts("Funcionando 2...\n");
}

#include <stdio.h>

void depositar(float *real) {
    puts("Digite a quantidade a ser depositada(R$):");
    float valor;
    scanf("%f", &valor);
    
    if (valor > 0) {
        *real += valor;  // Adiciona o valor depositado ao real
        printf("Novo saldo: %.2f\n", *real);
        puts("Transacao realizada com sucesso!");
    } else {
        puts("Houve um erro! Digite um valor valido...");
    }
    // Implementar extrato... 
}

int sacar(float *real){
    puts("Digite a quantidade a sacar(R$):");
    float valor;
    scanf("%f", &valor);
    
    if (valor > 0) {
        *real -= valor;  // subtrai o valor do real
        printf("Novo saldo: %.2f\n", *real);
        puts("Transacao realizada com sucesso!");
    } else {
        puts("Houve um erro! Digite um valor valido...");
    }
    // Implementar extrato... 
}

int comprar_cripto(int senha, float *bit){
    puts("Digite sua senha: ");
    int senh;
    scanf("%d", &senh);
    if (senh == senha){
        while(1){
            puts("Escolha uma opcao: ");
            menu2();
            int esc;
            scanf("%d", &esc);
            if (esc < 0 && esc > 4)
                puts("Escolha uma opcao valida...");
            else {
                // Colocar a quantidade da moeda ou a quantidade em reais?
                puts("Digite a quantidade:");
                float valor;
                scanf("%f", &valor);
                
                if (valor > 0) {
                    *bit += valor;  // Adiciona o valor depositado ao real
                    printf("Novo saldo: %.2f\n", *bit);
                    puts("Transacao realizada com sucesso!");
                } else {
                    puts("Houve um erro! Digite um valor valido...");
                }
                // Implementar extrato... 
                return 0;
            }
        }
    }
}

int vender_cripto(){
    puts("Funcionando 6...\n");
}

int atualizar_cot(){
    puts("Funcionando 7...\n");
}