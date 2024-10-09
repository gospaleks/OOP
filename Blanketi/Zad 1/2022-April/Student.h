#pragma once
#include <iostream>
using namespace std;
class Student
{
protected:
	int brojInd;
	int bodoviLab;
	int bodoviUsmeni;
public:
	Student();
	Student(int bbrojInde, int bbodoviLab, int bbodoviUsmeni);
	virtual ~Student();
	int GetbrojInd() { return brojInd; }
	virtual int ukupnobodoviPismeni() = 0;
	virtual void izmeni(int brBodova) = 0;
	virtual void izmeni(int brBodova, int kol) = 0;
	virtual int ukupanBrojBodova() = 0;
	virtual bool polozio() = 0;
	virtual void ispisi(ostream& izlaz) = 0;
};

