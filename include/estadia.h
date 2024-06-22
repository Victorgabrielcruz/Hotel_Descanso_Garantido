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

#endif
