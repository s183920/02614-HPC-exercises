CC	= gcc
OPT	= -g -O3
WARN   = -Wall
CFLAGS	= $(OPT) $(WARN)
OBJECTS = main.o data.o io.o

excer2.exe: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o excer2.exe


# clean up
clean: 
	@rm -f *.o core

realclean: clean
	@rm -f excer2.exe


# file dependencies
data.o: data.c data.h
main.o: main.c data.h io.h
io.o: io.h io.c

# Try to run 'make -r'?  What happens?  Why? 
# it cannot find .o files

# Run make with the compiler flags '-g -O2' _without_ changing the Makefile.  How can you achieve that?
# make OPT='-g -O2'




