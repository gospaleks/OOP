#include "StudentPismeniKol.h"

StudentPismeniKol::StudentPismeniKol()
	: Student()
{
	bodoviIkol = 0;
	bodoviIIkol = 0;
}

StudentPismeniKol::StudentPismeniKol(int brI, int bl, int bu, int prvi, int drugi)
	: Student(brI, bl, bu)
{
	if (prvi > 20)
		bodoviIkol = 20;
	else
		bodoviIkol = prvi;
	if (drugi > 20)
		bodoviIIkol = 20;
	else
		bodoviIIkol = drugi;
}

StudentPismeniKol::~StudentPismeniKol()
{

}

int StudentPismeniKol::ukupanBrojBodova()
{
	int rez = bodoviIkol + bodoviIIkol + bodoviLab + bodoviUsmeni;
	return rez;
}

bool StudentPismeniKol::polozio()
{
	if (bodoviUsmeni > 20 && ukupanBrojBodova() > 50 && bodoviIkol > 5 && bodoviIIkol > 5 && (bodoviIIkol + bodoviIkol) > 20)
		return true;
	else
		return false;
}

void StudentPismeniKol::izmeni(int brBodova, int kol)
{
	if (kol == 1)
		bodoviIkol += brBodova;
	else
		bodoviIIkol += brBodova;
}

void StudentPismeniKol::ispisi(ostream& izlaz)
{
	izlaz << "STUDENT KOJI POLAZE PISMENI PREKO KOLOKVIJUMA" << endl
		<< "Broj indeksa: " << brojInd << endl
		<< "Bodovi na laboratorijskim vezbama: " << bodoviLab << endl
		<< "Bodovi na usmenom delu ispita: " << bodoviUsmeni << endl
		<< "Bodovi na prvom kolokvijumu: " << bodoviIkol << endl
		<< "Bodovi na drugom kolokvijumu: " << bodoviIIkol << endl
		<< endl << "--------------------------------------------------------------"
		<< endl;
}


// brojInd;
// bodoviLab;
// bodoviUsmeni;
// bodovi prvi kolokvijum
// bodovi drugi kolokvijum