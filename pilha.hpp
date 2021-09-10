#ifndef _PILHA__HPP
#define _PILHA__HPP
#include "cliente.hpp"
using namespace std;

class pilha {
	public:
		cliente* topo;
		cliente* base;
		
		int tam;
		
	public:
		pilha ();
		
		void empilhar(cliente* c);
		cliente* desempilhar();
		
		void salvar();
		void carregar();
		
		int buscar(string nome,string senha);
		void inverter();
		
		void moverTopo(cliente* c);
		void imprimir();
};

#endif


