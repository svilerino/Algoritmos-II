

template<class T>
Conj<T>::Conj() {}

template<class T>
Conj<T>::Conj(const Conj<T>& otro): d(otro.d) {}

template<class T>
typename Conj<T>::Iterador Conj<T>::Agregar(const T& e){
    return Iterador(d.Definir(e, true));
}

template<class T>
typename Conj<T>::Iterador Conj<T>::AgregarRapido(const T& e){
    return Iterador(d.DefinirRapido(e, true));
}

template<class T>
bool Conj<T>::EsVacio() const{
    return d.CantClaves()==0;
}

template<class T>
bool Conj<T>::Pertenece(const T& e) const{
    return d.Definido(e);
}


template<class T>
void Conj<T>::Eliminar(const T& e){
    if(Pertenece(e)) d.Borrar(e);
}

template<class T>
Nat Conj<T>::Cardinal() const{
    return d.CantClaves();
}

template<class T>
bool Conj<T>::operator==(const Conj<T>& otro) const {
    return d == otro.d;
}

template<class T>
typename Conj<T>::Iterador Conj<T>::CrearIt(){
    return Iterador(this);
}

template<class T>
typename Conj<T>::const_Iterador Conj<T>::CrearIt() const{
    return const_Iterador(this);
}

template<class T>
Conj<T>::const_Iterador::const_Iterador(const Conj<T>* c):
    it(c->d.CrearIt()){}

template<class T>
Conj<T>::Iterador::Iterador(Conj<T>* c):
    it(c->d.CrearIt()){}

template<class T>
Conj<T>::Iterador::Iterador(const typename Dicc<T,bool>::Iterador& iter):
    it(iter) {}

template<class T>
bool Conj<T>::Iterador::HayAnterior() const{
    return it.HayAnterior();
}

template<class T>
bool Conj<T>::const_Iterador::HayAnterior() const{
    return it.HayAnterior();
}

template<class T>
bool Conj<T>::Iterador::HaySiguiente() const{
    return it.HaySiguiente();
}

template<class T>
bool Conj<T>::const_Iterador::HaySiguiente() const{
    return it.HaySiguiente();
}

template<class T>
const T& Conj<T>::const_Iterador::Siguiente() const{
    assert(HaySiguiente());    
    return it.SiguienteClave();
}

template<class T>
const T& Conj<T>::Iterador::Siguiente() const{
    assert(HaySiguiente());    
    return it.SiguienteClave();
}

template<class T>
const T& Conj<T>::Iterador::Anterior() const{
    assert(HayAnterior());    
    return it.AnteriorClave();
}

template<class T>
const T& Conj<T>::const_Iterador::Anterior() const{
    assert(HayAnterior());    
    return it.AnteriorClave();
}

template<class T>
void Conj<T>::Iterador::Avanzar() {
    assert(HaySiguiente());
    it.Avanzar();
}

template<class T>
void Conj<T>::const_Iterador::Avanzar() {
    assert(HaySiguiente());
    it.Avanzar();
}

template<class T>
void Conj<T>::Iterador::Retroceder() {
    assert(HayAnterior());    
    it.Retroceder();
}

template<class T>
void Conj<T>::const_Iterador::Retroceder() {
    assert(HayAnterior());    
    it.Retroceder();
}

template<class T>
void Conj<T>::Iterador::EliminarAnterior() {
    assert(HayAnterior());
    it.EliminarAnterior();
}

template<class T>
void Conj<T>::Iterador::EliminarSiguiente() {
    assert(HaySiguiente());
    it.EliminarSiguiente();
}

template<class T>
bool operator==(const Conj<T>& c1, const Conj<T>& c2) {
    return c1.operator==(c2);
}

template<class T>
std::ostream& operator<<(std::ostream& os, const Conj<T>& c) {
    return Mostrar(os, c, '{', '}');
}
