#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "meusStruct.h"

void salvarTabela(const Tabela *tabela, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo != NULL) {
        fprintf(arquivo, "Nome da Tabela: %s\n", tabela->nomeTabela);
        fprintf(arquivo, "Número de Colunas: %d\n", tabela->numeroColuna);

        for (int i = 0; i < tabela->numeroColuna; i++) {
            fprintf(arquivo, "Coluna %d:\n", i + 1);
            fprintf(arquivo, "\tNome da Coluna: %s\n", tabela->colunas[i].nomeColuna);
            fprintf(arquivo, "\tTipo de Dado: %d\n", tabela->colunas[i].tipoColuna);
            fprintf(arquivo, "\tChave Primária: %s\n", tabela->colunas[i].chavePrimaria ? "Sim" : "Não");
        }

        fclose(arquivo);
        printf("Informações da Tabela salvas com sucesso.\n");
    } else {
        printf("Erro ao abrir o arquivo para escrita.\n");
    }
}
// Função para criar tabela
Tabela criarTab(){
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

        printf("Qual o tipo de dado da coluna? (0 - int, 1 - double, 2 - float, 3 - char, 4 - string\n");
        scanf("%d", &novaTabela.colunas[i].tipoColuna);

        //define a chave primaria se nao houver uma ja definida
        //confere que o tipo de dado da coluna seja inteiro
        if(novaTabela.colunas[i].tipoColuna == 0 && pkDefinida != 1 ){
            printf("A coluna é a chave primaria da coluna?(sim ou nao)\n");
            scanf("%s", resp);
        }
        //transforma a resposta em minusculo para evitar erros
        for (int j = 0; resp[j] != '\0'; j++) {
            resp[j] = tolower(resp[j]);
        }

        // converte a resposta em valores inteiros
        if (strcmp(resp,"sim") == 0) {
            novaTabela.colunas[i].chavePrimaria = 1;
            //a chave primaria foi definida entao nao perguntamos mais
            pkDefinida = 1;
            strcpy(resp, "nao");
        }else{
            novaTabela.colunas[i].chavePrimaria = 0;
        } 
    }

    //Salvar informações da tabela em um arquivo;
    salvarTabela(&novaTabela , novaTabela.nomeTabela);
    
    return novaTabela;
}

//Apaga um arquivo
void apagarArquivo(const char *nomeArquivo) {
    if(remove(nomeArquivo)==0){
        printf("Arquivo '%s' apagado com sucesso.\n", nomeArquivo);
    }else {
        printf("Erro ao excluir o arquivo.\n");
    }
}
