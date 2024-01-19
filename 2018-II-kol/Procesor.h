#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Procesor
{
private:
	char* naziv;
	float brzina;
	int brojJezgara;
	float kolKesa;
	void Kreiraj(const char* _naziv, float _brzina, int _brojJezgara, float _kolKesa);
	void OslobodiMem();
public:
	Procesor();
	Procesor(const char* _naziv, float _brzina, int _brojJezgara, float _kolKesa);
	~Procesor();

	Procesor(const Procesor& p);
	Procesor& operator=(const Procesor& p);

	float GetVrednost();
	
	bool operator==(Procesor& p);
	bool operator>(Procesor& p);

	friend ostream& operator<<(ostream& izlaz, const Procesor& p) {
		izlaz << p.naziv << " " << p.brzina << " " << p.brojJezgara << " " << p.kolKesa;
		return izlaz;
	}

	friend istream& operator>>(istream& ulaz, Procesor& p) {
		char n[100];
		float b;
		int br;
		float kk;
		ulaz >> n >> b >> br >> kk;
		p.Kreiraj(n, b, br, kk);
		return ulaz;
	}
};

