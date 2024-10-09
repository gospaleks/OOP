#pragma once
#include <iostream>
using namespace std;
class Banana
{
	float tezina;
	char* trulazrela; 
public:
	Banana();
	Banana(float ttezina, const char* ttrulazrela);
	~Banana();

	//void zauzmi(float ttezina, const char* ttrulazrela);
	void zauzmi(float ttezina, const char* tt);
	Banana(const Banana& b);
	Banana& operator=(Banana& b);
	float operator+(float broj);
	float operator-(float broj);
	
	friend ostream& operator<<(ostream& izlaz, Banana& b);
};

