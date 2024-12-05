#pragma once
#include <iostream>

using namespace std;

class IspitniMaterijal
{
protected:
	int oznaka;
	double tezina;
	bool status; 

public:
	IspitniMaterijal();
	IspitniMaterijal(int oznaka, double tezina);
	IspitniMaterijal(const IspitniMaterijal& im);
	virtual ~IspitniMaterijal();

	int vratiOznaku();
	bool jeSavladan();
	void savladaj();

	virtual float vratiVreme(int vreme) = 0;

	virtual void stampaj(ostream& izlaz) = 0;
	friend ostream& operator<<(ostream& izlaz, IspitniMaterijal& im);
};

