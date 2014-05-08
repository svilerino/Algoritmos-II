/*
 * Main.cpp
 *
 *  Created on: 17/04/2013
 *      Author: Sil
 */
/*
#include<iostream>
#include "../Header/Lista.h"

using namespace std;

void agregarNodo();
void eliminarNodo();
void modificarNodo();
string obtenerDato();

Lista<string> list;

int main(int argc, char** argv){
	int opcion=-1;
	while(opcion!=0){
		cout << "Elija opcion" << endl;
		cout << "1.- Agregar Nodo" << endl;
		cout << "2.- Eliminar Nodo" << endl;
		cout << "3.- Modificar Nodo" << endl;
		cout << "4.- Mostrar Lista" << endl;
		cout << "0.- Salir" << endl;
		cin >> opcion;

		switch(opcion){
			case 0:
				break;
			case 1:
				agregarNodo();
				break;
			case 2:
				eliminarNodo();
				break;
			case 3:
				modificarNodo();
				break;
			case 4:
				cout << list;
				break;
			default:
				cerr << "Opc. Invalida" << endl;
				break;
		}
	}
	return 0;
}

void agregarNodo(){
	string dato = obtenerDato();
	list.agregarNodo(dato);
}

string obtenerDato() {
	string dato;
	cout << "Ingrese Dato :";
	cin >> dato;
	return dato;
}

void eliminarNodo(){
	string dato = obtenerDato();
	list.eliminarNodo(dato);
}

void modificarNodo(){

}
*/
