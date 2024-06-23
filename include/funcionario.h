#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

// Definição da estrutura Funcionario, que representa um funcionário de uma empresa.
typedef struct {
    int codigo;               // Código do funcionário
    char nome[100];           // Nome do funcionário
    char telefone[15];        // Telefone do funcionário
    char cargo[50];           // Cargo do funcionário
    float salario;            // Salário do funcionário
} Funcionario;

// Função para cadastrar um novo funcionário.
// Esta função solicita ao usuário informações sobre o funcionário
// e as armazena em um registro ou banco de dados.
void cadastrarFuncionario();

// Função para consultar todos os funcionários registrados.
// Esta função exibe uma lista de todos os funcionários armazenados,
// possivelmente com filtros ou critérios de busca específicos.
void consultarFuncionarios();

#endif