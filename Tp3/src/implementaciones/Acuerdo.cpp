#include "../interfaces/Acuerdo.h"

Acuerdo::Acuerdo(const Paritaria& pa, const nat porcentaje, const nat cantAcuerdosPrevios):paritaria(pa), cantAcuerdosPrevios(cantAcuerdosPrevios), porcentaje(porcentaje){

}

Paritaria& Acuerdo::obtenerParitaria(){
	return this->paritaria;
}

Acuerdo::Acuerdo(const Acuerdo& otro):paritaria(otro.paritaria), cantAcuerdosPrevios(otro.cantAcuerdosPrevios), porcentaje(otro.porcentaje){

}

Gremio& Acuerdo::obtenerGremio(){
	return (this->paritaria).obtenerGremio();
}

nat Acuerdo::obtenerPorcentaje() const{
	return this->porcentaje;
}

nat Acuerdo::obtenerCantAcuerdosPrevios() const{
	return this->cantAcuerdosPrevios;
}

Acuerdo::~Acuerdo() {
	//no hay nada que liberar...
}

