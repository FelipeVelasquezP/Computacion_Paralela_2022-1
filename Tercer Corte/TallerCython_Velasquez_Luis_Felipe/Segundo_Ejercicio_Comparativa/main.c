/*
Fecha: 21-04-2022
Autor: Luis Felipe Velasquez Puentes
Materia:Computación paralela y distribuida
Descripción: Programap principal para realizar el calculo de la secuencia de fibonacci
*/

//Importación de librerias nesesarias
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "cfib.h"

//Ejejcución del programa, donde se invocan a las funciones declaras en la interfaz
int main(int argc, char **argv) {
    int arg=-1, numiter=-1, i;
    clock_t t;
    //Validación de que se ingresen los argumentos nesesarios
    if (argc != 3) {
        printf("Wrong number of arguments,expecting 2 (got %d)\n.", argc-1);
        return 1;
    }
    arg = atoi(argv[1]);
    numiter = atoi(argv[2]);
    //Calculo de l secueencia de fibonacci
    t = clock();
    for (i=0; i<numiter; ++i) {
        cfib(arg);
    }
    t = clock() - t;
    //impresión del tiempo que tardo en realizar el calculo
    printf("%f\n", ((float)t) / 1000000/
    numiter * 1e9);
    return 0;
}