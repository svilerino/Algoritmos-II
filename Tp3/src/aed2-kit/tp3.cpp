#include "Driver.h"
#include "aed2_tests.h"

// Auxiliares de testeo

void crearSistema(Driver &d)
{
	d.agregarGremio("UOM",1000);
    d.agregarGremio("UOCRA",950);
    d.agregarGremio("AGD",950);

    d.aliar("UOM","UOCRA");
    d.aliar("AGD","UOCRA");
}

void testAliados()
{
	Driver d;
	crearSistema(d);

	/*cout << endl << d.aliados("UOCRA") << endl;
	cout << d.aliados("AGD") << endl;
	cout << d.aliados("UOM") << endl;*/
	ASSERT_EQ(d.aliados("UOCRA").Cardinal(),2);
	ASSERT_EQ(d.aliados("AGD").Cardinal(),2);
	ASSERT_EQ(d.aliados("UOM").Cardinal(),2);
}

void testAcuerdosyReabrir()
{
    Driver d;
    crearSistema(d);

    d.iniciar();

    d.abrirParitaria("AGD",0,10);
    d.abrirParitaria("UOM",1,11);
    d.cerrarAcuerdo("AGD",5);
    d.cerrarAcuerdo("UOM",6);

    ASSERT_EQ(d.acuerdos().Cardinal(),1);
    ASSERT_EQ(d.paritarias().Cardinal(),1);
}

int main()
{
    RUN_TEST(testAliados);
    RUN_TEST(testAcuerdosyReabrir);
}

