#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "meusStruct.h"
//Criar nova linha na tabela
/*void novaLinha(const Tabela *tabela){ 
    Linha novaLinha;
    int i;
    for(i = 0 ; i< tabela->numeroColuna ; i++){
        //Pega o nome da coluna atual
        char nomeColuna[50];
        strcpy(nomeColuna, tabela->colunas[i].nomeColuna);
        //pega o tipo da coluna atual
        switch (tabela->colunas[i].tipoColuna)
        {
        case 0:
            if(tabela->colunas[i].chavePrimaria == 1){
                printf("Essa coluna é a chave primaria");
            }
            printf("A coluna %s é do tipo INTEIRO, por favor adicione um valor inteiro à linha", nomeColuna);
            scanf("%d", &novaLinha.valoresInt);
            break;
        case 1:
            
            printf("A coluna %s é do tipo DOUBLE, por favor adicione um valor double à linha", nomeColuna);
            scanf("%lf", &novaLinha.valoresDouble);
            break;
        case 2:
            
            printf("A coluna %s é do tipo FLOAT , por favor adicione um valor float à linha", nomeColuna);
            scanf("%f", &novaLinha.valoresFloat);
            break;

        case 3:
            
            printf("A coluna %s é do tipo CHAR, por favor adicione um valor char à linha", nomeColuna);
            scanf("%c", &novaLinha.valoresChar);
            break;

        case 4:
            printf("A coluna %s é do tipo STRING, por favor adicione um valor string à linha", nomeColuna);
            scanf("%s", novaLinha.valoresString);
            break;

        default:
            printf("Tipo da coluna desconhecido/errado");
            break;
        }
    }

    
    a. Usuário deve informar o nome da tabela (recebe como atributo o nome da tabela)
    b. sistema deve solicitar os valores de cada uma das colunas
    c. sistema deve verificar a chave primária
        i. Em uma tabela deve existir um e apenas um valor de chave
        primária. Se o usuário informar uma chave que já existe,
        sistema deve emitir uma mensagem de erro e não deve inserir
        o registro */

//}
