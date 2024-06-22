#ifndef CLIENTE_H
#define CLIENTE_H

/**
 * Estrutura: Cliente
 * -------------------
 * Esta estrutura representa um cliente com os seguintes campos:
 * - codigo: Código único do cliente (inteiro).
 * - nome: Nome do cliente (string com até 100 caracteres).
 * - endereco: Endereço do cliente (string com até 200 caracteres).
 * - telefone: Telefone do cliente (string com até 15 caracteres).
 */
typedef struct {
    int codigo;
    char nome[100];
    char endereco[200];
    char telefone[15];
} Cliente;

/**
 * Função: cadastrarCliente
 * -------------------------
 * Declaração da função que permite cadastrar um novo cliente.
 * A implementação desta função está no arquivo de código fonte correspondente.
 */
void cadastrarCliente();

/**
 * Função: consultarClientes
 * -------------------------
 * Declaração da função que permite consultar e listar todos os clientes cadastrados.
 * A implementação desta função está no arquivo de código fonte correspondente.
 */
void consultarClientes();

#endif // CLIENTE_H
