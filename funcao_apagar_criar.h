#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "meusStruct.h"

#define MAX_COLUNAS 100

void criarTab() {
    Tabela novaTabela;
    int numeroColuna;
    char resp[5];
    int pkDefinida = 0;

    printf("Qual o nome da tabela?\n");
    scanf("%s", novaTabela.nomeTabela);

    printf("Qual a quantidade desejada de colunas na tabela?\n");
    scanf("%d", &numeroColuna);

    novaTabela.numeroColuna = numeroColuna;

    for (int i = 0; i < numeroColuna; i++){
        printf("Qual o nome da coluna?\n");
        scanf("%s", novaTabela.colunas[i].nomeColuna);

        printf("Qual o tipo de dado da coluna? (0 - int, 1 - double, 2 - float, 3 - char, 4 - string)\n");
        scanf("%d", &novaTabela.colunas[i].tipoColuna);

        // define a chave primária se não houver uma já definida
        // confere se o tipo de dado da coluna é inteiro
        if(novaTabela.colunas[i].tipoColuna == 0 && pkDefinida != 1 ){
            printf("A coluna é a chave primária da coluna? (sim ou nao)\n");
            scanf("%s", resp);

            // transforma a resposta em minúsculo para evitar erros
            for (int j = 0; resp[j] != '\0'; j++) {
                resp[j] = tolower(resp[j]);
            }

            // converte a resposta em valores inteiros
            if (strcmp(resp, "sim") == 0) {
                novaTabela.colunas[i].chavePrimaria = 1;
                // a chave primária foi definida então não perguntamos mais
                pkDefinida = 1;
            } else {
                novaTabela.colunas[i].chavePrimaria = 0;
            }
        }
    }

    // Abrir arquivo para escrita
    FILE *arquivo = fopen(novaTabela.nomeTabela, "w");
    if (arquivo != NULL) {
        fprintf(arquivo, "Nome da Tabela: %s\n", novaTabela.nomeTabela);
        fprintf(arquivo, "Número de Colunas: %d\n", novaTabela.numeroColuna);

        for (int i = 0; i < novaTabela.numeroColuna; i++) {
            fprintf(arquivo, "Coluna %d:\n", i + 1);
            fprintf(arquivo, "\tNome da Coluna: %s\n", novaTabela.colunas[i].nomeColuna);
            fprintf(arquivo, "\tTipo de Dado: %d\n", novaTabela.colunas[i].tipoColuna);
            fprintf(arquivo, "\tChave Primária: %s\n", novaTabela.colunas[i].chavePrimaria ? "Sim" : "Não");
        }

        fclose(arquivo);
        printf("Informações da Tabela salvas com sucesso.\n");
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}

//Apaga um arquivo
void apagarArquivo(const char *nomeArquivo) {
    if(remove(nomeArquivo)==0){
        printf("Arquivo '%s' apagado com sucesso.\n", nomeArquivo);
    }else {
        printf("Erro ao excluir o arquivo.\n");
    }
}

void novaLinha(const Tabela *tabela) {
    Linha novaLinha;
    int i;
    int chavePrimariaExistente = 0;

    printf("Nome da tabela: %s\n", tabela->nomeTabela);
    printf("%d", tabela->numeroColuna);

    // Abrir o arquivo correspondente à tabela no modo de adição ("a" - append)
    FILE *arquivo = fopen(tabela->nomeTabela, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo da tabela para adicionar a nova linha.\n");
        return;
    }
    printf("%d", tabela->numeroColuna);
    for (i = 0; i < tabela->numeroColuna; i++) {
        Linha novaLinha;
        // Pega o nome da coluna atual
        char nomeColuna[50];
        strcpy(nomeColuna, tabela->colunas[i].nomeColuna);
        printf("foi");
        // Verifica o tipo da coluna atual
        switch (tabela->colunas[i].tipoColuna) {
            case 0:
                if (tabela->colunas[i].chavePrimaria == 1) {
                    printf("Esta coluna é a chave primária. Insira um valor inteiro para a coluna %s:\n", nomeColuna);
                    scanf("%d", &novaLinha.valoresInt);

                    // Verifica se já existe uma chave primária igual
                    if (chavePrimariaExistente == 1) {
                        printf("Erro: Esta tabela já possui uma chave primária existente.\n");
                        fclose(arquivo);
                        return; // Encerra a função caso haja uma chave primária repetida
                    } else {
                        chavePrimariaExistente = 1;
                    }
                } else {
                    printf("Insira um valor inteiro para a coluna %s:\n", nomeColuna);
                    scanf("%d", &novaLinha.valoresInt);
                }
                break;
            case 1:
                printf("Insira um valor double para a coluna %s:\n", nomeColuna);
                scanf("%lf", &novaLinha.valoresDouble);
                break;
            case 2:
                printf("Insira um valor float para a coluna %s:\n", nomeColuna);
                scanf("%f", &novaLinha.valoresFloat);
                break;
            case 3:
                printf("Insira um valor char para a coluna %s:\n", nomeColuna);
                scanf(" %c", &novaLinha.valoresChar); // Note o espaço antes de %c para consumir possíveis espaços em branco
                break;
            case 4:
                printf("Insira um valor string para a coluna %s:\n", nomeColuna);
                scanf("%s", novaLinha.valoresString);
                break;
            default:
                printf("Tipo de coluna desconhecido/errado\n");
                break;
        }
    }

    // Salvar a nova linha no arquivo da tabela
    //fprintf(arquivo, "Número da Linha: %d\n", tabela->colunas[0].linhas[0].numeroLinha); // Você pode implementar a lógica para obter o próximo número da linha
    // Aqui você pode adicionar cada valor da nova linha ao arquivo conforme necessário, por exemplo:
    // fprintf(arquivo, "Valores: %d, %lf, %f, %c, %s\n", novaLinha.valoresInt, novaLinha.valoresDouble, novaLinha.valoresFloat, novaLinha.valoresChar, novaLinha.valoresString);
    // A linha acima é um exemplo de como poderia ser a estruturação dos valores no arquivo

    printf("Nova linha adicionada com sucesso no arquivo da tabela %s.\n", tabela->nomeTabela);

    // Fechar o arquivo após adicionar a nova linha
    fclose(arquivo);
}