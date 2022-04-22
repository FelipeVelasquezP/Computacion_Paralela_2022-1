/*
Fecha: 21-04-2022
Autor: Luis Felipe Velasquez Puentes
Materia:Computación paralela y distribuida
Descripción: Programa que realiza el calculo de la secuencia de fibonacci
*/

//Se importa a interfaz 
#include "cfib.h"


//Función que realiza el calculo de fibonacci
double cfib(int n) {
    int i;
    double a=0.0, b=1.0, tmp;
    for (i=0; i<n; ++i) {
        tmp = a; a = a + b; b = tmp;
    }
    return a;
}