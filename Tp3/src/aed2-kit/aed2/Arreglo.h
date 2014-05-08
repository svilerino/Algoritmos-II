
#ifndef AED2_ARREGLO_H_INCLUDED
#define AED2_ARREGLO_H_INCLUDED

#include "TiposBasicos.h"

namespace aed2 {

    template<class T>
    class Arreglo{
        public:
       
            /** 
             * Crea un arreglo de tamaño 0.
             */
            Arreglo();
        
            /**
             * Crea un arreglo de tamaño tam, donde todas las posiciones
             * son nulas.
             */ 
            Arreglo(Nat tam);
            
            /**
             * Constructor por copia.  Los elementos de otro se copian
             * en el mismo orden a this, y pasan a ser arreglos independientes
             */
            Arreglo(const Arreglo<T>& otro);
            
            /**
             * Operacion de asignacion.  Borra lo que se que habia en this
             * y copia los elementos de otro en el mismo orden.
             */
            Arreglo<T>& operator=(const Arreglo<T>& otro);
            
            /**
             * Destructor.  Borra lo que hubiera en el arreglo.
             */
            ~Arreglo();
            
            /**
             * Devuelve el elemento en la posicion pos.
             * Requiere: Definido(pos)
             */
            const T& operator[](Nat pos) const;
            
            /**
             * Devuelve el elemento en la posicion pos.
             * Requiere: Definido(pos)
             */
            T& operator[](Nat pos);
      
            /**
             * Devuelve true si en la posicion pos fue definido algun
             * elemento.
             */
            bool Definido(Nat pos) const;
            
            /**
             * Define valor en la posicion pos.  Devuelve this
             */ 
            Arreglo<T>& Definir(Nat pos, const T& valor);
            
            /**
             * Indefine el elemento en pos.  
             * No requiere que el elemento este definido.
             * Devuelve this.
             */
            Arreglo<T>& Borrar(Nat pos);
            
            /**
             * Devuelve el tamaño del arreglo
             */
            Nat Tamanho() const;
            
            /**
             * Redimensiona el arreglo, sin copiar los items de nuevo.
             * Si el arreglo es mas chico, se borran los datos sobrantes.
             * Sino, se definen items nuevos en null.
             */
            Arreglo<T>& Redimensionar(Nat tam);
            
            /**
             * Mueve el dato de otro[posOtro] a this[posThis] en O(1).  
             * Si ya habia un dato en this[posThis], el mismo se elimina.
             * Despues de esto, no esta definido el valor de posOtro en
             * otro.
             * Obviamente, this puede ser igual a otro, para lograr mover
             * las cosas de un lugar a otro.  Aunque se recomienda utilizar
             * la otra version de mover.
             */
            Arreglo<T>& Mover(Nat posThis, Arreglo<T>& otro, Nat posOtro);
            
            /**
             * Equivalente a Mover(destino, this, origen)
             */
            Arreglo<T>& Mover(Nat destino, Nat origen);
            
            /**
             * Intercambia los valores de this[posThis] y otro[posOtro]
             * sin realizar copias nuevas de los elementos.
             * Obviamente, this puede ser igual a otro.
             */
            Arreglo<T>& Swap(Nat posThis, Arreglo<T>& otro, Nat posOtro);
            
            /**
             * Equivalente a Swap(posA, this, posB)
             */
            Arreglo<T>& Swap(Nat posA, Nat posB);
            
        private:
            //HACK PARA QUE AUTOMAGICAMENTE SE ASIGNEN LAS POSICIONES EN NULL
            struct Ptr {
                public:
                    Ptr(T* t = NULL) {ptr = t;}
                    operator T*() {return ptr;}
                    void Delete() {delete ptr; ptr = NULL;}
                    Ptr Copiar() {return ptr == NULL ? NULL : Ptr(new T(*ptr));}
                    T* ptr;                   
            };

            Ptr* array;
            Nat size;
            
            void Destruir();            
            void Asignar(const Arreglo<T>& otro);
            
    };

    /**
     * Funciones globales de comparacion.  Con definir el == obtenemos
     * el != gratis :)
     */
    template<class T>
    bool operator==(const Arreglo<T>&, const Arreglo<T>&);

    template<class T>
    std::ostream& operator<<(std::ostream& os, const Arreglo<T>&);
    
    #include "Arreglo.cpp"
}



#endif
