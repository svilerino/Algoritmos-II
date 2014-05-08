#include "../interfaces/Gremio.h"

Gremio::Gremio(){

}

bool Gremio::operator != (const Gremio &p) const
{
    return this->idGremio!=p.idGremio;
}

void Gremio::guardarCantAfiliados(nat cantidadAfiliados){
	this->cantAfiliados=cantidadAfiliados;
}

void Gremio::guardarEmpresas(Conj<string>& empresas){
	this->empresas=empresas;
}

void Gremio::agregarEmpresa(const empresa &e){
	this->empresas.Agregar(e);
}

Gremio::Gremio(const Conj<empresa>& es, const nat cantidadAfiliados):empresas(es), cantAfiliados(cantidadAfiliados), idGremio(0), idGrupo(0) {

}

Conj<empresa>& Gremio::obtenerEmpresas(){
	return this->empresas;
}

Gremio::Gremio(const Gremio& otro): empresas(otro.empresas), cantAfiliados(otro.cantAfiliados), idGremio(otro.idGremio), idGrupo(otro.idGrupo){

}

nat Gremio::obtenerCantAfiliados() const{
	return this->cantAfiliados;
}

nat Gremio::obtenerIdGremio() const{
	return this->idGremio;
}

nat Gremio::obtenerIdGrupo() const{
	return this->idGrupo;
}

void Gremio::guardarIdGremio(const nat nuevoId){
	this->idGremio=nuevoId;
}

void Gremio::guardarIdGrupo(const nat nuevoId){
	this->idGrupo=nuevoId;
}

Gremio::~Gremio() {
	//no hay nada que liberar...
}

