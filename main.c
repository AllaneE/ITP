//Banco de Dados de ITP

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "meusStruct.h"
#include "funcao_apagar_criar.h"
#include "funcao_listar_editar.h"

// função para listar todas as tabelas

//função para criar nova linha na tabela

//função para listar todos os dados da tabela

//função para pesquisar valor em uma tabela

//função para apagar uma trupla, apagar auma linha, de uma tabela

//função para apagar uma tabela

//menu
void menu(){
    printf("+++++++++++++++++++++++\n");
    printf("Digite 1 - Para criar uma tabela\n");
    printf("Digite 2 - Para apagar uma tabela\n");
    printf("Digite 3 - Para listar as tabelas\n");
    printf("Digite 4 - Para listar dados de uma tabela\n");
    printf("+++++++++++++++++++++++\n");
}

int main(void){
    const char *caminho = "..\\output";
    int resposta_usuario;
    int continua = 0;
    char nomeArquivo[50];
    printf("Olá, seja bem-vindo ao SGBD ITP \n");
    
    while(continua != 1){
        menu();
        scanf("%d", &resposta_usuario);

        switch (resposta_usuario)
        {
        case 1:
            printf("entrou no if");
            criarTab();
            break;
        case 2:
            printf("Que arquivo desejas apagar?\n");
            scanf("%s", nomeArquivo);
            apagarArquivo(nomeArquivo);
            break;
        case 3:
            listarTodasTabelas(caminho);
            break;
        case 4:
            printf("Que arquivo desejas listar?\n");
            scanf("%s", nomeArquivo);
            listarDadosTabela(nomeArquivo);
            break;
        case 5:
            printf("A que tabela desejas adicionar linhas?\n");
            scanf("%s", nomeArquivo);
            novaLinha(&nomeArquivo);
            break;
        default:
            printf("numero invalido :(\n");
            break;
        }
        printf("Se desejar sair do SGBD ITP digite: 1\n");
        scanf("%d", &continua);
    }
    
}