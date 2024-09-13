#ifndef FUNCOES_H  
#define FUNCOES_H

extern int bit;
extern int eth;
extern int rip;
extern int real;

extern int cot_bit;
extern int cot_eth;
extern int cot_rip;


typedef struct {
    char cpf[10];
    int senha;
    char nome[50];
} Usuario;

void criarUsuarios();

int verificarUsuario();

int menu();

void consultar_saldo(char nome[], char cpf[]);

int consultar_extrato();

int depositar();

int sacar();

int comprar_cripto();

int vender_cripto();

int atualizar_cot();

#endif
