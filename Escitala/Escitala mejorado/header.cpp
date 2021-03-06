#include "header.h"
#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::cin;

string AlgoritmoCifrado_1::cifrar(string& msg) {
							string msg2;
							bool error = false;
							//A?adir espacios extra o recortar.
							while (msg.length() != (claveC * claveF)) {
								if (msg.length() < (claveC * claveF)) {
									msg.push_back(' ');
								}
								else if (msg.length() > (claveC * claveF)) {
									msg.erase(msg.begin() + (msg.length() - 1));
									error = true;
								}
							}
							//Advertir de error de claves.
							if (error == true) { cout << "...ADVERTENCIA: Error de claves...\n"; }
							//Cifrar mensaje.
							for (int x = 0; x < claveC; x++) {
								for (int i = 0; i < msg.length();) {
									if (msg[i] != '*') {
										msg2.push_back(msg[i]);
										msg[i] = '*';
										i += claveC;
									}
									else {
										i++;
									}
								}
							}
							return msg2;
						}
string AlgoritmoCifrado_1::descifrar(string& msg) {
							string msg2;
							//Descifrar mensaje.
							for (int x = 0; x < claveF; x++) {
								for (int i = 0; i < msg.length();) {
									if (msg[i] != '*') {
										msg2.push_back(msg[i]);
										msg[i] = '*';
										i += claveF;
									}
									else {
										i++;
									}
								}
							}
							return msg2;
						}
void IntroducirMensaje(string& msg) {
	cout << "Ingrese el mensaje: ";
	getline(cin, msg);
}
