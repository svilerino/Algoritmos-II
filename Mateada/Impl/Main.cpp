#include <iostream>
#include "../Header/Mateada.h"

void test1();
void test2();

int main(int argc, char **argv) {
//	test1();
	test2();
	return 0;
}

void test1() {
	cout << "test con Mateada<string>" << endl << endl;
	Mateada<string> mateada;

	cout << "test hay babeador (NO) " << (mateada.hayBabeador()) << endl;
	cout << "test nohaymateros (SI) " << (mateada.noHayMateros()) << endl;

	mateada.quieroMatear("matero1");
	mateada.quieroMatear("matero2");
	mateada.quieroMatear("matero3");
	mateada.quieroMatear("matero4");
	mateada.quieroMatear("matero5");
	cout << mateada << endl;
	cout << "fin agregado inicial!" << endl << endl << endl;

	cout << "test tamanio es 5 (SI) " << (mateada.tamanio() == 5) << endl;

	cout << "test nohaymateros (NO) " << (mateada.noHayMateros()) << endl;

	//actual apunta a (matero 5);
	cout << "test hay babeador (NO) " << (mateada.hayBabeador()) << endl;
	mateada.babearMate();
	//ahora matero51 es babeador
	mateada.pasarMate();
	//actual apunta a (matero 1);
	mateada.babearMate();
	//ahora matero 1 es babeador
	cout << "test hay babeador (1 y 5 son) (SI) " << (mateada.hayBabeador()) << endl;
	cout << mateada << endl << endl;

	mateada.gracias("matero1");
	mateada.gracias("matero3");
	mateada.gracias("materoInexistente");
	mateada.gracias("matero5");
	cout << "borre materos 1,3,5 e inexistente(este ultimo no lo encuentra)" << endl;
	cout << mateada << endl << endl;

	mateada.quieroMatear("matero5Nuevo");
	cout << "agrego matero5Nuevo" << endl;
	cout << mateada << endl << endl;

	Mateada<string> mateada2(mateada);
	mateada2.quieroMatear("materoNuevo");

	Mateada<string> mateada3(mateada);

	cout << "Mateada 1: " << mateada << endl << endl;
	cout << "Mateada 2: " << mateada2 << endl << endl;
	cout << "Mateada 3: " << mateada3 << endl << endl;

	cout << "test mateadas iguales 1 vs 1(SI) " << (mateada == mateada) << endl;
	cout << "test mateadas iguales 1 vs 2(NO) " << (mateada == mateada2) << endl;
	cout << "test mateadas iguales 1 vs 3(SI) " << (mateada == mateada3) << endl;

	cout << endl << endl << endl << endl;
}

void test2() {
	cout << "test con Mateada<Mateada<int> >" << endl << endl;
	Mateada<int> mateada;

	mateada.quieroMatear(1);
	mateada.quieroMatear(2);
	mateada.quieroMatear(3);
	mateada.quieroMatear(4);
	mateada.quieroMatear(5);

	mateada.pasarMate();
	mateada.pasarMate();

	mateada.babearMate();

	mateada.retrocederMate();

	mateada.babearMate();

	Mateada<int> mateada2(mateada);
	Mateada<int> mateada3(mateada);
	Mateada<int> mateada4(mateada);

	mateada2.quieroMatear(51);
	mateada4.quieroMatear(38);
	mateada4.babearMate();

	//mateada de mateadas
	Mateada<Mateada<int> > mateadaDeMateadas;
	mateadaDeMateadas.quieroMatear(mateada);
	mateadaDeMateadas.quieroMatear(mateada2);
	mateadaDeMateadas.quieroMatear(mateada3);

	mateadaDeMateadas.babearMate();

	Mateada<Mateada<int> > mateadaDeMateadas2(mateadaDeMateadas);

	cout << "Igualdad de varias mateadas : (SI) " << (mateadaDeMateadas==mateadaDeMateadas2) << endl << endl << endl;

	mateadaDeMateadas2.quieroMatear(mateada4);

	cout << "Igualdad de varias mateadas : (NO) " << (mateadaDeMateadas==mateadaDeMateadas2) << endl << endl << endl;

	cout << "Mateada De Mateadas" << mateadaDeMateadas << endl;

	cout << endl << endl << endl << endl;
}
