#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "./headers/algoritmo-afin.h"


int main() {
  string msg;
  ingresarMensaje(msg);
  algoritmoAfin emisor, receptor;
  string mensajeCifrado = emisor.cifrar(msg);
  cout<<"El mensaje cifrado es: "<<mensajeCifrado<<endl;
  bool permisoDescifrado = receptor.comprobarFuncionamiento();
  if (permisoDescifrado){
    string mensajeDescifrado = receptor.descifrar(mensajeCifrado);
    cout<<"El mensaje descifrado es: "<<mensajeDescifrado<<endl;
  }else{
    cout<<"Claves no compatibles, imposible descifrar\n";
  }
  
}