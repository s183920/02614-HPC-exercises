TARGET= matvec
OBJS  = main.o \
        matvec.o \
        alloc2d.o \

CC	= nvc
CXX	= nvc++

OPT	= -g -fast -Msafeptr -Minfo -acc -mp=gpu -gpu=pinned -gpu=cc80 -gpu=lineinfo -cuda -mp=noautopar
ISA	= 
PARA	= 
INC   = -I$(CUDA_ROOT)/include -I/appl/nvhpc/2022_2211/Linux_x86_64/22.11/examples/OpenMP/SDK/include
LIBS	= -lcuda -L$(CUDA_ROOT)/lib64 -lcudart -lcublas

CFLAGS = $(OPT) $(INC) $(ISA) $(PARA) $(XOPT)
CXXFLAGS = $(OPT) $(INC) $(ISA) $(PARA) $(XOPT)

all: module_load $(TARGET)

module_load:
	sh ../load_modules.sh

$(TARGET): $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LIBS)
clean:
	@/bin/rm -f *.o $(TARGET)

main.o: main.cpp matvec.h alloc2d.h
alloc2d.o: alloc2d.h alloc2d.cpp 
matvec.o: matvec.h matvec.cpp