#include <ctype.h>
#ifndef DEF
#define DEF

// Estruta para representar uma coluna
typedef struct {
    char nome[50];
    char tipo[10];
    int tamanho;
} Coluna;

// Estrutura para representar uma tabela
typedef struct {
    char nome[50];
    char chavePrimaria[50];
    Coluna colunas[100]; 
    int numColunas;
} Tabela;
#endif