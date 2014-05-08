#include <iostream>
#include "ABB.h"

using namespace std;

ABB<int> * abb(){
    ABB<int> * a = new ABB<int>();
    a->insertar(24);
    a->insertar(10);
    a->insertar(4);
    a->insertar(1);
    a->insertar(8);
    a->insertar(50);
    a->insertar(39);
    a->insertar(64);
    a->insertar(25);
    a->insertar(45);
    a->insertar(29);
    a->insertar(27);
    a->insertar(36);
    a->insertar(34);
    a->insertar(30);
    a->insertar(35);

    return a;
}

int main(){
    ABB<int> * a = abb();

    ///imprime
    cout << "Arbol: " << endl << *a << endl;

    ///devuelve la altura
    cout << "Altura: " << a->altura() << endl;

    ///recorre en pre order con el iterador
    ABB<int>::IteradorPreOrder it = a->crearItPreOrder();

    cout << "Pre-Order: [";
    while(it.hayMas()){
        cout << it.actual() << " ";
        it.avanzar();
    }
    cout << "]" << endl;

    ///borra
    int v = 24;
    a->borrar(v);

    cout << "Borrando el " << v << ":" << endl << *a << endl;

    ///busca
    v = 25;
    cout << "Esta el " << v << ": " << boolalpha << a->esta(v) << endl;

    v = 99;
    cout << "Esta el " << v << ": " << a->esta(v) << endl;

    ///copia
    ABB<int> * b = new ABB<int>(*a);

    cout << "Copia: " << endl << *b << endl;

    delete a;
    delete b;

    return 0;
}
