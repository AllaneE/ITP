# SGBD ITP

## Introdução🤯
Este projeto é uma implementação de um sistema de gerenciamento de banco de dados simplificado, baseado no modelo relacional. O objetivo principal é aplicar os conceitos abordados durante a disciplina de Introdução às Técnicas de Programação.

## Guia de Uso📖
Para executar o projeto, é necessário ter um compilador de C instalado no sistema operacional. Após compilar o arquivo main, um executável chamado main.exe será gerado. Basta executar esse arquivo para iniciar o programa.😎

## Arquitetura e Design📝
Os arquivos estão organizados de acordo com suas funções dentro do código. Eles foram divididos com base nas operações de criar, listar, pesquisar e apagar (CRUD). Os arquivos gerados a partir do código são armazenados na pasta chamada "output". Durante o projeto, foi adotado o padrão de nomenclatura camelCase.

## Código💻

### funcoesCriar.h
#### criarTabela()
Esta função tem a finalidade de criar uma tabela e armazenar seus dados em um arquivo .txt com o nome da tabela. Além disso, adiciona um registro à lista de tabelas. Caso a operação seja bem-sucedida, uma mensagem de sucesso é exibida; caso contrário, uma mensagem de erro é exibida.

#### adicionarLinha()
Essa função adiciona um registro à tabela selecionada pelo usuário, armazenando os dados em uma nova linha do arquivo .txt correspondente. Exibe uma mensagem de sucesso em caso de êxito e uma mensagem de erro em caso contrário.

### funcoesApagar.h
#### apagarTupla()
Permite apagar uma tupla de dados de um arquivo que representa uma tabela em um banco de dados simples. Solicita ao usuário o nome da tabela e a chave primária da tupla a ser removida.

#### apagarTabela()
Permite apagar toda uma tabela, incluindo seu registro no arquivo "tabelas.txt" (onde são armazenados os nomes das tabelas existentes). O processo é semelhante à função anterior, com algumas diferenças.

### funcoesListar.h
#### listarTabelas()
Exibe os nomes de todas as tabelas existentes através do arquivo tabelas.txt.

#### listarDadosTabela()
Lista os dados de uma tabela específica. Solicita ao usuário o nome da tabela e exibe suas informações.

### funcoesPesquisa.h
#### escolhaOperacao()
Apresenta um menu de opções de comparação e solicita ao usuário que faça uma escolha. Retorna o número correspondente à escolha do usuário.

#### pesquisarValor()
Permite que o usuário pesquise valores em uma coluna específica de uma tabela escolhida por ele. Essencialmente, busca por um valor específico em uma coluna determinada de uma tabela e apresenta os resultados com base nas escolhas de comparação feitas pelo usuário.
