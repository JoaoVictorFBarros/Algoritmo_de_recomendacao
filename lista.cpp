#include "lista.hpp"
#include <iostream>
#include <string.h>

#define palavra 100

lista :: lista (){
	inicio = fim = NULL;
	tam=0;
}


void lista :: add(item val){
		
	item* ant;
	
	if (inicio == NULL){
		inicio = (item*) malloc(sizeof(item));
		fim = (item*) malloc (sizeof(item));
		memcpy(fim,&val,sizeof(item));
		inicio->prox = fim;	
		fim->ant = inicio;
	}
	else{
		ant = fim;
		fim = (item*) malloc(sizeof(item));
		memcpy(fim,&val,sizeof(item));
		ant->prox = fim;
		fim->ant = ant;	
	}
	this -> tam++;
}


item* lista :: remover(int ref){
	
	item* aux;
	aux = inicio;

	for (int i=0;i<ref;i++){
		aux = aux->prox;
	}
	
	aux->ant->prox = aux->prox;
	aux->prox->ant = aux->ant;
	
	return aux;	
}


void lista :: zerar (){
	
	item* aux;
	item* aux2;
	aux = inicio;
	
	for (int i=0;i<tam;i++){
		aux2 = aux;
		aux = aux->prox;
		free(aux2);
	}
}


void lista :: iniciar (){
	FILE *f;
	item novo;
	char titulo[MAX2];
	
	f = fopen("Dados.txt","r");
	fgets (titulo,MAX2,f);
	
	if (f == NULL){
		cout<<"\n\n[ERRO] Não foi possível abrir o arquivo.\n\n";
	}
	else{
		
		while (not feof(f)){
			char aux[MAX2];
			fgets(aux,MAX2,f);
			strtok(aux,",");
			
			for (int i=0;i<sizeof(aux);i++){
					novo.nome[i] = aux[i];
			}
			novo.nome[sizeof(aux)] = '\0';
	
			for (int i=0;i<TAM;i++){
				novo.val[i] = stod(strtok(NULL,","));
			}
			add(novo);
		}		
	}	
}


void lista :: imprimir(int limite){
	
	item* p;
	p = inicio->prox;
	int cont =0;
	
	for (int i=0;i<limite;i++){
		cont++;
		cout<<cont<<" - "<<p->nome;
		cout<<"\n";
		p = p->prox;
	}
}


lista lista :: reordenar (cliente* c){
	
	item* aux;
	lista laux;
	aux = inicio->prox;
	string matriz[tam][2];
	int media=0;
	for (int i=0;i<tam;i++){
		for (int j=0;j<TAM;j++){
			media = media + aux->val[j]*c->afinidade[j];
		}
		matriz[i][0] = to_string(media);
		media = 0;
		matriz[i][1] = aux->nome;
		aux = aux->prox;
	}
	mergeSort(matriz,0,tam-1);
	
	item aux2;
	int cont=0;
	
	for (int i=0;i<matriz[0][0].size();i++){
		aux2.nome[i] = matriz[0][0][i];
	}
	aux2.nome[cont] = '\0';
		
	for (int i=tam-1;i>=0;i--){
		
		for (int j=0;j<matriz[i][1].size();j++){
			aux2.nome[j] = matriz[i][1][j];					
		}
		aux2.nome[matriz[i][1].size()] = '\0';
		laux.add(aux2);
	}
	return laux;
}


void lista :: mergeSort (string matriz[][2],int inicio, int fim){
			
	if (inicio >= fim){
		return;
	}
	
	int meio = inicio + (fim - inicio)/2;
	
	mergeSort(matriz,inicio,meio);
	mergeSort(matriz,meio + 1,fim);
	
	merge (matriz,inicio,meio,fim);
}


void lista :: merge (string matriz[][2],int inicio,int meio, int fim){
	
	int tamE = meio - inicio + 1;
	int tamD = fim - meio;
	string vetE[tamE][2], vetD[tamD][2];
	
	for (int i=0;i<tamE;i++){
		vetE[i][0] = matriz[i + inicio][0];
		vetE[i][1] = matriz[i + inicio][1];
	}
	for (int i=0;i<tamD;i++){
		vetD[i][0] = matriz[i + meio + 1][0];
		vetD[i][1] = matriz[i+ meio + 1][1];
	}
	
	int contE = 0;
	int contD = 0;
	int contM = inicio;

	while (contE < tamE and contD < tamD){

		if (stod(vetE[contE][0]) <= stod(vetD[contD][0])){
			matriz[contM][0] = vetE[contE][0];
			matriz[contM][1] = vetE[contE][1];	
			contE++;
		}
		else{
			matriz[contM][0] = vetD[contD][0];
			matriz[contM][1] = vetD[contD][1];
			contD++;
		}
		contM++;
	}

	while (contE < tamE){
		matriz[contM][0] = vetE[contE][0];
		matriz[contM][1] = vetE[contE][1];	
		contE++;
		contM++;
	}
	while (contD <tamD){
		matriz[contM][0] = vetD[contD][0];
		matriz[contM][1] = vetD[contD][1];
		contD++;
		contM++;
	}
}


