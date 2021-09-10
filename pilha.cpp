#include "pilha.hpp"
#include "string.h"
#include <stdlib.h>
#define MAX 100
pilha :: pilha (){
	base = topo = NULL;
	tam=0;
}


void pilha :: empilhar (cliente* c){
	
	cliente* aux;
	
	if (base == NULL){
		base = (cliente*) malloc (sizeof(cliente));
		
		topo = (cliente*) malloc (sizeof(cliente));
		memcpy(topo,c,sizeof(cliente));
	}
	else{
		
		aux = topo;
		topo = (cliente*) malloc (sizeof (cliente));
		memcpy(topo,c,sizeof(cliente));
		topo->ant = aux;
	}
	this -> tam++;
}


cliente* pilha :: desempilhar (){

	cliente* aux;
	aux = topo;
	topo = topo->ant;
	tam--;
	
	return aux;
}


void pilha :: salvar(){
	
	inverter();
	string save;
	cliente* aux;
	int tamAux = tam;	
	
	for (int i=0;i<tamAux;i++){
		aux=desempilhar();
		save = save + aux->nome ;
		save = save + aux->senha ;
		for (int i=0;i<TAM;i++){
			save = save + to_string(aux->afinidade[i]) + ",";
		}
		save = save + "\n";
	}
	save.pop_back();
	
	FILE* p;
	p = fopen("Clientes.txt","w");
	char c[save.size()];
	
	for (int i=0;i<save.size();i++){
		c[i] = save[i];
	}
	fputs(c,p);
	fclose(p);	
}

void pilha :: carregar(){
	
	FILE *p;
	p = fopen("Clientes.txt","r");
	string aux2;
	string::size_type st;
	cliente c[MAX];
	int cont=0;
	
	while (not feof(p)){
		
		char aux[MAX];
		
		fgets(aux,MAX,p);
		c[cont].nome = aux;
	
		fgets(aux,MAX,p);
		c[cont].senha = aux;
		
		fgets(aux,MAX,p);
		aux2 = strtok(aux,",");
		
		for (int i=0;i<TAM;i++){
			c[cont].afinidade[i] = stod(aux2,&st);
			if (i != TAM-1){
				aux2 = strtok(NULL,",");
			}
		}	
		cont++;
	}
	for (int i=0;i<cont;i++){
		empilhar(&c[i]);
	}
}


int pilha :: buscar (string nome,string senha){
	
	cliente* aux;
	aux = topo;
	
	for (int i=0;i<tam;i++){
		if (aux->nome == nome and aux->senha == senha){
			moverTopo(aux);
			return 0;
		}
		else if (aux->nome == nome){
			return 1;
		}
		aux = aux->ant;
	}
	return 2;
}


void pilha :: imprimir(){
	
	setlocale(LC_ALL,"portuguese");
	cout<<"Tam: "<<tam<<"\n\n\n";
	cout<<"\n---------------------------------------------\n";
	cliente* aux;
	aux = topo;
	
	for (int i=0;i<tam;i++){
		cout<<i+1<<"º Cliente: \nNome: "<<aux->nome<<"\nSenha: "<<aux->senha<<"\n";
		for (int i=0;i<TAM;i++){
			cout<<"["<<aux->afinidade[i]<<"]";
		}
		cout<<"\n---------------------------------------------\n";
		aux = aux->ant;	
	}	
}


void pilha :: inverter (){
	
	cliente* aux;
	pilha p,p2;
	int tamAux = tam;
	
	for (int i=0;i<tamAux;i++){
		p.empilhar(desempilhar());
	}
	
	for (int i=0;i<tamAux;i++){
		p2.empilhar(p.desempilhar());
	}
	
	for (int i=0;i<tamAux;i++){
		empilhar(p2.desempilhar());
	}
}


void pilha :: moverTopo(cliente* c){
	
	pilha paux;
	cliente* aux;
	int tamaux = tam;
	aux = topo;
				
	while (aux->nome != c->nome){
		paux.empilhar(desempilhar());
		aux = topo;
	}
	desempilhar();
	while (tam < tamaux-1){
		empilhar(paux.desempilhar());
	}
	empilhar(aux);
}


