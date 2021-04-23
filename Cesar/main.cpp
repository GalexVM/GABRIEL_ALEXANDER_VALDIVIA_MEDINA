#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string>
using std::string;
#include "header.h"

int main() {
	string msg;
	introducirMensaje(msg);
	algoritmoCesar emisor, receptor;
	string mensajeCifrado = emisor.cifrar(msg);
	cout <<"Mensaje cifrado : "<<'|'<< mensajeCifrado <<'|'<< endl;
	string mensajeDescifrado = receptor.descifrar(mensajeCifrado);
	cout <<"Mensaje descifrado :"<<'|'<< mensajeDescifrado <<'|'<< endl;
	cout << "Descifrando mensaje rompiendo algoritmo: \n";
	receptor.romper(mensajeCifrado);
}