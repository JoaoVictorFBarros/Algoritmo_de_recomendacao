#ifndef __MENU_HPP
#define __MENU_HPP
#include <iostream>
#include "cliente.hpp"
using namespace std;

#define QTDE 5
#define LIM 40
#define TAXA 1000

void interface(pilha* p,lista* l){
	
	setlocale(LC_ALL,"portuguese");
	string nome;
	int op=0;
	int cont=1;
	while (op != 3){
		cliente c = *p->desempilhar();
		nome = c.nome;
		p->empilhar(&c);
		nome.pop_back();
		system ("cls");
		int fav;
		
		system("cls");
		cout<<"------------------------------------Bem-vindo(a)-"<<nome<<"------------------------------------";
	
		cout<<"\n\n\nRecomendados para você: \n\n";	
		lista laux;	
		laux = l->reordenar(&c);	
		laux.imprimir(cont*QTDE);
		
		cout<<"\n";
		if (cont < laux.tam/QTDE){
			cout<<"\n1- Ver mais ";
		}
		cout<<"\n2- Enviar feedback\n3- Sair\n\n\nOperação: ";
		cin>>op;
		
		switch (op){
			
			case 1:{
				if (cont < laux.tam/QTDE){
					cont++;
				}	
				break;
			}
			case 2:{
				cont=1;
				cout<<"\n\nDentre essas opções qual sua favorita: ";
				cin>>fav;
				cout<<"\n\n\nObrigado pelo feedback!\n\n";
				system("pause");
				cliente* aux;
				aux = p->desempilhar();
				item* iaux = laux.inicio;
				
				for (int i=0;i<fav;i++){
					iaux = iaux->prox;
				}
				item* iaux2 = l->inicio;
				
				string nomeAux(iaux->nome),nomeAux2(iaux2->nome);
				int contAux=0;

				while (nomeAux2 != nomeAux){
					iaux2 = iaux2->prox;
					contAux=0;
					string nomeAux3(iaux2->nome);
					nomeAux2 = nomeAux3;
				}
				
				for (int j=0;j<TAM;j++){
					float razao =(float) (iaux2->val[j]-50)/TAXA;
					aux->altAfin(j,(1 + razao )*(aux->afinidade[j]));
					if (aux->afinidade[j] >100){
						aux->afinidade[j] = 100;
					}
					else if (aux->afinidade[j] < 1){
						aux->afinidade[j] = 1;
					}
				}
				p->empilhar(aux);
				break;
			}
			default:{
				cont=1;
				break;
			}
		}	
		system("cls");
	}
	p->salvar();
}

#endif


