Documentação do Projeto "Hotel Descanso Garantido - Sistema de Gerenciamento"
Introdução
O projeto "Hotel Descanso Garantido - Sistema de Gerenciamento" é um sistema desenvolvido para um hotel fictício. Ele permite a gestão de clientes, funcionários, quartos e estadias, com funcionalidades de cadastro, consulta e atualização dessas entidades, e persistência de dados em arquivos binários.

Estrutura do Projeto
O projeto está organizado da seguinte forma:

Fundamentos_AEDS/
├── include/
│   ├── cliente.h
│   ├── funcionario.h
│   ├── quarto.h
│   └── estadia.h
├── src/
│   ├── cliente.c
│   ├── funcionario.c
│   ├── quarto.c
│   ├── estadia.c
│   └── main.c
├── data/
│   ├── clientes.dat
│   ├── funcionarios.dat
│   ├── quartos.dat
│   └── estadias.dat
├── docs/
├── README.md
└── Makefile
include/: Diretório contendo todos os arquivos de cabeçalho (.h).
src/: Diretório contendo todos os arquivos fonte (.c).
data/: Diretório onde são armazenados os arquivos de dados (.dat).
docs/: Diretório para documentação adicional do projeto.
README.md: Arquivo de texto explicativo sobre o projeto, incluindo instruções de uso.
Makefile: Arquivo de construção para facilitar a compilação e limpeza do projeto.
Funcionalidades
Cadastro de clientes
Consulta de clientes
Cadastro de funcionários
Consulta de funcionários
Cadastro de quartos
Consulta de quartos
Registro de estadias
Baixa de estadias
Consulta de estadias

Arquivos de Cabeçalho (include/)
- cliente.h
Define a estrutura e as funções para gerenciamento de clientes.
#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct {
    int codigo;
    char nome[100];
    char endereco[200];
    char telefone[15];
} Cliente;

void cadastrarCliente();
void consultarClientes();

#endif // CLIENTE_H

- funcionario.h
Define a estrutura e as funções para gerenciamento de funcionários.
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

#endif // FUNCIONARIO_H

- quarto.h
Define a estrutura e as funções para gerenciamento de quartos.
#ifndef QUARTO_H
#define QUARTO_H

typedef struct {
    int numero;
    int quantidadeHospedes;
    float valorDiaria;
    char status[10];
} Quarto;

void cadastrarQuarto();
void consultarQuartos();

#endif // QUARTO_H


- estadia.h
Define a estrutura e as funções para gerenciamento de estadias.
#ifndef ESTADIA_H
#define ESTADIA_H

typedef struct {
    int codigo;
    char dataEntrada[11];
    char dataSaida[11];
    int quantidadeDiarias;
    int codigoCliente;
    int numeroQuarto;
} Estadia;

void cadastrarEstadia();
void darBaixaEstadia();
void consultarEstadias();

#endif // ESTADIA_H



Arquivos Fonte (src/)
- cliente.c
Implementa as funções de cadastro e consulta de clientes.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

void cadastrarCliente() {
    Cliente cliente;
    FILE *file = fopen("data/clientes.dat", "ab");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de clientes!\n");
        return;
    }

    printf("Código do cliente: ");
    scanf("%d", &cliente.codigo);
    printf("Nome: ");
    scanf(" %[^\n]", cliente.nome);
    printf("Endereço: ");
    scanf(" %[^\n]", cliente.endereco);
    printf("Telefone: ");
    scanf(" %[^\n]", cliente.telefone);

    fwrite(&cliente, sizeof(Cliente), 1, file);
    fclose(file);
    printf("Cliente cadastrado com sucesso!\n");
}

void consultarClientes() {
    Cliente cliente;
    FILE *file = fopen("data/clientes.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de clientes!\n");
        return;
    }

    printf("\nLista de Clientes:\n");
    while (fread(&cliente, sizeof(Cliente), 1, file)) {
        printf("Código: %d\n", cliente.codigo);
        printf("Nome: %s\n", cliente.nome);
        printf("Endereço: %s\n", cliente.endereco);
        printf("Telefone: %s\n", cliente.telefone);
        printf("--------------------\n");
    }
    fclose(file);
}


- funcionario.c
Implementa as funções de cadastro e consulta de funcionários.
fine QUARTO_H

typedef struct {
    int numero;
    int quantidadeHospedes;
    float valorDiaria;
    char status[10];
} Quarto;

void cadastrarQuarto();
void consultarQuartos();

#endif // QUARTO_H

- quarto.c
Implementa as funções de cadastro e consulta de quartos.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quarto.h"

void cadastrarQuarto() {
    Quarto quarto;
    FILE *file = fopen("data/quartos.dat", "ab");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de quartos!\n");
        return;
    }

    printf("Número do quarto: ");
    scanf("%d", &quarto.numero);
    printf("Quantidade de hóspedes: ");
    scanf("%d", &quarto.quantidadeHospedes);
    printf("Valor da diária: ");
    scanf("%f", &quarto.valorDiaria);
    strcpy(quarto.status, "livre");

    fwrite(&quarto, sizeof(Quarto), 1, file);
    fclose(file);
    printf("Quarto cadastrado com sucesso!\n");
}

void consultarQuartos() {
    Quarto quarto;
    FILE *file = fopen("data/quartos.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de quartos!\n");
        return;
    }

    printf("\nLista de Quartos:\n");
    while (fread(&quarto, sizeof(Quarto), 1, file)) {
        printf("Número: %d\n", quarto.numero);
        printf("Quantidade de hóspedes: %d\n", quarto.quantidadeHospedes);
        printf("Valor da diária: %.2f\n", quarto.valorDiaria);
        printf("Status: %s\n", quarto.status);
        printf("--------------------\n");
    }
    fclose(file);
}


- estadia.c
Implementa as funções de registro, baixa e consulta de estadias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estadia.h"
#include "cliente.h"
#include "quarto.h"

void cadastrarEstadia() {
    Estadia estadia;
    FILE *file = fopen("data/estadias.dat", "ab");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de estadias!\n");
        return;
    }

    printf("Código da estadia: ");
    scanf("%d", &estadia.codigo);
    printf("Data de entrada (dd/mm/yyyy): ");
    scanf("%s", estadia.dataEntrada);
    printf("Data de saída (dd/mm/yyyy): ");
    scanf("%s", estadia.dataSaida);
    printf("Quantidade de diárias: ");
    scanf("%d", &estadia.quantidadeDiarias);
    printf("Código do cliente: ");
    scanf("%d", &estadia.codigoCliente);
    printf("Número do quarto: ");
    scanf("%d", &estadia.numeroQuarto);

    // Atualiza status do quarto para ocupado
    FILE *fileQuartos = fopen("data/quartos.dat", "r+b");
    Quarto quarto;
    while (fread(&quarto, sizeof(Quarto), 1, fileQuartos)) {
        if (quarto.numero == estadia.numeroQuarto) {
            strcpy(quarto.status, "ocupado");
            fseek(fileQuartos, -sizeof(Quarto), SEEK_CUR);
            fwrite(&quarto, sizeof(Quarto), 1, fileQuartos);
            break;
        }
    }
    fclose(fileQuartos);

    fwrite(&estadia, sizeof(Estadia), 1, file);
    fclose(file);
    printf("Estadia cadastrada com sucesso!\n");
}

void darBaixaEstadia() {
    int codigoEstadia;
    printf("Código da estadia para dar baixa: ");
    scanf("%d", &codigoEstadia);

    FILE *file = fopen("data/estadias.dat", "r+b");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de estadias!\n");
        return;
    }

    Estadia estadia;
    int found = 0;
    while (fread(&estadia, sizeof(Estadia), 1, file)) {
        if (estadia.codigo == codigoEstadia) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Estadia não encontrada!\n");
        fclose(file);
        return;
    }

    // Atualiza status do quarto para livre
    FILE *fileQuartos = fopen("data/quartos.dat", "r+b");
    Quarto quarto;
    while (fread(&quarto, sizeof(Quarto), 1, fileQuartos)) {
        if (quarto.numero == estadia.numeroQuarto) {
            strcpy(quarto.status, "livre");
            fseek(fileQuartos, -sizeof(Quarto), SEEK_CUR);
            fwrite(&quarto, sizeof(Quarto), 1, fileQuartos);
            break;
        }
    }
    fclose(fileQuartos);

    // Remove a estadia do arquivo
    FILE *fileTemp = fopen("data/temp.dat", "wb");
    rewind(file);
    while (fread(&estadia, sizeof(Estadia), 1, file)) {
        if (estadia.codigo != codigoEstadia) {
            fwrite(&estadia, sizeof(Estadia), 1, fileTemp);
        }
    }
    fclose(file);
    fclose(fileTemp);

    remove("data/estadias.dat");
    rename("data/temp.dat", "data/estadias.dat");

    printf("Baixa de estadia realizada com sucesso!\n");
}

void consultarEstadias() {
    Estadia estadia;
    FILE *file = fopen("data/estadias.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de estadias!\n");
        return;
    }

    printf("\nLista de Estadias:\n");
    while (fread(&estadia, sizeof(Estadia), 1, file)) {
        printf("Código: %d\n", estadia.codigo);
        printf("Data de entrada: %s\n", estadia.dataEntrada);
        printf("Data de saída: %s\n", estadia.dataSaida);
        printf("Quantidade de diárias: %d\n", estadia.quantidadeDiarias);
        printf("Código do cliente: %d\n", estadia.codigoCliente);
        printf("Número do quarto: %d\n", estadia.numeroQuarto);
        printf("--------------------\n");
    }
    fclose(file);
}


- main.c
Implementa a interface do usuário e o menu principal.
#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "funcionario.h"
#include "quarto.h"
#include "estadia.h"

int main() {
    int opcao;

    do {
        printf("\nMenu Principal\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Consultar Clientes\n");
        printf("3. Cadastrar Funcionário\n");
        printf("4. Consultar Funcionários\n");
        printf("5. Cadastrar Quarto\n");
        printf("6. Consultar Quartos\n");
        printf("7. Registrar Estadia\n");
        printf("8. Dar Baixa em Estadia\n");
        printf("9. Consultar Estadias\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                consultarClientes();
                break;
            case 3:
                cadastrarFuncionario();
                break;
            case 4:
                consultarFuncionarios();
                break;
            case 5:
                cadastrarQuarto();
                break;
            case 6:
                consultarQuartos();
                break;
            case 7:
                cadastrarEstadia();
                break;
            case 8:
                darBaixaEstadia();
                break;
            case 9:
                consultarEstadias();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while(opcao != 0);

    return 0;
}


Compilação e Execução
Para compilar o projeto, utilize o Makefile fornecido. No terminal, navegue até o diretório do projeto e execute.

Considerações Finais
O projeto "Hotel Descanso Garantido - Sistema de Gerenciamento" foi desenvolvido com o intuito de facilitar a gestão de um hotel,
proporcionando um sistema simples e eficiente para o controle de clientes, funcionários, quartos e estadias.
