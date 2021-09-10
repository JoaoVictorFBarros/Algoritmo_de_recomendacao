#ifndef __LOGIN_HPP
#define __LOGIN_HPP
#include "Criptografar.hpp"
#include "pilha.hpp"
#include <conio.h>
using namespace std;

bool login(pilha *p){
	
	setlocale(LC_ALL,"portuguese");
	string nome,senha;
	int cont=0;
	char ch;
	
	cout<<"Digite seu nome de usuário: ";
	cin>>nome;
	nome = nome + "\n";
	cout<<"Digite sua senha: ";
	ch= _getch();
	while (ch != 13){
		cout<<"*";
		senha.push_back(ch);
		ch= _getch();
	}
	
	senha = criptografar(senha);
	senha = senha + "\n";
	
	if (not p->buscar(nome,senha)){	
		return true;
	}
	else if (p->buscar(nome,senha) == 2){
		cout<<"\n\n[ERRO] Usuário inexistente.\n\n";
		return false;
	}
	else if (p->buscar(nome,senha) == 1){
		cout<<"\n\n[ERRO] Senha incorreta.\n\n";
		return false;
	}
}
#endif


