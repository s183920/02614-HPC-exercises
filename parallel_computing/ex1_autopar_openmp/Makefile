CC	= gcc
# OPT	= -g -O3 -std=c99 -funroll-loops -flto -ffast-math
OPT = -g -std=c99
CHIP	= 
LIBS	= -lm
CFLAGS  = $(OPT) $(CHIP) $(ISA) $(DEFS) $(XOPT)

# SOURCES = ex1.c
# OBJECTS = $(SOURCES:.c=.o)

# TARGETS = ex1 ex1_autopar ex1_openmp


ex1: realclean
	@echo
	@echo "ex1 basic "
	gcc -O3 -ffast-math  -o ex1_basic ex1.c
	@/usr/bin/time --format="Time = %E" ./ex1_basic
	@echo
	@echo "ex1 autopar"
	gcc -O3 -ffast-math -ftree-parallelize-loops=4 -o ex1_autopar ex1.c
	@/usr/bin/time --format="Time = %E" ./ex1_autopar
	@echo
	@echo "ex1 openmp"
	gcc -O3 -ffast-math -fopenmp -o ex1_openmp  ex1.c
	@OMP_NUM_THREADS=4 /usr/bin/time --format="Time = %E" ./ex1_openmp
	@echo


hello: realclean
	$(CC) -o $@ $(CFLAGS) -fopenmp hello.c $(LIBS)
	OMP_NUM_THREADS=4 ./hello

clean:
	@/bin/rm -f $(OBJECTS) core
	@/bin/rm -f hello.o

realclean: clean
	@/bin/rm -f hello ex1 ex1_basic ex1_autopar ex1_openmp




