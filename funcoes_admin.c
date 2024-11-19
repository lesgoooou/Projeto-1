#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes_admin.h" 

void criarAdmin(Adm adms[]){
    strcpy(adms[0].cpf, "12345678901");
    adms[0].senha = 111;
    strcpy(adms[0].nome, "Gabriel");
    strcpy(adms[0].nome_arquivo, "01_G.bin");

    strcpy(adms[1].cpf, "12345678902");
    adms[1].senha = 222;
    strcpy(adms[1].nome, "Bruno");
    strcpy(adms[1].nome_arquivo, "02_B.bin");


    strcpy(adms[2].cpf, "12345678903");
    adms[2].senha = 333;
    strcpy(adms[2].nome, "Daniel");
    strcpy(adms[2].nome_arquivo, "03_D.bin");
};

void menu1_admin() { 
    printf("\n");
    printf("1. Cadastrar Novo Investidor\n");
    printf("2. Excluir Investidor\n");
    printf("3. Cadastrar Criptomoeda\n");
    printf("4. Excluir Criptomoeda\n");
    printf("5. Consultar Saldo de Investidor\n");
    printf("6. Consultar Extrato de Investidor\n");
    printf("7. Atualizar cotacao\n");
    printf("8. Sair\n");
    printf("\n");
}

void cadastrar_investidor(const char *arquivo_investidores) {
    Investidor novo;
    FILE *arquivo = fopen(arquivo_investidores, "ab");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para cadastro");
        return;
    }

    printf("Nome: ");
    scanf(" %[^\n]", novo.nome);
    printf("CPF: ");
    scanf("%s", novo.cpf);
    printf("Senha: ");
    scanf("%s", novo.senha);

    novo.num_criptos = 0; // Inicia sem nenhuma criptomoeda
    novo.saldo = 0.0; // Saldo inicial em reais

    if (fwrite(&novo, sizeof(Investidor), 1, arquivo) != 1) {
        perror("Erro ao escrever no arquivo");
    } else {
        printf("Investidor cadastrado com sucesso!\n");
    }

    fclose(arquivo);
}


void excluir_investidor(const char *arquivo_investidores) {
    char cpf[12];
    printf("Digite o CPF do investidor que deseja excluir: ");
    scanf("%s", cpf);

    FILE *arquivo = fopen(arquivo_investidores, "rb");
    FILE *temp = fopen("temp.bin", "wb"); // Arquivo temporário
    if (!arquivo || !temp) {
        printf("Erro ao abrir os arquivos!\n");
        return;
    }

    Investidor investidor;
    bool encontrado = false;

    // Lê todos os registros e copia os que não correspondem ao CPF
    while (fread(&investidor, sizeof(Investidor), 1, arquivo)) {
        if (strcmp(investidor.cpf, cpf) != 0) {
            fwrite(&investidor, sizeof(Investidor), 1, temp);
        } else {
            encontrado = true;
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove(arquivo_investidores); // Remove o arquivo original
    rename("temp.bin", arquivo_investidores); // Renomeia o temporário

    if (encontrado) {
        printf("Investidor excluído com sucesso!\n");
    } else {
        printf("CPF não encontrado!\n");
    }
}

void listar_investidores(const char *arquivo_investidores) {
    FILE *arquivo = fopen(arquivo_investidores, "rb");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s!\n", arquivo_investidores);
        return;
    }

    Investidor investidor;
    printf("\n--- Lista de Investidores ---\n");
    while (fread(&investidor, sizeof(Investidor), 1, arquivo)) {
        printf("Nome: %s | CPF: %s | Criptomoedas:\n", investidor.nome, investidor.cpf);
        if (investidor.num_criptos > 0) {
            for (int i = 0; i < investidor.num_criptos; i++) {
                printf("- %s: %.2f\n", 
                    investidor.criptos[i].nome, 
                    investidor.criptos[i].quantidade);
            }
        } else {
            printf("Nenhuma criptomoeda cadastrada.\n");
        }
        printf("\n");
    }
    printf("------------------------------\n");

    fclose(arquivo);
}

void consultar_saldo(const char *arquivo_investidores) {
    FILE *arquivo = fopen(arquivo_investidores, "rb");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s!\n", arquivo_investidores);
        return;
    }

    Investidor investidor;
    bool algum_registro = false;

    printf("\n--- Saldos de Todos os Investidores ---\n");
    while (fread(&investidor, sizeof(Investidor), 1, arquivo)) {
        printf("Nome: %s\n", investidor.nome);
        printf("Saldo em Reais: R$ %.2f\n", investidor.saldo);
        printf("Criptomoedas:\n");
        if (investidor.num_criptos > 0) {
            for (int i = 0; i < investidor.num_criptos; i++) {
                printf("- %s: %.2f\n", 
                    investidor.criptos[i].nome, 
                    investidor.criptos[i].quantidade);
            }
        } else {
            printf("Nenhuma criptomoeda cadastrada.\n");
        }
        printf("\n");
        algum_registro = true;
    }

    fclose(arquivo);

    if (!algum_registro) {
        printf("Nenhum investidor cadastrado no sistema.\n");
    }
    printf("---------------------------------------\n");
}

void consultar_extrato(const char *arquivo_investidores) {
    char cpf[12];
    printf("Digite o CPF do investidor que deseja consultar o extrato: ");
    scanf("%s", cpf);

    FILE *arquivo = fopen(arquivo_investidores, "rb");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s!\n", arquivo_investidores);
        return;
    }

    Investidor investidor;
    bool encontrado = false;

    while (fread(&investidor, sizeof(Investidor), 1, arquivo)) {
        if (strcmp(investidor.cpf, cpf) == 0) {
            encontrado = true;
            printf("\n--- Extrato do Investidor ---\n");
            printf("Nome: %s\n", investidor.nome);
            printf("CPF: %s\n", investidor.cpf);
            printf("Saldo em Reais: R$ %.2f\n", investidor.saldo);
            printf("Criptomoedas:\n");
            if (investidor.num_criptos > 0) {
                for (int i = 0; i < investidor.num_criptos; i++) {
                    printf("- %s: %.2f\n", 
                        investidor.criptos[i].nome, 
                        investidor.criptos[i].quantidade);
                }
            } else {
                printf("Nenhuma criptomoeda cadastrada.\n");
            }
            printf("------------------------------\n");
            break;
        }
    }

    fclose(arquivo);

    if (!encontrado) {
        printf("Investidor com CPF %s não encontrado.\n", cpf);
    }
}

int carregarUsuarios(const char *arquivo_investidores, Usuario usuarios[]) {
    FILE *arquivo = fopen(arquivo_investidores, "rb");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s!\n", arquivo_investidores);
        return 0;
    }

    int count = 0;
    while (fread(&usuarios[count], sizeof(Usuario), 1, arquivo)) {
        count++;
    }

    fclose(arquivo);
    return count; // Retorna o número de usuários carregados
}
