/* 
 * File:   Dicc.h
 * Author: Fede
 *
 * Created on 30 de octubre de 2010, 08:59
 */

#ifndef AED2_DICC_H_INCLUDED
#define	AED2_DICC_H_INCLUDED
#include <ostream>
#include "Lista.h"

namespace aed2 {
    template<class K,class S>
    class Dicc{
    public:
        //para iterar las tuplas vamos a usar los siguientes tipos
        struct Elem;
        struct const_Elem;
        class Iterador;
        class const_Iterador;

        Dicc();
        Dicc(const Dicc<K,S>& otro);
        Dicc<K,S>& operator=(const Dicc<K,S>& otro);
        Iterador Definir(const K& clave, const S& significado);
        Iterador DefinirRapido(const K& clave, const S& significado);
        bool Definido(const K& clave) const;
        const S& Significado(const K& clave) const;
        S& Significado(const K& clave);
        void Borrar(const K& clave);
        Nat CantClaves() const;
        Iterador CrearIt();
        const_Iterador CrearIt() const;
        //Estas funciones son utiles para saber si algo esta definido
        //y ver cual es su signficado, sin recorrer dos veces.
        Iterador Buscar(const K&);
        const_Iterador Buscar(const K&) const;
        
        class Iterador{
        public:
        	Iterador(const typename Dicc<K, S>::Iterador& otro) : itC(otro.itC), itS(otro.itS) {}
        	Iterador& operator=(const typename Dicc<K, S>::Iterador& otro) 
        		{itC = otro.itC; itS = otro.itS; return *this;}
        	Iterador() {}
        
        	bool operator==(const typename Dicc<K,S>::Iterador&) const;
        
            bool HaySiguiente() const;
            bool HayAnterior() const;
            const K& SiguienteClave() const;
            S& SiguienteSignificado() const;
            const K& AnteriorClave() const;
            S& AnteriorSignificado() const;
            Elem Siguiente() const;
            Elem Anterior() const;
            void Avanzar();
            void Retroceder();
            void EliminarSiguiente();
            void EliminarAnterior();
        private:
            Iterador(Dicc<K,S>* d);
            friend typename Dicc<K,S>::Iterador Dicc<K,S>::CrearIt();
            typename Lista<K>::Iterador itC;
            typename Lista<S>::Iterador itS;
            friend class Dicc<K, S>::const_Iterador;
        };

        class const_Iterador{
        public:
			const_Iterador(const typename Dicc<K,S>::Iterador& otro) : itC(otro.itC), itS(otro.itS) {}
        	const_Iterador(const typename Dicc<K, S>::const_Iterador& otro) : itC(otro.itC), itS(otro.itS) {}
        	const_Iterador& operator=(const typename Dicc<K, S>::const_Iterador& otro) 
        		{itC = otro.itC; itS = otro.itS; return *this;}
        	const_Iterador() {}

		    bool operator==(const typename Dicc<K,S>::const_Iterador&) const;

            bool HaySiguiente() const;
            bool HayAnterior() const;
            const K& SiguienteClave() const;
            const S& SiguienteSignificado() const;
            const K& AnteriorClave() const;
            const S& AnteriorSignificado() const;
            const_Elem Siguiente() const;
            const_Elem Anterior() const;
            void Avanzar();
            void Retroceder();
        private:
            const_Iterador(const Dicc<K,S>* d);
            friend typename Dicc<K,S>::const_Iterador Dicc<K,S>::CrearIt() const;
            typename Lista<K>::const_Iterador itC;
            typename Lista<S>::const_Iterador itS;
        };

        struct Elem {
                const K& clave;
                S& significado;
                Elem(const K& c, S& s) : clave(c), significado(s) {}
                //Para sacar esto de aca, necesitariamos definir rasgos y otras yerbas
                //Lamentablemente, sino C++ no reconoce bien los tipos
                friend std::ostream& operator<<(std::ostream& os, const Dicc<K,S>::Elem& e) {
                    return os << e.clave << ":" << e.significado;
                }
            private:
                typename Dicc<K,S>::Elem& operator=(const Dicc<K,S>::Elem&);
        };
        struct const_Elem {
                const K& clave;
                const S& significado;
                const_Elem(const K& c, const S& s) : clave(c), significado(s) {}
                //Para sacar esto de aca, necesitariamos definir rasgos y otras yerbas
                //Lamentablemente, sino C++ no reconoce bien los tipos                
                friend std::ostream& operator<<(std::ostream& os, const Dicc<K,S>::const_Elem& e) {
                    return os << e.clave << ":" << e.significado;
                }
            private:
                typename Dicc<K,S>::const_Elem& operator=(const Dicc<K,S>::const_Elem&);
        };

    private:
        Lista<K> claves;
        Lista<S> significados;

    };

    template<class K, class S>
    std::ostream& operator<<(std::ostream &os, const Dicc<K,S>& d);

    template<class K, class S>
    bool operator==(const Dicc<K,S>& d1, const Dicc<K,S>& d2);
    
    
    #include "Dicc.cpp"

}
#endif	//AED2_DICC_H_INCLUDED

