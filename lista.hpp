#ifndef __LISTA_HPP
#define __LISTA_HPP
#include "cliente.hpp"
using namespace std;

#define MAX2 100

struct item{
	char nome[MAX2];
	int val[TAM];
	item* prox;
	item* ant;
};

class lista{
	public:
		
	item* inicio;
	item* fim;
	int tam;
	
	lista();
	
	void add(item val);
	item* remover(int ref);
	void zerar();
	
	void iniciar();
	void imprimir(int limite);
	
	lista reordenar(cliente* c);
	
	void mergeSort (string matriz[][2],int inicio, int fim);
	void merge (string matriz[][2],int inicio,int meio, int fim);
};
#endif


