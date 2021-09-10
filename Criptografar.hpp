#include <iostream>
#include <string.h>
#ifndef CRIPTOGRAFAR_HPP
#define CRIPTOGRAFAR_HPP
using namespace std;

string criptografar(string x){
	
	string CHAVE="CHICO";
	string y=x;
	
	for(int i=0;i<x.size();i++){
		if(i%5==0 || i%5==3){
			x[i]=CHAVE[0];
		}
		else if(i%5==1){
			x[i]=CHAVE[1];
		}
		else if(i%5==2){
			x[i]=CHAVE[2];
		}
		else if(i%5==4){
			x[i]=CHAVE[4];
		}	
	}
	
	for(int i=0;i<x.size();i++){
		if(x[i]==CHAVE[0]){
			y[i]= y[i]+3;
		}
		else if(x[i]==CHAVE[1]){
			y[i]= y[i]+7;
		}
		else if(x[i]==CHAVE[2]){
			y[i]= y[i]+8;
		}
		else if(x[i]==CHAVE[4]){
			y[i]= y[i]+14;
		}
	}
	x=y;
	return x;
}
#endif


