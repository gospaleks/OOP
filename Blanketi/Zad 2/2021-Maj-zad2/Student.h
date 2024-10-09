#pragma once
#include <fstream>
#include <iostream>
using namespace std;

class Student
{
private:
	int brInd;
	char* ime;
	char* prezime;
	float pOcena;

	void Kreiraj(int _brInd, const char* _ime, const char* _prezime, float _pOcena);
	void OslobodiMem();

public:
	Student();
	Student(int _brInd, const char* _ime, const char* _prezime, float _pOcena);
	~Student();

	Student(const Student& s);
	Student& operator=(const Student& s);

	bool operator!=(Student& s);
	bool operator<(Student& s);
	bool operator>(Student& s);

	friend ostream& operator<<(ostream& izlaz, const Student& s);
	friend istream& operator>>(istream& ulaz, Student& s);
};

