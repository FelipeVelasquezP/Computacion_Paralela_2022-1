/*Fecha: 08/02/2022
* Autor: Luis F. Velasquez P.
* Subject: Parallel and Distributed Computing.
* Topic: Construction of the first Benchmark
* Description: Application that allows evaluating the performance
  of a specific aspect of the computer using matrix multiplication
  with the calssical algorithm (rows x columns)
*/

#ifndef MODULO_C_H_INCLUDE
#define MODULO_C_H_INCLUDE


void sampleStart();
void sampleEnd();
double randNumber();
void initMatrix(int SZ, double *Ma, double *Mb, double *Mr);
void printMatrix(int SZ, double *M);
void matrixMultiplyMM1c(int size, double *Ma, double *Mb, double *Mr);
void matrixMultiplyMM1f(int size, double *Ma, double *Mb, double *Mr);
double **reservaMEM(int size);
void IniciarMatriz(double **matA,double **matB,double **matB,int size);
printMatriz(double **matriz,int size);


#endif
