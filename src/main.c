#include <stdio.h>
#include "cliente.h"
#include "funcionario.h"
#include "quarto.h"
#include "estadia.h"

void menu() {
    printf("------ Hotel Descanso Garantido ------\n");
    printf("1. Cadastrar Cliente\n");
    printf("2. Consultar Clientes\n");
    printf("3. Cadastrar Funcionario\n");
    printf("4. Consultar Funcionarios\n");
    printf("5. Cadastrar Quarto\n");
    printf("6. Consultar Quartos\n");
    printf("7. Cadastrar Estadia\n");
    printf("8. Dar Baixa Estadia\n");
    printf("9. Consultar Estadias\n");
    printf("0. Sair\n");
    printf("--------------------------------------\n");
    printf("Escolha uma opção: ");
}

int main() {
    int opcao;
    do {
        menu();
        scanf("%d", &opcao);
        switch (opcao) {
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
        }
    } while (opcao != 0);
    return 0;
}
