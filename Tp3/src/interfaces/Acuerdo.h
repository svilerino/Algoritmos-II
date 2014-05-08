#include "../interfaces/Paritaria.h"
#ifndef ACUERDO_H_
#define ACUERDO_H_

class Acuerdo {
public:
	Acuerdo(const Paritaria& pa, const nat porcentaje, const nat cantAcuerdosPrevios);
	Acuerdo(const Acuerdo& otro);
	Paritaria& obtenerParitaria();
	Gremio& obtenerGremio();
	nat obtenerPorcentaje() const;
	nat obtenerCantAcuerdosPrevios() const;
	~Acuerdo();
private:
	Paritaria paritaria;
	nat cantAcuerdosPrevios;
	nat porcentaje;
};

#endif /* ACUERDO_H_ */
