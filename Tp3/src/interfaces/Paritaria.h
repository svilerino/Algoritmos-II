#include "../interfaces/Gremio.h"
#ifndef PARITARIA_H_
#define PARITARIA_H_

class Paritaria {
public:
	Paritaria();
	Paritaria(const Gremio& gr, const nat piso, const nat tope);
	Paritaria(const Paritaria& otra);
	Gremio& obtenerGremio();
	nat obtenerPiso() const;
	nat obtenerTope() const;
	~Paritaria();
	bool operator !=(const Paritaria &p) const;
private:
	Gremio gremio;
	nat piso;
	nat tope;
};

#endif /* PARITARIA_H_ */
