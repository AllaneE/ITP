#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "structs.h"

// Função para listar todas as tabelas
void listarTabelas() {
    FILE *arquivo;
    char nomeTabela[50];

    printf("Tabelas existentes:\n");

    // Abrir o arquivo que armazena as informações das tabelas
    arquivo = fopen("tabelas.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhuma tabela encontrada.\n");
        return;
    }

    // Ler e imprimir o nome de cada tabela
    while (fscanf(arquivo, "%s", nomeTabela) == 1) {
        printf("- %s\n", nomeTabela);
    }

    fclose(arquivo);
}

// Função para listar todos os dados de uma tabela
void listarDadosTabela() {
    FILE *arquivo;
    char nomeTabela[50];
    char linha[100];

    printf("Digite o nome da tabela: ");
    scanf("%s", nomeTabela);
    printf("\nListando dados de %s...\n\n" , nomeTabela);

    // Abrir o arquivo correspondente à tabela
    arquivo = fopen(nomeTabela, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo da tabela.\n");
        return;
    }

    // Ler e imprimir os dados da tabela
    int contador = 0;
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        switch (contador)
        {
        case 0:
            printf("Chave primaria: ");
            printf("%s", linha);
            break;
        case 1:
            printf("Numero de colunas: ");
            printf("%s", linha);
            break;
        default:   
            printf("%s", linha);
            break;
        }
        printf("\n");

        contador++;
    }
    printf("\n");
    fclose(arquivo);
}