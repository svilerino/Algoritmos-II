#include "../Utils.h"
#ifndef GREMIO_H_
#define GREMIO_H_

class Gremio {
	public:
		Gremio();
		Gremio(const Conj<empresa>& es, const nat cantidadAfiliados);
		Gremio(const Gremio& otro);
		Conj<empresa>& obtenerEmpresas();
		nat obtenerCantAfiliados() const;
		nat obtenerIdGremio() const;
		nat obtenerIdGrupo() const;
		void guardarIdGremio(const nat nuevoId);
		void guardarIdGrupo(const nat nuevoId);
		void guardarCantAfiliados(nat cantidadAfiliados);
		void guardarEmpresas(Conj<string>& empresa);
		~Gremio();
		bool operator !=(const Gremio &p) const;

		//agregados por driver
		void agregarEmpresa(const empresa &e);
	private:
		Conj<string> empresas;
		nat cantAfiliados;
		nat idGremio;
		nat idGrupo;
};

#endif /* GREMIO_H_ */
