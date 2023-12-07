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
    scanf("%s", novaTabela.nomeTabela);

    printf("Qual a quantidade desejada de colunas na tabela?\n");
    scanf("%d", &numeroColuna);

    novaTabela.numeroColuna = numeroColuna;

    for (int i = 0; i < numeroColuna; i++){
        printf("Qual o nome da coluna?\n");
        scanf("%s", novaTabela.colunas[i].nomeColuna);

        printf("A coluna é a chave primaria da coluna?(sim ou nao)\n");
        scanf("%s", resp);
        //transformar a resposta em minusculo para evitar erros
        for (int j = 0; resp[j] != '\0'; j++) {
            resp[j] = tolower(resp[j]);
        }

        // converter a resposta em valores inteiros
        if (strcmp(resp,"sim") == 0) {
            novaTabela.colunas[i].chavePrimaria = 1;
        }else{
            novaTabela.colunas[i].chavePrimaria = 0;
        } 

        printf("Qual o tipo de dado da coluna? (0 - int, 1 - double, 2 - float, 3 - char, 4 - string\n");
        scanf("%d", &novaTabela.colunas[i].tipoColuna);
    
          
    }

    //Salvar informações da tabela em um arquivo;
    FILE *arquivo = fopen(novaTabela.nomeTabela, "ab");
    if(arquivo != NULL){
        fwrite(&novaTabela, sizeof(Tabela), 1, arquivo);
        fclose(arquivo);
        printf("Tabela criada\n");
    }else{
        printf("Erro\n");
    }
    
    return novaTabela;
}

void apagarArquivo(const char *nomeArquivo) {
    if(remove(nomeArquivo)==0){
        printf("Arquivo '%s' apagado com sucesso.\n", nomeArquivo);
    }else {
        printf("Erro ao excluir o arquivo.\n");
    }
}
