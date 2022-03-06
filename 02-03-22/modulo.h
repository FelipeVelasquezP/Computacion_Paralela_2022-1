/**************************************
* Fecha: 01 de marzo de 2022.
* Autor: Oscar Reyes
* Materia : Computación Paralela y Distribuida
* Tema: Implementación Posix (Library).
* Interfaz del modulo del principal para multiplicar 2 matrices sin 
* variables globales.
* Se requiere que el diseño sea modular.
* El modulo implementará los hilos que harán el
* cálculo del producto de matrix.
**************************************/

#ifndef MODULO_H_INCLUDED
#define MODULO_H_INCLUDED

// Prototipos de las funciones a presentar como interfaz del modulo.c

void *multiplicacion(void *arg);

#endif
