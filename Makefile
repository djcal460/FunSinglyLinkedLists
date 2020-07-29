CC=gcc
CFLAGS=-I.
DEPS = func.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

funfunlinkedlists: funfunlinkedlists.o menufunc.o llfunc.o
	$(CC) -o funfunlinkedlists funfunlinkedlists.o menufunc.o llfunc.o
clean:
	$(RM) funfunlinkedlists.o llfunc.o menufunc.o funfunlinkedlists
