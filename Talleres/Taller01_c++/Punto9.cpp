#include <stdio.h>  
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Fecha: 4/2/22
 * Autor: Luis Felipe Velasquez Puentes
 * Materia: Computación Paralela y Distribuida
 * Tema: Punto 9 de taller c++
*/


/*Función generaraEspacios: Esta función retorna un string con los espacios nesesario
  Para que la piramide se vea ordenada*/
string generarEspacios(int n){
	string esp;
	for(int i=0;i<=n;i++){
		esp+=" ";
	}
	return esp;
}

main(){
	
	/*Definicion de Variables*/
	int filas,limite1,limite2,sum,esp=40;
	string piramide="";
	
	/*Petición de datos al usuario*/
	cout<<"Digite la cantidad de filas entre 11 y 20: ";
	cin>>filas;
	while(filas <11 || filas >20){
		cout<<"\nNo se permite esta cantidad de filas \n\nDigite nuevamente la cantidad de filas: ";
		cin>>filas;
	}
	
	/*Generación de datos de la piramide */
	/*Primer for: itera la cantidad de filas seleccionadas por el usuario*/
	for (int i=1;i<=filas;i++){
		limite1=i+i;
		sum=0;
		vector<string> mitad;
		piramide="\n"+generarEspacios(esp);
		cout<<piramide;
		
		/*Segundo for: itera de tal manera que adicina a un vector la mitad de los datos de cada fila*/
		
		for(int j=i;j<limite1;j++){
			
			if(j==10){
				cout<<" 0  1 ";
				sum=1;
				mitad.push_back("0");
				mitad.push_back("1");
				
			}else if(sum==9){
				
				cout<<" 0  1 ";
				sum=2;
				mitad.push_back("0");
				mitad.push_back("1");
								
			}else if(j>11){
				
				sum++;
				cout<<" "<<sum<<" ";
				mitad.push_back(to_string(sum));
				
			}else if(j<10){
				
				cout<<" "<<j<<" ";
				mitad.push_back(to_string(j));
				
			}	
			
		}	
		
		/*Tercer for: termina de completar los datos en base al vector que tiene la mitad de los datos de cada fila*/
		for (int i = mitad.size()-2; i >=0; i--){
			
			cout<<" "<<mitad[i]<<" ";
			
		}
		
		esp-=3;	
	}
	
}



