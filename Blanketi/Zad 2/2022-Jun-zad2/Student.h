#pragma once
#include <iostream>
using namespace std;

class Student
{
	char* indeks;
	char* ime;
	char* prezime;
	float prosek;
	void zauzmi(const char* iindeks, const char* iime, const char* pprezime, float pprosek);
public:
	Student();
	Student(const char* iindeks, const char* iime, const char* pprezime, float pprosek);
	~Student();

	Student(const Student& s);
	bool operator<(Student& s);
	bool operator>(Student& s);

	Student& operator=(Student& s);
	bool operator==(Student& s);

	friend ostream& operator<<(ostream& izlaz, Student& s);
	friend istream& operator>>(istream& ulaz, Student& s);
};

