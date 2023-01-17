TARGET= mandelbrot
OBJS	= main.o \
        writepng.o \
        mandel_omp.o \

OPT	= -g -fast -Msafeptr -Minfo -acc -mp=gpu -gpu=pinned -gpu=cc80 -gpu=lineinfo -cuda -mp=noautopar
ISA	= 
PARA	= 

PNGWRITERPATH = pngwriter
ARCH	      = $(shell uname -p)
PNGWRTLPATH   = $(PNGWRITERPATH)/lib/$(ARCH)
PNGWRTIPATH   = $(PNGWRITERPATH)/include
PNGWRITERLIB  = $(PNGWRTLPATH)/libpngwriter.a

CC	= nvc

CXX	= nvc++
CFLAGS= -I $(PNGWRTIPATH) $(OPT) $(ISA) $(PARA) $(XOPT)
CXXFLAGS= -I $(PNGWRTIPATH) $(OPT) $(ISA) $(PARA) $(XOPT)

F90C  	= gfortran
LIBS	= -L $(PNGWRTLPATH) -lpngwriter -lpng 

all: $(PNGWRITERLIB) $(TARGET)

$(TARGET): $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LIBS)

$(PNGWRITERLIB):
	@cd pngwriter/src && $(MAKE) -f $(MAKEFILE_LIST)

clean:
	@/bin/rm -f *.o $(TARGET)

realclean: clean
	@cd pngwriter/src && $(MAKE) -f $(MAKEFILE_LIST) clean
	@rm -f $(PNGWRITERLIB)
	@rm -f $(TARGET)
	@rm -f mandelbrot.png


test_cpu: realclean all
	./mandelbrot 0

test_loop: realclean all
	./mandelbrot 1

test_parallel: realclean all
	@echo "Without warmup"
	./mandelbrot 2 0
	@echo "With warmup"
	./mandelbrot 2 1

test: realclean all
	# @echo "CPU"
	# ./mandelbrot 0
	@echo "Loop"
	./mandelbrot 1
	@echo "Parallel"
	./mandelbrot 2

# dependencies
#
main.o  : main.cpp mandel_omp.h
mandel_omp.o: mandel_omp.cpp
writepng.o: writepng.h writepng.cc
