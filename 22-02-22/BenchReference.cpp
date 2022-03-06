/************************************
 * Fecha: 22022022
 * Autor: Luis Felipe Velasquez Puentes
 * Tema: Benchmark en serie. Implementacion en C++
 * $>./ejecutable <MatrixSize>
 * *********************************/

#include <iostream>
#include <random>
#include <chrono>
#include <ctime>

/**** Lugar de Funciones ****/
//funciòn creacion de matriz (doble puntero)
double** crearMatrix(int sizeN){
    int i;
    double  **matriz = new double* [sizeN];
    for(i=0;i<sizeN;i++){ 
        matriz[i] =new double [sizeN]();
    } 
    return matriz;
}

//Funciòn Inicializar matrices
void InicializarMatrices(int sizeN,double** &matriz1,
                        double** &matriz2,double** &matriz3){
    int i,j;
    for(i=0;i<sizeN;i++){ 
        for(j=0;j<sizeN;j++){ 
            matriz1[i][j]=2.1*(i-j);
            matriz2[i][j]=1.2*(i-j);
            matriz3[i][j]=0;
        }        
    }

}

//Funcion para imprimir las matrices
void printMatriz(double** &matriz,int sizeN){
    int i,j;
    for(i=0;i<sizeN;i++){ 
        for(j=0;j<sizeN;j++){ 
            printf(" %f ",matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
}

//Retornamos la memoia al sistema (Destruri las matrices)
void DestruirMatriz(int sizeN,double** &matriz){
    if(matriz){
        int i;
        for(i=0;i<sizeN;i++){ 
            delete[] matriz[i];
         }
        delete[] matriz; // se borra todas las filas
        matriz=nullptr; // se entrega MEM al system
    }
}

//Funciòn Multiplicaciòn de Matrices
//Algoritmo Clasico
double** ProductosMatrices(int sizeN,double** &matriz1,double** &matriz2){
    int i,j,k;
    double **matriz=crearMatrix(sizeN);
     for(i=0;i<sizeN;i++){ 
        for(j=0;j<sizeN;j++){ 
           for(k=0;k<sizeN;k++){ 
               matriz[i][j]+=matriz1[i][k]*matriz2[k][j];
            }  
        }        
    }
    return matriz;
}



/**** Funcion Principal ****/
int main(int argc,char *argv[]){
    /*Secciòn de Declaraciòn*/
    int i,j,k;
    int N = atoi(argv[1]); //Dimension (Size) de las matrices
    double** matA = new double* [N];
    double** matB = new double* [N];
    double** matC = new double* [N];

    InicializarMatrices(N,matA,matB,matC);

    printMatriz(matA,N);
    printMatriz(matB,N);
    matC=ProductosMatrices(N,matA,matB);
    printMatriz(matC,N);
    
    DestruirMatriz(N,matA);
    DestruirMatriz(N,matB);
    DestruirMatriz(N,matC);

    return 0;
}