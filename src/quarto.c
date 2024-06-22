#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quarto.h"

// Função para cadastrar um novo quarto.
void cadastrarQuarto() {
    Quarto quarto;
    FILE *file = fopen("data/quartos.dat", "ab"); // Abre o arquivo de quartos em modo de adição binária.
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de quartos!\n");
        return;
    }

    // Solicita e lê os dados do novo quarto.
    printf("Número do quarto: ");
    scanf("%d", &quarto.numero);
    printf("Quantidade de hóspedes: ");
    scanf("%d", &quarto.quantidadeHospedes);
    printf("Valor da diária: ");
    scanf("%f", &quarto.valorDiaria);
    strcpy(quarto.status, "livre"); // Define o status inicial do quarto como "livre".

    // Escreve o novo quarto no arquivo de quartos.
    fwrite(&quarto, sizeof(Quarto), 1, file);
    fclose(file);
    printf("Quarto cadastrado com sucesso!\n");
}

// Função para consultar todos os quartos registrados.
void consultarQuartos() {
    Quarto quarto;
    FILE *file = fopen("data/quartos.dat", "rb"); // Abre o arquivo de quartos em modo de leitura binária.
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de quartos!\n");
        return;
    }

    printf("\nLista de Quartos:\n");
    // Lê e exibe cada quarto registrado no arquivo.
    while (fread(&quarto, sizeof(Quarto), 1, file)) {
        printf("Número: %d\n", quarto.numero);
        printf("Quantidade de hóspedes: %d\n", quarto.quantidadeHospedes);
        printf("Valor da diária: %.2f\n", quarto.valorDiaria);
        printf("Status: %s\n", quarto.status);
        printf("--------------------\n");
    }
    fclose(file);
}
