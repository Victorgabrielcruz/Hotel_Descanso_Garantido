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
    Quarto quarto;
    FILE *fileQuarto = fopen("data/quartos.dat", "rb+");
    while (fread(&quarto, sizeof(Quarto), 1, fileQuarto)) {
        if (quarto.numero == estadia.numeroQuarto) {
            strcpy(quarto.status, "ocupado");
            fseek(fileQuarto, -sizeof(Quarto), SEEK_CUR);
            fwrite(&quarto, sizeof(Quarto), 1, fileQuarto);
            break;
        }
    }
    fclose(fileQuarto);

    fwrite(&estadia, sizeof(Estadia), 1, file);
    fclose(file);
    printf("Estadia cadastrada com sucesso!\n");
}

void darBaixaEstadia() {
    int codigo;
    printf("Código da estadia para dar baixa: ");
    scanf("%d", &codigo);

    Estadia estadia;
    FILE *file = fopen("data/estadias.dat", "rb+");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de estadias!\n");
        return;
    }

    int found = 0;
    while (fread(&estadia, sizeof(Estadia), 1, file)) {
        if (estadia.codigo == codigo) {
            found = 1;
            // Atualiza status do quarto para livre
            Quarto quarto;
            FILE *fileQuarto = fopen("data/quartos.dat", "rb+");
            while (fread(&quarto, sizeof(Quarto), 1, fileQuarto)) {
                if (quarto.numero == estadia.numeroQuarto) {
                    strcpy(quarto.status, "livre");
                    fseek(fileQuarto, -sizeof(Quarto), SEEK_CUR);
                    fwrite(&quarto, sizeof(Quarto), 1, fileQuarto);
                    break;
                }
            }
            fclose(fileQuarto);
            break;
        }
    }

    if (found) {
        // Remove a estadia do arquivo
        FILE *tempFile = fopen("data/temp.dat", "wb");
        rewind(file);
        while (fread(&estadia, sizeof(Estadia), 1, file)) {
            if (estadia.codigo != codigo) {
                fwrite(&estadia, sizeof(Estadia), 1, tempFile);
            }
        }
        fclose(file);
        fclose(tempFile);
        remove("data/estadias.dat");
        rename("data/temp.dat", "data/estadias.dat");
        printf("Estadia baixada com sucesso!\n");
    } else {
        fclose(file);
        printf("Estadia não encontrada!\n");
    }
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
