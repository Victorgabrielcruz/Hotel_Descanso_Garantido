#ifndef ESTADIA_H
#define ESTADIA_H

// Definição da estrutura Estadia, que representa uma estadia de um cliente em um hotel.
typedef struct {
    int codigo;              // Código único da estadia
    char dataEntrada[11];    // Data de entrada no formato "dd/mm/aaaa"
    char dataSaida[11];      // Data de saída no formato "dd/mm/aaaa"
    int quantidadeDiarias;   // Quantidade de diárias da estadia
    int codigoCliente;       // Código do cliente que realizou a estadia
    int numeroQuarto;        // Número do quarto onde o cliente ficou hospedado
} Estadia;

// Função para cadastrar uma nova estadia.
// Esta função provavelmente solicitará ao usuário informações sobre a estadia
// e as armazenará em um registro ou banco de dados.
void cadastrarEstadia();

// Função para dar baixa em uma estadia existente.
// Esta função provavelmente atualizará o status da estadia para indicar que
// o cliente fez o checkout e a estadia foi concluída.
void darBaixaEstadia();

// Função para consultar todas as estadias registradas.
// Esta função provavelmente exibirá uma lista de todas as estadias armazenadas,
// possivelmente com filtros ou critérios de busca específicos.
void consultarEstadias();

#endif
