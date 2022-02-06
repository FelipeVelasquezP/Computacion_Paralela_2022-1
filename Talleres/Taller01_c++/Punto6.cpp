#include <stdio.h>  
#include <iostream>
using namespace std;

/* Fecha: 4/2/22
 * Autor: Luis Felipe Velasquez Puentes
 * Materia: Computación Paralela y Distribuida
 * Tema: Punto 1 de taller c++
*/

main(){
	
	/*Definicion de Variables*/
	int limInf,limSup,sum=0,i;
	
	/*Petición de datos al usuario*/
	cout<<"Digite el numero A: ";
	cin>>limInf;
	while(limInf<0){
		cout<<"No se permite numeros Negativos \n\nDigite nuevamente el numero B: ";
		cin>>limInf;
	}
	
	cout<<"\nDigite el numero B: ";
	cin>>limSup;
	while(limSup<0){
		cout<<"No se permite numeros Negativos \n\nDigite nuevamente el numero B: ";
		cin>>limSup;
	}
	
	/*Se validan si A es mayor que B, en tal caso se intercambian los valores*/
	if (limInf>limSup){
		int aux=limInf;
		limInf=limSup;
		limSup=aux;
	}
	
	cout<<"\nNumero A: "<<limInf<<"\nNumero B: "<<limSup;
	
	/*Cálculo de la suma de los multilpos de 5*/
	for (i=limInf;i<=limSup;i++){
		if(i%5 == 0){
			sum+=i;
		}
	}
	
	cout<<"\n\n***RESULTADO DE LA SUMA: "<<sum<<"**";
	
}


