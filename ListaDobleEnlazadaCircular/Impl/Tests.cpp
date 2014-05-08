/*
 * Tests.cpp
 *
 *  Created on: 19/04/2013
 *      Author: i5
 */

#include<iostream>
#include "../Header/Lista.h"

using namespace std;


int main(int argc, char** argv){
	Lista<string> lista;
	//test de agregar, modificar, eliminar, etc sobre lista 1
	lista.agregarNodo("dato1");
	lista.agregarNodo("dato2");
	lista.agregarNodo("dato3");
	lista.agregarNodo("dato4");
	lista.agregarNodo("dato5");
	lista.agregarNodo("dato6");
	lista.agregarNodo("dato7");
	lista.agregarNodo("dato8");
	lista.agregarNodo("dato9");
	lista.agregarNodo("dato10");

	cout << lista;
	cout << endl;
	cout << endl;
	cout << endl;

	lista.modificarNodo("dato1", "dato1modificado");
	lista.modificarNodo("dato3", "dato3modificado");
	lista.modificarNodo("dato5", "dato5modificado");
	lista.modificarNodo("dato7", "dato7modificado");

	cout << lista;
	cout << endl;
	cout << endl;
	cout << endl;

	lista.eliminarNodo("dato2");
	lista.eliminarNodo("dato4");
	lista.eliminarNodo("dato6");
	lista.eliminarNodo("dato8");

	cout << lista;
	cout << endl;
	cout << endl;
	cout << endl;

	lista.agregarNodo("dato2reagregado");
	lista.agregarNodo("dato4reagregado");
	lista.agregarNodo("dato6reagregado");
	lista.agregarNodo("dato8reagregado");

	cout << "Fin tests.................................................................." << endl;

	cout << "Lista1:" << endl;
	cout << lista;
	cout << endl;

	//test constructor por copia

	Lista<string> lista2(lista);

	cout << "Lista2:" << endl;
	cout << lista2;
	cout << endl;
	cout << endl;
	cout << endl;

	return 0;
}


