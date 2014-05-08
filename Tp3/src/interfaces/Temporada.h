#include "../interfaces/SistemaLaboral.h"
#include "../interfaces/Paritaria.h"
#include "../interfaces/Acuerdo.h"
#ifndef TEMPORADA_H_
#define TEMPORADA_H_

class Temporada {
public:
	Temporada(SistemaLaboral& sl);
	void abrirParitaria(const Gremio gr, const nat piso, const nat techo, const Conj<empresa> es);
	void cerrarAcuerdo(const Gremio gr, const nat porcentaje);
	void reabrir(const Gremio gr);
	Conj<Gremio> gremios() const;
	bool enParitarias(const Gremio gr) const;
	Conj<Gremio> gremiosNegociando() const;
	Conj<empresa> empresasNegociando() const;
	nat trabajadoresNegociando() const;
	void gremioConflictivo(Gremio& gremioConflictivo) const;
	~Temporada();

	//necesarias por driver(nuevas o hechas publicas)
	const Conj<Paritaria>& obtenerParitariasAbiertas() const;
	nat obtenerCantAcuerdosPrevios(const Gremio& gr) const;
	Conj<nat> obtenerGremiosConAcuerdos() const;
	Lista<Acuerdo>& obtenerAcuerdosDeAliados(const Gremio& gr);
private:
	//atributos
	SistemaLaboral sistema;
	Conj<Paritaria> paritariasAbiertas;
	Vector<Lista<Acuerdo> > acuerdosPorGrupo;
	Vector<nat> cantAcuerdosPrevios;

	//metodos
	void inicializarAcuerdosPorGrupos();
	void inicializarCantAcuerdosPrevios();
	Paritaria& removerAcuerdo(const Gremio& gr);
	void agregarParitaria(Paritaria pa);
	void removerParitaria(const Gremio& gr, Paritaria& res);
};

#endif /* TEMPORADA_H_ */
