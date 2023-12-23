#pragma once
#include "Student.h"
#include <iostream>
using namespace std;

class StudentPismeniCelina : public Student
{
	int bodoviPismeni;
public:
	StudentPismeniCelina();
	StudentPismeniCelina(int brI, int bl, int bu, int bbodoviPismeni);
	virtual ~StudentPismeniCelina();
	virtual int ukupanBrojBodova();
	virtual bool polozio();
	virtual void izmeni(int brBodova);
	virtual int ukupnobodoviPismeni() { return bodoviPismeni; }
	virtual void izmeni(int brBodova, int kol) { }
	virtual void ispisi(ostream& izlaz);

};

// brojInd;
// bodoviLab
//  bodoviUsmeni;
// bodovi pismeni