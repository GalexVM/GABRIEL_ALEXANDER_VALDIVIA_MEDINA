#pragma once
#include <iostream>
#include<string>
using std::string;

class algoritmoCesar {
private:
	int clave = 5;
public:
	string alfabeto ="abcdefghijklmnopqrstuvwxyz";
	string cifrar(string &msg);
	string descifrar(string &msg);
	void romper(string &msg);
};

void introducirMensaje(string& msg);
int moduloPositivo(int dividendo, int divisor);

