#include "StudentPismeniCelina.h"

StudentPismeniCelina::StudentPismeniCelina()
	: Student()
{
	bodoviPismeni = 0;
}

StudentPismeniCelina::StudentPismeniCelina(int brI, int bl, int bu, int bbodoviPismeni)
	: Student(brI, bl, bu)
{
	if (bbodoviPismeni > 40)
		bodoviPismeni = 40;
	else
		bodoviPismeni = bbodoviPismeni;
}

StudentPismeniCelina::~StudentPismeniCelina()
{

}

int StudentPismeniCelina::ukupanBrojBodova()
{
	int rez = bodoviPismeni + bodoviLab + bodoviUsmeni;
	return rez;
}

bool StudentPismeniCelina::polozio()
{
	if (ukupanBrojBodova() > 50 && bodoviUsmeni > 20 && bodoviPismeni > 20)
		return true;
	else
		return false;
}

void StudentPismeniCelina::izmeni(int brBodova)
{
	bodoviPismeni += brBodova;
}

void StudentPismeniCelina::ispisi(ostream& izlaz)
{
	izlaz << "STUDENT KOJI POLAZE PISMENI U CELINI" << endl
		<< "Broj indeksa: " << brojInd << endl
		<< "Bodovi na laboratorijskim vezbama: " << bodoviLab << endl
		<< "Bodovi na usmenom delu ispita: " << bodoviUsmeni << endl
		<< "Bodovi na pismenom delu ispita: " << bodoviPismeni << endl
		<< endl << "--------------------------------------------------------------"
		<< endl;
}

// brojInd;
// bodoviLab
//  bodoviUsmeni;
// bodovi pismeni