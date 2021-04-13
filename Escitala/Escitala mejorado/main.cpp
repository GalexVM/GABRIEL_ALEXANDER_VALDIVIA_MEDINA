#include <iostream>
#include <string>
#include "header.h"
using std::cout;
using std::endl;

int main() {
	AlgoritmoCifrado_1 emisor;
	AlgoritmoCifrado_1 receptor;
	string msg;
	IntroducirMensaje(msg);
	string msgCifrado = emisor.cifrar(msg);
	cout << "...Cifrando su mensaje..." << endl << msgCifrado << endl;
	string msgDescifrado = receptor.descifrar(msgCifrado);
	cout << "...Descifrando su mensaje..." << endl << msgDescifrado << endl;
}
