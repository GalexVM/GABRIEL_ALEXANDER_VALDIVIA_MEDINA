#include <iostream>
#include <string>
#include "Header.h"
using std::cout;
using std::endl;
using std::string;

int main() {
	string msg;
	AlgCifradoRailFence emisor, receptor;
	ingresarMensaje(msg);
	string msgCifrado = emisor.cifrar(msg);
	cout << "...Cifrando su mensaje..." << endl << msgCifrado << endl;
	string msgDescifrado = receptor.descifrar(msgCifrado);
	cout << "...Descifrando su mensaje..." << endl << msgDescifrado << endl;


	return 0;
}