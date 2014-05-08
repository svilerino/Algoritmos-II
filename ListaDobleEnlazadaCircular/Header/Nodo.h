/*
 * Nodo.h
 *
 *  Created on: 17/04/2013
 *      Author: Sil
 */

#ifndef NODO_H_
#define NODO_H_

template<class T>
class Nodo {
private:
	T data;
	Nodo<T>* next;
	Nodo<T>* prev;
public:
	Nodo(T data, Nodo* prev, Nodo* next);
	Nodo();
	Nodo(Nodo<T>& otherNodo);
	~Nodo();
	T getData();
	Nodo<T>* getNext();
	Nodo<T>* getPrev();
	void setNext(Nodo<T>* next);
	void setPrev(Nodo<T>* prev);
	void setData(T data);
};

template<class T>
Nodo<T>::Nodo(T data, Nodo* prev, Nodo* next) {
	this->data = data;
	this->prev = prev;
	this->next = next;
}

template<class T>
Nodo<T>::Nodo() {
	this->prev = NULL;
	this->next = NULL;
}

template<class T>
Nodo<T>::~Nodo() {
}

template<class T>
T Nodo<T>::getData() {
	return this->data;
}

template<class T>
Nodo<T>* Nodo<T>::getNext() {
	return this->next;
}

template<class T>
Nodo<T>* Nodo<T>::getPrev() {
	return this->prev;
}

template<class T>
void Nodo<T>::setNext(Nodo<T>* next) {
	this->next = next;
}

template<class T>
void Nodo<T>::setPrev(Nodo<T>* prev) {
	this->prev = prev;
}

template<class T>
Nodo<T>::Nodo(Nodo<T>& otherNodo) {
	this->data=otherNodo.data;
	this->next=otherNodo.next;
	this->prev=otherNodo.prev;
}

template<class T>
void Nodo<T>::setData(T data) {
	this->data = data;
}

#endif /* NODO_H_ */
