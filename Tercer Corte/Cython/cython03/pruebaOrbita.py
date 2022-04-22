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

#time_span, n_steps
time_span = 600
n_steps = 4000000

initTime=time.time()
gravedad.step_time(tierra,time_span,n_steps)
endTime=time.time()
totalTimePy= endTime-initTime
print("Tiempo en python:", totalTimePy, "seg")


initTime=time.time()
gravedadCy.step_time(tierraCy,time_span,n_steps)
endTime=time.time()
totalTimeCy= endTime-initTime
print("Tiempo en Cython:", totalTimeCy, "seg")

speedUp=totalTimePy/totalTimeCy

print("Speed up", speedUp)