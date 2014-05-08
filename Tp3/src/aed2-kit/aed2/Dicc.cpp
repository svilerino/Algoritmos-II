

template<class K, class S>
Dicc<K,S>::Dicc() {}

template<class K, class S>
Dicc<K,S>::Dicc(const Dicc<K,S>& otro):
    claves(otro.claves), significados(otro.significados){}

template<class K, class S>
Dicc<K,S>& Dicc<K,S>::operator=(const Dicc<K,S>& otro) {
    claves = otro.claves;
    significados = otro.significados;
    return *this;
}

template<class K, class S>
typename Dicc<K,S>::Iterador Dicc<K,S>::Definir(const K& clave, const S& significado){
    Iterador it = Buscar(clave);
    if(it.HaySiguiente()) it.SiguienteSignificado() = significado;
    else it = DefinirRapido(clave, significado);
    return it;
}

template<class K, class S>
typename Dicc<K,S>::Iterador Dicc<K,S>::DefinirRapido(const K& clave, const S& significado){
    assert(!Definido(clave));
    claves.AgregarAdelante(clave);
    significados.AgregarAdelante(significado);
    return CrearIt();
}

template<class K, class S>
bool Dicc<K,S>::Definido(const K& clave) const{
    return Buscar(clave).HaySiguiente();
}

template<class K, class S>
const S& Dicc<K,S>::Significado(const K& clave)const{
    assert(Definido(clave));
    return Buscar(clave).SiguienteSignificado();
}

template<class K, class S>
S& Dicc<K,S>::Significado(const K& clave){
    assert(Definido(clave));
    return Buscar(clave).SiguienteSignificado();
}

template<class K, class S>
void Dicc<K,S>::Borrar(const K& clave){
    assert(Definido(clave));
    Buscar(clave).EliminarSiguiente();
}

template<class K, class S>
Nat Dicc<K,S>::CantClaves() const{
    return claves.Longitud();
}

template<class K, class S>
typename Dicc<K,S>::Iterador Dicc<K,S>::CrearIt(){
    return Iterador(this);
}

template<class K, class S>
typename Dicc<K,S>::const_Iterador Dicc<K,S>::CrearIt() const{
    return const_Iterador(this);
}

template<class K, class S>
bool Dicc<K,S>::Iterador::HaySiguiente() const{
    return itC.HaySiguiente();
}

template<class K, class S>
bool Dicc<K,S>::Iterador::HayAnterior() const{
    return itC.HayAnterior();
}
       
template<class K, class S>
const K& Dicc<K,S>::Iterador::SiguienteClave() const{
    assert(HaySiguiente());    
    return itC.Siguiente();
}

template<class K, class S>
S& Dicc<K,S>::Iterador::SiguienteSignificado() const {
    assert(HaySiguiente());    
    return itS.Siguiente();
}

template<class K, class S>
typename Dicc<K,S>::Elem Dicc<K,S>::Iterador::Siguiente() const{
    assert(HaySiguiente());    
    return Elem(SiguienteClave(), SiguienteSignificado());
}

template<class K, class S>
const K& Dicc<K,S>::Iterador::AnteriorClave() const{
    assert(HayAnterior());    
    return itC.Anterior();
}

template<class K, class S>
S& Dicc<K,S>::Iterador::AnteriorSignificado() const{
    assert(HayAnterior());    
    return itS.Anterior();
}

template<class K, class S>
typename Dicc<K,S>::Elem Dicc<K,S>::Iterador::Anterior() const{
    assert(HayAnterior());    
    return Elem(AnteriorClave(), AnteriorSignificado());
}

template<class K, class S>
void Dicc<K,S>::Iterador::Avanzar(){
    assert(HaySiguiente());    
    itC.Avanzar();
    itS.Avanzar();
}

template<class K, class S>
void Dicc<K,S>::Iterador::Retroceder(){
    assert(HayAnterior());    
    itC.Retroceder();
    itS.Retroceder();
}

template<class K, class S>
Dicc<K,S>::Iterador::Iterador(Dicc<K,S>* d):
    itC(d->claves.CrearIt()), itS(d->significados.CrearIt())
    {}


template<class K, class S>
void Dicc<K,S>::Iterador::EliminarSiguiente(){
    assert(HaySiguiente());    
    itC.EliminarSiguiente();
    itS.EliminarSiguiente();
}

template<class K, class S>
void Dicc<K,S>::Iterador::EliminarAnterior(){
    assert(HayAnterior());    
    itC.EliminarAnterior();
    itS.EliminarAnterior();
}

template<class K, class S>
bool Dicc<K,S>::const_Iterador::HaySiguiente() const{
    return itC.HaySiguiente();
}

template<class K, class S>
bool Dicc<K,S>::const_Iterador::HayAnterior() const{
    return itC.HayAnterior();
}

template<class K, class S>
const K& Dicc<K,S>::const_Iterador::SiguienteClave() const{
    assert(HaySiguiente());    
    return itC.Siguiente();
}

template<class K, class S>
const S& Dicc<K,S>::const_Iterador::SiguienteSignificado() const{
    assert(HaySiguiente());    
    return itS.Siguiente();
}

template<class K, class S>
typename Dicc<K,S>::const_Elem Dicc<K,S>::const_Iterador::Siguiente() const {
    assert(HaySiguiente());
    return const_Elem(SiguienteClave(), SiguienteSignificado());
}

template<class K, class S>
const K& Dicc<K,S>::const_Iterador::AnteriorClave() const{
    assert(HayAnterior());    
    return itC.Anterior();
}

template<class K, class S>
const S& Dicc<K,S>::const_Iterador::AnteriorSignificado() const{
    assert(HayAnterior());    
    return itS.Anterior();
}

template<class K, class S>
typename Dicc<K,S>::const_Elem Dicc<K,S>::const_Iterador::Anterior() const {
    assert(HayAnterior());
    return const_Elem(AnteriorClave(), AnteriorSignificado());
}

template<class K, class S>
void Dicc<K,S>::const_Iterador::Avanzar(){
    assert(HaySiguiente());
    itC.Avanzar();
    itS.Avanzar();
}

template<class K, class S>
void Dicc<K,S>::const_Iterador::Retroceder(){
    assert(HayAnterior());
    itC.Retroceder();
    itS.Retroceder();
}

template<class K, class S>
Dicc<K,S>::const_Iterador::const_Iterador(const Dicc<K,S>* d):
    itC(d->claves.CrearIt()), itS(d->significados.CrearIt()) 
    {}
    
template<class K, class S>
bool Dicc<K,S>::const_Iterador::operator==(const typename Dicc<K,S>::const_Iterador& otro) const {
	return itC == otro.itC && itS == otro.itS;
}
    
template<class K, class S>
bool Dicc<K,S>::Iterador::operator==(const typename Dicc<K,S>::Iterador& otro) const {
	return itC == otro.itC && itS == otro.itS;
}


///Funciones auxiliares
template<class K, class S>
typename Dicc<K,S>::Iterador Dicc<K,S>::Buscar(const K& clave){
    typename Dicc<K,S>::Iterador it = CrearIt();
    while(it.HaySiguiente() && it.SiguienteClave() != clave){
        it.Avanzar();
    }
    return it;
}

template<class K, class S>
typename Dicc<K,S>::const_Iterador Dicc<K,S>::Buscar(const K& clave) const{
    typename Dicc<K,S>::const_Iterador it = CrearIt();
    while(it.HaySiguiente() && it.SiguienteClave() != clave){
        it.Avanzar();
    }
    return it;
}

template<class K, class S>
std::ostream& operator<<(std::ostream& os, const Dicc<K,S>& d) {
    return Mostrar(os, d, '{', '}');
}

template<class K, class S>
bool operator==(const Dicc<K,S>& d1, const Dicc<K,S>& d2) {
    bool retval = d1.CantClaves() == d2.CantClaves();
    typename Dicc<K,S>::const_Iterador it1 = d1.CrearIt();
    while(retval and it1.HaySiguiente()){
        typename Dicc<K,S>::const_Iterador it2 = d2.Buscar(it1.SiguienteClave());
        retval = it2.HaySiguiente() and it1.SiguienteSignificado() == it2.SiguienteSignificado(); 
        it1.Avanzar();
    }
    return retval;
}
