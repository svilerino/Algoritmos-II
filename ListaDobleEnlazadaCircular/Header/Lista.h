/*
 * Lista.h
 *
 *  Created on: 17/04/2013
 *      Author: Sil
 */

#ifndef LISTA_H_
#define LISTA_H_
#include "Nodo.h"

using namespace std;

template<class T>
class Lista {
private:
	int _longuitud;
	Nodo<T> *_comienzo;
	Nodo<T> *_current;
	Nodo<T> * buscarElemento(T data) const;
	void eliminarLista();
public:
	Lista();
	Lista(Lista<T> &otraLista);
	~Lista();
	void agregarNodo(T dato);
	void eliminarNodo(T dato);
	int longuitud() const;
	void modificarNodo(T dato, T nuevoDato);
	T siguienteElemento();

	template<class T2> friend ostream& operator <<(ostream &o, Lista<T2> &l);
};

template<class T>
void Lista<T>::eliminarLista() {
	cout << "destructor de " << this << endl;
	Nodo<T>* indexPtr = this->_comienzo;
	//tengo que eliminar this->longuitud nodos.
	//Entonces voy borrando y decremento en longuitud hasta quedarme sin.
	while (this->_longuitud > 0) {
		//me guardo el nodo a eliminar
		Nodo<T>* targetToDelete = indexPtr;
		//avanzo el puntero
		indexPtr = indexPtr->getNext();
		//elimino el nodo del que guarde la direccion.
		cout << "boleteo " << targetToDelete << " : " << targetToDelete->getData() << " | quedan " << (this->_longuitud-1) << " nodos" << endl;
		delete targetToDelete;
		//actualizo la longuitud de la lista.
		this->_longuitud--;
	}
}

template<class T>
void Lista<T>::agregarNodo(T dato) {
	if (this->_comienzo == NULL) {
		this->_comienzo = new Nodo<T>(dato, NULL, NULL);
		this->_comienzo->setPrev(_comienzo);
		this->_comienzo->setNext(_comienzo);
		this->_current=this->_comienzo;
	} else {
		//agrego al final
		//obtengo la posicion en la cual voy a agregar el nodo
		//la ultima, que al ser circular es la anterior a la primera
		Nodo<T>* posicionTarget = this->_comienzo->getPrev();
		Nodo<T>* nuevoNodo = new Nodo<T>(dato, NULL, NULL);
		//el nuevo nodo va a apuntar prev al nodo ultimo y next al primer nodo
		nuevoNodo->setPrev(posicionTarget);
		nuevoNodo->setNext(this->_comienzo);
		//el ultimo nodo va a apuntar prev sin cambios
		//el ultimo nodo va a apuntar next al nuevo nodo
		posicionTarget->setNext(nuevoNodo);
		//el primer nodo va a apuntar next sin cambios
		//el primer nodo va a apuntar a prev al nuevo nodo(que es el nuevo ultimo)
		this->_comienzo->setPrev(nuevoNodo);
		//modificar valores del nodo viejo
	}
	//agregue un nodo, aumento la longuitud.
	this->_longuitud++;
}

template<class T>
Nodo<T>* Lista<T>::buscarElemento(T dato) const{
	//marco el comienzo como indice de inicio.
	Nodo<T>* indexPtr = this->_comienzo;
	int i = this->_longuitud;
	//recorro la lista i(longuitud) veces, si no encuentra el dato entra en ciclo al ser circular => salgo del while.
	//si encuentra antes el dato target tambien sale del while.
	while ((i > 0) && (indexPtr->getData() != dato)) {
		indexPtr = indexPtr->getNext();
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

template<class T>
Lista<T>::Lista() {
	//inicializo la lista a NULL el comienzo y la longuitud en 0
	this->_longuitud = 0;
	this->_comienzo = NULL;
	this->_current=NULL;
}

template<class T>
Lista<T>::Lista(Lista<T> &otraLista){
	this->_comienzo=NULL;
	this->_current=NULL;
	this->_longuitud=0;
	//me copio los elementos de la otra lista con el iterador.
	if(otraLista.longuitud()>0){
		int i = otraLista._longuitud;
		while(i>0){
			this->agregarNodo(otraLista.siguienteElemento());
			i--;
		}
	}
}

/**
 * PRE: lista no vacia.
 */
template<class T>
T Lista<T>::siguienteElemento(){
	T targetADevolver = this->_current->getData();
	this->_current=this->_current->getNext();
	return targetADevolver;
}

template<class T>
Lista<T>::~Lista() {
	//el destructor libera toda la memoria utilizada.
	eliminarLista();
}

template<class T>
void Lista<T>::eliminarNodo(T dato) {
	//OJO SI HAY UN SOLO NODO CON TODAS LAS REFERENCIAS DE CLASE Y PONER UN IF APARTE !



	/*//busca el target a eliminar
	Nodo<T>* targetPtr = this->buscarElemento(dato);//devuelve primera aparicion en la lista desde comienzo
	//si devuelve NULL, no existia el dato
	if (targetPtr == NULL) {
		cerr << "no encontro el elemento: " << dato << endl;
	} else {
		//se modifican las referencias de los nodos anteriores y siguientes al target, "salteando" el nodo a eliminar
		targetPtr->getNext()->setPrev(targetPtr->getPrev());
		targetPtr->getPrev()->setNext(targetPtr->getNext());
		//se elimina el target
		delete targetPtr;
		_longuitud--;//se decrementa la longuitud
	}*/
}

template<class T>
int Lista<T>::longuitud() const{
	return this->_longuitud;
}

template<class T>
ostream& operator <<(ostream &o, Lista<T> &l) {
	//recorre la lista desde el puntero al comienzo, longuitud posiciones hacia "adelante" imprimiendo los nodos y sus punteros.
	Nodo<T>* indexPtr = l._comienzo;
	int i = l._longuitud;
	while (i > 0) {
		o << "[Anterior: " << indexPtr->getPrev() << "]\t [Actual: "
				<< indexPtr << "]\t [Dato: " << indexPtr->getData() << "]\t [Siguiente: "
				<< indexPtr->getNext() << "]";
		o << endl;
		indexPtr = indexPtr->getNext();
		i--;
	}
	return o;
}

template<class T>
void Lista<T>::modificarNodo(T dato, T nuevoDato) {
	Nodo<T>* targetPtr = this->buscarElemento(dato);//devuelve primera aparicion
	if (targetPtr == NULL) {
		//no encontro el elemento
	} else {
		targetPtr->setData(nuevoDato);//modifica el dato del nodo
	}
}

#endif /* LISTA_H_ */
