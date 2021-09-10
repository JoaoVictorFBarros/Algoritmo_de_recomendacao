#ifndef _CLIENTE__HPP
#define _CLIENTE__HPP
#include <iostream>
using namespace std;

#define TAM 8

class cliente {
	public:
		
	string nome, senha;
	int afinidade[TAM];
	cliente* ant;
		
	cliente ();
	cliente (string nome,string senha,int afin[TAM]);
		
	int getAfin(int ref);
	void altAfin (int ref,int novoPeso);
};
#endif


