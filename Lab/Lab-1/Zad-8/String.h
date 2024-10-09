#include<iostream>
using namespace std;

class String
{
protected:
	char* niz;
	int max;
public:
	String();
	String(int max);
	void input();
	void output();
	int podstring(char p[]);
	int vratiDuzinu()
	{
		return max;
	};
	void novaFunkcija();
};