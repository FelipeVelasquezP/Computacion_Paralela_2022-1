/*Fecha: 08/02/2022
* Autor: Luis Felipe Velasquez Puentes
* Subject: Parallel and Distributed Computing.
* Topic: Construction of the first Benchmark
* Description: Application that allows evaluating the performance
  of a specific aspect of the computer using matrix multiplication
  with the calssical algorithm (rows x columns)
*/

/*Interfaces*/

#include "modulo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>


/*CONSTANTS*/
struct timespec inicio, fin;

/* -------------------------------------Funciones ------------------------------------*/
/*	@brief: Get the init time*/
void sampleStart(){
	clock_gettime(CLOCK_MONOTONIC, &inicio);	
}

/*	@brief: Get the end time */
void sampleEnd(){
	clock_gettime(CLOCK_MONOTONIC, &fin);	
	double totalTime;
	totalTime = (fin.tv_sec - inicio.tv_sec)*1e9;
	totalTime = (totalTime + (fin.tv_nsec - inicio.tv_nsec))*1e-9;
	printf ("\n%f\n", totalTime);
}
/*	@brief: Function that generates a random number 
	@return: Random number between 0.001 and 9.999 with double precision
    ---
    getpid(): Gets an ID of a rand porcess of the system
*/
double randNumber(){
    float min = 0.001, max = 9.999;
    static int first = -1;
    if(first == (first < 0)){
       srand(time(NULL) + getpid());
    }
    if(min >= max){
        return errno = EDOM, NAN;
    }
    return min + (float)rand()/((float)RAND_MAX/(max-min));
}

/*	@brief: Gives values for each space of a matrix
	@param size: Size of the matrix
	@return MI: Matrix with values in its spaces	
*/
void InitMatrix(int SZ, double *Ma, double *Mb, double *Mr){
    int i,j;
    for(i=0; i < SZ; ++i){
        for(j=0;j<SZ;++j){
            Ma[j+i*SZ] = 3.9*(i-j);
            Mb[j+i*SZ] = 2.0*(j+i);
            Mr[j+i*SZ] = 0.0;
        }
    }
}
/*	@brief: Gives values for each space of a matrix
	@param size: Size of the matrix
	@return MI: Matrix with values in its spaces	
*/
void initMatrix(int SZ, double *Ma, double *Mb, double *Mr){
	int i, j;
	for(i=0; i<SZ; ++i){
		for(j=0;j<SZ;++j){
			Ma[j+i*SZ] = 3.0*(i-j);
			Mb[j+i*SZ] = 2.8*(j+i);
			Mr[j+i*SZ] = 0.0;
		}
	}
		
}

/*	@brief: Print a matrix
	@param SZ: Size of the matrix
	@return *M: Matrix to print	
*/
void printMatrix(int SZ, double *M){
	int i,j;
	for (i=0;i<SZ; ++i){
		for (j=0;j<SZ; ++j){
			printf("  %f  ",M[j+i*SZ]);
		}
		printf("\n");
	}
		printf("----------------------------");
		printf("\n");
		
		
}

/*	@brief: Multiply matrices
	@param size: Size of matrix
	@param a: Matriz A to multiply
	@param b: Matriz B to multiply
	@param c: Total matrix of multiplication
    ---
*/
void matrixMultiplyMM1c(int size, double *Ma, double *Mb, double *Mr){
	int i, j;
	for(i=0; i<size; ++i){
		for(j=0; j<size; ++j){
		/*Necesita puteros auxiliares*/
		double *pA, *pB;
		double sumaAuxiliar = 0.0;
		pA = Ma + (i*size);
		pB = Mb + j;
			for(int k = 0; k < size; ++k, pA ++, pB+=size){
				sumaAuxiliar += (*pA * *pB);
			}
			Mr[i*size+j] = sumaAuxiliar;
		}
	}
}

void matrixMultiplyMM1f(int size, double *Ma, double *Mb, double *Mr){
  int i, j;
	for(i=0; i<size; ++i){
		for(j=0; j<size; ++j){
		/*Necesita puteros auxiliares*/
		double *pA, *pB;
		double sumaAuxiliar = 0.0;
		pA = Ma + (i*size);
		pB = Mb + (j*size);
			for(int k = 0; k < size; ++k, pA++, pB++){
				sumaAuxiliar += (*pA * *pB);
			}
			Mr[i*size+j] = sumaAuxiliar;
		}
	}
}







/*** FUNCIONES PARA EL PROGRAMA DE PTHREADS ***/
/* 2. --> Función Reserva de Memoria para las matrices de doble puntero */
double ** ReservaMEM(int size){
	//Reservamos memoria de dimensión NxN double contigua
	double * valor = (double *) malloc(size*size*sizeof(double));
	
	//Reserva de un vector de 'punteros double' con dimensión size
	double ** ptr = (double **) malloc(size*size*sizeof(double *));
	
	//Iteración para que cada puntero posicione en la reserva Mem
	for(int i = 0; i < size; ++i)
		ptr[i] = &valor[i*size];
		
	
	return ptr;
}

/* 3. -->Función de Inicialización de las matrices.*/
void IniciarMatriz(double **matA, 
                   double **matB, 
                   double **matC, int size){
	int i, j;
	
	for(i = 0; i < size; ++i){
		for(j = 0; j < size; ++j){
			matA[i][j] = 3.9*(i-j);
			matB[i][j] = 2.0*(i+j);
			matC[i][j] = 0.0;
		}
	}
	
	

	
}

/* 6. Se necesita función para impresión de matrices (doble puntero). */
void printMatriz(double **matriz, int size){
	int i,j;
	
	for(i = 0; i < size; ++i){
		for(j = 0; j < size; ++j){
			printf(" % lf", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n-----------------\n");



}






