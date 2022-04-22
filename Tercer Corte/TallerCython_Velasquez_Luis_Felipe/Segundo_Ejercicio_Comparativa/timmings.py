'''Fecha: 21-04-2022
Autor: Luis Felipe Velasquez Puentes
Materia:Computación paralela y distribuida
Descripción: Programa en python que crea un archivo csv 
            donde almacena registros obtenidos de los 
            programas de Python,Cython y C 
'''

#importación de librerias nesesarias
from timeit import repeat
from subprocess import check_output

#Función que obtiene el tiempo durante la ejecución
def timer(arg, niter, name, module):
    stmt = "%s(%s)" % (name, arg)
    setup = "from %s import %s" % (module, name)
    time = min(repeat(stmt=stmt, setup=setup,
    number=niter)) / float(niter) * 1e9
    return time
for i in range(3):
    #Definición de variables nesesarias para ejetuar las pruebas con Cython
    N = 10**6
    pytime_0 = timer(0, N, name='fib', module='fib')
    cytime_0 = timer(0, N, name='fib', module='cyfib')
    ctime_0 = float(check_output(('./main 0 %d' %
    N).split()))
    py0speedup = 1.0
    cy0speedup = pytime_0 / cytime_0
    c0speedup = pytime_0 / ctime_0

    #Definición de variables nesesarias para ejetuar las pruebas con Python
    N = 10**5
    pytime_90 = timer(90, N, name='fib', module='fib')
    cytime_90 = timer(90, N, name='fib',
    module='cyfib')
    ctime_90 = float(check_output(('./main 90 %d' %
    N).split()))
    py90speedup = 1.0
    cy90speedup = pytime_90 / cytime_90

    c90speedup = pytime_90 / ctime_90
    data_format = "{:s},{:.0f},{:.1f},{:.0f},{:.1f}\n"

    #Creación del CSV, asignando los valores correspondientes
    with open(f"fib{i}.csv", 'w') as fh:
        fh.write("Version,fib(0) runtime[ns],speedup,fib(90) runtime [ns],speedup\n")
        fh.write(data_format.format("Python", pytime_0,
        py0speedup, pytime_90, py90speedup))
        fh.write(data_format.format("Cython", cytime_0,
        cy0speedup, cytime_90, cy90speedup))
        fh.write(data_format.format("Pure C", ctime_0,
        c0speedup, ctime_90, c90speedup))