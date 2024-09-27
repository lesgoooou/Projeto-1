#ifndef FUNCOES_H  
#define FUNCOES_H

extern float bit;
extern float eth;
extern float rip;
extern float real;

// É interessante criar um 'struct' para as moedas?
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

int menu2();

void consultar_saldo(char nome[], char cpf[]);

int consultar_extrato();

void depositar( float *real);

int sacar(int senha,float *real);

int comprar_cripto(int senha, float *real ,float *bit, float *eth, float *rip, int *cot_bit, int *cot_eth, int *cot_rip);

int vender_cripto(int senha, float *real ,float *bit, float *eth, float *rip, int *cot_bit, int *cot_eth, int *cot_rip);

int atualizar_cot(int *cot_bit, int *cot_eth, int *cot_rip);

#endif
