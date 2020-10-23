/*
Instituto Tecnologico de Costa Rica        Escuela de Computacion
Estructuras de Datos                       Profesora: Ivannia Cerdas
I Parcial                                  Grupo 1
Estudiantes:
Luis Carlos Araya Mata
Sebastian Diaz Obando
*/
//Includes
#include<iostream>
#include "listaSimple.cpp"
using namespace std;

//Main
int main(){
	lista listaAux;
	listaAux.InsertarFinal();
	listaAux.InsertarFinal();
	listaAux.InsertarFinal();
	listaAux.InsertarFinal();
	listaAux.InsertarFinal();
	listaAux.InsertarFinal();
	listaAux.InsertarFinal();
	
	lista listaAux2;
	listaAux2.InsertarFinal();
	listaAux2.InsertarFinal();
	listaAux2.InsertarFinal();
	listaAux2.InsertarFinal();
	listaAux2.InsertarFinal();
	listaAux2.InsertarFinal();
	listaAux2.InsertarFinal();
	//UNO
	cout<<"EJERCICIO UNO"<<endl;
	listaAux.UNO(listaAux2);
	cout<<endl;
	
	//DOS
	cout<<"EJERCICIO DOS"<<endl;
	lista ListaPrimos;
	ListaPrimos.DOS(21);
	cout<<endl;
	
	//TRES
	cout<<"EJERCICIO TRES"<<endl;
	listaAux.TRES();
	cout<<endl;
	
	//CUATRO
	cout<<"EJERCICIO CUATRO"<<endl;
	listaAux.CUATRO();
	
	return 0;
}
