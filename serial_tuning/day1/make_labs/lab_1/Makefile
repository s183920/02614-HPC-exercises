CC	= cc
OPT	= -g -O3
WARN   = -Wall
CFLAGS	= $(OPT) $(WARN)
OBJECTS = main.o data.o io.o

lab1: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o lab1 

clean:
	@rm -f *.o core

realclean: clean
	@rm -f lab1

data.o: data.c data.h
	$(CC) $(CFLAGS) -c data.c

main.o: main.c data.h io.h
	$(CC) $(CFLAGS) -c main.c

io.o: io.h io.c
	$(CC) $(CFLAGS) -c io.c
