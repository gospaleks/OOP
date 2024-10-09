#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Knjiga
{
private:
	char* naslov;
	char* autor;
	int brojStrana;
	int tiraz;
	void Kreiraj(const char* _naslov, const char* _autor, int _brojStrana, int _tiraz);
	void OslobodiMem();
public:
	Knjiga();
	Knjiga(const char* _naslov, const char* _autor, int _brojStrana, int _tiraz);
	~Knjiga();

	Knjiga(const Knjiga& k);
	Knjiga& operator=(const Knjiga& k);

	bool operator==(Knjiga& k);
	bool operator>(Knjiga& k);

	friend ostream& operator<<(ostream& izlaz, const Knjiga& k);
	friend istream& operator>>(istream& ulaz, Knjiga& k);
};

