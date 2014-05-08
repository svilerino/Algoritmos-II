
template<class T>
Arreglo<T>::Arreglo() : array(NULL), size(0) {}

template<class T>
Arreglo<T>::Arreglo(Nat tamanio) : size(tamanio) {
    array = new Ptr[size];
}

template<class T>
Arreglo<T>::Arreglo(const Arreglo<T>& otro) {
    Asignar(otro);
}

template<class T>
Arreglo<T>& Arreglo<T>::operator=(const Arreglo<T>& otro) {
    if(this != &otro) {
        Destruir();
        Asignar(otro);
    }
    return *this;
}

template<class T>
Arreglo<T>::~Arreglo() {
    Destruir();
}

template<class T>
const T& Arreglo<T>::operator[](Nat pos) const {
    assert(Definido(pos));
    return *array[pos];
}

template<class T>
T& Arreglo<T>::operator[](Nat pos) {
    assert(Definido(pos));
    return *array[pos];
}

template<class T>
bool Arreglo<T>::Definido(Nat pos) const {
    return pos < size and array[pos] != NULL;
}

template<class T>
Arreglo<T>& Arreglo<T>::Definir(Nat pos, const T& valor) {
    assert(pos < size);
    Borrar(pos);
    array[pos] = new T(valor);
    return *this;
}

template<class T>
Arreglo<T>& Arreglo<T>::Borrar(Nat pos) {
    assert(pos < size);
    array[pos].Delete();
    return *this;
}

template<class T>
Nat Arreglo<T>::Tamanho() const {
    return size;
}

template<class T>
Arreglo<T>& Arreglo<T>::Redimensionar(Nat tam) {
    Ptr* oldarray = array;
    array = tam == 0 ? NULL : new Ptr[tam];
    
    for(Nat p = 0; p < size && p < tam; ++p) 
        array[p] = oldarray[p];     //no copia, simplemente mueve los punteros
    
    //borramos los eltos viejos
    for(Nat p = tam; p < size; ++p) 
        oldarray[p].Delete();
    delete [] oldarray;
                    
    size = tam;
    return *this;
}

template<class T>
Arreglo<T>& Arreglo<T>::Mover(Nat posThis, Arreglo<T>& otro, Nat posOtro) {
    if(this != &otro or posThis != posOtro) {
        Borrar(posThis);
        array[posThis] = otro.array[posOtro];
        otro.array[posOtro] = NULL;
    }
    return *this;
}

template<class T>
Arreglo<T>& Arreglo<T>::Mover(Nat destino, Nat origen) {
    return Mover(destino, *this, origen);
}

template<class T>
Arreglo<T>& Arreglo<T>::Swap(Nat posThis, Arreglo<T>& otro, Nat posOtro) {
    Ptr tmp = array[posThis];
    array[posThis] = otro.array[posOtro];
    otro.array[posOtro] = tmp;
    return *this;
}

template<class T>
Arreglo<T>& Arreglo<T>::Swap(Nat posA, Nat posB) {
    return Swap(posA, *this, posB);
}

template<class T>
void Arreglo<T>::Destruir() {
    for(Nat p = 0; p < size; ++p) Borrar(p);
    delete[] array;
    array = NULL;
}

template<class T>
void Arreglo<T>::Asignar(const Arreglo<T>& otro) {
    size = otro.size;
    array = new Ptr[size];
    for(Nat p = 0; p < size; ++p)
        array[p] = otro.array[p].Copiar();
}


template<class T>
std::ostream& operator<<(std::ostream& os, const Arreglo<T>& a) {
    os << "[";
    for(Nat p = 0; p < a.Tamanho() - 1; ++p) {
        if(a.Definido(p)) os << a[p];
        os << ",";  
    }
    if(a.Definido(a.Tamanho()-1)) os << a[a.Tamanho()-1];
    return os << "]";
}

template<class T>
bool operator==(const Arreglo<T>& a, const Arreglo<T>& b) {
    bool retval = a.Tamanho() == b.Tamanho();
    for(Nat p = 0; p < a.Tamanho() && retval; ++p) {
        retval = a.Definido(p) == b.Definido(p);
        if(retval and a.Definido(p)) retval = a[p] == b[p];
    }
    return retval;
}
