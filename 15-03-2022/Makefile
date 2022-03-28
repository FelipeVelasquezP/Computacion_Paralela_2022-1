GCC = gcc-9
FLAGS = -pedantic -Wall
CFLAGS = -lm -pthread

PROGS: MM1c MM1f Posix


MM1c:
	$(GCC) $(FLAGS) modulo.c -c $(FLAGS)
	$(GCC) $(FLAGS) $@.c -c 
	$(GCC) $(FLAGS) modulo.o $@.o -o $@
	
MM1f:
	$(GCC) $(FLAGS) modulo.c -c $(FLAGS)
	$(GCC) $(FLAGS) $@.c -c 
	$(GCC) $(FLAGS) modulo.o $@.o -o $@

Posix:
	$(GCC) $(FLAGS) modulo.c -c $(CFLAGS)
	$(GCC) $(FLAGS) $@.c -c $(CFLAGS)
	$(GCC) $(FLAGS) modulo.o $@.o -o $@ $(CFLAGS)

clean:
	$(RM) $(PROGS) *.o
	$(RM) MM1c MM1f Posix
