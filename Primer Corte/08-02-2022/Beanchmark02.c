/*Universidad Sergio Arboleda 
 *Fecha: 8/2/22
 * Autor: Luis Felipe Velasquez Puentes
 * Materia: Computaci�n Paralela y Distribuida
 * Tema: Implementaci�n de  Benchmark en c
 * Benchmark: Aplicai�n de juguete que permite evaluar rendimiento 
   de un aspecto espec�fico de la computadora
*/

#include <stdio.h>
#include <stdlib.h>

/*Se crea una variable con un valor alto
  para reservar memoria*/
#define DATA_SZ (1024*1024*64*3)
  
  /*Se reserva el espacio de memoria segun el valor*/
static double  MEM_CHUNK[DATA_SZ];

/*Se crea la funcion para inicializar las matrices*/
void InitMatrix(int SZ,double *Ma,double *Mb,double *Mr){
	int i,j,k;
	for(i=0;i<SZ;++i){
		for (j=0;j<SZ;++j){
			Ma[j+i*SZ]=3.0*(i-j);
			Mb[j+i*SZ]=2.8*(j+i);
			Mr[j+i*SZ]=0.0;
		}
	}
}
void printMatrix(int SZ,double *M){
	int i,j,k;
	for(i=0;i<SZ;++i){
		for (j=0;j<SZ;++j){
			printf("  %f  ",M[j+i*SZ]);
		}
		printf("\n");
	}
}

/*Se implementa la impres�n (para evectos de validaci�n)*/


/* Se implmenta paso a paso benchmark Multiplicaci�n de Matrices
   Algoritmo cl�sico (filas x columnas) de matrices de igual dimensi�n */

int main(int argc, char *argv[]) {
	/*Se captura en la dimesi�n de la matriz*/
	int N = (int) atof(argv[1]);
//	printf("valor ingresado %d",N);
	
	/*Apuntamos los vectores (creaci�n) al espacio
	  de memoria reservado, con dimensi�n NxN*/
	
	double *Ma, *Mb, *Mr;
	Ma=MEM_CHUNK;
	Mb=Ma+N*N;
	Mr=Mb+N*N;
	
	InitMatrix(N,Ma,Mb,Mr);
	printf("\n Matriz A \n");
	printMatrix(N,Ma);
	InitMatrix(N,Ma,Mb,Mr);
	printf("\n Matriz B \n");
	printMatrix(N,Mb);
	
	int i,j,k;
	for (i=0;i<N;++i){
		for(j=0;j<N;++j){
			/*Nesesita punteros auxiliares*/
			double *pA, *pB;
			double sumaAuxiliar = 0.0;
			pA = Ma + (i*N);
			pB = Mb + j;
			for(k=0;k<N;++k,pA++,pB+=N){
				sumaAuxiliar += (*pA * *pB);
			}
			Mr[i*N+j] = sumaAuxiliar;
			
			
		}
	}
	
	printf("\n Matriz R \n");
	printMatrix(N,Mr);
	return 0;
}
