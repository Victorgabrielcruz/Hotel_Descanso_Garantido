#ifndef QUARTO_H
#define QUARTO_H

// Definição da estrutura Quarto, que representa um quarto de hotel.
typedef struct {
    int numero;                // Número do quarto
    int quantidadeHospedes;    // Quantidade máxima de hóspedes que o quarto pode acomodar
    float valorDiaria;         // Valor da diária do quarto
    char status[10];           // Status do quarto (ex.: "livre", "ocupado", "manutenção")
} Quarto;

// Função para cadastrar um novo quarto.
// Esta função provavelmente solicitará ao usuário informações sobre o quarto
// e as armazenará em um registro ou banco de dados.
void cadastrarQuarto();

// Função para consultar todos os quartos registrados.
// Esta função provavelmente exibirá uma lista de todos os quartos armazenados,
// possivelmente com filtros ou critérios de busca específicos.
void consultarQuartos();

#endif
