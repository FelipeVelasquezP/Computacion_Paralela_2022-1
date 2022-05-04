import pandas as pd 
import numpy as np
import gravedad
import gravedadCy
import time

# Se inicializa el planeta para python 
tierra = gravedad.Planet()
tierra.x = 100e3
tierra.y = 300e3
tierra.z = 700e3
tierra.vx = 2e3
tierra.vy = 29.87e3
tierra.vz = 0.034e3
tierra.m = 5.9736e24

# Se inicializa el planeta para cython 
tierraCy = gravedadCy.Planet()
tierraCy.x = 100e3
tierraCy.y = 300e3
tierraCy.z = 700e3
tierraCy.vx = 2e3
tierraCy.vy = 29.87e3
tierraCy.vz = 0.034e3
tierraCy.m = 5.9736e24

#Metodo que realiza la simulación y retorna los tiempos de la misma
def get_performance(time_span ,n_steps):
    #Calculo de rendimeinto para Python
    initTime    = time.time()
    gravedad.step_time(planet = earth, time_span = time_span, n_steps = n_steps)
    totalTimePy = time.time() - initTime
    
    #Calculo de rendimeinto para Cython
    initTimeCy = time.time()
    gravedadCy.step_time(planet = earth_Cy, time_span = time_span, n_steps = n_steps)
    totalTimeCy = time.time() - initTimeCy

    return (totalTimePy, totalTimeCy)

#Variables iniciales
n = 0
times = []

#iteraciónes que aumentan los saltos
for _ in range (10):
    pyTime, cyTime = [], [] 
    n += 400000 # por cada uteracion, el numero de pasos se aumenta en 400000

    for _ in range(36): # Iteraciones para generar el promedio  de resultados
        performances = get_performance(600, n)
        pyTime.append(performances[0]) # rendimiento para Python
        cyTime.append(performances[1]) # rendimiento para Cython

    #Se calcula el promedio de los tiempos sobtendios
    times.append((n, sum(pyTime)/len(pyTime), sum(cyTime)/len(cyTime)))

#Se crea un dataframe que agraga a un CSV los datos obtenidos
pd.DataFrame(times).to_csv('samples.csv',  index_label = "Index", header  = ['n_steps', 'Python', 'Cython'])   