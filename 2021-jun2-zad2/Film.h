#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Film
{
private:
	int id;
	char* naziv;	// char* FTW!!!
	int godina;
	float ocena;
	void Kreiraj(int _id, const char* _naziv, int _godina, float _ocena);
public:
	Film();
	Film(int _id, const char* _naziv, int _godina, float _ocena);
	~Film();

	Film(const Film& f);
	Film& operator=(const Film& f);

	friend ostream& operator<<(ostream& izlaz, const Film& f);
	friend istream& operator>>(istream& ulaz, Film& f);

	bool operator<(float x);
	Film& operator=(float _ocena);
	bool operator==(float x);
	bool operator<(const Film& f);
	bool operator>(const Film& f);
};

