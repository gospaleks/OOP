#pragma once
#include <string.h>
#include <fstream>
using namespace std;
class Proizvod
{
private:
	char barkod[7];
	char* tip;
public:
	Proizvod();
	Proizvod(const char* _barkod, const char *_tip);
	~Proizvod();

	char* getTip() { return tip; }

	virtual bool jeDefektan() = 0;
	virtual void prikazi(ostream& izlaz);

};

