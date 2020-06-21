SRC = String.c StringTest.c
OBJ = String.o StringTest.o
BIN = StringTest.out
CC = clang
CFLAGS = -std=c18

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS)

run: $(BIN)
	$(BIN)
	
$(OBJ): $(SRC)
	$(CC) -c $(SRC) $(CFLAGS)