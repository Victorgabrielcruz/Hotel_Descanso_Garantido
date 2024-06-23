Dados de teste:
Clientes
Código: 1, Nome: João da Silva, Endereço: Rua A, 123, Telefone: (11) 1111-1111
Código: 2, Nome: Maria Souza, Endereço: Rua B, 456, Telefone: (22) 2222-2222
Funcionários
Código: 1, Nome: Carlos Pereira, Telefone: (33) 3333-3333, Cargo: Recepcionista, Salário: 2500.00
Código: 2, Nome: Ana Lima, Telefone: (44) 4444-4444, Cargo: Gerente, Salário: 4000.00
Quartos
Número: 101, Quantidade de Hóspedes: 2, Valor da Diária: 150.00, Status: livre
Número: 102, Quantidade de Hóspedes: 3, Valor da Diária: 200.00, Status: livre
Estadias
Código: 1, Data de Entrada: 01/06/2024, Data de Saída: 05/06/2024, Quantidade de Diárias: 4, Código do Cliente: 1, Número do Quarto: 101
Teste 1: Cadastro e Consulta de Cliente
Cadastro de Cliente
Vamos cadastrar um novo cliente.

Entrada Esperada:
Código do cliente: 3
Nome: Pedro Oliveira
Endereço: Rua C, 789
Telefone: (55) 5555-5555

Saída Esperada:
Cliente cadastrado com sucesso!

Código do Teste:
#include "cliente.h"

int main() {
    cadastrarCliente();
    consultarClientes();
    return 0;
}

Execução esperada após cadastro:
Lista de Clientes:
Código: 1
Nome: João da Silva
Endereço: Rua A, 123
Telefone: (11) 1111-1111
--------------------
Código: 2
Nome: Maria Souza
Endereço: Rua B, 456
Telefone: (22) 2222-2222
--------------------
Código: 3
Nome: Pedro Oliveira
Endereço: Rua C, 789
Telefone: (55) 5555-5555



Teste 2: Registro e Baixa de Estadia
Registro de Estadia
Vamos registrar uma nova estadia.

Entrada Esperada:
Código da estadia: 2
Data de entrada (dd/mm/aaaa): 10/06/2024
Data de saída (dd/mm/aaaa): 15/06/2024
Quantidade de diárias: 5
Código do cliente: 2
Número do quarto: 102

Saída Esperada:
Estadia cadastrada com sucesso!

Baixa de Estadia
Vamos dar baixa na estadia registrada.

Entrada Esperada:
Código da estadia para dar baixa: 2

Saída Esperada:
Baixa de estadia realizada com sucesso!

Código do Teste:

c
Copy code
#include "estadia.h"

int main() {
    cadastrarEstadia();
    consultarEstadias();
    darBaixaEstadia();
    consultarEstadias();
    return 0;
}

Execução Esperada (após registro e baixa):
Lista de Estadias:
Código: 1
Data de entrada: 01/06/2024
Data de saída: 05/06/2024
Quantidade de diárias: 4
Código do cliente: 1
Número do quarto: 101
--------------------
Código: 2
Data de entrada: 10/06/2024
Data de saída: 15/06/2024
Quantidade de diárias: 5
Código do cliente: 2
Número do quarto: 102
--------------------
Lista de Estadias:
Código: 1
Data de entrada: 01/06/2024
Data de saída: 05/06/2024
Quantidade de diárias: 4
Código do cliente: 1
Número do quarto: 101
