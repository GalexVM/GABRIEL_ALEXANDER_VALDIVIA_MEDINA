#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string>
using std::string;


string ingresarCadena();
int ingresarNumero();
string dividirCadena(string cad, int key);
void imprimirBloques(string &a);
void acomodarVector(string v[], string cad, int key);
void imprimirVector(string v[], int n);

int main(){
	string cadenaOriginal = ingresarCadena();//a)
	int tamBloque = ingresarNumero();//b)
	string cadenaDividida; 
	cadenaDividida = dividirCadena(cadenaOriginal,tamBloque);//d) e)
	imprimirBloques(cadenaDividida);//c)
	cout<<endl<<cadenaDividida<<endl;//e)
	const int v = (cadenaDividida.size()/tamBloque);
	string vector[v];
	acomodarVector(vector,cadenaDividida,tamBloque);//f)
	imprimirVector(vector,v);//f)
	
}
void imprimirVector(string v[], int n){
	cout<<endl;

	for(int j=0;j<n;j++){
		cout<<"|"<<v[j];
	}
	cout<<endl;
}
void acomodarVector(string v[], string cad, int key){
	string::iterator iterador1 =cad.begin();
	int bloque=0,counter=0;
		while(iterador1 != cad.end()){
			
			if(*iterador1 == '*'){
				iterador1++;
				
			}else{
				v[bloque].push_back(*iterador1);
				iterador1++;
				counter++;
				if(counter == key){
					bloque++;
					counter =0;
				}
			}
			
		}
}
void imprimirBloques(string &a){
	string::iterator iterador1 =a.begin();
	while(iterador1 != a.end()){
		if(*iterador1 != '*'){
		cout<<*iterador1;
		}else{
			cout<<endl;
		}
		iterador1++;
	}
}
string dividirCadena(string cad, int key){
	while(cad.size()%key!=0){
		cad.push_back('X');
	}
	string::iterator iterador1 = cad.begin();
	int counter=0;
	string temp;
	while(iterador1 != cad.end()){
		temp.push_back(*iterador1);
		iterador1++;
		counter++;
		if(counter%key == 0 &&counter != 0){
			temp.push_back('*');
		}
		
	}
	return temp;
}
string ingresarCadena(){//a)
	cout<<"Ingrese una cadena de caracteres: ";
	string cadena;
	getline(cin,cadena);
	cout<<endl;
	return cadena;
}
int ingresarNumero(){//b)
	cout<<"Ingrese un número para los bloques al dividir: ";
	int n;
	cin>>n;
	cout<<endl;
	return n;
}
