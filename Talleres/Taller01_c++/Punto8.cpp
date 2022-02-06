#include <stdio.h>  
#include <iostream>
using namespace std;

/* Fecha: 4/2/22
 * Autor: Luis Felipe Velasquez Puentes
 * Materia: Computación Paralela y Distribuida
 * Tema: Punto 7 de taller c++
*/


/*Función que permite validar si la fecha ingresada tiene datos negativos*/
int verificarNegativo(int dato){
	while(dato<0){
		cout<<"\nNo se permite numeros Negativos para b \n\nDigite nuevamente el valor : ";
		cin>>dato;
	}
	return dato;
}

/*Función que permite validar si la fecha ingresada tiene datos incorrectos*/
int verificarFecha(int dato,int rango){
	while(dato>rango){
		cout<<"\nEste valor no soporta numeros mayores a "<<rango<<" \n\nDigite nuevamente el valor : ";
		cin>>dato;
	}
	return dato;
}

main(){
	
	/*Definicion de Variables*/
	int dia,mes,ano,suma1,sum2,tarot;
	
	/*Petición de datos al usuario*/
	cout<<"Digite su dia de nacimiento: ";
	cin>>dia;
	dia=verificarNegativo(dia);
	dia=verificarFecha(dia,31);
	
	cout<<"\nDigite su mes de nacimiento: ";
	cin>>mes;
	mes=verificarNegativo(mes);
	mes=verificarFecha(mes,12);
	
	cout<<"\nDigite su año de nacimiento: ";
	cin>>ano;
	ano=verificarNegativo(ano);
	ano=verificarFecha(ano,2021);
	
	cout<<"\nSu fecha de nacimiento es: "<<dia<<"/"<<mes<<"/"<<ano;
	
	/*Cálculo del numero del tarot*/
	suma1=dia+mes+ano;
	sum2=(suma1%10)+((suma1/10)%10)+((suma1/100)%10)+(suma1/1000);
	tarot=(sum2/10)+(sum2%10);
	
	cout<<"\n***SU NUMERO DE TAROT ES: "<<tarot<<"***";
}



