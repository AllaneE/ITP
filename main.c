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

int main() {
    Tabela tabelas[10]; // Assumindo no máximo 10 tabelas
    int numTabelas = 0;

    // Menu principal
    int escolha;
    do {
        printf("\n1. Criar uma tabela\n2. Listar todas as tabelas\n3. Adicionar uma nova linha na tabela\n");
        printf("4. Listar todos os dados de uma tabela\n5. Pesquisar valor em uma tabela\n6. Apagar uma tupla de uma tabela\n");
        printf("7. Apagar uma tabela\n0. Sair\nEscolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                criarTabela(&tabelas[numTabelas]);
                numTabelas++;
                break;
            case 2:
                //nao funciona ainda
                listarTabelas(tabelas, numTabelas);
                break;
            case 3:
                //n funciona ainda
                adicionarLinha(tabelas, numTabelas);
                break;
            case 4:
                listarDadosTabela(tabelas, numTabelas);
                break;
            case 5:
                pesquisarValor(tabelas, numTabelas);
                break;
            case 6:
                apagarTupla(tabelas, numTabelas);
                break;
            case 7:
                apagarTabela(tabelas, &numTabelas);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Escolha inválida. Tente novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}