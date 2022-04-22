GCC = gcc-9
FLAGS = -pedantic -Wall
CFLAGS = -lm -pthread

PROGS: main
main:
	$(GCC) $(FLAGS) cfib.c -c $(CFLAGS)
	$(GCC) $(FLAGS) $@.c -c $(CFLAGS)
	$(GCC) $(FLAGS) cfib.o $@.o -o $@ $(CFLAGS)
	
clean:
	$(RM) $(PROGS) *.o
	$(RM) main