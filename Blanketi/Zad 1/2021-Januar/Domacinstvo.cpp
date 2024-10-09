#include "Domacinstvo.h"

Domacinstvo::Domacinstvo()
{
	brojDom = 0;
	povrsinaObjekti = 0;
	potrosnja = 0;
}

Domacinstvo::Domacinstvo(int bbrojDom, double po, double ppotrosnja)
{
	brojDom = bbrojDom;
	povrsinaObjekti = po;
	potrosnja = ppotrosnja;
}

Domacinstvo::~Domacinstvo()
{

}

void Domacinstvo::ispisi(ostream& izlaz)
{
	izlaz << "DOMACINSTVO: " << endl
		<< "Broj domacinstva: " << brojDom << endl
		<< "Povrsina pod objektima: " << povrsinaObjekti << endl
		<< "Potrosnja: " << potrosnja << endl
		<< "--------------------------------------------------" << endl;
}
