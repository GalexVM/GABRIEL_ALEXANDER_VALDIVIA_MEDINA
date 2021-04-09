#include <iostream>
#include <string>
using namespace std;

class AlgCifradoRailFence{
	private:
		int clave =4;
	public:
		string cifrar(string &msg){
			string msg2;
			int tamOla = (2*clave)-2;
			//preparar cifrado(nro carácteres).
			if((msg.length()-1)%tamOla != 0){
				if((msg.length()-1)%tamOla >(tamOla/2)){
					while((msg.length()-1)%tamOla != 0){
						msg.push_back('z');
					}
				}
			}
			//copiar puntas
			for(int i=0;i<msg.length();i+=tamOla){
				msg2.push_back(msg[i]);
				msg[i]='*';
			}
			//cifrar el resto.
			for(int x=0;x<tamOla;x++){
			
				//Convertir los pegados a "*" en "/"
				for(int i=0;i<msg.length();i++){
					if(msg[i]!='*'){
						if((i-1>=0 && msg[i-1] == '*')||(i+1<(msg.length()) && msg[i+1] == '*')){
							msg2.push_back(msg[i]);
							msg[i]='/';
						}
					}
				}
				//Convertir "." a "*".
				for(int j=0;j<msg.length();j++){
					if(msg[j]=='/'){
						msg[j]='*';
					}
					
				}
			}
			return msg2;	
		}
		
		string descifrar(string &msg){
			string msg2;
			int tamOla = (2*clave)-2;
			//llenar de '|' a msg2.
			for(int i=0;i<msg.length();i++){
				msg2.push_back('|');
			}
			//Saltos de ola.
			for(int i=0;i<msg2.length();){
				msg2[i]='/';
				i+=tamOla;
			}
			//Descifrado.
			for(int k=0;k<clave;k++){	
				//Copiar puntas.
				for(int i=0;i<msg.length();i++){
					while(msg[i]=='*') i++;// saltar caracteres ya copiados.
					for(int j=0;j<msg2.length();j++){
						if(msg2[j]=='/'){
							msg2[j]=msg[i];
							msg[i]='*';
							if(msg2[j-1]=='|')msg2[j-1]='*';
							if(msg2[j+1]=='|')msg2[j+1]='*';
							j+=msg2.length();//Termina la iteración para que i avance.)
						}
					}
				}
				//Convertir '*' a '/'.
				for(int i=0;i<msg2.length();i++){
					if (msg2[i]=='*') msg2[i]='/';
				}
			}
			return msg2;
		}
};

void ingresarMensaje(string &msg){
	cout<<"Ingrese su mensaje: ";
	getline(cin,msg);
	cout<<endl;
}
int main(){
	string msg;
	AlgCifradoRailFence emisor, receptor;
	ingresarMensaje(msg);
	string msgCifrado=emisor.cifrar(msg);
	cout<<"...Cifrando su mensaje..."<<endl<<msgCifrado<<endl;
	string msgDescifrado=receptor.descifrar(msgCifrado);
	cout<<"...Descifrando su mensaje..."<<endl<<msgDescifrado<<endl;
	
	
	return 0;
}
