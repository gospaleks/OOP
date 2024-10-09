#include "Predmet.h"

Predmet::Predmet()
{
	masa = 0;
	vrednost = 0;
}

Predmet::Predmet(double m, double v)
	:masa(m), vrednost(v) {
}

double Predmet::vratiVrednost()
{
	return vrednost;
}

double Predmet::vratiMasu()
{
	return masa;
}


