CC	= gcc
OPT	= -g -O3
WARN   = -Wall
CFLAGS	= $(OPT) $(WARN)

# targets
.PHONY: all
all: ex1 ex2 ex3 ex5

ex1: ex1.o matrix.o
	$(CC) $(CFLAGS) -o $@ $^

test_ex1:
	@echo "Python results:"
	@python ex1.py
	@echo "C results:"
	@./ex1
	

ex2: ex2.o matrix.o
	$(CC) $(CFLAGS) -o $@ $^

test_ex2:
	@echo "Python results:"
	@python ex2.py
	@echo "C results:"
	@./ex2

ex3: ex3.o matrix.o
	$(CC) $(CFLAGS) -o $@ $^

test_ex3:
	@echo "C results:"
	@./ex3

ex5: ex5.o matrix.o
	$(CC) $(CFLAGS) -L /usr/lib64/atlas -lsatlas -o $@ $^

test_ex5:
	@echo "C results using cblas_dgemm():"
	@./ex5

# clean up
clean: 
	@rm -f *.o core

realclean: clean
	@rm -f ex1 ex2 ex3 ex5

# dependencies
matrix.o: matrix.c matrix.h
ex1.o: ex1.c matrix.h
ex2.o: ex2.c matrix.h
ex3.o: ex3.c matrix.h
ex5.o: ex5.c matrix.h