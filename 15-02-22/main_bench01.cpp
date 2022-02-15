 
/*Fecha: 3/02/2022
* Autor: Luis Felipe Velasquez
* Materia: Computaci�n Paralela y Distribuida.
* Tema: Construcci�n del primer Benchmark 
* Descripci�n: Aplicaci�n que permite evaluar el rendimiento
  de un aspecto en espec�fico del ordenador
* Ejercicio: Se requiere implementar una aplicaci�n que multiplique dos matrices.
  el algoritmo a usar ser� e cl�sico (filas por columnas).
  Las matrices deben ser de doble presici�n.
*/

/* Declaraci�n de interfaces*/
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <unistd.h>
#include <cstring>
#include <math.h>

/*Declaraci�n del espacio de dominio*/
using namespace std;

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


void printMatrix (vector<vector<double>> M, string name){
	
	cout << name << endl;
	for (int i=0; i<M.size(); ++i){
		for (int j=0; j<M.size(); ++j){
			cout << M[i][j] << "    ";
		}
		cout << "\n";
	}	
	cout << "\n";
}

/*	@brief: Function that generates a random number 
	@param min: Lower limit
	@return
*/
double randNumber(double min, double max){
	double f = (double)rand() / RAND_MAX;
	return min + f* (max - min);
}

/** Inializaci�n de las matrices con n�mero aleatoreos*/
vector<vector<double>> matrixInit(int size){
	int i,j;
	vector<vector<double>> MI(size, vector<double> (size,0)); 
    	
	for (int i=0; i<size; ++i){
		for (int j=0; j<size; ++j){
			MI[i][j] = randMM();
		}
	}
	return MI;	
}

/** Multiplicaci�n de matrices*/
void matrixMultiply (vector<vector<double>> MA, vector<vector<double>>MB){
	vector<vector<double>> MT (MA.size(), vector<double> (MA.size(),0));;
	int j,k,i;
	/*auto se utiliza cuando no se sabe que tipo de dato ser� la variable.*/
	for( i = 0; i<MA.size(); ++i){
		for( j = 0; j<MA.size(); ++j){
			for( k = 0; k<MA.size(); ++k){
				MT[i][j] += MA[i][k]*MB[k][j];
			}
		}
	}
}

int main (int argc, char** argv) {
	int k;
	int N = atoi(argv[1]);
	
	/* Se utiliza la calse vector para crear las matrices */
	/*** Matriz de tama�o NxN compuesta por vectores de tama�o N con el dato 0 en todas sus posiciones*/
	vector<vector<double>> M1(N, vector<double> (N,0)); 
	vector<vector<double>> M2(N, vector<double> (N,0));
	vector<vector<double>> MR(N, vector<double> (N,0));
	
	/*Inializaci�n de las matrices con n�mero aleatoreos*/
	M1 = matrixInit(N);
	M2 = matrixInit(N);	
	
	/*Multiplicaci�n de matrices M1 y M2
	Se debe validar que el algoritmo de multiplicaci�n funcione*/
	SampleStart();
	matrixMultiply(M1, M2);
	SampleEnd();

	/*Se imprime M1*/
//	printMatrix(M1, "Matrix 1");
//		
//	/*Se imprime M2*/
//	printMatrix(M2, "Matrix 2");
//	
//	/*Se imprime MR*/
//	printMatrix(MR, "Matrix R");

	return 0;
}

