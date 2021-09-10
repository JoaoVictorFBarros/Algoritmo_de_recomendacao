#include <iostream>
#include "pilha.hpp"
#include "Criptografar.hpp"
#include <conio.h>

#define CAB 300
using namespace std;

bool VerificarNome(string nome, pilha p){
	
	pilha aux;
	bool ver = true;
	
	for (int i=0;i<p.tam;i++){
		cliente* c;
		c = p.desempilhar();
		aux.empilhar(c);
		
		if (nome == c->nome){
			ver = false;
			break;
		}
	}
	for (int i=0;i<aux.tam;i++){
		p.empilhar(aux.desempilhar());
	}	
	return ver;
}


void criarConta(pilha *p){
	
	setlocale(LC_ALL,"portuguese");
	
	cout<<"------------------------------------Criar-conta------------------------------------\n\n\n";
	string nome= "-",senha="-",ver=".";
	int afin[TAM];
	bool aux = true;	
	
	while (aux or  not VerificarNome(nome,*p)){
		cout<<"Digite um nome de usuário: ";
		getline(cin,nome);
		nome = nome + "\n";
		aux=false;
		
		if (not VerificarNome(nome,*p)){
			cout<<"[ERRO] Nome já existente, escolha outro.\n\n";
			system("pause");
			system("cls");
			cout<<"------------------------------------Criar-conta------------------------------------\n\n\n";
		}
	}
	cout<<"\n";
	while (senha != ver){
		senha = ver = "";
		cout<<"Digite uma senha: ";
		char ch= _getch();
		while (ch != 13){
			cout<<"*";
			ver.push_back(ch);
			ch= _getch();
		}
		cout<<"\n\nDigite a senha novamente: ";
		ch= _getch();
		while (ch != 13){
			cout<<"*";
			senha.push_back(ch);
			ch= _getch();
		}
		
		if (senha != ver){
			cout<<"\n\n[ERRO] as senhas são diferentes \n\n\n";
			system ("pause");
			system ("cls");
			cout<<"------------------------------------Criar-conta------------------------------------\n\n\n";
			cout<<"Digite um nome de usuário: "<<nome<<"\n";
		}
	}
	system("cls");
	cout<<"------------------------------------Iniciando-conta------------------------------------\n\n\n";
	senha = criptografar(senha);
	
	senha = senha + "\n";
	
	FILE *pont;
	pont = fopen("Dados.txt","r");
	
	string genero[TAM];
	char aux2[CAB];
	
	fgets(aux2,CAB,pont);
	
	strtok(aux2,",");
	
	for (int i=0;i<TAM;i++){
		genero[i] = strtok(NULL,",");
	}
	
	int fav,mais[2];
	
	for (int i=0;i<TAM;i++){
		afin[i] = 0;
	}
	
	cout<<"Lista: \n";
	for (int i=0;i<TAM;i++){
		cout<<i+1<<" - "<<genero[i]<<"\n";
	}
	
	cout<<"Digite seu gênero favorito: ";
	cin>> fav;
	
	afin[fav-1] = 75;
	
	cout<<"Digite outros 2 gêneros que goste: ";
	cin>>mais[0];
	cin>>mais[1];
	
	for (int i=0;i<2;i++){
		afin[mais[i]-1] = 50;
	}
	
	for (int i=0;i<TAM;i++){
		if (afin[i] == 0){
			afin[i] = 20;
		}
	}
	
	cliente c(nome,senha,afin);
	p->empilhar(&c);
}


