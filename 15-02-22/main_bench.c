/* 
	Fecha: 08 de febrero de 2022
	Autor: ALuis Felipe Velasquez Puentes
	Materia: Computaci�n Paralela y Distribuida
	Tema: Aplicaci�n que permite evaluar el rendimiento
  	de un aspecto en espec�fico del ordenador
 	Descripci�n: Se requiere implementar una aplicaci�n que multiplique dos matrices.
  	el algoritmo a usar ser� e cl�sico (filas por columnas).
  	Las matrices deben ser de doble presici�n.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <sys/time.h>
#include <errno.h>

// Se crea una variable con un valor alto para reservar memoria
#define DATA_SZ (1024*1024*64*3)

// Se reserva el espacio de memoria segun el valor
static double MEM_CHUNK[DATA_SZ];

/*Definici�n de constantes*/
struct timespec inicio,fin;

/*****************	Funciones	******************+*/



/*Inicio medida de tiempo*/
void SampleStart(){
	clock_gettime(CLOCK_MONOTONIC,&inicio);
}

/*Fin medida de tiempo*/
void SampleEnd(){
	clock_gettime(CLOCK_MONOTONIC,&fin);
	/*Se imprime el tiempo*/
	double  tiempoTotal;
	tiempoTotal=(fin.tv_sec - inicio.tv_sec)*1e9;
	tiempoTotal=(tiempoTotal+(fin.tv_nsec - inicio.tv_nsec))*1e9;
	printf(" %f \n",tiempoTotal );
}


/* Se crea un doble presiciòn Aleatorio */
float randMM(){
	float min=0.001,max=9.999;
	static int first=-1;
	if((first=(first<0))){
		srand(time(NULL)+getpid());
	}
	if (min>=max){
		return errno=EDOM,NAN;
	}
	return min + (float) rand()/((float)RAND_MAX/(max-min));
}



//Se crea la funcion para incializar las matrices
void InitMatrix(int SZ, double *Ma, double *Mb, double *Mr){
	int i,j,k;
	for(i=0;i<SZ;++i){
		for(j=0;j<SZ;++j){
			Ma[j+i*SZ] = randMM();
			Mb[j+i*SZ] = randMM();
			Mr[j+i*SZ] = 0.0;
		}
	}
		
}

// Se impleenta la impresi�n (Para efectos de validaci�n)
void printMatrix(int SZ, double *M){
	int i,j;
	for (i=0;i<SZ; ++i){
		for (j=0;j<SZ; ++j){
			printf("  %f  ",M[j+i*SZ]);
		}
		printf("\n");
	}
		
}



void MatrixMM(int size,double *a,double *b,double *c){
int i,j,k;
	for(i=0;i<size;++i){
		for(j=0;j<size;++j){
		// Necesita puteros Auxiliares
		double *pA, *pB;
		double sumaAuxiliar = 0.0;
		pA = a + i;
		pB = b + (j*size);
			for(k=0;k<size;++k, pA+=size, pB+=size){
				sumaAuxiliar += (*pA * *pB);
			}
			c[i*size+j] = sumaAuxiliar;
		}
	}
	
}
/*	Se imlementa paso a paso benchmark Multiaplicacion de matrices
	Algoritmo cl�sico (filas x columnas) de matrices
	de igual diemnsi�n
*/
int main(int argc, char *argv[]) {
	
	/*Se captura la dimensi�n de la matriz*/
	int N = (int) atof(argv[1]);
	
	// Apuntamos los vectores (creaci�n) a espacio de memoria reservada con dimensi�n NxN
	double *Ma, *Mb, *Mr;
	Ma = MEM_CHUNK;
	Mb = Ma + N*N;
	Mr = Mb + N*N;
	
	InitMatrix(N, Ma, Mb, Mr);
	SampleStart();
	MatrixMM(N,Ma,Mb,Mr);
	SampleEnd();
	return 0;
}
