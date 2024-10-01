#include <stdio.h>
#include <stdlib.h>

int main(void){

    float bit = 3;
    float eth = 1;
    float rip = 4;
    float real = 0;

    double cot_bit = 5000.0;
    double cot_eth = 2000.0;
    double cot_rip = 500.0;


    #define MAX 100
    #define LEN 200
    char extrato[MAX][LEN];
    int num_strings = 0;


    //ponteiro para arquivo
    FILE  *arquivo;
    //abertura de arquivos
    arquivo = fopen("00_M.bin", "wb");

    if(arquivo != NULL)
        printf("Arquivo criado com sucesso!");
    else{
        printf("\n\nErro: O arquivo não foi aberto\n");
        system("pause");
        exit(1);
    }

    //Gravando os dados no arquivo usando fwrite
    //Sintaxe: fwrite(&variavel, numero_de_bytes, numero_de_registros, arquivo);
    fwrite(&bit,sizeof(float), 1,arquivo);
    fwrite(&eth,sizeof(float),1,arquivo);
    fwrite(&rip,sizeof(float),1,arquivo);
    fwrite(&real,sizeof(float),1,arquivo);
    fwrite(&cot_bit,sizeof(double),1,arquivo);
    fwrite(&cot_eth,sizeof(double),1,arquivo);
    fwrite(&cot_rip,sizeof(double),1,arquivo);
    fwrite(&num_strings,sizeof(int),1,arquivo);

    fclose(arquivo);
}