#include <ctype.h>
#ifndef DEF
#define DEF

typedef struct{
    int chavePrimaria;
    int tipoColuna;
    char nomeColuna[100];
} Coluna;

typedef struct{
    char nomeTabela[100];
    Coluna colunas[100];
    int numeroColuna;
} Tabela;

//Função para converter string para minúscula
void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

#endif