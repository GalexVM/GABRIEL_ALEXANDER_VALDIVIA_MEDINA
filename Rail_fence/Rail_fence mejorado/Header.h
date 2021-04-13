#pragma once
#include <iostream>
#include <string>
using std::string;

class AlgCifradoRailFence {
private:
	int clave = 4;
public:
	string cifrar(string& msg);

	string descifrar(string& msg);
};

void ingresarMensaje(string& msg);
