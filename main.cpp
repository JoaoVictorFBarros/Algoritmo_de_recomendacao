#include "cliente.hpp"
#include "pilha.hpp"
#include "lista.hpp"
#include "SignIn.hpp"
#include "Criptografar.hpp"
#include "login.hpp"
#include "menu.hpp"

int main (){
	
	setlocale(LC_ALL,"portuguese");	
	lista l;
	l.iniciar();
	pilha p;
	p.carregar();

	int op=0;
	
	while (true){
		cout<<"------------------------------------Inicio------------------------------------\n";
		cout<<"Digite:\n\n1- Entrar\n2- Criar conta\n3- Sair\n\nOperação: ";
		cin>>op;
		system ("cls");
		
		switch (op){
			
			case 1:{
				cout<<"------------------------------------Entrar------------------------------------\n\n\n";
				while (not login(&p)){
					system("pause");
					system("cls");
					cout<<"------------------------------------Entrar------------------------------------\n\n\n";
				}
				interface(&p,&l);
				break;
			}
			case 2:{
				cin.ignore();
				system ("cls");
				criarConta(&p);	
				interface(&p,&l);
				break;
			}
			case 3:{
				return 0;
				
				break;
			}
			
			default:{
				cout<<"[ERRO]Operação inexistente.\n\n\n";
				break;
			}
		}
	}
}


