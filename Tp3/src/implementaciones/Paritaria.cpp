#include "../interfaces/Paritaria.h"

Paritaria::Paritaria(const Gremio& gr, const nat piso, const nat tope):gremio(gr),piso(piso),tope(tope) {

}

Paritaria::Paritaria(){

}

Paritaria::Paritaria(const Paritaria& otra):gremio(otra.gremio),piso(otra.piso),tope(otra.tope){

}

bool Paritaria::operator != (const Paritaria &p) const
{
    return ( this->gremio!=p.gremio)
    		|| (this->piso!=p.piso) ||
    		(this->tope!=p.tope);
}

Gremio& Paritaria::obtenerGremio(){
	return this->gremio;
}

nat Paritaria::obtenerPiso() const{
	return this->piso;
}

nat Paritaria::obtenerTope() const{
	return this->tope;
}

Paritaria::~Paritaria() {
	//no hay nada que liberar...
}

