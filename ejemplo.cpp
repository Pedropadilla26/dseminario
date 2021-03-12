#include <iostream>
using namespace std;




Lista :: Lista(void){
	primero = 0;
	n_nodos = 0;

}

Lista :: Lista(int tamanio){

	n_nodos = tamanio;
	ReservaMemoria(tamanio);

Lista :: Lista(int tamanio, int valor){

	n_nodos = tamanio;
	ReservaMemoria(tamanio);
	TipoNodo *ultimo = primero;

	while(ultimo){
		ultimo->info = valor;
		ultimo = ultimo -> sig;
}


Lista :: Lista(const Lista &l){

	n_nodos = l.n_nodos;

	ReservaMemoria(n_nodos);
	TipoNodo *ultimo = primero;
	TipoNodo *ultimo_l = l.primero;

	while(ultimo_l){
		ultimo->info = ultimo_l->info;
		ultimo = ultimo->sig;
		ultimo_l = ultimo_l->sig;
	}
}

Lista :: ~Lista(void){
	EliminaTodos();
}


Lista :: ReservaMemoria(int tamanio){

	primero = new TipoNodo;
	TipoNodo *ultimo = primero;
	Tiponodo *p;
	
	for(int i = 0; i < tamanio-1; i++){
		p = new TipoNodo;
		ultimo->sig = p;
		ultimo = p;
	}
	ultimo-> sig = 0;
}

bool Lista :: ListaVacia(void){
	return(primero == 0)
}


void Lista :: EliminaTodos(void){
	
	if(!ListaVacia()){

		TipoNodo *p = primero;
	
			while(p){
				primero = p->sig;
				delete p;
				p = primero;
			}
			delete p;
			primero = 0;

		n_nodos = 0;
	}
		
}


int Lista :: NumeroNodos(void){
	return n_nodos;
}


void Lista :: Insertar(TipoBase valor, int pos){

	if(!ListaVacia()){

		TipoNodo *nuevo = new TipoNodo;
		nuevo->info = valor;

		TipoNodo *antes;
		TipoNodo *despues;

		for(int i = 0; i < pos; i++){
			antes = antes->sig;
		}

		despues = antes->sig;

		antes->sig = nuevo;
		nuevo->sig = despues;

		n_nodos++;
	}
}


void Lista :: Elimina(int pos){
	
	if(!ListaVacia()){

		TipoNodo *p;
		TipoNodo *antes;

	
		for(int i = 0; i < pos-1; i++){
			antes = antes->sig;
		}

		p = antes->sig;

		antes->sig = p->sig;
	
		delete p;
		n_nodos--;
	}
}


void Lista :: Aniade(TipoBase valor){

	if(!ListaVacia()){

		TipoNodo *p = primero;
		TipoNodo *nuevo = new TipoNodo;

		while(p){
			p = p->sig;
		}

		nuevo->info = valor;
		nuevo->sig = 0;

		p->sig = nuevo;

		n_nodos++;
	}
} 

TipoBase Lista :: Elemento(int pos){
	
	if(!ListaVacia()){

		TipoNodo *p = primero;

		for(int i = 1; i < pos; i++){

			p = p->sig
		}


		return(p->info);
	}
}


void Lista :: Modifica (int pos, TipoBase val){
	

	if(!ListaVacia()){

		TipoNodo *p = primero;

		for(int i = 1; i < pos; i++){

			p = p->sig
		}

		p->info = val;
	}
}


void Lista :: Lista InicTodos(int val){

	
	if(!ListaVacia()){

		TipoNodo *p = primero;
		 
		while(p){
			p->info = val;
			p = p->sig;
		}
	}
}








	
