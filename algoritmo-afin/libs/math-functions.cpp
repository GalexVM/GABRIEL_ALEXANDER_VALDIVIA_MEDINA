#include <iostream>
using std::cout;
using std::endl;
#include "../headers/math-functions.h"

int moduloPositivo(int dividendo, int divisor){
	int cociente=dividendo/divisor; //Definir cociente
	int residuo=dividendo-(cociente*divisor);//Definir residuo
	if(residuo<0 && divisor>0){//Si el residuo es negativo y el divisor positivo
		residuo=divisor+residuo;
		cociente-=1;
	}else if(residuo<0 && divisor<0){//Si el residuo es negativo y el divisor negativo
		residuo=(-divisor)+residuo;
		cociente+=1;
	}
	return residuo;
}

int euclides(int r1, int r2){
	int q,r;
	while(r2>0){
		q = r1/r2;
		r = r1 - (q*r2);
		r1 = r2;
		r2 = r;
	}
	return r1;
}

int* euclidesExtendido(int r1, int r2, int s1, int s2, int t1, int t2){
	int q,r,s,t;
	while(r2>0){
		q = r1/r2;
		//Updating r's
		r = r1 - (q*r2);
		r1 = r2;
		r2 = r;
		//Updating s's
		s = s1 - (q*s2);
		s1 = s2;
		s2 = s;
		//Updating t's
		t = t1 - (q*t2);
		t1 = t2;
		t2 = t;
	}
	int resultados[3] = {r1,s1,t1};
	int* rpta = resultados;
	return rpta;
}




