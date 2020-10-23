#include <iostream>
using namespace std;

class nodo { 
	
   public:
    nodo(int v) 
    {
       valor = v;
       veces = 1;
       siguiente = NULL;
    }

 
    nodo(int v, nodo * signodo) 
    {
       valor = v;
       veces = 1;
       siguiente = signodo;
    }

   private: 
    int valor;
	int veces; 
    nodo *siguiente;
    
        
   friend class lista;

};
typedef nodo *pnodo; 

class lista {
   public:
    lista()
	{
      primero=NULL;   	
    	
	}
    ~lista();
    void InsertarInicio(int v);
    void InsertarFinal(int v);
    bool ListaVacia() { return primero == NULL; } 
    void Mostrar();
    int largoLista();
    void UNO(lista& lista2);
    void DOS(int num);
    void TRES();
    void CUATRO();
    pnodo RetornarNodo(int pos);
   private:
    pnodo primero; 
   
};
//Funciones
bool esPrimo(int numero) {

  if (numero == 0 || numero == 1 || numero == 4) return false;
  for (int x = 2; x < numero / 2; x++) {
    if (numero % x == 0) return false;
  }
  return true;
}


//Metodos
  
lista::~lista() 
{
   pnodo aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
  
}

int lista::largoLista(){ 
    int cont=0;

    pnodo aux; 
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    }
    
}

void lista::InsertarInicio(int v)
{
   if (ListaVacia())
     primero = new nodo(v);
   else
     primero=new nodo (v,primero);
}
 
void lista::InsertarFinal(int v)
{
   if (ListaVacia())
     primero = new nodo(v);
   else
     { pnodo aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodo(v);
      }    
}

void lista::Mostrar()
{
   nodo *aux;
   if (primero== NULL)
       cout << "No hay elementos";  
   else
   {
   
       
   		aux = primero;
		while(aux) 
		{
		    cout << aux->valor << "-> ";
		    aux = aux->siguiente;
		}
		cout << endl;
   }
}
pnodo lista::RetornarNodo(int pos){
	pnodo buscar = primero;
	int cont = 1;
	while(cont!=pos){
		buscar = buscar->siguiente;
		cont++;
	}
	return buscar;
	
}

void lista::UNO(lista& lista2){
	if(largoLista()!=lista2.largoLista()){
		cout<<"Las listas no son del mismo largo"<<endl;
	}else{
		bool condicion = largoLista()%2==1;
		if(!condicion){
			cout<<"Las listas no son impares"<<endl;
		}else{
			bool condicion2 = largoLista()!=1;
			if(!condicion2){
				cout<<"Las listas son de largo 1"<<endl;
			}else{
				pnodo buscarC = primero;
				pnodo buscarC2 = lista2.primero;
				int cont = 0;
				int limite = (largoLista()-1)/2;
				while(cont < limite ){
					buscarC = buscarC->siguiente;
					buscarC2 = buscarC2->siguiente;
					cont++;
				}
				int centro1 = buscarC->valor;
				int centro2 = buscarC2->valor;
				lista listaF;
				int L1 = cont;
				int L2 = cont+2;
				int LS1 = 1;
				int LS2 = largoLista();
				while(limite!=0){
					listaF.InsertarFinal((lista2.RetornarNodo(L1)->valor)*centro1);
					L1--;
					listaF.InsertarFinal((lista2.RetornarNodo(L2)->valor)*centro1);
					L2++;
					listaF.InsertarFinal((RetornarNodo(LS1)->valor)*centro2);
					LS1++;
					listaF.InsertarFinal((RetornarNodo(LS2)->valor)*centro2);
					LS2--;
					limite--;
				}
				cout<<"Lista Final: "<<endl;
				listaF.Mostrar();
			}
		}
	}
	
}
void lista::DOS(int num){
	for(int valor = 0;valor<=num;valor++){
		if(esPrimo(valor)){
			InsertarFinal(valor);
		}
		else{
			continue;
		}
	}
	cout<<"Lista con los numeros primos: "<<endl;
	Mostrar();
}
void lista::TRES(){
    lista listaN;
    if (ListaVacia()){
           cout << "La lista esta vacia"<<endl;; 
    }else{
        pnodo aux = primero;
        while(aux!=NULL) {
            listaN.InsertarFinal(aux->valor+1);
            listaN.InsertarFinal(aux->valor);
            listaN.InsertarFinal(aux->valor-1);
            aux = aux->siguiente;
        }
    cout<<"Lista antecesor y sucesor: "<<endl;
    listaN.Mostrar();
   }
}
void lista::CUATRO(){
	lista nueva;
	pnodo recorrer = primero;
	while(recorrer!=NULL){
		pnodo aux = nueva.primero; bool flag = false;
		while(aux!=NULL){
			if(aux->valor==recorrer->valor){
				aux->veces=aux->veces+1;
				flag = true;
				break; 
			}
			else{
				aux=aux->siguiente;
			}
		}
		if(!flag){
			nueva.InsertarFinal(recorrer->valor);
			recorrer=recorrer->siguiente;
		}
		else{
			recorrer=recorrer->siguiente;
		}
	}
	pnodo final = nueva.primero; bool flag= false;
	cout<<"Lista con contador de repetidos: "<<endl;
	while(final!=NULL){
		flag=true;
		cout<<final->valor<<"-"<<final->veces<<"->";
		final = final->siguiente;
	}if(!flag){
		cout<<"La lista esta vacia"<<endl;
	}
}

