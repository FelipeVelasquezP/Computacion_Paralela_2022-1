#include <stdio.h>  
#include <iostream>
using namespace std;

/* Fecha: 6/2/22
 * Autor: Luis Felipe Velasquez Puentes
 * Materia: Computación Paralela y Distribuida
 * Tema: Punto 10 de taller c++
*/

main(){
	
	/*Definicion de Variables*/
	int n,i,j,k,sumSuperior,sumInferior,centro;
	
	/*Petición de datos al usuario*/
	cout<<"Digite el valor de n: ";
	cin>>n;
	
	while(n<=0){
		cout<<"\nNo se permite cantidades negativas para ns \n\nDigite nuevamente la cantidad de n: ";
		cin>>n;
	}
	
	/*En los siguientes for anidado , se realzio el  cálculo para encontrar los centros numericos*/
	cout<<"\nn = "<<n<<"\n\n";
	/*Iteración de 1 hasta n*/
	for (i=1;i<=n;i++){
		
		sumInferior=0;
		sumSuperior=0;
		centro=i;
		
		/*Iteración desde el centro a evaluar hasta n con el fin de evaluar la suma de los numeros
		 inferiores al posible centro*/
		for (j=i-1;j>0;j--){
			
			sumInferior+=j;
			sumSuperior=0;
			
			/*Iteración desde el centro a evaluar hasta n con el fin de evaluar la suma de los numeros
		 	Superiores al posible centro*/
			for (k=i+1;k<=n;k++){
				sumSuperior+=k;
				if (sumInferior==sumSuperior){		
					if(centro<10){
						cout<<" ";
					}
					cout<<centro<<" es un centro numerico con suma igual a "<<sumInferior<<"\n";
				}
			}	
			
		}
		
	}
}







