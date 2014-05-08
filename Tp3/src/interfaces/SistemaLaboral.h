#include "../interfaces/Gremio.h"
#include "../aed2-kit/Tipos.h"
#ifndef SISTEMALABORAL_H_
#define SISTEMALABORAL_H_

class SistemaLaboral {
public:
	SistemaLaboral();
	nat agregarGremio(const Conj<empresa>& es, const nat cantAfiliados);
	void aliarGremios(const nat idGr1, const nat idGr2);
	Conj<nat> obtenerAliados(const nat idGremio) const;
	Conj<Gremio> obtenerGremios() const;
	nat obtenerCantidadGrupos() const;
	~SistemaLaboral();

	//agregados por driver
	void agregarEmpresa(const nat &idG, const Empresa &e);
	Conj<empresa>& obtenerEmpresas(const nat &idG);
	Gremio obtenerGremio(nat idG);
private:
	//atributos
	Vector<Gremio> sl;

	//metodos
	nat maximoIdGrupo() const;
};

#endif /* SISTEMALABORAL_H_ */
