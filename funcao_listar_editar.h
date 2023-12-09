#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "meusStruct.h"

void listarTabela(){
    char nomeTabela[50];
    printf("Qual o nome da tabela?\n");
    scanf("%s", nomeTabela);
    
    char nomeArquivo[100]; // Variável para armazenar o nome do arquivo
    snprintf(nomeArquivo, sizeof(nomeArquivo), "%s.bin", nomeTabela); // Adiciona a extensão .bin ao nome do arquivo

    FILE *arquivo;
    arquivo = fopen(nomeArquivo , "r");

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
        printf("%f\t", leitura.colunaDouble);
        printf("%f\t", leitura.colunaFloat);
        printf("\n");
    }

    fclose(arquivo);
}

void listarTodasTabelas(const char *caminho){
    struct dirent *entrada;
    DIR *diretorio;

    diretorio = opendir(caminho);

    if (diretorio == NULL) {
        perror("Erro ao abrir o diretório");
        exit(EXIT_FAILURE);
    }

    printf("Listando as tabelas... \n");
    printf("--------------------------\n");
    while ((entrada = readdir(diretorio)) != NULL) {
        // Ignorar arquivos com extensão .exe
        if (strstr(entrada->d_name, ".exe") == NULL) {
            printf("%s\n", entrada->d_name);
        }
    }
    printf("--------------------------\n");
    closedir(diretorio);
}

//Listar dados de uma tabela(os dados deverão ser obtidos a partir do arquivo que armazena)
void listarDadosTabela(const char *nomeArquivo){
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    printf("Conteúdo do arquivo '%s':\n", nomeArquivo);

    char caractere;
    while ((caractere = fgetc(arquivo)) != EOF) {
        printf("%c", caractere);
    }

    fclose(arquivo);
}