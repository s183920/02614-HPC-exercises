CC	= gcc 
# OPT	= -g -O3 -std=c99 -funroll-loops -flto -ffast-math
OPT = -g -std=c99 -ffast-math
CHIP	= 
LIBS	= -lm
CFLAGS  = $(OPT) $(CHIP) $(ISA) $(DEFS) $(XOPT)

SOURCES = ex1.c
OBJECTS = $(SOURCES:.c=.o)

TARGETS = ex1 ex1_autopar


ex1: clean $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(OBJECTS) $(LIBS)

ex1_autopar: clean $(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(OBJECTS) $(LIBS) -ftree-parallelize-loops=4

test_ex1: ex1 ex1_autopar
	@echo "ex1 basic "
	@/usr/bin/time --format="Time = %E" ./ex1 100000000
	@echo "ex1 with -ftree-parallelize-loops=4"
	@/usr/bin/time --format="Time = %E" ./ex1_autopar 100000000



clean:
	@/bin/rm -f $(OBJECTS) core

realclean: clean
	@/bin/rm -f $(TARGETS)




