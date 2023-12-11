#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "structs.h"

// Função para criar uma tabela
void criarTabela(Tabela *tabela) {
    FILE *arquivo;
    FILE *tabelasArquivo;

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
    }
    fprintf(arquivo, "\n");
    fclose(arquivo);

    // Abrir arquivo "tabelas.txt" para adicionar o nome da nova tabela
    tabelasArquivo = fopen("tabelas.txt", "a");
    if (tabelasArquivo == NULL) {
        printf("Erro ao abrir o arquivo das tabelas.\n");
        exit(1);
    }

    // Escrever o nome da tabela no arquivo de tabelas
    fprintf(tabelasArquivo, "%s\n", tabela->nome);

    fclose(tabelasArquivo);

    printf("Tabela criada com sucesso!\n");
}

// Função para adicionar uma nova linha na tabela
void adicionarLinha(Tabela *tabelas, int numTabelas) {
    char nomeTabela[50];
    char linha[100];

   FILE *arquivoTabelas = fopen("tabelas.txt", "r");

    if (arquivoTabelas == NULL) {
        printf("Erro ao abrir o arquivo das tabelas.\n");
        return;
    }

    printf("Digite o nome da tabela: ");
    scanf("%s", nomeTabela);

    int tabelaEncontrada = 0;

    // Verificar se o nome da tabela existe no arquivo "tabelas.txt"
    while (fscanf(arquivoTabelas, "%s", linha) == 1) {
        if (strcmp(linha, nomeTabela) == 0) {
            tabelaEncontrada = 1;
            break;
        }
    }

    fclose(arquivoTabelas);

    if (!tabelaEncontrada) {
        printf("Tabela não encontrada.\n");
        return;
    }

    FILE *arquivo = fopen(nomeTabela, "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo da tabela '%s'.\n", nomeTabela);
        return;
    }

    printf("Adicionando uma nova linha na tabela '%s':\n", nomeTabela);

    // Solicitar os valores para cada coluna da nova linha
    printf("Digite os valores para cada coluna separados por espaços:\n");
    scanf(" %[^\n]", linha);

    // Adicionar a nova linha ao arquivo da tabela
    fprintf(arquivo, "%s\n", linha);

    fclose(arquivo);

    printf("Linha adicionada com sucesso na tabela '%s'!\n", nomeTabela);
}

