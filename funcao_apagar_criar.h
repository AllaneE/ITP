#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "meusStruct.h"

// Função para criar tabela
Tabela criarTab(){
    Tabela novaTabela;
    int numeroColuna;
    char resp[5];

    printf("Qual o nome da tabela?\n");
    scanf("%s\n", novaTabela.nomeTabela);

    printf("Qual a quantidade desejada de colunas na tabela?\n");
    scanf("%d\n", &numeroColuna);

    novaTabela.numeroColuna = numeroColuna;

    for (int i = 0; i < numeroColuna; i++){
        printf("Qual o nome da coluna?\n");
        scanf("%s\n", novaTabela.colunas[i].nomeColuna);

        printf("A coluna é a chave primaria da coluna?\n");
        scanf("%s\n", resp);
        toLowerCase(resp);

        printf("Qual o tipo de dado coluna? (0 - int, 1 - double, 2 - float, 3 - char, 4 - string\n");
        scanf("%d\n", &novaTabela.colunas[i].tipoColuna);
    
        // converter a resposta em valores inteiros
        if (strcmp(resp,"sim") == 0) {
            novaTabela.colunas[i].chavePrimaria = 1;
        }else{
            novaTabela.colunas[i].chavePrimaria = 0;
        }   
    }

    //Salvar informações da tabela em um arquivo;
    FILE *arquivo = fopen(novaTabela.nomeTabela, "a+");
    if(arquivo != NULL){
        fwrite(&novaTabela, sizeof(Tabela), 1, arquivo);
        fclose(arquivo);
        printf("Tabela criada\n");
    }else{
        printf("Erro\n");
    }
    
    return novaTabela;
}

void apagarArquivo(const char *nomeArquivo){
    if(remove(*nomeArquivo)==0){
        printf("Arquivo '%s' apagado com sucesso.\n", nomeArquivo);
    }else{
        prinf("Erro ao excluir")
    }
}
