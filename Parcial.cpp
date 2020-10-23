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
	listaAux.InsertarFinal(12);
	listaAux.InsertarFinal(2);
	listaAux.InsertarFinal(5);
	listaAux.InsertarFinal(43);
	listaAux.InsertarFinal(7);
	listaAux.InsertarFinal(43);
	listaAux.InsertarFinal(9);
	
	lista listaAux2;
	listaAux2.InsertarFinal(5);
	listaAux2.InsertarFinal(3);
	listaAux2.InsertarFinal(2);
	listaAux2.InsertarFinal(43);
	listaAux2.InsertarFinal(1);
	listaAux2.InsertarFinal(2);
	listaAux2.InsertarFinal(2);
	//UNO
	cout<<"EJERCICIO UNO"<<endl;
	listaAux.UNO(listaAux2);
	cout<<endl;
	
	//DOS
	cout<<"EJERCICIO DOS"<<endl;
	lista ListaPrimos;
	ListaPrimos.DOS(89);
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
