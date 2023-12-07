#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "meusStruct.h"

void listarTabela(){
    char nomeTabela;
    printf("Qual o nome da tabela?\n");
    scanf("%s",&nomeTabela);
    
    FILE *arquivo fopen(nomeTabela, "r");

    if(arquivo==NULL){
        printf("Error ao abrir arquivo!\n");

        return;
    }

    Tabela tabela;
    fread(&tabela, sizeof(Tabela), 1, arquivo);

    for(int i=0; i<tabela.numeroColuna; i++){
        printf("%s\t", tabela.colunas[i].nomeTabela);
    }
    printf("\n");

    Linha leitura;
    while (fread(&leituraLinha, sizeof(Linha), 1, arquivo) == 1) {
        printf("%d\t", leitura.chavePrimaria);
        printf("%s\t", leitura.colunaString);
        printf("%s\t", leitura.colunaChar);
        printf("%d\t", leitura.colunaInt);
        printf("%d\t", leitura.colunaDouble);
        printf("%ln\t", leitura.colunaFloat);
        printf("\n");
    }

    fclose(arquivo);
}