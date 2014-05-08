#include "../interfaces/SistemaLaboral.h"

SistemaLaboral::SistemaLaboral(){

}

void SistemaLaboral::agregarEmpresa(const nat &idG, const Empresa &e){
	this->sl[idG].agregarEmpresa(e);
}

nat SistemaLaboral::agregarGremio(const Conj<empresa>& es, const nat cantAfiliados){
	//idgrupo fixes
	//+1 fix
	//gremios vacios fix
	nat idGremio=sl.Longitud();//siempre es uno mas que el ultimo, ok.
	nat idGrupo=maximoIdGrupo();
	if(idGremio==0){
		//sl esta vacio...
		//entonces el idGrupo tambien es 0...porque arrancan a numerarse asi.
	}else{
		//hay al menos otro gremio en el sistema
		//si pongo siempre maximoIdGrupo me quedan el nuevo aliado implicitamente con los del ultimo grupo. +1 Fix, esto hace que cada nuevo gremio tenga su "particion" unica implicitamente.
		idGrupo++;
	}

	Gremio nuevoGremio(es, cantAfiliados);
	nuevoGremio.guardarIdGremio(idGremio);
	nuevoGremio.guardarIdGrupo(idGrupo);

	sl.AgregarAtras(nuevoGremio);

	return idGremio;
}

Conj<empresa>& SistemaLaboral::obtenerEmpresas(const nat &idG){
	return this->sl[idG].obtenerEmpresas();
}

Gremio SistemaLaboral::obtenerGremio(nat idG){
	return this->sl[idG];
}

void SistemaLaboral::aliarGremios(const nat idGr1, const nat idGr2){
	nat idGrupo1 = sl[idGr1].obtenerIdGrupo();
	nat idGrupo2 = sl[idGr2].obtenerIdGrupo();

	if(idGrupo1!=idGrupo2){
		nat idMenor = min(idGrupo1, idGrupo2);
		nat idMayor = max(idGrupo1, idGrupo2);
		nat indice=0;
		while(indice<sl.Longitud()){
			nat idGrupoActual = sl[indice].obtenerIdGrupo();
			if(idMayor == idGrupoActual){
				sl[indice].guardarIdGrupo(idMenor);
			}else{
				if(idMayor<idGrupoActual){
					sl[indice].guardarIdGrupo(idGrupoActual-1);
				}
			}
			indice++;
		}
	}
}

Conj<Gremio> SistemaLaboral::obtenerGremios() const{
	Conj<Gremio> result;
	for(nat i=0;i<sl.Longitud();i++){
		result.AgregarRapido(sl[i]);
	}
	return result;
}

Conj<nat> SistemaLaboral::obtenerAliados(const nat idGremio) const{
	// condicion de while a if fix
	Conj<nat> result;
	nat indice=0;
	nat idGrupoTarget=sl[idGremio].obtenerIdGrupo();
	while(indice < sl.Longitud()){
		if((indice!=idGremio) && (sl[indice].obtenerIdGrupo()==idGrupoTarget)){
			result.AgregarRapido(indice);
		}
		indice++;
	}
	return result;
}

nat SistemaLaboral::obtenerCantidadGrupos() const{
	//* gremios vacios fix
	//* plus one fix.
	return (sl.Longitud()>0)? this->maximoIdGrupo() + 1 : 0;
}

nat SistemaLaboral::maximoIdGrupo() const {
	nat max=0;
	for(nat j=0; j<sl.Longitud(); j++)
	{
	    if(max<sl[j].obtenerIdGrupo()){
	    	max=sl[j].obtenerIdGrupo();
	    }
	}
	return max;
}

SistemaLaboral::~SistemaLaboral() {

}
