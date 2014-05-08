#ifndef DRIVER_H_
#define DRIVER_H_

#include <stdlib.h>

// adaptar a los archivos que correspondan
#include "aed2.h"
#include "Tipos.h"

// Modulos del tp de la catedra
#include "../interfaces/SistemaLaboral.h"
#include "../interfaces/Temporada.h"

using namespace std;

// Deberan adaptar la implementacion del Driver para que corresponda
// a los archivos, nombres de clases y metodos de su implementacion.
// El codigo otorgado del driver deberia ser de mucha ayuda para poder usarlo.
//
// IMPORTANTE: No debe alterarse en ningun aspecto la interfaz del driver.
class Driver {
public:
        Driver();
       ~Driver();

    ///////////////////////////////////////////////////////////////
    /// Sistema Laboral

    /// Se crea implicitamente en la primer llamada a agregarGremio

    // Generadores
    void agregarGremio(const NombreGremio& g, Nat cantAfiliados);
    void agregarEmpresa(const NombreGremio& g, const Empresa& e);
    void aliar(const NombreGremio & g1, const NombreGremio & g2);

    // Iteracion de empresas, aliados
    Nat cantAfiliados(const NombreGremio& g) const;
    Conj<Empresa> empresas(const NombreGremio& g) const;
    Conj<NombreGremio> aliados(const NombreGremio& g) const;
    Conj<NombreGremio> gremios(const NombreGremio& g) const;

    ///////////////////////////////////////////////////////////////
    /// Temporada

    // Generadores
    /** La Temporada se crea al llamar a iniciar()
     * usando el sistema gremial armado con la misma instancia del Driver.
     * SE INDEFINE si nunca se llamo a agregarGremio
    */
    void iniciar();

    void abrirParitaria(const NombreGremio& g, Nat piso, Nat tope);
    void cerrarAcuerdo(const NombreGremio& g, Nat valor);

    Conj<NombreGremio> paritarias() const;
    Conj<NombreGremio> acuerdos() const;

    // debe existir una paritaria de g
    Nat piso(const NombreGremio& g) const;
    Nat tope(const NombreGremio& g) const;

    // debe existir un acuerdo de g
    Nat valor (const NombreGremio& g) const;
    Nat acuerdosPrevios (const NombreGremio& g) const;

private:
    // Deshabilitamos copia y asignacion
    Driver(const Driver& otro);
    Driver& operator=(const Driver& otro);

    /// BORRAR DE ACA PARA ABAJO PARA DAR A LOS ALUMNOS
    // En esta seccion va el codigo de cada grupo.
    // Lo que esta abajo es un ejemplo ilustrativo
    ///

    SistemaLaboral * sistema;
    Temporada * temporada;
    Dicc<NombreGremio, nat> puenteNombreId;
    Dicc<nat, NombreGremio> puenteIdNombre;

};

#endif /* DRIVER_H_ */
