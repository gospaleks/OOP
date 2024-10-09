#include<iostream>
using namespace std;

class Skup
{
private:
	int n;
	int* niz;
public:
	Skup();
	Skup(int n);
	~Skup();
	inline int brojElemenata() { return n; };
	void izbaciDupl();
	int ispitaj(int element);
	void input();
	void nerastuci();
	void output();
};

