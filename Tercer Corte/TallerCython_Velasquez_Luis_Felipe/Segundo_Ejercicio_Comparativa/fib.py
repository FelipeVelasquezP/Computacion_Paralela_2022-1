'''Fecha: 21-04-2022
Autor: Luis Felipe Velasquez Puentes
Materia:Computación paralela y distribuida
Descripción: Programa que realiza el calculo de la secuencia de fibonacci co Python nativo
'''

#Función que calcula la secuencia de fibonacci con un numero implemnetado con python
#Para este caso, las variables no estan definidas por un tipo de dato
def fib(n):
    a, b = 0.0, 1.0
    for i in range(n):
         a, b = a + b, a
    return a

#Ejecución del programa
if __name__ == '__main__':
    import sys
    arg, numiter = map(int, sys.argv[1:])
    for i in range(numiter):
        fib(arg)