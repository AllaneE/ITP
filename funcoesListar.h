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
    char linha[100];  // Ajuste o tamanho conforme necessário

    printf("Digite o nome da tabela: ");
    scanf("%s", nomeTabela);

    // Abrir o arquivo correspondente à tabela
    arquivo = fopen(nomeTabela, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo da tabela.\n");
        return;
    }

    // Ler e imprimir os dados da tabela
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    fclose(arquivo);
}