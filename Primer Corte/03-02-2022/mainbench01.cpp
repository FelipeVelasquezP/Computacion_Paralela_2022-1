/* Fecha: 3/2/22
 * Autor: Luis Felipe Velasquez Puentes
 * Materia: Computación Paralela y Distribuida
 * Tema: Construcción del primer Benchmark
 * Benchmark: Aplicaión de juguete que permite evaluar rendimiento 
   de un aspecto específico de la computadora
*/

#include <iostream>
#include <vector>
#include <random>
using namespace std;

/*Función Multiplicaion Matrices:
  Se requiere multipliar las dos matrices: Adicionalmente 
  los ingenieros deben verificar y validar que realmente 
  se cumpla el algoritmo de multiplicación*/
vector<vector<double>> MultiMatriz(vector<vector<double>> Ma,
								   vector<vector<double>> Mb){	
	int i,j,k;
	vector<vector<double>> Mresultado(Ma.size(),vector<double>(Ma.size(),0));
	for(i=0;i<Ma.size();++i){
		for(j=0;j<Ma.size();++j){
			for(k=0;k<Ma.size();++k){
				Mresultado[i][j]+=Ma[i][k]*Mb[k][j];
			}
		}	
	}
	return Mresultado;
}


/* Funcion Inicialización: Se requiere inicializar las matrices con numeros aleatorios*/
	
vector<vector<double>> InicializacionMatriz(vector<vector<double>> M){
	int i,j;
	float limInf=0.001,limSup=9.999;
	vector<vector<double>> Minicializada(M.size(),vector<double>(M.size(),0));
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(limInf,limSup);
	
	for(i=0;i<M.size();++i){
		for(j=0;j<M.size();++j){
			Minicializada[i][j]=dis(gen);
		}
	}
	return Minicializada;
}

/*Se crea la función para imprimir matrices*/
void ImprimirMatriz(vector<vector<double>> M){
int i,j;
for(i=0;i<M.size();++i){
		for(j=0;j<M.size();++j){
			cout<<M[i][j]<<"   ";
		}
		cout<<"\n";
	}
}
/* Se requiere implementar una aplicación que multiplique dos matrices
   Las matrices deben ser de doble presición
   El algoritmo a usar sera el clasico (filas por columnas)*/
   
   

int main(int argc, char** argv) {
	int i,j,k;
	int N = atoi(argv[1]);
	
	/*Se usa la clase vector para crear las matrices*/
	vector<vector<double>> M1(N,vector<double>(N,0));
	vector<vector<double>> M2(N,vector<double>(N,0));
	vector<vector<double>> MR(N,vector<double>(N,0));
	
	M1=InicializacionMatriz(M1);
	M2=InicializacionMatriz(M2);
	
	/* Se imprime M1*/
	cout << "Se imprime M1" <<"\n";
	ImprimirMatriz(M1);
	cout << "\n \n \n";
	
	/* Se imprime M2*/
	cout << "Se imprime M2" <<"\n";
	ImprimirMatriz(M2);
	cout << "\n \n \n";
	
	/*Se hace la multiplicación*/
	MR=MultiMatriz(M1,M2);
	
	/* Se imprime MR*/
	cout << "Se imprime MR" <<"\n";
	ImprimirMatriz(MR);
	cout << "\n \n \n";
	
	
	return 0;
}
