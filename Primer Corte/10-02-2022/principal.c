
/*  Universidad Sergio Arboleda
    Autor:Luis Felipe Velasquez
    Fecha:10-2-22
    Materia:Parallel Computing
    Tema:Programacion Modular en C
    Fichero:Principal*/


/*Se presenta la cabecera del Mòdulo*/
#include "funciones.h"
#include <stdio.h>

int main(){
    int a=10,b=2, resultado;
    printf("Programa Principal\n");
    printf("LLamada a la funcion \n");
    resultado = Sumar(a,b);
    printf("Resultado de la funcion: %d \n",resultado);

    return 0;
}