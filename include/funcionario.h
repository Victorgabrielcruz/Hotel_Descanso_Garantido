#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

typedef struct {
    int codigo;
    char nome[100];
    char telefone[15];
    char cargo[50];
    float salario;
} Funcionario;

void cadastrarFuncionario();
void consultarFuncionarios();

#endif