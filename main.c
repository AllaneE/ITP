//Banco de Dados de ITP
//Por Allane e Ignacio 😎
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "structs.h"
#include "funcoesApagar.h"
#include "funcoesCriar.h"
#include "funcoesListar.h"
#include "funcoesPesquisa.h"

// Menu principal
void menu(){
    printf("--------------MENU PRINCIPAL-----------\n");
    printf("1. Criar uma tabela\n");
    printf("2. Listar todas as tabelas\n");
    printf("3: Adicionar uma nova linha na tabela\n");
    printf("4: Listar todos os dados de uma tabela\n");
    printf("5. Pesquisar valor em uma tabela\n");
    printf("6. Apagar uma tupla de uma tabela\n");
    printf("7. Apagar uma tabela\n");
    printf("0. Sair\n");
    printf("----------------------------------------\n");
    
}

int main() {
    Tabela tabelas[100]; 
    int numTabelas = 0; 
    int escolha;

    //laço para que o programa se repita até o usuario desejar parar
    do {
        menu();
        printf("Escolha o que deseja fazer\n");
        scanf("%d", &escolha);

        //condicionais para executar cada opção
        switch (escolha) {

            // caso para criar uma nova tabela
            case 1:
                criarTabela(&tabelas[numTabelas]);
                numTabelas++;
                break;

            //listar todas as tabelas
            case 2:
                listarTabelas(tabelas, numTabelas);
                break;

            //caso para o usuario adicionar uma nova linha a tabela
            case 3:
                adicionarLinha(tabelas, numTabelas);
                break;

            //caso para listar todos os dados de uma tabela
            case 4:
                listarDadosTabela(tabelas, numTabelas);
                break;

            //caso para pesquisar os valores de uma tabela
            case 5:
                pesquisarValor(tabelas, numTabelas);
                break;

            //caso para apagar uma trupla ou uma linha
            case 6:
                apagarTupla(tabelas, numTabelas);
                break;

            //caso para apagar toda uma tabela
            case 7:
                apagarTabela(tabelas, &numTabelas);
                break;

            //caso para sair do programa
            case 0:
                printf("Saindo do programa.\n");
                break;

            //caso o usurio coloque algum valor fora dos ofertados
            default:
                printf("Escolha inválida. Tente novamente.\n");
        }

    } while (escolha != 0);

    return 0;
}