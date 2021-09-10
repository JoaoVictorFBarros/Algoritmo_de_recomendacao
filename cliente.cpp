#include "cliente.hpp"

cliente :: cliente (){
	
}


cliente :: cliente (string nome,string senha,int afin[TAM]){
	
	this -> nome = nome;
	this -> senha = senha;
	
	for (int i=0;i<TAM;i++){
		this -> afinidade[i] = afin[i];
	}
}


int cliente :: getAfin(int ref){

	return this -> afinidade[ref];
}


void cliente :: altAfin(int ref, int novoPeso){
	
	this -> afinidade[ref] = novoPeso;
}


