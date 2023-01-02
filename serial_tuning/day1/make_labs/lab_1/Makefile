CC	= cc
OPT	= -g -O3
WARN   = -Wall
CFLAGS	= $(OPT) $(WARN)
OBJECTS = main.o data.o io.o

excer1.exe: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o excer1.exe 

clean:
	@rm -f *.o core

realclean: clean
	@rm -f excer1.exe 

data.o: data.c data.h
	$(CC) $(CFLAGS) -c data.c

main.o: main.c data.h io.h
	$(CC) $(CFLAGS) -c main.c

io.o: io.h io.c
	$(CC) $(CFLAGS) -c io.c
