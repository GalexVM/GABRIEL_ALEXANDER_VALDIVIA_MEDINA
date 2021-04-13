#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
using std::cout;
using std::string;


class AlgoritmoCifrado_1 {
private:
	int claveC=5;
	int claveF=5;
public:
	string cifrar(string& msg);
	string descifrar(string& msg);
};
void IntroducirMensaje(string& msg);
#endif //HEADER_H
