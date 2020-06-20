IDIR =../04-Strings
CC=clang
CFLAGS=-std=c18

ODIR=./

_DEPS = String.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = StringTest.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# testmake: $(OBJ)
# 	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 