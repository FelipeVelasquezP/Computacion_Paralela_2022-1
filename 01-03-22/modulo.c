/*****************************************
 * Fecha:01-03-22
 * Autor:Luis Felipe Velsquez
 * Materia: Computaciòn Paralela y Distribuida
 * Tema: Implementaciòn POsix (Library)
 * Modulo del principal para multiplicar 2 matrices sin variables globales
 * Se requiere que el diseño sea modular
 * El modulo implementarà los hilos que aran el 
 * calculo del producto de la matriz.
 * ***************************************/

#include "modulo.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

//Funciòn para cada thread calcula un solo elemento sobre la matriz  resultado
/*  Se pasa como argumento el puntero al vector de datos
    El vector de datos serà la porciòn enviada para el 
    calculo del elemento sobre la matriz resultado*/

void *multiplicacion(void *arg){
//la variable "datos" del tipo entero, apunta al vector argumentos
    int *datos =(int *)arg;
    int i,j,k;
    /** var que contenga el primer valor del v**/
     int x= datos[0];
     for(i=1;i<=x;i++){
        k+=datos[i]*datos[i+x];
     }

     int*p =(int *)malloc(sizeof(int));
     *p = k;

     //Se usa para terminar el hilo y retornar
     //el valor pasad como puntero
    pthread_exit(p);

}