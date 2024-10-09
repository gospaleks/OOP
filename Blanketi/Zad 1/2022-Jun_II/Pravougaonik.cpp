#include "Pravougaonik.h"

Pravougaonik::Pravougaonik()
	:Figura(){
	visina = sirina = 0;
}

Pravougaonik::Pravougaonik(float vvisina, float ssirina, float xx, float yy)
	:Figura(xx, yy){
	visina = vvisina;
	sirina = ssirina;
}

void Pravougaonik::ispisi(ostream& izlaz)
{
	izlaz << "PRAVOUGAONIK" << endl << "koordinate x i y su: " << x << " " << y << endl << "sirina stranice je: " << sirina << endl << "visina je: " << visina << endl << "povrsina je: " << vratiP() << endl << "obim je: " << vratiO() << endl;
}

void Pravougaonik::upisi(istream& ulaz)
{
	float xx, yy, vvisina, ssirina;
	ulaz >> xx >> yy >> vvisina >> ssirina;
	x = xx;
	y = yy;
	visina = vvisina;
	sirina = ssirina;
}
