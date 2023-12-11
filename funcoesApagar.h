#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "structs.h"

// Função para apagar uma tupla de uma tabela
void apagarTupla() {
    FILE *arquivo, *temp;
    char nomeTabela[50];
    char chavePrimaria[50];
    char linha[100];  

    printf("Digite o nome da tabela: ");
    scanf("%s", nomeTabela);

    printf("Digite a chave primaria da tupla a ser apagada: ");
    scanf("%s", chavePrimaria);

    // Abrir o arquivo correspondente à tabela
    arquivo = fopen(nomeTabela, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo da tabela.\n");
        return;
    }

    // Abrir arquivo temporário para escrita
    temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(arquivo);
        return;
    }

    // Copiar todas as linhas exceto a que contém a chave primária a ser apagada
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strstr(linha, chavePrimaria) == NULL) {
            fprintf(temp, "%s", linha);
        }
    }

    fclose(arquivo);
    fclose(temp);

    // Substituir o arquivo original pelo temporário
    remove(nomeTabela);
    rename("temp.txt", nomeTabela);

    printf("Tupla apagada com sucesso!\n");
}

// Função para apagar uma tabela
void apagarTabela() {
    FILE *arquivo, *temp;
    char nomeTabela[50];
    char linha[100]; 

    printf("Digite o nome da tabela a ser apagada: ");
    scanf("%s", nomeTabela);

    // Abrir o arquivo que armazena os nomes das tabelas
    arquivo = fopen("tabelas.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhuma tabela encontrada.\n");
        return;
    }

    // Abrir arquivo temporário para escrita
    temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(arquivo);
        return;
    }

    // Copiar todas as linhas exceto a que contém o nome da tabela a ser apagada
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strstr(linha, nomeTabela) == NULL) {
            fprintf(temp, "%s", linha);
        }
    }

    fclose(arquivo);
    fclose(temp);

    // Substituir o arquivo original pelo temporário
    remove("tabelas.txt");
    rename("temp.txt", "tabelas.txt");

    // Apagar o arquivo correspondente à tabela
    remove(nomeTabela);

    printf("Tabela apagada com sucesso!\n");
}