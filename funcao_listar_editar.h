#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "meusStruct.h"

void listarTabela(){
    char nomeTabela[50];
    printf("Qual o nome da tabela?\n");
    scanf("%s", nomeTabela);
    
    char nomeArquivo[100]; // Variável para armazenar o nome do arquivo
    snprintf(nomeArquivo, sizeof(nomeArquivo), "%s.bin", nomeTabela); // Adiciona a extensão .bin ao nome do arquivo

    FILE *arquivo;
    arquivo = fopen(nomeArquivo , "rb");

    if(arquivo==NULL){
        printf("Error ao abrir arquivo!\n");

        return;
    }

    Tabela tabela;
    fread(&tabela, sizeof(Tabela), 1, arquivo);
    //Listar tabela
    for(int i=0; i<tabela.numeroColuna; i++){
        printf("%s\t", tabela.colunas[i].nomeColuna);
    }
    printf("\n");

    Linha leitura;
    while (fread(&leitura, sizeof(Linha), 1, arquivo) == 1) {
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