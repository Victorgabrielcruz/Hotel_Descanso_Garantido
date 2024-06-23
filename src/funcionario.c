#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"

void cadastrarFuncionario() {
    Funcionario funcionario;
    FILE *file = fopen("data/funcionarios.dat", "ab");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de funcionarios!\n");
        return;
    }

    printf("Código do funcionário: ");
    scanf("%d", &funcionario.codigo);
    printf("Nome: ");
    scanf(" %[^\n]", funcionario.nome);
    printf("Telefone: ");
    scanf(" %[^\n]", funcionario.telefone);
    printf("Cargo: ");
    scanf(" %[^\n]", funcionario.cargo);
    printf("Salário: ");
    scanf("%f", &funcionario.salario);

    fwrite(&funcionario, sizeof(Funcionario), 1, file);
    fclose(file);
    printf("Funcionário cadastrado com sucesso!\n");
}

void consultarFuncionarios() {
    Funcionario funcionario;
    FILE *file = fopen("data/funcionarios.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de funcionarios!\n");
        return;
    }

    printf("\nLista de Funcionários:\n");
    while (fread(&funcionario, sizeof(Funcionario), 1, file)) {
        printf("Código: %d\n", funcionario.codigo);
        printf("Nome: %s\n", funcionario.nome);
        printf("Telefone: %s\n", funcionario.telefone);
        printf("Cargo: %s\n", funcionario.cargo);
        printf("Salário: %.2f\n", funcionario.salario);
        printf("--------------------\n");
    }
    fclose(file);
}