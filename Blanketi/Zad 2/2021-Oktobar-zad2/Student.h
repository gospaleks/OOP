#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Student
{
private:
	char* ime;
	char* prezime;
	char* imeRoditelja;
	float prosek;
	void zauzmichar(const char* iime, const char* pprezime, const char* iimeRoditelja);
public:
	Student();
	Student(const char* iime, const char* pprezime, const char* iimeRoditelja, float pprosek);
	Student(Student& s);
	~Student();

	Student& operator=(const Student& s);
	bool operator==(Student& s);
	friend ostream& operator<<(ostream& izlaz, Student& s);

	void oslobodimem();
};

