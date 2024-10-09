#pragma once
#include "Student.h"
#include <iostream>
using namespace std;

class StudentPismeniKol : public Student
{
	int bodoviIkol;
	int bodoviIIkol;
public:
	StudentPismeniKol();
	StudentPismeniKol(int brI, int bl, int bu, int prvi, int drugi);
	virtual ~StudentPismeniKol();
	virtual int ukupanBrojBodova();
	virtual bool polozio();
	virtual int ukupnobodoviPismeni() { return bodoviIkol + bodoviIIkol; }
	virtual void izmeni(int brBodova) { }
	virtual void izmeni(int brBodova, int kol);
	virtual void ispisi(ostream& izlaz);
};

// brojInd;
// bodoviLab;
// bodoviUsmeni;
// bodovi prvi kolokvijum
// bodovi drugi kolokvijum

