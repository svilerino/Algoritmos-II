/* 
 * File:   Conj.h
 * Author: Fede
 *
 * Created on 30 de octubre de 2010, 15:57
 */

#ifndef AED2_CONJ_H_INCLUDED
#define	AED2_CONJ_H_INCLUDED

#include <iostream>
#include "Dicc.h"

namespace aed2 {

    template<class T>
    class Conj{
    public:
        class Iterador;
        class const_Iterador;

        Conj();
        Conj(const Conj<T>& otro);

        Iterador Agregar(const T& e);
        Iterador AgregarRapido(const T& e);
        bool EsVacio() const;
        bool Pertenece(const T& e) const;
        void Eliminar(const T& e);
        Nat Cardinal() const;
        const_Iterador CrearIt() const;
        Iterador CrearIt();
        
        //esta funcion la agregamos aca, porque nos conviene acceder a 
        //la representación.  Sino, no haria falta.
        bool operator==(const Conj<T>& otro) const;
        
        class const_Iterador{
            typename Dicc<T,bool>::const_Iterador it;
            const_Iterador(const Conj<T>* c);
            friend typename Conj<T>::const_Iterador Conj<T>::CrearIt() const;
        public:
        	const_Iterador() {}
			const_Iterador(const typename Conj<T>::Iterador& otra) : it(otra.it) {}
			const_Iterador(const typename Conj<T>::const_Iterador& otra) : it(otra.it) {}
			const_Iterador& operator=(const typename Conj<T>::const_Iterador& otra) 
				{it = otra.it; return *this;}

			bool operator==(const typename Conj<T>::const_Iterador& otro) const {return it == otro.it;}
			
            bool HaySiguiente()const;
            bool HayAnterior()const;
            const T& Siguiente()const;
            const T& Anterior()const;
            void Avanzar();
            void Retroceder();
        };

        class Iterador{
            typename Dicc<T,bool>::Iterador it;
            Iterador(Conj<T>* c);
            friend typename Conj<T>::Iterador Conj<T>::CrearIt();
            Iterador(const typename Dicc<T,bool>::Iterador& itDict);
            friend typename Conj<T>::Iterador Conj<T>::Agregar(const T&);
            friend typename Conj<T>::Iterador Conj<T>::AgregarRapido(const T&);
            friend class Conj<T>::const_Iterador;
        public:
			Iterador(const typename Conj<T>::Iterador& otra) : it(otra.it) {}
			Iterador& operator=(const typename Conj<T>::Iterador& otra) 
				{it = otra.it; return *this;}
			Iterador() {}

			bool operator==(const typename Conj<T>::Iterador& otro) const {return it == otro.it;}

            bool HaySiguiente() const;
            bool HayAnterior() const;
            const T& Siguiente() const;
            const T& Anterior() const;
            void Avanzar();
            void Retroceder();
            void EliminarAnterior();
            void EliminarSiguiente();
        };

    private:
        Dicc<T,bool> d;
    };

    template<class T>
    std::ostream& operator<<(std::ostream&, const Conj<T>&);

    template<class T>
    std::ostream& operator==(const Conj<T>&, const Conj<T>&);

    #include "Conj.cpp"
}

#endif	//AED2_CONJ_H_INCLUDED

