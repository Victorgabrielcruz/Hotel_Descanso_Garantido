#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"

// Função para cadastrar um novo funcionário.
void cadastrarFuncionario() {
    Funcionario funcionario; // Declara uma variável do tipo Funcionario.
    FILE *file = fopen("data/funcionarios.dat", "ab"); // Abre o arquivo de funcionários em modo de adição binária.
    if (file == NULL) {
        // Verifica se o arquivo foi aberto corretamente.
        // Caso não tenha sido possível abrir o arquivo, imprime uma mensagem de erro e retorna.
        printf("Erro ao abrir o arquivo de funcionarios!\n");
        return;
    }

    // Solicita e lê os dados do novo funcionário.
    printf("Código do funcionário: ");
    scanf("%d", &funcionario.codigo); // Lê o código do funcionário.
    printf("Nome: ");
    scanf(" %[^\n]", funcionario.nome); // Lê o nome do funcionário, permitindo espaços.
    printf("Telefone: ");
    scanf(" %[^\n]", funcionario.telefone); // Lê o telefone do funcionário, permitindo espaços.
    printf("Cargo: ");
    scanf(" %[^\n]", funcionario.cargo); // Lê o cargo do funcionário, permitindo espaços.
    printf("Salário: ");
    scanf("%f", &funcionario.salario); // Lê o salário do funcionário.

    // Escreve os dados do novo funcionário no arquivo de funcionários.
    fwrite(&funcionario, sizeof(Funcionario), 1, file); // Escreve o registro do funcionário no arquivo.
    fclose(file); // Fecha o arquivo.
    printf("Funcionário cadastrado com sucesso!\n"); // Informa que o cadastro foi realizado com sucesso.
}

// Função para consultar todos os funcionários registrados.
void consultarFuncionarios() {
    Funcionario funcionario; // Declara uma variável do tipo Funcionario.
    FILE *file = fopen("data/funcionarios.dat", "rb"); // Abre o arquivo de funcionários em modo de leitura binária.
    if (file == NULL) {
        // Verifica se o arquivo foi aberto corretamente.
        // Caso não tenha sido possível abrir o arquivo, imprime uma mensagem de erro e retorna.
        printf("Erro ao abrir o arquivo de funcionarios!\n");
        return;
    }

    printf("\nLista de Funcionários:\n");
    // Lê e exibe cada funcionário registrado no arquivo.
    while (fread(&funcionario, sizeof(Funcionario), 1, file)) {
        // Lê um registro de funcionário do arquivo e imprime suas informações.
        printf("Código: %d\n", funcionario.codigo);
        printf("Nome: %s\n", funcionario.nome);
        printf("Telefone: %s\n", funcionario.telefone);
        printf("Cargo: %s\n", funcionario.cargo);
        printf("Salário: %.2f\n", funcionario.salario);
        printf("--------------------\n");
    }
    fclose(file); // Fecha o arquivo.
}