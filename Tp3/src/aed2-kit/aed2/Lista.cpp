
/// Implementación

template <typename T>
Lista<T>::Lista() : primero(NULL), longitud(0) {}

template <typename T>
Lista<T>::Lista(const Lista<T>& otra) : primero(NULL), longitud(0)
{
    *this = otra;
}

template <typename T>
Lista<T>& Lista<T>::operator=(const Lista<T>& otra) {
    if(this != &otra) {
        while(!EsVacia()) Fin();    
        for(const_Iterador it = otra.CrearIt(); it.HaySiguiente(); it.Avanzar())
            this->AgregarAtras(it.Siguiente());
    }
    return *this;
}

template <typename T>
Lista<T>::~Lista()
{
    while(!EsVacia()) Fin();
}

template <typename T>
bool Lista<T>::EsVacia() const
{
    return primero == NULL;
}

template <typename T>
Nat Lista<T>::Longitud() const
{
    return longitud;
}

template <typename T>
T& Lista<T>::Primero()
{
    assert(not EsVacia());
    return CrearIt().Siguiente();
}

template <typename T>
const T& Lista<T>::Primero() const
{
    assert(not EsVacia());
    return CrearIt().Siguiente();
}

template <typename T>
T& Lista<T>::Ultimo()
{
    assert(not EsVacia());
    return CrearItUlt().Anterior();
}

template <typename T>
const T& Lista<T>::Ultimo() const
{
    assert(not EsVacia());    
    return CrearItUlt().Anterior();
}

template <typename T>
const T& Lista<T>::operator[](Nat i) const
{
    assert(i < longitud);    
    const_Iterador it = CrearIt();
    while(i > 0) {
        it.Avanzar();
        --i;
    }

    return it.Siguiente();
}

template <typename T>
T& Lista<T>::operator[](Nat i)
{
    assert(i < longitud);    
    Iterador it = CrearIt();
    while(i > 0)
    {
        it.Avanzar();
        --i;
    }

    return it.Siguiente();
}

template <typename T>
void Lista<T>::Fin()
{
    assert(not EsVacia());    
    CrearIt().EliminarSiguiente();
}

template <typename T>
void Lista<T>::Comienzo()
{
    assert(not EsVacia());    
    CrearItUlt().EliminarAnterior();
}

template <typename T>
typename Lista<T>::Iterador Lista<T>::AgregarAdelante(const T& dato)
{
    typename Lista<T>::Iterador res =  CrearIt(); 
    res.AgregarComoSiguiente(dato);
    return res;
}

template <typename T>
typename Lista<T>::Iterador Lista<T>::AgregarAtras(const T& dato)
{
    typename Lista<T>::Iterador res = CrearItUlt();
    res.AgregarComoSiguiente(dato);
    return res;
}

/*
template <typename T>
std::ostream& Lista<T>::Mostrar(std::ostream& os) const
{
    os << "| ";
    const_Iterador it = CrearIt();

    while(it.HaySiguiente())
    {
        os << it.Siguiente() << " ";
        it.Avanzar();
    }
    return os << "|";
}
*/


template <typename T>
typename Lista<T>::const_Iterador Lista<T>::CrearIt() const
{
    return const_Iterador(this, primero);
}

template <typename T>
typename Lista<T>::const_Iterador Lista<T>::CrearItUlt() const
{
    return const_Iterador(this, NULL);
}

template <typename T>
bool Lista<T>::const_Iterador::HaySiguiente() const
{
    return nodo_siguiente != NULL;
}

template <typename T>
bool Lista<T>::const_Iterador::HayAnterior() const
{
    return nodo_siguiente != lista->primero;
}

template <typename T>
const T& Lista<T>::const_Iterador::Siguiente() const
{
    assert(HaySiguiente());
    return nodo_siguiente->dato;
}

template <typename T>
const T& Lista<T>::const_Iterador::Anterior() const
{
    assert(HayAnterior());
    return SiguienteReal()->anterior->dato;
}

template <typename T>
void Lista<T>::const_Iterador::Avanzar()
{
    assert(HaySiguiente());
    nodo_siguiente = nodo_siguiente->siguiente;
    if(nodo_siguiente == lista->primero) nodo_siguiente = NULL;
}

template <typename T>
void Lista<T>::const_Iterador::Retroceder()
{
    assert(HayAnterior());
    nodo_siguiente = SiguienteReal()->anterior;
}

template <typename T>
const typename Lista<T>::Nodo* Lista<T>::const_Iterador::SiguienteReal() const {
    return nodo_siguiente == NULL ? lista->primero : nodo_siguiente;
}

template <typename T>
typename Lista<T>::Iterador Lista<T>::CrearIt()
{
    return Iterador(this, primero);
}

template <typename T>
typename Lista<T>::Iterador Lista<T>::CrearItUlt()
{
    return Iterador(this, NULL);
}

template <typename T>
bool Lista<T>::Iterador::HaySiguiente() const
{
    return nodo_siguiente != NULL;
}

template <typename T>
bool Lista<T>::Iterador::HayAnterior() const
{
    return nodo_siguiente != lista->primero;
}

template <typename T>
T& Lista<T>::Iterador::Siguiente() const
{
    assert(HaySiguiente());
    return nodo_siguiente->dato;
}

template <typename T>
T& Lista<T>::Iterador::Anterior() const
{
    assert(HayAnterior());
    return SiguienteReal()->anterior->dato;
}

template <typename T>
void Lista<T>::Iterador::Avanzar()
{
    assert(HaySiguiente());
    nodo_siguiente = nodo_siguiente->siguiente;
    if(nodo_siguiente == lista->primero) nodo_siguiente = NULL;
}

template <typename T>
void Lista<T>::Iterador::Retroceder()
{
    assert(HayAnterior());
    nodo_siguiente = SiguienteReal()->anterior;
}

template <typename T>
void Lista<T>::Iterador::AgregarComoAnterior(const T& dato)
{
    Nodo* sig = SiguienteReal();
    Nodo* nuevo = new Nodo(dato);

    //asignamos anterior y siguiente de acuerdo a si el nodo es el primero
    //o no de la lista circular
    nuevo->anterior = sig == NULL ? nuevo : sig->anterior;
    nuevo->siguiente = sig == NULL ? nuevo : sig;
    
    //reencadenamos los otros nodos (notar que no hay problema cuando nuevo
    //es el primer nodo creado de la lista)
    nuevo->anterior->siguiente = nuevo;
    nuevo->siguiente->anterior = nuevo;

    //cambiamos el primero en el caso que nodo_siguiente == primero
    if(nodo_siguiente == lista->primero)
        lista->primero = nuevo;

    lista->longitud++;
}

template <typename T>
void Lista<T>::Iterador::AgregarComoSiguiente(const T& dato)
{
    AgregarComoAnterior(dato);
    Retroceder();
}

template <typename T>
void Lista<T>::Iterador::EliminarAnterior()
{
    assert(HayAnterior());
    Retroceder();
    EliminarSiguiente();
}

template <typename T>
void Lista<T>::Iterador::EliminarSiguiente()
{
    assert(HaySiguiente());

    Nodo* tmp = nodo_siguiente;

    //reencadenamos los nodos
    tmp->siguiente->anterior = tmp->anterior;
    tmp->anterior->siguiente = tmp->siguiente;

    //borramos el unico nodo que habia?
    nodo_siguiente = tmp->siguiente == tmp ? NULL : tmp->siguiente;
    //borramos el último?
    nodo_siguiente = tmp->siguiente == lista->primero ? NULL : tmp->siguiente;

    if(tmp == lista->primero)    //borramos el primero?
        lista->primero = nodo_siguiente;

    delete tmp;
    lista->longitud--;
}

template<class T>
bool Lista<T>::Iterador::operator==(const typename Lista<T>::Iterador& otro) const {
	return lista == otro.lista && nodo_siguiente == otro.nodo_siguiente;
}

template<class T>
bool Lista<T>::const_Iterador::operator==(const typename Lista<T>::const_Iterador& otro) const {
	return lista == otro.lista && nodo_siguiente == otro.nodo_siguiente;
}

template <typename T>
typename Lista<T>::Nodo* Lista<T>::Iterador::SiguienteReal() const {
    return nodo_siguiente == NULL ? lista->primero : nodo_siguiente;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Lista<T>& lista)
{
    return Mostrar(os, lista, '<', '>');
}

template <typename T>
bool operator==(const Lista<T>& l1, const Lista<T>& l2) 
{
    typename Lista<T>::const_Iterador it1 = l1.CrearIt();
    typename Lista<T>::const_Iterador it2 = l2.CrearIt();
    while(it1.HaySiguiente() and it2.HaySiguiente() and it1.Siguiente() == it2.Siguiente()) {
        it1.Avanzar(); it2.Avanzar();
    }
    return not it1.HaySiguiente() and not it2.haySiguiente();
}

