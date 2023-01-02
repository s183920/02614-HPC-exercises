F90C	= gfortran
F90FLAGS= -g -Wall -O3
OBJECTS	= f90main.o
LDFLAGS = $(F90FLAGS)

f90project: $(OBJECTS)
	$(F90C) $(LDFLAGS) -o $@ $(OBJECTS) $(LDLIBS)

clean:
	@/bin/rm -f *.o core

realclean: clean
	/bin/rm -f f90project

# add your changes below
#
