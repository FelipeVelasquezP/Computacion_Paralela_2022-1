/************************************************************
* Fecha: 15 de marzo de 2022.
* Autor: Luis Felipe Velasquez Puentes
* Materia : Computación Paralela y Distribuida
* Tema: Implementación Posix (Library).
* Programa Principal para multiplicar 2 matrices sin 
* variables GLOBALES.
* Se requiere que el diseño sea modular.
* El modulo implementará las funeciones para 
* cálculo del producto de la matrix:
* 1. Creación de variables doble puntero para matrices principal GLOBAL
* 2. Función Reserva de Memoria para las matrices de doble puntero
* 3. Función de Inicialización de las matrices.
* 4. Función para el producto de matrices:
	Sea dividide la matriz A por porciones, a ser enviadas a cada hilo
	--> El número de hilos será enviada al ejecutar
	--> La dimensión de la matriz será enviada al ejecutar
* 5. La dimensión de la matriz siempre será cuadrada (NxN)
* 6. Se necesita función para impresión de matrices (doble puntero).	
************************************************************/

#include "modulo.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>


int main(int argc, char* argv[]){

    struct arg_struct { 
     int N;
     int Nthreads;
     double **Ma;
     double **Mb;
     double **Mc;
     int *idThread;
    };

	struct arg_struct args;

	if (argc != 3){
		printf("./Exe N<dimMatriz> Nth<numHilos>");
		return -1;
	}


	//Se capturan las variables size y número de hilos*/
	args.N	 = atof(argv[1]);
	args.Nthreads = atof(argv[1]);
	
	/*Se crea el pool de hilos*/
	pthread_t *hilosExec;
	/*Se reserva memoria para los hilos*/
	hilosExec = (pthread_t *)malloc(args.Nthreads*sizeof(pthread_t));

	//Creación y reserva de Mem para cada Matriz
	args.Ma = ReservaMEM(args.N);
	args.Mb = ReservaMEM(args.N);
	args.Mc = ReservaMEM(args.N);	
	/*Se inicializan las matrices*/
	IniciarMatriz(args.Ma,args.Mb,args.Mc,args.N);
	
	if (args.N<4){
		printf("Matriz A: \n");
		printMatriz(args.Ma,args.N);
		printf("Matriz B: \n");
		printMatriz(args.Mb,args.N);
	}
	sampleStart();
	/*Se reparte la tarea a cada hilo, al usar la funcion pthread_create*/
	for(int i=0; i<args.Nthreads; ++i){
		//args.idThread = (int *)malloc(sizeof(int));
		(args.idThread) = i;
		pthread_create(&hilosExec[i],NULL, multMM,(void *)&args);
	}
	/*Espero a que todos los hilos terminen*/
	for(int i=0; i<args.Nthreads; ++i){
		pthread_join(hilosExec[i],NULL);
	}
	sampleEnd();

	free(hilosExec);


	if (args.N<4){	 	
		printf("Matriz C: \n");
		printMatriz(args.Mc,args.N);
	}
	return 0;

}



















