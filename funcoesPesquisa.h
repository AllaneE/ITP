#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "structs.h"

// Função para escolher a operação de comparação
int escolhaOperacao() {
    int escolha;

    printf("Escolha a operacao de comparacao:\n");
    printf("1. Valores maior que o valor informado\n");
    printf("2. Valores maior ou igual que o valor informado\n");
    printf("3. Valores igual o valor informado\n");
    printf("4. Valores menor que o valor informado\n");
    printf("5. Valores menor ou igual que o valor informado\n");

    printf("Digite o número correspondente à operação: ");
    scanf("%d", &escolha);

    return escolha;
}

//função para pesquisar algum valor
void pesquisarValor() {
    FILE *arquivo;
    char nomeTabela[50];
    char nomeColuna[50];
    char valorPesquisa[50];
    char linha[100];

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
    fscanf(arquivo, "%*s");
    fscanf(arquivo, "%*d");

    while (fscanf(arquivo, "%s", nomeColuna) == 1) {
        printf("- %s\n", nomeColuna);
    }

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

        // Verificar se a coluna é do tipo string
        if (strcmp(nomeColuna, "string") == 0) {
            // Comparação exata para colunas do tipo string
            if (strcmp(token, valorPesquisa) == 0) {
                printf("%s", linha);
            }
        } else {
            // Comparação numérica para outras colunas
            int valorInt = atoi(token);
            int valorPesquisaInt = atoi(valorPesquisa);

            switch (escolhaOperacao()) {
                case 1:
                    if (valorInt > valorPesquisaInt)
                        printf("%s", linha);
                    break;
                case 2:
                    if (valorInt >= valorPesquisaInt)
                        printf("%s", linha);
                    break;
                case 3:
                    if (valorInt == valorPesquisaInt)
                        printf("%s", linha);
                    break;
                case 4:
                    if (valorInt < valorPesquisaInt)
                        printf("%s", linha);
                    break;
                case 5:
                    if (valorInt <= valorPesquisaInt)
                        printf("%s", linha);
                    break;
                default:
                    printf("Escolha inválida.\n");
                    break;
            }
        }
    }

    fclose(arquivo);
}

