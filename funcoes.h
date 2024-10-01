#define FUNCOES_H  
#define FUNCOES_H

extern float bit;
extern float eth;
extern float rip;
extern float real;

#define MAX 100
#define LEN 200
extern char extrato[MAX][LEN];
extern int num_strings;

// É interessante criar um 'struct' para as moedas?
extern double cot_bit;
extern double cot_eth;
extern double cot_rip;


typedef struct {
    char cpf[10];
    int senha;
    char nome[50];
    char nome_arquivo[12];
} Usuario;

int ler_arquivo(char nome_arquivo[],float *bit,float *eth, float *rip, float *real, double *cot_bit, double *cot_eth,double *cot_rip, char extrato[][LEN], int *num_strings);

int salvar_arquivo(char nome_arquivo[],float *bit,float *eth, float *rip, float *real, double *cot_bit, double *cot_eth,double *cot_rip, char extrato[][LEN], int *num_strings);

void criarUsuarios();

int verificarUsuario();

int menu();

int menu2();

void consultar_saldo(char nome[], char cpf[]);

int consultar_extrato(int num_strings, int senha, char nome[], char cpf[]);

int depositar(float *real, int *num_strings, float *bit, float *eth, float *rip);

int sacar(int senha,float *real,int *num_strings, float *bit, float *eth, float *rip);

int comprar_cripto(int senha,int *num_strings, float *real ,float *bit, float *eth, float *rip, double *cot_bit, double *cot_eth, double *cot_rip);

int vender_cripto(int senha,int *num_strings, float *real ,float *bit, float *eth, float *rip, double *cot_bit, double *cot_eth, double *cot_rip);

int atualizar_cot(double *cot_bit, double *cot_eth, double *cot_rip);
