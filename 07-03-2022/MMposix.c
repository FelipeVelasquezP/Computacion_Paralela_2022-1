/*Fecha: 08/02/2022
* Autor: Luis F. Velasquez P.
* Subject: Parallel and Distributed Computing.
* Topic: Implementación Posix (Library)
* Description: Prorama principal para multiplicar 2 matrices con variebles globales
* Se requiere que el diseño sesa modular.
* El modulo implementará las funciones para el 
* calculo del producto de la matriz
* 1.- Creación de variables donde el puntero para matrices principal GLobal
* 2.- Función reserva de memoria para las matrices de doble puntero
* 3.- Función de Inicilización de las matrices
* 4.- Función para el producto de matrices
*   Se dividio la matriz Ampor porciones , a ser enviadas a cada hilo.
*   El número de hilos sera cagado al ejecutar
*   La dimensión de la matriz sera enviada al ajecutar
* 5. La dimensión de la matriz siempre sea cuadrada (NXN)
* 6. Se nesesita función para impresion de matrices (doble puntero).
*/

#include "modulo.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread>
#include <sys/time>

/*Se declaran las variables GLOBALES para todo el programa*/
int N,Nthreads;
double **Ma, **Mb, **Mc;

int main(int argc, char* argv[]){
    /*Se capturan los valores*/
    N=atof(argv[1]);
    Nthreads=atof(argv[2]);

    /*Creación y reserva de Mem para cada matriz*/
    Ma=reservaMEM(N);
    Mb=reservaMEM(N);
    Mc=reservaMEM(N);
    IniciarMatriz(Ma,Mb,Mc,N);
    printMatriz(Ma,N)
    printMatriz(Mb,N)
    printMatriz(Mc,N)


    return 0;
}

