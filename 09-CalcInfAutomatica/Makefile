TARGET = Calc.out
CC = gcc
CFLAGS = -std=c18 -g

FLEXL = Scanner.l
FLEXC = Scanner.c

BISONY = Parser.y
BISONC = Parser.c
BISONH = Token.h
BISON = Parser


.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(BISONC) $(FLEXC) $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) $(LIBS) -o $@

$(FLEXC): $(FLEXL)
	flex -o$(FLEXC) $(FLEXL)

$(BISONC): $(BISONY)
	bison -o$(BISONC) $(BISONY) --defines=$(BISONH)
	
clean:
	-rm -f *.o
	-rm -f $(TARGET)