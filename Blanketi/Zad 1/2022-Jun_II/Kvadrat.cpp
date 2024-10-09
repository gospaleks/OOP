#include "Kvadrat.h"
#include<math.h>

Kvadrat::Kvadrat()
	:Figura(){
	duzinaStranice = 0;
}

Kvadrat::Kvadrat(float duzina, float x, float y)
	:Figura(x, y){
	duzinaStranice = duzina;
}

void Kvadrat::ispisi(ostream& izlaz)
{
	izlaz << "KVADRAT" << endl << "koordinate x i y su: " << x << " " << y << endl << "stranica je: " << duzinaStranice << endl << "povrsina je: " << vratiP() << endl << "obim je: " << vratiO() << endl;
}

void Kvadrat::upisi(istream& ulaz)
{
	float xx, yy, duzina;
	ulaz >> xx >> yy >> duzina;
	x = xx;
	y = yy;
	duzinaStranice = duzina;
}
