'''
Fecha: 21-04-2022
Autor: Luis Felipe Velasquez Puentes
Materia:Computacoón paralela y distribuida
Descripción: Programa de cython que realiza el calculo de fibonacci

'''

# Se toma la version 3 de cython por default
#cython: language_level=3

#Función que calcula la secuencia de fibonacci con un numero implemnetado con cython
def fib(int n):
    #Se utiliza cdef para inicializar las variables , con el fin de indicar que sea basado en C
    cdef int i
    cdef double a=0.0, b=1.0
    for i in range(n):
         a, b = a + b, a
    return a

#Ejecución del programa
if __name__ == '__main__':
    import sys
    arg, numiter = map(int, sys.argv[1:])
    for i in range(numiter):
        fib(arg)