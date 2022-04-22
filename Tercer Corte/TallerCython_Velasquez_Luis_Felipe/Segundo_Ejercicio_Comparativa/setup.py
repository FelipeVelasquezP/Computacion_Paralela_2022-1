'''
Fecha: 21-04-2022
Autor: Luis Felipe Velasquez Puentes
Materia:Computación paralela y distribuida
Descripción: Programa que genera los ejecutables de programas realizados en python y cython

'''
#importación de librerias
from distutils.core import setup
from Cython.Build import cythonize
#Creación del ejecutable de acuerdo al programa que se desee
setup(ext_modules =cythonize('cyfib.pyx'))