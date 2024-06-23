Documentação do Projeto "Hotel Descanso Garantido - Sistema de Gerenciamento"
Introdução
O projeto "Hotel Descanso Garantido - Sistema de Gerenciamento" é um sistema desenvolvido para um hotel fictício. Ele permite a gestão de clientes, funcionários, quartos e estadias, com funcionalidades de cadastro, consulta e atualização dessas entidades, e persistência de dados em arquivos binários.

Estrutura do Projeto
O projeto está organizado da seguinte forma:

Fundamentos_AEDS/
├── include/
│   ├── cliente.h
│   ├── funcionario.h
│   ├── quarto.h
│   └── estadia.h
├── src/
│   ├── cliente.c
│   ├── funcionario.c
│   ├── quarto.c
│   ├── estadia.c
│   └── main.c
├── data/
│   ├── clientes.dat
│   ├── funcionarios.dat
│   ├── quartos.dat
│   └── estadias.dat
├── docs/
├── README.md
└── Makefile
include/: Diretório contendo todos os arquivos de cabeçalho (.h).
src/: Diretório contendo todos os arquivos fonte (.c).
data/: Diretório onde são armazenados os arquivos de dados (.dat).
docs/: Diretório para documentação adicional do projeto.
README.md: Arquivo de texto explicativo sobre o projeto, incluindo instruções de uso.
Makefile: Arquivo de construção para facilitar a compilação e limpeza do projeto.
Funcionalidades
Cadastro de clientes
Consulta de clientes
Cadastro de funcionários
Consulta de funcionários
Cadastro de quartos
Consulta de quartos
Registro de estadias
Baixa de estadias
Consulta de estadias

Arquivos de Cabeçalho (include/)
- cliente.h
Define a estrutura e as funções para gerenciamento de clientes.

- funcionario.h
Define a estrutura e as funções para gerenciamento de funcionários.

- quarto.h
Define a estrutura e as funções para gerenciamento de quartos.

- estadia.h
Define a estrutura e as funções para gerenciamento de estadias.


Arquivos Fonte (src/)
- cliente.c
Implementa as funções de cadastro e consulta de clientes.

- funcionario.c
Implementa as funções de cadastro e consulta de funcionários.

- quarto.c
Implementa as funções de cadastro e consulta de quartos.

- estadia.c
Implementa as funções de registro, baixa e consulta de estadias

- main.c
Implementa a interface do usuário e o menu principal.

Compilação e Execução
Para compilar o projeto, utilize o Makefile fornecido. No terminal, navegue até o diretório do projeto e execute.

Considerações Finais
O projeto "Hotel Descanso Garantido - Sistema de Gerenciamento" foi desenvolvido com o intuito de facilitar a gestão de um hotel,
proporcionando um sistema simples e eficiente para o controle de clientes, funcionários, quartos e estadias.
