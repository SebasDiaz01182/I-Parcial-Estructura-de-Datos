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
    void InsertarPos (int v, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Imprimir();
    void Mostrar();
    void Primero();
	void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    void DOS(int num);
    void TRES();
    void CUATRO();
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

void lista::InsertarPos(int v, int pos) 
{
   if (ListaVacia())
     primero = new nodo(v);
   else{
        if(pos <=1){                     
          pnodo nuevo = new nodo(v);
          nuevo->siguiente= primero;
          primero= nuevo;     
        }      
        else
		{
        	if (pos>=largoLista())
			   InsertarFinal(v);
			else
			{
			
             pnodo aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodo nuevo= new nodo(v); 
             nuevo->siguiente=aux->siguiente; 
             aux->siguiente=nuevo;
            }
             
        }
        }
}
      
void lista::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
                primero= NULL;
            } else {

                pnodo aux = primero;
                while (aux->siguiente->siguiente != NULL) {
                    aux = aux->siguiente;

                }
                
              pnodo temp = aux->siguiente;
              aux->siguiente= NULL;

                
                delete temp;
            }
        }
}

void lista::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else
   {
        if (primero->siguiente == NULL)
		{
        	    pnodo temp=primero;
                primero= NULL;
                delete temp;
        }
		else
		{

                pnodo aux = primero;
                primero=primero->siguiente;                
                delete aux;
        }
   }
}



void lista:: borrarPosicion(int pos){
     if(ListaVacia()){
              cout << "Lista vacia" <<endl;
    }else{
         if((pos>largoLista())||(pos<0)){
        cout << "Error en posicion" << endl;
        }else{
        if(pos==1){
        primero=primero->siguiente;
        }else{
          int cont=2;
            pnodo aux=  primero;
            while(cont<pos){
             aux=aux->siguiente;
             cont++;
            }
            aux->siguiente=aux->siguiente->siguiente;
            }
        }
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
    if (primero == NULL){
           cout << "No hay elementos"; 
    }else{
        pnodo aux = primero;
        while(aux!=NULL) {
            listaN.InsertarFinal(aux->valor+1);
            listaN.InsertarFinal(aux->valor);
            listaN.InsertarFinal(aux->valor-1);
            aux = aux->siguiente;
        }
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
	pnodo final = nueva.primero;
	while(final!=NULL){
		cout<<final->valor<<"-"<<final->veces<<"->";
		final = final->siguiente;
	}
}

