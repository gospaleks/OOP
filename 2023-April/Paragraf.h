#pragma once
#include <fstream>
using namespace std;
class Paragraf
{
protected:
	char* p;
public:
	Paragraf();
	Paragraf(char * pp);
	virtual ~Paragraf();
	virtual void prikazi(ostream& izlaz);
};

