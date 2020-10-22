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
	listaAux.InsertarFinal(5);
	listaAux.InsertarFinal(7);
	listaAux.InsertarFinal(9);
	listaAux.InsertarFinal(10);
	listaAux.InsertarFinal(14);s
	
	lista listaAux2;
	listaAux2.InsertarFinal(5);
	listaAux2.InsertarFinal(7);
	listaAux2.InsertarFinal(4);
	listaAux2.InsertarFinal(6);
	listaAux2.InsertarFinal(18);
	//UNO
	cout<<"EJERCICIO UNO"<<endl;
	listaAux.UNO(listaAux2);
	cout<<endl;
	//DOS
	cout<<"EJERCICIO DOS"<<endl;
	lista ListaPrimos;
	ListaPrimos.DOS(15);
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
