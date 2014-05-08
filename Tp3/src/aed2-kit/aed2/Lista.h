#ifndef AED2_LISTA_H_INCLUDED
#define AED2_LISTA_H_INCLUDED

#include <iostream>
#include "TiposBasicos.h"

namespace aed2{
    /**
     * Implementación del módulo Lista Enlazada(alpha) con su const_Iterador correspondiente.
     * Como estamos en C++, en lugar de alpha vamos a usar T.
     * Del parámetro formal T, sólo se supone la existencia de su constructor por copia.
     */
    template <typename T>
    class Lista
    {
    public:
        //forward declarations
        class Iterador;
        class const_Iterador;

        /// Crea una lista enlazada vacía. (Operación Vacia())
        Lista();
        /// Crea por copia una lista enlazada (operación Copiar())
        Lista(const Lista& otra);
        /// Destruye la lista, incluyendo los T alojados
        ~Lista();
        /// Operacion de asignacion
        Lista<T>& operator=(const Lista<T>& otra);

        /// Opreaciones básicas
        bool EsVacia() const;
        Nat Longitud() const;


        /// Acceso al primero y último elemento (en O(1) )
        /// Versiones modificables y no modificables
        T& Primero();
        const T& Primero() const;
        T& Ultimo();
        const T& Ultimo() const;
        /// Operador "iésimo"
        T& operator[](Nat i);
        const T& operator[](Nat i) const;

        /// Elimina el primer elemento
        void Fin();
        /// Elimina el último elemento
        void Comienzo();

        /// Inserción de elementos
        Iterador AgregarAdelante(const T& elem);
        Iterador AgregarAtras(const T& elem);

        /*************************************
         * const_Iterador de Lista, no modificable *
         *************************************/
        class const_Iterador
        {
        public:
        	const_Iterador() : lista(NULL), nodo_siguiente(NULL) {}
            /// Funcion de copia
            const_Iterador(const typename Lista<T>::const_Iterador& otro) :
                lista(otro.lista), nodo_siguiente(otro.nodo_siguiente) {}

            const_Iterador(const typename Lista<T>::Iterador& otro) :
                lista(otro.lista), nodo_siguiente(otro.nodo_siguiente) {}
                
            const_Iterador& operator=(const typename Lista<T>::const_Iterador& otro) 
                {lista = otro.lista; nodo_siguiente = otro.nodo_siguiente; return *this;}            

            bool HayAnterior() const;
            bool HaySiguiente() const;

            const T& Anterior() const;
            const T& Siguiente() const;

            void Avanzar();
            void Retroceder();

			bool operator==(const typename Lista<T>::const_Iterador& otro) const;

        private:
            /// El constructor es privado, necesitamos el friend.
            const_Iterador(const Lista<T>* _lista, const typename Lista<T>::Nodo* _proximo)
            : lista(_lista), nodo_siguiente(_proximo) {};
            friend typename Lista<T>::const_Iterador Lista<T>::CrearIt() const;
            friend typename Lista<T>::const_Iterador Lista<T>::CrearItUlt() const;

            const Lista<T>* lista;
            const typename Lista<T>::Nodo* nodo_siguiente;

            //devuelve el nodo siguiente en la lista circular
            const typename Lista<T>::Nodo* SiguienteReal() const;
        };
        /// Creación del const_Iterador
        const_Iterador CrearIt() const;
        const_Iterador CrearItUlt() const;


        /**********************************
         * const_Iterador de Lista, modificable *
         **********************************/
        class Iterador
        {
        public:
        	Iterador() : lista(NULL), nodo_siguiente(NULL) {}
            ///Funcion copiar
            Iterador(const typename Lista<T>::Iterador& otro) :
                lista(otro.lista), nodo_siguiente(otro.nodo_siguiente) {}

            Iterador& operator=(const typename Lista<T>::Iterador& otro) 
                {lista = otro.lista; nodo_siguiente = otro.nodo_siguiente; return *this;}            


            bool HayAnterior() const;
            bool HaySiguiente() const;

            T& Anterior() const;
            T& Siguiente() const;

            void Avanzar();
            void Retroceder();

            void EliminarAnterior();
            void EliminarSiguiente();

            void AgregarComoAnterior(const T& elem);
            void AgregarComoSiguiente(const T& elem);

			bool operator==(const typename Lista<T>::Iterador& otro) const;
            
        private:
            /// El constructor es privado, necesitamos el friend.
            Iterador(Lista<T>* _lista, typename Lista<T>::Nodo* _proximo)
            : lista(_lista), nodo_siguiente(_proximo) {};
            friend typename Lista<T>::Iterador Lista<T>::CrearIt();
            friend typename Lista<T>::Iterador Lista<T>::CrearItUlt();
            friend class Lista<T>::const_Iterador;

            Lista<T>* lista;
            typename Lista<T>::Nodo* nodo_siguiente;

            //devuelve el nodo siguiente en la lista circular
            typename Lista<T>::Nodo* SiguienteReal() const;

        };
        /// Creación del const_Iterador
        Iterador CrearIt();
        Iterador CrearItUlt();

    private:
        struct Nodo
        {
            Nodo(const T& d) : dato(d), anterior(NULL), siguiente(NULL) {};

            T dato;
            Nodo* anterior;
            Nodo* siguiente;
        };

        Nodo* primero;
        Nat longitud;
    };

    template<class T>
    std::ostream& operator<<(std::ostream& os, const Lista<T>& l);
    template<class T>
    bool operator==(const Lista<T>&, const Lista<T>&);

    #include "Lista.cpp"

}

#endif // AED2_LISTA_H_INCLUDED
