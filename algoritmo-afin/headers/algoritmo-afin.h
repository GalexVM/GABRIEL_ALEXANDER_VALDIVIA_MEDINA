#include <string>
using std:: string;

class algoritmoAfin{
  private:
    int claveA = 37;
    int claveB = 100;
  public:
  string alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890-.";
  bool comprobarFuncionamiento();
  string cifrar(string &msg);
  string descifrar(string &msg);
};

void ingresarMensaje(string &msg);
