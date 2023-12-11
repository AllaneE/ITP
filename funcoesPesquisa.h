#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "structs.h"

// Função para pesquisar valor em uma tabela
void pesquisarValor() {
    FILE *arquivo;
    char nomeTabela[50];
    char nomeColuna[50];
    char valorPesquisa[50];
    char linha[100];  // Ajuste o tamanho conforme necessário

    printf("Digite o nome da tabela: ");
    scanf("%s", nomeTabela);

    // Abrir o arquivo correspondente à tabela
    arquivo = fopen(nomeTabela, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo da tabela.\n");
        return;
    }

    // Listar as colunas disponíveis na tabela
    printf("Colunas disponíveis na tabela %s:\n", nomeTabela);
    fscanf(arquivo, "%*s"); // Ignorar a linha da chave primária
    fscanf(arquivo, "%*d"); // Ignorar a linha do número de colunas

    while (fscanf(arquivo, "%s", nomeColuna) == 1) {
        printf("- %s\n", nomeColuna);
    }

    // Voltar ao início do arquivo para começar a leitura dos dados
    fseek(arquivo, 0, SEEK_SET);

    // Solicitar ao usuário selecionar uma coluna para a pesquisa
    printf("Digite o nome da coluna para pesquisa: ");
    scanf("%s", nomeColuna);

    // Solicitar ao usuário o valor para pesquisa
    printf("Digite o valor para pesquisa: ");
    scanf("%s", valorPesquisa);

    // Realizar a pesquisa e exibir os resultados
    printf("Resultados da pesquisa na coluna %s:\n", nomeColuna);
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char *token = strtok(linha, " ");
        if (strcmp(token, valorPesquisa) == 0) {
            printf("%s", linha);
        }
    }

    fclose(arquivo);
}