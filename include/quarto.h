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

#endif
