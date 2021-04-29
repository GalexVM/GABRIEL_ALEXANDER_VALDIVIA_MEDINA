#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "../headers/algoritmo-afin.h"
#include "../headers/math-functions.h"

//abcdefghijklmnopqrstuvwxyz
string algoritmoAfin:: cifrar(string &msg){
  string msg2 =  msg;
  int key = 0;
  //Usar clave a (multiplicacion)
  for (int i = 0; i < msg.size(); i++) {
		for (int j = 0; j < alfabeto.size(); j++) {
			if (msg[i] == alfabeto[j]) {
				key = j * claveA;
        key = key + claveB; //Usar clave b (adicion)
				if (key > alfabeto.size()-1) {
					key =moduloPositivo(key,alfabeto.size());
				}
				msg2[i] = alfabeto[key];
        j = j + alfabeto.size();
			}
		}
	}
  return msg2;
}
string algoritmoAfin:: descifrar(string &msg){
  string msg2 =  msg;
  //Hallar la inversa de claveA
  int inversaA;
  inversaA = *(euclidesExtendido(claveA,alfabeto.length())+1);
  if (inversaA < 0) inversaA = moduloPositivo(inversaA, alfabeto.length());

  //Descifrar con la nueva clave.
  int key =0;
    for (int i = 0; i < msg.size(); i++) {
		  for (int j = 0; j < alfabeto.size(); j++) {
        if (msg2[i] == alfabeto[j]){
          key = j - claveB;//Restar claveB
          //Respetar la operación binaria
          if(key < 0)key = moduloPositivo(key, alfabeto.length());
          key = key * inversaA;//Multiplicar inversaA.
          //Módulo final
          if(key > alfabeto.length()-1)key = moduloPositivo(key, alfabeto.length()); 
          msg2[i] = alfabeto[key];
          j = + alfabeto.size();
        }
      }
    }
  return msg2;
}

bool algoritmoAfin::comprobarFuncionamiento(){
  if ( euclides(claveA, alfabeto.size()) != 1 ){
    return false;
  }else{
    return true;
  }
}

void ingresarMensaje(string &msg){
  cout<<"Introduce el mensaje a cifrar : ";
  getline(cin,msg);
  cout<<endl;
}

