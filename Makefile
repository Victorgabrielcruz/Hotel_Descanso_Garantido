CC = gcc
CFLAGS = -Wall -I include
OBJ = ./src/cliente.o src/funcionario.o src/quarto.o src/estadia.o src/main.o
EXEC = HotelDescansoGarantido

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

src/cliente.o: ./src/cliente.c ./include/cliente.h
	$(CC) $(CFLAGS) -c ./src/cliente.c -o ./src/cliente.o

src/funcionario.o: ./src/funcionario.c include/funcionario.h
	$(CC) $(CFLAGS) -c ./src/funcionario.c -o ./src/funcionario.o

src/quarto.o: ./src/quarto.c include/quarto.h
	$(CC) $(CFLAGS) -c ./src/quarto.c -o ./src/quarto.o

src/estadia.o: ./src/estadia.c ./include/estadia.h
	$(CC) $(CFLAGS) -c ./src/estadia.c -o ./src/estadia.o

src/main.o: ./src/main.c ./include/cliente.h ./include/funcionario.h ./include/quarto.h ./include/estadia.h
	$(CC) $(CFLAGS) -c ./src/main.c -o ./src/main.o

clean:
	rm -f src/*.o $(EXEC)