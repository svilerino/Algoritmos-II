#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED

#include <iostream>
#include <cassert>
#include <cmath>
#include <stack>

using namespace std;

/**
* Asume que T tiene constructor por copia
*/
template<typename T>
class ABB{
public:
    class IteradorPreOrder;

    ABB();

    ~ABB();

    ABB(ABB<T> const & otro);

    void insertar(T const & elem);

    void borrar(T const & elem);

    int altura() const;

    bool esta(T const & elem) const;

    IteradorPreOrder crearItPreOrder() const;

    ostream & mostrar(ostream & out) const;

    class IteradorPreOrder{
    public:
        void avanzar();
        T actual() const;
        bool hayMas() const;
        friend IteradorPreOrder ABB<T>::crearItPreOrder() const;
    private:
        typename ABB<T>::Nodo * _actual;
        stack<typename ABB<T>::Nodo *> _proximos;
        IteradorPreOrder(typename ABB<T>::Nodo * raiz);
    };

private:
    struct Nodo{
        T _elem;
        Nodo * _padre;
        Nodo * _izq;
        Nodo * _der;

        Nodo(T const & otro) : _elem(otro){
            _izq = _der = NULL;
        };
    };

    Nodo * _raiz;

    void desalojar(Nodo * nodo);

    Nodo * copiar(Nodo const * nodo);

    int altura(Nodo const * nodo) const;

    ostream & mostrar(ostream & out, Nodo const * nodo, int profundidad) const;

    void insertar(Nodo * & nodo, T const & elem) const;

    Nodo * buscar(Nodo * nodo, T const & elem) const;

    Nodo * & hijo(Nodo * nodo) const;

    Nodo * antecesor(Nodo const * nodo) const;

    void borrar(Nodo * nodo);
};

template<class T>
ostream & operator<<(ostream & out, const ABB<T>& a) {
	return a.mostrar(out);
}

//publicas

template<typename T>
ABB<T>::ABB(){
    _raiz = NULL;
}

template<typename T>
ABB<T>::~ABB(){
    desalojar(_raiz);
}

template<typename T>
ABB<T>::ABB(ABB<T> const & otro){
    _raiz = copiar(otro._raiz);
}

template<typename T>
void ABB<T>::insertar(T const & elem){
    insertar(_raiz, elem);
}

template<typename T>
void ABB<T>::borrar(T const & elem){
    Nodo * nodo = buscar(_raiz, elem);

    assert(nodo != NULL);

    borrar(nodo);
}

template<typename T>
int ABB<T>::altura() const{
    return altura(_raiz);
}

template<typename T>
bool ABB<T>::esta(T const & elem) const{
    return buscar(_raiz, elem) != NULL;
}

template<typename T>
typename ABB<T>::IteradorPreOrder ABB<T>::crearItPreOrder() const{
    return ABB<T>::IteradorPreOrder(_raiz);
}

template<typename T>
ostream & ABB<T>::mostrar(ostream & out) const{
    return mostrar(out, _raiz, 0);
}

//iterador

template<typename T>
ABB<T>::IteradorPreOrder::IteradorPreOrder(Nodo * raiz) : _actual(raiz){
    if(raiz != NULL){
        _proximos.push(raiz);
    }
}

template<typename T>
void ABB<T>::IteradorPreOrder::avanzar(){
    assert(hayMas());

    _proximos.pop();

    if(_actual->_izq != NULL){
        if(_actual->_der != NULL){
            _proximos.push(_actual->_der);
        }
        _proximos.push(_actual->_izq);

        _actual = _actual->_izq;
    }else{
        if(_actual->_der != NULL){
            _proximos.push(_actual->_der);
            _actual = _actual->_der;
        }else{
            if(!_proximos.empty()){
                _actual = _proximos.top();
            }
        }
    }
}

template<typename T>
T ABB<T>::IteradorPreOrder::actual() const{
    assert(hayMas());

    return _actual->_elem;
}

template<typename T>
bool ABB<T>::IteradorPreOrder::hayMas() const{
    return !_proximos.empty();
}

//privadas

template<typename T>
void ABB<T>::desalojar(Nodo * nodo){
    if(nodo != NULL){
        desalojar(nodo->_izq);
        desalojar(nodo->_der);
        delete nodo;
    }
}

template<typename T>
typename ABB<T>::Nodo * ABB<T>::copiar(Nodo const * nodo){
    if(nodo == NULL){
        return NULL;
    }

    Nodo * res = new Nodo(nodo->_elem);
    res->_izq = copiar(nodo->_izq);
    res->_der = copiar(nodo->_der);

    return res;
}

template<typename T>
int ABB<T>::altura(Nodo const * nodo) const{
    if(nodo == NULL){
        return 0;
    }

    return 1 + max(altura(nodo->_izq), altura(nodo->_der));
}

template<typename T>
ostream & ABB<T>::mostrar(ostream & out, Nodo const * nodo, int profundidad) const{
    if(nodo->_der != NULL){
        mostrar(out, nodo->_der, profundidad + 1);
    }

    for(int i = 0; i < profundidad; i++){
        out << "   ";
    }

    out << nodo->_elem << endl;

    if(nodo->_izq != NULL){
        mostrar(out, nodo->_izq, profundidad + 1);
    }

    return out;
}

template<typename T>
void ABB<T>::insertar(Nodo * & nodo, T const & elem) const{
    if(nodo == NULL){
        //arbol vacio
        nodo = new Nodo(elem);
    }else{
        if(elem < nodo->_elem){
            if(nodo->_izq == NULL){
                Nodo * nuevo = new Nodo(elem);
                nuevo->_padre = nodo;
                nodo->_izq = nuevo;
            }else{
                insertar(nodo->_izq, elem);
            }
        }else{
            if(nodo->_der == NULL){
                Nodo * nuevo = new Nodo(elem);
                nuevo->_padre = nodo;
                nodo->_der = nuevo;
            }else{
                insertar(nodo->_der, elem);
            }
        }
    }
}

template<typename T>
typename ABB<T>::Nodo * ABB<T>::buscar(Nodo * nodo, T const & elem) const{
    if(nodo == NULL){
        return NULL;
    }

    if(nodo->_elem == elem){
        return nodo;
    }

    if(elem < nodo->_elem){
        return buscar(nodo->_izq, elem);
    }

    return buscar(nodo->_der, elem);
}

// devuelve una referencia al puntero a nodo de su padre
template<typename T>
typename ABB<T>::Nodo * & ABB<T>::hijo(Nodo * nodo) const{
    assert(nodo->_padre != NULL);

    if(nodo->_padre->_izq == nodo){
        return nodo->_padre->_izq;
    }else{
        return nodo->_padre->_der;
    }
}

template<typename T>
typename ABB<T>::Nodo * ABB<T>::antecesor(Nodo const * nodo) const{
    assert(nodo->_izq != NULL);

    Nodo * actual = nodo->_izq;

    while(actual->_der != NULL){
        actual = actual->_der;
    }

    return actual;
}

template<typename T>
void ABB<T>::borrar(Nodo * nodo){
    if(nodo->_izq == NULL && nodo->_der == NULL){
        //caso 1: el nodo a borrar es una hoja
        if(nodo->_padre == NULL){
            //es la raiz
            _raiz = NULL;
        }else{
            hijo(nodo) = NULL;
        }

        delete nodo;
    }else{
        if(nodo->_izq == NULL || nodo->_der == NULL){
        //caso 2: el nodo a borrar tiene un unico hijo
            if(nodo->_izq != NULL){
                if(nodo->_padre == NULL){
                    _raiz = nodo->_izq;
                }else{
                    //uno el padre de nodo con el hijo de nodo
                    hijo(nodo) = nodo->_izq;
                }
            }else{
                if(nodo->_padre == NULL){
                    _raiz = nodo->_der;
                }else{
                    hijo(nodo) = nodo->_der;
                }
            }

            delete nodo;
        }else{
            //caso 3: el nodo a borrar tiene dos hijos
            Nodo * ante = antecesor(nodo);
            nodo->_elem = ante->_elem;
            borrar(ante);
        }
    }
}

#endif // ABB_H_INCLUDED
