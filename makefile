IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -ftest-coverage -fprofile-arcs --coverage

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = catch.hpp romanos.hpp 
DEPS = $(patsubst % , $(IDIR)/% , $(_DEPS))

_OBJ = romanos.o testa_romanos.o
OBJ = $(patsubst % , $(ODIR)/% , $(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

romanos: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/.o *~ core $(INCDIR)/~