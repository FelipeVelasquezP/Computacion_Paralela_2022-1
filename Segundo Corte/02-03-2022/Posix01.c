/**************************************
* Fecha: 01 de marzo de 2022.
* Autor: Oscar Reyes
* Materia : Computación Paralela y Distribuida
* Tema: Implementación Posix (Library).
* Programa Principal para multiplicar 2 matrices sin 
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

//Se define el número de hilos segun configuración
#define MAX 4

//Se implementa el principal
int main(){
	int mA[MAX][MAX];
	int mB[MAX][MAX];
	//Se crean variables para los indices de las matrices
	int f1=MAX;
	int c1=MAX;
	int f2=MAX;
	int c2=MAX;
	
	//Se generan aleatorios para las matrices
		printf("Presentar la matriz A \n");
	for(int i=0;i<f1; i++){
		for(int j = 0; j<c1; j++){
			mA[i][j] = rand()%10;
			mB[i][j] = rand()%10;
		}
	}
	
	//Presentar la matriz A
	for(int i=0;i<f1; i++){
		for(int j=0;j<c1; j++){
			printf(" %d  ",mA[i][j]);
		}
		printf("\n");
	}
		printf("\n");
	
	//Presentar la matriz B
	printf("Presentar la matriz B \n");
	for(int i=0;i<f1; i++){
		for(int j=0;j<c1; j++){
			printf(" %d  ",mB[i][j]);
		}
		printf("\n");
	}
	
//Declarar un entero que tenga el producto Fila x Columna
	int maxFC = f1*c2;
//Se declara el número de threads de size maxFC
	pthread_t *hilos;
	hilos = (pthread_t *)malloc(maxFC*sizeof(pthread_t));
	int contador = 0;
	int* dato = NULL;
	
	for(int i = 0;i<f1; i++){
		for(int j=0;j<c2; j++){
//Almacenar filas y columnas en data(puntero)
			dato = (int *)malloc((20)*sizeof(int));
			//dato[0] = c1; /**---DEBUG **/
			dato[0] = c1;
			for(int k=0;k<c1; k++)
				dato[k+1]=mA[i][k];
			for(int k=0;k<f2; k++)
				dato[k+c1+1]=mB[k][j];
		//Se crean los threads 
		pthread_create(&hilos[contador++],NULL,multiplicacion,(void *)(dato));
		
		}
					
	}
	
	// PENDIENTE........
	//Presentar la matriz Resultado
	//int z = 0;
	printf("\n Presentar la matriz Resultado \n");
	for(int i=0; i<maxFC; i++){
		
		//joing de los hilos
		void *k;
		pthread_join(hilos[i], &k);
		//apuntamos p en k
		int *p = (int *)k;
		printf("%d	", *p);
		if((i+1)%c2 == 0){
		printf("\n");
		}
					
	}
	
	
	return 0;
}
