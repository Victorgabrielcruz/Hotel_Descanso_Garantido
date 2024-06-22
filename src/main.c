#include <stdio.h>
#include "cliente.h"
#include "funcionario.h"
#include "quarto.h"
#include "estadia.h"

// Função que exibe o menu de opções do sistema.
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

// Função principal que controla o fluxo do programa.
int main() {
    int opcao;
    do {
        menu(); // Exibe o menu
        scanf("%d", &opcao); // Lê a opção escolhida pelo usuário
        switch (opcao) {
            case 1:
                cadastrarCliente(); // Chama a função para cadastrar um cliente
                break;
            case 2:
                consultarClientes(); // Chama a função para consultar clientes
                break;
            case 3:
                cadastrarFuncionario(); // Chama a função para cadastrar um funcionário
                break;
            case 4:
                consultarFuncionarios(); // Chama a função para consultar funcionários
                break;
            case 5:
                cadastrarQuarto(); // Chama a função para cadastrar um quarto
                break;
            case 6:
                consultarQuartos(); // Chama a função para consultar quartos
                break;
            case 7:
                cadastrarEstadia(); // Chama a função para cadastrar uma estadia
                break;
            case 8:
                darBaixaEstadia(); // Chama a função para dar baixa em uma estadia
                break;
            case 9:
                consultarEstadias(); // Chama a função para consultar estadias
                break;
            case 0:
                printf("Saindo...\n"); // Informa que o programa está sendo encerrado
                break;
            default:
                printf("Opção inválida!\n"); // Informa que a opção escolhida é inválida
        }
    } while (opcao != 0); // Continua exibindo o menu até que a opção de sair seja escolhida
    return 0;
}
