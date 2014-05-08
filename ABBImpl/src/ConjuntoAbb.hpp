#ifndef CONJUNTO_HPP_
#define CONJUNTO_HPP_
#define MODORECORRIDO int
#define INORDER 1
#define BFS 2

#include <iostream>
#include <queue>
#include <cmath>
#include <sstream>
using namespace std;

template<class T>
class Conjunto {
private:
	// la representaci�n de un nodo interno.
	struct Nodo {
		// el constructor, toma el elemento al que representa el nodo.
		Nodo(const T& v);
		// el elemento al que representa el nodo.
		T valor;
		// puntero a la ra�z del sub�rbol izquierdo.
		Nodo* izq;
		// puntero a la ra�z del sub�rbol derecho.
		Nodo* der;
	};

	// puntero a la ra�z de nuestro �rbol.
	Nodo* raiz;
	//punteros a maximo y minimo
	Nodo* minimo_ptr;
	Nodo* maximo_ptr;
	//cardinal
	unsigned int _cardinal;

	/** funciones auxiliares */

	// Actualiza los punteros de maximo y minimo segun corresponda
	// Recibe la direccion de memoria del elemento a comparar
	// Con los minimo y maximo actual
	// O(1)
	void actualizarMaximoYMinimoEnInsercionConstante(
			Nodo* punteroNuevoElemento);

	//Busca el maximo y minimo recorriendo el arbol
	//O(n)
	std::pair<T, T> actualizarMaximoYMinimoLineal();

	// Devuelve un puntero, al puntero que deber�a apuntar al nodo
	// del elemento que estoy buscando. Si el elemento pertenece
	// al conjunto, el puntero apunta a un nodo v�lido, si no, a NULL.
	Nodo** buscar(const T& clave);

	// Lo mismo de arriba, pero devuelve un puntero const al puntero
	// del nodo que representa al elemento buscado.
	// Esto quiere decir que si queremos modificar el puntero
	// al que apunta el elemento, a trav�s del resultado
	// de �sta funcion no podemos.
	Nodo* const * buscar(const T& clave) const;

	//funcion recursiva para recorrer en profundidad e ir borrando los nodos
	void depthFirstSearchAndDelete(Nodo* entryPoint);

	//funcion recursiva para mostrar el arbol
	void recorrido_inorder(Nodo* nodoDeEntrada, std::ostream& oo, int nivel) const;
	void recorrido_ancho(Nodo* entrada, std::ostream& oo) const;
	Nodo** dameMinimo(Nodo** entryPointPointer);
	Nodo** dameMaximo(Nodo** entryPointPointer);
	bool removerCasoHoja(Nodo** doblePtr);
	bool removerCasoUnicoHijo(Nodo** doblePtr);
	bool removerCasoDosHijos(Nodo** doblePtr);
	bool removerConPuntero(Nodo** doblePtr);

public:
	class IteradorConjunto{
	private:
		IteradorConjunto(MODORECORRIDO modo){
			prim=NULL;
		}
		struct Elemento{
			Conjunto::Nodo ** doblePtrNodo;
			Elemento* next;
		};
		Elemento* prim;
	};

	IteradorConjunto* getIterador();

	// Constructor. Genera un conjunto vac�o.
	Conjunto();

	// Destructor. Debe dejar limpia la memoria.
	~Conjunto();

	// Inserta un elemento en el conjunto. Si �ste ya existe,
	// el conjunto no se modifica.
	void insertar(const T&);

	// Decide si un elemento pertenece al conjunto o no.
	bool pertenece(const T&) const;

	// borra un elemento del conjunto. Si �ste no existe,
	// el conjunto no se modifica.
	bool remover(const T&);

	// devuelve el m�nimo elemento del conjunto seg�n <.
	const T& minimo() const;

	// devuelve el m�ximo elemento del conjunto seg�n <.
	const T& maximo() const;

	// devuelve la cantidad de elementos que tiene el conjunto.
	unsigned int cardinal() const;

	// muestra el conjunto.
	void mostrar(std::ostream&, MODORECORRIDO modo) const;
};

//impl Conjunto-----------------------------------------------

template<class T>
Conjunto<T>::Conjunto() :
		raiz(NULL), minimo_ptr(NULL), maximo_ptr(NULL), _cardinal(0) {//supongo maximo y minimo tienen constructor por defecto
}

template<class T>
Conjunto<T>::~Conjunto() {
	depthFirstSearchAndDelete(raiz);
}

template<class T>
typename Conjunto<T>::Nodo** Conjunto<T>::dameMinimo(Nodo** n) {
	while ((*n)->izq != NULL) {
		n = &((*n)->izq);
	}
	return n;
}

template<class T>
typename Conjunto<T>::Nodo** Conjunto<T>::dameMaximo(Nodo** n) {
	while ((*n)->der != NULL) {
		n = &((*n)->der);
	}
	return n;
}

template<class T>
std::pair<T, T> Conjunto<T>::actualizarMaximoYMinimoLineal() {
	minimo_ptr = *(dameMinimo(&raiz));
	maximo_ptr = *(dameMaximo(&raiz));
	return make_pair(minimo_ptr->valor, maximo_ptr->valor);
}

template<class T>
void Conjunto<T>::actualizarMaximoYMinimoEnInsercionConstante(
		Nodo* punteroNuevoElemento) {
	if ((minimo_ptr == NULL)
			|| (punteroNuevoElemento->valor < minimo_ptr->valor)) {
		minimo_ptr = punteroNuevoElemento;
	}
	if ((maximo_ptr == NULL)
			|| (punteroNuevoElemento->valor > maximo_ptr->valor)) {
		maximo_ptr = punteroNuevoElemento;
	}
}

template<class T>
bool Conjunto<T>::pertenece(const T& clave) const {
	Nodo* const * n = this->buscar(clave);
	return *n != NULL;
}

template<class T>
void Conjunto<T>::insertar(const T& clave) {
	Nodo** n = this->buscar(clave);
	if (*n == NULL) {
		*n = new Nodo(clave);
		actualizarMaximoYMinimoEnInsercionConstante(*n);
		_cardinal++;
	}
}

template<class T>
Conjunto<T>::Nodo::Nodo(const T& v) :
		valor(v), izq(NULL), der(NULL) {
}

template<class T>
typename Conjunto<T>::Nodo** Conjunto<T>::buscar(const T& clave) {
	Nodo** n = &(this->raiz);
	while (*n != NULL && (*n)->valor != clave) {
		if (clave < (*n)->valor)
			n = &((*n)->izq);
		else
			n = &((*n)->der);
	}
	return n;
}

template<class T>
const T& Conjunto<T>::minimo() const {
	return minimo_ptr->valor;
}

template<class T>
const T& Conjunto<T>::maximo() const {
	return maximo_ptr->valor;
}

template<class T>
unsigned int Conjunto<T>::cardinal() const {
	return _cardinal;
}

template<class T>
typename Conjunto<T>::IteradorConjunto* Conjunto<T>::getIterador() {
	IteradorConjunto* it = new IteradorConjunto(BFS);

	return it;
}

template<class T>
void Conjunto<T>::mostrar(std::ostream& oo, MODORECORRIDO modo) const {
	if (modo == INORDER) {
		if (raiz != NULL) {
			recorrido_inorder(raiz, oo, 1);
		}
	} else if (modo == BFS) {
		recorrido_ancho(raiz, oo);
	}
}

template<class T>
typename Conjunto<T>::Nodo* const * Conjunto<T>::buscar(const T& clave) const {
	Nodo* const * n = &(this->raiz);
	while (*n != NULL && (*n)->valor != clave) {
		if (clave < (*n)->valor)
			n = &((*n)->izq);
		else
			n = &((*n)->der);
	}
	return n;
}

template<class T>
void Conjunto<T>::recorrido_inorder(Nodo* nodoDeEntrada, std::ostream& oo,
		int nivel) const {
	if (nodoDeEntrada->izq != NULL) {
		recorrido_inorder(nodoDeEntrada->izq, oo, nivel + 1);
	}
	oo << "[Nivel: " << nivel << "]" << nodoDeEntrada->valor << "\n";
	if (nodoDeEntrada->der != NULL) {
		recorrido_inorder(nodoDeEntrada->der, oo, nivel + 1);
	}

}

template<class T>
void Conjunto<T>::depthFirstSearchAndDelete(Nodo* entryPoint) {
	if (entryPoint->izq != NULL) {
		depthFirstSearchAndDelete(entryPoint->izq);
	}
	if (entryPoint->der != NULL) {
		depthFirstSearchAndDelete(entryPoint->der);
	}
	delete entryPoint;
	entryPoint = NULL;
}

template<class T>
bool Conjunto<T>::removerCasoHoja(Nodo** doblePtr) {
	Nodo* nodoPosta = *doblePtr;
	//no tiene hijos
	//caso trivial, lo volamos con fritas porque es una hoja.
	delete nodoPosta;
	nodoPosta = NULL;
	*doblePtr = NULL;
	return true;
}

template<class T>
bool Conjunto<T>::removerCasoUnicoHijo(Nodo** doblePtr) {
	Nodo* nodoPosta = *doblePtr;
	//tiene un solo hijo
	//tengo que ver cual es el hijo que tiene efectivamente y eliminar el nodo target poniendo en su lugar al hijo(linked list style)
	Nodo* hijoUnicoDeTarget =
			(nodoPosta->izq == NULL) ? nodoPosta->der : nodoPosta->izq;
	*doblePtr = hijoUnicoDeTarget;
	delete nodoPosta;
	nodoPosta = NULL;
	return true;
}

template<class T>
bool Conjunto<T>::removerCasoDosHijos(Nodo** doblePtr) {
	Nodo* nodoPosta = *doblePtr;
	//vale que ( (NO tiene los dos nodos nulos) Y (tampoco tiene un solo hijo) ) => tiene 2 hijos, caso epico.
	//reemplazo valor del nodo target por el maximo de los minimos(subarbol izquierdo), analogamente funcionaria al reves (min subarbol de los maximos).
	//por transitividad vemos que queda re piola el invariante
	Nodo** punteroACandidatoAReemplazarTarget = dameMaximo(&nodoPosta->izq);
	swap(nodoPosta->valor, (*punteroACandidatoAReemplazarTarget)->valor);
	return removerConPuntero(punteroACandidatoAReemplazarTarget);
}

template<class T>
bool Conjunto<T>::removerConPuntero(Nodo** doblePtr) {
	bool removi = false;
	Nodo* nodoPosta = *doblePtr;
	if (nodoPosta == NULL) {
		//no existe, PIOLA.
	} else {
		//casos.
		if (nodoPosta->der == NULL && nodoPosta->izq == NULL) {	//no tiene hijos
			//caso trivial, lo volamos con fritas porque es una hoja.
			removi = removerCasoHoja(doblePtr);
		} else if (((nodoPosta->der == NULL) && (nodoPosta->izq != NULL))
				|| ((nodoPosta->der != NULL) && (nodoPosta->izq == NULL))) {//tiene un solo hijo
			//tengo que ver cual es el hijo que tiene efectivamente y eliminar el nodo target poniendo en su lugar al hijo(linked list style)
			removi = removerCasoUnicoHijo(doblePtr);
		} else {
			//vale que ( (NO tiene los dos nodos nulos) Y (tampoco tiene un solo hijo) ) => tiene 2 hijos, caso epico.
			//reemplazo valor del nodo target por el maximo de los minimos(subarbol izquierdo), analogamente funcionaria al reves (min subarbol de los maximos).
			//por transitividad vemos que queda re piola el invariante
			removi = removerCasoDosHijos(doblePtr);
		}
	}
	//actualizo cosas
	if (removi) {
		actualizarMaximoYMinimoLineal();
		_cardinal--;
	}
	return removi;
}

template<class T>
bool Conjunto<T>::remover(const T& target) {
	Nodo ** doblePtr = buscar(target);
	return removerConPuntero(doblePtr);
}

template<class T>
void Conjunto<T>::recorrido_ancho(Nodo* entrada, std::ostream& oo) const {
	queue<Nodo*> cola_nodos;
	Nodo* nodo_actual;
	if (entrada != NULL){ // si el arbol esta vacio, salimos
		cola_nodos.push(entrada);
		int contador = 0;
		while (!(cola_nodos.empty())) {
			contador++;
			nodo_actual = cola_nodos.front();
			cola_nodos.pop();
			int nivel = log2(contador);
			oo << "Nivel " << nivel << " :" << nodo_actual->valor << "\n";
			if (nodo_actual->izq != NULL){ // si existe, ponemos el hijo izquierdo en la cola
				cola_nodos.push(nodo_actual->izq);
			}
			if (nodo_actual->der != NULL){ // si existe, ponemos el hijo derecho en la cola
				cola_nodos.push(nodo_actual->der);
			}
		}
	}
}

#endif // CONJUNTO_HPP_
