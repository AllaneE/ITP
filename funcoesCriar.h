#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "structs.h"

// Função para criar uma tabela
void criarTabela(Tabela *tabela) {
    FILE *arquivo;

    printf("Digite o nome da tabela: ");
    scanf("%s", tabela->nome);

    printf("Digite o nome da chave primaria (inteiro sem sinal): ");
    scanf("%s", tabela->chavePrimaria);

    printf("Quantas colunas a tabela tera? ");
    scanf("%d", &tabela->numColunas);

    // Abrir arquivo para escrita
    arquivo = fopen(tabela->nome, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo da tabela.\n");
        exit(1);
    }

    // Escrever informações da tabela no arquivo
    fprintf(arquivo, "%s\n", tabela->chavePrimaria);
    fprintf(arquivo, "%d\n", tabela->numColunas);

    for (int i = 0; i < tabela->numColunas; ++i) {
        printf("Digite o nome da coluna %d: ", i + 1);
        scanf("%s", tabela->colunas[i].nome);
        fprintf(arquivo, "%s ", tabela->colunas[i].nome);

        printf("Digite o tipo da coluna %d (char, int, float, double, string): ", i + 1);
        scanf("%s", tabela->colunas[i].tipo);
        fprintf(arquivo, "%s ", tabela->colunas[i].tipo);

        // Aqui seria o lugar para tratar o tipo string e seu tamanho, se necessário
    }

    fclose(arquivo);

    printf("Tabela criada com sucesso!\n");
}

// Função para adicionar uma nova linha na tabela
void adicionarLinha(Tabela *tabelas, int numTabelas) {
    FILE *arquivo;
    char nomeTabela[50];
    char linha[100];  // Ajuste o tamanho conforme necessário

    printf("Escolha a tabela para adicionar uma linha:\n");

    for (int i = 0; i < numTabelas; ++i) {
        printf("%d. %s\n", i + 1, tabelas[i].nome);
    }

    int escolha;
    printf("Digite o número correspondente à tabela: ");
    scanf("%d", &escolha);

    if (escolha < 1 || escolha > numTabelas) {
        printf("Escolha inválida.\n");
        return;
    }

    strcpy(nomeTabela, tabelas[escolha - 1].nome);

    // Abrir arquivo da tabela para adição de linha
    arquivo = fopen(nomeTabela, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo da tabela '%s'.\n", nomeTabela);
        exit(1);
    }

    // Adicionar uma linha
    for (int i = 0; i < tabelas[escolha - 1].numColunas; ++i) {
        printf("Digite o valor para a coluna %s: ", tabelas[escolha - 1].colunas[i].nome);
        scanf("%s", linha);
        fprintf(arquivo, "%s ", linha);
    }

    fprintf(arquivo, "\n");

    fclose(arquivo);

    printf("Linha adicionada com sucesso na tabela '%s'!\n", nomeTabela);
}