#include <iostream>
using namespace std;
//-------------------------declaracion de la clase Demo---------------------
class Demo {
private:
	int _dato;//atributo privcado del tipo int
public:
	void setDato(int dato);// el prototipo del metodo publico 
	int getDato();		   // el prototipo del metodo publico getter
	void verTodo();		   // el prototipo del metodo publico otro
};
//fin de la declaracion