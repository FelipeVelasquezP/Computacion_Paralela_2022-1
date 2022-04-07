#include <stdio.h>  
#include <iostream>
#include <string>
using namespace std;

/* Fecha: 4/2/22
 * Autor: Luis Felipe Velasquez Puentes
 * Materia: Computación Paralela y Distribuida
 * Tema: Punto 11 de taller c++
*/

main(){
	
	/*Definicion de Variables*/
	int tipo, km,tm,importe;
	
	/*Petición de datos al usuario*/
	std::string menu= std::string(" ******SELECCIONE TIPO DE VEHICULO******\n")+
				 std::string(" 1. Bicicleta \n")+
				 std::string(" 2. Moto \n")+
				 std::string(" 3. Coche \n")+
				 std::string(" 4. Camion \n")+
				 std::string(" 5. Salir \n");
	cout<<menu;
	cin>>tipo;
	
	
	while(tipo>5 || tipo<0){
		cout<<"\n La opcion seleccionada no existe \n\n: "<<menu;
		cin>>tipo;
	}
	
	
	
	switch(tipo) {
	   case 1  :
	      importe=100;
	      break; 
	      
	   case 2  :
	   case 3  :
	   	  cout<<"Digite la cantidad de Kilometros: ";
	   	  cin>>km;
	   	  importe=30*km;
	      break; 
	    
	    case 4:
	   	  cout<<"Digite la cantidad de Kilometros: ";
	   	  cin>>km;
		  cout<<"Digite la cantidad de Toneladas: ";
	   	  cin>>tm;	    	
	      importe=30*km+25*tm;
	      break;
	    
	    case 5:
	      return 0;
	    	
	  
	}
	cout<<" \n******El importe total es "<<importe<<"******\n";

}



