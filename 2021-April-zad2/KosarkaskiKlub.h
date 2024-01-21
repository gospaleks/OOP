#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class KosarkaskiKlub
{
private:
	char boja;
	char** lista;
	int brojsponzora;
	int brojulaznica;
	int cenaulaznice;
	int budzet;
	int aktivnost;
	void zauzmimem(const char _boja,  char* _lista[100], int _brojsponzora, int _brojulaznica, int _cenaulaznica, int _budzet);
	void oslobodimem();
public:
	KosarkaskiKlub();
	KosarkaskiKlub(const char _boja, char* _lista[], int _brojsponzora, int _brojulaznica, int _cenaulaznica, int _budzet);
	~KosarkaskiKlub();
	KosarkaskiKlub(const KosarkaskiKlub& kk);
	friend istream& operator>>(istream& ulaz, KosarkaskiKlub& kk);
	friend ostream& operator<<(ostream& izlaz, const KosarkaskiKlub& kk);
	bool operator>(KosarkaskiKlub& kk);
	KosarkaskiKlub& operator=(KosarkaskiKlub& kk);
	float operator+(float x);
};

