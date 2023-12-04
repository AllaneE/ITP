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

#endif