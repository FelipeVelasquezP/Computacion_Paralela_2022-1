/*****************************************
 * Fecha:01-03-22
 * Autor:Luis Felipe Velsquez
 * Materia: Computaciòn Paralela y Distribuida
 * Tema: Implementaciòn POsix (Library)
 * Prgrama para multipliacr 2 matrices sin variables globales
 * Se requiere que el diseño sea modular
 * El modulo implementarà los hilos que aran el 
 * calculo del producto de la matriz.
 * ***************************************/


#include "modulo.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

//Se define el nùmero de hilos segun configuraciòn
#define MAX 4

//se implementa el prncipal
int main(){
    int mA[MAX][MAX];
    int mB[MAX][MAX];
    //Se crean variables para los indices de las matrices
    int f1=MAX;
    int c1=MAX;
    int f2=MAX;
    int c2=MAX;

    //Se generan aleatorios para las matrices
    for(int i=0;i<f1;i++){
        for(int j=0;j<c1;j++){
            mA[i][j]=rand()%10;
            mB[i][j]=rand()%10;
        }   
    }
    //presentar la matriz A
    printf("\nMatriz A:\n"  );
    for(int i=0;i<f1;i++){
        for(int j=0;j<c1;j++){
            printf(" %d ", mA[i][j]);
                }   
        printf("\n");
    }

    //presentar la matriz B
    printf("\nMatriz B:\n"  );
    for(int i=0;i<f1;i++){
        for(int j=0;j<c1;j++){
            printf(" %d ", mB[i][j]);
                }   
        printf("\n");
    }

    //Declarar un entero que tenga el producto fxc
    int maxFc=f1*c1;
    //Se delcara el numero de threads de size maxFC
    pthread_t*hilos;
    hilos=(pthread_t *)malloc(maxFc*sizeof(pthread_t));
    int contador = 0;
    int* dato=NULL;
    for(int i=0;i<f1;i++){
        for(int j=0;j<c2;j++){
            //Almacenar filas y columnas en data(puntero)
            dato=(int *)malloc((24)*sizeof(int));
        
            for(int k=0;k<c1;k++){
                dato[k+1]=mA[j][k];
            }   
            for(int k=0;k<f2;k++){
                dato[k+c1+1]=mA[k][j];
            } 
        }
        pthread_create(&hilos[contador++],NULL,multiplicacion,(void *)(dato)); 
    }
      printf("\n");
    
    int count=0;
    for(int i=0;i<maxFc;i++){
        count+=1;
        //Joining de los hilos
        void *k;
        pthread_join(hilos[i],k);
        //apuntamos p en k
        int *p=(int *)k;
        printf(" %d ",*p);
        if (count==MAX){
            printf("\n");
            count=0;
        }
    }
    return 0;
}
