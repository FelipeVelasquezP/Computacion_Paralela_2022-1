#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    //declaración de variables 
    int a,b,c;

    //Solicitud de ingreso de datos al usuario
    printf("\nIntroduzca El valor de a ");
    scanf("%i", &a);
    printf("\nIntroduzca El valor de b ");
    scanf("%i", &b);
    printf("\nIntroduzca El valor de c ");
    scanf("%i", &c);


    //Se valida el numero mayo entre a,b y c
    if(a > b){
        if (a > c){
            printf ("\n a is the largest number  ");
        }else{
            printf ("\n c is the largest number ");
        }
    }else{
        if (b > c){
            printf ("\n b is the largest number ");
        }else{
            printf ("\nE c is the largest number ");
        }
    }
    printf("\n");

    return 0;
}