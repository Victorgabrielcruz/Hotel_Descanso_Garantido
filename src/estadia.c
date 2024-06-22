#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estadia.h"
#include "cliente.h"
#include "quarto.h"

// Função para cadastrar uma nova estadia.
void cadastrarEstadia() {
    Estadia estadia;
    FILE *file = fopen("data/estadias.dat", "ab"); // Abre o arquivo de estadias em modo de adição binária.
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de estadias!\n");
        return;
    }

    // Solicita e lê os dados da nova estadia.
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

    // Atualiza o status do quarto para "ocupado".
    Quarto quarto;
    FILE *fileQuarto = fopen("data/quartos.dat", "rb+"); // Abre o arquivo de quartos em modo de leitura/escrita binária.
    while (fread(&quarto, sizeof(Quarto), 1, fileQuarto)) {
        if (quarto.numero == estadia.numeroQuarto) {
            strcpy(quarto.status, "ocupado");
            fseek(fileQuarto, -sizeof(Quarto), SEEK_CUR);
            fwrite(&quarto, sizeof(Quarto), 1, fileQuarto);
            break;
        }
    }
    fclose(fileQuarto);

    // Escreve a nova estadia no arquivo de estadias.
    fwrite(&estadia, sizeof(Estadia), 1, file);
    fclose(file);
    printf("Estadia cadastrada com sucesso!\n");
}

// Função para dar baixa em uma estadia existente.
void darBaixaEstadia() {
    int codigo;
    printf("Código da estadia para dar baixa: ");
    scanf("%d", &codigo);

    Estadia estadia;
    FILE *file = fopen("data/estadias.dat", "rb+"); // Abre o arquivo de estadias em modo de leitura/escrita binária.
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de estadias!\n");
        return;
    }

    int found = 0;
    while (fread(&estadia, sizeof(Estadia), 1, file)) {
        if (estadia.codigo == codigo) {
            found = 1;
            // Atualiza o status do quarto para "livre".
            Quarto quarto;
            FILE *fileQuarto = fopen("data/quartos.dat", "rb+"); // Abre o arquivo de quartos em modo de leitura/escrita binária.
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
        // Remove a estadia do arquivo.
        FILE *tempFile = fopen("data/temp.dat", "wb"); // Cria um arquivo temporário para armazenar as estadias restantes.
        rewind(file);
        while (fread(&estadia, sizeof(Estadia), 1, file)) {
            if (estadia.codigo != codigo) {
                fwrite(&estadia, sizeof(Estadia), 1, tempFile);
            }
        }
        fclose(file);
        fclose(tempFile);
        remove("data/estadias.dat"); // Remove o arquivo antigo.
        rename("data/temp.dat", "data/estadias.dat"); // Renomeia o arquivo temporário para o nome do arquivo original.
        printf("Estadia baixada com sucesso!\n");
    } else {
        fclose(file);
        printf("Estadia não encontrada!\n");
    }
}

// Função para consultar todas as estadias registradas.
void consultarEstadias() {
    Estadia estadia;
    FILE *file = fopen("data/estadias.dat", "rb"); // Abre o arquivo de estadias em modo de leitura binária.
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de estadias!\n");
        return;
    }

    printf("\nLista de Estadias:\n");
    // Lê e exibe cada estadia registrada no arquivo.
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
