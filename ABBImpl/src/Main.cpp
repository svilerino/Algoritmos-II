#include <iostream>
#include <cstdlib>
#include <ctime>

#include "ConjuntoAbb.hpp"

using namespace std;

int main(int argc, char ** argv){
	srand(time(0)) ;//ponemos semillita
	Conjunto<int> abbSet;
	int CANT_ELEMENTOS_TEST=150;
	for (int k = 0; k < CANT_ELEMENTOS_TEST; k++) {
		int COTAINFERIORRANGOELEMENTOS = 1;
		int RANGOELEMENTOS = 50;
		int value = rand() % RANGOELEMENTOS + COTAINFERIORRANGOELEMENTOS; //valores aleatorios distribuidos uniformemente entre COTAINFERIORRANGOELEMENTOS y RANGOELEMENTOS
		abbSet.insertar(value);
	}

	abbSet.mostrar(cout, BFS);

	cout << "-------------------------------------------------------------\n";


	abbSet.remover(10);

	//un hijo
	abbSet.remover(8);

	//dos hijos
	abbSet.remover(2);

	//hoja
	abbSet.remover(1);

	abbSet.mostrar(cout, BFS);
	return 0;
}
