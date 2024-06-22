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
