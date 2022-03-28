/**************************************
* Fecha: 01 de marzo de 2022.
* Autor: Oscar Reyes
* Materia : Computación Paralela y Distribuida
* Tema: Implementación Posix (Library).
* Modulo del principal para multiplicar 2 matrices sin 
* variables globales.
* Se requiere que el diseño sea modular.
* El modulo implementará los hilos que harán el
* cálculo del producto de matrix.
**************************************/

#include "modulo.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

//Funcion para cada thread calcula un elemento un solo 
//sobre el resultado de la matrix

/* Se pasa como argumento el puntero al vector de datos
 * El vector de datos será la porción envida para el cálculo
 * del elemento sobre la matriz resultado */ 
void *multiplicacion(void *arg){
//La variable "datos" de tipo entero, apunta al vector argumentos  
	int *datos = (int *)arg; 
	int i=0, k=0;
	//-> var que contenga el primer valor del v
	int x = datos[0];
	for (i=1; i<=x; i++)
		k += datos[i]*datos[i+x];
	int *p = (int *)malloc(sizeof(int));
	*p = k;
	
//Se usa para terminar el hilo y retornar el valor pasado como puntero
	pthread_exit(p);
			
}

