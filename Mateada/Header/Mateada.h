#ifndef MATEADA_H_ 
#define MATEADA_H_

#include <iostream>
#include <cassert>
using namespace std;

//se puede asumir que el tipo T tiene constructor por copia
//y operator==
//no se puede asumir que el tipo T tenga operator=
template<typename T>
class Mateada {
public:

	/*
	 * constructor por defecto, crea una mateada 
	 */
	Mateada();

	/*
	 * constructor por copia, una vez copiado, ambas mateadas deben ser
	 * independientes, es decir, cuando se borre una no debe morir la otra.
	 */
	Mateada(const Mateada<T>&);

	/*
	 * Destructor. Acordarse de liberar toda la memoria!
	 */
	~Mateada();

	/*
	 * Devuelve true si las mateadas son iguales
	 */
	bool operator==(const Mateada<T>&) const;

	/*
	 * Dice si la mateada es vac�a
	 */
	bool noHayMateros() const;

	/*
	 * Dice el tamanio de la mateada
	 */
	int tamanio() const;

	/*
	 * Devuelve el elemento actual mateando
	 * PRE: no es vac�a la mateada.
	 */
	const T& actual() const;

	/*
	 * Devuelve el pr�ximo elemento seg�n el orden de la mateada.
	 * El mate va pasando de posici�n. Con lo cual sucesivas llamadas a esta funci�n
	 * retornan distintos valores.
	 *
	 * El valor retornado pasa a ser el anterior.
	 *
	 * PRE: no es vac�a la mateada.
	 */
	const T& pasarMate();

	/*
	 * Agrega el elemento a la mateada. Recordar que el �ltimo agregado es el
	 * actual
	 */
	void quieroMatear(const T&);

	/*
	 * Elimina una ocurrencia del elemento en la mateada.
	 */
	void gracias(const T&);

	/*
	 * Marca que la persona actual babea el mate.
	 *
	 * PRE: no es vac�a la mateada.
	 */
	void babearMate();

	/*
	 * Indica si alguna persona del anillo babea el mate.
	 */
	bool hayBabeador() const;

	/*
	 * Indica cu�l es la persona siguiente que babea el mate.
	 *
	 * PRE: hayBabeador
	 */
	const T& babeador() const;

	/*
	 * Vuelve hacia atr�s el mate
	 * El anterior, en caso de existir, no debe alterarse.
	 */
	void retrocederMate();

	/*
	 * Devuelve el pr�ximo elemento seg�n el orden de la mateada, salteando a la persona/s que babean. 
	 * El mate va pasando de posici�n. Con lo cual sucesivas llamadas a esta funci�n
	 * retornan distintos valores.
	 *
	 * El valor retornado pasa a ser el anterior.
	 *
	 * PRE: Hay al menos una persona que no babea el mate.
	 */
	const T& pasarMateSaltearBabeadores();

	/*
	 * debe mostrar la mateada en el stream (y retornar la misma).
	 * Mateada vacia: []
	 * Mateada con 2 elementos (e1 es el actual): [e1, e2]
	 * Mateada con 2 elementos (e2 es el actual y e1 es babeador): [e2, e1*]
	 * Mateada con 3 elementos (e3 es el actual, e2 fue agregado antes que e3, e1 fue agregado antes que e2): [e3, e2, e1]
	 *
	 */
	ostream& mostrarMateada(ostream&) const;

private:
	//No se puede modificar esta funcion.
	Mateada<T>& operator=(const Mateada<T>& otro) {
		assert(false);
		return *this;
	}

	struct Nodo {
		Nodo(T dato) :
				_data(dato) {
			_sig = NULL;
			_prev = NULL;
			_baboso = false;
		}
		T _data;
		bool _baboso;
		Nodo* _sig;
		Nodo* _prev;
	};

	Nodo* _comienzo;
	Nodo* _actual;
	int _longuitud;

	Nodo* buscarElemento(const T& dato) const {
		//marco el comienzo como indice de inicio.
		Nodo* indexPtr = _comienzo;
		int i = _longuitud;
		//recorro la lista i(longuitud) veces, si no encuentra el dato entra en ciclo al ser circular => salgo del while.
		//si encuentra antes el dato target tambien sale del while.
		while ((i > 0) && (indexPtr->_data != dato)) {
			indexPtr = indexPtr->_sig;
			i--;
		}
		//si i llego a 0 es porque se cumplio todo el ciclo de la lista circular.
		if (i == 0) {
			return NULL;
		} else {
			//en otro caso, devuelvo el puntero que en el ultimo ciclo del while dejo apuntado lo que buscabamos.
			return indexPtr;
		}
	}
	void eliminarLista();
};

template<class T>
ostream& operator<<(ostream& out, const Mateada<T>& a) {
	return a.mostrarMateada(out);
}

template<typename T>
Mateada<T>::Mateada() {
	_comienzo = NULL;
	_actual = NULL;
	_longuitud = 0;
}

template<class T>
void Mateada<T>::eliminarLista() {
	Nodo* indexPtr = _comienzo;
	//tengo que eliminar this->longuitud nodos.
	//Entonces voy borrando y decremento en longuitud hasta quedarme sin ninguno.
	while (_longuitud > 0) {
		//me guardo el nodo a eliminar
		Nodo* targetToDelete = indexPtr;
		//avanzo el puntero
		indexPtr = indexPtr->_sig;
		//elimino el nodo del que guarde la direccion.
		//cout << "libero " << targetToDelete << " : " << targetToDelete->_data << " | quedan " << (_longuitud-1) << " materos" << "\n";
		delete targetToDelete;
		//actualizo la longuitud de la lista.
		_longuitud--;
	}
	//cout << endl << endl << endl << endl;
}

template<typename T>
Mateada<T>::~Mateada() {
	//cout << "destructor de " << this << " " << _longuitud << " Nodos en la lista"<< "\n";
	eliminarLista();
}

template<typename T>
bool Mateada<T>::noHayMateros() const {
	return (_longuitud == 0);
}

template<typename T>
int Mateada<T>::tamanio() const {
	return _longuitud;
}

template<typename T>
const T& Mateada<T>::actual() const {
	return _actual->_data;
}

template<typename T>
const T& Mateada<T>::pasarMate() {
	T& datoADevolver = _actual->_data;
	_actual = _actual->_sig;
	return datoADevolver;
}

template<typename T>
void Mateada<T>::quieroMatear(const T& dato) {
	if (_comienzo == NULL) {
		//es un solo nodo, apunta a si mismo prev y sig, (circular)
		_comienzo = new Nodo(dato);
		_comienzo->_prev = _comienzo;
		_comienzo->_sig = _comienzo;
		//inicializo en no babeador
		_comienzo->_baboso = false;
		_actual = _comienzo;
	} else {
		//agrego al final
		//obtengo la posicion en la cual voy a agregar el nodo
		//la ultima, que al ser circular es la anterior a la primera
		Nodo* nuevoNodo = new Nodo(dato);
		//inicializo en no babeador
		nuevoNodo->_baboso = false;
		_actual->_sig->_prev = nuevoNodo;
		nuevoNodo->_sig = _actual->_sig;
		_actual->_sig = nuevoNodo;
		nuevoNodo->_prev = _actual;
		_actual=nuevoNodo;
	}
	//agregue un nodo, aumento la longuitud.
	_longuitud++;
}

template<typename T>
void Mateada<T>::gracias(const T& dato) {
	//busca el target a eliminar
	Nodo* targetPtr = buscarElemento(dato);	//devuelve primera aparicion en la lista desde comienzo
	//si devuelve NULL, no existia el dato
	if (targetPtr == NULL) {
		cout << "no encontro el elemento: " << dato << " para eliminar" << "\n";
	} else {
		if (_longuitud == 1) {
			delete _comienzo;
			//borro el unico nodo
			//limpio las referencias colgantes
			_comienzo = NULL;
			_actual = NULL;
			_longuitud--;			//se decrementa la longuitud
		} else {
			//se modifican las referencias de los nodos anteriores y siguientes al target, "salteando" el nodo a eliminar
			targetPtr->_sig->_prev = targetPtr->_prev;
			targetPtr->_prev->_sig = targetPtr->_sig;

			//La politica que tomo es mover hacia adelante los punteros (al tener long mayor que 1 tengo otro nodo) que apuntan a algo invalido

			//si era el primer elemento ahora tengo que modificar _comienzo !!!
			_comienzo = (_comienzo == targetPtr) ? _comienzo->_sig : _comienzo;

			//revisar actual tambien!
			_actual = (_actual == targetPtr) ? _actual->_sig : _actual;

			//se elimina el target
			delete targetPtr;
			//limpio las referencias colgantes
			targetPtr = NULL;
			_longuitud--;			//se decrementa la longuitud
		}
	}
}

template<typename T>
void Mateada<T>::babearMate() {
	//setea el valor de baboso a true en el nodo actual.
	_actual->_baboso = true;
}

template<typename T>
bool Mateada<T>::hayBabeador() const {
	//marco el comienzo como indice de inicio.
	Nodo* indexPtr = _comienzo;
	int i = _longuitud;
	//recorro la lista i(longuitud) veces, si no encuentra el baboso entra en ciclo al ser circular => salgo del while.
	//si encuentra antes el baboso target tambien sale del while.
	while ((i > 0) && (!indexPtr->_baboso)) {
		indexPtr = indexPtr->_sig;
		i--;
	}
	//si i llego a 0 es porque se cumplio todo el ciclo de la lista circular.
	//caso contrario se ha encontrado un babeador antes de terminar el ciclo por la segunda condicion del while
	return (i != 0);
}

template<typename T>
void Mateada<T>::retrocederMate() {
	//muevo el puntero "para atras"
	if(_actual!=NULL){
		_actual = _actual->_prev;
	}
}

template<typename T>
const T& Mateada<T>::pasarMateSaltearBabeadores() {
	//avanza hasta encontrar un baboso, la precondicion y la lista circular me aseguran que esto no entra en loop infinito.
	while (_actual->_baboso) {
		_actual = _actual->_sig;
	}
	return _actual->_data;
}

template<typename T>
ostream& Mateada<T>::mostrarMateada(ostream& o) const {
	//recorre la lista desde el puntero al comienzo, longuitud posiciones hacia "adelante" imprimiendo los nodos y sus punteros.
	Nodo* indexPtr = _comienzo;
	int i = _longuitud;
	o << "[";
	while (i > 0) {
		o << indexPtr->_data << ((indexPtr->_baboso) ? "*" : "")
				<< ((i > 1) ? "," : "");
		indexPtr = indexPtr->_sig;
		i--;
	}
	o << "]";
//	int i = _longuitud;
//	while (i > 0) {
//		o << "[Anterior: " << indexPtr->_prev << "] ";
//		o << "[Actual: " << indexPtr << "] ";
//		o << "[Dato: " << indexPtr->_data << ((indexPtr->_baboso) ? "*" : "") << "] ";
//		o << "[Siguiente: " << indexPtr->_sig << "] ";
//
//		indexPtr = indexPtr->_sig;
//		i--;
//		o << endl;
//	}
//	o << endl << endl;
	return o;
}

template<typename T>
const T& Mateada<T>::babeador() const {
	Nodo * _aux = _actual;
	while (!_aux->_baboso) {
		_aux = _aux->_sig;
	}
	return _aux->_data;
}

template<typename T>
bool Mateada<T>::operator ==(const Mateada<T>& constMateada) const {
	if (this == &constMateada) {
		return true;
	} else if (tamanio() != constMateada.tamanio()) {
		return false;
	} else {
		bool nodosIguales = true;
		Nodo* comienzoListaImplicita = _comienzo;
		Nodo* comienzoOtraLista = constMateada._comienzo;
		for (int i = 0; i < tamanio(); i++) {
			nodosIguales &= ((comienzoListaImplicita->_data
					== comienzoOtraLista->_data)
					&& (comienzoListaImplicita->_baboso
							== comienzoOtraLista->_baboso));
			//avanzo los punteros(tienen la misma longuitud asi que no hay drama)
			comienzoListaImplicita = comienzoListaImplicita->_sig;
			comienzoOtraLista = comienzoOtraLista->_sig;
		}
		return nodosIguales;
	}
}

template<typename T>
Mateada<T>::Mateada(const Mateada<T>& constMateada) {
	_comienzo = NULL;
	_actual = NULL;
	_longuitud = 0;
	//copiar nodos
	Nodo* indexPtr = constMateada._comienzo;
	int i = constMateada._longuitud;
	while (i > 0) {
		quieroMatear(indexPtr->_data);
		if (indexPtr->_baboso) babearMate();
		indexPtr = indexPtr->_sig;
		i--;
	}
}

#endif //MATEADA_H_
