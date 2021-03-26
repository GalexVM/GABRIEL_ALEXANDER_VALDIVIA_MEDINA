#include <iostream>
#include <string>
using namespace std;

class AlgoritmoCifrado_1{
	private:
		int clave=21;
	public:
		string cifrar(string &msg, int c=0){
			c+=1;
			string msg2;
			//Separar las cifras de la clave.
			int nfi=(int)clave/10,rep=clave%10;
			//Hallar numero de caracteres.
			int car =0;
			for(int x=0;x<msg.length();x++){
				car++;
			}
			//Regulando division de caracteres.
			while (car%nfi!=0){
				car+=1;
			}
			for(int x=0;x<(car-msg.length());x++){
				msg.push_back(' ');
			}
			//Generando mensaje cifrado.
			for(int x=0;x<nfi;x++){
				for(int i=0;i<car;){
					if(msg[i]!='*'){
						msg2.push_back(msg[i]);
						msg[i]='*';
						i+=nfi;
					}else{
						i++;
					}
				}
			}
			//Repeticiones del algoritmo.
			if(c==rep){
				return msg2;
			}else{
				msg2= cifrar(msg2,c);
			}
			return msg2;
		}
		string descifrar(string &msg, int c=0){
			c+=1;
			string msg2;
			//Separar las cifras de la clave.
			int nfi=msg.length()/((int)clave/10),rep=clave%10;
			//Generando descifración.
			for(int x=0;x<nfi;x++){
				for(int i=0;i<msg.length();){
					if(msg[i]!='*'){
						msg2.push_back(msg[i]);
						msg[i]='*';
						i+=nfi;
					}else{
						i++;
					}
				}
			}
			//Repeticion del algoritmo.
			if(c==rep){
				return msg2;
			}else{
				msg2= descifrar(msg2,c);
			}
			return msg2;
		}
};
void IntroducirMensaje(string &msg){
	cout<<"Ingrese el mensaje: ";
	getline(cin,msg);
}
int main(){
 	AlgoritmoCifrado_1 emisor;
	AlgoritmoCifrado_1 receptor;
	string msg;
	IntroducirMensaje(msg);
	string msgCifrado=emisor.cifrar(msg);
	cout<<"...Cifrando su mensaje..."<<endl<<msgCifrado<<endl;
	string msgDescifrado=receptor.descifrar(msgCifrado);
	cout<<"...Descifrando su mensaje..."<<endl<<msgDescifrado<<endl;	
}
