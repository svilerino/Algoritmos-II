#include "Driver.h"

#include <iostream>
#include <sstream>

Driver::Driver() {
    sistema = NULL;
    temporada = NULL;
}

Driver::~Driver() {
    // el sistema laboral se destruye solo si fue creado
    if (sistema != NULL)
        delete sistema;

    // la temporada se destruye solo si fue creado
    if (temporada != NULL)
        delete temporada;
}

void Driver::agregarGremio(const NombreGremio &g, Nat cantAfiliados)
{
    if (sistema == NULL)
        sistema = new SistemaLaboral();

    if(puenteNombreId.Definido(g)){
    	cerr << "Ya existe este gremio en el sistema" << endl;
    }else{
		Conj<empresa> empresas;//dummy conj
		nat idG = sistema->agregarGremio(empresas, cantAfiliados);
		puenteNombreId.Definir(g, idG);
		puenteIdNombre.Definir(idG, g);
    }
}

void Driver::aliar(const NombreGremio &g1, const NombreGremio &g2)
{
	if(puenteNombreId.Definido(g1) && puenteNombreId.Definido(g2)){
		nat idG1 = puenteNombreId.Significado(g1);
		nat idG2 = puenteNombreId.Significado(g2);
		sistema->aliarGremios(idG1, idG2);
	}else{
		cerr << "No existe alguno o ambos de estos nombres" << endl;
	}
}

void Driver::agregarEmpresa(const NombreGremio &g, const Empresa &e)
{
	if(puenteNombreId.Definido(g)){
		nat idG = puenteNombreId.Significado(g);
		sistema->agregarEmpresa(idG, e);
	}else{
		cerr << "No existe el nombre de gremio" << endl;
	}
}

Conj<Empresa> Driver::empresas(const NombreGremio &g) const
{
	if(puenteNombreId.Definido(g)){
		nat idG = puenteNombreId.Significado(g);
		Conj<Empresa> ret;
		    Conj<empresa>::Iterador it = sistema->obtenerEmpresas(idG).CrearIt();
		    while (it.HaySiguiente()) {
		        ret.Agregar(it.Siguiente());
		        it.Avanzar();
		    }
		 return ret;
	}else{
		cerr << "No existe el nombre de gremio" << endl;
		return Conj<Empresa>();
	}
}

Conj<NombreGremio> Driver::aliados(const NombreGremio &g) const
{
	Conj<NombreGremio> ret;
	if(puenteNombreId.Definido(g)){
		nat idG = puenteNombreId.Significado(g);
		Conj<nat> aliados = sistema->obtenerAliados(idG);
		//cout << "aliados de " << idG << aliados << endl;
		Conj<nat>::Iterador it = aliados.CrearIt();
		while (it.HaySiguiente()) {
			ret.Agregar(puenteIdNombre.Significado(it.Siguiente()));
			it.Avanzar();
		}
		//cout << sistema->obtenerCantidadGrupos() << endl;
		return ret;
	}else{
		cerr << "No existe el nombre de gremio" << endl;
		return Conj<Empresa>();
	}
}

void Driver::iniciar()
{
    temporada = new Temporada(*sistema);
}

void Driver::abrirParitaria(const NombreGremio &g, Nat piso, Nat tope)
{
	if(puenteNombreId.Definido(g)){
		nat idG = puenteNombreId.Significado(g);
		Gremio gremio = sistema->obtenerGremio(idG);
		temporada->abrirParitaria(gremio, piso, tope, gremio.obtenerEmpresas());
	}else{
		cerr << "No existe el nombre de gremio" << endl;
	}
}

void Driver::cerrarAcuerdo(const NombreGremio &g, Nat valor)
{
	if(puenteNombreId.Definido(g)){
		nat idG = puenteNombreId.Significado(g);
		Gremio gremio = sistema->obtenerGremio(idG);
		temporada->cerrarAcuerdo(gremio, valor);
	}else{
		cerr << "No existe el nombre de gremio" << endl;
	}
}

Conj<NombreGremio> Driver::paritarias() const
{
    Conj<NombreGremio> ret;
    Conj<Paritaria>::const_Iterador it = temporada->obtenerParitariasAbiertas().CrearIt();
    while (it.HaySiguiente())
    {
    	Paritaria pa = it.Siguiente();
        ret.Agregar(puenteIdNombre.Significado(pa.obtenerGremio().obtenerIdGremio()));
        it.Avanzar();
    }
    return ret;
}

Conj<NombreGremio> Driver::acuerdos() const
{
	Conj<NombreGremio> res;
	Conj<nat> conj = temporada->obtenerGremiosConAcuerdos();
	Conj<nat>::Iterador acuerdos = conj.CrearIt();
	while(acuerdos.HaySiguiente()){
		res.AgregarRapido(puenteIdNombre.Significado(acuerdos.Siguiente()));
		acuerdos.Avanzar();
	}
	return res;
}

Nat Driver::piso(const NombreGremio & g) const
{
	if(puenteNombreId.Definido(g)){
		nat idG = puenteNombreId.Significado(g);
		Conj<Paritaria>::const_Iterador it = temporada->obtenerParitariasAbiertas().CrearIt();
		Paritaria pa = it.Siguiente();
		while (pa.obtenerGremio().obtenerIdGremio() != idG){
			it.Avanzar();
		}
		return it.Siguiente().obtenerPiso();
	}else{
		cerr << "No existe el nombre de gremio" << endl;
		return 0;
	}
}

Nat Driver::tope(const NombreGremio& g) const
{
	if(puenteNombreId.Definido(g)){
		nat idG = puenteNombreId.Significado(g);
		Conj<Paritaria>::const_Iterador it = temporada->obtenerParitariasAbiertas().CrearIt();
		Paritaria pa = it.Siguiente();
		while (pa.obtenerGremio().obtenerIdGremio() != idG){
			it.Avanzar();
		}
		return it.Siguiente().obtenerTope();
	}else{
		cerr << "No existe el nombre de gremio" << endl;
		return 0;
	}
}

Nat Driver::valor(const NombreGremio &g) const
{
	if(puenteNombreId.Definido(g)){
		nat idG = puenteNombreId.Significado(g);
		Gremio gremio = sistema->obtenerGremio(idG);
		Lista<Acuerdo>::Iterador it = temporada->obtenerAcuerdosDeAliados(gremio).CrearIt();
			while (it.Siguiente().obtenerGremio().obtenerIdGrupo()!= idG){
				it.Avanzar();
			}
			return it.Siguiente().obtenerPorcentaje();
	}else{
		cerr << "No existe el nombre de gremio" << endl;
		return 0;
	}
}

Nat Driver::acuerdosPrevios(const NombreGremio &g) const
{
	if(puenteNombreId.Definido(g)){
		nat idG = puenteNombreId.Significado(g);
		Gremio gremio = sistema->obtenerGremio(idG);
		return temporada->obtenerCantAcuerdosPrevios(gremio);
	}else{
		cerr << "No existe el nombre de gremio" << endl;
		return 0;
	}
}
