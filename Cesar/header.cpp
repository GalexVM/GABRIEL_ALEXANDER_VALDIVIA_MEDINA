#include "header.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string>
using std::string;


void introducirMensaje(string& msg)
{
	cout << "Introduzca el mensaje a cifrar: \n";
	getline(cin, msg);
}

int moduloPositivo(int dividendo, int divisor)
{
	int cociente = dividendo / divisor; //Definir cociente
	int residuo = dividendo - (cociente * divisor);//Definir residuo
	if (residuo < 0 && divisor>0) {//Si el residuo es negativo y el divisor positivo
		residuo = divisor + residuo;
		cociente -= 1;
	}
	else if (residuo < 0 && divisor < 0) {//Si el residuo es negativo y el divisor negativo
		residuo = (-divisor) + residuo;
		cociente += 1;
	}
	return residuo;
}



string algoritmoCesar::cifrar(string& msg){
	string msg2 = msg;
	int key = 0;
	for (int i = 0; i < msg.size(); i++) {
		for (int j = 0; j < alfabeto.size(); j++) {
			if (msg[i] == alfabeto[j]) {
				key = j + clave;
				if (key > alfabeto.size()-1) {
					key =moduloPositivo(key,alfabeto.size());
				}
				msg2[i] = alfabeto[key];
			}
		}
	}
	return msg2;
}

string algoritmoCesar::descifrar(string& msg){
	string msg2 = msg;
	int key = 0;
	for (int i = 0; i < msg.size(); i++) {
		for (int j = 0; j < alfabeto.size(); j++) {
			if (msg[i] == alfabeto[j]) {
				key = j - clave;
				if (key < 0) {
					if ((-key) < alfabeto.size()) { // Si el valor abs de key es mayor que el largo, no se puede dividir como se hace abajo:
						key = moduloPositivo(alfabeto.size(), key);
					}
					else {//En este casi tendremos que sacar el modulo de la inversa de key con el largo del alfabeto.
						key = moduloPositivo((-key), alfabeto.size());
						key = alfabeto.size() - key;//Para obtener el equivalente, se resta el resultado al largo.
					}
				}
				msg2[i] = alfabeto[key];
			}
		}
	}
	
	return msg2;
}

void algoritmoCesar::romper(string& msg){
	
	int repeticiones = alfabeto.length();//Cuántas claves diferentes se probarán.
	int claveFalsa = 1;
	int key;
	string msg2;
	string respuestas[128]; //En ASCII hay 128 caracteres diferentes.
	//Asignar valores al array.
	for (int i = 0; i < 128; i++) {
		respuestas[i] = "*_*_*";
	}
	//Bucle de intentos.
	while (claveFalsa <= repeticiones) {
		msg2 = msg;
		//Descifrado con claves falsas.
		for (int i = 0; i < msg.size(); i++) {//Iterar el mensaje.
			for (int j = 0; j < alfabeto.size(); j++) {//Iterar el alfabeto.
				if (msg[i] == alfabeto[j]) {
					key = j - claveFalsa;
					if (key < 0) {
						if ((-key) < alfabeto.size()) { // Si el valor abs de key es mayor que el largo, no se puede dividir como se hace abajo:
							key = moduloPositivo(alfabeto.size(), key);
						}
						else {//En este casi tendremos que sacar el modulo de la inversa de key con el largo del alfabeto.
							key = moduloPositivo((-key), alfabeto.size());
							key = alfabeto.size() - key;//Para obtener el equivalente, se resta el resultado al largo.
						}
					}
					msg2[i] = alfabeto[key];
				}
			}
		}
		respuestas[claveFalsa-1] = msg2;//Se utiliza la variable clavefalsa para controlar los indices del array.
		cout << "------";
		cout << respuestas[claveFalsa - 1] <<" clave: "<<claveFalsa<< endl;
		claveFalsa++;
	}

}
