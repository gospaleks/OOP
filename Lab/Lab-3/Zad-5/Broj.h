#pragma once
class Broj
{
private:
	char* vrsta;
	double vrednost;
protected:
	virtual void PostaviVrednost(double vvrednost);
public:
	Broj(char* vvrsta, double vvrednost);
	Broj(char* vvrsta);
	virtual ~Broj();

	virtual void Print();
	virtual double VratiVrednost();
	const char* VratiVrstu() { return vrsta; }


	bool Veci(Broj* b) {
		if (this->VratiVrednost() > b->VratiVrednost())
			return true;
		return false;
	}
};
