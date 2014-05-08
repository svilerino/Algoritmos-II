
#ifndef AED2_VECTOR_H_INCLUDED
#define AED2_VECTOR_H_INCLUDED

#include "TiposBasicos.h"
#include "Arreglo.h"

namespace aed2 {

    template<class T>
    class Vector {
        public:
            class const_Iterador;
        
            Vector();
            Vector(const Vector<T>& otro);
            Vector<T>& operator=(const Vector<T>& otro);
            
            void AgregarAtras(const T& elem);
            bool EsVacio() const;
            void Comienzo();
            void TomarPrimeros(Nat n);
            void TirarUltimos(Nat n);
            const T& Ultimo() const;
            T& Ultimo();
            Nat Longitud() const;
            const T& operator[](Nat pos) const;
            T& operator[](Nat pos);
            
            void Agregar(Nat pos, const T& elem);
            void Eliminar(Nat pos);
            
            //funciones para implementar sorting y esas cosas eficientemente
            void Mover(Nat posThis, Vector<T>& otro, Nat posOtro);
            void Mover(Nat destino, Nat origen);
            void Swap(Nat posThis, Vector<T>& otro, Nat posOtro);
            void Swap(Nat pos1, Nat pos2);
            
            //iterador para funciones genericas.  En particular, Mostrar :)
            const_Iterador CrearIt() const;
            
            class const_Iterador{
                public:
                    bool HaySiguiente() const {return pos < vector->Longitud();}
                    bool HayAnterior() const {return pos != 0;}
                    void Avanzar() {assert(HaySiguiente()); ++pos;}
                    void Retroceder() {assert(HayAnterior()); --pos;}
                    const T& Siguiente() const {assert(HaySiguiente()); return (*vector)[pos];}
                    const T& Anterior() const {assert(HayAnterior()); return (*vector)[pos-1];};
                private:
                    const Vector<T>* vector;
                    Nat pos;
                    const_Iterador(const Vector<T>* v, Nat p = 0) : vector(v), pos(p) {}
                    friend typename Vector<T>::const_Iterador Vector<T>::CrearIt() const;
            };
        private:
            Arreglo<T> elementos;
            Nat longitud;
    };

    template<class T>
    std::ostream& operator<<(std::ostream& os, const Vector<T>& v);
    
    template<class T>
    bool operator==(const Vector<T>& v, const Vector<T>& w);
    
    #include "Vector.cpp"
}

#endif //AED2_VECTOR_H_INCLUDED
