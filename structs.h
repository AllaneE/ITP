#include <ctype.h>
#ifndef DEF
#define DEF

// Estrutura para representar uma coluna da tabela
typedef struct {
    char nome[50];
    char tipo[10];
    int tamanho;
} Coluna;

// Estrutura para representar uma tabela
typedef struct {
    char nome[50];
    char chavePrimaria[50];
    Coluna colunas[10]; // Assumindo no máximo 10 colunas por tabela
    int numColunas;
} Tabela;
#endif